#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
//using namespace std;

float pow2(int n)
{
	return n * n;
}

Bitmap^ Mask_Operation(Bitmap^ image, double* mask)
{
	System::Drawing::Rectangle rect = System::Drawing::Rectangle(0, 0, image->Width, image->Height);
	System::Drawing::Imaging::BitmapData^ bmpData = image->LockBits(rect, System::Drawing::Imaging::ImageLockMode::ReadWrite, image->PixelFormat);
	IntPtr ptr = bmpData->Scan0;
	int W = image->Width * 3;
	int BytesOfSkip = bmpData->Stride - W;
	int Height = image->Height;
	Byte* p = (Byte*)((void*)ptr);
	array<Byte>^ Target_Image = gcnew array<Byte>(bmpData->Stride * Height);
	for (int y = 0; y < Height; y++)
	{
		if (y == 0 || y == Height - 1)
		{
			for (int x = 0; x < W; x++)
			{
				Target_Image[y * W + x] = p[y * W + x];
			}
		}
		else
		{
			for (int x = 0; x < W; x += 3)
			{
				if (x == 0 || x == W - 3)
				{
					Target_Image[y * W + x] = p[y * W + x];
					Target_Image[y * W + x + 1] = p[y * W + x + 1];
					Target_Image[y * W + x + 2] = p[y * W + x + 2];
				}
				else
				{
					Target_Image[y * W + x] = p[(y - 1) * W + x - 3] * mask[0] + p[(y - 1) * W + x] * mask[1] + p[(y - 1) * W + x + 3] * mask[2] + p[(y)*W + x - 3] * mask[3] + p[(y)*W + x] * mask[4] + p[(y)*W + x + 3] * mask[5] + p[(y + 1) * W + x - 3] * mask[6] + p[(y + 1) * W + x] * mask[7] + p[(y + 1) * W + x + 3] * mask[8];						//B
					Target_Image[y * W + x + 1] = p[(y - 1) * W + x - 2] * mask[0] + p[(y - 1) * W + x + 1] * mask[1] + p[(y - 1) * W + x + 4] * mask[2] + p[(y)*W + x - 2] * mask[3] + p[(y)*W + x + 1] * mask[4] + p[(y)*W + x + 4] * mask[5] + p[(y + 1) * W + x - 2] * mask[6] + p[(y + 1) * W + x + 1] * mask[7] + p[(y + 1) * W + x + 4] * mask[8];		//G
					Target_Image[y * W + x + 2] = p[(y - 1) * W + x - 1] * mask[0] + p[(y - 1) * W + x + 2] * mask[1] + p[(y - 1) * W + x + 5] * mask[2] + p[(y)*W + x - 1] * mask[3] + p[(y)*W + x + 2] * mask[4] + p[(y)*W + x + 5] * mask[5] + p[(y + 1) * W + x - 1] * mask[6] + p[(y + 1) * W + x + 2] * mask[7] + p[(y + 1) * W + x + 5] * mask[8];		//R	
				}
			}
		}
	}
	System::Runtime::InteropServices::Marshal::Copy(Target_Image, 0, ptr, bmpData->Stride * Height);
	image->UnlockBits(bmpData);
	return image;
}


