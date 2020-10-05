#include "SVM_Package.h"
#include <fstream>
#include <iostream>
#include <string>

//using namespace std;

void SVM_Package::svmCreateProblem(const std::vector<double>& target,
	const std::vector< std::vector<double> >& feature,
	struct svm_problem* prob)
{
	if (target.size() == feature.begin()->size())
	{
		if (target.size() && feature.begin()->size())
		{
			prob->l = target.size();					// set the number of training data
			prob->y = new double[prob->l];				// Allocate the memory space for target
			prob->x = new struct svm_node* [prob->l];

			struct svm_node* element = new struct svm_node[prob->l * (feature.size() + 1)];
			int offset = 0;
			for (int ind = 0; ind != prob->l; ++ind)
			{
				prob->y[ind] = target[ind];    // Set target for each training sample
				prob->x[ind] = element + offset;

				// Set contents of feature vector for each training sample
				for (int f_ind = 0; f_ind != feature.size(); ++f_ind)
				{
					element[offset].value = feature[f_ind][ind];	// Set feature value
					element[offset].index = f_ind + 1;				// Set index of the the feature
					++offset;
				}
				// indicate the end of the feature vector
				element[offset].value = NULL;
				element[offset].index = -1;
				++offset;
			}
		}
		SVM_Package::prob_train = prob;
		//std::cout<<"svmCreateProblem done!"<<std::endl;
	}
	else
	{
		std::cerr << "Error occurs in function: svmCreateProblem" << std::endl;
		//return;
	}
}

void SVM_Package::svmCreateProblemForTrainingData(const std::vector<double>& target,
	const std::vector< std::vector<double> >& feature)
{
	svmCreateProblem(target, feature, prob_train);
}

void SVM_Package::svmCreateProblemForTestData(const std::vector<double>& target,
	const std::vector< std::vector<double> >& feature)
{
	svmCreateProblem(target, feature, prob_test);
}

struct svm_parameter* SVM_Package::svmCrossValidation(const int& nr_fold,
	const int& c_lowerbound, const int& c_upperbound,
	const int& g_lowerbound, const int& g_upperbound)
{

	if (!svm_check_parameter(prob_train, param))
	{
		//int num_of_c = c_upperbound - c_lowerbound + 1;
		//int num_of_g = g_upperbound - g_lowerbound + 1;

		std::vector<CV_ParamSet> cv_param_set/*(num_of_c * num_of_g)*/;
		// Perform cross-validation
		for (int c = c_lowerbound; c <= c_upperbound; c++)
		{
			for (int g = g_lowerbound; g <= g_upperbound; g++)
			{
				// Store the classification result
				double* target = new double[prob_train->l];
				struct svm_parameter* param_test = new struct svm_parameter;

				param_test->svm_type = C_SVC;
				param_test->kernel_type = RBF;
				param_test->degree = 3;
				param_test->coef0 = 0;
				param_test->nu = 0.5;
				param_test->cache_size = 10000;
				param_test->eps = 1e-3;
				param_test->p = 0.1;
				param_test->shrinking = 1;
				param_test->probability = 0;
				param_test->nr_weight = 0;
				param_test->weight_label = NULL;
				param_test->weight = NULL;
				param_test->C = pow(2.0, c);		 // Vary this parameter!!
				param_test->gamma = pow(2.0, g);	 // Vary this parameter!!

				svm_cross_validation(prob_train, param_test, nr_fold, target);

				int total_correct = 0;
				for (int ind = 0; ind != prob_train->l; ++ind)
					if (fabs(target[ind] - prob_train->y[ind]) < 1e-3)
						++total_correct;

				CV_ParamSet tmp;
				tmp.accuracy = 100.0 * total_correct / prob_train->l;
				tmp.C = param_test->C;
				tmp.gamma = param_test->gamma;
				cv_param_set.push_back(tmp);
				delete param_test;
				delete target;
			}
		}

		// Based on cross-validation result, find the most appropriate parameter set
		CV_ParamSet optimal_param = cv_param_set[0];
		for (int ind = 1; ind != cv_param_set.size(); ++ind)
		{
			if (cv_param_set[ind].accuracy >= optimal_param.accuracy)
				optimal_param = cv_param_set[ind];
		}
		// Update the parameter
		param->C = optimal_param.C;
		param->gamma = optimal_param.gamma;
		// Re-train the svm model
		SVM_Package::svmTrain();
		return param;
	}
	else
	{
		std::cerr << "Error occurs in fuctionL svmCrossValidation" << std::endl;
		return param;
	}
}

void SVM_Package::svmTrain()
{
	// Train SVM model
	model = svm_train(prob_train, param);
}

double SVM_Package::svmTestModel()
{
	if (!svm_check_parameter(prob_test, param))
	{
		if (model)
		{
			std::vector<double> result;
			// Do the prediction
			for (int ind = 0; ind < prob_test->l; ++ind)
				result.push_back(svm_predict(model, prob_test->x[ind]));

			int total_correct = 0;
			for (int ind = 0; ind != prob_test->l; ++ind)
				if (fabs(result[ind] - prob_test->y[ind]) < 1e-3)
					++total_correct;

			return 100.0 * total_correct / prob_test->l;
		}
		else
		{
			// throw an exception to user
			std::cout << "   <Error> The model hasn't been trained." << std::endl;
			return 0.0;
		}
	}
	else
	{
		std::cerr << "Error occurs in function: svmTestModel" << std::endl;
		return 0.0;
	}
}

double SVM_Package::svmPredict(const std::vector<double>& target,
	const std::vector< std::vector<double> >& feature, int* cls)
{
	struct svm_problem* prob = new struct svm_problem;
	svmCreateProblem(target, feature, prob);
	if (!svm_check_parameter(prob, param))
	{
		if (model)
		{
			std::vector<double> result;
			// Do the prediction
			for (int ind = 0; ind < prob->l; ++ind)
			{
				result.push_back(svm_predict(model, prob->x[ind]));
				cls[ind] = (int)result[ind];
			}
			int total_correct = 0;
			for (int ind = 0; ind != prob->l; ++ind)
			{
				if (fabs(result[ind] - prob->y[ind]) < 1e-3)
				{
					//cls[ind]=1;
					++total_correct;
				}
				// 				else
				// 				{
				// 					cls[ind]=2;
				// 				}
			}
			int total_number = prob->l;
			delete prob;

			return 100.0 * total_correct / total_number;
		}
		delete prob;
		return 0.0;
	}
	else
	{
		delete prob;
		std::cerr << "Error occurs in function: svmPredict" << std::endl;
		return 0.0;
	}
}

void SVM_Package::svmSetParamter(struct svm_parameter* parameter)
{
	param = parameter;
	SVM_Package::svmTrain();
}