// Each training sample has its own feature vector,
//
//  Sampel_1----Sample_2----Sample_3----...
//     |           |           |
//  feature_1   feature_1   feature_1   ...
//     |		   |           |
//  feature_2   feature_2   feature_2   ...
//     |		   |           |
//    ...         ...         ...       ...

#ifndef SVM_PACKAGE_H
#define SVM_PACKAGE_H

// Stander library headers
#include <iostream>
#include <vector>


// SVM library header
#include "svm.h"

//using namespace std;

#pragma once

class CV_ParamSet
{
public:
	CV_ParamSet(const double& c = 0, const double& g = 0) : C(c), gamma(g), accuracy(0.0) {  }

	double C;
	double gamma;
	double accuracy;
};

class SVM_Package
{
public:
	// Constructor
	SVM_Package(void) : prob_train(new struct svm_problem),
		prob_test(new struct svm_problem),
		model(NULL),
		param(new struct svm_parameter)
	{
		// For more detailed parameter description, please check out the document
		param->svm_type = C_SVC;
		param->kernel_type = RBF;
		param->degree = 3;
		param->gamma = 0;
		param->coef0 = 0;
		param->nu = 0.5;
		param->cache_size = 10000;
		param->C = 1;
		param->eps = 1e-3;
		param->p = 0.1;
		param->shrinking = 1;
		param->probability = 0;
		param->nr_weight = 0;
		param->weight_label = NULL;
		param->weight = NULL;
	}
	// Destructor
	~SVM_Package(void)
	{
		//delete prob_train;
		//delete prob_test;
		//delete param;
		//delete model;
	}

	// Create problem
	void SVM_Package::svmCreateProblem(const std::vector<double>& target,
		const std::vector< std::vector<double> >& feature,
		struct svm_problem* prob);
	// param.  in: target
	// param.  in: feature
	// param. out: prob

	// Create problem for training data
	void SVM_Package::svmCreateProblemForTrainingData(const std::vector<double>& target,
		const std::vector< std::vector<double> >& feature);
	// param.  in: target
	// param.  in: feature

	// Create problem for test data
	void SVM_Package::svmCreateProblemForTestData(const std::vector<double>& target,
		const std::vector< std::vector<double> >& feature);
	// param.  in: target
	// param.  in: feature

	// Perform cross-validation to find the best parameter set (find C and gamma)
	struct svm_parameter* SVM_Package::svmCrossValidation(const int& nr_fold = 5,
		const int& c_lowerbound = -8, const int& c_upperbound = +8,
		const int& g_lowerbound = -8, const int& g_upperbound = +8);
	// param.  in: nr_fold
	// param.  in: c_lowerbound, c_upperbound
	// param.  in: g_lowerbound, g_upperbound

	// Train svm model
	void SVM_Package::svmTrain();

	// Test the trained model
	double SVM_Package::svmTestModel();
	// return - accuracy

	// Predict unknown data based on the trained model
	double SVM_Package::svmPredict(const std::vector<double>& target,
		const std::vector< std::vector<double> >& feature, int* cls);
	// param.  in: target
	// param.  in: feature
	void SVM_Package::svmSetParamter(struct svm_parameter* parameter);



private:
	struct svm_problem* prob_train;    // Describe the training data
	struct svm_problem* prob_test;     // Describe the test data
	struct svm_parameter* param;       // Parameters are used to describe the properties of the svm model
	struct svm_model* model;
};

#endif