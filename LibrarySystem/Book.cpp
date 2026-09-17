#include "Book.h"
#include<iostream>
using namespace std;
Book::Book()
{
	m_title = "";
	m_author = "";
	m_publisher = "";
	m_ISBN = "";
	m_id = "";
	m_price = 0.0;
	m_isBorrowed = false;

}

Book::Book(string title, string author, string publisher, string ISBN, string id, double price, bool isBorrowed)
{
	m_title = title;
	m_author = author;
	m_publisher = publisher;
	m_ISBN = ISBN;
	m_id = id;
	m_price = price;
	m_isBorrowed = false;

}

string Book::getTitle()
{
	return m_title;
}

string Book::getAuthor()
{
	return m_author;
}

string Book::getPublisher()
{
	return m_publisher;
}

string Book::getISBN()
{
	return m_ISBN;
}

string Book::getId()
{
	return m_id;
}

double Book::getPrice()
{
	return m_price;
}

bool Book::getIsBorrowed()
{
	return m_isBorrowed;
}

void Book::setTitle(string title)
{
	m_title = title;
}

void Book::setAuthor(string author)
{
	m_author = author;
}

void Book::setPublisher(string publisher)
{
	m_publisher = publisher;
}

void Book::setISBN(string ISBN)
{
	m_ISBN = ISBN;
}

void Book::setId(string id)
{
	m_id = id;
}

void Book::setPrice(double price)
{
	m_price = price;
}

void Book::setIsBorrowed(bool isBorrowed)
{
	m_isBorrowed = isBorrowed;
}

void Book::display()
{
	cout<<"Title: " << m_title << endl;
	cout<<"Author: " << m_author << endl;
	cout<<"Publisher: " << m_publisher << endl;
	cout<<"ISBN: " << m_ISBN << endl;
	cout<<"ID: " << m_id << endl;
	cout<<"Price: " << m_price << endl;
	cout<<"Is Borrowed: " << (m_isBorrowed ? "Yes" : "No") << endl;

}
