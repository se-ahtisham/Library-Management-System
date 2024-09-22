#include"orderArray.h"
#include "bookArray.h"
#include "magazineArray.h"
#include "newspaperArray.h"
#include "journalArray.h"

OrderArray::OrderArray(int capacity) : size(0), capacity(capacity) {
    orders = new Order[capacity];
}
OrderArray::~OrderArray() {
    delete[] orders;
}

void OrderArray::addOrder(Order order)
{
    if (size < capacity) {
        orders[size++] = order;
    }
    else {
        cout << "Array is full. Cannot add more students." << endl;
    }
    
}


Order OrderArray::search(int orderId) {
    for (int i = 0; i < size; i++) {
        if (orders[i].getOrderId() == orderId) {
            cout << "Order Found!!" << endl;
            return orders[i];
        }
    }
    cout << "Order Not Found!!" << endl;
}
bool OrderArray::searchOrder(int orderId) {
    for (int i = 0; i < size; i++) {
        if (orders[i].getOrderId() == orderId) {
            return true;
        }
    }
    return false;
}


void OrderArray::printOrders() {
    for (int i = 0; i < size; i++)
    {
        orders[i].printOrders();
        cout << "--------------------------------------------------" << endl;
    }

}
void OrderArray:: removeOrder(int orderId)
{
    for (int i = 0; i < size; i++) {
        if (orders[i].getOrderId() == orderId) {
            for (int j = i; j < size - 1; j++)
            {
                orders[j] = orders[j + 1];
            }
            size--;
            return;
        }
    }
    cout << "Order Not Found!!" << endl;
}
int OrderArray::applyfine(Date orderDate, Date returnDate)
{
    int oldDays = orderDate.getDay();
    int newDays = returnDate.getDay();
    int oldMonth = orderDate.getMonth();
    int newMonth = returnDate.getMonth();
    int total = 0;

    if (oldMonth == newMonth) {
        total = newDays - oldDays;
    }

    else if (newMonth > oldMonth) {
        total = (30 - oldDays) + newDays + (newMonth - oldMonth - 1) * 30;
    }
    if (total > 0) {
        return total;
    }
    return 0;

}
void OrderArray::returned(int orderid,  int itemType, Date newreturnDate)
// 0 for Book, 1 for Journal, 2 for Magazine, 3 for Newspaper
// False "Not Avaiable" True means "Avaiable"
{
    for (int i = 0; i < size; i++)
    {
        if (orders[i].getOrderId() == orderid)
        {
            if (itemType == 0)
            {
                cout << "Book Return Center " << endl;
                cout << "-----------------------------------------" << endl;
                cout << "Book Name: " << orders[i].getBook().getname() << endl;
                cout << "Book ISBN: " << orders[i].getBook().getisbn() << endl;
                Date obj = orders[i].getReturnDate();
                cout << "Return Date was ::: " << endl;
                cout << "Date: " << obj.getDay() << endl;
                cout << "Month: " << obj.getMonth() << endl;
                cout << "Year: " << obj.getYear() << endl;
                cout << "The fine is: " << applyfine(obj,newreturnDate);
                cout << endl;
            }
            else if(itemType == 1)
            {
                cout << "Journal Return Center " << endl;
                cout << "-----------------------------------------" << endl;
                cout << "Journal Name: " << orders[i].getJournal().getname() << endl;
                cout << "Journal ISBN: " << orders[i].getJournal().getisbn() << endl;
                Date obj = orders[i].getReturnDate();
                cout << "Return Date was ::: " << endl;
                cout << "Date: " << obj.getDay() << endl;
                cout << "Month: " << obj.getMonth() << endl;
                cout << "Year: " << obj.getYear() << endl;
                cout << "The fine is: " << applyfine(obj, newreturnDate);
                cout << endl;

            }
            else if (itemType == 2)
            {
                cout << "Magazine Return Center " << endl;
                cout << "-----------------------------------------" << endl;
                cout << "Magazine Name: " << orders[i].getMagazine().getname() << endl;
                cout << "Magazine ISBN: " << orders[i].getMagazine().getisbn() << endl;
                Date obj = orders[i].getReturnDate();
                cout << "Return Date was ::: " << endl;
                cout << "Date: " << obj.getDay() << endl;
                cout << "Month: " << obj.getMonth() << endl;
                cout << "Year: " << obj.getYear() << endl;
                cout << "The fine is: " << applyfine(obj, newreturnDate);
                cout << endl;
            }
            else
            {
                cout << "Newspaper Return Center " << endl;
                cout << "-----------------------------------------" << endl;
                cout << "Newspaper Name: " << orders[i].getNewspaper().getname() << endl;
                cout << "Newspaper ISBN: " << orders[i].getNewspaper().getisbn() << endl;
                Date obj = orders[i].getReturnDate();
                cout << "Return Date was ::: " << endl;
                cout << "Date: " << obj.getDay() << endl;
                cout << "Month: " << obj.getMonth() << endl;
                cout << "Year: " << obj.getYear() << endl;
                cout << "The fine is: " << applyfine(obj, newreturnDate);
                cout << endl;
            }

        }

    }
}



