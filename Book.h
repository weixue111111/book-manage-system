#pragma once
#include<string>
using namespace std;
class Book//基类
{
private:
	string m_title;
	string m_author;
	string m_publisher;
	string m_ISBN;
	string m_id;//条码号
	double m_price;
	bool m_isBorrowed;
	int m_count;//新增库存数量
public:
	//构造函数
	Book();
	Book(string title, string author, string publisher, string ISBN, string id, double price, bool isBorrowed);
	virtual~Book() = default;
	virtual void showInfo()const = 0;//虚析构+纯虚函数，用来实现继承和多态，子类必须实现showInfo()函数
	//获取
	string getTitle();
	string getAuthor();
	string getPublisher();
	string getISBN();
	string getId();
	double getPrice();
	bool getIsBorrowed();
	int getCount();
	//修改 设置
	void setTitle(string title);
	void setAuthor(string author);
	void setPublisher(string publisher);
	void setISBN(string ISBN);
	void setId(string id);
	void setPrice(double price);
	void setIsBorrowed(bool isBorrowed);
	void display()const;
	void setCount(int count);
};
class NormalBook : public Book//派生类1：普通图书，公有继承Book，没有新增独有成员
{
public:
	NormalBook(string title, string author, string publisher, string ISBN, string id, double price, bool isBorrowed);
	void showInfo()const override;//重写父类的纯虚函数
};
class Magazine :public Book {//派生类2：杂志，公有继承Book，新增独有成员m_issue
private:
	int m_issue;
public:
	Magazine(string title, string author, string publisher, string ISBN, string id, double price, bool isBorrowed, int issue);
	void showInfo()const override;
};
class EBook :public Book {//派生类3：电子书，公有继承Book，新增独有成员m_url
private:
	string m_url;//新增独有成员m_url
public:
	EBook(string title, string author, string publisher, string ISBN, string id, double price, bool isBorrowed, string url);
	void showInfo()const override;
};