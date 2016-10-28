#pragma once
#include <opencv\cv.h>
#include <opencv\highgui.h>
#include <opencv2\core.hpp>
#include <opencv2\contrib\contrib.hpp>
#include <opencv2\highgui.hpp>
#include <opencv2\imgproc.hpp>
#include <opencv2\objdetect.hpp>
#include <iostream>
#include <fstream>
#include <sstream>
//#include "stdAfx.h"
#include "Attendance_Stats_Screen.h"

using namespace cv;
using namespace std;


namespace Group4_Class_Attendance_System {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	
	public ref class Main_Screen : public System::Windows::Forms::Form
	{
	public:
		Main_Screen(void)
		{
			InitializeComponent();
		}

	protected:
		~Main_Screen()
		{
			if (components)
			{
				delete components;
			}
		}

	public:  
		static System::Windows::Forms::Timer^ myTimer = gcnew System::Windows::Forms::Timer;		//Timer used to control capturing time
		static int lectureNumber = 0;
		static int quater = 1;
	private: System::Windows::Forms::ComboBox^  lectrueNumComboBox;
	public:

	private: System::Windows::Forms::Label^  lectureNumberlbl;
	private: System::Windows::Forms::Label^  chosenLecturelbl;
	private: System::Windows::Forms::Button^  button1;

	public:
	private:
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			this->lectrueNumComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->lectureNumberlbl = (gcnew System::Windows::Forms::Label());
			this->chosenLecturelbl = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// lectrueNumComboBox
			// 
			this->lectrueNumComboBox->FormattingEnabled = true;
			this->lectrueNumComboBox->Items->AddRange(gcnew cli::array< System::Object^  >(25) {
				L"1", L"2", L"3", L"4", L"5", L"6", L"7",
					L"8", L"9", L"10", L"11", L"12", L"13", L"14", L"15", L"16", L"17", L"18", L"19", L"20", L"21", L"22", L"23", L"24", L"25"
			});
			this->lectrueNumComboBox->Location = System::Drawing::Point(258, 41);
			this->lectrueNumComboBox->Name = L"lectrueNumComboBox";
			this->lectrueNumComboBox->Size = System::Drawing::Size(146, 21);
			this->lectrueNumComboBox->TabIndex = 0;
			this->lectrueNumComboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &Main_Screen::lectrueNumComboBox_SelectedIndexChanged);
			// 
			// lectureNumberlbl
			// 
			this->lectureNumberlbl->AutoSize = true;
			this->lectureNumberlbl->Location = System::Drawing::Point(35, 44);
			this->lectureNumberlbl->Name = L"lectureNumberlbl";
			this->lectureNumberlbl->Size = System::Drawing::Size(217, 13);
			this->lectureNumberlbl->TabIndex = 1;
			this->lectureNumberlbl->Text = L"Please select the Lecture Number to begin:  ";
			// 
			// chosenLecturelbl
			// 
			this->chosenLecturelbl->AutoSize = true;
			this->chosenLecturelbl->Location = System::Drawing::Point(268, 44);
			this->chosenLecturelbl->Name = L"chosenLecturelbl";
			this->chosenLecturelbl->Size = System::Drawing::Size(0, 13);
			this->chosenLecturelbl->TabIndex = 2;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(258, 180);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(208, 38);
			this->button1->TabIndex = 3;
			this->button1->Text = L"View Attendance Statistics";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Main_Screen::button1_Click);
			// 
			// Main_Screen
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(478, 230);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->chosenLecturelbl);
			this->Controls->Add(this->lectureNumberlbl);
			this->Controls->Add(this->lectrueNumComboBox);
			this->Name = L"Main_Screen";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Main_Screen";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: void static TimerEventProcessor(Object^ myObject, EventArgs^ myEventArgs)
	{
		myTimer->Stop();
	 
			//Capturing image and processing goes here
		MessageBox::Show("Taking out picture number " + quater);
		captureImage();

		if (quater > 4)
		{
			MessageBox::Show("..............................");
			myTimer->Stop();
			myTimer->Enabled = false;
		}
		else{
			myTimer->Enabled = true;
		}


		
	 }

	private: System::Void lectrueNumComboBox_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
		
		lectureNumber = Convert::ToInt32(this->lectrueNumComboBox->SelectedItem::get());
		//MessageBox::Show("Lecture number : " + lectureNumber + " chosen.");
		chosenLecturelbl->Text = "Lecture number : " + lectureNumber + " chosen.";
		lectrueNumComboBox->Visible = false;

		captureImage();
		myTimer->Tick += gcnew EventHandler(TimerEventProcessor);
		myTimer->Interval = 2000;					// Sets the timer interval to 10 minutes.
		myTimer->Start();
		
	}


	 static void captureImage()
	 {
		 
			 Mat capturedImage;
			 vector<Mat> faces;
			 vector<int> ids;

			 read_csv("C:/Class_Attendance_System_Files/csv_file.csv", faces, ids);

			 int im_width = faces[0].cols;
			 int im_height = faces[0].rows;

			 Ptr<FaceRecognizer> model = createFisherFaceRecognizer();
			 model->train(faces, ids);

			 CascadeClassifier haar_cascade;
			 haar_cascade.load("C:/Class_Attendance_System_Files/haarcascade_frontalface_default.xml");

			 VideoCapture cap;
			 cap.open(0);

			 if (!cap.isOpened())
			 {
				 MessageBox::Show("ERROR: Could not open camera.");
			 }

			 //namedWindow("window", 1);
			 cap >> capturedImage;
			 //imshow("window", capturedImage);

			 Mat original = capturedImage.clone();
			 Mat greyImage;
			 cvtColor(capturedImage, greyImage, CV_BGR2GRAY);

			 vector<Rect_<int>> facePositions;
			 haar_cascade.detectMultiScale(greyImage, facePositions);

			 for (int i = 0; i < facePositions.size(); i++)
			 {

				 Rect face_i = facePositions[i];
				 Mat getFace = greyImage(face_i);
				 Mat face_resized;
				 cv::resize(getFace, face_resized, cv::Size(im_width, im_height), 1.0, 1.0, INTER_CUBIC);
				 int foundID = model->predict(face_resized);
				 //setAttendance(foundID,quater);

				 rectangle(original, face_i, CV_RGB(0, 255, 0), 1);///////////////////////////////////////////////////////////
				 string box_text = format("ID = %d", foundID);
				 int pos_x = std::max(face_i.tl().x - 10, 0);
				 int pos_y = std::max(face_i.tl().y - 10, 0);
				 putText(original, box_text, cv::Point(pos_x, pos_y), FONT_HERSHEY_PLAIN, 1.0, CV_RGB(0, 255, 0), 2.0);///////

			 }

			 imshow("face_recognizer", original);
			 char key = (char)waitKey(20);

		 quater++;
	 }

	 static void read_csv(const string& filepath, vector<Mat>& images, vector<int>& labels) 
	 {		 
		 std::ifstream file(filepath.c_str(), ifstream::in);
		 if (!file) 
		 {
			 MessageBox::Show("ERROR: Could not read CSV file.");
		 }
		 string line, path, classlabel;
		 while (getline(file, line)) 
		 {
			 stringstream liness(line);
			 getline(liness, path, ';');
			 getline(liness, classlabel);
			 if (!path.empty() && !classlabel.empty()) 
			 {
				 images.push_back(imread(path, 0));
				 labels.push_back(atoi(classlabel.c_str()));
			 }
		 }
	 }



private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
	this->Hide();
	Attendance_Stats_Screen^ ass = gcnew Attendance_Stats_Screen();
	ass->ShowDialog();
}
};
}
