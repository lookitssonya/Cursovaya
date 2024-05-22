#include <iostream>
#include <string>
#include <windows.h>
#include "Notebook.h"

using namespace std;

// Реализация методов класса MyNotebookApp

void MyNotebookApp::run() {
	Notebook notebook;
	int choice;

	while (true) {
		notebook.displayMenu();
		cout << "Введите номер выбранного действия: ";
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
			cout << "\nНеверный выбор. Пожалуйста, введите число от 1 до 6.\n";
			break;
		}
	}
}

void MyNotebookApp::addContactToNotebook(Notebook& notebook) { // Метод для добавления контакта
	string firstName, lastName, dob, phoneNumber;
	cout << "\nВведите имя контакта: ";
	cin >> firstName;
	cout << "Введите фамилию контакта: ";
	cin >> lastName;
	cout << "Введите дату рождения контакта: ";
	cin >> dob;
	cout << "Введите номер телефона контакта: ";
	cin >> phoneNumber;

	Contact newContact(firstName, lastName, dob, phoneNumber);
	notebook.addContact(newContact);
	cout << "\nКонтакт добавлен.\n";
}

void MyNotebookApp::searchContactByLastName(Notebook& notebook) { // Метод для поиска контакта
	string searchLastName;
	cout << "\nВведите фамилию контакта для поиска: ";
	cin >> searchLastName;
	cout << "\nПоиск контакта с фамилией '" << searchLastName << "':\n";
	notebook.searchByLastName(searchLastName);
}

void MyNotebookApp::editContactInNotebook(Notebook& notebook) { // Метод для редактирования контакта
	string lastName;
	cout << "\nВведите фамилию контакта для редактирования: ";
	cin >> lastName;

	string newFirstName, newLastName, newDOB, newPhoneNumber;
	cout << "\nВведите новое имя контакта: ";
	cin >> newFirstName;
	cout << "Введите новую фамилию контакта: ";
	cin >> newLastName;
	cout << "Введите новую дату рождения контакта: ";
	cin >> newDOB;
	cout << "Введите новый номер телефона контакта: ";
	cin >> newPhoneNumber;

	Contact editedContact(newFirstName, newLastName, newDOB, newPhoneNumber);
	notebook.editContact(lastName, editedContact);
}

void MyNotebookApp::deleteContactFromNotebook(Notebook& notebook) { // Метод для удаления контакта
	string lastName;
	cout << "\nВведите фамилию контакта для удаления: ";
	cin >> lastName;
	notebook.deleteContact(lastName);
}

int main() {
	system("color F0");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	setlocale(LC_ALL, "Russian");
	cout << "--------МОЯ ЗАПИСНАЯ КНИЖКА--------\n";
	cout << "\n";

	MyNotebookApp app;
	app.run();

	return 0;
}
