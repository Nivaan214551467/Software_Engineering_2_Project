#pragma once
#include <opencv\cv.h>
#include <opencv\highgui.h>

using namespace cv;

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

	public:
	private:
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			this->lectrueNumComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->lectureNumberlbl = (gcnew System::Windows::Forms::Label());
			this->chosenLecturelbl = (gcnew System::Windows::Forms::Label());
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
			// Main_Screen
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(578, 218);
			this->Controls->Add(this->chosenLecturelbl);
			this->Controls->Add(this->lectureNumberlbl);
			this->Controls->Add(this->lectrueNumComboBox);
			this->Name = L"Main_Screen";
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
	 
		myTimer->Enabled = true;
	 }

	 static void captureImage()
	 {
		 Mat capturedImage;
		 vector<Mat> faces;

		 VideoCapture cap;
		 cap.open(0);
		 
		 if (!cap.isOpened())
		 {
			 MessageBox::Show("Error. Could not open camera.");
		 }
		 /*
		 namedWindow("window", 1);

		 cap >> capturedImage;
		 imshow("window", capturedImage);
		 */
		 quater++;
	 }



	private: System::Void lectrueNumComboBox_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
		
		lectureNumber = Convert::ToInt32(this->lectrueNumComboBox->SelectedItem::get());
		//MessageBox::Show("Lecture number : " + lectureNumber + " chosen.");
		chosenLecturelbl->Text = "Lecture number : " + lectureNumber + " chosen.";
		lectrueNumComboBox->Visible = false;

		myTimer->Tick += gcnew EventHandler(TimerEventProcessor);
		myTimer->Interval = 6000;					// Sets the timer interval to 10 minutes.
		myTimer->Start();
		
	}
};
}
