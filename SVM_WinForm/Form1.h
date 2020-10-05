#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <fstream>
#include <algorithm>
#include "SVM_Package.h"
#include "StringConvertor.h"
#include "function.h"
#include "Form2.h"
#include "Form3.h"



#pragma once

namespace SVM_WinForm {

	using namespace System;
	using namespace System::IO;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Drawing::Drawing2D;
	using namespace System::Diagnostics;
	//using namespace std;
	using namespace System::Runtime::InteropServices;
	using namespace StringUtilities;


	/// <summary>
	/// Form1 的摘要
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: 在此加入建構函式程式碼
			//
		}


	protected:
		/// <summary>
		/// 清除任何使用中的資源。
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:

	private:
		/// <summary>
		/// 設計工具所需的變數。
		/// </summary>
	private: Bitmap^ image_raw_data, ^ image, ^ image_data;
	private: Bitmap^ band_image_1_ini, ^ band_image_2_ini, ^ band_image_3_ini, ^ band_image_4_ini;
	private: Bitmap^ band_image_1, ^ band_image_2, ^ band_image_3, ^ band_image_4;
	private: Point p;
	private: float imageAspect, controlAspect;
	private: int h_max;
	private: int* cls;
	private: bool right_click;
	private: Point max_XY, min_XY, imgLocation;
	private: array<Point>^ curvePoints, ^ curveDisPoints;
	private: List<Point>^ imgSelePoints, ^ visible_points, ^ imgDisPoints;
	private: struct svm_parameter* parameter;
	private: System::Drawing::Size size_panel7, size_panel1, size_pictureBox1;
	private: double ratio_Height, ratio_Width;
	private: Graphics^ imageRegionGraphics, ^ picGraphics;
	private: Drawing::Rectangle recImage;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ openImageToolStripMenuItem;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	private: System::ComponentModel::IContainer^ components;
	private: System::Windows::Forms::ToolStripMenuItem^ functionToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ windowsProcessToolStripMenuItem;
	private: System::Windows::Forms::SaveFileDialog^ saveFileDialog1;
	private: System::Windows::Forms::TabControl^ tabControl1;
	private: System::Windows::Forms::TabPage^ tabPage2;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Button^ button7;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::ProgressBar^ progressBar1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::ListBox^ listBox4;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::TabPage^ tabPage3;
	private: System::Windows::Forms::ToolStripMenuItem^ newFormToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ exitToolStripMenuItem;
	private: System::Windows::Forms::ListBox^ listBox6;
	private: System::Windows::Forms::ListBox^ listBox5;
	private: System::Windows::Forms::Button^ button9;
	private: System::Windows::Forms::ListBox^ listBox1;
	private: System::Windows::Forms::ToolStripMenuItem^ testToolStripMenuItem;
	private: System::Windows::Forms::ListBox^ listBox7;
	private: System::Windows::Forms::TabPage^ tabPage1;
	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::Label^ label16;
	private: System::Windows::Forms::Label^ label15;
	private: System::Windows::Forms::Label^ label14;
	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::Button^ button13;
	private: System::Windows::Forms::Button^ button12;
	private: System::Windows::Forms::Button^ button11;
	private: System::Windows::Forms::Button^ button10;
	private: System::Windows::Forms::PictureBox^ pictureBox3;
	private: System::Windows::Forms::PictureBox^ pictureBox5;
	private: System::Windows::Forms::PictureBox^ pictureBox4;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::Button^ button14;
	private: System::Windows::Forms::ListBox^ listBox10;
	private: System::Windows::Forms::ListBox^ listBox9;
	private: System::Windows::Forms::ListBox^ listBox8;
	private: System::Windows::Forms::ListBox^ listBox12;
	private: System::Windows::Forms::ListBox^ listBox11;
	private: System::Windows::Forms::Label^ label18;
	private: System::Windows::Forms::Label^ label17;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::ToolStripMenuItem^ clearListToolStripMenuItem;
	private: System::Windows::Forms::GroupBox^ groupBox3;
	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::Panel^ panel4;
	private: System::Windows::Forms::ToolStripMenuItem^ saveImageToolStripMenuItem;
	private: System::Windows::Forms::TabPage^ tabPage4;
	private: System::Windows::Forms::Panel^ panel5;
	private: System::Windows::Forms::CheckBox^ checkBox1;
	private: System::Windows::Forms::ListBox^ listBox13;
	private: System::Windows::Forms::Button^ button16;
	private: System::Windows::Forms::Button^ button15;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Button^ button17;
	private: System::Windows::Forms::Button^ button18;
	private: System::Windows::Forms::ToolStripMenuItem^ openImageNewWindowToolStripMenuItem;
	private: System::Windows::Forms::TabPage^ tabPage5;
	private: System::Windows::Forms::Panel^ panel6;
	private: System::Windows::Forms::Button^ button20;
	private: System::Windows::Forms::Button^ button19;
	private: System::Windows::Forms::Button^ button21;
	private: System::Windows::Forms::Button^ button22;
	private: System::Windows::Forms::Label^ label20;
	private: System::Windows::Forms::Label^ label19;
	private: System::Windows::Forms::ListBox^ listBox14;
	private: System::Windows::Forms::ListBox^ listBox15;
	private: System::Windows::Forms::Button^ button23;
	private: System::Windows::Forms::TabPage^ tabPage6;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Button^ button24;
	private: System::Windows::Forms::Button^ button25;
	private: System::Windows::Forms::ToolStripMenuItem^ clearOnlyFeaturesToolStripMenuItem;
	private: System::Windows::Forms::CheckBox^ checkBox2;
	private: System::Windows::Forms::ToolStripMenuItem^ displayNewImageAutoSizeToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ saveTrainingImageToolStripMenuItem;
	private: System::Windows::Forms::GroupBox^ groupBox4;
	private: System::Windows::Forms::Label^ label30;
	private: System::Windows::Forms::Label^ label28;
	private: System::Windows::Forms::Label^ label27;
	private: System::Windows::Forms::Label^ label25;
	private: System::Windows::Forms::Label^ label24;
	private: System::Windows::Forms::Label^ label22;
	private: System::Windows::Forms::Label^ label21;
	private: System::Windows::Forms::Label^ label29;
	private: System::Windows::Forms::Label^ label26;
	private: System::Windows::Forms::Label^ label23;
	private: System::Windows::Forms::Label^ label31;
	private: System::Windows::Forms::TrackBar^ trackBar1;
	private: System::Windows::Forms::Label^ label32;
	private: System::Windows::Forms::ListBox^ listBox3;
	private: System::Windows::Forms::ListBox^ listBox2;
	private: System::Windows::Forms::Panel^ panel7;
	private: System::Windows::Forms::Button^ button8;
	private: System::Windows::Forms::Panel^ panel8;
	private: System::Windows::Forms::ToolStripMenuItem^ windowToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ defaultSizeToolStripMenuItem;
	private: System::Windows::Forms::GroupBox^ groupBox5;
	private: System::Windows::Forms::Button^ button26;
	private: System::Windows::Forms::Label^ label33;
	private: System::Windows::Forms::Label^ label34;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label35;
	private: System::Windows::Forms::CheckBox^ checkBox4;
	private: System::Windows::Forms::TabPage^ tabPage7;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::ListBox^ listBox16;
	private: System::Windows::Forms::ListBox^ listBox17;
	private: System::Windows::Forms::GroupBox^ groupBox6;
	private: System::Windows::Forms::Label^ label36;
	private: System::Windows::Forms::Label^ label37;
	private: System::Windows::Forms::Label^ label38;
	private: System::Windows::Forms::Label^ label39;
	private: System::Windows::Forms::Label^ label40;
	private: System::Windows::Forms::Button^ button27;
	private: System::Windows::Forms::CheckBox^ checkBox3;