// void Semivariogram_All(std::string file_name,Bitmap^ image,int channel)
// {
// 	System::Drawing::Rectangle rect = System::Drawing::Rectangle(0, 0, image->Width, image->Height);	   
// 	System::Drawing::Imaging::BitmapData^ bmpData = image->LockBits( rect, System::Drawing::Imaging::ImageLockMode::ReadWrite, image->PixelFormat );
// 	IntPtr ptr = bmpData->Scan0;
// 	int W = image->Width*3;
// 	int BytesOfSkip = bmpData->Stride - W;
// 	int Height = image->Height;
// 	Byte* p = (Byte*)((void*)ptr);
// 
// 	std::ofstream fout(file_name.c_str(),std::ios::out);
// 
// 	int pos[9];
// 	float f_semivariogram;
// 
// 
// 	for(int y=0; y<Height; y++)
// 	{
// 		if (y==0 || y==Height-1)
// 		{
// 			for (int x=0;x<W;x++)
// 			{
// 				//
// 			}
// 		}
// 		else
// 		{
// 			for(int x=0; x<W;x+=3)
// 			{
// 				if (x==0 || x==W-3)
// 				{
// 					//
// 				}
// 				else
// 				{
// 					switch (channel)
// 					{
// 						case 0:
// 						case 1:
// 						case 2:
// 							fout<<"1 1:";
// 							pos[0]=p[(y-1)*W+x-3+channel];
// 							pos[1]=p[(y-1)*W+x+channel];
// 							pos[2]=p[(y-1)*W+x+3+channel];
// 							pos[3]=p[(y)*W+x-3+channel];
// 							pos[4]=p[(y)*W+x+channel];
// 							pos[5]=p[(y)*W+x+3+channel];
// 							pos[6]=p[(y+1)*W+x-3+channel];
// 							pos[7]=p[(y+1)*W+x+channel];
// 							pos[8]=p[(y+1)*W+x+3+channel];
// 							f_semivariogram=( pow2(pos[0]-pos[4]) + pow2(pos[1]-pos[4]) + pow2(pos[2]-pos[4]) + pow2(pos[3]-pos[4]) + pow2(pos[5]-pos[4]) + pow2(pos[6]-pos[4]) + pow2(pos[7]-pos[4]) + pow2(pos[8]-pos[4]) )/(2*8);
// 							fout<<f_semivariogram;
// 							break;
// 						case 3:
// 							fout<<"1 1:";
// 							pos[0]=p[(y-1)*W+x-3];
// 							pos[1]=p[(y-1)*W+x];
// 							pos[2]=p[(y-1)*W+x+3];
// 							pos[3]=p[(y)*W+x-3];
// 							pos[4]=p[(y)*W+x];
// 							pos[5]=p[(y)*W+x+3];
// 							pos[6]=p[(y+1)*W+x-3];
// 							pos[7]=p[(y+1)*W+x];
// 							pos[8]=p[(y+1)*W+x+3];
// 							f_semivariogram=( pow2(pos[0]-pos[4]) + pow2(pos[1]-pos[4]) + pow2(pos[2]-pos[4]) + pow2(pos[3]-pos[4]) + pow2(pos[5]-pos[4]) + pow2(pos[6]-pos[4]) + pow2(pos[7]-pos[4]) + pow2(pos[8]-pos[4]) )/(2*8);
// 							fout<<f_semivariogram<<" 2:";
// 							pos[0]=p[(y-1)*W+x-3+1];
// 							pos[1]=p[(y-1)*W+x+1];
// 							pos[2]=p[(y-1)*W+x+3+1];
// 							pos[3]=p[(y)*W+x-3+1];
// 							pos[4]=p[(y)*W+x+1];
// 							pos[5]=p[(y)*W+x+3+1];
// 							pos[6]=p[(y+1)*W+x-3+1];
// 							pos[7]=p[(y+1)*W+x+1];
// 							pos[8]=p[(y+1)*W+x+3+1];
// 							f_semivariogram=( pow2(pos[0]-pos[4]) + pow2(pos[1]-pos[4]) + pow2(pos[2]-pos[4]) + pow2(pos[3]-pos[4]) + pow2(pos[5]-pos[4]) + pow2(pos[6]-pos[4]) + pow2(pos[7]-pos[4]) + pow2(pos[8]-pos[4]) )/(2*8);
// 							fout<<f_semivariogram;
// 							break;
// 						case 4:
// 							fout<<"1 1:";
// 							pos[0]=p[(y-1)*W+x-3+1];
// 							pos[1]=p[(y-1)*W+x+1];
// 							pos[2]=p[(y-1)*W+x+3+1];
// 							pos[3]=p[(y)*W+x-3+1];
// 							pos[4]=p[(y)*W+x+1];
// 							pos[5]=p[(y)*W+x+3+1];
// 							pos[6]=p[(y+1)*W+x-3+1];
// 							pos[7]=p[(y+1)*W+x+1];
// 							pos[8]=p[(y+1)*W+x+3+1];
// 							f_semivariogram=( pow2(pos[0]-pos[4]) + pow2(pos[1]-pos[4]) + pow2(pos[2]-pos[4]) + pow2(pos[3]-pos[4]) + pow2(pos[5]-pos[4]) + pow2(pos[6]-pos[4]) + pow2(pos[7]-pos[4]) + pow2(pos[8]-pos[4]) )/(2*8);
// 							fout<<f_semivariogram<<" 2:";
// 							pos[0]=p[(y-1)*W+x-3+2];
// 							pos[1]=p[(y-1)*W+x+2];
// 							pos[2]=p[(y-1)*W+x+3+2];
// 							pos[3]=p[(y)*W+x-3+2];
// 							pos[4]=p[(y)*W+x+2];
// 							pos[5]=p[(y)*W+x+3+2];
// 							pos[6]=p[(y+1)*W+x-3+2];
// 							pos[7]=p[(y+1)*W+x+2];
// 							pos[8]=p[(y+1)*W+x+3+2];
// 							f_semivariogram=( pow2(pos[0]-pos[4]) + pow2(pos[1]-pos[4]) + pow2(pos[2]-pos[4]) + pow2(pos[3]-pos[4]) + pow2(pos[5]-pos[4]) + pow2(pos[6]-pos[4]) + pow2(pos[7]-pos[4]) + pow2(pos[8]-pos[4]) )/(2*8);
// 							fout<<f_semivariogram;
// 							break;
// 						case 5:
// 							fout<<"1 1:";
// 							pos[0]=p[(y-1)*W+x-3];
// 							pos[1]=p[(y-1)*W+x];
// 							pos[2]=p[(y-1)*W+x+3];
// 							pos[3]=p[(y)*W+x-3];
// 							pos[4]=p[(y)*W+x];
// 							pos[5]=p[(y)*W+x+3];
// 							pos[6]=p[(y+1)*W+x-3];
// 							pos[7]=p[(y+1)*W+x];
// 							pos[8]=p[(y+1)*W+x+3];
// 							f_semivariogram=( pow2(pos[0]-pos[4]) + pow2(pos[1]-pos[4]) + pow2(pos[2]-pos[4]) + pow2(pos[3]-pos[4]) + pow2(pos[5]-pos[4]) + pow2(pos[6]-pos[4]) + pow2(pos[7]-pos[4]) + pow2(pos[8]-pos[4]) )/(2*8);
// 							fout<<f_semivariogram<<" 2:";
// 							pos[0]=p[(y-1)*W+x-3+2];
// 							pos[1]=p[(y-1)*W+x+2];
// 							pos[2]=p[(y-1)*W+x+3+2];
// 							pos[3]=p[(y)*W+x-3+2];
// 							pos[4]=p[(y)*W+x+2];
// 							pos[5]=p[(y)*W+x+3+2];
// 							pos[6]=p[(y+1)*W+x-3+2];
// 							pos[7]=p[(y+1)*W+x+2];
// 							pos[8]=p[(y+1)*W+x+3+2];
// 							f_semivariogram=( pow2(pos[0]-pos[4]) + pow2(pos[1]-pos[4]) + pow2(pos[2]-pos[4]) + pow2(pos[3]-pos[4]) + pow2(pos[5]-pos[4]) + pow2(pos[6]-pos[4]) + pow2(pos[7]-pos[4]) + pow2(pos[8]-pos[4]) )/(2*8);
// 							fout<<f_semivariogram;
// 							break;
// 						case 6:
// 							fout<<"1 1:";
// 							pos[0]=p[(y-1)*W+x-3];
// 							pos[1]=p[(y-1)*W+x];
// 							pos[2]=p[(y-1)*W+x+3];
// 							pos[3]=p[(y)*W+x-3];
// 							pos[4]=p[(y)*W+x];
// 							pos[5]=p[(y)*W+x+3];
// 							pos[6]=p[(y+1)*W+x-3];
// 							pos[7]=p[(y+1)*W+x];
// 							pos[8]=p[(y+1)*W+x+3];
// 							f_semivariogram=( pow2(pos[0]-pos[4]) + pow2(pos[1]-pos[4]) + pow2(pos[2]-pos[4]) + pow2(pos[3]-pos[4]) + pow2(pos[5]-pos[4]) + pow2(pos[6]-pos[4]) + pow2(pos[7]-pos[4]) + pow2(pos[8]-pos[4]) )/(2*8);
// 							fout<<f_semivariogram<<" 2:";
// 							pos[0]=p[(y-1)*W+x-3+1];
// 							pos[1]=p[(y-1)*W+x+1];
// 							pos[2]=p[(y-1)*W+x+3+1];
// 							pos[3]=p[(y)*W+x-3+1];
// 							pos[4]=p[(y)*W+x+1];
// 							pos[5]=p[(y)*W+x+3+1];
// 							pos[6]=p[(y+1)*W+x-3+1];
// 							pos[7]=p[(y+1)*W+x+1];
// 							pos[8]=p[(y+1)*W+x+3+1];
// 							f_semivariogram=( pow2(pos[0]-pos[4]) + pow2(pos[1]-pos[4]) + pow2(pos[2]-pos[4]) + pow2(pos[3]-pos[4]) + pow2(pos[5]-pos[4]) + pow2(pos[6]-pos[4]) + pow2(pos[7]-pos[4]) + pow2(pos[8]-pos[4]) )/(2*8);
// 							fout<<f_semivariogram<<" 3:";
// 							pos[0]=p[(y-1)*W+x-3+2];
// 							pos[1]=p[(y-1)*W+x+2];
// 							pos[2]=p[(y-1)*W+x+3+2];
// 							pos[3]=p[(y)*W+x-3+2];
// 							pos[4]=p[(y)*W+x+2];
// 							pos[5]=p[(y)*W+x+3+2];
// 							pos[6]=p[(y+1)*W+x-3+2];
// 							pos[7]=p[(y+1)*W+x+2];
// 							pos[8]=p[(y+1)*W+x+3+2];
// 							f_semivariogram=( pow2(pos[0]-pos[4]) + pow2(pos[1]-pos[4]) + pow2(pos[2]-pos[4]) + pow2(pos[3]-pos[4]) + pow2(pos[5]-pos[4]) + pow2(pos[6]-pos[4]) + pow2(pos[7]-pos[4]) + pow2(pos[8]-pos[4]) )/(2*8);
// 							fout<<f_semivariogram;
// 							break;
// 					}
// 					fout<<std::endl;
// 				}	
// 			}
// 		}
// 	}
// 	//System::Runtime::InteropServices::Marshal::Copy(Target_Image,0,ptr,bmpData->Stride*Height);
// 	image->UnlockBits( bmpData );
// 	fout.close();
// }

