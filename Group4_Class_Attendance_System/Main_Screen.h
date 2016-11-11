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
#include <string>
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
	using namespace MySql::Data::MySqlClient;

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
		static System::Windows::Forms::Timer^ myTimer = gcnew System::Windows::Forms::Timer;		
															//Timer used to control capturing time
		static int lectureNumber = 0;						//Stores the lecture number 
		static int quarter = 1;								//The current quarter of the lecture
		static System::String^ constring;					//Used for database communication
		static MySqlConnection^ conDataBase;
		static MySqlConnection^ conDataBase1;
		static MySqlConnection^ conDataBase2;
		static MySqlDataReader^ myReader;
		static MySqlDataReader^ myReader1;
		static MySqlDataReader^ myReader2;
		static System::String^ quarter1;					//Stores the presence of a student in quater1
		static System::String^ quarter2;					//Stores the presence of a student in quater2
		static System::String^ quarter3;					//Stores the presence of a student in quater3
		static System::String^ quarter4;					//Stores the presence of a student in quater4
		

	private: 
		System::Windows::Forms::ComboBox^  lectrueNumComboBox;
		System::Windows::Forms::Label^  lectureNumberlbl;
		System::Windows::Forms::Label^  chosenLecturelbl;
		System::Windows::Forms::Button^  button1;
		System::ComponentModel::Container ^components;
	    static System::Windows::Forms::RichTextBox^  richTextBox1;
        System::Windows::Forms::Label^  label1;

