#pragma once // ƒиректива препроцессора, гарантирует, что файл будет включен только один раз
#ifndef NOTEBOOK_H
#define NOTEBOOK_H

#include <iostream>
#include <string>
#include <map>
#include <fstream>
using namespace std;

class Contact { 		//  ласс, представл€ющий контакт
public:
	//  онструктор класса Contact, принимает им€, фамилию, дату рождени€ и номер телефона
	Contact(const string& firstName, const string& lastName, const string& dob, const string& phoneNumber);
	void display() const;
	string getLastName() const;
	string getFirstName() const;
	string getDOB() const;
	string getPhoneNumber() const;

private:
	string firstName;
	string lastName;
	string dob;
	string phoneNumber;
};

class Notebook {		//  ласс, представл€ющий записную книжку
public:
	// ћетоды дл€ управлени€ контактами
	void addContact(const Contact& contact);
	void displayAllContacts();
	void searchByLastName(const string& lastName);
	void deleteContact(const string& lastName);
	void editContact(const string& lastName, const Contact& newContact);
	void displayMenu();
	void exportToFile(const string& filename);

private:
	multimap<string, Contact> contacts;
};

class MyNotebookApp {		//  ласс, представл€ющий приложение записной книжки
public:
	void run();
	void addContactToNotebook(Notebook& notebook);
	void searchContactByLastName(Notebook& notebook);
	void editContactInNotebook(Notebook& notebook);
	void deleteContactFromNotebook(Notebook& notebook);
};

#endif // NOTEBOOK_H
