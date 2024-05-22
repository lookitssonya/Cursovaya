#include <iostream>
#include <string>
#include <windows.h>
#include "Notebook.h"

using namespace std;

// ���������� ������� ������ MyNotebookApp

void MyNotebookApp::run() {
	Notebook notebook;
	int choice;

	while (true) {
		notebook.displayMenu();
		cout << "������� ����� ���������� ��������: ";
		cin >> choice;

		switch (choice) {
		case 1:
			addContactToNotebook(notebook);
			break;
		case 2:
			notebook.displayAllContacts();
			break;
		case 3:
			searchContactByLastName(notebook);
			break;
		case 4:
			editContactInNotebook(notebook);
			break;
		case 5:
			deleteContactFromNotebook(notebook);
			break;
		case 6:
			cout << "\n";
			return;
		default:
			cout << "\n�������� �����. ����������, ������� ����� �� 1 �� 6.\n";
			break;
		}
	}
}

void MyNotebookApp::addContactToNotebook(Notebook& notebook) { // ����� ��� ���������� ��������
	string firstName, lastName, dob, phoneNumber;
	cout << "\n������� ��� ��������: ";
	cin >> firstName;
	cout << "������� ������� ��������: ";
	cin >> lastName;
	cout << "������� ���� �������� ��������: ";
	cin >> dob;
	cout << "������� ����� �������� ��������: ";
	cin >> phoneNumber;

	Contact newContact(firstName, lastName, dob, phoneNumber);
	notebook.addContact(newContact);
	cout << "\n������� ��������.\n";
}

void MyNotebookApp::searchContactByLastName(Notebook& notebook) { // ����� ��� ������ ��������
	string searchLastName;
	cout << "\n������� ������� �������� ��� ������: ";
	cin >> searchLastName;
	cout << "\n����� �������� � �������� '" << searchLastName << "':\n";
	notebook.searchByLastName(searchLastName);
}

void MyNotebookApp::editContactInNotebook(Notebook& notebook) { // ����� ��� �������������� ��������
	string lastName;
	cout << "\n������� ������� �������� ��� ��������������: ";
	cin >> lastName;

	string newFirstName, newLastName, newDOB, newPhoneNumber;
	cout << "\n������� ����� ��� ��������: ";
	cin >> newFirstName;
	cout << "������� ����� ������� ��������: ";
	cin >> newLastName;
	cout << "������� ����� ���� �������� ��������: ";
	cin >> newDOB;
	cout << "������� ����� ����� �������� ��������: ";
	cin >> newPhoneNumber;

	Contact editedContact(newFirstName, newLastName, newDOB, newPhoneNumber);
	notebook.editContact(lastName, editedContact);
}

void MyNotebookApp::deleteContactFromNotebook(Notebook& notebook) { // ����� ��� �������� ��������
	string lastName;
	cout << "\n������� ������� �������� ��� ��������: ";
	cin >> lastName;
	notebook.deleteContact(lastName);
}

int main() {
	system("color F0");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	setlocale(LC_ALL, "Russian");
	cout << "--------��� �������� ������--------\n";
	cout << "\n";

	MyNotebookApp app;
	app.run();

	return 0;
}
