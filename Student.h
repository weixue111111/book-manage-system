#pragma once
#include<string>
#include<vector>//vector容器，用来存放学生接到的所有book对象
#include"Book.h"
using namespace std;

class Student
{
private:
    string m_name;
    string m_stuId;
    int m_borrowCount;       //当前借了几本书
    vector<Book*> m_borrowBooks; //展现组合的关系
public:
    //构造
    Student();
    Student(string name, string stuId);

    
    bool borrowBook(Book*book);
    //还书
    bool returnBook(Book*book);
    
    void showStudentInfo();//展示学生信息

    //get
    string getName();
    string getStuId();
};