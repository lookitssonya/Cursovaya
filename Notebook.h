#pragma once // ��������� �������������, �����������, ��� ���� ����� ������� ������ ���� ���
#ifndef NOTEBOOK_H
#define NOTEBOOK_H

#include <iostream>
#include <string>
#include <map>
#include <fstream>
using namespace std;

class Contact { 		// �����, �������������� �������
public:
	// ����������� ������ Contact, ��������� ���, �������, ���� �������� � ����� ��������
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

class Notebook {		// �����, �������������� �������� ������
public:
	// ������ ��� ���������� ����������
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

class MyNotebookApp {		// �����, �������������� ���������� �������� ������
public:
	void run();
	void addContactToNotebook(Notebook& notebook);
	void searchContactByLastName(Notebook& notebook);
	void editContactInNotebook(Notebook& notebook);
	void deleteContactFromNotebook(Notebook& notebook);
};

#endif // NOTEBOOK_H
