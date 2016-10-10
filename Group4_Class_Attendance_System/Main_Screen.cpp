#include "Main_Screen.h"

using namespace System; 
using namespace System::Windows::Forms;   

[STAThread] void Main()			//opens the Main_Screen GUI
{ 
	Application::EnableVisualStyles(); 
	Application::SetCompatibleTextRenderingDefault(false);  
	Group4_Class_Attendance_System::Main_Screen form;
	Application::Run(%form); 
}




