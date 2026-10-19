#pragma once
#include <vector>
#include "Book.h"

class Library
{
public:
    Library();
    ~Library();
    void addBook(Book* book);//新增的图书资源
    Book* findBookById(const std::string& id) const;
    bool lendBook(const std::string& bookId);
    bool takeBackBook(const std::string& bookId);
	void showAllCollection() const;//显示图书馆所有的图书资源
    void clearResources();
    bool addBookCount(const string& id, int num);//新增已有图书的库存数量
	bool reduceBookCount(const string& id, int num);//减少图书的库存数量
	bool deleteBookById(const string& id);//删除图书馆的图书资源

private:
    std::vector<Book*> m_bookCollection;
};

