#pragma once

namespace Group4_Class_Attendance_System {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

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
			this->SuspendLayout();
			// 
			// Attendance_Stats_Screen
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(323, 272);
			this->Name = L"Attendance_Stats_Screen";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Attendance_Stats_Screen";
			this->Load += gcnew System::EventHandler(this, &Attendance_Stats_Screen::Attendance_Stats_Screen_Load);
			this->ResumeLayout(false);

		}
#pragma endregion


	private: System::Void Attendance_Stats_Screen_Load(System::Object^  sender, System::EventArgs^  e) {
		//This method will run when screen is loaded so put connection to DB here

		//Make a textbox and button. User will enter student number in the textbox. When button pressed, read the student 
		//number from the textbox and get data for that student from DB. So put the other code in the "button pressed" method.
	}
	};
}
