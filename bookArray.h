#pragma once
#include "book.h"

class Bookarray
{
private:
	int capacity;
	int size;
	Book* bk;

public:
	Bookarray(int capacity);
	~Bookarray();

	void addBook(Book book);
	bool searchBookByISBN(int isbn);


	void searchBook(int isbn);


	void deleteBookByISBN(int isbn);
	void updateBookByISBN(int isbn,Book book);

	void printOrderedBook();      // Status false;
	void printreturnBook();       // Status True;

	void printAllBooks();


	Book getbookobj(int isbn);



};


