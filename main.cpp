#include <iostream>
#include "api/KeyAuth.hpp"
#include "xorstr.hpp"
#include <tlhelp32.h>
#include <fstream>
#include <filesystem>
#include "mapper/kdmapper.hpp"
#include <fileapi.h>
#include <iomanip> 
#include "Spoofer/Spoofer.h"
#include "Util.h"
//#define DISABLE_OUTPUT
using namespace std;
using namespace KeyAuth;
void safe();
void notSafe();
void me();

std::string name = XorStr("EclipsedSpoofer"); // application name. right above the blurred text aka the secret on the licenses tab among other tabs
std::string ownerid = XorStr("UydZJ0nYcE"); // ownerid, found in account settings. click your profile picture on top right of dashboard and then account settings.
std::string secret = XorStr("538573134cf21326d435aa017447098c0aacf29028e3bcf23868c35e6d62c072"); // app secret, the blurred text on licenses tab and other tabs
std::string version = XorStr("1.0"); // leave alone unless you've changed version on website

api KeyAuthApp(name, ownerid, secret, version);
void SpoofMAC() {
	Util::WriteLine("Old MAC Address(es):");
	system(XorStr("GETMAC /V").c_str());
	notSafe();
	std::vector<std::uint8_t> bytes = KeyAuthApp.download(XorStr("659292")); // spufer driv
	safe();
	HANDLE iqvw64e_device_handle = intel_driver::Load();

	if (!iqvw64e_device_handle || iqvw64e_device_handle == INVALID_HANDLE_VALUE) {
		std::cout << XorStr("\n Error code iq00001, please disable any anti-cheat such as valorant or faceit and try again");
		Sleep(3500);
		exit(0);
	}
	if (!kdmapper::MapDriver(iqvw64e_device_handle, bytes.data())) {
		Util::WriteLine(XorStr("\nCould not load driver"));
		std::cout << XorStr("\n Error code iq00002, please disable any anti-cheat such as valorant or faceit and try again");
		intel_driver::Unload(iqvw64e_device_handle);
		Sleep(3500);
		exit(0);
	}
	intel_driver::Unload(iqvw64e_device_handle);
	Sleep(3000);
	Util::WriteLine("New MAC Address(es):");
	system(XorStr("GETMAC /V").c_str());
	Util::SetColor(YELLOW);
	Util::WriteLine(XorStr("Press any key to go back to the menu"));
	system(XorStr("Pause >nul").c_str());
}
void SpoofMenu() {
	VM_FISH_BLACK_START
		int option;
	std::vector<std::uint8_t> bytes;
	HANDLE iqvw64e_device_handle;
	std::ofstream SpooferCustom(XorStr("C:\\Windows\\Spoofer - CustomSerial.tmp").c_str());
	HOWSTUPIDAREYOUBRUH:
	Util::Clear();
	Util::Logo();

	Util::SetColor(CYAN);
	Util::WriteLine(XorStr("\n                              =================================================================\n"), 1);
	std::cout << std::endl;
	Util::SetColor(LIGHTBLUE);
	Util::WriteLine(XorStr("[1] Randomize Serials\n"));
	Util::WriteLine(XorStr("[2] NULL Serials\n"));
	Util::WriteLine(XorStr("[3] Custom Serials\n"));
	Util::SetColor(CYAN);
	Util::WriteLine(XorStr("\n                              =================================================================\n"), 1);
	Util::SetColor(LIGHTBLUE);
	Util::WriteLine("Please choose an selection: ");
	Util::SetColor(LIGHTBLUE);
	std::cin >> option;
	std::string YN;
	if (option == 1) {
		Util::WriteLine(XorStr("[BETA] Would you like to spoof Volume ID? (Y/N): "));
		std::cin >> YN;
		std::transform(YN.begin(), YN.end(), YN.begin(), ::toupper);
		if (YN == "Y") {
			Spoof();
		}
		else {
			Util::WriteLine(XorStr("Skipping Volume ID Spoof"));
			std::cout << std::endl;
		}
		Util::SetColor(CYAN);
		Util::WriteLine(XorStr("Old Disk Serial Number(s):"));
		std::cout << std::endl;
		system(XorStr("wmic path win32_physicalmedia get SerialNumber\n").c_str());
		SpooferCustom << Util::GenRandomString(40);
		SpooferCustom.close();
		notSafe();
	    bytes = KeyAuthApp.download(XorStr("455613")); // spufer driv
		safe();
	    iqvw64e_device_handle = intel_driver::Load();

		if (!iqvw64e_device_handle || iqvw64e_device_handle == INVALID_HANDLE_VALUE) {
			std::cout << XorStr("\n Error code iq00001, please disable any anti-cheat such as valorant or faceit and try again");
			Sleep(3500);
			exit(0);
		}
		if (!kdmapper::MapDriver(iqvw64e_device_handle, bytes.data())) {
			Util::WriteLine(XorStr("\nCould not load driver"));
			std::cout << XorStr("\n Error code iq00002, please disable any anti-cheat such as valorant or faceit and try again");
			intel_driver::Unload(iqvw64e_device_handle);
			Sleep(3500);
			exit(0);
		}		
		Util::SetColor(CYAN);
		Util::WriteLine(XorStr("New Disk Serial Number(s):"));
		std::cout << std::endl;
		system(XorStr("wmic path win32_physicalmedia get SerialNumber\n").c_str());
		intel_driver::Unload(iqvw64e_device_handle);
		system(XorStr("powershell -command \"Reset-PhysicalDisk *\" --quiet --no-verbose >$null 2>&1").c_str());
		system(XorStr("net stop winmgmt /Y >nul").c_str());
		Util::SetColor(GREEN);
		std::cout << std::endl << std::endl;
		Util::WriteLine(XorStr("Success!"));
		std::cout << std::endl;
		Util::SetColor(YELLOW);
		Util::WriteLine(XorStr("Press any key to go back to the menu"));
		system(XorStr("Pause >nul").c_str());
	}
	else if (option == 2) {
		Util::WriteLine(XorStr("[BETA] Would you like to spoof Volume ID? (Y/N): "));
		std::cin >> YN;
		std::transform(YN.begin(), YN.end(), YN.begin(), ::toupper);
		if (YN == "Y") {
			Spoof();
		}
		else {
			Util::WriteLine(XorStr("Skipping Volume ID Spoof"));
			std::cout << std::endl;
		}
		Util::WriteLine(XorStr("Old Disk Serial Number(s):"));
		std::cout << std::endl;
		system(XorStr("wmic path win32_physicalmedia get SerialNumber\n").c_str());
		SpooferCustom << " ";
		SpooferCustom.close();
		notSafe();
		bytes = KeyAuthApp.download(XorStr("455613")); // spufer driv
		safe();
		iqvw64e_device_handle = intel_driver::Load();

		if (!iqvw64e_device_handle || iqvw64e_device_handle == INVALID_HANDLE_VALUE) {
			std::cout << XorStr("\n Error code iq00001, please disable any anti-cheat such as valorant or faceit and try again");
			Sleep(3500);
			exit(0);
		}
		if (!kdmapper::MapDriver(iqvw64e_device_handle, bytes.data())) {
			Util::WriteLine(XorStr("\nCould not load driver"));
			std::cout << XorStr("\n Error code iq00002, please disable any anti-cheat such as valorant or faceit and try again");
			intel_driver::Unload(iqvw64e_device_handle);
			Sleep(3500);
			exit(0);
		}	
		Util::SetColor(CYAN);
		Util::WriteLine(XorStr("New Disk Serial Number(s):"));
		std::cout << std::endl;
		system(XorStr("wmic path win32_physicalmedia get SerialNumber\n").c_str());
		intel_driver::Unload(iqvw64e_device_handle);
		system(XorStr("powershell -command \"Reset-PhysicalDisk *\" --quiet --no-verbose >$null 2>&1").c_str());
		system(XorStr("net stop winmgmt /Y >nul").c_str());
		Util::SetColor(GREEN);
		std::cout << std::endl << std::endl;
		Util::WriteLine(XorStr("Success!"));
		std::cout << std::endl;
		Util::SetColor(YELLOW);
		Util::WriteLine(XorStr("Press any key to go back to the menu"));
		system(XorStr("Pause >nul").c_str());
	}
	else if (option == 3) {
		Util::WriteLine(XorStr("[BETA] Would you like to spoof Volume ID? (Y/N): "));
		std::cin >> YN;
		std::transform(YN.begin(), YN.end(), YN.begin(), ::toupper);
		if (YN == "Y") {
			Spoof();
		}
		else {
			Util::WriteLine(XorStr("Skipping Volume ID Spoof"));
			std::cout << std::endl;
		}
		Util::WriteLine("Enter Wanted HWID:");
		std::string ay;
		std::cin >> ay;
		SpooferCustom << ay;
		SpooferCustom.close();
		Util::WriteLine(XorStr("Old Disk Serial Number(s):"));
		std::cout << std::endl;
		system(XorStr("wmic path win32_physicalmedia get SerialNumber\n").c_str());
		notSafe();
		bytes = KeyAuthApp.download(XorStr("455613")); // spufer driv
		safe();
	    iqvw64e_device_handle = intel_driver::Load();

		if (!iqvw64e_device_handle || iqvw64e_device_handle == INVALID_HANDLE_VALUE) {
			std::cout << XorStr("\n Error code iq00001, please disable any anti-cheat such as valorant or faceit and try again");
			Sleep(3500);
			exit(0);
		}
		if (!kdmapper::MapDriver(iqvw64e_device_handle, bytes.data())) {
			Util::WriteLine(XorStr("\nCould not load driver"));
			std::cout << XorStr("\n Error code iq00002, please disable any anti-cheat such as valorant or faceit and try again");
			intel_driver::Unload(iqvw64e_device_handle);
			Sleep(3500);
			exit(0);
		}
		Util::SetColor(CYAN);
		Util::WriteLine(XorStr("New Disk Serial Number(s):"));
		std::cout << std::endl;
		system(XorStr("wmic path win32_physicalmedia get SerialNumber\n").c_str());
		intel_driver::Unload(iqvw64e_device_handle);
		system(XorStr("powershell -command \"Reset-PhysicalDisk *\" --quiet --no-verbose >$null 2>&1").c_str());
		system(XorStr("net stop winmgmt /Y >nul").c_str());
		Util::SetColor(GREEN);
		std::cout << std::endl << std::endl;
		Util::WriteLine(XorStr("Success!"));
		std::cout << std::endl;
		Util::SetColor(YELLOW);
		Util::WriteLine(XorStr("Press any key to go back to the menu"));
		system(XorStr("Pause >nul").c_str());
	}
	else {
	goto HOWSTUPIDAREYOUBRUH;
}
VM_FISH_BLACK_END
	
}
void Helper() {
	Util::Clear();
	Util::Logo();
	Util::SetColor(CYAN);
	Util::WriteLine(XorStr("\n                              =================================================================\n"), 1);
	std::cout << std::endl;
	Util::SetColor(LIGHTBLUE);
	Util::WriteLine(XorStr("[1] Undetected Games\n"));
	Util::WriteLine(XorStr("[2] How to use\n"));
	Util::WriteLine(XorStr("[3] Terms of Service\n"));
	Util::WriteLine(XorStr("[0] Back to main menu\n"));
	Util::SetColor(CYAN);
	std::cout << std::endl;
	Util::WriteLine(XorStr("\n                              =================================================================\n"), 1);
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	Util::WriteLine("Please choose an selection: ");
	Util::SetColor(LIGHTBLUE);
	int sexo;
	std::cin >> sexo;
	if (sexo == 1) {
		Util::Clear();
		Util::WriteStatus("Dead by Daylight", Util::Undetected);
		Util::WriteStatus("Fortnite", Util::Undetected);
		Util::WriteStatus("Apex Legends", Util::Undetected);
		Util::WriteStatus("RUST", Util::Unknown);
		Util::WriteStatus("Rainbow Six Siege", Util::Detected);
		Util::WriteStatus("Among Us", Util::Undetected);
		Util::WriteStatus("CSGO", Util::Undetected);
		Util::WriteStatus("FACEIT", Util::Unknown);
		Util::WriteStatus("Friday the 13th", Util::Undetected);
		Util::WriteStatus("SCUM", Util::Undetected);

	}
	if (sexo == 2) {
		Util::WriteLine(XorStr("Recommended Steps for DBD: 2 > 3 ").c_str());
		Util::WriteLine(XorStr("\nRecommended Steps for More Protected Games (I.e RUST): 1 > 2 > Restart PC > 3 > 2 ").c_str());

	}
	if (sexo == 3) {
		Util::Clear();
		Util::WriteLine(XorStr(R"(
Add your TOS here..
)"), 0);
	}
	if (sexo == 0) {

	}
	std::cout << std::endl << std::endl;
	Util::SetColor(YELLOW);
	Util::WriteLine(XorStr("Press any key to go back to the menu"));
	system(XorStr("Pause >nul").c_str());
}
void Activate() {
	VM_FISH_RED_START
	Util::WriteLine(XorStr("[1] Home"));
	std::cout << std::endl;
	Util::WriteLine(XorStr("[2] Home N"));
	std::cout << std::endl;
	Util::WriteLine(XorStr("[3] Home Single Language"));
	std::cout << std::endl;
	Util::WriteLine(XorStr("[4] Home Country Specific"));
	std::cout << std::endl;
	Util::WriteLine(XorStr("[5] Professional"));
	std::cout << std::endl;
	Util::WriteLine(XorStr("[6] Professional N"));
	std::cout << std::endl;
	Util::WriteLine(XorStr("[7] Education"));
	std::cout << std::endl;
	Util::WriteLine(XorStr("[8] Education N"));
	std::cout << std::endl;
	Util::WriteLine(XorStr("[9] Enterprise"));
	std::cout << std::endl;
	Util::WriteLine(XorStr("[10] Enterprise "));
	std::cout << std::endl << std::endl;
	Util::WriteLine(XorStr("Choose Your Version: "));
	int WindowsKey;
	std::cin >> WindowsKey;


	if (WindowsKey < 0 || WindowsKey > 10) {
		exit(0);
	}

	std::string Home = "TX9XD-98N7V-6WMQ6-BX7FG-H8Q99",
		HomeN = "3KHY7-WNT83-DGQKR-F7HPR-844BM",
		HomeSL = "7HNRX-D7KGG-3K4RQ-4WPJ4-YTDFH",
		HomeCS = "PVMJN-6DFY6-9CCP6-7BKTT-D3WVR",
		Pro = "W269N-WFGWX-YVC9B-4J6C9-T83GX",
		ProN = "MH37W-N47XK-V7XM9-C7227-GCQG9",
		Edu = "NW6C2-QMPVW-D7KKK-3GKT6-VCFB2",
		EduN = "2WH4N-8QGBV-H22JP-CT43Q-MDWWJ",
		Ent = "NPPR9-FWDCX-D2C8J-H872K-2YT43",
		EntN = "DPH2V-TTNVB-4X9Q3-TJR4H-KHJW4",
		WindowsKeyChoice, WindowsName;

	switch (WindowsKey) {
	case 0: exit(0);
	case 1: WindowsKeyChoice = Home; WindowsName = "Home"; break;
	case 2: WindowsKeyChoice = HomeN; WindowsName = "Home N"; break;
	case 3: WindowsKeyChoice = HomeSL; WindowsName = "Home SL"; break;
	case 4: WindowsKeyChoice = HomeCS; WindowsName = "Home CS"; break;
	case 5: WindowsKeyChoice = Pro; WindowsName = "Pro"; break;
	case 6: WindowsKeyChoice = ProN; WindowsName = "Pro N"; break;
	case 7: WindowsKeyChoice = Edu; WindowsName = "Edu"; break;
	case 8: WindowsKeyChoice = EduN; WindowsName = "Edu N"; break;
	case 9: WindowsKeyChoice = Ent; WindowsName = "Ent"; break;
	case 10: WindowsKeyChoice = EntN; WindowsName = "Ent N"; break;
	default: exit(1); break;
	}

	system("cls");
	std::cout << XorStr("Activating Windows 10 ").c_str() << WindowsName << "\n\n";
	system(("slmgr /ipk " + WindowsKeyChoice).c_str());

	system(XorStr("runas /user:Administrator@domain slmgr /skms kms8.msguides.com").c_str());
	system(XorStr("slmgr /ato").c_str());
	Util::SetColor(GREEN);
	std::cout << std::endl << std::endl;
	Util::WriteLine(XorStr("Success!"));
	std::cout << std::endl;
	Util::SetColor(YELLOW);
	Util::WriteLine(XorStr("Press any key to go back to the menu"));
	system(XorStr("Pause >nul").c_str());
	VM_FISH_RED_END
}
int main(int argc, char** argv)
{
//	VM_DOLPHIN_BLACK_START
		char ownPth[MAX_PATH];

	// When NULL is passed to GetModuleHandle, the handle of the exe itself is returned
/*	HMODULE hModule = GetModuleHandle(NULL);

		GetModuleFileName(hModule, ownPth, (sizeof(ownPth)));


	//std::cout << fs::basepath(full_path) << std::endl;

	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO scrBufferInfo;
	GetConsoleScreenBufferInfo(hOut, &scrBufferInfo);
	short winWidth = scrBufferInfo.srWindow.Right - scrBufferInfo.srWindow.Left + 1;
	short winHeight = scrBufferInfo.srWindow.Bottom - scrBufferInfo.srWindow.Top + 1;
	short scrBufferWidth = scrBufferInfo.dwSize.X;
	short scrBufferHeight = scrBufferInfo.dwSize.Y;
	COORD newSize;
	newSize.X = scrBufferWidth;
	newSize.Y = winHeight;

	// set the new screen buffer dimensions
	int Status = SetConsoleScreenBufferSize(hOut, newSize);*/
#pragma region Variables
	std::string license;
#pragma endregion

	safe();
	SetConsoleTitleA(Util::GenRandomString(6969).c_str());
	Sleep(500);
#ifdef LOGS
	system("pause");
#endif // LOGS

	Util::SetColor(CYAN);
	Util::CoolLogo();
	Util::SetColor(YELLOW);
	Util::WriteLine(XorStr("\n\nConnecting.."), 25);
	notSafe();
	KeyAuthApp.init();
	Util::SetColor(GREEN);
	Util::WriteLine(" Success!", 30);

	if (KeyAuthApp.checkblack())
	{
		exit(0);
	}
	
	safe();
	LOGINLABEL: 
	Util::Clear();
	Util::SetColor(CYAN);
	Util::CoolLogo();
	if (std::filesystem::exists(XorStr("C:\\ProgramData\\Eclipsed\\Config.cfg").c_str())) {
		std::ifstream password_file(XorStr("C:\\ProgramData\\Eclipsed\\Config.cfg"), std::ios::in);
		std::getline(password_file, license);
		notSafe();
		Util::WriteLine(license);
		if (KeyAuthApp.license(encryption::decode(license))) {
			safe();
			goto LITERALLYTHECOOLESTTHINGEVER;
		}
		else {
			DeleteFileA(XorStr("C:\\ProgramData\\Eclipsed\\Config.cfg").c_str());
		}
		Sleep(4000);
		goto LOGINLABEL;

	}
	else {
		std::filesystem::create_directories(XorStr("C:\\ProgramData\\Eclipsed").c_str());
		Util::SetColor(LIGHTBLUE);
		Util::WriteLine("                     License: ");
		std::cin >> license;
		notSafe();
		if(KeyAuthApp.license(license)) {
			std::ofstream password_file2(XorStr("C:\\ProgramData\\Eclipsed\\Config.cfg").c_str());
			safe();
			password_file2 << encryption::encode(license);
			goto LITERALLYTHECOOLESTTHINGEVER;
		}
		else {
			DeleteFileA(XorStr("C:\\ProgramData\\Eclipsed\\Config.cfg").c_str());

		}
		Sleep(4000);
		goto LOGINLABEL;
	
	}
LITERALLYTHECOOLESTTHINGEVER:
	int option;
	Util::Clear();
	Util::SetColor(LIGHTBLUE);
	Util::CoolLogo();
	Util::WriteLine(XorStr("\nYour License Expires at: "));
	time_t rawtime = mktime(&KeyAuthApp.user_data.createdate);
	struct tm* timeinfo;
	timeinfo = localtime(&rawtime);
	rawtime = mktime(&KeyAuthApp.user_data.expiry);
	timeinfo = localtime(&rawtime);
	Util::SetColor(RED);
	printf(XorStr("%s").c_str(), asctime(timeinfo));
	Util::SetColor(LIGHTBLUE);
	Util::WriteLine("Current Users Online: ");
	Util::SetColor(RED);
	Util::WriteLine(KeyAuthApp.user_data.numUsersOnline);
	Sleep(2000);
AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA:
	Util::SetColor(RED);
	Util::PrintMainMenu();
	std::cin >> option;
	switch (option) {
	case 2:
		SpoofMenu();
		goto LITERALLYTHECOOLESTTHINGEVER;
	case 3:
		SpoofMAC();
		goto LITERALLYTHECOOLESTTHINGEVER;
	case 4:
		goto 	AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA;
		break;
	case 5: 
		Helper();
		goto 	AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA;
	case 6:
		Util::Clear();
		Util::WriteLine(XorStr("Disk Drives: "));
		system(XorStr("wmic diskdrive get serialnumber").c_str());
		Util::WriteLine(XorStr("BIOS & Motherboard: "));
		system(XorStr("wmic csproduct get uuid").c_str());
		system(XorStr("wmic bios get serialnumber").c_str());
		system(XorStr("wmic baseboard get serialnumber").c_str());
		Util::WriteLine(XorStr("Memorychip: "));
		system(XorStr("wmic memorychip get serialnumber").c_str());
		Util::WriteLine(XorStr("MAC: "));
		system(XorStr("getmac /V").c_str());
		Util::SetColor(YELLOW);
		Util::WriteLine(XorStr("Press any key to go back to the menu"));
		system(XorStr("Pause >nul").c_str());
		goto AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA;
	default:
		goto AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA;
	}
	
//	VM_DOLPHIN_BLACK_END
}

void* pe_header[4096];
// enable antidump
void safe()
{
	MutateStart();
	DWORD old = 0;
	void* module = GetModuleHandleW(0);

	VirtualProtect(module, 4096, PAGE_READWRITE, &old);
	memcpy(pe_header, module, 4096);
	ZeroMemory(module, 4096);
	VirtualProtect(module, 4096, old, &old);
	MutateEnd();
}
void notSafe()
{
	MutateStart();
	DWORD old = 0;
	void* module = GetModuleHandleW(0);

	VirtualProtect(module, 4096, PAGE_READWRITE, &old);
	memcpy(module, pe_header, 4096);
	VirtualProtect(module, 4096, old, &old);
	MutateEnd();
}

