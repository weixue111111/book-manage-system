#include <iostream>
#include "Student.h"
using namespace std;

Student::Student()
{
    m_name = "";
    m_stuId = "";
    m_borrowCount = 0;
}

Student::Student(string name, string stuId)
{
    m_name = name;
    m_stuId = stuId;
    m_borrowCount = 0;
}

bool Student::borrowBook(Book& book)
{
    if (book.getIsBorrowed())
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

    book.setIsBorrowed(true);
    m_borrowBooks.push_back(book);
    m_borrowCount++;
    cout << "借阅成功！" << endl;
    return true;
}

bool Student::returnBook(Book& book)
{
    for (int i = 0; i < m_borrowBooks.size(); i++)
    {
        if (m_borrowBooks[i].getId() == book.getId())
        {
            m_borrowBooks.erase(m_borrowBooks.begin() + i);
            m_borrowCount--;
            book.setIsBorrowed(false);
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
    for (auto& b : m_borrowBooks)
    {
        b.display();
    }
}

string Student::getName()
{
    return m_name;
}

string Student::getStuId()
{
    return m_stuId;
}