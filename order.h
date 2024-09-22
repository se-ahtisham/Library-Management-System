#pragma once
#include"student.h"
#include"faculty.h"
#include"book.h"
#include"magazine.h"
#include"journal.h"
#include"newspaper.h"
#include"day.h"

class Order {
private:
    int orderid;
    bool purchaser; // false for Student, true for Faculty
    int itemType;   // 0 for Book, 1 for Journal, 2 for Magazine, 3 for Newspaper

    Date orderDate;
    Date returnDate;

    Student std;
    Faculty ftd;
    Book bk;
    Journal jk;
    Magazine mk;
    Newspaper news;

public:
    Order();
    ~Order();

    void setOrderId(int id);
    void setPurchaserType(bool type);
    void setItemType(int type);

    void setOrderDate(Date date);
    void setReturnDate(Date date);

    Date getOrderDate();
    Date getReturnDate();

    int getOrderId();
    bool getPurchaserType();
    int getItemType();

    void setStudent(Student& student);
    void setFaculty(Faculty& faculty);

    Student getStudent();
    Faculty getFaculty();

    void setBook(Book& book);
    void setJournal(Journal& journal);
    void setMagazine(Magazine& magazine);
    void setNewspaper(Newspaper& news);

    Book getBook();
    Journal getJournal();
    Magazine getMagazine();
    Newspaper getNewspaper();


    void printOrders();


    void issuedBooktoStudent(int orderid, bool purchaser,int itemType, Book bk, Student std, Date orderDate, Date returnDate);
    void issuedMagazinetoStudent(int orderid, bool purchaser, int itemType,Magazine mk, Student std, Date orderDate, Date returnDate);
    void issuedNewspapertoStudent(int orderid, bool purchaser, int itemType,Newspaper news, Student std, Date orderDate, Date returnDate);
    void issuedJournaltoStudent(int orderid, bool purchaser, int itemType,Journal jk, Student std, Date orderDate, Date returnDate);


    void issuedBooktoFaculty(int orderid, bool purchaser, int itemType,Book bk, Faculty ftd, Date orderDate, Date returnDate);
    void issuedMagazinetoFaculty(int orderid, bool purchaser, int itemType, Magazine mk, Faculty ftd, Date orderDate, Date returnDate);
    void issuedNewspapertoFaculty(int orderid, bool purchaser, int itemType,Newspaper news, Faculty ftd, Date orderDate, Date returnDate);
    void issuedJournaltoFaculty(int orderid, bool purchaser, int itemType,Journal jk, Faculty ftd, Date orderDate, Date returnDate);







};

