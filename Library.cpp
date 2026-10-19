#include "Library.h"
#include<iostream>
using namespace std;

Library::Library()
{

}

Library::~Library()
{
    clearResources();
}

void Library::addBook(Book* book)
{
    if (book != nullptr)
    {
        m_bookCollection.push_back(book);
    }
}

Book* Library::findBookById(const string& id) const
{
    for (Book* p : m_bookCollection)
    {
        if (p->getId() == id)
        {
            return p;
        }
    }
    return nullptr;
}

bool Library::lendBook(const string& bookId)
{
    Book* pBook = findBookById(bookId);
    if (pBook == nullptr || pBook->getIsBorrowed())
    {
        return false;
    }
    pBook->setIsBorrowed(true);
    return true;
}

bool Library::takeBackBook(const string& bookId)
{
    Book* pBook = findBookById(bookId);
    if (pBook == nullptr || !pBook->getIsBorrowed())
    {
        return false;
    }
    pBook->setIsBorrowed(false);
    return true;
}

void Library::showAllCollection() const
{
    cout << "\n====图书馆馆藏全部图书====" << endl;
    for (Book* p : m_bookCollection)
    {
		p->showInfo();//调用多态，显示不同类型的图书信息,显示某一本书或资源情况
    }
}

void Library::clearResources()
{
    for (Book* p : m_bookCollection)
    {
        delete p;
    }
    m_bookCollection.clear();
}

bool Library::addBookCount(const string& id, int num)// 增加已有图书资源数量
{
    for (Book* p : m_bookCollection)
    {
        if (p->getId() == id)
        {
            p->setCount(p->getCount() + num);
            cout << "库存增加成功！" << endl;
            return true;
        }
    }
    cout << "未找到该图书，增加数量失败" << endl;
    return false;
}


bool Library::reduceBookCount(const string& id, int num)//减少已有图书资源数量
{
    for (Book* p : m_bookCollection)
    {
        if (p->getId() == id)
        {
            if (p->getCount() < num)
            {
                cout << "库存不足，减少数量失败！" << endl;
                return false;
            }
            p->setCount(p->getCount() - num);
            cout << "库存减少成功！" << endl;
            return true;
        }
    }
    cout << "未找到该图书，减少数量失败" << endl;
    return false;
}


bool Library::deleteBookById(const string& id)//删除某图书资源
{
    for (auto it = m_bookCollection.begin(); it != m_bookCollection.end(); ++it)
    {
        if ((*it)->getId() == id)
        {
            delete* it; //释放堆内存
            m_bookCollection.erase(it); //从vector删掉指针
            cout << "图书删除成功" << endl;
            return true;
        }
    }
    cout << "未找到该图书，删除失败" << endl;
    return false;
}