float Semivariogram_One(Bitmap^ image, Point point, int channel)
{
	System::Drawing::Rectangle rect = System::Drawing::Rectangle(0, 0, image->Width, image->Height);
	System::Drawing::Imaging::BitmapData^ bmpData = image->LockBits(rect, System::Drawing::Imaging::ImageLockMode::ReadWrite, image->PixelFormat);
	IntPtr ptr = bmpData->Scan0;
	int W = image->Width * 3;
	Byte* p = (Byte*)((void*)ptr);

	int x = point.X, y = point.Y, pos[9];
	float f_semivariogram;
	pos[0] = p[(y - 1) * W + 3 * x - 3 + channel];
	pos[1] = p[(y - 1) * W + 3 * x + channel];
	pos[2] = p[(y - 1) * W + 3 * x + 3 + channel];
	pos[3] = p[(y)*W + 3 * x - 3 + channel];
	pos[4] = p[(y)*W + 3 * x + channel];
	pos[5] = p[(y)*W + 3 * x + 3 + channel];
	pos[6] = p[(y + 1) * W + 3 * x - 3 + channel];
	pos[7] = p[(y + 1) * W + 3 * x + channel];
	pos[8] = p[(y + 1) * W + 3 * x + 3 + channel];
	f_semivariogram = (pow2(pos[0] - pos[4]) + pow2(pos[1] - pos[4]) + pow2(pos[2] - pos[4]) + pow2(pos[3] - pos[4]) + pow2(pos[5] - pos[4]) + pow2(pos[6] - pos[4]) + pow2(pos[7] - pos[4]) + pow2(pos[8] - pos[4])) / (2 * 8);
	image->UnlockBits(bmpData);
	return f_semivariogram;
}