#pragma region Windows Form Designer generated code
		   /// <summary>
		   /// 此為設計工具支援所需的方法 - 請勿使用程式碼編輯器
		   /// 修改這個方法的內容。
		   /// </summary>
		   void InitializeComponent(void)
		   {
			   this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			   this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->newFormToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->openImageToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->openImageNewWindowToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->displayNewImageAutoSizeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->saveImageToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->saveTrainingImageToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->functionToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->windowsProcessToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->testToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->clearListToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->clearOnlyFeaturesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->windowToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->defaultSizeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			   this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			   this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			   this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			   this->panel3 = (gcnew System::Windows::Forms::Panel());
			   this->panel4 = (gcnew System::Windows::Forms::Panel());
			   this->label14 = (gcnew System::Windows::Forms::Label());
			   this->label13 = (gcnew System::Windows::Forms::Label());
			   this->label15 = (gcnew System::Windows::Forms::Label());
			   this->label16 = (gcnew System::Windows::Forms::Label());
			   this->button10 = (gcnew System::Windows::Forms::Button());
			   this->button11 = (gcnew System::Windows::Forms::Button());
			   this->button12 = (gcnew System::Windows::Forms::Button());
			   this->button13 = (gcnew System::Windows::Forms::Button());
			   this->label18 = (gcnew System::Windows::Forms::Label());
			   this->label17 = (gcnew System::Windows::Forms::Label());
			   this->label12 = (gcnew System::Windows::Forms::Label());
			   this->button14 = (gcnew System::Windows::Forms::Button());
			   this->listBox10 = (gcnew System::Windows::Forms::ListBox());
			   this->listBox9 = (gcnew System::Windows::Forms::ListBox());
			   this->listBox8 = (gcnew System::Windows::Forms::ListBox());
			   this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			   this->pictureBox5 = (gcnew System::Windows::Forms::PictureBox());
			   this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
			   this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			   this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			   this->panel2 = (gcnew System::Windows::Forms::Panel());
			   this->button26 = (gcnew System::Windows::Forms::Button());
			   this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			   this->listBox6 = (gcnew System::Windows::Forms::ListBox());
			   this->listBox4 = (gcnew System::Windows::Forms::ListBox());
			   this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			   this->listBox11 = (gcnew System::Windows::Forms::ListBox());
			   this->listBox12 = (gcnew System::Windows::Forms::ListBox());
			   this->listBox7 = (gcnew System::Windows::Forms::ListBox());
			   this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			   this->listBox5 = (gcnew System::Windows::Forms::ListBox());
			   this->button9 = (gcnew System::Windows::Forms::Button());
			   this->button5 = (gcnew System::Windows::Forms::Button());
			   this->button4 = (gcnew System::Windows::Forms::Button());
			   this->tabPage7 = (gcnew System::Windows::Forms::TabPage());
			   this->panel1 = (gcnew System::Windows::Forms::Panel());
			   this->listBox16 = (gcnew System::Windows::Forms::ListBox());
			   this->listBox17 = (gcnew System::Windows::Forms::ListBox());
			   this->groupBox6 = (gcnew System::Windows::Forms::GroupBox());
			   this->label36 = (gcnew System::Windows::Forms::Label());
			   this->label37 = (gcnew System::Windows::Forms::Label());
			   this->label38 = (gcnew System::Windows::Forms::Label());
			   this->label39 = (gcnew System::Windows::Forms::Label());
			   this->label40 = (gcnew System::Windows::Forms::Label());
			   this->button27 = (gcnew System::Windows::Forms::Button());
			   this->tabPage6 = (gcnew System::Windows::Forms::TabPage());
			   this->panel7 = (gcnew System::Windows::Forms::Panel());
			   this->groupBox5 = (gcnew System::Windows::Forms::GroupBox());
			   this->label10 = (gcnew System::Windows::Forms::Label());
			   this->label6 = (gcnew System::Windows::Forms::Label());
			   this->label9 = (gcnew System::Windows::Forms::Label());
			   this->label7 = (gcnew System::Windows::Forms::Label());
			   this->label8 = (gcnew System::Windows::Forms::Label());
			   this->button8 = (gcnew System::Windows::Forms::Button());
			   this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			   this->listBox3 = (gcnew System::Windows::Forms::ListBox());
			   this->listBox2 = (gcnew System::Windows::Forms::ListBox());
			   this->trackBar1 = (gcnew System::Windows::Forms::TrackBar());
			   this->label32 = (gcnew System::Windows::Forms::Label());
			   this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
			   this->panel8 = (gcnew System::Windows::Forms::Panel());
			   this->label31 = (gcnew System::Windows::Forms::Label());
			   this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			   this->checkBox4 = (gcnew System::Windows::Forms::CheckBox());
			   this->checkBox3 = (gcnew System::Windows::Forms::CheckBox());
			   this->label35 = (gcnew System::Windows::Forms::Label());
			   this->label33 = (gcnew System::Windows::Forms::Label());
			   this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			   this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			   this->label34 = (gcnew System::Windows::Forms::Label());
			   this->checkBox2 = (gcnew System::Windows::Forms::CheckBox());
			   this->button7 = (gcnew System::Windows::Forms::Button());
			   this->button6 = (gcnew System::Windows::Forms::Button());
			   this->button3 = (gcnew System::Windows::Forms::Button());
			   this->button2 = (gcnew System::Windows::Forms::Button());
			   this->label5 = (gcnew System::Windows::Forms::Label());
			   this->label4 = (gcnew System::Windows::Forms::Label());
			   this->label2 = (gcnew System::Windows::Forms::Label());
			   this->button1 = (gcnew System::Windows::Forms::Button());
			   this->progressBar1 = (gcnew System::Windows::Forms::ProgressBar());
			   this->label1 = (gcnew System::Windows::Forms::Label());
			   this->label3 = (gcnew System::Windows::Forms::Label());
			   this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			   this->label30 = (gcnew System::Windows::Forms::Label());
			   this->label29 = (gcnew System::Windows::Forms::Label());
			   this->label28 = (gcnew System::Windows::Forms::Label());
			   this->label27 = (gcnew System::Windows::Forms::Label());
			   this->label26 = (gcnew System::Windows::Forms::Label());
			   this->label25 = (gcnew System::Windows::Forms::Label());
			   this->label24 = (gcnew System::Windows::Forms::Label());
			   this->label23 = (gcnew System::Windows::Forms::Label());
			   this->label22 = (gcnew System::Windows::Forms::Label());
			   this->label21 = (gcnew System::Windows::Forms::Label());
			   this->tabPage4 = (gcnew System::Windows::Forms::TabPage());
			   this->panel5 = (gcnew System::Windows::Forms::Panel());
			   this->button25 = (gcnew System::Windows::Forms::Button());
			   this->button24 = (gcnew System::Windows::Forms::Button());
			   this->listBox14 = (gcnew System::Windows::Forms::ListBox());
			   this->button18 = (gcnew System::Windows::Forms::Button());
			   this->button17 = (gcnew System::Windows::Forms::Button());
			   this->label11 = (gcnew System::Windows::Forms::Label());
			   this->button16 = (gcnew System::Windows::Forms::Button());
			   this->button15 = (gcnew System::Windows::Forms::Button());
			   this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			   this->listBox13 = (gcnew System::Windows::Forms::ListBox());
			   this->tabPage5 = (gcnew System::Windows::Forms::TabPage());
			   this->panel6 = (gcnew System::Windows::Forms::Panel());
			   this->button23 = (gcnew System::Windows::Forms::Button());
			   this->listBox15 = (gcnew System::Windows::Forms::ListBox());
			   this->label20 = (gcnew System::Windows::Forms::Label());
			   this->label19 = (gcnew System::Windows::Forms::Label());
			   this->button22 = (gcnew System::Windows::Forms::Button());
			   this->button21 = (gcnew System::Windows::Forms::Button());
			   this->button20 = (gcnew System::Windows::Forms::Button());
			   this->button19 = (gcnew System::Windows::Forms::Button());
			   this->menuStrip1->SuspendLayout();
			   this->tabControl1->SuspendLayout();
			   this->tabPage1->SuspendLayout();
			   this->panel3->SuspendLayout();
			   this->panel4->SuspendLayout();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->BeginInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->BeginInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			   this->tabPage2->SuspendLayout();
			   this->panel2->SuspendLayout();
			   this->groupBox2->SuspendLayout();
			   this->groupBox3->SuspendLayout();
			   this->tabPage7->SuspendLayout();
			   this->panel1->SuspendLayout();
			   this->groupBox6->SuspendLayout();
			   this->tabPage6->SuspendLayout();
			   this->panel7->SuspendLayout();
			   this->groupBox5->SuspendLayout();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->BeginInit();
			   this->tabPage3->SuspendLayout();
			   this->panel8->SuspendLayout();
			   this->groupBox1->SuspendLayout();
			   this->groupBox4->SuspendLayout();
			   this->tabPage4->SuspendLayout();
			   this->panel5->SuspendLayout();
			   this->tabPage5->SuspendLayout();
			   this->panel6->SuspendLayout();
			   this->SuspendLayout();
			   // 
			   // menuStrip1
			   // 
			   this->menuStrip1->GripMargin = System::Windows::Forms::Padding(2, 2, 0, 2);
			   this->menuStrip1->ImageScalingSize = System::Drawing::Size(24, 24);
			   this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				   this->fileToolStripMenuItem,
					   this->functionToolStripMenuItem, this->windowToolStripMenuItem
			   });
			   this->menuStrip1->Location = System::Drawing::Point(0, 0);
			   this->menuStrip1->Name = L"menuStrip1";
			   this->menuStrip1->Size = System::Drawing::Size(1588, 40);
			   this->menuStrip1->TabIndex = 9;
			   this->menuStrip1->Text = L"menuStrip1";
			   // 
			   // fileToolStripMenuItem
			   // 
			   this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(7) {
				   this->newFormToolStripMenuItem,
					   this->openImageToolStripMenuItem, this->openImageNewWindowToolStripMenuItem, this->displayNewImageAutoSizeToolStripMenuItem,
					   this->saveImageToolStripMenuItem, this->saveTrainingImageToolStripMenuItem, this->exitToolStripMenuItem
			   });
			   this->fileToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(136)));
			   this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			   this->fileToolStripMenuItem->Size = System::Drawing::Size(68, 34);
			   this->fileToolStripMenuItem->Text = L"File";
			   // 
			   // newFormToolStripMenuItem
			   // 
			   this->newFormToolStripMenuItem->Name = L"newFormToolStripMenuItem";
			   this->newFormToolStripMenuItem->Size = System::Drawing::Size(456, 38);
			   this->newFormToolStripMenuItem->Text = L"New Form";
			   this->newFormToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::newFormToolStripMenuItem_Click);
			   // 
			   // openImageToolStripMenuItem
			   // 
			   this->openImageToolStripMenuItem->Name = L"openImageToolStripMenuItem";
			   this->openImageToolStripMenuItem->Size = System::Drawing::Size(456, 38);
			   this->openImageToolStripMenuItem->Text = L"Open Image";
			   this->openImageToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::openImageToolStripMenuItem_Click);
			   // 
			   // openImageNewWindowToolStripMenuItem
			   // 
			   this->openImageNewWindowToolStripMenuItem->Name = L"openImageNewWindowToolStripMenuItem";
			   this->openImageNewWindowToolStripMenuItem->Size = System::Drawing::Size(456, 38);
			   this->openImageNewWindowToolStripMenuItem->Text = L"Display New Image";
			   this->openImageNewWindowToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::openImageNewWindowToolStripMenuItem_Click);
			   // 
			   // displayNewImageAutoSizeToolStripMenuItem
			   // 
			   this->displayNewImageAutoSizeToolStripMenuItem->Name = L"displayNewImageAutoSizeToolStripMenuItem";
			   this->displayNewImageAutoSizeToolStripMenuItem->Size = System::Drawing::Size(456, 38);
			   this->displayNewImageAutoSizeToolStripMenuItem->Text = L"Display New Image (AutoSize)";
			   this->displayNewImageAutoSizeToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::displayNewImageAutoSizeToolStripMenuItem_Click);
			   // 
			   // saveImageToolStripMenuItem
			   // 
			   this->saveImageToolStripMenuItem->Name = L"saveImageToolStripMenuItem";
			   this->saveImageToolStripMenuItem->Size = System::Drawing::Size(456, 38);
			   this->saveImageToolStripMenuItem->Text = L"Save Image";
			   this->saveImageToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::saveImageToolStripMenuItem_Click);
			   // 
			   // saveTrainingImageToolStripMenuItem
			   // 
			   this->saveTrainingImageToolStripMenuItem->Name = L"saveTrainingImageToolStripMenuItem";
			   this->saveTrainingImageToolStripMenuItem->Size = System::Drawing::Size(456, 38);
			   this->saveTrainingImageToolStripMenuItem->Text = L"Save Training Image";
			   this->saveTrainingImageToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::saveTrainingImageToolStripMenuItem_Click);
			   // 
			   // exitToolStripMenuItem
			   // 
			   this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			   this->exitToolStripMenuItem->Size = System::Drawing::Size(456, 38);
			   this->exitToolStripMenuItem->Text = L"Exit";
			   this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::exitToolStripMenuItem_Click);
			   // 
			   // functionToolStripMenuItem
			   // 
			   this->functionToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				   this->windowsProcessToolStripMenuItem,
					   this->testToolStripMenuItem, this->clearListToolStripMenuItem, this->clearOnlyFeaturesToolStripMenuItem
			   });
			   this->functionToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(136)));
			   this->functionToolStripMenuItem->Name = L"functionToolStripMenuItem";
			   this->functionToolStripMenuItem->Size = System::Drawing::Size(129, 34);
			   this->functionToolStripMenuItem->Text = L"Function";
			   // 
			   // windowsProcessToolStripMenuItem
			   // 
			   this->windowsProcessToolStripMenuItem->Name = L"windowsProcessToolStripMenuItem";
			   this->windowsProcessToolStripMenuItem->Size = System::Drawing::Size(337, 38);
			   this->windowsProcessToolStripMenuItem->Text = L"mask";
			   this->windowsProcessToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::windowsProcessToolStripMenuItem_Click);
			   // 
			   // testToolStripMenuItem
			   // 
			   this->testToolStripMenuItem->Name = L"testToolStripMenuItem";
			   this->testToolStripMenuItem->Size = System::Drawing::Size(337, 38);
			   this->testToolStripMenuItem->Text = L"Nornal Image";
			   this->testToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::testToolStripMenuItem_Click);
			   // 
			   // clearListToolStripMenuItem
			   // 
			   this->clearListToolStripMenuItem->Name = L"clearListToolStripMenuItem";
			   this->clearListToolStripMenuItem->Size = System::Drawing::Size(337, 38);
			   this->clearListToolStripMenuItem->Text = L"Clear All List ";
			   this->clearListToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::clearListToolStripMenuItem_Click);
			   // 
			   // clearOnlyFeaturesToolStripMenuItem
			   // 
			   this->clearOnlyFeaturesToolStripMenuItem->Name = L"clearOnlyFeaturesToolStripMenuItem";
			   this->clearOnlyFeaturesToolStripMenuItem->Size = System::Drawing::Size(337, 38);
			   this->clearOnlyFeaturesToolStripMenuItem->Text = L"Clear Only Features";
			   this->clearOnlyFeaturesToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::clearOnlyFeaturesToolStripMenuItem_Click);
			   // 
			   // windowToolStripMenuItem
			   // 
			   this->windowToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->defaultSizeToolStripMenuItem });
			   this->windowToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(136)));
			   this->windowToolStripMenuItem->Name = L"windowToolStripMenuItem";
			   this->windowToolStripMenuItem->Size = System::Drawing::Size(123, 34);
			   this->windowToolStripMenuItem->Text = L"Window";
			   // 
			   // defaultSizeToolStripMenuItem
			   // 
			   this->defaultSizeToolStripMenuItem->Name = L"defaultSizeToolStripMenuItem";
			   this->defaultSizeToolStripMenuItem->Size = System::Drawing::Size(251, 38);
			   this->defaultSizeToolStripMenuItem->Text = L"Default Size";
			   this->defaultSizeToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::defaultSizeToolStripMenuItem_Click);
			   // 
			   // openFileDialog1
			   // 
			   this->openFileDialog1->FileName = L"openFileDialog1";
			   // 
			   // tabControl1
			   // 
			   this->tabControl1->Controls->Add(this->tabPage1);
			   this->tabControl1->Controls->Add(this->tabPage2);
			   this->tabControl1->Controls->Add(this->tabPage7);
			   this->tabControl1->Controls->Add(this->tabPage6);
			   this->tabControl1->Controls->Add(this->tabPage3);
			   this->tabControl1->Controls->Add(this->tabPage4);
			   this->tabControl1->Controls->Add(this->tabPage5);
			   this->tabControl1->Dock = System::Windows::Forms::DockStyle::Fill;
			   this->tabControl1->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(136)));
			   this->tabControl1->Location = System::Drawing::Point(0, 40);
			   this->tabControl1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			   this->tabControl1->Name = L"tabControl1";
			   this->tabControl1->SelectedIndex = 0;
			   this->tabControl1->Size = System::Drawing::Size(1588, 658);
			   this->tabControl1->TabIndex = 21;
			   // 
			   // tabPage1
			   // 
			   this->tabPage1->BackColor = System::Drawing::SystemColors::Control;
			   this->tabPage1->Controls->Add(this->panel3);
			   this->tabPage1->Location = System::Drawing::Point(4, 34);
			   this->tabPage1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			   this->tabPage1->Name = L"tabPage1";
			   this->tabPage1->Padding = System::Windows::Forms::Padding(4, 4, 4, 4);
			   this->tabPage1->Size = System::Drawing::Size(1580, 620);
			   this->tabPage1->TabIndex = 3;
			   this->tabPage1->Text = L"Band Image";
			   // 
			   // panel3
			   // 
			   this->panel3->AutoScroll = true;
			   this->panel3->AutoSize = true;
			   this->panel3->Controls->Add(this->panel4);
			   this->panel3->Controls->Add(this->label18);
			   this->panel3->Controls->Add(this->label17);
			   this->panel3->Controls->Add(this->label12);
			   this->panel3->Controls->Add(this->button14);
			   this->panel3->Controls->Add(this->listBox10);
			   this->panel3->Controls->Add(this->listBox9);
			   this->panel3->Controls->Add(this->listBox8);
			   this->panel3->Controls->Add(this->pictureBox3);
			   this->panel3->Controls->Add(this->pictureBox5);
			   this->panel3->Controls->Add(this->pictureBox4);
			   this->panel3->Controls->Add(this->pictureBox2);
			   this->panel3->Dock = System::Windows::Forms::DockStyle::Fill;
			   this->panel3->Location = System::Drawing::Point(4, 4);
			   this->panel3->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			   this->panel3->Name = L"panel3";
			   this->panel3->Size = System::Drawing::Size(1572, 612);
			   this->panel3->TabIndex = 0;
			   // 
			   // panel4
			   // 
			   this->panel4->Controls->Add(this->label14);
			   this->panel4->Controls->Add(this->label13);
			   this->panel4->Controls->Add(this->label15);
			   this->panel4->Controls->Add(this->label16);
			   this->panel4->Controls->Add(this->button10);
			   this->panel4->Controls->Add(this->button11);
			   this->panel4->Controls->Add(this->button12);
			   this->panel4->Controls->Add(this->button13);
			   this->panel4->Location = System::Drawing::Point(8, 39);
			   this->panel4->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			   this->panel4->Name = L"panel4";
			   this->panel4->Size = System::Drawing::Size(1377, 230);
			   this->panel4->TabIndex = 19;
			   // 
			   // label14
			   // 
			   this->label14->AutoSize = true;
			   this->label14->Location = System::Drawing::Point(232, 74);
			   this->label14->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->label14->Name = L"label14";
			   this->label14->Size = System::Drawing::Size(74, 24);
			   this->label14->TabIndex = 9;
			   this->label14->Text = L"Band 2";
			   // 
			   // label13
			   // 
			   this->label13->AutoSize = true;
			   this->label13->Location = System::Drawing::Point(232, 16);
			   this->label13->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->label13->Name = L"label13";
			   this->label13->Size = System::Drawing::Size(74, 24);
			   this->label13->TabIndex = 8;
			   this->label13->Text = L"Band 1";
			   // 
			   // label15
			   // 
			   this->label15->AutoSize = true;
			   this->label15->Location = System::Drawing::Point(232, 130);
			   this->label15->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->label15->Name = L"label15";
			   this->label15->Size = System::Drawing::Size(74, 24);
			   this->label15->TabIndex = 10;
			   this->label15->Text = L"Band 3";
			   // 
			   // label16
			   // 
			   this->label16->AutoSize = true;
			   this->label16->Location = System::Drawing::Point(232, 189);
			   this->label16->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->label16->Name = L"label16";
			   this->label16->Size = System::Drawing::Size(74, 24);
			   this->label16->TabIndex = 11;
			   this->label16->Text = L"Band 4";
			   // 
			   // button10
			   // 
			   this->button10->Location = System::Drawing::Point(4, 4);
			   this->button10->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			   this->button10->Name = L"button10";
			   this->button10->Size = System::Drawing::Size(204, 48);
			   this->button10->TabIndex = 4;
			   this->button10->Text = L"Band Image #1";
			   this->button10->UseVisualStyleBackColor = true;
			   this->button10->Click += gcnew System::EventHandler(this, &Form1::button10_Click);
			   // 
			   // button11
			   // 
			   this->button11->Location = System::Drawing::Point(4, 62);
			   this->button11->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			   this->button11->Name = L"button11";
			   this->button11->Size = System::Drawing::Size(204, 48);
			   this->button11->TabIndex = 5;
			   this->button11->Text = L"Band Image #2\r\n";
			   this->button11->UseVisualStyleBackColor = true;
			   this->button11->Click += gcnew System::EventHandler(this, &Form1::button11_Click);
			   // 
			   // button12
			   // 
			   this->button12->Location = System::Drawing::Point(4, 118);
			   this->button12->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			   this->button12->Name = L"button12";
			   this->button12->Size = System::Drawing::Size(204, 48);
			   this->button12->TabIndex = 6;
			   this->button12->Text = L"Band Image #3\r\n";
			   this->button12->UseVisualStyleBackColor = true;
			   this->button12->Click += gcnew System::EventHandler(this, &Form1::button12_Click);
			   // 
			   // button13
			   // 
			   this->button13->Location = System::Drawing::Point(4, 177);
			   this->button13->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			   this->button13->Name = L"button13";
			   this->button13->Size = System::Drawing::Size(204, 48);
			   this->button13->TabIndex = 7;
			   this->button13->Text = L"Band Image #4";
			   this->button13->UseVisualStyleBackColor = true;
			   this->button13->Click += gcnew System::EventHandler(this, &Form1::button13_Click);
			   // 
			   // label18
			   // 
			   this->label18->AutoSize = true;
			   this->label18->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(136)));
			   this->label18->Location = System::Drawing::Point(1400, 290);
			   this->label18->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->label18->Name = L"label18";
			   this->label18->Size = System::Drawing::Size(32, 24);
			   this->label18->TabIndex = 18;
			   this->label18->Text = L"G:";
			   // 
			   // label17
			   // 
			   this->label17->AutoSize = true;
			   this->label17->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(136)));
			   this->label17->Location = System::Drawing::Point(1400, 182);
			   this->label17->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->label17->Name = L"label17";
			   this->label17->Size = System::Drawing::Size(31, 24);
			   this->label17->TabIndex = 17;
			   this->label17->Text = L"B:";
			   // 
			   // label12
			   // 
			   this->label12->AutoSize = true;
			   this->label12->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(136)));
			   this->label12->Location = System::Drawing::Point(1400, 400);
			   this->label12->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->label12->Name = L"label12";
			   this->label12->Size = System::Drawing::Size(31, 24);
			   this->label12->TabIndex = 16;
			   this->label12->Text = L"R:";
			   // 
			   // button14
			   // 
			   this->button14->Location = System::Drawing::Point(1410, 476);
			   this->button14->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			   this->button14->Name = L"button14";
			   this->button14->Size = System::Drawing::Size(123, 93);
			   this->button14->TabIndex = 15;
			   this->button14->Text = L"Create RGB Image";
			   this->button14->UseVisualStyleBackColor = true;
			   this->button14->Click += gcnew System::EventHandler(this, &Form1::button14_Click);
			   // 
			   // listBox10
			   // 
			   this->listBox10->FormattingEnabled = true;
			   this->listBox10->ItemHeight = 24;
			   this->listBox10->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"Band1", L"Band2", L"Band3", L"Band4" });
			   this->listBox10->Location = System::Drawing::Point(1442, 362);
			   this->listBox10->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			   this->listBox10->Name = L"listBox10";
			   this->listBox10->Size = System::Drawing::Size(73, 100);
			   this->listBox10->TabIndex = 14;
			   // 
			   // listBox9
			   // 
			   this->listBox9->FormattingEnabled = true;
			   this->listBox9->ItemHeight = 24;
			   this->listBox9->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"Band1", L"Band2", L"Band3", L"Band4" });
			   this->listBox9->Location = System::Drawing::Point(1442, 250);
			   this->listBox9->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			   this->listBox9->Name = L"listBox9";
			   this->listBox9->Size = System::Drawing::Size(73, 100);
			   this->listBox9->TabIndex = 13;
			   // 
			   // listBox8
			   // 
			   this->listBox8->FormattingEnabled = true;
			   this->listBox8->ItemHeight = 24;
			   this->listBox8->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"Band1", L"Band2", L"Band3", L"Band4" });
			   this->listBox8->Location = System::Drawing::Point(1442, 140);
			   this->listBox8->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			   this->listBox8->Name = L"listBox8";
			   this->listBox8->Size = System::Drawing::Size(73, 100);
			   this->listBox8->TabIndex = 12;
			   // 
			   // pictureBox3
			   // 
			   this->pictureBox3->Location = System::Drawing::Point(354, 298);
			   this->pictureBox3->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			   this->pictureBox3->Name = L"pictureBox3";
			   this->pictureBox3->Size = System::Drawing::Size(338, 270);
			   this->pictureBox3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			   this->pictureBox3->TabIndex = 1;
			   this->pictureBox3->TabStop = false;
			   // 
			   // pictureBox5
			   // 
			   this->pictureBox5->Location = System::Drawing::Point(1047, 298);
			   this->pictureBox5->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			   this->pictureBox5->Name = L"pictureBox5";
			   this->pictureBox5->Size = System::Drawing::Size(338, 270);
			   this->pictureBox5->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			   this->pictureBox5->TabIndex = 3;
			   this->pictureBox5->TabStop = false;
			   this->pictureBox5->Click += gcnew System::EventHandler(this, &Form1::pictureBox5_Click);
			   // 
			   // pictureBox4
			   // 
			   this->pictureBox4->Location = System::Drawing::Point(700, 298);
			   this->pictureBox4->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			   this->pictureBox4->Name = L"pictureBox4";
			   this->pictureBox4->Size = System::Drawing::Size(338, 270);
			   this->pictureBox4->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			   this->pictureBox4->TabIndex = 2;
			   this->pictureBox4->TabStop = false;
			   // 
			   // pictureBox2
			   // 
			   this->pictureBox2->Location = System::Drawing::Point(8, 298);
			   this->pictureBox2->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			   this->pictureBox2->Name = L"pictureBox2";
			   this->pictureBox2->Size = System::Drawing::Size(338, 270);
			   this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			   this->pictureBox2->TabIndex = 0;
			   this->pictureBox2->TabStop = false;
			   // 
			   // tabPage2
			   // 
			   this->tabPage2->BackColor = System::Drawing::SystemColors::Control;
			   this->tabPage2->Controls->Add(this->panel2);
			   this->tabPage2->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(136)));
			   this->tabPage2->Location = System::Drawing::Point(4, 34);
			   this->tabPage2->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			   this->tabPage2->Name = L"tabPage2";
			   this->tabPage2->Padding = System::Windows::Forms::Padding(4, 4, 4, 4);
			   this->tabPage2->Size = System::Drawing::Size(1580, 618);
			   this->tabPage2->TabIndex = 1;
			   this->tabPage2->Text = L"Mode";
			   // 
			   // panel2
			   // 
			   this->panel2->AutoScroll = true;
			   this->panel2->AutoSize = true;
			   this->panel2->Controls->Add(this->button26);
			   this->panel2->Controls->Add(this->groupBox2);
			   this->panel2->Controls->Add(this->listBox4);
			   this->panel2->Controls->Add(this->groupBox3);
			   this->panel2->Controls->Add(this->listBox7);
			   this->panel2->Controls->Add(this->listBox1);
			   this->panel2->Controls->Add(this->listBox5);
			   this->panel2->Controls->Add(this->button9);
			   this->panel2->Controls->Add(this->button5);
			   this->panel2->Controls->Add(this->button4);
			   this->panel2->Dock = System::Windows::Forms::DockStyle::Fill;
			   this->panel2->Location = System::Drawing::Point(4, 4);
			   this->panel2->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			   this->panel2->Name = L"panel2";
			   this->panel2->Size = System::Drawing::Size(1572, 610);
			   this->panel2->TabIndex = 22;
			   // 
			   // button26
			   // 
			   this->button26->Location = System::Drawing::Point(442, 150);
			   this->button26->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			   this->button26->Name = L"button26";
			   this->button26->Size = System::Drawing::Size(183, 60);
			   this->button26->TabIndex = 29;
			   this->button26->Text = L"Refresh";
			   this->button26->UseVisualStyleBackColor = true;
			   this->button26->Click += gcnew System::EventHandler(this, &Form1::button26_Click);
			   // 
			   // groupBox2
			   // 
			   this->groupBox2->Controls->Add(this->listBox6);
			   this->groupBox2->Location = System::Drawing::Point(184, 0);
			   this->groupBox2->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			   this->groupBox2->Name = L"groupBox2";
			   this->groupBox2->Padding = System::Windows::Forms::Padding(4, 4, 4, 4);
			   this->groupBox2->Size = System::Drawing::Size(249, 168);
			   this->groupBox2->TabIndex = 27;
			   this->groupBox2->TabStop = false;
			   this->groupBox2->Text = L"Direct-Semivariogram";
			   // 
			   // listBox6
			   // 
			   this->listBox6->FormattingEnabled = true;
			   this->listBox6->ItemHeight = 24;
			   this->listBox6->Items->AddRange(gcnew cli::array< System::Object^  >(5) {
				   L"東-西 (0)", L"南-北 (90)", L"東北-西南 (45)", L"西北-東南 (135)",
					   L"等向性 (平均)"
			   });
			   this->listBox6->Location = System::Drawing::Point(9, 33);
			   this->listBox6->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			   this->listBox6->Name = L"listBox6";
			   this->listBox6->Size = System::Drawing::Size(229, 124);
			   this->listBox6->TabIndex = 23;
			   // 
			   // listBox4
			   // 
			   this->listBox4->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(136)));
			   this->listBox4->FormattingEnabled = true;
			   this->listBox4->HorizontalScrollbar = true;
			   this->listBox4->ItemHeight = 24;
			   this->listBox4->Location = System::Drawing::Point(634, 9);
			   this->listBox4->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			   this->listBox4->Name = L"listBox4";
			   this->listBox4->Size = System::Drawing::Size(691, 580);
			   this->listBox4->TabIndex = 16;
			   // 
			   // groupBox3
			   // 
			   this->groupBox3->Controls->Add(this->listBox11);
			   this->groupBox3->Controls->Add(this->listBox12);
			   this->groupBox3->Location = System::Drawing::Point(184, 177);
			   this->groupBox3->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			   this->groupBox3->Name = L"groupBox3";
			   this->groupBox3->Padding = System::Windows::Forms::Padding(4, 4, 4, 4);
			   this->groupBox3->Size = System::Drawing::Size(249, 141);
			   this->groupBox3->TabIndex = 28;
			   this->groupBox3->TabStop = false;
			   this->groupBox3->Text = L"Cross-Semivariogram";
			   // 
			   // listBox11
			   // 
			   this->listBox11->FormattingEnabled = true;
			   this->listBox11->ItemHeight = 24;
			   this->listBox11->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Band1 (B)", L"Band2 (G)", L"Band3 (R)" });
			   this->listBox11->Location = System::Drawing::Point(9, 28);
			   this->listBox11->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			   this->listBox11->Name = L"listBox11";
			   this->listBox11->Size = System::Drawing::Size(109, 100);
			   this->listBox11->TabIndex = 25;
			   // 
			   // listBox12
			   // 
			   this->listBox12->FormattingEnabled = true;
			   this->listBox12->ItemHeight = 24;
			   this->listBox12->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"Band1 (B)", L"Band2 (G)", L"Band3 (R)", L"Band4" });
			   this->listBox12->Location = System::Drawing::Point(129, 28);
			   this->listBox12->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			   this->listBox12->Name = L"listBox12";
			   this->listBox12->Size = System::Drawing::Size(109, 100);
			   this->listBox12->TabIndex = 26;
			   // 
			   // listBox7
			   // 
			   this->listBox7->FormattingEnabled = true;
			   this->listBox7->ItemHeight = 24;
			   this->listBox7->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Direct", L"Cross", L"Both" });
			   this->listBox7->Location = System::Drawing::Point(8, 96);
			   this->listBox7->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			   this->listBox7->Name = L"listBox7";
			   this->listBox7->Size = System::Drawing::Size(166, 76);
			   this->listBox7->TabIndex = 24;
			   // 
			   // listBox1
			   // 
			   this->listBox1->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(136)));
			   this->listBox1->FormattingEnabled = true;
			   this->listBox1->ItemHeight = 24;
			   this->listBox1->Items->AddRange(gcnew cli::array< System::Object^  >(8) {
				   L"B", L"G", L"R", L"B G", L"G R", L"B R", L"B G R",
					   L"B G R IR"
			   });
			   this->listBox1->Location = System::Drawing::Point(8, 345);
			   this->listBox1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			   this->listBox1->Name = L"listBox1";
			   this->listBox1->Size = System::Drawing::Size(166, 196);
			   this->listBox1->TabIndex = 20;
			   // 
			   // listBox5
			   // 
			   this->listBox5->FormattingEnabled = true;
			   this->listBox5->ItemHeight = 24;
			   this->listBox5->Items->AddRange(gcnew cli::array< System::Object^  >(6) {
				   L"3 x 3      (h=1)", L"5 x 5      (h=2)", L"7 x 7      (h=3)",
					   L"9 x 9      (h=4)", L"11 x 11  (h=5)", L"13 x 13  (h=6)"
			   });
			   this->listBox5->Location = System::Drawing::Point(8, 186);
			   this->listBox5->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			   this->listBox5->Name = L"listBox5";
			   this->listBox5->SelectionMode = System::Windows::Forms::SelectionMode::MultiSimple;
			   this->listBox5->Size = System::Drawing::Size(166, 148);
			   this->listBox5->TabIndex = 22;
			   // 
			   // button9
			   // 
			   this->button9->Location = System::Drawing::Point(8, 6);
			   this->button9->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			   this->button9->Name = L"button9";
			   this->button9->Size = System::Drawing::Size(168, 81);
			   this->button9->TabIndex = 21;
			   this->button9->Text = L"Full Image\r\nSemivariogram";
			   this->button9->UseVisualStyleBackColor = true;
			   this->button9->Click += gcnew System::EventHandler(this, &Form1::button9_Click);
			   // 
			   // button5
			   // 
			   this->button5->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(136)));
			   this->button5->Location = System::Drawing::Point(442, 80);
			   this->button5->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			   this->button5->Name = L"button5";
			   this->button5->Size = System::Drawing::Size(183, 62);
			   this->button5->TabIndex = 18;
			   this->button5->Text = L"Delete";
			   this->button5->UseVisualStyleBackColor = true;
			   this->button5->Click += gcnew System::EventHandler(this, &Form1::button5_Click);
			   // 
			   // button4
			   // 
			   this->button4->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(136)));
			   this->button4->Location = System::Drawing::Point(442, 9);
			   this->button4->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			   this->button4->Name = L"button4";
			   this->button4->Size = System::Drawing::Size(183, 62);
			   this->button4->TabIndex = 17;
			   this->button4->Text = L"Save All As File";
			   this->button4->UseVisualStyleBackColor = true;
			   this->button4->Click += gcnew System::EventHandler(this, &Form1::button4_Click);
			   // 
			   // tabPage7
			   // 
			   this->tabPage7->BackColor = System::Drawing::SystemColors::Control;
			   this->tabPage7->Controls->Add(this->panel1);
			   this->tabPage7->Location = System::Drawing::Point(4, 34);
			   this->tabPage7->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			   this->tabPage7->Name = L"tabPage7";
			   this->tabPage7->Padding = System::Windows::Forms::Padding(4, 4, 4, 4);
			   this->tabPage7->Size = System::Drawing::Size(1580, 618);
			   this->tabPage7->TabIndex = 7;
			   this->tabPage7->Text = L"Feature Selection";
			   // 
			   // panel1
			   // 
			   this->panel1->AutoScroll = true;
			   this->panel1->AutoSize = true;
			   this->panel1->Controls->Add(this->listBox16);
			   this->panel1->Controls->Add(this->listBox17);
			   this->panel1->Controls->Add(this->groupBox6);
			   this->panel1->Controls->Add(this->button27);
			   this->panel1->Cursor = System::Windows::Forms::Cursors::Cross;
			   this->panel1->Dock = System::Windows::Forms::DockStyle::Fill;
			   this->panel1->Location = System::Drawing::Point(4, 4);
			   this->panel1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			   this->panel1->Name = L"panel1";
			   this->panel1->Size = System::Drawing::Size(1572, 610);
			   this->panel1->TabIndex = 28;
			   this->panel1->SizeChanged += gcnew System::EventHandler(this, &Form1::panel1_SizeChanged);
			   this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::panel1_Paint);
			   this->panel1->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::panel1_MouseDown);
			   this->panel1->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::panel1_MouseMove);
			   // 
			   // listBox16
			   // 
			   this->listBox16->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(136)));
			   this->listBox16->FormattingEnabled = true;
			   this->listBox16->ItemHeight = 24;
			   this->listBox16->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"Red", L"Green", L"Blue", L"Black" });
			   this->listBox16->Location = System::Drawing::Point(8, 348);
			   this->listBox16->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			   this->listBox16->Name = L"listBox16";
			   this->listBox16->Size = System::Drawing::Size(82, 100);
			   this->listBox16->TabIndex = 30;
			   // 
			   // listBox17
			   // 
			   this->listBox17->Font = (gcnew System::Drawing::Font(L"新細明體", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(136)));
			   this->listBox17->FormattingEnabled = true;
			   this->listBox17->ItemHeight = 23;
			   this->listBox17->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Man-made", L"Not Man-made" });
			   this->listBox17->Location = System::Drawing::Point(100, 348);
			   this->listBox17->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			   this->listBox17->Name = L"listBox17";
			   this->listBox17->Size = System::Drawing::Size(136, 73);
			   this->listBox17->TabIndex = 29;
			   // 
			   // groupBox6
			   // 
			   this->groupBox6->Controls->Add(this->label36);
			   this->groupBox6->Controls->Add(this->label37);
			   this->groupBox6->Controls->Add(this->label38);
			   this->groupBox6->Controls->Add(this->label39);
			   this->groupBox6->Controls->Add(this->label40);
			   this->groupBox6->Location = System::Drawing::Point(8, 75);
			   this->groupBox6->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			   this->groupBox6->Name = L"groupBox6";
			   this->groupBox6->Padding = System::Windows::Forms::Padding(4, 4, 4, 4);
			   this->groupBox6->Size = System::Drawing::Size(231, 264);
			   this->groupBox6->TabIndex = 28;
			   this->groupBox6->TabStop = false;
			   this->groupBox6->Text = L"Information";
			   // 
			   // label36
			   // 
			   this->label36->AutoSize = true;
			   this->label36->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(136)));
			   this->label36->Location = System::Drawing::Point(10, 105);
			   this->label36->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->label36->Name = L"label36";
			   this->label36->Size = System::Drawing::Size(32, 72);
			   this->label36->TabIndex = 15;
			   this->label36->Text = L"R:\r\nG:\r\nB:";
			   // 
			   // label37
			   // 
			   this->label37->AutoSize = true;
			   this->label37->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(136)));
			   this->label37->Location = System::Drawing::Point(10, 34);
			   this->label37->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->label37->Name = L"label37";
			   this->label37->Size = System::Drawing::Size(38, 24);
			   this->label37->TabIndex = 11;
			   this->label37->Text = L"X: ";
			   // 
			   // label38
			   // 
			   this->label38->AutoSize = true;
			   this->label38->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(136)));
			   this->label38->Location = System::Drawing::Point(10, 225);
			   this->label38->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->label38->Name = L"label38";
			   this->label38->Size = System::Drawing::Size(32, 24);
			   this->label38->TabIndex = 14;
			   this->label38->Text = L"H:";
			   // 
			   // label39
			   // 
			   this->label39->AutoSize = true;
			   this->label39->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(136)));
			   this->label39->Location = System::Drawing::Point(10, 58);
			   this->label39->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->label39->Name = L"label39";
			   this->label39->Size = System::Drawing::Size(38, 24);
			   this->label39->TabIndex = 12;
			   this->label39->Text = L"Y: ";
			   // 
			   // label40
			   // 
			   this->label40->AutoSize = true;
			   this->label40->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(136)));
			   this->label40->Location = System::Drawing::Point(10, 201);
			   this->label40->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->label40->Name = L"label40";
			   this->label40->Size = System::Drawing::Size(37, 24);
			   this->label40->TabIndex = 13;
			   this->label40->Text = L"W:";
			   // 
			   // button27
			   // 
			   this->button27->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(136)));
			   this->button27->Location = System::Drawing::Point(4, 4);
			   this->button27->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			   this->button27->Name = L"button27";
			   this->button27->Size = System::Drawing::Size(234, 62);
			   this->button27->TabIndex = 27;
			   this->button27->Text = L"Open Image";
			   this->button27->UseVisualStyleBackColor = true;
			   this->button27->Click += gcnew System::EventHandler(this, &Form1::button27_Click);
			   // 
			   // tabPage6
			   // 
			   this->tabPage6->BackColor = System::Drawing::SystemColors::Control;
			   this->tabPage6->Controls->Add(this->panel7);
			   this->tabPage6->Location = System::Drawing::Point(4, 34);
			   this->tabPage6->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			   this->tabPage6->Name = L"tabPage6";
			   this->tabPage6->Padding = System::Windows::Forms::Padding(4, 4, 4, 4);
			   this->tabPage6->Size = System::Drawing::Size(1580, 618);
			   this->tabPage6->TabIndex = 6;
			   this->tabPage6->Text = L"Feature";
			   // 
			   // panel7
			   // 
			   this->panel7->AutoScroll = true;
			   this->panel7->AutoSize = true;
			   this->panel7->Controls->Add(this->groupBox5);
			   this->panel7->Controls->Add(this->button8);
			   this->panel7->Controls->Add(this->pictureBox1);
			   this->panel7->Controls->Add(this->listBox3);
			   this->panel7->Controls->Add(this->listBox2);
			   this->panel7->Controls->Add(this->trackBar1);
			   this->panel7->Controls->Add(this->label32);
			   this->panel7->Dock = System::Windows::Forms::DockStyle::Fill;
			   this->panel7->Location = System::Drawing::Point(4, 4);
			   this->panel7->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			   this->panel7->Name = L"panel7";
			   this->panel7->Size = System::Drawing::Size(1572, 610);
			   this->panel7->TabIndex = 26;
			   this->panel7->SizeChanged += gcnew System::EventHandler(this, &Form1::panel7_SizeChanged);
			   // 
			   // groupBox5
			   // 
			   this->groupBox5->Controls->Add(this->label10);
			   this->groupBox5->Controls->Add(this->label6);
			   this->groupBox5->Controls->Add(this->label9);
			   this->groupBox5->Controls->Add(this->label7);
			   this->groupBox5->Controls->Add(this->label8);
			   this->groupBox5->Location = System::Drawing::Point(8, 75);
			   this->groupBox5->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			   this->groupBox5->Name = L"groupBox5";
			   this->groupBox5->Padding = System::Windows::Forms::Padding(4, 4, 4, 4);
			   this->groupBox5->Size = System::Drawing::Size(231, 264);
			   this->groupBox5->TabIndex = 27;
			   this->groupBox5->TabStop = false;
			   this->groupBox5->Text = L"Information";
			   // 
			   // label10
			   // 
			   this->label10->AutoSize = true;
			   this->label10->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(136)));
			   this->label10->Location = System::Drawing::Point(10, 105);
			   this->label10->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->label10->Name = L"label10";
			   this->label10->Size = System::Drawing::Size(32, 72);
			   this->label10->TabIndex = 15;
			   this->label10->Text = L"R:\r\nG:\r\nB:";
			   // 
			   // label6
			   // 
			   this->label6->AutoSize = true;
			   this->label6->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(136)));
			   this->label6->Location = System::Drawing::Point(10, 34);
			   this->label6->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->label6->Name = L"label6";
			   this->label6->Size = System::Drawing::Size(38, 24);
			   this->label6->TabIndex = 11;
			   this->label6->Text = L"X: ";
			   // 
			   // label9
			   // 
			   this->label9->AutoSize = true;
			   this->label9->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(136)));
			   this->label9->Location = System::Drawing::Point(10, 225);
			   this->label9->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->label9->Name = L"label9";
			   this->label9->Size = System::Drawing::Size(32, 24);
			   this->label9->TabIndex = 14;
			   this->label9->Text = L"H:";
			   // 
			   // label7
			   // 
			   this->label7->AutoSize = true;
			   this->label7->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(136)));
			   this->label7->Location = System::Drawing::Point(10, 58);
			   this->label7->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->label7->Name = L"label7";
			   this->label7->Size = System::Drawing::Size(38, 24);
			   this->label7->TabIndex = 12;
			   this->label7->Text = L"Y: ";
			   // 
			   // label8
			   // 
			   this->label8->AutoSize = true;
			   this->label8->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(136)));
			   this->label8->Location = System::Drawing::Point(10, 201);
			   this->label8->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->label8->Name = L"label8";
			   this->label8->Size = System::Drawing::Size(37, 24);
			   this->label8->TabIndex = 13;
			   this->label8->Text = L"W:";
			   // 
			   // button8
			   // 
			   this->button8->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(136)));
			   this->button8->Location = System::Drawing::Point(4, 4);
			   this->button8->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			   this->button8->Name = L"button8";
			   this->button8->Size = System::Drawing::Size(234, 62);
			   this->button8->TabIndex = 26;
			   this->button8->Text = L"Open Image";
			   this->button8->UseVisualStyleBackColor = true;
			   this->button8->Click += gcnew System::EventHandler(this, &Form1::button8_Click);
			   // 
			   // pictureBox1
			   // 
			   this->pictureBox1->AccessibleRole = System::Windows::Forms::AccessibleRole::IpAddress;
			   this->pictureBox1->Cursor = System::Windows::Forms::Cursors::Cross;
			   this->pictureBox1->Location = System::Drawing::Point(243, 4);
			   this->pictureBox1->Margin = System::Windows::Forms::Padding(0);
			   this->pictureBox1->Name = L"pictureBox1";
			   this->pictureBox1->Size = System::Drawing::Size(300, 300);
			   this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			   this->pictureBox1->TabIndex = 22;
			   this->pictureBox1->TabStop = false;
			   this->pictureBox1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::pictureBox1_Paint);
			   this->pictureBox1->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox1_MouseDown);
			   this->pictureBox1->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox1_MouseMove);
			   // 
			   // listBox3
			   // 
			   this->listBox3->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(136)));
			   this->listBox3->FormattingEnabled = true;
			   this->listBox3->ItemHeight = 24;
			   this->listBox3->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"Red", L"Green", L"Blue", L"Black" });
			   this->listBox3->Location = System::Drawing::Point(8, 348);
			   this->listBox3->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			   this->listBox3->Name = L"listBox3";
			   this->listBox3->Size = System::Drawing::Size(82, 100);
			   this->listBox3->TabIndex = 25;
			   // 
			   // listBox2
			   // 
			   this->listBox2->Font = (gcnew System::Drawing::Font(L"新細明體", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(136)));
			   this->listBox2->FormattingEnabled = true;
			   this->listBox2->ItemHeight = 23;
			   this->listBox2->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Man-made", L"Not Man-made" });
			   this->listBox2->Location = System::Drawing::Point(100, 348);
			   this->listBox2->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			   this->listBox2->Name = L"listBox2";
			   this->listBox2->Size = System::Drawing::Size(136, 73);
			   this->listBox2->TabIndex = 24;
			   // 
			   // trackBar1
			   // 
			   this->trackBar1->LargeChange = 6;
			   this->trackBar1->Location = System::Drawing::Point(8, 459);
			   this->trackBar1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			   this->trackBar1->Maximum = 32;
			   this->trackBar1->Name = L"trackBar1";
			   this->trackBar1->Size = System::Drawing::Size(231, 69);
			   this->trackBar1->SmallChange = 2;
			   this->trackBar1->TabIndex = 1;
			   this->trackBar1->TickFrequency = 4;
			   this->trackBar1->TickStyle = System::Windows::Forms::TickStyle::TopLeft;
			   this->trackBar1->Scroll += gcnew System::EventHandler(this, &Form1::trackBar1_Scroll);
			   // 
			   // label32
			   // 
			   this->label32->AutoSize = true;
			   this->label32->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(136)));
			   this->label32->Location = System::Drawing::Point(3, 531);
			   this->label32->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->label32->Name = L"label32";
			   this->label32->Size = System::Drawing::Size(72, 24);
			   this->label32->TabIndex = 16;
			   this->label32->Text = L"Size: 0";
			   // 
			   // tabPage3
			   // 
			   this->tabPage3->BackColor = System::Drawing::SystemColors::Control;
			   this->tabPage3->Controls->Add(this->panel8);
			   this->tabPage3->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(136)));
			   this->tabPage3->Location = System::Drawing::Point(4, 34);
			   this->tabPage3->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			   this->tabPage3->Name = L"tabPage3";
			   this->tabPage3->Padding = System::Windows::Forms::Padding(4, 4, 4, 4);
			   this->tabPage3->Size = System::Drawing::Size(1580, 618);
			   this->tabPage3->TabIndex = 2;
			   this->tabPage3->Text = L"SVM";
			   // 
			   // panel8
			   // 
			   this->panel8->AutoScroll = true;
			   this->panel8->AutoSize = true;
			   this->panel8->Controls->Add(this->label31);
			   this->panel8->Controls->Add(this->groupBox1);
			   this->panel8->Controls->Add(this->groupBox4);
			   this->panel8->Location = System::Drawing::Point(4, 4);
			   this->panel8->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			   this->panel8->Name = L"panel8";
			   this->panel8->Size = System::Drawing::Size(1540, 602);
			   this->panel8->TabIndex = 25;
			   // 
			   // label31
			   // 
			   this->label31->AutoSize = true;
			   this->label31->Location = System::Drawing::Point(879, 356);
			   this->label31->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->label31->Name = L"label31";
			   this->label31->Size = System::Drawing::Size(217, 24);
			   this->label31->TabIndex = 24;
			   this->label31->Text = L"Overall Accuracy: 0% ";
			   // 
			   // groupBox1
			   // 
			   this->groupBox1->Controls->Add(this->checkBox4);
			   this->groupBox1->Controls->Add(this->checkBox3);
			   this->groupBox1->Controls->Add(this->label35);
			   this->groupBox1->Controls->Add(this->label33);
			   this->groupBox1->Controls->Add(this->textBox2);
			   this->groupBox1->Controls->Add(this->textBox1);
			   this->groupBox1->Controls->Add(this->label34);
			   this->groupBox1->Controls->Add(this->checkBox2);
			   this->groupBox1->Controls->Add(this->button7);
			   this->groupBox1->Controls->Add(this->button6);
			   this->groupBox1->Controls->Add(this->button3);
			   this->groupBox1->Controls->Add(this->button2);
			   this->groupBox1->Controls->Add(this->label5);
			   this->groupBox1->Controls->Add(this->label4);
			   this->groupBox1->Controls->Add(this->label2);
			   this->groupBox1->Controls->Add(this->button1);
			   this->groupBox1->Controls->Add(this->progressBar1);
			   this->groupBox1->Controls->Add(this->label1);
			   this->groupBox1->Controls->Add(this->label3);
			   this->groupBox1->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(136)));
			   this->groupBox1->Location = System::Drawing::Point(4, 4);
			   this->groupBox1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			   this->groupBox1->Name = L"groupBox1";
			   this->groupBox1->Padding = System::Windows::Forms::Padding(4, 4, 4, 4);
			   this->groupBox1->Size = System::Drawing::Size(848, 592);
			   this->groupBox1->TabIndex = 22;
			   this->groupBox1->TabStop = false;
			   this->groupBox1->Text = L"SVM";
			   // 
			   // checkBox4
			   // 
			   this->checkBox4->AutoSize = true;
			   this->checkBox4->Checked = true;
			   this->checkBox4->CheckState = System::Windows::Forms::CheckState::Checked;
			   this->checkBox4->Location = System::Drawing::Point(502, 168);
			   this->checkBox4->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			   this->checkBox4->Name = L"checkBox4";
			   this->checkBox4->Size = System::Drawing::Size(133, 28);
			   this->checkBox4->TabIndex = 28;
			   this->checkBox4->Text = L"Quick Run";
			   this->checkBox4->UseVisualStyleBackColor = true;
			   // 
			   // checkBox3
			   // 
			   this->checkBox3->AutoSize = true;
			   this->checkBox3->Location = System::Drawing::Point(549, 366);
			   this->checkBox3->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			   this->checkBox3->Name = L"checkBox3";
			   this->checkBox3->Size = System::Drawing::Size(176, 28);
			   this->checkBox3->TabIndex = 27;
			   this->checkBox3->Text = L"Fixed Paramter";
			   this->checkBox3->UseVisualStyleBackColor = true;
			   // 
			   // label35
			   // 
			   this->label35->AutoSize = true;
			   this->label35->Location = System::Drawing::Point(27, 368);
			   this->label35->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->label35->Name = L"label35";
			   this->label35->Size = System::Drawing::Size(32, 24);
			   this->label35->TabIndex = 26;
			   this->label35->Text = L"G:";
			   // 
			   // label33
			   // 
			   this->label33->AutoSize = true;
			   this->label33->Location = System::Drawing::Point(28, 303);
			   this->label33->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->label33->Name = L"label33";
			   this->label33->Size = System::Drawing::Size(31, 24);
			   this->label33->TabIndex = 25;
			   this->label33->Text = L"C:";
			   // 
			   // textBox2
			   // 
			   this->textBox2->Location = System::Drawing::Point(74, 363);
			   this->textBox2->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			   this->textBox2->Name = L"textBox2";
			   this->textBox2->Size = System::Drawing::Size(66, 36);
			   this->textBox2->TabIndex = 16;
			   // 
			   // textBox1
			   // 
			   this->textBox1->Location = System::Drawing::Point(74, 298);
			   this->textBox1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			   this->textBox1->Name = L"textBox1";
			   this->textBox1->Size = System::Drawing::Size(66, 36);
			   this->textBox1->TabIndex = 15;
			   // 
			   // label34
			   // 
			   this->label34->AutoSize = true;
			   this->label34->Location = System::Drawing::Point(544, 288);
			   this->label34->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->label34->Name = L"label34";
			   this->label34->Size = System::Drawing::Size(182, 72);
			   this->label34->TabIndex = 14;
			   this->label34->Text = L"Optimal Parameter\r\nC:\r\nG:";
			   // 
			   // checkBox2
			   // 
			   this->checkBox2->AutoSize = true;
			   this->checkBox2->Checked = true;
			   this->checkBox2->CheckState = System::Windows::Forms::CheckState::Checked;
			   this->checkBox2->Location = System::Drawing::Point(344, 168);
			   this->checkBox2->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			   this->checkBox2->Name = L"checkBox2";
			   this->checkBox2->Size = System::Drawing::Size(142, 28);
			   this->checkBox2->TabIndex = 13;
			   this->checkBox2->Text = L"Use Header";
			   this->checkBox2->UseVisualStyleBackColor = true;
			   this->checkBox2->CheckedChanged += gcnew System::EventHandler(this, &Form1::checkBox2_CheckedChanged);
			   // 
			   // button7
			   // 
			   this->button7->Location = System::Drawing::Point(344, 352);
			   this->button7->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			   this->button7->Name = L"button7";
			   this->button7->Size = System::Drawing::Size(178, 56);
			   this->button7->TabIndex = 12;
			   this->button7->Text = L"Load Result";
			   this->button7->UseVisualStyleBackColor = true;
			   this->button7->Click += gcnew System::EventHandler(this, &Form1::button7_Click);
			   // 
			   // button6
			   // 
			   this->button6->Location = System::Drawing::Point(344, 288);
			   this->button6->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			   this->button6->Name = L"button6";
			   this->button6->Size = System::Drawing::Size(178, 56);
			   this->button6->TabIndex = 11;
			   this->button6->Text = L"Display Result";
			   this->button6->UseVisualStyleBackColor = true;
			   this->button6->Click += gcnew System::EventHandler(this, &Form1::button6_Click);
			   // 
			   // button3
			   // 
			   this->button3->Location = System::Drawing::Point(216, 165);
			   this->button3->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			   this->button3->Name = L"button3";
			   this->button3->Size = System::Drawing::Size(87, 34);
			   this->button3->TabIndex = 10;
			   this->button3->Text = L"File";
			   this->button3->UseVisualStyleBackColor = true;
			   this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
			   // 
			   // button2
			   // 
			   this->button2->Location = System::Drawing::Point(216, 57);
			   this->button2->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			   this->button2->Name = L"button2";
			   this->button2->Size = System::Drawing::Size(87, 34);
			   this->button2->TabIndex = 9;
			   this->button2->Text = L"File";
			   this->button2->UseVisualStyleBackColor = true;
			   this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			   // 
			   // label5
			   // 
			   this->label5->AutoSize = true;
			   this->label5->Font = (gcnew System::Drawing::Font(L"新細明體", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(136)));
			   this->label5->Location = System::Drawing::Point(28, 225);
			   this->label5->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->label5->Name = L"label5";
			   this->label5->Size = System::Drawing::Size(0, 20);
			   this->label5->TabIndex = 8;
			   // 
			   // label4
			   // 
			   this->label4->AutoSize = true;
			   this->label4->Font = (gcnew System::Drawing::Font(L"新細明體", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(136)));
			   this->label4->Location = System::Drawing::Point(28, 120);
			   this->label4->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->label4->Name = L"label4";
			   this->label4->Size = System::Drawing::Size(0, 20);
			   this->label4->TabIndex = 7;
			   // 
			   // label2
			   // 
			   this->label2->AutoSize = true;
			   this->label2->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(136)));
			   this->label2->Location = System::Drawing::Point(27, 62);
			   this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->label2->Name = L"label2";
			   this->label2->Size = System::Drawing::Size(164, 30);
			   this->label2->TabIndex = 4;
			   this->label2->Text = L"Training Data";
			   // 
			   // button1
			   // 
			   this->button1->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(136)));
			   this->button1->Location = System::Drawing::Point(150, 288);
			   this->button1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			   this->button1->Name = L"button1";
			   this->button1->Size = System::Drawing::Size(178, 56);
			   this->button1->TabIndex = 0;
			   this->button1->Text = L"Run";
			   this->button1->UseVisualStyleBackColor = true;
			   this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			   // 
			   // progressBar1
			   // 
			   this->progressBar1->Location = System::Drawing::Point(150, 352);
			   this->progressBar1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			   this->progressBar1->Name = L"progressBar1";
			   this->progressBar1->Size = System::Drawing::Size(178, 56);
			   this->progressBar1->TabIndex = 6;
			   // 
			   // label1
			   // 
			   this->label1->AutoSize = true;
			   this->label1->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(136)));
			   this->label1->Location = System::Drawing::Point(28, 420);
			   this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->label1->Name = L"label1";
			   this->label1->Size = System::Drawing::Size(79, 24);
			   this->label1->TabIndex = 1;
			   this->label1->Text = L"Result: ";
			   // 
			   // label3
			   // 
			   this->label3->AutoSize = true;
			   this->label3->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(136)));
			   this->label3->Location = System::Drawing::Point(27, 168);
			   this->label3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->label3->Name = L"label3";
			   this->label3->Size = System::Drawing::Size(155, 30);
			   this->label3->TabIndex = 5;
			   this->label3->Text = L"Testing Data";
			   // 
			   // groupBox4
			   // 
			   this->groupBox4->Controls->Add(this->label30);
			   this->groupBox4->Controls->Add(this->label29);
			   this->groupBox4->Controls->Add(this->label28);
			   this->groupBox4->Controls->Add(this->label27);
			   this->groupBox4->Controls->Add(this->label26);
			   this->groupBox4->Controls->Add(this->label25);
			   this->groupBox4->Controls->Add(this->label24);
			   this->groupBox4->Controls->Add(this->label23);
			   this->groupBox4->Controls->Add(this->label22);
			   this->groupBox4->Controls->Add(this->label21);
			   this->groupBox4->Location = System::Drawing::Point(861, 4);
			   this->groupBox4->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			   this->groupBox4->Name = L"groupBox4";
			   this->groupBox4->Padding = System::Windows::Forms::Padding(4, 4, 4, 4);
			   this->groupBox4->Size = System::Drawing::Size(398, 318);
			   this->groupBox4->TabIndex = 23;
			   this->groupBox4->TabStop = false;
			   this->groupBox4->Text = L"Confusion Matrix";
			   // 
			   // label30
			   // 
			   this->label30->Location = System::Drawing::Point(138, 34);
			   this->label30->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->label30->Name = L"label30";
			   this->label30->Size = System::Drawing::Size(240, 60);
			   this->label30->TabIndex = 9;
			   this->label30->Text = L"Ground Truth\r\n(Percent)";
			   this->label30->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			   // 
			   // label29
			   // 
			   this->label29->Location = System::Drawing::Point(258, 250);
			   this->label29->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->label29->Name = L"label29";
			   this->label29->Size = System::Drawing::Size(120, 45);
			   this->label29->TabIndex = 8;
			   this->label29->Text = L"label29";
			   this->label29->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			   // 
			   // label28
			   // 
			   this->label28->Location = System::Drawing::Point(138, 250);
			   this->label28->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->label28->Name = L"label28";
			   this->label28->Size = System::Drawing::Size(120, 45);
			   this->label28->TabIndex = 7;
			   this->label28->Text = L"label28";
			   this->label28->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			   // 
			   // label27
			   // 
			   this->label27->Location = System::Drawing::Point(18, 250);
			   this->label27->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->label27->Name = L"label27";
			   this->label27->Size = System::Drawing::Size(120, 45);
			   this->label27->TabIndex = 6;
			   this->label27->Text = L"Not\r\nMan-made\r\n";
			   this->label27->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			   // 
			   // label26
			   // 
			   this->label26->Location = System::Drawing::Point(258, 172);
			   this->label26->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->label26->Name = L"label26";
			   this->label26->Size = System::Drawing::Size(120, 45);
			   this->label26->TabIndex = 5;
			   this->label26->Text = L"label26";
			   this->label26->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			   // 
			   // label25
			   // 
			   this->label25->Location = System::Drawing::Point(138, 172);
			   this->label25->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->label25->Name = L"label25";
			   this->label25->Size = System::Drawing::Size(120, 45);
			   this->label25->TabIndex = 4;
			   this->label25->Text = L"label25";
			   this->label25->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			   // 
			   // label24
			   // 
			   this->label24->Location = System::Drawing::Point(18, 172);
			   this->label24->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->label24->Name = L"label24";
			   this->label24->Size = System::Drawing::Size(120, 45);
			   this->label24->TabIndex = 3;
			   this->label24->Text = L"Man-made";
			   this->label24->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			   // 
			   // label23
			   // 
			   this->label23->Location = System::Drawing::Point(258, 94);
			   this->label23->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->label23->Name = L"label23";
			   this->label23->Size = System::Drawing::Size(120, 45);
			   this->label23->TabIndex = 2;
			   this->label23->Text = L"Not\r\nMan-made";
			   this->label23->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			   // 
			   // label22
			   // 
			   this->label22->Location = System::Drawing::Point(138, 94);
			   this->label22->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->label22->Name = L"label22";
			   this->label22->Size = System::Drawing::Size(120, 45);
			   this->label22->TabIndex = 1;
			   this->label22->Text = L"Man-made";
			   this->label22->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			   // 
			   // label21
			   // 
			   this->label21->Location = System::Drawing::Point(18, 94);
			   this->label21->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->label21->Name = L"label21";
			   this->label21->Size = System::Drawing::Size(120, 45);
			   this->label21->TabIndex = 0;
			   this->label21->Text = L"Class";
			   this->label21->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			   // 
			   // tabPage4
			   // 
			   this->tabPage4->BackColor = System::Drawing::SystemColors::Control;
			   this->tabPage4->Controls->Add(this->panel5);
			   this->tabPage4->Location = System::Drawing::Point(4, 34);
			   this->tabPage4->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			   this->tabPage4->Name = L"tabPage4";
			   this->tabPage4->Padding = System::Windows::Forms::Padding(4, 4, 4, 4);
			   this->tabPage4->Size = System::Drawing::Size(1580, 618);
			   this->tabPage4->TabIndex = 4;
			   this->tabPage4->Text = L"Record";
			   // 
			   // panel5
			   // 
			   this->panel5->AutoScroll = true;
			   this->panel5->AutoSize = true;
			   this->panel5->Controls->Add(this->button25);
			   this->panel5->Controls->Add(this->button24);
			   this->panel5->Controls->Add(this->listBox14);
			   this->panel5->Controls->Add(this->button18);
			   this->panel5->Controls->Add(this->button17);
			   this->panel5->Controls->Add(this->label11);
			   this->panel5->Controls->Add(this->button16);
			   this->panel5->Controls->Add(this->button15);
			   this->panel5->Controls->Add(this->checkBox1);
			   this->panel5->Controls->Add(this->listBox13);
			   this->panel5->Dock = System::Windows::Forms::DockStyle::Fill;
			   this->panel5->Location = System::Drawing::Point(4, 4);
			   this->panel5->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			   this->panel5->Name = L"panel5";
			   this->panel5->Size = System::Drawing::Size(1572, 610);
			   this->panel5->TabIndex = 0;
			   // 
			   // button25
			   // 
			   this->button25->Location = System::Drawing::Point(1046, 111);
			   this->button25->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			   this->button25->Name = L"button25";
			   this->button25->Size = System::Drawing::Size(220, 62);
			   this->button25->TabIndex = 25;
			   this->button25->Text = L"Position -> Features";
			   this->button25->UseVisualStyleBackColor = true;
			   this->button25->Click += gcnew System::EventHandler(this, &Form1::button25_Click);
			   // 
			   // button24
			   // 
			   this->button24->Location = System::Drawing::Point(848, 111);
			   this->button24->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			   this->button24->Name = L"button24";
			   this->button24->Size = System::Drawing::Size(189, 62);
			   this->button24->TabIndex = 24;
			   this->button24->Text = L"Load Positions";
			   this->button24->UseVisualStyleBackColor = true;
			   this->button24->Click += gcnew System::EventHandler(this, &Form1::button24_Click);
			   // 
			   // listBox14
			   // 
			   this->listBox14->FormattingEnabled = true;
			   this->listBox14->ItemHeight = 24;
			   this->listBox14->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Image Coordinate", L"PictureBox Coordinate" });
			   this->listBox14->Location = System::Drawing::Point(420, 48);
			   this->listBox14->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			   this->listBox14->Name = L"listBox14";
			   this->listBox14->Size = System::Drawing::Size(224, 52);
			   this->listBox14->TabIndex = 23;
			   // 
			   // button18
			   // 
			   this->button18->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(136)));
			   this->button18->Location = System::Drawing::Point(606, 182);
			   this->button18->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			   this->button18->Name = L"button18";
			   this->button18->Size = System::Drawing::Size(177, 62);
			   this->button18->TabIndex = 22;
			   this->button18->Text = L"Load Setting";
			   this->button18->UseVisualStyleBackColor = true;
			   this->button18->Click += gcnew System::EventHandler(this, &Form1::button18_Click);
			   // 
			   // button17
			   // 
			   this->button17->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(136)));
			   this->button17->Location = System::Drawing::Point(420, 182);
			   this->button17->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			   this->button17->Name = L"button17";
			   this->button17->Size = System::Drawing::Size(177, 62);
			   this->button17->TabIndex = 21;
			   this->button17->Text = L"Save Setting";
			   this->button17->UseVisualStyleBackColor = true;
			   this->button17->Click += gcnew System::EventHandler(this, &Form1::button17_Click);
			   // 
			   // label11
			   // 
			   this->label11->AutoSize = true;
			   this->label11->Location = System::Drawing::Point(416, 270);
			   this->label11->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->label11->Name = L"label11";
			   this->label11->Size = System::Drawing::Size(125, 24);
			   this->label11->TabIndex = 20;
			   this->label11->Text = L"Image Path :";
			   // 
			   // button16
			   // 
			   this->button16->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(136)));
			   this->button16->Location = System::Drawing::Point(420, 111);
			   this->button16->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			   this->button16->Name = L"button16";
			   this->button16->Size = System::Drawing::Size(177, 62);
			   this->button16->TabIndex = 19;
			   this->button16->Text = L"Delete";
			   this->button16->UseVisualStyleBackColor = true;
			   this->button16->Click += gcnew System::EventHandler(this, &Form1::button16_Click);
			   // 
			   // button15
			   // 
			   this->button15->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(136)));
			   this->button15->Location = System::Drawing::Point(606, 111);
			   this->button15->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			   this->button15->Name = L"button15";
			   this->button15->Size = System::Drawing::Size(232, 62);
			   this->button15->TabIndex = 18;
			   this->button15->Text = L"Save Positions As File";
			   this->button15->UseVisualStyleBackColor = true;
			   this->button15->Click += gcnew System::EventHandler(this, &Form1::button15_Click);
			   // 
			   // checkBox1
			   // 
			   this->checkBox1->AutoSize = true;
			   this->checkBox1->Checked = true;
			   this->checkBox1->CheckState = System::Windows::Forms::CheckState::Checked;
			   this->checkBox1->Location = System::Drawing::Point(420, 9);
			   this->checkBox1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			   this->checkBox1->Name = L"checkBox1";
			   this->checkBox1->Size = System::Drawing::Size(134, 28);
			   this->checkBox1->TabIndex = 1;
			   this->checkBox1->Text = L"Record On";
			   this->checkBox1->UseVisualStyleBackColor = true;
			   this->checkBox1->CheckedChanged += gcnew System::EventHandler(this, &Form1::checkBox1_CheckedChanged);
			   // 
			   // listBox13
			   // 
			   this->listBox13->FormattingEnabled = true;
			   this->listBox13->ItemHeight = 24;
			   this->listBox13->Location = System::Drawing::Point(4, 4);
			   this->listBox13->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			   this->listBox13->Name = L"listBox13";
			   this->listBox13->Size = System::Drawing::Size(404, 580);
			   this->listBox13->TabIndex = 0;
			   // 
			   // tabPage5
			   // 
			   this->tabPage5->BackColor = System::Drawing::SystemColors::Control;
			   this->tabPage5->Controls->Add(this->panel6);
			   this->tabPage5->Location = System::Drawing::Point(4, 34);
			   this->tabPage5->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			   this->tabPage5->Name = L"tabPage5";
			   this->tabPage5->Padding = System::Windows::Forms::Padding(4, 4, 4, 4);
			   this->tabPage5->Size = System::Drawing::Size(1580, 618);
			   this->tabPage5->TabIndex = 5;
			   this->tabPage5->Text = L"Tool";
			   // 
			   // panel6
			   // 
			   this->panel6->AutoScroll = true;
			   this->panel6->AutoSize = true;
			   this->panel6->Controls->Add(this->button23);
			   this->panel6->Controls->Add(this->listBox15);
			   this->panel6->Controls->Add(this->label20);
			   this->panel6->Controls->Add(this->label19);
			   this->panel6->Controls->Add(this->button22);
			   this->panel6->Controls->Add(this->button21);
			   this->panel6->Controls->Add(this->button20);
			   this->panel6->Controls->Add(this->button19);
			   this->panel6->Dock = System::Windows::Forms::DockStyle::Fill;
			   this->panel6->Location = System::Drawing::Point(4, 4);
			   this->panel6->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			   this->panel6->Name = L"panel6";
			   this->panel6->Size = System::Drawing::Size(1572, 610);
			   this->panel6->TabIndex = 0;
			   // 
			   // button23
			   // 
			   this->button23->Location = System::Drawing::Point(286, 258);
			   this->button23->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			   this->button23->Name = L"button23";
			   this->button23->Size = System::Drawing::Size(140, 70);
			   this->button23->TabIndex = 27;
			   this->button23->Text = L"Clear";
			   this->button23->UseVisualStyleBackColor = true;
			   this->button23->Click += gcnew System::EventHandler(this, &Form1::button23_Click);
			   // 
			   // listBox15
			   // 
			   this->listBox15->FormattingEnabled = true;
			   this->listBox15->ItemHeight = 24;
			   this->listBox15->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Image Coordinate", L"PictureBox Coordinate" });
			   this->listBox15->Location = System::Drawing::Point(291, 20);
			   this->listBox15->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			   this->listBox15->Name = L"listBox15";
			   this->listBox15->Size = System::Drawing::Size(224, 52);
			   this->listBox15->TabIndex = 26;
			   // 
			   // label20
			   // 
			   this->label20->AutoSize = true;
			   this->label20->Location = System::Drawing::Point(286, 201);
			   this->label20->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->label20->Name = L"label20";
			   this->label20->Size = System::Drawing::Size(62, 24);
			   this->label20->TabIndex = 25;
			   this->label20->Text = L"Path: ";
			   // 
			   // label19
			   // 
			   this->label19->AutoSize = true;
			   this->label19->Location = System::Drawing::Point(286, 122);
			   this->label19->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->label19->Name = L"label19";
			   this->label19->Size = System::Drawing::Size(62, 24);
			   this->label19->TabIndex = 24;
			   this->label19->Text = L"Path: ";
			   // 
			   // button22
			   // 
			   this->button22->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(136)));
			   this->button22->Location = System::Drawing::Point(8, 20);
			   this->button22->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			   this->button22->Name = L"button22";
			   this->button22->Size = System::Drawing::Size(270, 70);
			   this->button22->TabIndex = 23;
			   this->button22->Text = L"Load Setting";
			   this->button22->UseVisualStyleBackColor = true;
			   this->button22->Click += gcnew System::EventHandler(this, &Form1::button22_Click);
			   // 
			   // button21
			   // 
			   this->button21->Location = System::Drawing::Point(8, 258);
			   this->button21->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			   this->button21->Name = L"button21";
			   this->button21->Size = System::Drawing::Size(270, 70);
			   this->button21->TabIndex = 2;
			   this->button21->Text = L"Combine";
			   this->button21->UseVisualStyleBackColor = true;
			   this->button21->Click += gcnew System::EventHandler(this, &Form1::button21_Click);
			   // 
			   // button20
			   // 
			   this->button20->Location = System::Drawing::Point(8, 178);
			   this->button20->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			   this->button20->Name = L"button20";
			   this->button20->Size = System::Drawing::Size(270, 70);
			   this->button20->TabIndex = 1;
			   this->button20->Text = L"Position -> Cross Feature";
			   this->button20->UseVisualStyleBackColor = true;
			   this->button20->Click += gcnew System::EventHandler(this, &Form1::button20_Click);
			   // 
			   // button19
			   // 
			   this->button19->Location = System::Drawing::Point(8, 99);
			   this->button19->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			   this->button19->Name = L"button19";
			   this->button19->Size = System::Drawing::Size(270, 70);
			   this->button19->TabIndex = 0;
			   this->button19->Text = L"Position -> Direct Feature";
			   this->button19->UseVisualStyleBackColor = true;
			   this->button19->Click += gcnew System::EventHandler(this, &Form1::button19_Click);
			   // 
			   // Form1
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(144, 144);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Dpi;
			   this->AutoScroll = true;
			   this->AutoSize = true;
			   this->ClientSize = System::Drawing::Size(1588, 698);
			   this->Controls->Add(this->tabControl1);
			   this->Controls->Add(this->menuStrip1);
			   this->MainMenuStrip = this->menuStrip1;
			   this->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			   this->Name = L"Form1";
			   this->Text = L"SVM_WinForm";
			   this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			   this->menuStrip1->ResumeLayout(false);
			   this->menuStrip1->PerformLayout();
			   this->tabControl1->ResumeLayout(false);
			   this->tabPage1->ResumeLayout(false);
			   this->tabPage1->PerformLayout();
			   this->panel3->ResumeLayout(false);
			   this->panel3->PerformLayout();
			   this->panel4->ResumeLayout(false);
			   this->panel4->PerformLayout();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->EndInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->EndInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			   this->tabPage2->ResumeLayout(false);
			   this->tabPage2->PerformLayout();
			   this->panel2->ResumeLayout(false);
			   this->groupBox2->ResumeLayout(false);
			   this->groupBox3->ResumeLayout(false);
			   this->tabPage7->ResumeLayout(false);
			   this->tabPage7->PerformLayout();
			   this->panel1->ResumeLayout(false);
			   this->groupBox6->ResumeLayout(false);
			   this->groupBox6->PerformLayout();
			   this->tabPage6->ResumeLayout(false);
			   this->tabPage6->PerformLayout();
			   this->panel7->ResumeLayout(false);
			   this->panel7->PerformLayout();
			   this->groupBox5->ResumeLayout(false);
			   this->groupBox5->PerformLayout();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->EndInit();
			   this->tabPage3->ResumeLayout(false);
			   this->tabPage3->PerformLayout();
			   this->panel8->ResumeLayout(false);
			   this->panel8->PerformLayout();
			   this->groupBox1->ResumeLayout(false);
			   this->groupBox1->PerformLayout();
			   this->groupBox4->ResumeLayout(false);
			   this->tabPage4->ResumeLayout(false);
			   this->tabPage4->PerformLayout();
			   this->panel5->ResumeLayout(false);
			   this->panel5->PerformLayout();
			   this->tabPage5->ResumeLayout(false);
			   this->tabPage5->PerformLayout();
			   this->panel6->ResumeLayout(false);
			   this->panel6->PerformLayout();
			   this->ResumeLayout(false);
			   this->PerformLayout();

		   }
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e)
	{
		Stopwatch^ sw = gcnew Stopwatch();
		sw->Start();
		progressBar1->Value = 0;
		progressBar1->Maximum = 6;

		std::vector<double> target;
		std::vector< std::vector<double>> feature;
		std::vector<double> predict_target;
		std::vector<std::vector <double>> predict_feature;
		std::vector<double> maximum, minimum;
		double result;
		std::ifstream file_stream;
		int target_max, target_min;

		StringConvertor sc1(label4->Text);
		std::string file_name1 = sc1.STLAnsiString;
		file_stream.open(file_name1.c_str(), std::ios::in);
		if (file_stream)
		{
			double l, f;
			int row, t, max = 0, line_count = 0;
			std::string strline;
			while (!file_stream.eof())
			{
				getline(file_stream, strline);

				if (!strline.empty())
				{
					line_count++;
					std::stringstream   ss(strline);
					ss >> l;
					target.push_back(l);
					row = 0;
					while (ss >> t)
					{
						ss.ignore(1, ':');
						ss >> f;
						if (t > max)
						{
							feature.resize(t);
							for (int i = 0; i < t; i++)
								feature[i].resize(line_count);
							max = t;
							if (t != (row + 1))	   //比target小的補0
							{
								for (int i = row; i < (t - 1); i++)
									feature[i][line_count - 1] = 0;
								row = t - 1;
							}
							feature[row][line_count - 1] = f;
							if (row < max)
							{
								for (int i = row + 1; i < max; i++)
									feature[row][line_count - 1] = 0;
							}
							if (t > max)
							{
								for (int i = max; i < (t - 1); i++)   //比max大的補0
								{
									for (int j = 0; j < line_count - 2; j++)
									{
										feature[i][j] = 0;
									}
								}
							}
						}
						else
						{
							if (t > (row + 1))	   //比target小的補0
							{
								for (int i = row; i < (t - 1); i++)
									feature[i].push_back(0);
								row = t - 1;
							}
							feature[row].push_back(f);
						}
						row++;
					}
					if (row < max)
					{
						for (int i = row; i < max; i++)
							feature[i].push_back(0);
					}
				}
			}
			for (int i = 0; i != feature.size(); i++)
			{
				maximum.push_back(*max_element(feature[i].begin(), feature[i].end()));
				minimum.push_back(*min_element(feature[i].begin(), feature[i].end()));
			}
			target_max = (int)*max_element(target.begin(), target.end());
			target_min = (int)*min_element(target.begin(), target.end());
			file_stream.close();
			label1->Text = "Load Training Data Successfully.";
		}
		else
		{
			label1->Text = "Load Training Data unsuccessfully.";
		}
		progressBar1->Value++;
		//
		StringConvertor sc2(label5->Text);
		std::string file_name2 = sc2.STLAnsiString;
		file_stream.open(file_name2.c_str(), std::ios::in);
		int test_width, test_height, h;
		if (file_stream)
		{
			double l, f;
			int row, t, max = 0, line_count = 0;
			std::string strline;
			if (checkBox2->Checked == true)
			{
				file_stream >> test_width >> test_height >> h;
				h_max = h;

			}
			while (!file_stream.eof())
			{
				getline(file_stream, strline);
				if (!strline.empty())
				{
					line_count++;
					std::stringstream   ss(strline);
					ss >> l;
					predict_target.push_back(l);
					row = 0;
					while (ss >> t)
					{
						ss.ignore(1, ':');
						ss >> f;
						if (t > max)
						{
							predict_feature.resize(t);
							for (int i = 0; i < t; i++)
								predict_feature[i].resize(line_count);
							max = t;
							if (t != (row + 1))	   //比target小的補0
							{
								for (int i = row; i < (t - 1); i++)
									predict_feature[i][line_count - 1] = 0;
								row = t - 1;
							}
							predict_feature[row][line_count - 1] = f;
							if (row < max)
							{
								for (int i = row + 1; i < max; i++)
									predict_feature[row][line_count - 1] = 0;
							}
							if (t > max)
							{
								for (int i = max; i < (t - 1); i++)   //比max大的補0
								{
									for (int j = 0; j < line_count - 2; j++)
									{
										predict_feature[i][j] = 0;
									}
								}
							}
						}
						else
						{
							if (t > (row + 1))	   //比target小的補0
							{
								for (int i = row; i < (t - 1); i++)
									predict_feature[i].push_back(0);
								row = t - 1;
							}
							predict_feature[row].push_back(f);
						}
						row++;
					}
					if (row < max)
					{
						for (int i = row; i < max; i++)
							predict_feature[i].push_back(0);
					}
				}
			}
			for (int i = 0; i != predict_feature.size(); i++)
			{
				maximum.push_back(*max_element(predict_feature[i].begin(), predict_feature[i].end()));
				minimum.push_back(*min_element(predict_feature[i].begin(), predict_feature[i].end()));
			}
			file_stream.close();
			label1->Text = label1->Text + "\nLoad Testing Data Successfully.";

		}
		else
		{
			label1->Text = label1->Text + "\nLoad Testing Data Unsuccessfully.";
		}
		progressBar1->Value++;
		//
		//label33->Text="";
		double maximum_number = (*max_element(maximum.begin(), maximum.end()));
		double minimum_number = (*min_element(minimum.begin(), minimum.end()));
		double n;
		for (int i = 0; i != feature.size(); i++)
		{
			for (int j = 0; j != feature[i].size(); j++)
			{
				n = feature[i][j];
				feature[i][j] = ((n - minimum_number) / (maximum_number - minimum_number)) * 2 - 1;
			}
		}
		for (int i = 0; i != predict_feature.size(); i++)
		{
			for (int j = 0; j != predict_feature[i].size(); j++)
			{
				n = predict_feature[i][j];
				predict_feature[i][j] = ((n - minimum_number) / (maximum_number - minimum_number)) * 2 - 1;
			}
		}
		progressBar1->Value++;
		//
		bool signal = 1;
		SVM_Package* svm = new SVM_Package;
		svm->svmCreateProblemForTrainingData(target, feature);
		svm->svmCreateProblemForTestData(target, feature);
		if (checkBox4->Checked == true)
		{
			textBox1->Text = String::Format("1");
			textBox2->Text = String::Format("1");
		}
		if (textBox1->Text != "" && textBox2->Text != "")
		{
			parameter = new struct svm_parameter;
			parameter->svm_type = C_SVC;
			parameter->kernel_type = RBF;
			parameter->degree = 3;
			parameter->gamma = 0;
			parameter->coef0 = 0;
			parameter->nu = 0.5;
			parameter->cache_size = 10000;
			parameter->C = 1;
			parameter->eps = 1e-3;
			parameter->p = 0.1;
			parameter->shrinking = 1;
			parameter->probability = 0;
			parameter->nr_weight = 0;
			parameter->weight_label = NULL;
			parameter->weight = NULL;
			parameter->C = Convert::ToDouble(textBox1->Text);
			parameter->gamma = Convert::ToDouble(textBox2->Text);
			svm->svmSetParamter(parameter);
		}
		else
		{
			if (checkBox3->Checked == true && parameter != nullptr)
			{
				svm->svmSetParamter(parameter);
			}
			else if (checkBox3->Checked == true && parameter == nullptr)
			{
				signal = 0;
				progressBar1->Value = 6;
				MessageBox::Show("Please enter parameter!");
			}
			else
			{
				parameter = new struct svm_parameter;
				parameter = svm->svmCrossValidation();
				label34->Text = String::Format("Optimal Paramter\nC:{0:#.###}\nG:{1:#.###}", parameter->C, parameter->gamma);
			}
		}
		if (signal == 1)
		{
			result = svm->svmTestModel();
			label1->Text += String::Format("\naccuracy of testing trained model: {0:#.###}%", result);
			progressBar1->Value++;

			if (saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			{

				StringConvertor s(saveFileDialog1->FileName);
				std::ofstream fout(s.STLAnsiString.c_str(), std::ios::out);
				cls = new int[predict_target.size()];
				result = svm->svmPredict(predict_target, predict_feature, cls);
				progressBar1->Value++;

				int cls_max = cls[0], cls_min = cls[0];
				for (int i = 0; i < predict_target.size(); i++)
				{
					if (cls[i] > cls_max)
						cls_max = cls[i];
					if (cls[i] < cls_min)
						cls_min = cls[i];
				}

				int arti_true = 0, arti_false = 0, unarti_true = 0, unarti_false = 0;
				for (int i = 0; i != predict_target.size(); i++)
				{
					if (predict_target[i] == target_min && cls[i] == cls_min)
						arti_true++;
					else if (predict_target[i] == target_min && cls[i] == cls_max)
						arti_false++;
					else if (predict_target[i] == target_max && cls[i] == cls_max)
						unarti_true++;
					else if (predict_target[i] == target_max && cls[i] == cls_min)
						unarti_false++;
				}
				if (checkBox2->Checked == true)
				{
					fout << test_width << std::endl;
					fout << test_height << std::endl;
					fout << h_max << std::endl;
				}
				label25->Text = String::Format("{0:F}%", (float)arti_true / (float)(arti_true + arti_false) * 100.0);
				label28->Text = String::Format("{0:F}%", (float)arti_false / (float)(arti_true + arti_false) * 100.0);

				if ((unarti_true + unarti_false) != 0)
				{
					label26->Text = String::Format("{0:F}%", (float)unarti_false / (float)(unarti_true + unarti_false) * 100.0);
					label29->Text = String::Format("{0:F}%", (float)unarti_true / (float)(unarti_true + unarti_false) * 100.0);
					fout << (float)arti_true / (float)(arti_true + arti_false) * 100.0 << " " << (float)unarti_false / (float)(unarti_true + unarti_false) * 100.0 << std::endl;
					fout << (float)arti_false / (float)(arti_true + arti_false) * 100.0 << " " << (float)unarti_true / (float)(unarti_true + unarti_false) * 100.0 << std::endl;
				}
				else
				{
					label26->Text = "0%";
					label29->Text = "0%";
					fout << (float)arti_true / (float)(arti_true + arti_false) * 100.0 << " 0.0" << std::endl;
					fout << (float)arti_false / (float)(arti_true + arti_false) * 100.0 << " 0.0" << std::endl;
				}

				fout << (float)(arti_true + unarti_true) / (float)predict_target.size() * 100.0 << std::endl;
				for (int i = 0; i != predict_target.size(); i++)
					fout << cls[i] << "\n";
				fout.close();

				label31->Text = String::Format("Overall Accuracy: {0:#.###}%", (float)(arti_true + unarti_true) / (float)predict_target.size() * 100.0);
				progressBar1->Value++;
				sw->Stop();
				MessageBox::Show("Predict Result Done!\n" + s.ToString() + "\nTotal Run Time: " + Convert::ToString(sw->ElapsedMilliseconds / 1000) + "s");
			}

			if (result == 0)
				label1->Text += String::Format("\naccuracy of predict unknown data: failed!");
			else
				label1->Text += String::Format("\naccuracy of predict unknown data: {0:#.###}%", result);

			label1->Text += "\ntarget size: " + target.size() + "   feature size: " + feature.begin()->size() + "\npredict target size: " + predict_target.size() + "   predict feature size: " + predict_feature.begin()->size();
		}

		delete svm;
		target.clear();
		feature.clear();
		predict_target.clear();
		predict_feature.clear();
		maximum.clear();
		minimum.clear();
		//
	}
	private: System::Void Form1_Load(System::Object^ sender, System::EventArgs^ e)
	{
		listBox1->SetSelected(0, true);
		listBox2->SetSelected(0, true);
		listBox3->SetSelected(0, true);
		listBox5->SetSelected(0, true);
		listBox6->SetSelected(0, true);
		listBox7->SetSelected(0, true);
		listBox11->SetSelected(0, true);
		listBox12->SetSelected(1, true);
		listBox14->SetSelected(0, true);
		listBox15->SetSelected(0, true);
		listBox16->SetSelected(0, true);
		listBox17->SetSelected(0, true);
		label25->Text = "0%";
		label26->Text = "0%";
		label28->Text = "0%";
		label29->Text = "0%";
		System::Drawing::Size size_panel = panel7->Size;
		System::Drawing::Size size_pictureBox1 = pictureBox1->Size;
		double ratio_Height = (double)(size_panel.Height - pictureBox1->Location.Y) / (double)size_pictureBox1.Height;
		double ratio_Width = (double)(size_panel.Width - pictureBox1->Location.X) / (double)size_pictureBox1.Width;
		if (ratio_Width > 0 && ratio_Height > 0)
		{
			if (ratio_Height < ratio_Width)
			{
				size_pictureBox1.Height = (int)((double)size_pictureBox1.Height * ratio_Height);
				size_pictureBox1.Width = (int)((double)size_pictureBox1.Width * ratio_Height);
			}
			else
			{
				size_pictureBox1.Height = (int)((double)size_pictureBox1.Height * ratio_Width);
				size_pictureBox1.Width = (int)((double)size_pictureBox1.Width * ratio_Width);
			}
			pictureBox1->Size = size_pictureBox1;
		}
		size_panel = panel7->Size;
		size_pictureBox1 = pictureBox1->Size;
		ratio_Height = (double)(size_panel.Height - pictureBox1->Location.Y) / (double)size_pictureBox1.Height;
		ratio_Width = (double)(size_panel.Width - pictureBox1->Location.X) / (double)size_pictureBox1.Width;
		imgSelePoints = gcnew List<Point>(0);
		imgDisPoints = gcnew List<Point>(0);
		visible_points = gcnew List<Point>(0);
		curvePoints = gcnew array<Point>(0);
		curveDisPoints = gcnew array<Point>(0);
		right_click = true;
	}
	private: System::Void openImageToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			image_raw_data = gcnew Bitmap(openFileDialog1->FileName);
			System::Drawing::Rectangle cloneRect = System::Drawing::Rectangle(0, 0, image_raw_data->Width, image_raw_data->Height);
			image = image_raw_data->Clone(cloneRect, System::Drawing::Imaging::PixelFormat::Format24bppRgb);
			image_data = image_raw_data->Clone(cloneRect, System::Drawing::Imaging::PixelFormat::Format24bppRgb);
			pictureBox1->Image = image;
			imageAspect = (float)image->Width / image->Height;
			controlAspect = (float)pictureBox1->Width / pictureBox1->Height;
			label8->Text = "Width: " + Convert::ToString(image->Width);
			label9->Text = "Height: " + Convert::ToString(image->Height);
			label11->Text = openFileDialog1->FileName;
			this->Text = "SVM_WinForm " + openFileDialog1->FileName;
		}
	}
	private: System::Void windowsProcessToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (image != nullptr)
		{
			double mask[9] = { -1.0 / 9,-1.0 / 9,-1.0 / 9,-1.0 / 9,8.0 / 9,-1.0 / 9,-1.0 / 9,-1.0 / 9,-1.0 / 9 };
			Stopwatch^ sw = gcnew Stopwatch();
			sw->Start();
			pictureBox1->Image = Mask_Operation(image, mask);
			sw->Stop();
			MessageBox::Show("Total Run Time: " + Convert::ToString(sw->ElapsedMilliseconds / 1000) + "s");
		}
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			label4->Text = openFileDialog1->FileName;
		}
	}
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			label5->Text = openFileDialog1->FileName;
		}
	}
	private: System::Void pictureBox1_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
	{
		double X, Y;
		if (pictureBox1->Image == nullptr)
		{
			//p.X=e->X+1;
			//p.Y=e->Y+1;
			p.X = e->X;
			p.Y = e->Y;
			label6->Text = String::Format("X: {0}", p.X + 1);
			label7->Text = String::Format("Y: {0}", p.Y + 1);
		}
		else if (image != nullptr)
		{

			if (pictureBox1->Width == 0 || pictureBox1->Height == 0 || image->Width == 0 || image->Height == 0)
			{
				p.X = e->X;
				p.Y = e->Y;
				label6->Text = "X: " + Convert::ToString(p.X + 1);
				label7->Text = "Y: " + Convert::ToString(p.Y + 1);
			}
			else
			{
				X = e->X + 1;
				Y = e->Y + 1;
				if (imageAspect > controlAspect)
				{
					double ratioWidth = (double)image->Width / (double)pictureBox1->Width;
					X *= ratioWidth;
					//X++;
					double scale = (double)pictureBox1->Width / image->Width;
					double displayHeight = scale * (double)image->Height;
					double diffHeight = (double)pictureBox1->Height - displayHeight;
					diffHeight /= 2;
					Y -= diffHeight;
					Y /= scale;
					//Y++;	
				}
				else
				{
					double ratioHeight = (double)image->Height / (double)pictureBox1->Height;
					Y *= ratioHeight;
					//Y++;
					double scale = (double)pictureBox1->Height / image->Height;
					double displayWidth = scale * (double)image->Width;
					double diffWidth = (double)pictureBox1->Width - displayWidth;
					diffWidth /= 2;
					X -= diffWidth;
					X /= scale;
					//X++;
				}
				if (X >= 0 && X < image->Width && Y >= 0 && Y < image->Height)
				{
					p.X = (int)X;
					p.Y = (int)Y;
					label6->Text = String::Format("X: {0}", p.X + 1);
					label7->Text = String::Format("Y: {0}", p.Y + 1);
					Color c;
					c = image_data->GetPixel((int)X, (int)Y);
					label10->Text = String::Format("R: {0}\nG: {1}\nB: {2}", c.R, c.G, c.B);
				}
				else
				{
					label6->Text = String::Format("X: ##");
					label7->Text = String::Format("Y: ##");
				}
			}
		}
	}
	private: System::Void pictureBox1_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
	{

		switch (e->Button)
		{
		case System::Windows::Forms::MouseButtons::Left:
			if (right_click)
			{
				max_XY = min_XY = e->Location;
			}
			right_click = false;
			if (e->X > max_XY.X)
				max_XY.X = e->X;
			else if (e->X < min_XY.X)
				min_XY.X = e->X;
			if (e->Y > max_XY.Y)
				max_XY.Y = e->Y;
			else if (e->Y < min_XY.Y)
				min_XY.Y = e->Y;
			imgSelePoints->Add(e->Location);
			Array::Resize(curvePoints, imgSelePoints->Count);
			for (int i = 0; i < imgSelePoints->Count; i++)
				curvePoints[i] = imgSelePoints[i];
			break;
		case System::Windows::Forms::MouseButtons::Right:
			//drawing
			right_click = true;
			pictureBox1->Refresh();
			array<bool>^ imageVisited = gcnew array<bool>(image->Width * image->Height);
			for (int i = 0; i < image->Height; i++)
			{
				for (int j = 0; j < image->Width; j++)
				{
					imageVisited[i * image->Width + j] = false;
				}
			}
			for (int point_num = 0; point_num < visible_points->Count; point_num++)
			{
				double X, Y;
				Point p;
				if (pictureBox1->Image != nullptr && image != nullptr && (pictureBox1->Width != 0 || pictureBox1->Height != 0 || image->Width != 0 || image->Height != 0))
				{
					X = (double)visible_points[point_num].X + 1;
					Y = (double)visible_points[point_num].Y + 1;
					if (imageAspect > controlAspect)
					{
						double ratioWidth = (double)image->Width / (double)pictureBox1->Width;
						X *= ratioWidth;
						double scale = (double)pictureBox1->Width / image->Width;
						double displayHeight = scale * (double)image->Height;
						double diffHeight = (double)pictureBox1->Height - displayHeight;
						diffHeight /= 2;
						Y -= diffHeight;
						Y /= scale;
					}
					else
					{
						double ratioHeight = (double)image->Height / (double)pictureBox1->Height;
						Y *= ratioHeight;
						double scale = (double)pictureBox1->Height / image->Height;
						double displayWidth = scale * (double)image->Width;
						double diffWidth = (double)pictureBox1->Width - displayWidth;
						diffWidth /= 2;
						X -= diffWidth;
						X /= scale;
					}
				}
				p.X = System::Math::Round(X);
				p.Y = System::Math::Round(Y);
				if (imageVisited[p.Y * image->Height + p.X] == true)
				{
					continue;
				}
				else
				{
					imageVisited[p.Y * image->Height + p.X] = true;
				}
				h_max = listBox5->SelectedIndices[listBox5->SelectedIndices->Count - 1] + 1;
				if (p.X > (h_max - 1) && p.X < (image->Width - h_max) && (p.Y > h_max - 1) && p.Y < (image->Height - h_max))
				{
					std::stringstream ss;
					ss << listBox2->SelectedIndex + 1;
					switch (listBox7->SelectedIndex)
					{
					case 0:
						for (int i = 0; i < listBox5->SelectedIndices->Count; i++)
						{
							switch (listBox1->SelectedIndex)
							{
							case 0:
							case 1:
							case 2:
								ss << " " << i + 1 << ":" << window_direction_process(listBox5->SelectedIndices[i] + 1, window_data(p, listBox5->SelectedIndices[i] + 1, image_data, listBox1->SelectedIndex), listBox6->SelectedIndex);
								break;
							case 3:
								ss << " " << (i * 2) + 1 << ":" << window_direction_process(listBox5->SelectedIndices[i] + 1, window_data(p, listBox5->SelectedIndices[i] + 1, image_data, 0), listBox6->SelectedIndex) << " " << (i * 2) + 2 << ":" << window_direction_process(listBox5->SelectedIndices[i] + 1, window_data(p, listBox5->SelectedIndices[i] + 1, image_data, 1), listBox6->SelectedIndex);
								break;
							case 4:
								ss << " " << (i * 2) + 1 << ":" << window_direction_process(listBox5->SelectedIndices[i] + 1, window_data(p, listBox5->SelectedIndices[i] + 1, image_data, 1), listBox6->SelectedIndex) << " " << (i * 2) + 2 << ":" << window_direction_process(listBox5->SelectedIndices[i] + 1, window_data(p, listBox5->SelectedIndices[i] + 1, image_data, 2), listBox6->SelectedIndex);
								break;
							case 5:
								ss << " " << (i * 2) + 1 << ":" << window_direction_process(listBox5->SelectedIndices[i] + 1, window_data(p, listBox5->SelectedIndices[i] + 1, image_data, 0), listBox6->SelectedIndex) << " " << (i * 2) + 2 << ":" << window_direction_process(listBox5->SelectedIndices[i] + 1, window_data(p, listBox5->SelectedIndices[i] + 1, image_data, 2), listBox6->SelectedIndex);
								break;
							case 6:
								ss << " " << (i * 3) + 1 << ":" << window_direction_process(listBox5->SelectedIndices[i] + 1, window_data(p, listBox5->SelectedIndices[i] + 1, image_data, 0), listBox6->SelectedIndex) << " " << (i * 3) + 2 << ":" << window_direction_process(listBox5->SelectedIndices[i] + 1, window_data(p, listBox5->SelectedIndices[i] + 1, image_data, 1), listBox6->SelectedIndex) << " " << (i * 3) + 3 << ":" << window_direction_process(listBox5->SelectedIndices[i] + 1, window_data(p, listBox5->SelectedIndices[i] + 1, image_data, 2), listBox6->SelectedIndex);
								break;
							case 7:
								if (band_image_4 == nullptr)
								{
									ss << " " << (i * 3) + 1 << ":" << window_direction_process(listBox5->SelectedIndices[i] + 1, window_data(p, listBox5->SelectedIndices[i] + 1, image_data, 0), listBox6->SelectedIndex) << " " << (i * 3) + 2 << ":" << window_direction_process(listBox5->SelectedIndices[i] + 1, window_data(p, listBox5->SelectedIndices[i] + 1, image_data, 1), listBox6->SelectedIndex) << " " << (i * 3) + 3 << ":" << window_direction_process(listBox5->SelectedIndices[i] + 1, window_data(p, listBox5->SelectedIndices[i] + 1, image_data, 2), listBox6->SelectedIndex);
									break;
								}
								else
								{
									ss << " " << (i * 4) + 1 << ":" << window_direction_process(listBox5->SelectedIndices[i] + 1, window_data(p, listBox5->SelectedIndices[i] + 1, image_data, 0), listBox6->SelectedIndex) << " " << (i * 4) + 2 << ":" << window_direction_process(listBox5->SelectedIndices[i] + 1, window_data(p, listBox5->SelectedIndices[i] + 1, image_data, 1), listBox6->SelectedIndex) << " " << (i * 4) + 3 << ":" << window_direction_process(listBox5->SelectedIndices[i] + 1, window_data(p, listBox5->SelectedIndices[i] + 1, image_data, 2), listBox6->SelectedIndex) << " " << (i * 4) + 4 << ":" << window_direction_process(listBox5->SelectedIndices[i] + 1, window_data(p, listBox5->SelectedIndices[i] + 1, band_image_4, 0), listBox6->SelectedIndex);
									break;
								}
							}
						}
						break;
					case 1:
						if (listBox12->SelectedIndex == 3)
						{
							if (pictureBox5->Image == nullptr)
								MessageBox::Show("Please input band image !");
							else
							{
								for (int i = 0; i < listBox5->SelectedIndices->Count; i++)
									ss << " " << i + 1 << ":" << window_cross_process(listBox5->SelectedIndices[i] + 1, window_data(p, listBox5->SelectedIndices[i] + 1, image_data, listBox11->SelectedIndex), window_data(p, listBox5->SelectedIndices[i] + 1, band_image_4, 0));
							}

						}
						else
						{
							for (int i = 0; i < listBox5->SelectedIndices->Count; i++)
								ss << " " << i + 1 << ":" << window_cross_process(listBox5->SelectedIndices[i] + 1, window_data(p, listBox5->SelectedIndices[i] + 1, image_data, listBox11->SelectedIndex), window_data(p, listBox5->SelectedIndices[i] + 1, image_data, listBox12->SelectedIndex));
						}
						break;
					case 2:
						int index_count = 0;
						for (int i = 0; i < listBox5->SelectedIndices->Count; i++)
						{
							switch (listBox1->SelectedIndex)
							{
							case 0:
							case 1:
							case 2:
								ss << " " << i + 1 << ":" << window_direction_process(listBox5->SelectedIndices[i] + 1, window_data(p, listBox5->SelectedIndices[i] + 1, image_data, listBox1->SelectedIndex), listBox6->SelectedIndex);
								index_count++;
								break;
							case 3:
								ss << " " << (i * 2) + 1 << ":" << window_direction_process(listBox5->SelectedIndices[i] + 1, window_data(p, listBox5->SelectedIndices[i] + 1, image_data, 0), listBox6->SelectedIndex) << " " << (i * 2) + 2 << ":" << window_direction_process(listBox5->SelectedIndices[i] + 1, window_data(p, listBox5->SelectedIndices[i] + 1, image_data, 1), listBox6->SelectedIndex);
								index_count += 2;
								break;
							case 4:
								ss << " " << (i * 2) + 1 << ":" << window_direction_process(listBox5->SelectedIndices[i] + 1, window_data(p, listBox5->SelectedIndices[i] + 1, image_data, 1), listBox6->SelectedIndex) << " " << (i * 2) + 2 << ":" << window_direction_process(listBox5->SelectedIndices[i] + 1, window_data(p, listBox5->SelectedIndices[i] + 1, image_data, 2), listBox6->SelectedIndex);
								index_count += 2;
								break;
							case 5:
								ss << " " << (i * 2) + 1 << ":" << window_direction_process(listBox5->SelectedIndices[i] + 1, window_data(p, listBox5->SelectedIndices[i] + 1, image_data, 0), listBox6->SelectedIndex) << " " << (i * 2) + 2 << ":" << window_direction_process(listBox5->SelectedIndices[i] + 1, window_data(p, listBox5->SelectedIndices[i] + 1, image_data, 2), listBox6->SelectedIndex);
								index_count += 2;
								break;
							case 6:
								ss << " " << (i * 3) + 1 << ":" << window_direction_process(listBox5->SelectedIndices[i] + 1, window_data(p, listBox5->SelectedIndices[i] + 1, image_data, 0), listBox6->SelectedIndex) << " " << (i * 3) + 2 << ":" << window_direction_process(listBox5->SelectedIndices[i] + 1, window_data(p, listBox5->SelectedIndices[i] + 1, image_data, 1), listBox6->SelectedIndex) << " " << (i * 3) + 3 << ":" << window_direction_process(listBox5->SelectedIndices[i] + 1, window_data(p, listBox5->SelectedIndices[i] + 1, image_data, 2), listBox6->SelectedIndex);
								index_count += 3;
								break;
							case 7:
								if (band_image_4 == nullptr)
								{
									ss << " " << (i * 3) + 1 << ":" << window_direction_process(listBox5->SelectedIndices[i] + 1, window_data(p, listBox5->SelectedIndices[i] + 1, image_data, 0), listBox6->SelectedIndex) << " " << (i * 3) + 2 << ":" << window_direction_process(listBox5->SelectedIndices[i] + 1, window_data(p, listBox5->SelectedIndices[i] + 1, image_data, 1), listBox6->SelectedIndex) << " " << (i * 3) + 3 << ":" << window_direction_process(listBox5->SelectedIndices[i] + 1, window_data(p, listBox5->SelectedIndices[i] + 1, image_data, 2), listBox6->SelectedIndex);
									index_count += 3;
									break;
								}
								else
								{
									ss << " " << (i * 4) + 1 << ":" << window_direction_process(listBox5->SelectedIndices[i] + 1, window_data(p, listBox5->SelectedIndices[i] + 1, image_data, 0), listBox6->SelectedIndex) << " " << (i * 4) + 2 << ":" << window_direction_process(listBox5->SelectedIndices[i] + 1, window_data(p, listBox5->SelectedIndices[i] + 1, image_data, 1), listBox6->SelectedIndex) << " " << (i * 4) + 3 << ":" << window_direction_process(listBox5->SelectedIndices[i] + 1, window_data(p, listBox5->SelectedIndices[i] + 1, image_data, 2), listBox6->SelectedIndex) << " " << (i * 4) + 4 << ":" << window_direction_process(listBox5->SelectedIndices[i] + 1, window_data(p, listBox5->SelectedIndices[i] + 1, band_image_4, 0), listBox6->SelectedIndex);
									index_count += 4;
									break;
								}
							}

						}
						if (listBox12->SelectedIndex == 3)
						{
							if (pictureBox5->Image == nullptr)
								MessageBox::Show("Please input band image !");
							else
							{
								for (int i = index_count; i < listBox5->SelectedIndices->Count + index_count; i++)
									ss << " " << i + 1 << ":" << window_cross_process(listBox5->SelectedIndices[i - index_count] + 1, window_data(p, listBox5->SelectedIndices[i - index_count] + 1, image_data, listBox11->SelectedIndex), window_data(p, listBox5->SelectedIndices[i - index_count] + 1, band_image_4, 0));
							}

						}
						else
						{
							for (int i = index_count; i < listBox5->SelectedIndices->Count + index_count; i++)
								ss << " " << i + 1 << ":" << window_cross_process(listBox5->SelectedIndices[i - index_count] + 1, window_data(p, listBox5->SelectedIndices[i - index_count] + 1, image_data, listBox11->SelectedIndex), window_data(p, listBox5->SelectedIndices[i - index_count] + 1, image_data, listBox12->SelectedIndex));
						}
						break;
					}

					std::string s = ss.str();
					StringConvertor sc(s);
					listBox4->Items->Add(sc.ToString());
					switch (listBox3->SelectedIndex)
					{
					case 0:
						image->SetPixel((int)X, (int)Y, Color::Red);
						break;
					case 1:
						image->SetPixel((int)X, (int)Y, Color::Green);
						break;
					case 2:
						image->SetPixel((int)X, (int)Y, Color::Blue);
						break;
					case 3:
						image->SetPixel((int)X, (int)Y, Color::Black);
						break;
					}
					listBox4->TopIndex = listBox4->Items->Count - 1;
					if (checkBox1->Checked == true)
					{
						if (listBox14->SelectedIndex == 0)
							listBox13->Items->Add((listBox2->SelectedIndex + 1) + " " + p.X + " " + p.Y);
						else
							listBox13->Items->Add((listBox2->SelectedIndex + 1) + " " + (e->X + 1) + " " + (e->Y + 1));
						listBox13->TopIndex = listBox13->Items->Count - 1;
					}
				}
			}
			right_click = false;
			imgSelePoints->Clear();
			visible_points->Clear();
			Array::Resize(curvePoints, 0);
			Array::Resize(imageVisited, 0);
			//drawing end
			break;
		}
		pictureBox1->Refresh();
	}
	private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e)
	{
		int index = listBox4->SelectedIndex;
		listBox13->Items->RemoveAt(index);
		listBox4->Items->RemoveAt(index);
	}
	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e)
	{
		std::ofstream fout;
		if (fout)
		{
			saveFileDialog1->Filter = "txt|*.txt";
			if (saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			{
				StringConvertor path(saveFileDialog1->FileName);
				std::string file_name = path.STLAnsiString;
				fout.open(file_name.c_str(), std::ios::out);
				for (int i = 0; i < listBox4->Items->Count; i++)
				{
					StringConvertor s(listBox4->GetItemText(listBox4->Items[i]));
					std::string ss(s.STLAnsiString);
					fout << ss << std::endl;
				}
				label4->Text = path.ToString();
				MessageBox::Show("Done!\n" + path);
			}
			saveFileDialog1->Filter = "";
			fout.close();
		}
	}
	private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (pictureBox1->Image != nullptr)
		{
			Bitmap^ image_result = gcnew Bitmap(image->Width - (2 * h_max), image->Height - (2 * h_max), System::Drawing::Imaging::PixelFormat::Format24bppRgb);
			System::Drawing::Rectangle rect = System::Drawing::Rectangle(0, 0, image_result->Width, image_result->Height);
			System::Drawing::Imaging::BitmapData^ bmpData = image_result->LockBits(rect, System::Drawing::Imaging::ImageLockMode::ReadWrite, image_result->PixelFormat);
			IntPtr ptr = bmpData->Scan0;
			int W = image_result->Width * 3;
			int BytesOfSkip = bmpData->Stride - W;
			int Height = image_result->Height;
			int Width = image_result->Width;
			Byte* p = (Byte*)((void*)ptr);
			int count = 0;

			for (int y = 0; y < Height; y++)
			{
				for (int x = 0; x < W; x += 3)
				{
					if (cls[count] == 1)
					{
						p[0] = 255;
						p[1] = 255;
						p[2] = 255;
					}
					else if (cls[count] == 2)
					{
						p[0] = 0;
						p[1] = 0;
						p[2] = 0;
					}
					p += 3;
					count++;
				}
				p += BytesOfSkip;
			}
			//System::Runtime::InteropServices::Marshal::Copy(Display_image,0,ptr,bmpData->Stride*Height);
			image_result->UnlockBits(bmpData);
			Form2^ aForm2 = gcnew Form2;
			aForm2->Show();
			aForm2->pictureBox1->Image = image_result;
		}
		else
			MessageBox::Show("No Image !");
	}
	private: System::Void button7_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (checkBox2->Checked == true)
		{
			if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			{
				StringConvertor sc1(openFileDialog1->FileName);
				std::string file_name = sc1.STLAnsiString;
				std::ifstream fin(file_name.c_str(), std::ios::in);
				int test_width, test_height, h;
				double lb25, lb26, lb28, lb29, all_accuracy;
				fin >> test_width >> test_height >> h >> lb25 >> lb26 >> lb28 >> lb29 >> all_accuracy;
				h_max = h;
				label25->Text = lb25 + "%";
				label26->Text = lb26 + "%";
				label28->Text = lb28 + "%";
				label29->Text = lb29 + "%";
				label31->Text = all_accuracy + "%";
				Bitmap^ image_result = gcnew Bitmap(test_width, test_height, System::Drawing::Imaging::PixelFormat::Format24bppRgb);
				System::Drawing::Rectangle rect = System::Drawing::Rectangle(0, 0, image_result->Width, image_result->Height);
				System::Drawing::Imaging::BitmapData^ bmpData = image_result->LockBits(rect, System::Drawing::Imaging::ImageLockMode::ReadWrite, System::Drawing::Imaging::PixelFormat::Format24bppRgb);
				IntPtr ptr = bmpData->Scan0;
				int W = image_result->Width * 3;
				int BytesOfSkip = bmpData->Stride - W;
				int Height = image_result->Height;
				int Width = image_result->Width;
				Byte* p = (Byte*)((void*)ptr);
				int result;

				for (int y = 0; y < Height; y++)
				{
					for (int x = 0; x < W; x += 3)
					{
						fin >> result;
						if (result == 1)
						{
							p[0] = 255;
							p[1] = 255;
							p[2] = 255;
						}
						else
						{
							p[0] = 0;
							p[1] = 0;
							p[2] = 0;
						}
						p += 3;
					}
					p += BytesOfSkip;
				}
				image_result->UnlockBits(bmpData);
				fin.close();
				Form2^ aForm2 = gcnew Form2;
				aForm2->Show();
				aForm2->pictureBox1->Image = image_result;
			}
		}
		else
			MessageBox::Show("Please Use Header !");
	}
	private: System::Void newFormToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
	{
		Form1^ newform = gcnew Form1();
		newform->Show();
	}
	private: System::Void exitToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
	{
		this->Close();
	}
	private: System::Void button8_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			image_raw_data = gcnew Bitmap(openFileDialog1->FileName);
			System::Drawing::Rectangle cloneRect = System::Drawing::Rectangle(0, 0, image_raw_data->Width, image_raw_data->Height);
			image = image_raw_data->Clone(cloneRect, System::Drawing::Imaging::PixelFormat::Format24bppRgb);
			image_data = image_raw_data->Clone(cloneRect, System::Drawing::Imaging::PixelFormat::Format24bppRgb);
			pictureBox1->Image = image;
			imageAspect = (float)image->Width / image->Height;
			controlAspect = (float)pictureBox1->Width / pictureBox1->Height;
			label8->Text = "Width: " + Convert::ToString(image->Width);
			label9->Text = "Height: " + Convert::ToString(image->Height);
			label11->Text = openFileDialog1->FileName;
			this->Text = "SVM_WinForm " + openFileDialog1->FileName;
			size_panel7 = panel7->Size;
			size_pictureBox1 = pictureBox1->Size;
		}
	}
	private: System::Void button9_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (image == nullptr)
		{
			MessageBox::Show("Please choose image first !");
		}
		else
		{
			saveFileDialog1->Filter = "txt|*.txt";
			if (saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			{
				StringConvertor sc1(saveFileDialog1->FileName);
				std::string file_name = sc1.STLAnsiString;

				Stopwatch^ sw = gcnew Stopwatch();
				sw->Start();

				std::vector<int> h;
				h.resize(listBox5->SelectedIndices->Count);
				for (int i = 0; i != h.size(); i++)
				{
					h[i] = listBox5->SelectedIndices[i] + 1;
				}
				h_max = h[h.size() - 1];
				switch (listBox7->SelectedIndex)
				{
				case 0:
					Semivariogram_direct_all(file_name, image_data, band_image_4, listBox1->SelectedIndex, listBox6->SelectedIndex, h.size(), h);
					break;
				case 1:
					if (listBox11->SelectedIndex == listBox12->SelectedIndex)
						MessageBox::Show("Two bands must be different!");
					else if (listBox12->SelectedIndex == 3)
						Semivariogram_cross_all(file_name, image_data, band_image_4, listBox11->SelectedIndex, listBox12->SelectedIndex, h.size(), h);
					else
						Semivariogram_cross_all(file_name, image_data, nullptr, listBox11->SelectedIndex, listBox12->SelectedIndex, h.size(), h);
					break;
				case 2:
					if (listBox11->SelectedIndex == listBox12->SelectedIndex)
						MessageBox::Show("Two bands must be different!");
					else	if (listBox12->SelectedIndex == 3)
						Semivariogram_both_all(file_name, image_data, band_image_4, listBox1->SelectedIndex, listBox6->SelectedIndex, listBox11->SelectedIndex, listBox12->SelectedIndex, h.size(), h);
					else
						Semivariogram_both_all(file_name, image_data, nullptr, listBox1->SelectedIndex, listBox6->SelectedIndex, listBox11->SelectedIndex, listBox12->SelectedIndex, h.size(), h);
					break;
				}
				label5->Text = sc1.ToString();

				sw->Stop();
				MessageBox::Show("Total Run Time: " + Convert::ToString((sw->ElapsedMilliseconds) / 1000) + "s\n" + Convert::ToString(sc1));
			}
			saveFileDialog1->Filter = "";
		}
	}
	private: System::Void testToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
	{
		Form3^ PicForm = gcnew Form3;
		PicForm->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
		PicForm->Show();
		PicForm->pictureBox1->Image = image;
	}
	private: System::Void button10_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			band_image_1_ini = gcnew Bitmap(openFileDialog1->FileName);
			System::Drawing::Rectangle cloneRect = System::Drawing::Rectangle(0, 0, band_image_1_ini->Width, band_image_1_ini->Height);
			band_image_1 = band_image_1_ini->Clone(cloneRect, System::Drawing::Imaging::PixelFormat::Format24bppRgb);
			pictureBox2->Image = band_image_1;
			label13->Text = openFileDialog1->FileName;
		}
	}
	private: System::Void button11_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			band_image_2_ini = gcnew Bitmap(openFileDialog1->FileName);
			System::Drawing::Rectangle cloneRect = System::Drawing::Rectangle(0, 0, band_image_2_ini->Width, band_image_2_ini->Height);
			band_image_2 = band_image_2_ini->Clone(cloneRect, System::Drawing::Imaging::PixelFormat::Format24bppRgb);
			pictureBox3->Image = band_image_2;
			label14->Text = openFileDialog1->FileName;
		}
	}
	private: System::Void button12_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			band_image_3_ini = gcnew Bitmap(openFileDialog1->FileName);
			System::Drawing::Rectangle cloneRect = System::Drawing::Rectangle(0, 0, band_image_3_ini->Width, band_image_3_ini->Height);
			band_image_3 = band_image_3_ini->Clone(cloneRect, System::Drawing::Imaging::PixelFormat::Format24bppRgb);
			pictureBox4->Image = band_image_3;
			label15->Text = openFileDialog1->FileName;
		}
	}
	private: System::Void button13_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			band_image_4_ini = gcnew Bitmap(openFileDialog1->FileName);
			System::Drawing::Rectangle cloneRect = System::Drawing::Rectangle(0, 0, band_image_4_ini->Width, band_image_4_ini->Height);
			band_image_4 = band_image_4_ini->Clone(cloneRect, System::Drawing::Imaging::PixelFormat::Format24bppRgb);
			pictureBox5->Image = band_image_4;
			label16->Text = openFileDialog1->FileName;
		}
	}
	private: System::Void button14_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (listBox8->SelectedIndex == listBox9->SelectedIndex || listBox9->SelectedIndex == listBox10->SelectedIndex || listBox8->SelectedIndex == listBox10->SelectedIndex)
			MessageBox::Show("Duplicate Bands!");
		else
		{
			Bitmap^ R, ^ G, ^ B;
			switch (listBox8->SelectedIndex)
			{
			case 0:
				B = band_image_1;
				break;
			case 1:
				B = band_image_2;
				break;
			case 2:
				B = band_image_3;
				break;
			case 3:
				B = band_image_4;
				break;
			}
			switch (listBox9->SelectedIndex)
			{
			case 0:
				G = band_image_1;
				break;
			case 1:
				G = band_image_2;
				break;
			case 2:
				G = band_image_3;
				break;
			case 3:
				G = band_image_4;
				break;
			}
			switch (listBox10->SelectedIndex)
			{
			case 0:
				R = band_image_1;
				break;
			case 1:
				R = band_image_2;
				break;
			case 2:
				R = band_image_3;
				break;
			case 3:
				R = band_image_4;
				break;
			}

			image_raw_data = gcnew Bitmap(Create_RGB_Image(R, G, B));
			System::Drawing::Rectangle cloneRect = System::Drawing::Rectangle(0, 0, image_raw_data->Width, image_raw_data->Height);
			image = image_raw_data->Clone(cloneRect, System::Drawing::Imaging::PixelFormat::Format24bppRgb);
			image_data = image_raw_data->Clone(cloneRect, System::Drawing::Imaging::PixelFormat::Format24bppRgb);

			pictureBox1->Image = image;
			label8->Text = "Width: " + Convert::ToString(image->Width);
			label9->Text = "Height: " + Convert::ToString(image->Height);


			listBox11->Items[0] = listBox8->SelectedItem;
			listBox11->Items[1] = listBox9->SelectedItem;
			listBox11->Items[2] = listBox10->SelectedItem;
			listBox12->Items[0] = listBox8->SelectedItem;
			listBox12->Items[1] = listBox9->SelectedItem;
			listBox12->Items[2] = listBox10->SelectedItem;

			Form3^ PicForm = gcnew Form3;
			PicForm->Text = "RGB Image";
			PicForm->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			PicForm->Show();
			PicForm->pictureBox1->Image = image;
		}
	}
	private: System::Void clearListToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
	{
		listBox4->Items->Clear();
		listBox13->Items->Clear();
	}
	private: System::Void saveImageToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			image_data->Save(saveFileDialog1->FileName, System::Drawing::Imaging::ImageFormat::Tiff);
		}
	}
	private: System::Void saveTrainingImageToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			image->Save(saveFileDialog1->FileName, System::Drawing::Imaging::ImageFormat::Tiff);
		}
	}
	private: System::Void checkBox1_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
	{
		if (checkBox1->Checked == true)
			checkBox1->Text = "Record On";
		else
			checkBox1->Text = "Record Off";
	}
	private: System::Void button15_Click(System::Object^ sender, System::EventArgs^ e)
	{
		std::ofstream fout;
		if (fout)
		{
			if (saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			{
				StringConvertor path(saveFileDialog1->FileName);
				std::string file_name = path.STLAnsiString;
				fout.open(file_name.c_str(), std::ios::out);
				for (int i = 0; i < listBox13->Items->Count; i++)
				{
					StringConvertor s(listBox13->GetItemText(listBox13->Items[i]));
					std::string ss(s.STLAnsiString);
					fout << ss << std::endl;
				}
				MessageBox::Show("Done!\n" + path);
			}
			fout.close();
		}
	}
	private: System::Void button16_Click(System::Object^ sender, System::EventArgs^ e)
	{
		int index = listBox13->SelectedIndex;
		listBox4->Items->RemoveAt(index);
		listBox13->Items->RemoveAt(index);
	}
	private: System::Void button17_Click(System::Object^ sender, System::EventArgs^ e)
	{
		std::ofstream fout;
		if (fout)
		{
			if (saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			{
				StringConvertor path(saveFileDialog1->FileName), image_name(label11->Text), image_name2(label16->Text);
				std::string file_name = path.STLAnsiString;
				fout.open(file_name.c_str(), std::ios::out);
				fout << image_name.STLAnsiString << std::endl;
				fout << image_name2.STLAnsiString << std::endl;
				fout << listBox7->SelectedIndex << std::endl;
				for (int i = 0; i < listBox5->SelectedIndices->Count; i++)
					fout << listBox5->SelectedIndices[i] << " ";
				fout << std::endl;
				fout << listBox1->SelectedIndex << std::endl;
				fout << listBox6->SelectedIndex << std::endl;
				fout << listBox11->SelectedIndex << std::endl;
				fout << listBox12->SelectedIndex << std::endl;
				MessageBox::Show("Done!\n" + path);
			}
			fout.close();
		}
	}
	private: System::Void button18_Click(System::Object^ sender, System::EventArgs^ e)
	{
		std::ifstream fin;
		if (fin)
		{
			if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			{
				StringConvertor path(openFileDialog1->FileName);
				std::string file_name = path.STLAnsiString, s;
				fin.open(file_name.c_str(), std::ios::in);

				getline(fin, s);
				StringConvertor image_name(s);
				image_raw_data = gcnew Bitmap(image_name.ToString());
				System::Drawing::Rectangle cloneRect = System::Drawing::Rectangle(0, 0, image_raw_data->Width, image_raw_data->Height);
				image = image_raw_data->Clone(cloneRect, System::Drawing::Imaging::PixelFormat::Format24bppRgb);
				image_data = image_raw_data->Clone(cloneRect, System::Drawing::Imaging::PixelFormat::Format24bppRgb);
				pictureBox1->Image = image;
				imageAspect = (float)image->Width / image->Height;
				controlAspect = (float)pictureBox1->Width / pictureBox1->Height;
				label8->Text = "Width: " + Convert::ToString(image->Width);
				label9->Text = "Height: " + Convert::ToString(image->Height);
				label11->Text = image_name.ToString();
				this->Text = "SVM_WinForm " + image_name.ToString();;

				getline(fin, s);
				StringConvertor ss(s);
				label16->Text = ss.ToString();


				getline(fin, s);
				std::stringstream s1(s);
				int index;
				s1 >> index;
				listBox7->SetSelected(index, true);
				for (int i = 0; i < listBox5->Items->Count; i++)
					listBox5->SetSelected(i, false);
				getline(fin, s);
				std::stringstream s2(s);
				while (s2 >> index)
					listBox5->SetSelected(index, true);
				getline(fin, s);
				std::stringstream s3(s);
				s3 >> index;
				listBox1->SetSelected(index, true);
				getline(fin, s);
				std::stringstream s4(s);
				s4 >> index;
				listBox6->SetSelected(index, true);
				getline(fin, s);
				std::stringstream s5(s);
				s5 >> index;
				listBox11->SetSelected(index, true);
				getline(fin, s);
				std::stringstream s6(s);
				s6 >> index;
				listBox12->SetSelected(index, true);

				if (band_image_4_ini = gcnew Bitmap(label16->Text))
				{
					System::Drawing::Rectangle cloneRect2 = System::Drawing::Rectangle(0, 0, band_image_4_ini->Width, band_image_4_ini->Height);
					band_image_4 = band_image_4_ini->Clone(cloneRect2, System::Drawing::Imaging::PixelFormat::Format24bppRgb);
					pictureBox5->Image = band_image_4;
				}
				MessageBox::Show("Done!\n" + path);
			}
			fin.close();
		}
	}
	private: System::Void openImageNewWindowToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			Bitmap^ new_image = gcnew Bitmap(openFileDialog1->FileName);
			Form3^ NewPicForm = gcnew Form3;
			NewPicForm->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			NewPicForm->Show();
			NewPicForm->pictureBox1->Image = new_image;
		}
	}
	private: System::Void displayNewImageAutoSizeToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			Bitmap^ new_image = gcnew Bitmap(openFileDialog1->FileName);
			Form2^ NewPicForm = gcnew Form2;
			NewPicForm->Show();
			NewPicForm->pictureBox1->Image = new_image;
		}
	}
	private: System::Void button19_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (pictureBox1->Image != nullptr)
		{
			std::ofstream fout;
			std::ifstream fin;
			if (fin)
			{
				if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
				{
					StringConvertor path1(openFileDialog1->FileName);
					std::string file_name1 = path1.STLAnsiString;
					fin.open(file_name1.c_str(), std::ios::in);
					if (fout)
					{
						if (saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
						{
							StringConvertor path2(saveFileDialog1->FileName);
							std::string file_name2 = path2.STLAnsiString;
							fout.open(file_name2.c_str(), std::ios::out);
							label19->Text = saveFileDialog1->FileName;
							int c;
							double pX, pY;
							Point p;
							while (!fin.eof())
							{
								std::string si;
								getline(fin, si);
								std::stringstream sin(si);
								sin >> c >> pX >> pY;
								if (listBox15->SelectedIndex != 0)
								{
									if (imageAspect > controlAspect)
									{
										double ratioWidth = (double)image->Width / (double)pictureBox1->Width;
										pX *= ratioWidth;
										double scale = (double)pictureBox1->Width / image->Width;
										double displayHeight = scale * (double)image->Height;
										double diffHeight = (double)pictureBox1->Height - displayHeight;
										diffHeight /= 2;
										pY -= diffHeight;
										pY /= scale;
									}
									else
									{
										double ratioHeight = (double)image->Height / (double)pictureBox1->Height;
										pY *= ratioHeight;
										double scale = (double)pictureBox1->Height / image->Height;
										double displayWidth = scale * (double)image->Width;
										double diffWidth = (double)pictureBox1->Width - displayWidth;
										diffWidth /= 2;
										pX -= diffWidth;
										pX /= scale;
									}
								}
								p.X = (int)pX;
								p.Y = (int)pY;
								fout << c;
								for (int i = 0; i < listBox5->SelectedIndices->Count; i++)
								{
									switch (listBox1->SelectedIndex)
									{
									case 0:
									case 1:
									case 2:
										fout << " " << i + 1 << ":" << window_direction_process(listBox5->SelectedIndices[i] + 1, window_data(p, listBox5->SelectedIndices[i] + 1, image_data, listBox1->SelectedIndex), listBox6->SelectedIndex);
										break;
									case 3:
										fout << " " << (i * 2) + 1 << ":" << window_direction_process(listBox5->SelectedIndices[i] + 1, window_data(p, listBox5->SelectedIndices[i] + 1, image_data, 0), listBox6->SelectedIndex) << " " << (i * 2) + 2 << ":" << window_direction_process(listBox5->SelectedIndices[i] + 1, window_data(p, listBox5->SelectedIndices[i] + 1, image_data, 1), listBox6->SelectedIndex);
										break;
									case 4:
										fout << " " << (i * 2) + 1 << ":" << window_direction_process(listBox5->SelectedIndices[i] + 1, window_data(p, listBox5->SelectedIndices[i] + 1, image_data, 1), listBox6->SelectedIndex) << " " << (i * 2) + 2 << ":" << window_direction_process(listBox5->SelectedIndices[i] + 1, window_data(p, listBox5->SelectedIndices[i] + 1, image_data, 2), listBox6->SelectedIndex);
										break;
									case 5:
										fout << " " << (i * 2) + 1 << ":" << window_direction_process(listBox5->SelectedIndices[i] + 1, window_data(p, listBox5->SelectedIndices[i] + 1, image_data, 0), listBox6->SelectedIndex) << " " << (i * 2) + 2 << ":" << window_direction_process(listBox5->SelectedIndices[i] + 1, window_data(p, listBox5->SelectedIndices[i] + 1, image_data, 2), listBox6->SelectedIndex);
										break;
									case 6:
										fout << " " << (i * 3) + 1 << ":" << window_direction_process(listBox5->SelectedIndices[i] + 1, window_data(p, listBox5->SelectedIndices[i] + 1, image_data, 0), listBox6->SelectedIndex) << " " << (i * 3) + 2 << ":" << window_direction_process(listBox5->SelectedIndices[i] + 1, window_data(p, listBox5->SelectedIndices[i] + 1, image_data, 1), listBox6->SelectedIndex) << " " << (i * 3) + 3 << ":" << window_direction_process(listBox5->SelectedIndices[i] + 1, window_data(p, listBox5->SelectedIndices[i] + 1, image_data, 2), listBox6->SelectedIndex);
										break;
									case 7:
										if (band_image_4 == nullptr)
										{
											fout << " " << (i * 3) + 1 << ":" << window_direction_process(listBox5->SelectedIndices[i] + 1, window_data(p, listBox5->SelectedIndices[i] + 1, image_data, 0), listBox6->SelectedIndex) << " " << (i * 3) + 2 << ":" << window_direction_process(listBox5->SelectedIndices[i] + 1, window_data(p, listBox5->SelectedIndices[i] + 1, image_data, 1), listBox6->SelectedIndex) << " " << (i * 3) + 3 << ":" << window_direction_process(listBox5->SelectedIndices[i] + 1, window_data(p, listBox5->SelectedIndices[i] + 1, image_data, 2), listBox6->SelectedIndex);
											break;
										}
										else
										{
											fout << " " << (i * 4) + 1 << ":" << window_direction_process(listBox5->SelectedIndices[i] + 1, window_data(p, listBox5->SelectedIndices[i] + 1, image_data, 0), listBox6->SelectedIndex) << " " << (i * 4) + 2 << ":" << window_direction_process(listBox5->SelectedIndices[i] + 1, window_data(p, listBox5->SelectedIndices[i] + 1, image_data, 1), listBox6->SelectedIndex) << " " << (i * 4) + 3 << ":" << window_direction_process(listBox5->SelectedIndices[i] + 1, window_data(p, listBox5->SelectedIndices[i] + 1, image_data, 2), listBox6->SelectedIndex) << " " << (i * 4) + 4 << ":" << window_direction_process(listBox5->SelectedIndices[i] + 1, window_data(p, listBox5->SelectedIndices[i] + 1, band_image_4, 0), listBox6->SelectedIndex);
											break;
										}
									}
								}
								fout << std::endl;
							}
							MessageBox::Show("Done!");
						}
						fin.close();
					}
				}
				fout.close();
			}
		}
		else
			MessageBox::Show("Please choose image first !");
	}
	private: System::Void button20_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (pictureBox1->Image != nullptr)
		{
			std::ofstream fout;
			std::ifstream fin;
			if (fin)
			{
				if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
				{
					StringConvertor path1(openFileDialog1->FileName);
					std::string file_name1 = path1.STLAnsiString;
					fin.open(file_name1.c_str(), std::ios::in);
					if (fout)
					{
						if (saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
						{
							StringConvertor path2(saveFileDialog1->FileName);
							std::string file_name2 = path2.STLAnsiString;
							fout.open(file_name2.c_str(), std::ios::out);
							label20->Text = saveFileDialog1->FileName;
							int c;
							float pX, pY;
							Point p;
							while (!fin.eof())
							{
								std::string si;
								getline(fin, si);
								std::stringstream sin(si);
								sin >> c >> pX >> pY;
								if (listBox15->SelectedIndex != 0)
								{
									if (imageAspect > controlAspect)
									{
										float ratioWidth = (float)image->Width / (float)pictureBox1->Width;
										pX *= ratioWidth;
										float scale = (float)pictureBox1->Width / image->Width;
										float displayHeight = scale * (float)image->Height;
										float diffHeight = (float)pictureBox1->Height - displayHeight;
										diffHeight /= 2;
										pY -= diffHeight;
										pY /= scale;
									}
									else
									{
										float ratioHeight = (float)image->Height / (float)pictureBox1->Height;
										pY *= ratioHeight;
										float scale = (float)pictureBox1->Height / image->Height;
										float displayWidth = scale * (float)image->Width;
										float diffWidth = (float)pictureBox1->Width - displayWidth;
										diffWidth /= 2;
										pX -= diffWidth;
										pX /= scale;
									}
								}
								p.X = (int)pX;
								p.Y = (int)pY;
								fout << c;
								if (listBox12->SelectedIndex == 3)
								{
									if (pictureBox5->Image == nullptr)
									{
										MessageBox::Show("Please input band image !");
										break;
									}
									else
									{
										for (int i = 0; i < listBox5->SelectedIndices->Count; i++)
											fout << " " << i + 1 << ":" << window_cross_process(listBox5->SelectedIndices[i] + 1, window_data(p, listBox5->SelectedIndices[i] + 1, image_data, listBox11->SelectedIndex), window_data(p, listBox5->SelectedIndices[i] + 1, band_image_4, 0));
									}

								}
								else
								{
									for (int i = 0; i < listBox5->SelectedIndices->Count; i++)
										fout << " " << i + 1 << ":" << window_cross_process(listBox5->SelectedIndices[i] + 1, window_data(p, listBox5->SelectedIndices[i] + 1, image_data, listBox11->SelectedIndex), window_data(p, listBox5->SelectedIndices[i] + 1, image_data, listBox12->SelectedIndex));
								}
								fout << std::endl;
							}
							MessageBox::Show("Done!");
						}
						fin.close();
					}
				}
				fout.close();
			}
		}
		else
			MessageBox::Show("Please choose image first !");
	}
	private: System::Void button21_Click(System::Object^ sender, System::EventArgs^ e)
	{
		std::ofstream fout;
		std::ifstream fin1, fin2;
		if (fin1 && fin2 && fout)
		{
			StringConvertor path1(label19->Text);
			std::string file_name1 = path1.STLAnsiString;
			fin1.open(file_name1.c_str(), std::ios::in);
			if (!fin1)
			{
				if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
				{
					StringConvertor path1(openFileDialog1->FileName);
					std::string file_name1 = path1.STLAnsiString;
					fin1.open(file_name1.c_str(), std::ios::in);
				}
			}
			StringConvertor path2(label20->Text);
			std::string file_name2 = path2.STLAnsiString;
			fin2.open(file_name2.c_str(), std::ios::in);
			if (!fin2)
			{
				if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
				{
					StringConvertor path1(openFileDialog1->FileName);
					std::string file_name1 = path1.STLAnsiString;
					fin2.open(file_name1.c_str(), std::ios::in);
				}
			}
			if (saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			{
				StringConvertor path3(saveFileDialog1->FileName);
				std::string file_name3 = path3.STLAnsiString;
				fout.open(file_name3.c_str(), std::ios::out);

				std::vector<int> target;
				std::vector< std::vector<double>> feature;
				target.clear();
				feature.clear();
				double f;
				int row, t, max = 0, max2 = 0, l;
				std::string strline;

				while (!fin1.eof())
				{
					getline(fin1, strline);
					if (!strline.empty())
					{
						std::stringstream ss(strline);
						ss >> l;
						target.push_back(l);
						row = 0;
						while (ss >> t)
						{
							ss.ignore(1, ':');
							ss >> f;
							if (t > max)
							{
								feature.resize(t);
								max = t;
							}
							feature[row].push_back(f);
							row++;
						}
					}
				}
				while (!fin2.eof())
				{
					getline(fin2, strline);
					if (!strline.empty())
					{
						std::stringstream ss(strline);
						ss >> l;
						row = max;
						while (ss >> t)
						{
							ss.ignore(1, ':');
							ss >> f;
							if (t > max2)
							{
								feature.resize(t + max);
								max2 = t;
							}
							feature[row].push_back(f);
							row++;
						}
					}
				}

				for (int i = 0; i != feature[0].size(); i++)
				{
					fout << target[i];
					for (int j = 0; j != feature.size(); j++)
					{
						fout << " " << j + 1 << ":" << feature[j][i];
					}
					fout << std::endl;
				}
				MessageBox::Show("Done!\n" + path3);
			}
			fin1.close();
			fin2.close();
			fout.close();
		}
	}
	private: System::Void button22_Click(System::Object^ sender, System::EventArgs^ e)
	{
		tabControl1->SelectedTab = tabControl1->TabPages[4];
		button18->PerformClick();
		tabControl1->SelectedTab = tabControl1->TabPages[5];
	}
	private: System::Void button23_Click(System::Object^ sender, System::EventArgs^ e)
	{
		label19->Text = "Path: ";
		label20->Text = "Path: ";
	}
	private: System::Void pictureBox5_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (label16->Text != "Band 4")
		{
			band_image_4_ini = gcnew Bitmap(label16->Text);
			System::Drawing::Rectangle cloneRect = System::Drawing::Rectangle(0, 0, band_image_4_ini->Width, band_image_4_ini->Height);
			band_image_4 = band_image_4_ini->Clone(cloneRect, System::Drawing::Imaging::PixelFormat::Format24bppRgb);
			pictureBox5->Image = band_image_4;
		}
	}
	private: System::Void button24_Click(System::Object^ sender, System::EventArgs^ e)
	{
		std::ifstream fin;
		if (fin)
		{
			if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			{
				StringConvertor path(openFileDialog1->FileName);
				std::string file_name = path.STLAnsiString, s;
				fin.open(file_name.c_str(), std::ios::in);

				while (!fin.eof())
				{
					getline(fin, s);
					StringConvertor pos(s);
					listBox13->Items->Add(pos.ToString());
				}
				//MessageBox::Show("Done!\n"+path);
			}
			fin.close();
		}
	}
	private: System::Void button25_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (image != nullptr)
		{
			clearOnlyFeaturesToolStripMenuItem->PerformClick();
			Point p;
			int class_num, X, Y;
			for (int ii = 0; ii < listBox13->Items->Count; ii++)
			{
				StringConvertor data(listBox13->GetItemText(listBox13->Items[ii]));
				std::stringstream s(data.STLAnsiString);
				s >> class_num >> X >> Y;
				p.X = X;
				p.Y = Y;
				h_max = listBox5->SelectedIndices[listBox5->SelectedIndices->Count - 1] + 1;
				if (p.X > (h_max - 1) && p.X < (image->Width - h_max) && (p.Y > h_max - 1) && p.Y <= (image->Height - h_max))
				{
					std::stringstream ss;
					ss << class_num;
					switch (listBox7->SelectedIndex)
					{
					case 0:
						for (int i = 0; i < listBox5->SelectedIndices->Count; i++)
						{
							switch (listBox1->SelectedIndex)
							{
							case 0:
							case 1:
							case 2:
								ss << " " << i + 1 << ":" << window_direction_process(listBox5->SelectedIndices[i] + 1, window_data(p, listBox5->SelectedIndices[i] + 1, image_data, listBox1->SelectedIndex), listBox6->SelectedIndex);
								break;
							case 3:
								ss << " " << (i * 2) + 1 << ":" << window_direction_process(listBox5->SelectedIndices[i] + 1, window_data(p, listBox5->SelectedIndices[i] + 1, image_data, 0), listBox6->SelectedIndex) << " " << (i * 2) + 2 << ":" << window_direction_process(listBox5->SelectedIndices[i] + 1, window_data(p, listBox5->SelectedIndices[i] + 1, image_data, 1), listBox6->SelectedIndex);
								break;
							case 4:
								ss << " " << (i * 2) + 1 << ":" << window_direction_process(listBox5->SelectedIndices[i] + 1, window_data(p, listBox5->SelectedIndices[i] + 1, image_data, 1), listBox6->SelectedIndex) << " " << (i * 2) + 2 << ":" << window_direction_process(listBox5->SelectedIndices[i] + 1, window_data(p, listBox5->SelectedIndices[i] + 1, image_data, 2), listBox6->SelectedIndex);
								break;
							case 5:
								ss << " " << (i * 2) + 1 << ":" << window_direction_process(listBox5->SelectedIndices[i] + 1, window_data(p, listBox5->SelectedIndices[i] + 1, image_data, 0), listBox6->SelectedIndex) << " " << (i * 2) + 2 << ":" << window_direction_process(listBox5->SelectedIndices[i] + 1, window_data(p, listBox5->SelectedIndices[i] + 1, image_data, 2), listBox6->SelectedIndex);
								break;
							case 6:
								ss << " " << (i * 3) + 1 << ":" << window_direction_process(listBox5->SelectedIndices[i] + 1, window_data(p, listBox5->SelectedIndices[i] + 1, image_data, 0), listBox6->SelectedIndex) << " " << (i * 3) + 2 << ":" << window_direction_process(listBox5->SelectedIndices[i] + 1, window_data(p, listBox5->SelectedIndices[i] + 1, image_data, 1), listBox6->SelectedIndex) << " " << (i * 3) + 3 << ":" << window_direction_process(listBox5->SelectedIndices[i] + 1, window_data(p, listBox5->SelectedIndices[i] + 1, image_data, 2), listBox6->SelectedIndex);
								break;
							case 7:
								if (band_image_4 == nullptr)
								{
									ss << " " << (i * 3) + 1 << ":" << window_direction_process(listBox5->SelectedIndices[i] + 1, window_data(p, listBox5->SelectedIndices[i] + 1, image_data, 0), listBox6->SelectedIndex) << " " << (i * 3) + 2 << ":" << window_direction_process(listBox5->SelectedIndices[i] + 1, window_data(p, listBox5->SelectedIndices[i] + 1, image_data, 1), listBox6->SelectedIndex) << " " << (i * 3) + 3 << ":" << window_direction_process(listBox5->SelectedIndices[i] + 1, window_data(p, listBox5->SelectedIndices[i] + 1, image_data, 2), listBox6->SelectedIndex);
									break;
								}
								else
								{
									ss << " " << (i * 4) + 1 << ":" << window_direction_process(listBox5->SelectedIndices[i] + 1, window_data(p, listBox5->SelectedIndices[i] + 1, image_data, 0), listBox6->SelectedIndex) << " " << (i * 4) + 2 << ":" << window_direction_process(listBox5->SelectedIndices[i] + 1, window_data(p, listBox5->SelectedIndices[i] + 1, image_data, 1), listBox6->SelectedIndex) << " " << (i * 4) + 3 << ":" << window_direction_process(listBox5->SelectedIndices[i] + 1, window_data(p, listBox5->SelectedIndices[i] + 1, image_data, 2), listBox6->SelectedIndex) << " " << (i * 4) + 4 << ":" << window_direction_process(listBox5->SelectedIndices[i] + 1, window_data(p, listBox5->SelectedIndices[i] + 1, band_image_4, 0), listBox6->SelectedIndex);
									break;
								}
							}
						}
						break;
					case 1:
						if (listBox12->SelectedIndex == 3)
						{
							if (pictureBox5->Image == nullptr)
							{
								MessageBox::Show("Please input band image !");
								ii = listBox13->Items->Count;
							}
							else
							{
								for (int i = 0; i < listBox5->SelectedIndices->Count; i++)
									ss << " " << i + 1 << ":" << window_cross_process(listBox5->SelectedIndices[i] + 1, window_data(p, listBox5->SelectedIndices[i] + 1, image_data, listBox11->SelectedIndex), window_data(p, listBox5->SelectedIndices[i] + 1, band_image_4, 0));
							}

						}
						else
						{
							for (int i = 0; i < listBox5->SelectedIndices->Count; i++)
								ss << " " << i + 1 << ":" << window_cross_process(listBox5->SelectedIndices[i] + 1, window_data(p, listBox5->SelectedIndices[i] + 1, image_data, listBox11->SelectedIndex), window_data(p, listBox5->SelectedIndices[i] + 1, image_data, listBox12->SelectedIndex));
						}
						break;
					case 2:
						int index_count = 0;
						for (int i = 0; i < listBox5->SelectedIndices->Count; i++)
						{
							switch (listBox1->SelectedIndex)
							{
							case 0:
							case 1:
							case 2:
								ss << " " << i + 1 << ":" << window_direction_process(listBox5->SelectedIndices[i] + 1, window_data(p, listBox5->SelectedIndices[i] + 1, image_data, listBox1->SelectedIndex), listBox6->SelectedIndex);
								index_count++;
								break;
							case 3:
								ss << " " << (i * 2) + 1 << ":" << window_direction_process(listBox5->SelectedIndices[i] + 1, window_data(p, listBox5->SelectedIndices[i] + 1, image_data, 0), listBox6->SelectedIndex) << " " << (i * 2) + 2 << ":" << window_direction_process(listBox5->SelectedIndices[i] + 1, window_data(p, listBox5->SelectedIndices[i] + 1, image_data, 1), listBox6->SelectedIndex);
								index_count += 2;
								break;
							case 4:
								ss << " " << (i * 2) + 1 << ":" << window_direction_process(listBox5->SelectedIndices[i] + 1, window_data(p, listBox5->SelectedIndices[i] + 1, image_data, 1), listBox6->SelectedIndex) << " " << (i * 2) + 2 << ":" << window_direction_process(listBox5->SelectedIndices[i] + 1, window_data(p, listBox5->SelectedIndices[i] + 1, image_data, 2), listBox6->SelectedIndex);
								index_count += 2;
								break;
							case 5:
								ss << " " << (i * 2) + 1 << ":" << window_direction_process(listBox5->SelectedIndices[i] + 1, window_data(p, listBox5->SelectedIndices[i] + 1, image_data, 0), listBox6->SelectedIndex) << " " << (i * 2) + 2 << ":" << window_direction_process(listBox5->SelectedIndices[i] + 1, window_data(p, listBox5->SelectedIndices[i] + 1, image_data, 2), listBox6->SelectedIndex);
								index_count += 2;
								break;
							case 6:
								ss << " " << (i * 3) + 1 << ":" << window_direction_process(listBox5->SelectedIndices[i] + 1, window_data(p, listBox5->SelectedIndices[i] + 1, image_data, 0), listBox6->SelectedIndex) << " " << (i * 3) + 2 << ":" << window_direction_process(listBox5->SelectedIndices[i] + 1, window_data(p, listBox5->SelectedIndices[i] + 1, image_data, 1), listBox6->SelectedIndex) << " " << (i * 3) + 3 << ":" << window_direction_process(listBox5->SelectedIndices[i] + 1, window_data(p, listBox5->SelectedIndices[i] + 1, image_data, 2), listBox6->SelectedIndex);
								index_count += 3;
								break;
							case 7:
								if (band_image_4 == nullptr)
								{
									ss << " " << (i * 3) + 1 << ":" << window_direction_process(listBox5->SelectedIndices[i] + 1, window_data(p, listBox5->SelectedIndices[i] + 1, image_data, 0), listBox6->SelectedIndex) << " " << (i * 3) + 2 << ":" << window_direction_process(listBox5->SelectedIndices[i] + 1, window_data(p, listBox5->SelectedIndices[i] + 1, image_data, 1), listBox6->SelectedIndex) << " " << (i * 3) + 3 << ":" << window_direction_process(listBox5->SelectedIndices[i] + 1, window_data(p, listBox5->SelectedIndices[i] + 1, image_data, 2), listBox6->SelectedIndex);
									index_count += 3;
									break;
								}
								else
								{
									ss << " " << (i * 4) + 1 << ":" << window_direction_process(listBox5->SelectedIndices[i] + 1, window_data(p, listBox5->SelectedIndices[i] + 1, image_data, 0), listBox6->SelectedIndex) << " " << (i * 4) + 2 << ":" << window_direction_process(listBox5->SelectedIndices[i] + 1, window_data(p, listBox5->SelectedIndices[i] + 1, image_data, 1), listBox6->SelectedIndex) << " " << (i * 4) + 3 << ":" << window_direction_process(listBox5->SelectedIndices[i] + 1, window_data(p, listBox5->SelectedIndices[i] + 1, image_data, 2), listBox6->SelectedIndex) << " " << (i * 4) + 4 << ":" << window_direction_process(listBox5->SelectedIndices[i] + 1, window_data(p, listBox5->SelectedIndices[i] + 1, band_image_4, 0), listBox6->SelectedIndex);
									index_count += 4;
									break;
								}
							}

						}
						if (listBox12->SelectedIndex == 3)
						{
							if (pictureBox5->Image == nullptr)
							{
								MessageBox::Show("Please input band image !");
								ii = listBox13->Items->Count;
							}
							else
							{

								for (int i = index_count; i < listBox5->SelectedIndices->Count + index_count; i++)
									ss << " " << i + 1 << ":" << window_cross_process(listBox5->SelectedIndices[i - index_count] + 1, window_data(p, listBox5->SelectedIndices[i - index_count] + 1, image_data, listBox11->SelectedIndex), window_data(p, listBox5->SelectedIndices[i - index_count] + 1, band_image_4, 0));
							}

						}
						else
						{

							for (int i = index_count; i < listBox5->SelectedIndices->Count + index_count; i++)
								ss << " " << i + 1 << ":" << window_cross_process(listBox5->SelectedIndices[i - index_count] + 1, window_data(p, listBox5->SelectedIndices[i - index_count] + 1, image_data, listBox11->SelectedIndex), window_data(p, listBox5->SelectedIndices[i - index_count] + 1, image_data, listBox12->SelectedIndex));
						}
						break;
					}

					std::string s = ss.str();
					StringConvertor sc(s);
					listBox4->Items->Add(sc.ToString());
					switch (class_num)
					{
					case 1:
						image->SetPixel(X, Y, Color::Red);
						break;
					case 2:
						image->SetPixel(X, Y, Color::Blue);
						break;
					}


				}

			}
			pictureBox1->Refresh();
			listBox4->TopIndex = listBox4->Items->Count - 1;
			//MessageBox::Show("Done!");
			tabControl1->SelectedTab = tabControl1->TabPages[1];
		}
		else
			MessageBox::Show("Please load image first !");
	}
	private: System::Void clearOnlyFeaturesToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
	{
		listBox4->Items->Clear();
	}
	private: System::Void checkBox2_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
	{
		if (checkBox2->Checked == true)
			checkBox2->Text = "Use Header";
		else
			checkBox2->Text = "Not Use Header";
	}
	private: System::Void trackBar1_Scroll(System::Object^ sender, System::EventArgs^ e)
	{
		label32->Text = String::Format("size: {0}", trackBar1->Value);
	}
	private: System::Void panel7_SizeChanged(System::Object^ sender, System::EventArgs^ e)
	{
		size_panel7 = panel7->Size;
		size_pictureBox1 = pictureBox1->Size;
		double ratio_Height = (double)(size_panel7.Height - pictureBox1->Location.Y) / (double)size_pictureBox1.Height;
		double ratio_Width = (double)(size_panel7.Width - pictureBox1->Location.X) / (double)size_pictureBox1.Width;
		if (pictureBox1->Image != nullptr && ratio_Width > 0 && ratio_Height > 0)
		{
			if (ratio_Height < ratio_Width)
			{
				size_pictureBox1.Height = (int)((double)size_pictureBox1.Height * ratio_Height);
				size_pictureBox1.Width = (int)((double)size_pictureBox1.Width * ratio_Height);
			}
			else
			{
				size_pictureBox1.Height = (int)((double)size_pictureBox1.Height * ratio_Width);
				size_pictureBox1.Width = (int)((double)size_pictureBox1.Width * ratio_Width);
			}
			pictureBox1->Size = size_pictureBox1;

		}
		//imageAspect=(float)image->Width/image->Height;
		//controlAspect=(float)pictureBox1->Width/pictureBox1->Height;
	}
	private: System::Void defaultSizeToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
	{
		this->Size = System::Drawing::Size(1057, 503);
	}
	private: System::Void button26_Click(System::Object^ sender, System::EventArgs^ e)
	{
		listBox4->Items->Clear();
		tabControl1->SelectedTab = tabControl1->TabPages[4];
		button25->PerformClick();
		tabControl1->SelectedTab = tabControl1->TabPages[1];
	}
	private: System::Void pictureBox1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e)
	{
		if (pictureBox1->Image != nullptr)
		{
			Point picBox1Location;
			Drawing::Size graPic;
			if (imageAspect == 1)
			{
				picBox1Location = Point(0, 0);
				graPic = size_pictureBox1;
			}
			else if (imageAspect > 1)
			{
				picBox1Location = Point(0, (pictureBox1->Height - pictureBox1->Width / image->Width * image->Height) / 2);
				graPic = Drawing::Size(size_pictureBox1.Width, pictureBox1->Width / image->Width * image->Height);
			}
			else
			{
				picBox1Location = Point((pictureBox1->Width - pictureBox1->Height / image->Height * image->Width) / 2, 0);
				graPic = Drawing::Size(pictureBox1->Height / image->Height * image->Width, size_pictureBox1.Height);
			}
			e->Graphics->InterpolationMode = Drawing2D::InterpolationMode::NearestNeighbor;
			System::Drawing::Rectangle destRect = System::Drawing::Rectangle(picBox1Location, graPic);
			e->Graphics->DrawImage(pictureBox1->Image, destRect);
		}
		Pen^ pen;
		switch (listBox3->SelectedIndex)
		{
		case 0:
			pen = gcnew Pen(Color::Red, 1.0f);
			break;
		case 1:
			pen = gcnew Pen(Color::Green, 1.0f);
			break;
		case 2:
			pen = gcnew Pen(Color::Blue, 1.0f);
			break;
		case 3:
			pen = gcnew Pen(Color::Black, 1.0f);
			break;
		}
		if (imgSelePoints->Count == 0)
			return;
		if (imgSelePoints->Count == 1)
		{
			if (right_click == false)
			{
				e->Graphics->DrawEllipse(pen, imgSelePoints[0].X - 1, imgSelePoints[0].Y - 1, 2, 2);
			}
			else
			{
				visible_points->Add(imgSelePoints[0]);
			}
		}
		else if (imgSelePoints->Count >= 2)
		{
			if (right_click == false)
			{
				e->Graphics->DrawLines(pen, curvePoints);
			}
			else if (imgSelePoints->Count >= 3)
			{
				Point p;
				GraphicsPath^ Path = gcnew GraphicsPath;
				Path->AddPolygon(curvePoints);
				System::Drawing::Region^ region = gcnew System::Drawing::Region(Path);
				for (int i = min_XY.Y; i <= max_XY.Y; i++)
				{
					for (int j = min_XY.X; j <= max_XY.X; j++)
					{
						p = Point(j, i);
						if (region->IsVisible(p))
						{
							visible_points->Add(p);
						}
					}
				}
			}
		}
	}
	private: System::Void button27_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			image_raw_data = gcnew Bitmap(openFileDialog1->FileName);
			System::Drawing::Rectangle cloneRect = System::Drawing::Rectangle(0, 0, image_raw_data->Width, image_raw_data->Height);
			image = image_raw_data->Clone(cloneRect, System::Drawing::Imaging::PixelFormat::Format24bppRgb);
			image_data = image_raw_data->Clone(cloneRect, System::Drawing::Imaging::PixelFormat::Format24bppRgb);
			imgLocation = Point(162, 3);
			size_panel1 = panel1->Size;
			double ratio_Height = (double)(size_panel1.Height - imgLocation.Y) / (double)image->Height;
			double ratio_Width = (double)(size_panel1.Width - imgLocation.X) / (double)image->Width;
			if (image != nullptr && ratio_Width > 0 && ratio_Height > 0)
			{
				if (ratio_Height < ratio_Width)
				{
					recImage.Height = (int)((double)image->Height * ratio_Height);
					recImage.Width = (int)((double)image->Width * ratio_Height);
				}
				else
				{
					recImage.Height = (int)((double)image->Height * ratio_Width);
					recImage.Width = (int)((double)image->Width * ratio_Width);
				}
				recImage.Location = imgLocation;
			}
			picGraphics = panel1->CreateGraphics();
			picGraphics->InterpolationMode = Drawing2D::InterpolationMode::NearestNeighbor;
			imageAspect = (float)image->Width / image->Height;
			controlAspect = (float)recImage.Width / recImage.Height;
			label40->Text = "Width: " + Convert::ToString(image->Width);
			label38->Text = "Height: " + Convert::ToString(image->Height);
			label11->Text = openFileDialog1->FileName;
			this->Text = "SVM_WinForm " + openFileDialog1->FileName;
		}
	}
	private: System::Void panel1_SizeChanged(System::Object^ sender, System::EventArgs^ e)
	{
		if (image == nullptr)
		{
			return;
		}
		size_panel1 = panel1->Size;
		double ratio_Height = (double)(size_panel1.Height - imgLocation.Y) / (double)image->Height;
		double ratio_Width = (double)(size_panel1.Width - imgLocation.X) / (double)image->Width;
		if (ratio_Width > 0 && ratio_Height > 0)
		{
			if (ratio_Height < ratio_Width)
			{
				recImage.Height = (int)((double)image->Height * ratio_Height);
				recImage.Width = (int)((double)image->Width * ratio_Height);
			}
			else
			{
				recImage.Height = (int)((double)image->Height * ratio_Width);
				recImage.Width = (int)((double)image->Width * ratio_Width);
			}
			recImage.Location = imgLocation;
			imageAspect = (float)image->Width / image->Height;
			controlAspect = (float)recImage.Width / recImage.Height;
			picGraphics = panel1->CreateGraphics();
			picGraphics->InterpolationMode = Drawing2D::InterpolationMode::NearestNeighbor;
		}
	}
	private: System::Void panel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e)
	{
		if (image != nullptr)
		{
			picGraphics->DrawImage(image, recImage);
			imageRegionGraphics = panel1->CreateGraphics();

			Pen^ pen;
			switch (listBox16->SelectedIndex)
			{
			case 0:
				pen = gcnew Pen(Color::Red, 1.0f);
				break;
			case 1:
				pen = gcnew Pen(Color::Green, 1.0f);
				break;
			case 2:
				pen = gcnew Pen(Color::Blue, 1.0f);
				break;
			case 3:
				pen = gcnew Pen(Color::Black, 1.0f);
				break;
			}
			if (imgSelePoints->Count == 0)
			{
				return;
			}
			if (imgSelePoints->Count == 1)
			{
				if (right_click == false)
				{
					imageRegionGraphics->DrawEllipse(pen, imgDisPoints[0].X - 1, imgDisPoints[0].Y - 1, 2, 2);
				}
			}
			else if (imgSelePoints->Count >= 2)
			{
				if (right_click == false)
				{
					imageRegionGraphics->DrawLines(pen, curveDisPoints);
				}
			}
		}
	}
	private: System::Void panel1_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
	{
		double X, Y;
		if (image != nullptr && e->X >= imgLocation.X && e->X <= imgLocation.X + recImage.Width && e->Y >= imgLocation.Y && e->Y <= imgLocation.Y + recImage.Height)
		{
			if (image->Width != 0 && image->Height != 0)
			{
				X = e->X - imgLocation.X;
				Y = e->Y - imgLocation.Y;
				if (imageAspect > controlAspect)
				{
					double ratioWidth = (double)image->Width / (double)recImage.Width;
					X *= ratioWidth;
					double scale = (double)recImage.Width / image->Width;
					double displayHeight = scale * (double)image->Height;
					double diffHeight = (double)recImage.Height - displayHeight;
					diffHeight /= 2;
					Y -= diffHeight;
					Y /= scale;
				}
				else
				{
					double ratioHeight = (double)image->Height / (double)recImage.Height;
					Y *= ratioHeight;
					double scale = (double)recImage.Height / image->Height;
					double displayWidth = scale * (double)image->Width;
					double diffWidth = (double)recImage.Width - displayWidth;
					diffWidth /= 2;
					X -= diffWidth;
					X /= scale;
				}
				p.X = System::Math::Round(X);
				p.Y = System::Math::Round(Y);
				if (p.X >= 0 && p.X < image->Width && p.Y >= 0 && p.Y < image->Height)
				{
					label37->Text = String::Format("X: {0}", p.X + 1);
					label39->Text = String::Format("Y: {0}", p.Y + 1);
					Color c;
					c = image_data->GetPixel(p.X, p.Y);
					label36->Text = String::Format("R: {0}\nG: {1}\nB: {2}", c.R, c.G, c.B);
				}
				else
				{
					label37->Text = String::Format("X: ##");
					label39->Text = String::Format("Y: ##");
				}
			}
		}
	}
	private: System::Void panel1_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
	{
		if (image != nullptr && e->X >= imgLocation.X && e->X < imgLocation.X + recImage.Width && e->Y >= imgLocation.Y && e->Y < imgLocation.Y + recImage.Height)
		{
			switch (e->Button)
			{
			case System::Windows::Forms::MouseButtons::Left:
			{
				double X, Y;
				Point p;
				X = e->X - imgLocation.X;
				Y = e->Y - imgLocation.Y;
				if (imageAspect > controlAspect)
				{
					double ratioWidth = (double)image->Width / (double)recImage.Width;
					X *= ratioWidth;
					double scale = (double)recImage.Width / image->Width;
					double displayHeight = scale * (double)image->Height;
					double diffHeight = (double)recImage.Height - displayHeight;
					diffHeight /= 2;
					Y -= diffHeight;
					Y /= scale;
				}
				else
				{
					double ratioHeight = (double)image->Height / (double)recImage.Height;
					Y *= ratioHeight;
					double scale = (double)recImage.Height / image->Height;
					double displayWidth = scale * (double)image->Width;
					double diffWidth = (double)recImage.Width - displayWidth;
					diffWidth /= 2;
					X -= diffWidth;
					X /= scale;
				}
				p.X = System::Math::Round(X);
				p.Y = System::Math::Round(Y);
				if (right_click)
				{
					max_XY = min_XY = p;
				}
				right_click = false;
				if (p.X > max_XY.X)
					max_XY.X = p.X;
				else if (p.X < min_XY.X)
					min_XY.X = p.X;
				if (p.Y > max_XY.Y)
					max_XY.Y = p.Y;
				else if (p.Y < min_XY.Y)
					min_XY.Y = p.Y;
				imgDisPoints->Add(e->Location);
				Array::Resize(curveDisPoints, imgDisPoints->Count);
				for (int i = 0; i < imgDisPoints->Count; i++)
					curveDisPoints[i] = imgDisPoints[i];
				imgSelePoints->Add(p);
				Array::Resize(curvePoints, imgSelePoints->Count);
				for (int i = 0; i < imgSelePoints->Count; i++)
					curvePoints[i] = imgSelePoints[i];
			}
			break;
			case System::Windows::Forms::MouseButtons::Right:
				right_click = true;
				if (imgSelePoints->Count == 1)
				{
					visible_points->Add(imgSelePoints[0]);
				}
				else if (imgSelePoints->Count >= 3)
				{
					GraphicsPath^ Path = gcnew GraphicsPath;
					Path->AddPolygon(curvePoints);
					System::Drawing::Region^ region = gcnew System::Drawing::Region(Path);
					for (int i = min_XY.Y; i <= max_XY.Y; i++)
					{
						for (int j = min_XY.X; j <= max_XY.X; j++)
						{
							if (region->IsVisible(Point(j, i)))
							{
								visible_points->Add(Point(j, i));
							}
						}
					}
				}
				else
				{
					break;
				}
				for (int point_num = 0; point_num < visible_points->Count; point_num++)
				{
					Point p;
					p = visible_points[point_num];
					h_max = listBox5->SelectedIndices[listBox5->SelectedIndices->Count - 1] + 1;
					if (p.X > (h_max - 1) && p.X < (image->Width - h_max) && (p.Y > h_max - 1) && p.Y < (image->Height - h_max))
					{
						std::stringstream ss;
						ss << listBox2->SelectedIndex + 1;
						switch (listBox7->SelectedIndex)
						{
						case 0:
							for (int i = 0; i < listBox5->SelectedIndices->Count; i++)
							{
								switch (listBox1->SelectedIndex)
								{
								case 0:
								case 1:
								case 2:
									ss << " " << i + 1 << ":" << window_direction_process(listBox5->SelectedIndices[i] + 1, window_data(p, listBox5->SelectedIndices[i] + 1, image_data, listBox1->SelectedIndex), listBox6->SelectedIndex);
									break;
								case 3:
									ss << " " << (i * 2) + 1 << ":" << window_direction_process(listBox5->SelectedIndices[i] + 1, window_data(p, listBox5->SelectedIndices[i] + 1, image_data, 0), listBox6->SelectedIndex) << " " << (i * 2) + 2 << ":" << window_direction_process(listBox5->SelectedIndices[i] + 1, window_data(p, listBox5->SelectedIndices[i] + 1, image_data, 1), listBox6->SelectedIndex);
									break;
								case 4:
									ss << " " << (i * 2) + 1 << ":" << window_direction_process(listBox5->SelectedIndices[i] + 1, window_data(p, listBox5->SelectedIndices[i] + 1, image_data, 1), listBox6->SelectedIndex) << " " << (i * 2) + 2 << ":" << window_direction_process(listBox5->SelectedIndices[i] + 1, window_data(p, listBox5->SelectedIndices[i] + 1, image_data, 2), listBox6->SelectedIndex);
									break;
								case 5:
									ss << " " << (i * 2) + 1 << ":" << window_direction_process(listBox5->SelectedIndices[i] + 1, window_data(p, listBox5->SelectedIndices[i] + 1, image_data, 0), listBox6->SelectedIndex) << " " << (i * 2) + 2 << ":" << window_direction_process(listBox5->SelectedIndices[i] + 1, window_data(p, listBox5->SelectedIndices[i] + 1, image_data, 2), listBox6->SelectedIndex);
									break;
								case 6:
									ss << " " << (i * 3) + 1 << ":" << window_direction_process(listBox5->SelectedIndices[i] + 1, window_data(p, listBox5->SelectedIndices[i] + 1, image_data, 0), listBox6->SelectedIndex) << " " << (i * 3) + 2 << ":" << window_direction_process(listBox5->SelectedIndices[i] + 1, window_data(p, listBox5->SelectedIndices[i] + 1, image_data, 1), listBox6->SelectedIndex) << " " << (i * 3) + 3 << ":" << window_direction_process(listBox5->SelectedIndices[i] + 1, window_data(p, listBox5->SelectedIndices[i] + 1, image_data, 2), listBox6->SelectedIndex);
									break;
								case 7:
									if (band_image_4 == nullptr)
									{
										ss << " " << (i * 3) + 1 << ":" << window_direction_process(listBox5->SelectedIndices[i] + 1, window_data(p, listBox5->SelectedIndices[i] + 1, image_data, 0), listBox6->SelectedIndex) << " " << (i * 3) + 2 << ":" << window_direction_process(listBox5->SelectedIndices[i] + 1, window_data(p, listBox5->SelectedIndices[i] + 1, image_data, 1), listBox6->SelectedIndex) << " " << (i * 3) + 3 << ":" << window_direction_process(listBox5->SelectedIndices[i] + 1, window_data(p, listBox5->SelectedIndices[i] + 1, image_data, 2), listBox6->SelectedIndex);
										break;
									}
									else
									{
										ss << " " << (i * 4) + 1 << ":" << window_direction_process(listBox5->SelectedIndices[i] + 1, window_data(p, listBox5->SelectedIndices[i] + 1, image_data, 0), listBox6->SelectedIndex) << " " << (i * 4) + 2 << ":" << window_direction_process(listBox5->SelectedIndices[i] + 1, window_data(p, listBox5->SelectedIndices[i] + 1, image_data, 1), listBox6->SelectedIndex) << " " << (i * 4) + 3 << ":" << window_direction_process(listBox5->SelectedIndices[i] + 1, window_data(p, listBox5->SelectedIndices[i] + 1, image_data, 2), listBox6->SelectedIndex) << " " << (i * 4) + 4 << ":" << window_direction_process(listBox5->SelectedIndices[i] + 1, window_data(p, listBox5->SelectedIndices[i] + 1, band_image_4, 0), listBox6->SelectedIndex);
										break;
									}
								}
							}
							break;
						case 1:
							if (listBox12->SelectedIndex == 3)
							{
								if (pictureBox5->Image == nullptr)
									MessageBox::Show("Please input band image !");
								else
								{
									for (int i = 0; i < listBox5->SelectedIndices->Count; i++)
										ss << " " << i + 1 << ":" << window_cross_process(listBox5->SelectedIndices[i] + 1, window_data(p, listBox5->SelectedIndices[i] + 1, image_data, listBox11->SelectedIndex), window_data(p, listBox5->SelectedIndices[i] + 1, band_image_4, 0));
								}

							}
							else
							{
								for (int i = 0; i < listBox5->SelectedIndices->Count; i++)
									ss << " " << i + 1 << ":" << window_cross_process(listBox5->SelectedIndices[i] + 1, window_data(p, listBox5->SelectedIndices[i] + 1, image_data, listBox11->SelectedIndex), window_data(p, listBox5->SelectedIndices[i] + 1, image_data, listBox12->SelectedIndex));
							}
							break;
						case 2:
							int index_count = 0;
							for (int i = 0; i < listBox5->SelectedIndices->Count; i++)
							{
								switch (listBox1->SelectedIndex)
								{
								case 0:
								case 1:
								case 2:
									ss << " " << i + 1 << ":" << window_direction_process(listBox5->SelectedIndices[i] + 1, window_data(p, listBox5->SelectedIndices[i] + 1, image_data, listBox1->SelectedIndex), listBox6->SelectedIndex);
									index_count++;
									break;
								case 3:
									ss << " " << (i * 2) + 1 << ":" << window_direction_process(listBox5->SelectedIndices[i] + 1, window_data(p, listBox5->SelectedIndices[i] + 1, image_data, 0), listBox6->SelectedIndex) << " " << (i * 2) + 2 << ":" << window_direction_process(listBox5->SelectedIndices[i] + 1, window_data(p, listBox5->SelectedIndices[i] + 1, image_data, 1), listBox6->SelectedIndex);
									index_count += 2;
									break;
								case 4:
									ss << " " << (i * 2) + 1 << ":" << window_direction_process(listBox5->SelectedIndices[i] + 1, window_data(p, listBox5->SelectedIndices[i] + 1, image_data, 1), listBox6->SelectedIndex) << " " << (i * 2) + 2 << ":" << window_direction_process(listBox5->SelectedIndices[i] + 1, window_data(p, listBox5->SelectedIndices[i] + 1, image_data, 2), listBox6->SelectedIndex);
									index_count += 2;
									break;
								case 5:
									ss << " " << (i * 2) + 1 << ":" << window_direction_process(listBox5->SelectedIndices[i] + 1, window_data(p, listBox5->SelectedIndices[i] + 1, image_data, 0), listBox6->SelectedIndex) << " " << (i * 2) + 2 << ":" << window_direction_process(listBox5->SelectedIndices[i] + 1, window_data(p, listBox5->SelectedIndices[i] + 1, image_data, 2), listBox6->SelectedIndex);
									index_count += 2;
									break;
								case 6:
									ss << " " << (i * 3) + 1 << ":" << window_direction_process(listBox5->SelectedIndices[i] + 1, window_data(p, listBox5->SelectedIndices[i] + 1, image_data, 0), listBox6->SelectedIndex) << " " << (i * 3) + 2 << ":" << window_direction_process(listBox5->SelectedIndices[i] + 1, window_data(p, listBox5->SelectedIndices[i] + 1, image_data, 1), listBox6->SelectedIndex) << " " << (i * 3) + 3 << ":" << window_direction_process(listBox5->SelectedIndices[i] + 1, window_data(p, listBox5->SelectedIndices[i] + 1, image_data, 2), listBox6->SelectedIndex);
									index_count += 3;
									break;
								case 7:
									if (band_image_4 == nullptr)
									{
										ss << " " << (i * 3) + 1 << ":" << window_direction_process(listBox5->SelectedIndices[i] + 1, window_data(p, listBox5->SelectedIndices[i] + 1, image_data, 0), listBox6->SelectedIndex) << " " << (i * 3) + 2 << ":" << window_direction_process(listBox5->SelectedIndices[i] + 1, window_data(p, listBox5->SelectedIndices[i] + 1, image_data, 1), listBox6->SelectedIndex) << " " << (i * 3) + 3 << ":" << window_direction_process(listBox5->SelectedIndices[i] + 1, window_data(p, listBox5->SelectedIndices[i] + 1, image_data, 2), listBox6->SelectedIndex);
										index_count += 3;
										break;
									}
									else
									{
										ss << " " << (i * 4) + 1 << ":" << window_direction_process(listBox5->SelectedIndices[i] + 1, window_data(p, listBox5->SelectedIndices[i] + 1, image_data, 0), listBox6->SelectedIndex) << " " << (i * 4) + 2 << ":" << window_direction_process(listBox5->SelectedIndices[i] + 1, window_data(p, listBox5->SelectedIndices[i] + 1, image_data, 1), listBox6->SelectedIndex) << " " << (i * 4) + 3 << ":" << window_direction_process(listBox5->SelectedIndices[i] + 1, window_data(p, listBox5->SelectedIndices[i] + 1, image_data, 2), listBox6->SelectedIndex) << " " << (i * 4) + 4 << ":" << window_direction_process(listBox5->SelectedIndices[i] + 1, window_data(p, listBox5->SelectedIndices[i] + 1, band_image_4, 0), listBox6->SelectedIndex);
										index_count += 4;
										break;
									}
								}

							}
							if (listBox12->SelectedIndex == 3)
							{
								if (pictureBox5->Image == nullptr)
									MessageBox::Show("Please input band image !");
								else
								{
									for (int i = index_count; i < listBox5->SelectedIndices->Count + index_count; i++)
										ss << " " << i + 1 << ":" << window_cross_process(listBox5->SelectedIndices[i - index_count] + 1, window_data(p, listBox5->SelectedIndices[i - index_count] + 1, image_data, listBox11->SelectedIndex), window_data(p, listBox5->SelectedIndices[i - index_count] + 1, band_image_4, 0));
								}

							}
							else
							{
								for (int i = index_count; i < listBox5->SelectedIndices->Count + index_count; i++)
									ss << " " << i + 1 << ":" << window_cross_process(listBox5->SelectedIndices[i - index_count] + 1, window_data(p, listBox5->SelectedIndices[i - index_count] + 1, image_data, listBox11->SelectedIndex), window_data(p, listBox5->SelectedIndices[i - index_count] + 1, image_data, listBox12->SelectedIndex));
							}
							break;
						}
						std::string s = ss.str();
						StringConvertor sc(s);
						listBox4->Items->Add(sc.ToString());
						switch (listBox16->SelectedIndex)
						{
						case 0:
							image->SetPixel(p.X, p.Y, Color::Red);
							break;
						case 1:
							image->SetPixel(p.X, p.Y, Color::Green);
							break;
						case 2:
							image->SetPixel(p.X, p.Y, Color::Blue);
							break;
						case 3:
							image->SetPixel(p.X, p.Y, Color::Black);
							break;
						}
						listBox4->TopIndex = listBox4->Items->Count - 1;
						if (checkBox1->Checked == true)
						{
							if (listBox14->SelectedIndex == 0)
								listBox13->Items->Add((listBox17->SelectedIndex + 1) + " " + p.X + " " + p.Y);
							else
								listBox13->Items->Add((listBox17->SelectedIndex + 1) + " " + (e->X + 1) + " " + (e->Y + 1));
							listBox13->TopIndex = listBox13->Items->Count - 1;
						}
					}
				}
				right_click = false;
				imgSelePoints->Clear();
				imgDisPoints->Clear();
				visible_points->Clear();
				Array::Resize(curvePoints, 0);
				Array::Resize(curveDisPoints, 0);
				break;
			}
			panel1->Refresh();
		}
	}
	};
}