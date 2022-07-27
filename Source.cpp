//github.com/ferrnnaando
//t.me/ferrnnaando
//youtube.com/ferrnnaando
//folow me :)
// *laype project

#include <iostream>
#include <Windows.h>
#include <TlHelp32.h>
#include <string>

DWORD getProcId(const char* procName);

int main() {
	DWORD hexAmmo, hexHealth, procId;
	int newAmmo, newHealth;
	std::string healthOption, ammoOption, closeValue;

	std::string procNameStrng;
	std::cout << "[?] enter a process name: ";
	std::cin >> procNameStrng;
	const char* procName = procNameStrng.c_str();

	HANDLE hProc = OpenProcess(PROCESS_ALL_ACCESS, FALSE, procId);

	while (true) {

		std::cout << "do you want custom health [Y/N]: ";
		std::cin >> healthOption;
		if (healthOption == "Y") {
			std::cout << "enter a health address: ";
			std::cin >> std::hex >> hexHealth;
			std::cout << "enter a custom health value: ";
			std::cin >> newHealth;
			WriteProcessMemory(hProc, (LPVOID)hexHealth, &newHealth, sizeof(newHealth), NULL);
			if (WriteProcessMemory(hProc, (LPVOID)hexHealth, &newHealth, sizeof(newHealth), NULL) == NULL) {
				std::cout << "there was an error.";
			}
		} else if (healthOption == "N") {
			Sleep(35);
		} else {
			std::cout << "not a correct option.";
			Sleep(35);
		}

		system("cls");
		std::cout << "do you want custom ammo [Y/N]: ";
		std::cin >> ammoOption;
		if (ammoOption == "Y") {
			std::cin >> ammoOption;
			std::cout << "enter an ammo address: ";
			std::cin >> std::hex >> hexAmmo;
			std::cout << "enter a custom ammo ammount: ";
			std::cin >> newAmmo;
			WriteProcessMemory(hProc, (LPVOID)hexAmmo, &newAmmo, sizeof(newAmmo), NULL);
			if (WriteProcessMemory(hProc, (LPVOID)hexAmmo, &newAmmo, sizeof(newAmmo), NULL) == NULL) {
				std::cout << "there was an error.";
			}
		} else if (ammoOption == "N") {
			Sleep(35);
		} else {
			std::cout << "not a correct option.";
		}
		
		system("cls");
		std::cout << "do you want close the program [Y/N]: ";
		std::cin >> closeValue;
		if (closeValue == "Y") {
			exit(-1);
		}
		else if (closeValue == "N") {
	
		} else {
			std::cout << "not a correct option.";
		}
	}

	return 0;
}

DWORD getProcId(const char* procName) {
	DWORD procId = 0;
	HANDLE hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, procId);
	if (hSnap != INVALID_HANDLE_VALUE) {
		PROCESSENTRY32 procEntry;
		procEntry.dwSize = sizeof(procEntry);

		if (Process32First(hSnap, &procEntry)) {
			do {
				if (!_stricmp(procEntry.szExeFile, procName)) {
					procId = procEntry.th32ProcessID;
				}
			} while (Process32Next(hSnap, &procEntry));
		}
	}

	CloseHandle(hSnap);
	return procId;
}