void mark_color(Bitmap^ image, Point point, int color)
{
	System::Drawing::Rectangle rect = System::Drawing::Rectangle(0, 0, image->Width, image->Height);
	System::Drawing::Imaging::BitmapData^ bmpData = image->LockBits(rect, System::Drawing::Imaging::ImageLockMode::ReadWrite, image->PixelFormat);
	IntPtr ptr = bmpData->Scan0;
	int W = image->Width * 3;
	Byte* p = (Byte*)((void*)ptr);

	int x = point.X, y = point.Y;
	switch (color)
	{
	case 0:
		p[(y)*W + x] = 0;
		p[(y)*W + x + 1] = 0;
		p[(y)*W + x + 2] = 0;
		break;
	case 1:
		p[(y)*W + x] = 0;
		p[(y)*W + x + 1] = 0;
		p[(y)*W + x + 2] = 0;
		break;
	case 2:
		p[(y)*W + x] = 255;
		p[(y)*W + x + 1] = 255;
		p[(y)*W + x + 2] = 255;
		break;
	}
	image->UnlockBits(bmpData);
}

std::vector<int> window_data(Point pos, int h, Bitmap^ image, int channel)
{
	System::Drawing::Imaging::PixelFormat pf = image->PixelFormat;
	if (pf != System::Drawing::Imaging::PixelFormat::Format24bppRgb)
	{
		MessageBox::Show("PixelFormat is not Format24bppRgb !");
	}
	System::Drawing::Rectangle rect = System::Drawing::Rectangle(0, 0, image->Width, image->Height);
	System::Drawing::Imaging::BitmapData^ bmpData = image->LockBits(rect, System::Drawing::Imaging::ImageLockMode::ReadWrite, image->PixelFormat);
	IntPtr ptr = bmpData->Scan0;
	int W = image->Width * 3;
	Byte* p = (Byte*)((void*)ptr);

	std::vector<int> data, test;
	data.resize((h * 2 + 1) * (h * 2 + 1));

	int count = 0;
	for (int y = pos.Y - h; y <= pos.Y + h; y++)
	{
		for (int x = pos.X - h; x <= pos.X + h; x++)
		{
			data[count] = p[y * W + 3 * x + channel];
			count++;
		}
	}
	image->UnlockBits(bmpData);
	return data;
}

