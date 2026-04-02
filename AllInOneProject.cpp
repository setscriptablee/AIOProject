#include <iostream>
#include <Windows.h>

using namespace std;

void show_info()
{
	SYSTEM_INFO si;
	GetSystemInfo(&si);

	cout << "================ system info ================" << endl;

	cout << "architecture: ";
	if (si.wProcessorArchitecture == 9) {
		cout << "x64 (AMD64)" << endl;
	}
	else if (si.wProcessorArchitecture == 0) {
		cout << "x86 (intel)" << endl;
	}
	else {
		cout << "unknown" << endl;
	}

	cout << "number of processors: " << si.dwNumberOfProcessors << endl;

	cout << "page size: " << si.dwPageSize << " bytes" << endl;

	cout << "=============================================" << endl;
	system("pause");
}

int main()
{
	bool running = true;
	while (running) {
		system("title aio toolkit - made by brutalizedshrimpo");
		int choice = -1;
		cout << "1. internal wipeout\n";
		cout << "2. external wipeout\n";
		cout << "3. system checkup\n";
		cout << "4. 'reset' network\n";
		cout << "0. exit\n";
		cout << "enter your choice: ";
		cin >> choice;

		if (choice == 1) {
			system("color 0A");
			cout << "deleting temporary files...\n";
			system("del /f /s /q %temp%\\*.*");
			cout << "deleted temporary files.\n";
			cout << "deleting prefetch files...\n";
			system("del /f /s /q %systemroot%\\prefetch\\*.*");
			cout << "deleted prefetch files.\n";
			system("pause");
		}
		else if (choice == 2) {
			cout << "deleting old windows update files...\n";
			system("Dism /Online /Cleanup-Image /StartComponentCleanup");
			cout << "deleted old windows update files.\n";
			cout << "cleaning browser cache...\n";
			if (system("if exist \"%localappdata%\\Google\\Chrome\" (exit 0) else (exit 1)") == 0) {
				cout << "found google chrome.\n";
				system("cd /d \"%localappdata%\\Google\\Chrome\\User Data\\Default\" && del /f /s /q \"Cache\\*.*\" && del /f /s /q \"Code Cache\\*.*\" && del /f /s /q \"GPUCache\\*.*\"");
			}
			else {
				cout << "no supported browsers found.\n";
			}
			if (system("if exist \"%localappdata%\\Microsoft\\Edge\" (exit 0) else (exit 1)") == 0) {
				cout << "found microsoft edge.\n";
				system("cd /d \"%localappdata%\\Microsoft\\Edge\\User Data\\Default\" && del /f /s /q \"Cache\\*.*\" && del /f /s /q \"Code Cache\\*.*\" && del /f /s /q \"GPUCache\\*.*\"");
			}
			else {
				cout << "no supported browsers found.\n";
			}
			cout << "cleaned chrome/edge cache.\n";
			system("pause");
		}
		else if (choice == 3) {
			system("color 0B");
			cout << "running system checkup...\n";
			system("sfc /scannow");
			cout << "system checkup complete.\n";
			system("findstr /c:'[SR]' %windir%\\Logs\\CBS\\CBS.log > %userprofile%\\Desktop\\sfclogs.txt");
			cout << "saved sfc logs to desktop.\n";
			system("pause");
		}
		else if (choice == 4) {
			system("color 0C");
			cout << "resetting network...\n";
			system("netsh winsock reset");
			cout << "network reset complete.\n";
			cout << "restart your computer.\n";
			system("pause");
		}
		else if (choice == 9) {
			system("cls");
			show_info();
		}
		else if (choice == 0) {
			cout << "exiting program...\n";
			running = false;
		}
		else {
			running = false;
		}
		system("cls");
	}
}
