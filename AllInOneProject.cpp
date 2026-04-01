
#include <iostream>

int main()
{
	bool running = true;
	while (running) {
		system("title aio toolkit - made by brutalizedshrimpo");
		int choice = -1;
		std::cout << "1. internal wipeout\n";
		std::cout << "2. external wipeout\n";
		std::cout << "3. system checkup\n";
		std::cout << "4. 'reset' network\n";
		std::cout << "0. exit\n";
		std::cout << "enter your choice: ";
		std::cin >> choice;

		if (choice == 1) {
			system("color 0A");
			std::cout << "deleting temporary files...\n";
			system("del /f /s /q %temp%\\*.*");
			std::cout << "deleted temporary files.\n";
			std::cout << "deleting prefetch files...\n";
			system("del /f /s /q %systemroot%\\prefetch\\*.*");
			std::cout << "deleted prefetch files.\n";
			system("pause");
		}
		else if (choice == 2) {
			std::cout << "deleting old windows update files...\n";
			system("Dism /Online /Cleanup-Image /StartComponentCleanup");
			std::cout << "deleted old windows update files.\n";
			std::cout << "cleaning browser cache...\n";
			if (system("if exist \"%localappdata%\\Google\\Chrome\" (exit 0) else (exit 1)") == 0) {
				std::cout << "found google chrome.\n";
				system("cd /d \"%localappdata%\\Google\\Chrome\\User Data\\Default\" && del /f /s /q \"Cache\\*.*\" && del /f /s /q \"Code Cache\\*.*\" && del /f /s /q \"GPUCache\\*.*\"");
			}
			else {
				std::cout << "no supported browsers found.\n";
			}
			if (system("if exist \"%localappdata%\\Microsoft\\Edge\" (exit 0) else (exit 1)") == 0) {
				std::cout << "found microsoft edge.\n";
				system("cd /d \"%localappdata%\\Microsoft\\Edge\\User Data\\Default\" && del /f /s /q \"Cache\\*.*\" && del /f /s /q \"Code Cache\\*.*\" && del /f /s /q \"GPUCache\\*.*\"");
			}
			else {
				std::cout << "no supported browsers found.\n";
			}
			std::cout << "cleaned chrome/edge cache.\n";
			system("pause");
		}
		else if (choice == 3) {
			system("color 0B");
			std::cout << "running system checkup...\n";
			system("sfc /scannow");
			std::cout << "system checkup complete.\n";
			system("findstr /c:'[SR]' %windir%\\Logs\\CBS\\CBS.log > %userprofile%\\Desktop\\sfclogs.txt");
			std::cout << "saved sfc logs to desktop.\n";
			system("pause");
		}
		else if (choice == 4) {
			system("color 0C");
			std::cout << "resetting network...\n";
			system("netsh winsock reset");
			std::cout << "network reset complete.\n";
			std::cout << "restart your computer.\n";
			system("pause");
		}
		else if (choice == 0) {
			std::cout << "exiting program...\n";
			running = false;
		}
		else {
			running = false;
		}
		system("cls");
	}
}
