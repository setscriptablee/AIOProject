#include <iostream>
#include <windows.h>

using namespace std;

void batterywatcher() {
	SYSTEM_POWER_STATUS	sps;

	if (GetSystemPowerStatus(&sps)) {
		int batteryLvl = (int)sps.BatteryLifePercent;
		int chargingState = (int)sps.ACLineStatus;

		cout << "current battery: " << batteryLvl << "%" << endl;

		if (chargingState == 1) {
			cout << "charging..." << endl;
		}
		else {
			cout << "discharging..." << endl;
			if (batteryLvl <= 20) {
				cout << "battery low!" << endl;
				Beep(750, 500);
			}
		}
	}
	else
	{
		cout << "your battery died." << endl;
	}
}