float window_direction_process(int h, std::vector<int> data, int direction)
{
	float pow_sum = 0, count = 0;
	float result;
	for (int x = 0; x < (2 * h + 1); x++)
	{
		for (int y = 0; y < (2 * h + 1); y++)
		{
			switch (direction)
			{
			case 0:
				if (y == h && x != h)
				{
					pow_sum += pow2(data[y * (2 * h + 1) + x] - data[h * (2 * h + 1) + h]);
					count++;
				}
				break;
			case 1:
				if (x == h && y != h)
				{
					pow_sum += pow2(data[y * (2 * h + 1) + x] - data[h * (2 * h + 1) + h]);
					count++;
				}
				break;
			case 2:
				if ((y * (2 * h + 1) + x) % (2 * h) == 0 && x != h && y != h && (y * (2 * h + 1) + x) != 0 && (y * (2 * h + 1) + x) != (data.size() - 1))
				{
					pow_sum += pow2(data[y * (2 * h + 1) + x] - data[h * (2 * h + 1) + h]);
					count++;
				}
				break;
			case 3:
				if ((y * (2 * h + 1) + x) % (2 * h + 2) == 0 && x != h && y != h)
				{
					pow_sum += pow2(data[y * (2 * h + 1) + x] - data[h * (2 * h + 1) + h]);
					count++;
				}
				break;
			case 4:
				if (x != h && y != h)
				{
					pow_sum += pow2(data[y * (2 * h + 1) + x] - data[h * (2 * h + 1) + h]);
					count++;
				}
				break;
			}
		}
	}
	result = pow_sum / count;
	return result;
}

