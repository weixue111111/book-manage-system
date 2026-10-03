#include <iostream>
#include "Book.h"
#include "Student.h"
using namespace std;

int main()
{

    Book b1("C++面向对象", "张三", "人民邮电出版社", "97800111", "B001", 49.5, false);
    Book b2("数据结构", "李四", "机械工业出版社", "97800222", "B002", 55.0, false);

    Student stu("小明", "2026001");

    cout << "====尝试借书1====" << endl;
    stu.borrowBook(b1);

    cout << "\n====尝试借书2====" << endl;
    stu.borrowBook(b2);

    stu.showStudentInfo();

    cout << "\n====再次尝试借b1（已借出）====" << endl;
    stu.borrowBook(b1);

    cout << "\n====归还b1====" << endl;
    stu.returnBook(b1);

    stu.showStudentInfo();

    return 0;
}