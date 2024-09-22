#include"order.h"

Order::Order() : orderid(0), purchaser(false), itemType(0), orderDate(Date()), returnDate(Date()),
std(Student()) , ftd (Faculty()), bk(Book()), jk(Journal()),mk(Magazine()), news(Newspaper()){}

Order::~Order() {}

void Order::setOrderId(int id) {
    orderid = id;
}

void Order::setPurchaserType(bool type) {
    purchaser = type;
}

void Order::setItemType(int type) {
    itemType = type;
}

int Order::getOrderId() {
    return orderid;
}

bool Order::getPurchaserType() {
    return purchaser;
}

int Order::getItemType() {
    return itemType;
}


void Order::setStudent(Student& student) {
    std = student;
    purchaser = false;
}

void Order::setFaculty(Faculty& faculty) {
    ftd = faculty;
    purchaser = true;
}

Student Order::getStudent() {
    return std;
}

Faculty Order::getFaculty() {
    return ftd;
}

void Order::setBook(Book& book) {
    bk = book;
    itemType = 0;
}

void Order::setJournal(Journal& journal) {
    jk = journal;
    itemType = 1; 
}

void Order::setMagazine(Magazine& magazine) {
    mk = magazine;
    itemType = 2;
}

void Order::setNewspaper(Newspaper& newspaper) {
    news = newspaper;
    itemType = 3; 
}


Book Order::getBook() { return bk; }
Journal Order::getJournal() { return jk; }
Magazine Order::getMagazine() { return mk; }
Newspaper Order::getNewspaper() { return news;}


void Order::setOrderDate(Date date) {
    orderDate = date;
}
void Order::setReturnDate(Date date){
    returnDate = date;
}

Date Order::getOrderDate() { return orderDate; }
Date Order::getReturnDate() { return returnDate; }


void Order::printOrders() {
    cout << "Order ID: " << orderid << endl;
    cout << "Purchaser Type: " << (purchaser ? "Faculty" : "Student") << endl;
    if (!purchaser) {
        std.printStudentDetails();
    }
    else {
        ftd.printFacultyDetails();
    }

    cout << "Item Type: ";

    if (itemType == 0) {
        cout << "Book" << endl;
        bk.prinbookinfo();
    }
    else if (itemType == 1) {
        cout << "Journal" << endl;
        jk.printjournalinfo();
    }
    else if (itemType == 2) {
        cout << "Magazine" << endl;
        mk.printmagazineinfo();
    }
    else if (itemType == 3) {
        cout << "Newspaper" << endl;
        news.printnewspaperinfo();
    }

    cout << endl;
    cout << "Order Date: ";
    orderDate.printDate();
    cout << "Return Date: ";
    returnDate.printDate();
}




void  Order:: issuedBooktoStudent(int orderid, bool purchaser, int itemType, Book bk, Student std, Date orderDate, Date returnDate) {
    if (bk.getstatus() == false)
    {
        cout << "Book Not Available" << endl;
        return;
    }

    this->setItemType(itemType);
    this->setOrderId(orderid);
    this->setPurchaserType(false);
    this->setBook(bk);
    this->setStudent(std);
    this->setOrderDate(orderDate);
    this->setReturnDate(returnDate);
    cout << "Order successfull!" << endl;

}
void Order::issuedMagazinetoStudent(int orderid, bool purchaser, int itemType, Magazine mk, Student std, Date orderDate, Date returnDate) {
    if (mk.getstatus() == false) {
        cout << "Magazine Not Available" << endl;
        return;
    }
    this->setItemType(itemType);
    this->setPurchaserType(false);
    this->setOrderId(orderid);
    this->setMagazine(mk);
    this->setStudent(std);
    this->setOrderDate(orderDate);
    this->setReturnDate(returnDate);
    cout << "Order successful!" << endl;
}
void Order::issuedNewspapertoStudent(int orderid, bool purchaser, int itemType, Newspaper news, Student std, Date orderDate, Date returnDate) {
    if (news.getstatus() == false) {
        cout << "Newspaper Not Available" << endl;
        return;
    }
    this->setItemType(itemType);
    this->setPurchaserType(false);
    this->setOrderId(orderid);
    this->setNewspaper(news);
    this->setStudent(std);
    this->setOrderDate(orderDate);
    this->setReturnDate(returnDate);
    cout << "Order successful!" << endl;
}
void Order::issuedJournaltoStudent(int orderid, bool purchaser, int itemType, Journal jk, Student std, Date orderDate, Date returnDate) {
    if (jk.getstatus() == false) {
        cout << "Journal Not Available" << endl;
        return;
    }
    this->setItemType(itemType);
    this->setPurchaserType(false);
    this->setOrderId(orderid);
    this->setJournal(jk);
    this->setStudent(std);
    this->setOrderDate(orderDate);
    this->setReturnDate(returnDate);
    cout << "Order successful!" << endl;
}

void Order::issuedBooktoFaculty(int orderid, bool purchaser, int itemType, Book bk, Faculty ftd, Date orderDate, Date returnDate) {
    if (bk.getstatus() == false) {
        cout << "Book Not Available" << endl;
        return;
    }
    this->setItemType(itemType);
    this->setPurchaserType(true);
    this->setOrderId(orderid);
    this->setBook(bk);
    this->setFaculty(ftd);
    this->setOrderDate(orderDate);
    this->setReturnDate(returnDate);
    cout << "Order successful!" << endl;
}
void Order:: issuedMagazinetoFaculty(int orderid, bool purchaser, int itemType, Magazine mk, Faculty ftd, Date orderDate, Date returnDate) {
    if (mk.getstatus() == false) {
        cout << "Magazine Not Available" << endl;
        return;
    }
    this->setItemType(itemType);
    this->setPurchaserType(true);
    this->setOrderId(orderid);
    this->setMagazine(mk);
    this->setFaculty(ftd);
    this->setOrderDate(orderDate);
    this->setReturnDate(returnDate);
    cout << "Order successful!" << endl;
}
void Order::issuedNewspapertoFaculty(int orderid, bool purchaser, int itemType, Newspaper news, Faculty ftd, Date orderDate, Date returnDate) {
    if (news.getstatus() == false) {
        cout << "Newspaper Not Available" << endl;
        return;
    }
    this->setItemType(itemType);
    this->setPurchaserType(true);
    this->setOrderId(orderid);
    this->setNewspaper(news);
    this->setFaculty(ftd);
    this->setOrderDate(orderDate);
    this->setReturnDate(returnDate);
    cout << "Order successful!" << endl;
}
void Order::issuedJournaltoFaculty(int orderid, bool purchaser, int itemType, Journal jk, Faculty ftd, Date orderDate, Date returnDate){
    if (jk.getstatus() == false) {
        cout << "Journal Not Available" << endl;
        return;
    }
    this->setItemType(itemType);
    this->setPurchaserType(true);
    this->setOrderId(orderid);
    this->setJournal(jk);
    this->setFaculty(ftd);
    this->setOrderDate(orderDate);
    this->setReturnDate(returnDate);
    cout << "Order successful!" << endl;
}
