using namespace System;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
//using namespace std;

float pow2(float n);
Bitmap^ Mask_Operation(Bitmap^ image, double* mask);
//void Semivariogram_All(std::string file_name,Bitmap^ image,int channel);  //channel: 0=B,1=G,2=R;
float Semivariogram_One(Bitmap^ image, Point p, int channel);  //channel: 0=B,1=G,2=R;
void mark_color(Bitmap^ image, Point point, int color);
std::vector<int> window_data(Point pos, int h, Bitmap^ image, int channel);
float window_direction_process(int h, std::vector<int> data, int direction);
float window_cross_process(int h, std::vector<int> data1, std::vector<int> data2);
Bitmap^ Create_RGB_Image(Bitmap^ R, Bitmap^ G, Bitmap^ B);
void Semivariogram_direct_all(std::string file_name, Bitmap^ image, Bitmap^ image2, int channel, int direction, int h_num, std::vector<int> h);
void Semivariogram_cross_all(std::string file_name, Bitmap^ image, Bitmap^ image2, int channel1, int channel2, int h_num, std::vector<int> h);
void Semivariogram_both_all(std::string file_name, Bitmap^ image, Bitmap^ image2, int channel, int direction, int channel1, int channel2, int h_num, std::vector<int> h);


