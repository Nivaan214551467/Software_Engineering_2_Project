#pragma once

namespace Group4_Class_Attendance_System {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Main_Screen
	/// </summary>
	public ref class Main_Screen : public System::Windows::Forms::Form
	{
	public:
		Main_Screen(void)
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
		~Main_Screen()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:

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
			// Main_Screen
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(564, 339);
			this->Name = L"Main_Screen";
			this->Text = L"Main_Screen";
			this->Load += gcnew System::EventHandler(this, &Main_Screen::Main_Screen_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Main_Screen_Load(System::Object^  sender, System::EventArgs^  e) {
	}
	};
}
