#pragma once
#include<string>
#include<vector>
#include"Book.h"
using namespace std;

class Student
{
private:
    string m_name;
    string m_stuId;
    int m_borrowCount;       //当前借了几本书
    vector<Book> m_borrowBooks; 
public:
    //构造
    Student();
    Student(string name, string stuId);

    
    bool borrowBook(Book& book);
    //还书
    bool returnBook(Book& book);
    
    void showStudentInfo();

    //get
    string getName();
    string getStuId();
};