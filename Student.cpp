#include <iostream>
#include "Student.h"
using namespace std;

Student::Student()
{
    m_name = "";
    m_stuId = "";
	m_borrowCount = 0;//无参构造，创建空学生对象，名字和学号为空，借书数量为0
}

Student::Student(string name, string stuId)
{
    m_name = name;
    m_stuId = stuId;
	m_borrowCount = 0;//有参构造，创建学生对象，名字和学号为传入参数，借书数量为0
}

bool Student::borrowBook(Book*book)//学生借阅
{
    if (book == nullptr) {
        cout << "图书为空！" << endl;
        return false;
    }
    if (book->getIsBorrowed())
    {
        cout << "借阅失败，该书已被借出！" << endl;
        return false;
    }
    //最多借10本
    if (m_borrowCount >= 10)
    {
        cout << "借阅失败，已达到最大借阅数量！" << endl;
        return false;
    }

    book->setIsBorrowed(true);
    m_borrowBooks.push_back(book);
    m_borrowCount++;
    cout << "借阅成功！" << endl;
    return true;
}

bool Student::returnBook(Book*book)//学生归还
{
    for (int i = 0; i < m_borrowBooks.size(); i++)
    {
        if (m_borrowBooks[i]->getId() == book->getId())
        {
            m_borrowBooks.erase(m_borrowBooks.begin() + i);
			//等价含义，删除vector中下标为i的元素，表示归还该书
            m_borrowCount--;
            book->setIsBorrowed(false);
            cout << "归还成功！" << endl;
            return true;
        }
    }
    cout << "归还失败，未找到该图书！" << endl;
    return false;
}

void Student::showStudentInfo()
{
    cout << "\n====学生信息====" << endl;
    cout << "姓名：" << m_name << endl;
    cout << "学号：" << m_stuId << endl;
    cout << "已借图书数量：" << m_borrowCount << endl;

    if (m_borrowBooks.empty())
    {
        cout << "暂无借阅图书" << endl;
        return;
    }
    cout << "已借阅图书列表：" << endl;
	for (auto& b : m_borrowBooks)//遍历学生借阅的图书列表，调用Book类的display()方法展示每本书的信息
    {
        b->display();
    }
}
//对外提供接口，获取学生姓名，学号，封装思想
string Student::getName()
{
    return m_name;
}

string Student::getStuId()
{
    return m_stuId;
}