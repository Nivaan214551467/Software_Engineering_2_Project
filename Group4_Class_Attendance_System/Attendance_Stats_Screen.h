#pragma once
#include <opencv\cv.h>
#include <opencv\highgui.h>
#include <opencv2\core.hpp>
#include <opencv2\contrib\contrib.hpp>
#include <opencv2\highgui.hpp>
#include <opencv2\imgproc.hpp>				// including all required libraries and header files
#include <opencv2\objdetect.hpp>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iostream> 
#include <string>
#include<iostream>

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
	
	
	
	

	/// <summary>
	/// Summary for Attendance_Stats_Screen
	/// </summary>
	public ref class Attendance_Stats_Screen : public System::Windows::Forms::Form
	{
	public:
		Attendance_Stats_Screen(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Attendance_Stats_Screen()
		{
			if (components)
			{
				delete components;
			}
		}

	public:
		System::String^ constring; // connection string variable to connect to database
		MySqlConnection^ conDataBase; // connection variable to create database connection

		MySqlDataReader^ myReader; // reader variable to read from database
		static System::String^ studentName; // stores student's name
		static System::String^ studentSurname; // stores student's surname
		static int studentID = 0; // stores student number
		static int NoOfDaysPresent = 0; // stores number of days present
		static int NoOfDaysAbsent = 0; // stores number of days absent
		static int NoOfDaysCameLate = 0; // stores number of days late
		static int NoOfDaysLeftEarly = 0; // stores number of days left early

	private: System::Windows::Forms::TextBox^  srchtextBox;
	protected:

	private: System::Windows::Forms::Button^  searchBtn;
	protected:

	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::TextBox^  nametextBox;
	private: System::Windows::Forms::TextBox^  snametextBox;


	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::TextBox^  prtextBox;
	private: System::Windows::Forms::TextBox^  latetextBox;


	private: System::Windows::Forms::TextBox^  abtextBox;
	private: System::Windows::Forms::TextBox^  earlytextBox;
	private: System::Windows::Forms::Button^  button1;




	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->srchtextBox = (gcnew System::Windows::Forms::TextBox());
			this->searchBtn = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->nametextBox = (gcnew System::Windows::Forms::TextBox());
			this->snametextBox = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->prtextBox = (gcnew System::Windows::Forms::TextBox());
			this->latetextBox = (gcnew System::Windows::Forms::TextBox());
			this->abtextBox = (gcnew System::Windows::Forms::TextBox());
			this->earlytextBox = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// srchtextBox
			// 
			this->srchtextBox->Location = System::Drawing::Point(122, 31);
			this->srchtextBox->Name = L"srchtextBox";
			this->srchtextBox->Size = System::Drawing::Size(132, 20);
			this->srchtextBox->TabIndex = 0;
			// 
			// searchBtn
			// 
			this->searchBtn->Location = System::Drawing::Point(179, 57);
			this->searchBtn->Name = L"searchBtn";
			this->searchBtn->Size = System::Drawing::Size(75, 23);
			this->searchBtn->TabIndex = 1;
			this->searchBtn->Text = L"Search";
			this->searchBtn->UseVisualStyleBackColor = true;
			this->searchBtn->Click += gcnew System::EventHandler(this, &Attendance_Stats_Screen::searchBtn_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(24, 34);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(92, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Enter Student No.";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(24, 110);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(38, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Name:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(24, 136);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(52, 13);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Surname:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(24, 162);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(67, 13);
			this->label4->TabIndex = 5;
			this->label4->Text = L"Student No.:";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(24, 188);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(73, 13);
			this->label5->TabIndex = 6;
			this->label5->Text = L"Days Present:";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(24, 214);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(70, 13);
			this->label6->TabIndex = 7;
			this->label6->Text = L"Days Absent:";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(24, 240);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(58, 13);
			this->label7->TabIndex = 8;
			this->label7->Text = L"Days Late:";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(24, 266);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(76, 13);
			this->label8->TabIndex = 9;
			this->label8->Text = L"Days left early:";
			// 
			// nametextBox
			// 
			this->nametextBox->Location = System::Drawing::Point(122, 107);
			this->nametextBox->Name = L"nametextBox";
			this->nametextBox->ReadOnly = true;
			this->nametextBox->Size = System::Drawing::Size(132, 20);
			this->nametextBox->TabIndex = 10;
			// 
			// snametextBox
			// 
			this->snametextBox->Location = System::Drawing::Point(122, 133);
			this->snametextBox->Name = L"snametextBox";
			this->snametextBox->ReadOnly = true;
			this->snametextBox->Size = System::Drawing::Size(132, 20);
			this->snametextBox->TabIndex = 11;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(122, 159);
			this->textBox3->Name = L"textBox3";
			this->textBox3->ReadOnly = true;
			this->textBox3->Size = System::Drawing::Size(132, 20);
			this->textBox3->TabIndex = 12;
			// 
			// prtextBox
			// 
			this->prtextBox->Location = System::Drawing::Point(122, 185);
			this->prtextBox->Name = L"prtextBox";
			this->prtextBox->ReadOnly = true;
			this->prtextBox->Size = System::Drawing::Size(52, 20);
			this->prtextBox->TabIndex = 13;
			// 
			// latetextBox
			// 
			this->latetextBox->Location = System::Drawing::Point(122, 237);
			this->latetextBox->Name = L"latetextBox";
			this->latetextBox->ReadOnly = true;
			this->latetextBox->Size = System::Drawing::Size(52, 20);
			this->latetextBox->TabIndex = 14;
			// 
			// abtextBox
			// 
			this->abtextBox->Location = System::Drawing::Point(122, 211);
			this->abtextBox->Name = L"abtextBox";
			this->abtextBox->ReadOnly = true;
			this->abtextBox->Size = System::Drawing::Size(52, 20);
			this->abtextBox->TabIndex = 15;
			// 
			// earlytextBox
			// 
			this->earlytextBox->Location = System::Drawing::Point(122, 263);
			this->earlytextBox->Name = L"earlytextBox";
			this->earlytextBox->ReadOnly = true;
			this->earlytextBox->Size = System::Drawing::Size(52, 20);
			this->earlytextBox->TabIndex = 16;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(195, 279);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 17;
			this->button1->Text = L"Close";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Attendance_Stats_Screen::button1_Click);
			// 
			// Attendance_Stats_Screen
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(282, 314);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->earlytextBox);
			this->Controls->Add(this->abtextBox);
			this->Controls->Add(this->latetextBox);
			this->Controls->Add(this->prtextBox);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->snametextBox);
			this->Controls->Add(this->nametextBox);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->searchBtn);
			this->Controls->Add(this->srchtextBox);
			this->Name = L"Attendance_Stats_Screen";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Attendance Statistics";
			this->Load += gcnew System::EventHandler(this, &Attendance_Stats_Screen::Attendance_Stats_Screen_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


	private: System::Void Attendance_Stats_Screen_Load(System::Object^  sender, System::EventArgs^  e) {
		constring = L"datasource=localhost; port=3306; username=root; password=password@0105"; // connection string to connect to database
		conDataBase = gcnew MySqlConnection(constring); // creates new connection
	}
			

	private: System::Void searchBtn_Click(System::Object^  sender, System::EventArgs^  e) {

		studentID = Int32::Parse(srchtextBox->Text); // gets the student number entered by the user in the text box and converts it to an integer
		getData(studentID); // function to get data
		displayData(); // function to display data
	}
			 void getData(int stdNo){
				 MySqlCommand^ cmdDataBase = gcnew MySqlCommand("select * from studentattendancedb.studentattendancetbl where studentID = '" + stdNo + "';", conDataBase); // SQL statement to obtain information from database
				 try{
					 conDataBase->Close(); // closes connection to database
					 conDataBase->Open(); // opens connection to database
					 myReader = cmdDataBase->ExecuteReader(); // runs the reader to read from database

					 while (myReader->Read()) // reads data from database while there is still information to be read
					 {
						 for (int i = 1; i <= 25; i++)
						 {

							 if (myReader->GetString("Lecture" + i) == "absent")
							 {
								 NoOfDaysAbsent++; // counts the number of days absent
							 }
							 else if (myReader->GetString("Lecture" + i) == "present")
							 {
								 NoOfDaysPresent++; // counts the number of days present
							 }
							 else if (myReader->GetString("Lecture" + i) == "came late")
							 {
								 NoOfDaysCameLate++; // counts the number of days arrived late 
							 }
							 else if (myReader->GetString("Lecture" + i) == "left early")
							 {
								 NoOfDaysLeftEarly++; // counts the number of days left early
							 }
						 }
						 studentID = myReader->GetInt32("StudentID"); // reads the student number from database and converts it to an integer
						 studentName = myReader->GetString("Name"); // reads student's name from the database
						 studentSurname = myReader->GetString("Surname"); //reads student's surname from the database
					 }

					 
					 
				 }
				 catch (System::Exception^ ex){

					MessageBox::Show(ex->Message);
				 }

			 }
			 void displayData(){
				 textBox3->Text = Convert::ToString(studentID); // converts student number from integer to string and displays it in the text box
				 nametextBox->Text = studentName; // displays student's name in textbox
				 snametextBox->Text = studentSurname;// displays student's surname in textbox
				 abtextBox->Text = Convert::ToString(NoOfDaysAbsent); // converts number of days absent from integer to string and displays it in the text box
				 prtextBox->Text = Convert::ToString(NoOfDaysPresent); // converts number of days present from integer to string and displays it in the text box
				 latetextBox->Text = Convert::ToString(NoOfDaysCameLate); // converts number of days came late from integer to string and displays it in the text box
				 earlytextBox->Text = Convert::ToString(NoOfDaysLeftEarly); // converts number of days left early from integer to string and displays it in the text box

				 NoOfDaysPresent = 0;  
				 NoOfDaysAbsent = 0;					// resets all counts for next display
				 NoOfDaysCameLate = 0;
				 NoOfDaysLeftEarly = 0;
			 }
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
	this->Close(); // closes attendance stats screen
}
};
}