Bitmap^ Create_RGB_Image(Bitmap^ R, Bitmap^ G, Bitmap^ B)
{
	Bitmap^ combine_image = gcnew Bitmap(R->Width, R->Height, System::Drawing::Imaging::PixelFormat::Format24bppRgb);
	System::Drawing::Rectangle rect = System::Drawing::Rectangle(0, 0, R->Width, R->Height);
	System::Drawing::Imaging::PixelFormat pf = System::Drawing::Imaging::PixelFormat::Format24bppRgb;
	System::Drawing::Imaging::BitmapData^ bmpData = combine_image->LockBits(rect, System::Drawing::Imaging::ImageLockMode::ReadWrite, pf);
	System::Drawing::Imaging::BitmapData^ bmpData_R = R->LockBits(rect, System::Drawing::Imaging::ImageLockMode::ReadWrite, pf);
	System::Drawing::Imaging::BitmapData^ bmpData_G = G->LockBits(rect, System::Drawing::Imaging::ImageLockMode::ReadWrite, pf);
	System::Drawing::Imaging::BitmapData^ bmpData_B = B->LockBits(rect, System::Drawing::Imaging::ImageLockMode::ReadWrite, pf);
	IntPtr ptr = bmpData->Scan0;
	IntPtr ptr_R = bmpData_R->Scan0;
	IntPtr ptr_G = bmpData_G->Scan0;
	IntPtr ptr_B = bmpData_B->Scan0;
	int W = R->Width * 3;
	int BytesOfSkip = bmpData_R->Stride - W;
	int Height = R->Height;
	Byte* p = (Byte*)((void*)ptr);
	Byte* p_R = (Byte*)((void*)ptr_R);
	Byte* p_G = (Byte*)((void*)ptr_G);
	Byte* p_B = (Byte*)((void*)ptr_B);

	for (int y = 0; y < Height; y++)
	{
		for (int x = 0; x < W; x += 3)
		{
			p[0] = p_B[0];
			p[1] = p_G[0];
			p[2] = p_R[0];
			p += 3;
			p_B += 3;
			p_G += 3;
			p_R += 3;
		}
		p += BytesOfSkip;
		p_B += BytesOfSkip;
		p_G += BytesOfSkip;
		p_R += BytesOfSkip;
	}
	B->UnlockBits(bmpData_B);
	G->UnlockBits(bmpData_G);
	R->UnlockBits(bmpData_R);
	combine_image->UnlockBits(bmpData);
	return combine_image;
}

float window_cross_process(int h, std::vector<int> data1, std::vector<int> data2)
{
	int sum = 0, count = 0;
	float result;
	for (int x = 0; x < (2 * h + 1); x++)
	{
		for (int y = 0; y < (2 * h + 1); y++)
		{
			sum = sum + abs(data1[y * (2 * h + 1) + x] - data1[h * (2 * h + 1) + h]) * abs(data2[y * (2 * h + 1) + x] - data2[h * (2 * h + 1) + h]);
			count++;
		}
	}
	result = (float)sum / (float)count;
	return result;
}


