#pragma once
#include"order.h"


class OrderArray {
private:
    int size;
    int capacity;
    Order* orders;


public:
    OrderArray(int capacity);
    ~OrderArray();



    void addOrder(Order order);
    void removeOrder(int orderId);
    bool searchOrder(int orderId);

    Order search (int orderId);
    void printOrders();

     void returned(int orderid,int itemType, Date newreturnDate);

     int applyfine(Date orderDate, Date returnDate);



};