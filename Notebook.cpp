#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <windows.h>

#include "Notebook.h"
using namespace std;

// Реализация класса Contact
// Конструктор класса Contact. Инициализирует поля объекта значениями.
Contact::Contact(const string& firstName, const string& lastName, const string& dob, const string& phoneNumber)
	: firstName(firstName), lastName(lastName), dob(dob), phoneNumber(phoneNumber) {}

void Contact::display() const {
	cout << "\nИмя: " << firstName << "\n";
	cout << "Фамилия: " << lastName << "\n";
	cout << "Дата рождения: " << dob << "\n";
	cout << "Номер телефона: " << phoneNumber << "\n";
}
// Геттеры для полей класса Contact
string Contact::getLastName() const { return lastName; }
string Contact::getFirstName() const { return firstName; }
string Contact::getDOB() const { return dob; }
string Contact::getPhoneNumber() const { return phoneNumber; }

// Реализация класса Notebook

void Notebook::addContact(const Contact& contact) { // Метод для добавления контакта
	contacts.insert(make_pair(contact.getLastName(), contact));
	exportToFile("contacts.txt");
}

void Notebook::displayAllContacts() { // Метод для отображения контакта
	for (const auto& contact : contacts) {
		contact.second.display();
	}
}

void Notebook::searchByLastName(const string& lastName) { // Метод для поиска контакта
	auto it = contacts.find(lastName);
	if (it != contacts.end()) {
		it->second.display();
	}
	else {
		cout << "Контакт с фамилией '" << lastName << "' не найден.\n";
	}
}

void Notebook::deleteContact(const string& lastName) { // Метод для удаления контакта
	auto range = contacts.equal_range(lastName);
	if (range.first != contacts.end()) {
		contacts.erase(range.first);
		cout << "\nКонтакт с фамилией '" << lastName << "' удалён.\n";
		exportToFile("contacts.txt");
	}
	else {
		cout << "\nКонтакт с фамилией '" << lastName << "' не найден.\n";
	}
}

void Notebook::editContact(const string& lastName, const Contact& newContact) { // Метод для редактирования контакта
	auto range = contacts.equal_range(lastName);
	if (range.first != contacts.end()) {
		contacts.erase(range.first);
		addContact(newContact);
		cout << "\nКонтакт отредактирован.\n";
		exportToFile("contacts.txt");
	}
	else {
		cout << "\nКонтакт с фамилией '" << lastName << "' не найден.\n";
	}
}

void Notebook::displayMenu() { // Метод для отображения меню
	cout << "\n";
	cout << "Выберите действие:\n";
	cout << "1. Добавить контакт\n";
	cout << "2. Отобразить все контакты\n";
	cout << "3. Найти контакт по фамилии\n";
	cout << "4. Редактировать контакт\n";
	cout << "5. Удалить контакт\n";
	cout << "6. Выйти из программы\n";
	cout << "\n";
}

void Notebook::exportToFile(const std::string& filename) { // Метод для экспорта данных в текстовый файл
	ofstream outfile(filename);

	if (outfile.is_open()) {
		for (const auto& contact : contacts) {
			outfile << contact.second.getFirstName() << " "
				<< contact.second.getLastName() << " "
				<< contact.second.getDOB() << " "
				<< contact.second.getPhoneNumber() << endl;
		}
		outfile.close();
	}
	else {
		cerr << "Ошибка открытия файла: " << filename << endl;
	}
}