void Semivariogram_direct_all(std::string file_name, Bitmap^ image, Bitmap^ image2, int channel, int direction, int h_num, std::vector<int> h)
{

	int W = image->Width * 3;
	int Height = image->Height;
	std::ofstream fout(file_name.c_str(), std::ios::out);
	fout << W / 3 - h[h_num - 1] * 2 << std::endl;
	fout << Height - 2 * h[h_num - 1] << std::endl;
	fout << h[h_num - 1] << std::endl;

	for (int y = 0; y < Height; y++)
	{
		if (y<h[h_num - 1] || y>Height - h[h_num - 1] - 1)
		{
		}
		else
		{
			for (int x = 0; x < W; x += 3)
			{
				if (x<3 * h[h_num - 1] || x>W - 3 * h[h_num - 1] - 3)
				{
				}
				else
				{
					Point p;
					p.X = x / 3;
					p.Y = y;
					float r0, r1, r2, r3;
					fout << "1";
					for (int i = 0; i != h.size(); i++)
					{
						if (channel >= 0 && channel <= 2)
						{
							fout << " " << i + 1 << ":" << window_direction_process(h[i], window_data(p, h[i], image, channel), direction);
						}
						else
						{
							switch (channel)
							{
							case 3:
								r0 = window_direction_process(h[i], window_data(p, h[i], image, 0), direction);
								r1 = window_direction_process(h[i], window_data(p, h[i], image, 1), direction);
								fout << " " << (i * 2) + 1 << ":" << r0 << " " << (i * 2) + 2 << ":" << r1;
								break;
							case 4:
								r1 = window_direction_process(h[i], window_data(p, h[i], image, 1), direction);
								r2 = window_direction_process(h[i], window_data(p, h[i], image, 2), direction);
								fout << " " << (i * 2) + 1 << ":" << r1 << " " << (i * 2) + 2 << ":" << r2;
								break;
							case 5:
								r0 = window_direction_process(h[i], window_data(p, h[i], image, 0), direction);
								r2 = window_direction_process(h[i], window_data(p, h[i], image, 2), direction);
								fout << " " << (i * 2) + 1 << ":" << r0 << " " << (i * 2) + 2 << ":" << r2;
								break;
							case 6:
								r0 = window_direction_process(h[i], window_data(p, h[i], image, 0), direction);
								r1 = window_direction_process(h[i], window_data(p, h[i], image, 1), direction);
								r2 = window_direction_process(h[i], window_data(p, h[i], image, 2), direction);
								fout << " " << (i * 3) + 1 << ":" << r0 << " " << (i * 3) + 2 << ":" << r1 << " " << (i * 3) + 3 << ":" << r2;
								break;
							case 7:
								if (image2 == nullptr)
								{
									r0 = window_direction_process(h[i], window_data(p, h[i], image, 0), direction);
									r1 = window_direction_process(h[i], window_data(p, h[i], image, 1), direction);
									r2 = window_direction_process(h[i], window_data(p, h[i], image, 2), direction);
									fout << " " << (i * 3) + 1 << ":" << r0 << " " << (i * 3) + 2 << ":" << r1 << " " << (i * 3) + 3 << ":" << r2;
									break;
								}
								else
								{
									r0 = window_direction_process(h[i], window_data(p, h[i], image, 0), direction);
									r1 = window_direction_process(h[i], window_data(p, h[i], image, 1), direction);
									r2 = window_direction_process(h[i], window_data(p, h[i], image, 2), direction);
									r3 = window_direction_process(h[i], window_data(p, h[i], image2, 0), direction);
									fout << " " << (i * 4) + 1 << ":" << r0 << " " << (i * 4) + 2 << ":" << r1 << " " << (i * 4) + 3 << ":" << r2 << " " << (i * 4) + 4 << ":" << r3;
									break;
								}
							}
						}
					}
					fout << std::endl;
				}
			}
		}
	}
	fout.close();
}


void Semivariogram_cross_all(std::string file_name, Bitmap^ image, Bitmap^ image2, int channel1, int channel2, int h_num, std::vector<int> h)
{
	if (image2 == nullptr)
		image2 = image;
	else
		channel2 = 0;
	int W = image->Width * 3;
	int Height = image->Height;
	std::ofstream fout(file_name.c_str(), std::ios::out);
	fout << W / 3 - h[h_num - 1] * 2 << std::endl;
	fout << Height - 2 * h[h_num - 1] << std::endl;
	fout << h[h_num - 1] << std::endl;

	for (int y = 0; y < Height; y++)
	{
		if (y<h[h_num - 1] || y>Height - h[h_num - 1] - 1)
		{
		}
		else
		{
			for (int x = 0; x < W; x += 3)
			{
				if (x<3 * h[h_num - 1] || x>W - 3 * h[h_num - 1] - 3)
				{
				}
				else
				{
					Point p;
					p.X = x / 3;
					p.Y = y;
					fout << "1";
					for (int i = 0; i != h.size(); i++)
					{
						fout << " " << i + 1 << ":" << window_cross_process(h[i], window_data(p, h[i], image, channel1), window_data(p, h[i], image2, channel2));
					}
					fout << std::endl;
				}
			}
		}
	}
	fout.close();
}

