#include <iostream>
#include <windows.h>
#include <string>
#include <fstream>
#include <conio.h>
using namespace std;

class login_system
{
	void waiting()
	{
		for (int i = 0; i < 10; i++)
		{
			Sleep(200);
			cout << "..";
		}
	}
private:
	string fname, password, name, pass, date, month, year, email, number;
public:
	void homepage();
	void menu();
	void details();
	void modify();
	void change_password();
	void delete_account();

};
void login_system::homepage() {
    system("cls");
    cout << "\n\t\t\t\t===========================================================" << endl;
    cout << "\t\t\t\t|                                                         |" << endl;
    cout << "\t\t\t\t|               CREATE, LOGIN & AUTHENTICATION            |" << endl;
    cout << "\t\t\t\t|                                                         |" << endl;
    cout << "\t\t\t\t===========================================================" << endl << endl << endl;
    cout << "\n\t\t\t\t\t====================================" << endl;
    cout << "\t\t\t\t\t|                                  |" << endl;
    cout << "\t\t\t\t\t|              HOMEPAGE            |" << endl;
    cout << "\t\t\t\t\t|                                  |" << endl;
    cout << "\t\t\t\t\t====================================" << endl;
    cout << "\t\t\t\t\t|                                  |" << endl;
    cout << "\t\t\t\t\t| Kindly select an option below:   |" << endl;
    cout << "\t\t\t\t\t| 1. Create Account                |" << endl;
    cout << "\t\t\t\t\t| 2. Login                         |" << endl;
    cout << "\t\t\t\t\t| 3. List of All Accounts          |" << endl;
    cout << "\t\t\t\t\t| 4. Search Account By Name        |" << endl;
    cout << "\t\t\t\t\t| 5. Exit                          |" << endl;
    cout << "\t\t\t\t\t====================================" << endl << endl;
    char x;
    cout << "\t\t\t\t\t-> ";
    cin >> x;

    if (x == '1') {
        system("cls");
        cout << "\n\t\t\t\t\t====================================" << endl;
        cout << "\t\t\t\t\t|                                  |" << endl;
        cout << "\t\t\t\t\t|         Create Account           |" << endl;
        cout << "\t\t\t\t\t|                                  |" << endl;
        cout << "\t\t\t\t\t====================================" << endl << endl;
        cout << "\t\t\t\t\tEnter User_Name: ";
        cin >> fname;
        cout << endl << "\t\t\t\t\tEnter your Date of Birth: " << endl << "\t\t\t\t\tDay: ";
        cin >> date;
        cout << "\t\t\t\t\tMonth: ";
        cin >> month;
        cout << "\t\t\t\t\tYear: ";
        cin >> year;
        cout << endl << "\t\t\t\t\tEnter your Contact Details: " << endl << "\t\t\t\t\tPhone Number: ";
        cin >> number;
        cout << endl << "\t\t\t\t\tEnter Email Address: ";
        cin >> email;
        cout << endl << "\t\t\t\t\tEnter password: ";
        char ch;
        password = "";
        ch = _getch();
        while (ch != 13) {  // 13 je ASCII za Enter
            password.push_back(ch);
            cout << "*";
            ch = _getch();
        }
        fstream file;
        file.open("files.txt", ios::app | ios::out);
        if (!file) {
            cout << "\t\t\t\t\tRegistration failed. Try again later." << endl;
        }
        else {
            file << fname << " " << password << " " << number << " " << email << " " << date << " " << month << " " << year << "\n";
            cout << "\n\n\t\t\t\t\tAccount Created Successfully." << endl;
            file.close();
        }
        system("pause");
        homepage();
    }
    else if (x == '2') {
        system("cls");
        cout << "\n\t\t\t\t\t====================================" << endl;
        cout << "\t\t\t\t\t|                                  |" << endl;
        cout << "\t\t\t\t\t|          LOGIN PAGE              |" << endl;
        cout << "\t\t\t\t\t|                                  |" << endl;
        cout << "\t\t\t\t\t====================================" << endl << endl;
        fstream file;
        file.open("files.txt", ios::in);
        if (!file) {
            cout << "\t\t\t\t\tError! File not found." << endl;
            file.close();
            system("pause");
            homepage();
        }
        else {
            char ch;
            string name, pass;
            int flag = 0;
            cout << "\t\t\t\t\tEnter User Name: ";
            cin >> name;
            cout << "\t\t\t\t\tEnter Password: ";
            ch = _getch();
            while (ch != 13) {  // 13 je ASCII za Enter
                pass.push_back(ch);
                cout << "*";
                ch = _getch();
            }
            file >> fname >> password >> number >> email >> date >> month >> year;
            while (!file.eof()) {
                if (name == fname && pass == password) {
                    flag = 1;
                    break;
                }
                file >> fname >> password >> number >> email >> date >> month >> year;
            }
            cout << "\n\t\t\t\t\tVerifying User Data: " << endl;
            waiting();
            if (flag == 1) {
                cout << "\n\n\t\t\t\t\tLogin Successful." << endl;
                file.close();
                Sleep(789);
                menu();
            }
            else {
                cout << "\n\n\t\t\t\t\tNo account exists with given credentials." << endl;
                system("pause");
                file.close();
                homepage();
            }
        }
    }
	else if (x == '3') 
	{
		system("cls");
		cout << "\n\t\t\t\t\t====================================" << endl;
		cout << "\t\t\t\t\t|                                  |" << endl;
		cout << "\t\t\t\t\t|       LIST OF ALL ACCOUNTS       |" << endl;
		cout << "\t\t\t\t\t|                                  |" << endl;
		cout << "\t\t\t\t\t====================================" << endl << endl;

		fstream file;
		file.open("files.txt", ios::in);
		if (!file) {
			cout << "\t\t\t\t\tError! File not found." << endl;
		}
		else {
			int x = 1;
			while (file >> fname >> password >> number >> email >> date >> month >> year) {
				Sleep(60);
				cout << "\t\t\t\t\t====================================" << endl;
				cout << "\t\t\t\t\t|                                  |" << endl;
				cout << "\t\t\t\t\t|             ACCOUNT " << x++ << "            |" << endl;
				cout << "\t\t\t\t\t|                                  |" << endl;
				cout << "\t\t\t\t\t====================================" << endl;
				cout << "\t\t\t\t\t 1. User_name = " << fname << endl;
				cout << "\t\t\t\t\t 2. Contact = " << number << endl;
				cout << "\t\t\t\t\t 3. Email = " << email << endl;
				cout << "\t\t\t\t\t 4. Date of Birth = " << date << "/" << month << "/" << year << endl;
				cout << "\t\t\t\t\t====================================" << endl << endl;
			}
			if (x == 1) {
				cout << "\t\t\t\t\tNo accounts found." << endl;
			}
		}
		file.close();
		cout << "\t\t\t\t\t";
		system("pause");
		homepage();
	}
	else if (x == '4')
	{
		system("cls");
		cout << "\n\t\t\t\t\t====================================" << endl;
		cout << "\t\t\t\t\t|                                  |" << endl;
		cout << "\t\t\t\t\t|          SEARCH ACCOUNT          |" << endl;
		cout << "\t\t\t\t\t|                                  |" << endl;
		cout << "\t\t\t\t\t====================================" << endl << endl;
		cout << "\t\t\t\t\t Enter User_Name: ";
		cin >> name;
		int found = 0;
		fstream file;
		file.open("files.txt", ios::in);
		file >> fname >> password >> number >> email >> date >> month >> year;
		while (!file.eof())
		{
			if (name == fname)
			{
				Sleep(60);
				cout << "\t\t\t\t\t 1. User_Name = " << fname << endl;
				cout << "\t\t\t\t\t 2. Email = " << email << endl;
				cout << "\t\t\t\t\t 3. Contact = " << number << endl;
				cout << "\t\t\t\t\t 4. Date of Birth = " << date << "/" << month << "/" << endl << endl;
				cout << "\t\t\t\t\t ========================================" << endl << endl;
				found++;
			}
			file >> fname >> password >> number >> email >> date >> month >> year;
		}
		if (found == 0)
		{
			cout << endl << "\t\t\t\t\t No account exist with [" << name << "] username. " << endl << endl;
		}
		file.close();
		cout << "\t\t\t\t\t";
		system("pause");
		homepage();
	}
	else if (x == '5')
	{
		_exit(0);
	}
	else
	{
		cout << "\t\t\t\t\t Invalid Parameter, Try Again.";
		Sleep(600);
		homepage();
	}
}
void login_system::menu()
{
	system("cls");
	cout << "\n\t\t\t\t\t====================================" << endl;
	cout << "\t\t\t\t\t|                                  |" << endl;
	cout << "\t\t\t\t\t|        ACCOUNT MANAGER           |" << endl;
	cout << "\t\t\t\t\t|                                  |" << endl;
	cout << "\t\t\t\t\t====================================" << endl << endl;
	cout << "\t\t\t\t\t Kindl select an option below: " << endl << endl;
	cout << "\t\t\t\t\t 1. Account Details " << endl << endl;
	cout << "\t\t\t\t\t 2. Modify Account " << endl << endl;
	cout << "\t\t\t\t\t 3. Change Password " << endl << endl;
	cout << "\t\t\t\t\t 4. Delete Account " << endl << endl;
	cout << "\t\t\t\t\t 5. Logout " << endl;
	char option;
	cout << endl << "\t\t\t\t\t -> ";
	cin >> option;
	switch (option)
	{
	case '1':
		details();
		break;
	case '2':
		modify();
		break;
	case '3':
		change_password();
	case '4':
		delete_account();
	case '5':
	{
		cout << "\n\t\t\t\t\t Logginng Out ... " << endl;
		waiting();
		homepage();
		break;
	}
	default:
		cout << "\n\t\t\t\t\t Invalid Option \n\t\t\t\t\t Try Again. " << endl;
		Sleep(600);
		menu();
	}
}
void login_system::details() {
	system("cls");
	cout << "\n\t\t\t\t\t====================================" << endl;
	cout << "\t\t\t\t\t|                                  |" << endl;
	cout << "\t\t\t\t\t|          ACCOUNT DETAILS         |" << endl;
	cout << "\t\t\t\t\t|                                  |" << endl;
	cout << "\t\t\t\t\t====================================" << endl << endl;

	fstream file;
	file.open("files.txt", ios::in);
	if (!file) {
		cout << "\t\t\t\t\tError! File not found." << endl;
	}
	else {
		bool found = false;
		while (file >> fname >> password >> number >> email >> date >> month >> year) {
			if (name == fname && pass == password) {
				cout << "\t\t\t\t\t 1. User_Name = " << fname << endl;
				cout << "\t\t\t\t\t 2. Email = " << email << endl;
				cout << "\t\t\t\t\t 3. Contact = " << number << endl;
				cout << "\t\t\t\t\t 4. Date of Birth = " << date << "/" << month << "/" << year << endl;
				cout << "\t\t\t\t\t 5. Account Password = " << password << endl;
				found = true;
				break;
			}
		}
		if (!found) {
			cout << "\t\t\t\t\tNo account found with the given credentials." << endl;
		}
	}
	file.close();
	cout << "\t\t\t\t\t";
	system("pause");
	menu();
}
void login_system::modify() {
	system("cls");
	cout << "\n\t\t\t\t\t====================================" << endl;
	cout << "\t\t\t\t\t|                                  |" << endl;
	cout << "\t\t\t\t\t|           MODIFY ACCOUNT         |" << endl;
	cout << "\t\t\t\t\t|                                  |" << endl;
	cout << "\t\t\t\t\t====================================" << endl << endl;

	fstream file, file1;
	file.open("files.txt", ios::in);
	file1.open("modify.txt", ios::app | ios::out);

	if (!file || !file1) {
		cout << "\t\t\t\t\tError! Could not open files." << endl;
		return;
	}

	bool found = false;
	while (file >> fname >> password >> number >> email >> date >> month >> year) {
		if (name == fname && pass == password) {
			cout << "\t\t\t\t\tEnter User_Name: ";
			cin >> fname;
			cout << endl << "\t\t\t\t\tEnter your Date of Birth: " << endl << "\t\t\t\t\tDay: ";
			cin >> date;
			cout << "\t\t\t\t\tMonth: ";
			cin >> month;
			cout << "\t\t\t\t\tYear: ";
			cin >> year;
			cout << endl << "\t\t\t\t\tEnter your Contact: " << endl << "\t\t\t\t\tPhone Number: ";
			cin >> number;
			cout << endl << "\t\t\t\t\tEnter Email Address: ";
			cin >> email;
			file1 << fname << " " << password << " " << number << " " << email << " " << date << " " << month << " " << year << "\n";
			found = true;
		}
		else {
			file1 << fname << " " << password << " " << number << " " << email << " " << date << " " << month << " " << year << "\n";
		}
	}

	file.close();
	file1.close();

	if (!found) {
		cout << "\t\t\t\t\tNo account found with the given credentials." << endl;
		remove("modify.txt");  // Izbriši privremenu datoteku ako nije pronaðen raèun
	}
	else {
		remove("files.txt");
		rename("modify.txt", "files.txt");
		cout << "\n\t\t\t\t\tAccount details saved successfully." << endl;
	}

	cout << "\t\t\t\t\t";
	system("pause");
	menu();
}
void login_system::change_password() {
	system("cls");
	cout << "\n\t\t\t\t\t====================================" << endl;
	cout << "\t\t\t\t\t|                                  |" << endl;
	cout << "\t\t\t\t\t|          CHANGE PASSWORD         |" << endl;
	cout << "\t\t\t\t\t|                                  |" << endl;
	cout << "\t\t\t\t\t====================================" << endl << endl;

	string oldpass, newpass, confirmpass;
	cout << "\t\t\t\t\tEnter your current password: ";
	cin >> oldpass;

	if (oldpass == pass) {
		cout << endl << "\t\t\t\t\tEnter new password: ";
		cin >> newpass;
		if (newpass == oldpass) {
			cout << endl << "\t\t\t\t\tOld and new password can't be the same." << endl;
		}
		else {
			cout << endl << "\t\t\t\t\tConfirm new password: ";
			cin >> confirmpass;
			if (confirmpass != newpass) {
				cout << endl << "\t\t\t\t\tError! Password mismatch." << endl;
			}
			else {
				fstream file, file1;
				file.open("files.txt", ios::in);
				file1.open("modify.txt", ios::app | ios::out);

				if (!file || !file1) {
					cout << "\t\t\t\t\tError! Could not open files." << endl;
					return;
				}

				bool found = false;
				while (file >> fname >> password >> number >> email >> date >> month >> year) {
					if (name == fname && pass == oldpass) {
						file1 << fname << " " << newpass << " " << number << " " << email << " " << date << " " << month << " " << year << "\n";
						found = true;
					}
					else {
						file1 << fname << " " << password << " " << number << " " << email << " " << date << " " << month << " " << year << "\n";
					}
				}

				file.close();
				file1.close();

				if (!found) {
					cout << "\t\t\t\t\tNo account found with the given credentials." << endl;
					remove("modify.txt");  // Izbriši privremenu datoteku ako nije pronaðen raèun
				}
				else {
					remove("files.txt");
					rename("modify.txt", "files.txt");
					cout << "\n\t\t\t\t\tPassword changed successfully." << endl;
				}
			}
		}
	}
	else {
		cout << endl << "\t\t\t\t\tError! Wrong password." << endl;
	}

	cout << "\t\t\t\t\t";
	system("pause");
	menu();
}
void login_system::delete_account() {
	system("cls");
	cout << "\n\t\t\t\t\t====================================" << endl;
	cout << "\t\t\t\t\t|                                  |" << endl;
	cout << "\t\t\t\t\t|           DELETE ACCOUNT         |" << endl;
	cout << "\t\t\t\t\t|                                  |" << endl;
	cout << "\t\t\t\t\t====================================" << endl << endl;

	cout << "\t\t\t\t\tAre you sure you want to delete your account? (Y/N): ";
	char x;
	cin >> x;

	if (x == 'y' || x == 'Y') {
		fstream file, file1;
		file.open("files.txt", ios::in);
		file1.open("modify.txt", ios::app | ios::out);

		if (!file || !file1) {
			cout << "\t\t\t\t\tError! Could not open files." << endl;
			return;
		}

		bool found = false;
		while (file >> fname >> password >> number >> email >> date >> month >> year) {
			if (name == fname && pass == password) {
				found = true;
			}
			else {
				file1 << fname << " " << password << " " << number << " " << email << " " << date << " " << month << " " << year << "\n";
			}
		}

		file.close();
		file1.close();

		if (!found) {
			cout << "\t\t\t\t\tNo account found with the given credentials." << endl;
			remove("modify.txt");  // Izbriši privremenu datoteku ako nije pronaðen raèun
		}
		else {
			remove("files.txt");
			rename("modify.txt", "files.txt");
			cout << "\n\t\t\t\t\tAccount deleted successfully." << endl;
		}

		cout << "\t\t\t\t\tLogging you out..." << endl;
		Sleep(1000);
		homepage();
	}
	else if (x == 'n' || x == 'N') {
		cout << "\t\t\t\t\tReturning to the menu..." << endl;
		Sleep(1000);
		menu();
	}
	else {
		cout << "\t\t\t\t\tInvalid option. Please try again." << endl;
		system("pause");
		delete_account();
	}
}
int main()
{
	login_system x;
	x.homepage();
	return 0;
}