#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			this->lectrueNumComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->lectureNumberlbl = (gcnew System::Windows::Forms::Label());
			this->chosenLecturelbl = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
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
			this->button1->Location = System::Drawing::Point(259, 246);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(208, 38);
			this->button1->TabIndex = 3;
			this->button1->Text = L"View Attendance Statistics";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Main_Screen::button1_Click);
			// 
			// richTextBox1
			// 
			this->richTextBox1->Location = System::Drawing::Point(12, 144);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->ReadOnly = true;
			this->richTextBox1->Size = System::Drawing::Size(239, 140);
			this->richTextBox1->TabIndex = 4;
			this->richTextBox1->Text = L"";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 119);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(98, 13);
			this->label1->TabIndex = 5;
			this->label1->Text = L"System Action Log:";
			// 
			// Main_Screen
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(479, 296);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->richTextBox1);
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
		//This method executes when timer has reached 10 minutes
		myTimer->Stop();						//Stop the timer

		richTextBox1->Text += "\nTaking out picture number " + quarter;
		captureImage();							//Call the captureImage function

		if (quarter > 4){
			richTextBox1->Text += "\nAttendance for lecture number "+lectureNumber+" complete.";
			myTimer->Stop();
			myTimer->Enabled = false;			//If all four quaters are captured, do not restart the timer
		}
		else{
			myTimer->Enabled = true;			//Restart the timer for another 10 minutes
		}
	}

	private: System::Void lectrueNumComboBox_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
		//this method runs when the lecture number is chosen from the combo box

		constring = L"datasource=localhost; port=3306; username=root; password=password@0105";
		lectureNumber = Convert::ToInt32(this->lectrueNumComboBox->SelectedItem::get());		//Stores the lecture number

		conDataBase1 = gcnew MySqlConnection(constring);
		MySqlCommand^ cmdDataBase1 = gcnew MySqlCommand("select lecture"+lectureNumber+" from studentattendancedb.studentattendancetbl;", conDataBase1);

		try{
			conDataBase1->Open();
			myReader1 = cmdDataBase1->ExecuteReader();
			myReader1->Read();
			
			if (myReader1->GetString("Lecture" + lectureNumber) != "unknown")
			{
				MessageBox::Show("Lecture "+lectureNumber+" contains data. Please choose another lecture.");
				//If the attendance for this lecture has already been taken, display error message and wait for another slelection
			}
			else{
				richTextBox1->Text += "\nLecture number : " + lectureNumber + " chosen.";
				chosenLecturelbl->Text = "Lecture number : " + lectureNumber + " chosen.";
				lectrueNumComboBox->Visible = false;				//Disable the combo box so the lecture number cannot be altered
				lectrueNumComboBox->Enabled = false;

				conDataBase = gcnew MySqlConnection(constring);
				std::string sql1 = "UPDATE `studentattendancedb`.`studentattendancetbl` SET `quarter1`= 'absent' ,`quarter2`= 'absent',`quarter3`= 'absent',`quarter4`= 'absent' WHERE `studentID` > '0' ;";
				System::String^ sql2 = gcnew System::String(sql1.c_str());
				MySqlCommand^ cmdDataBase = gcnew MySqlCommand(sql2, conDataBase);
				try{
					conDataBase->Open();
					myReader = cmdDataBase->ExecuteReader();				//Marks all the quarters as absent for every student 
					richTextBox1->Text += "\nDatabase initialized.";
				}
				catch (System::Exception^ ex){
					MessageBox::Show(ex->Message);
				}
				conDataBase->Close();

				captureImage();												//Captures the image for quarter 1 
				myTimer->Tick += gcnew EventHandler(TimerEventProcessor);
				myTimer->Interval = 2000;									// Sets the timer interval to 10 minutes.
				myTimer->Start();											//Starts the timer
			}
		}
		catch (System::Exception^ ex){

			MessageBox::Show(ex->Message);
		}
		conDataBase1->Close();
	}

			 void static setAttendence(int stid, int y){

		 std::string qtr;				//Used to alter the SQL
				 if (y == 1)
					 qtr = "quarter1";
				 else if (y == 2)
					 qtr = "quarter2";
				 else if (y == 3)
					 qtr = "quarter3";
				 else
					 qtr = "quarter4";

		 //Marks student present for quarter defined by y

				 constring = L"datasource=localhost; port=3306; username=root; password=password@0105";
				 conDataBase = gcnew MySqlConnection(constring);
				 std::string sql1 = "UPDATE `studentattendancedb`.`studentattendancetbl` SET `" + qtr + "`= 'present' WHERE `studentID`= " + std::to_string(stid) + ";";
				 System::String^ sql2 = gcnew System::String(sql1.c_str());
				 MySqlCommand^ cmdDataBase = gcnew MySqlCommand(sql2, conDataBase);

				 try{
					 conDataBase->Open();
					 myReader = cmdDataBase->ExecuteReader();
			 while (myReader->Read()){
					 }
				 }
				 catch (System::Exception^ ex){
					 MessageBox::Show(ex->Message);
				 }
				 conDataBase->Close();
			 }

			 static void captureImage()
			 {
		Mat capturedImage;					//Stores the captured image
		 vector<Mat> faces;					//Stores the images used for comparisons
		 vector<int> ids;					//Stores the IDs of the images

		 read_csv("C:/Class_Attendance_System_Files/csv_file.csv", faces, ids);		//Fills the faces and ids vectors

		 int im_width = faces[0].cols;		//Gets width and height of the images used for comparisons
				 int im_height = faces[0].rows;

				 Ptr<FaceRecognizer> model = createFisherFaceRecognizer();
		 model->train(faces, ids);			//Creates a face recognizer, trains it with the images used for comparisons

		 CascadeClassifier haar_cascade;		//Chooses haar-cascade that is used for face detection
				 haar_cascade.load("C:/Class_Attendance_System_Files/haarcascade_frontalface_default.xml");

		 VideoCapture cap;						//Opens a video feed
				 cap.open(0);

				 if (!cap.isOpened())
				 {
					 MessageBox::Show("ERROR: Could not open camera.");
				 }

		 cap >> capturedImage;						//Captures an image and stores in the captruedImage

		 Mat original = capturedImage.clone();		//Keeps a copy of the original image
				 Mat greyImage;
		 cvtColor(capturedImage, greyImage, CV_BGR2GRAY);		//Converts the image to greyscale

				 vector<Rect_<int>> facePositions;
		 haar_cascade.detectMultiScale(greyImage, facePositions);		//Gets the positions of the deteced faces from the image

				 for (int i = 0; i < facePositions.size(); i++)
				 {
			 Rect face_i = facePositions[i];						//Position of the ith face
			 Mat getFace = greyImage(face_i);						//Converts to greyscale
			 Mat face_resized;										//Resizes the detected face 
					 cv::resize(getFace, face_resized, cv::Size(im_width, im_height), 1.0, 1.0, INTER_CUBIC);
			 int foundID = model->predict(face_resized);			//Gets predicition from face recognizer
			 setAttendence(foundID, quarter);						//Calls the setAttendance method. Sends the recognized ID as a parameter

			 rectangle(original, face_i, CV_RGB(0, 255, 0), 1);		//Places rectangle over detected face and ID of the recognized faces
					 string box_text = format("ID = %d", foundID);
					 int pos_x = std::max(face_i.tl().x - 10, 0);
					 int pos_y = std::max(face_i.tl().y - 10, 0);
					 putText(original, box_text, cv::Point(pos_x, pos_y), FONT_HERSHEY_PLAIN, 1.0, CV_RGB(0, 255, 0), 2.0);///////
				 }

		 imshow("face_recognizer", original);						//Shows original image with recognized faces and their IDs

		 if (quarter == 4)								//This is executed after all four quarters have been captured
				 {
			 std::string sql1 = "SELECT * FROM `studentattendancedb`.`studentattendancetbl`;";		//Reads details of every student
					 System::String^ sql2 = gcnew System::String(sql1.c_str());
					 MySqlCommand^ cmdDataBase = gcnew MySqlCommand(sql2, conDataBase);

					 try{
						 conDataBase->Open();
						 myReader = cmdDataBase->ExecuteReader();
				 richTextBox1->Text += "\nSetting final attendance.";
				 while (myReader->Read())									//Loop runs for every student
						 {
					 quarter1 = myReader->GetString("quarter1");			//Gets the required data
							 quarter2 = myReader->GetString("quarter2");
							 quarter3 = myReader->GetString("quarter3");
							 quarter4 = myReader->GetString("quarter4");
							 int stID = myReader->GetInt32("studentID");
							 int i = 0;

							 if (quarter1 == "present")
								 i = i + 1;
							 if (quarter2 == "present")
								 i = i + 1;
							 if (quarter3 == "present")
								 i = i + 1;
							 if (quarter4 == "present")
								 i = i + 1;

					 if (i == 4 || (quarter1 == "present" && quarter4 == "present"))		//Conditions for present
							 {
								 constring = L"datasource=localhost; port=3306; username=root; password=password@0105";
								 conDataBase2 = gcnew MySqlConnection(constring);
								 std::string sql1 = "UPDATE `studentattendancedb`.`studentattendancetbl` SET `lecture" + std::to_string(lectureNumber) + "`= 'present' WHERE `studentID` = '"+std::to_string(stID)+"';";
								 System::String^ sql2 = gcnew System::String(sql1.c_str());
								 MySqlCommand^ cmdDataBase1 = gcnew MySqlCommand(sql2, conDataBase2);
								 conDataBase2->Open();
								 myReader2 = cmdDataBase1->ExecuteReader();
						 richTextBox1->Text += "\nMarking "+ stID + " as Present.";
								 conDataBase2->Close();
							 }
					 else if ((i == 2 || i == 3) && quarter1 != "present")					//Conditions for 'Came late'
							 {
								 constring = L"datasource=localhost; port=3306; username=root; password=password@0105";
								 conDataBase2 = gcnew MySqlConnection(constring);
								 std::string sql1 = "UPDATE `studentattendancedb`.`studentattendancetbl` SET `lecture" + std::to_string(lectureNumber) + "`= 'came late' WHERE `studentID` = '" + std::to_string(stID) + "';";
								 System::String^ sql2 = gcnew System::String(sql1.c_str());
								 MySqlCommand^ cmdDataBase1 = gcnew MySqlCommand(sql2, conDataBase2);
								 conDataBase2->Open();
								 myReader2 = cmdDataBase1->ExecuteReader();
						 richTextBox1->Text += "\nMarking " + stID + " as Came late.";
								 conDataBase2->Close();
							 }
					 else if (i == 2 || i == 3 && quarter4 != "present")					//Conditions for 'Left early'
							 {
								 constring = L"datasource=localhost; port=3306; username=root; password=password@0105";
								 conDataBase2 = gcnew MySqlConnection(constring);
								 std::string sql1 = "UPDATE `studentattendancedb`.`studentattendancetbl` SET `lecture" + std::to_string(lectureNumber) + "`= 'left early' WHERE `studentID` = '" + std::to_string(stID) + "';";
								 System::String^ sql2 = gcnew System::String(sql1.c_str());
								 MySqlCommand^ cmdDataBase1 = gcnew MySqlCommand(sql2, conDataBase2);
								 conDataBase2->Open();
								 myReader2 = cmdDataBase1->ExecuteReader();
						 richTextBox1->Text += "\nMarking " + stID + " as Left early.";
								 conDataBase2->Close();
							 }
							 else
					 {																		//mark stduent absent
								 constring = L"datasource=localhost; port=3306; username=root; password=password@0105";
								 conDataBase2 = gcnew MySqlConnection(constring);
								 std::string sql1 = "UPDATE `studentattendancedb`.`studentattendancetbl` SET `lecture" + std::to_string(lectureNumber) + "`= 'absent' WHERE `studentID` = '" + std::to_string(stID) + "';";
								 System::String^ sql2 = gcnew System::String(sql1.c_str());
								 MySqlCommand^ cmdDataBase1 = gcnew MySqlCommand(sql2, conDataBase2);
								 conDataBase2->Open();
								 myReader2 = cmdDataBase1->ExecuteReader();
						 richTextBox1->Text += "\nMarking " + stID + " as Absent.";
								 conDataBase2->Close();
							 }
						 }
					 }
					 catch (System::Exception^ ex){
						 MessageBox::Show(ex->Message);
					 }
					 conDataBase->Close();
				 }
		 quarter++;				//move to next quarter
			 }

			 static void read_csv(const string& filepath, vector<Mat>& images, vector<int>& labels)
			 {
				 std::ifstream file(filepath.c_str(), ifstream::in);
				 if (!file)
				 {
					 MessageBox::Show("ERROR: Could not read CSV file.");
				 }
				 string line, path, classlabel;
		 while (getline(file, line))					//Loop runs for every line of the CSV file
				 {
					 stringstream liness(line);
			 getline(liness, path, ';');				//Delimiter seperates data
					 getline(liness, classlabel);
					 if (!path.empty() && !classlabel.empty())
					 {
				 images.push_back(imread(path, 0));				//Stores image in vector
				 labels.push_back(atoi(classlabel.c_str()));	//Stores ID in vector
					 }
				 }
			 }

	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		Attendance_Stats_Screen^ ass = gcnew Attendance_Stats_Screen();				//Displays the attendance stats screen
		ass->ShowDialog();
	}
};
}