void Semivariogram_both_all(std::string file_name, Bitmap^ image, Bitmap^ image2, int channel, int direction, int channel1, int channel2, int h_num, std::vector<int> h)
{
	if (image2 == nullptr)
		image2 = image;
	else
		channel2 = 0;
	int W = image->Width * 3;
	int Height = image->Height;
	std::ofstream fout(file_name.c_str(), std::ios::out);
	fout << W / 3 - h[h_num - 1] * 2 << std::endl;
	fout << Height - 2 * h[h_num - 1] << std::endl;
	fout << h[h_num - 1] << std::endl;

	for (int y = 0; y < Height; y++)
	{
		if (y<h[h_num - 1] || y>Height - h[h_num - 1] - 1)
		{
		}
		else
		{
			for (int x = 0; x < W; x += 3)
			{
				if (x<3 * h[h_num - 1] || x>W - 3 * h[h_num - 1] - 3)
				{
				}
				else
				{
					Point p;
					p.X = x / 3;
					p.Y = y;
					float r0, r1, r2, r3;
					int index_count = 0;
					fout << "1";
					for (int i = 0; i != h.size(); i++)
					{
						if (channel >= 0 && channel <= 2)
						{
							fout << " " << i + 1 << ":" << window_direction_process(h[i], window_data(p, h[i], image, channel), direction);
							index_count++;
						}
						else
						{
							switch (channel)
							{
							case 3:
								r0 = window_direction_process(h[i], window_data(p, h[i], image, 0), direction);
								r1 = window_direction_process(h[i], window_data(p, h[i], image, 1), direction);
								fout << " " << (i * 2) + 1 << ":" << r0 << " " << (i * 2) + 2 << ":" << r1;
								index_count += 2;
								break;
							case 4:
								r1 = window_direction_process(h[i], window_data(p, h[i], image, 1), direction);
								r2 = window_direction_process(h[i], window_data(p, h[i], image, 2), direction);
								fout << " " << (i * 2) + 1 << ":" << r1 << " " << (i * 2) + 2 << ":" << r2;
								index_count += 2;
								break;
							case 5:
								r0 = window_direction_process(h[i], window_data(p, h[i], image, 0), direction);
								r2 = window_direction_process(h[i], window_data(p, h[i], image, 2), direction);
								fout << " " << (i * 2) + 1 << ":" << r0 << " " << (i * 2) + 2 << ":" << r2;
								index_count += 2;
								break;
							case 6:
								r0 = window_direction_process(h[i], window_data(p, h[i], image, 0), direction);
								r1 = window_direction_process(h[i], window_data(p, h[i], image, 1), direction);
								r2 = window_direction_process(h[i], window_data(p, h[i], image, 2), direction);
								fout << " " << (i * 3) + 1 << ":" << r0 << " " << (i * 3) + 2 << ":" << r1 << " " << (i * 3) + 3 << ":" << r2;
								index_count += 3;
								break;
							case 7:
								if (image2 == nullptr)
								{
									r0 = window_direction_process(h[i], window_data(p, h[i], image, 0), direction);
									r1 = window_direction_process(h[i], window_data(p, h[i], image, 1), direction);
									r2 = window_direction_process(h[i], window_data(p, h[i], image, 2), direction);
									fout << " " << (i * 3) + 1 << ":" << r0 << " " << (i * 3) + 2 << ":" << r1 << " " << (i * 3) + 3 << ":" << r2;
									index_count += 3;
									break;
								}
								else
								{
									r0 = window_direction_process(h[i], window_data(p, h[i], image, 0), direction);
									r1 = window_direction_process(h[i], window_data(p, h[i], image, 1), direction);
									r2 = window_direction_process(h[i], window_data(p, h[i], image, 2), direction);
									r3 = window_direction_process(h[i], window_data(p, h[i], image2, 0), direction);
									fout << " " << (i * 4) + 1 << ":" << r0 << " " << (i * 4) + 2 << ":" << r1 << " " << (i * 4) + 3 << ":" << r2 << " " << (i * 4) + 4 << ":" << r3;
									index_count += 4;
									break;
								}
							}
						}
					}
					for (int i = index_count; i < h.size() + index_count; i++)
					{
						fout << " " << i + 1 << ":" << window_cross_process(h[i - index_count], window_data(p, h[i - index_count], image, channel1), window_data(p, h[i - index_count], image2, channel2));
					}
					fout << std::endl;
				}
			}
		}
	}
	fout.close();
}
