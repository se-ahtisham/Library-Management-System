#include "order.h"
#include "orderArray.h"

#include"admin.h"
#include"adminArray.h"

#include"Student.h"
#include"studentArray.h"

#include"Faculty.h"
#include"facultyArray.h"

#include "book.h"
#include "bookArray.h"

#include "magazine.h"
#include "magazineArray.h"

#include "newspaper.h"
#include "newspaperArray.h"

#include "journal.h"
#include "journalArray.h"


void intro()
{
    cout << endl;
    cout << "\t\t********************************************************************************";
    cout << endl;
    cout << " \t\t                      Welcome to Library Management System                     ";
    cout << endl;
    cout << "\t\t********************************************************************************";
    cout << endl;
}

int main()
{
    intro();
    cout << endl;
    cout << endl;

    // Default Declearations
    AdminArray* adminarray = new AdminArray(2);
    StudentArray* stdarray = new StudentArray(2);
    FacultyArray * ftdarray = new FacultyArray(2);


    Bookarray* book = new Bookarray(2);
    Magazinearray* magazine = new Magazinearray(2);
    Journalarray* journal = new Journalarray(2);
    Newspaperarray* news = new Newspaperarray(2);

    OrderArray* orderarray = new OrderArray(2);


  

    int choice = -1;
    while (choice != 0) {
        // Displaying the main menu
        cout << "\n============================" << endl;
        cout << "        Main Menu           " << endl;
        cout << "============================" << endl;
        cout << "1. Student Portal" << endl;
        cout << "2. Faculty Portal" << endl;
        cout << "3. Admin Portal" << endl;
        cout << "0. Exit" << endl;
        cout << "============================" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        string name, email, bookName, bookAuthor, volumn, edition = "";
        int isbn,id, yearOfPublication, libraryCode, pages, day, month, year = 0;
        int orderid = 1;

        switch (choice) {

            // Student portal
        case 1:
        {

            int studentChoice = -1;
            while (studentChoice != 0) {
                cout << endl;
                cout << "\n--- Student Portal ---" << endl;
                cout << endl;
                cout << "1. Login" << endl;
                cout << "2. Signup" << endl;
                cout << "3. Search (Book, Magazine, Newspaper, Journal)" << endl;
                cout << "4. Check all available (Book, Magazine, Newspaper, Journal)" << endl;
                cout << "0. Back to Main Menu" << endl;
                cout << "Enter your choice: ";
                cin >> studentChoice;
                cout << endl;
                switch (studentChoice) {
                case 1:
                {
                    cout << endl;
                    bool found = false;
                    cout << "Enter Student ID: ";
                    cin >> id;
                    found = stdarray->searchStudentById(id);

                    cout << endl;
                    if (found) {
                        

                        int loggedIn = -1;
                        int logchoice = -1;
                        while (loggedIn != 0) {
                            cout << "1. Order Book" << endl;
                            cout << "2. Order Magazine" << endl;
                            cout << "3. Order Newspaper" << endl;
                            cout << "4. Order Journal" << endl;
                            cout << "0. Logout" << endl;
                            cout << "Enter your choice: ";
                            cin >> logchoice;
                            cout << endl;

                            switch (logchoice) {
                            case 1: {
                                cout << endl;
                                Student* student = new Student();
                                Order* order = new Order();
                                Date orderDate = Date();
                                Date returnDate = Date();
                                bool phuchaser = false;
                               

                                Book* bk = new Book();
                                int itemType = 0; // Book


                                cout << ">>>> Your Order ID is: " << orderid << endl;
                                orderid++;

                              
                                cout << "Enter Email: ";
                                cin.ignore();
                                getline(cin, email);
                                cout << "Enter Student Name: ";
                                getline(cin, name);


                                student->setId(id);
                                student->setName(name);
                                student->setEmail(email);

                                cout << "Enter ISBN: ";
                                cin >> isbn;

                                if (book->searchBookByISBN(isbn)) {
                                    cout << "Book found!\n";
                                    bk->setisbn(isbn);                                   
                                }
                                else {
                                    cout << "Book not found!\n";
                                }

                                // Set status of book false if order
                                Book obj = book->getbookobj(isbn);
                                obj.setstatus(false);
                               

                                cout << "Enter Order Date (day month year): ";
                                cin >> day >> month >> year;
                                orderDate.setDay(day);
                                orderDate.setMonth(month);
                                orderDate.setYear(year);

                                cout << "Enter Return Date (day month year): ";
                                cin >> day >> month >> year;
                                returnDate.setDay(day);
                                returnDate.setMonth(month);
                                returnDate.setYear(year);

                                order->issuedBooktoStudent(orderid, phuchaser, itemType, *bk, *student, orderDate, returnDate);
                                
                                orderarray->addOrder(*order);

                                delete student;
                                delete bk;
                                delete order;
                              
                                break;
                            }
                            case 2: {
                                cout << endl;
                                Student* student = new Student();
                                Order* order = new Order();
                                Date orderDate = Date();
                                Date returnDate = Date();
                                bool phuchaser = false;


                                Magazine* mag = new Magazine();
                                int itemType = 2; // Magazine


                                cout << ">>>> Your Order ID is: " << orderid << endl;
                                orderid++;


                                cout << "Enter Email: ";
                                cin.ignore();
                                getline(cin, email);
                                cout << "Enter Student Name: ";
                                getline(cin, name);


                                student->setId(id);
                                student->setName(name);
                                student->setEmail(email);

                                cout << "Enter ISBN: ";
                                cin >> isbn;

                                if (magazine->searchMagazineByISBN(isbn)) {
                                    cout << "Magazine found!\n";
                                    mag->setisbn(isbn);
                                }
                                else {
                                    cout << "Book not found!\n";
                                }

                                // Set status of book false if order
                                Magazine obj = magazine->getmagazineobj(isbn);
                                obj.setstatus(false);


                                cout << "Enter Order Date (day month year): ";
                                cin >> day >> month >> year;
                                orderDate.setDay(day);
                                orderDate.setMonth(month);
                                orderDate.setYear(year);

                                cout << "Enter Return Date (day month year): ";
                                cin >> day >> month >> year;
                                returnDate.setDay(day);
                                returnDate.setMonth(month);
                                returnDate.setYear(year);

                                order->issuedMagazinetoStudent(orderid, phuchaser, itemType, *mag, *student, orderDate, returnDate);

                                orderarray->addOrder(*order);

                                delete student;
                                delete mag;
                                delete order;
                                break;
                            }

                            case 3: {
                                cout << endl;
                                Student* student = new Student();
                                Order* order = new Order();
                                Date orderDate = Date();
                                Date returnDate = Date();
                                bool purchaser = false;

                                Newspaper* newspaper = new Newspaper();
                                int itemType = 3; // Newspaper

                                cout << ">>>> Your Order ID is: " << orderid << endl;
                                orderid++;

                                cout << "Enter Email: ";
                                cin.ignore();
                                getline(cin, email);
                                cout << "Enter Student Name: ";
                                getline(cin, name);

                                student->setId(id);
                                student->setName(name);
                                student->setEmail(email);

                                cout << "Enter ISSN: ";
                                cin >> isbn;

                                if (news->searchNewspaperByISBN(isbn)) {
                                    cout << "Newspaper found!\n";
                                    newspaper->setisbn(isbn);
                                }
                                else {
                                    cout << "Newspaper not found!\n";
                                }

                                // Set status of newspaper false if ordered
                                Newspaper obj = news->getnewspaperobj(isbn);
                                obj.setstatus(false);

                                cout << "Enter Order Date (day month year): ";
                                cin >> day >> month >> year;
                                orderDate.setDay(day);
                                orderDate.setMonth(month);
                                orderDate.setYear(year);

                                cout << "Enter Return Date (day month year): ";
                                cin >> day >> month >> year;
                                returnDate.setDay(day);
                                returnDate.setMonth(month);
                                returnDate.setYear(year);

                                order->issuedNewspapertoStudent(orderid, purchaser, itemType, *newspaper, *student, orderDate, returnDate);

                                orderarray->addOrder(*order);

                                delete student;
                                delete newspaper;
                                delete order;
                                break;
                                break;
                            }

                            case 4: {
                                cout << endl;
                                Student* student = new Student();
                                Order* order = new Order();
                                Date orderDate = Date();
                                Date returnDate = Date();
                                bool purchaser = false;

                                Journal* jar = new Journal();
                                int itemType = 1; // Journal

                                cout << ">>>> Your Order ID is: " << orderid << endl;
                                orderid++;

                                cout << "Enter Email: ";
                                cin.ignore();
                                getline(cin, email);
                                cout << "Enter Student Name: ";
                                getline(cin, name);

                                student->setId(id);
                                student->setName(name);
                                student->setEmail(email);

                                cout << "Enter ISBN: ";
                                cin >> isbn;

                                if (journal->searchJournalByISBN(isbn)) {
                                    cout << "Journal found!\n";
                                    jar->setisbn(isbn);
                                }
                                else {
                                    cout << "Journal not found!\n";
                                }

                                // Set status of journal false if ordered
                                Journal obj = journal->getjournalobj(isbn);
                                obj.setstatus(false);

                                cout << "Enter Order Date (day month year): ";
                                cin >> day >> month >> year;
                                orderDate.setDay(day);
                                orderDate.setMonth(month);
                                orderDate.setYear(year);

                                cout << "Enter Return Date (day month year): ";
                                cin >> day >> month >> year;
                                returnDate.setDay(day);
                                returnDate.setMonth(month);
                                returnDate.setYear(year);

                                order->issuedJournaltoStudent(orderid, purchaser, itemType, *jar, *student, orderDate, returnDate);

                                orderarray->addOrder(*order);

                                delete student;
                                delete journal;
                                delete order;
                                break;
                                
                            }
                            case 0:
                                cout << "Logging out..." << endl;
                                loggedIn = 0;
                                break;
                            default:
                                cout << "Invalid choice. Please try again." << endl;
                            }
                        }
                    }
                    else {
                        cout << "ID not found!!" << endl;
                    }
                    break;
                }//login
                case 2:
                {
                    cout << endl;
                    Student* student = new Student();

                    cout << "Enter Student ID: ";
                    cin >> id;


                    cout << "Enter Student Name: ";
                    cin.ignore();
                    getline(cin, name);

                    cout << "Enter Email: ";
                    getline(cin, email);

                    student->setId(id);
                    student->setName(name);
                    student->setEmail(email);

                    stdarray->addStudent(*student);

                    cout << "Signup successfully!" << endl;
                    delete student;

                    break;
                }//Signup              
                case 3: // Search
                {
                    cout << endl;
                    int subchoice = -1;
                    while (subchoice != 0)
                    {
                        cout << "\n--- Item Menu ---" << endl;
                        cout << "1. Book" << endl;
                        cout << "2. Journal" << endl;
                        cout << "3. Magazine" << endl;
                        cout << "4. Newspaper" << endl;
                        cout << "0. Back to Student Portal" << endl;
                        cout << "Enter your choice: ";
                        cin >> subchoice;
                        int isbn = 0;
                        switch (subchoice) {
                        case 1:
                            cout << "Please enter Book ISBN: ";
                            cin >> isbn;
                            book->searchBook(isbn);
                            break;
                        case 2:
                            cout << "Please enter Journal ISBN: ";
                            cin >> isbn;
                            journal->searchjournal(isbn);
                            break;
                        case 3:
                            cout << "Please enter Magazine ISBN: ";
                            cin >> isbn;
                            magazine->searchmagazine(isbn);
                            break;
                        case 4:
                            cout << "Please enter Newspaper ISBN: ";
                            cin >> isbn;
                            news->searchnewspaper(isbn);
                            break;
                        case 0:
                            cout << "Returning to Student Portal..." << endl;
                            break;
                        default:
                            cout << "Invalid choice. Please try again." << endl;
                        }
                    }
                    break;
                }
                case 4: // All available
                {
                    cout << endl;
                    int subchoice = -1;
                    while (subchoice != 0)
                    {
                        cout << "\n--- Item Menu ---" << endl;
                        cout << "1. Book" << endl;
                        cout << "2. Journal" << endl;
                        cout << "3. Magazine" << endl;
                        cout << "4. Newspaper" << endl;
                        cout << "0. Back to Student Portal" << endl;
                        cout << "Enter your choice: ";
                        cin >> subchoice;
                        switch (subchoice) {
                        case 1:
                            cout << endl;
                            book->printreturnBook();
                            break;
                        case 2:
                            cout << endl;
                            journal->printreturnJournals();
                            break;
                        case 3:
                            cout << endl;
                            magazine->printreturnMagazines();
                            break;
                        case 4:
                            cout << endl;
                            news->printreturnNewspaper();
                            break;
                        case 0:
                            cout << "Returning to Student Portal..." << endl;
                            break;
                        default:
                            cout << "Invalid choice. Please try again." << endl;
                        }
                    }
                    break;
                }


                case 0:
                    cout << endl;
                    cout << "Returning to Main Menu..." << endl;
                    break;
                default:
                    cout << endl;
                    cout << "Invalid choice. Please try again." << endl;
                }
            }
            
            break;
        }

            //Faculty portal
        case 2:
        {
            cout << endl;
            int facultyChoice = -1;
            while (facultyChoice != 0) {
                cout << endl;
                cout << "\n--- Faculty Portal ---" << endl;
                cout << endl;
                cout << "1. Login" << endl;
                cout << "2. Signup" << endl;
                cout << "3. Search (Book, Magazine, Newspaper, Journal)" << endl;
                cout << "4. Check all available (Book, Magazine, Newspaper, Journal)" << endl;
                cout << "0. Back to Main Menu" << endl;
                cout << "Enter your choice: ";
                cin >> facultyChoice;
                cout << endl;
                switch (facultyChoice) {
                case 1:
                {
                    cout << endl;
                    bool found = false;
                    cout << "Enter Faculty ID: ";
                    cin >> id;
                    found = ftdarray->searchFacultyById(id);

                    cout << endl;
                    if (found) {


                        int loggedIn = -1;
                        int logchoice = -1;
                        while (loggedIn != 0) {
                            cout << "1. Order Book" << endl;
                            cout << "2. Order Magazine" << endl;
                            cout << "3. Order Newspaper" << endl;
                            cout << "4. Order Journal" << endl;
                            cout << "0. Logout" << endl;
                            cout << "Enter your choice: ";
                            cin >> logchoice;
                            cout << endl;

                            switch (logchoice) {
                            case 1: {

                                cout << endl;

                                Faculty* fac = new Faculty();
                                Order* order = new Order();
                                Date orderDate = Date();
                                Date returnDate = Date();
                                bool phuchaser = true;


                                Book* bk = new Book();
                                int itemType = 0; // Book


                                cout << ">>>> Your Order ID is: " << orderid << endl;
                                orderid++;


                                cout << "Enter Email: ";
                                cin.ignore();
                                getline(cin, email);
                                cout << "Enter Faculty Name: ";
                                getline(cin, name);


                                fac->setId(id);
                                fac->setName(name);
                                fac->setEmail(email);

                                cout << "Enter ISBN: ";
                                cin >> isbn;

                                if (book->searchBookByISBN(isbn)) {
                                    cout << "Book found!\n";
                                    bk->setisbn(isbn);
                                }
                                else {
                                    cout << "Book not found!\n";
                                }

                                // Set status of book false if order
                                Book obj = book->getbookobj(isbn);
                                obj.setstatus(false);


                                cout << "Enter Order Date (day month year): ";
                                cin >> day >> month >> year;
                                orderDate.setDay(day);
                                orderDate.setMonth(month);
                                orderDate.setYear(year);

                                cout << "Enter Return Date (day month year): ";
                                cin >> day >> month >> year;
                                returnDate.setDay(day);
                                returnDate.setMonth(month);
                                returnDate.setYear(year);

                                order->issuedBooktoFaculty(orderid, phuchaser, itemType, *bk, *fac, orderDate, returnDate);

                                orderarray->addOrder(*order);

                                delete fac;
                                delete bk;
                                delete order;

                                break;
                            }
                            case 2: {
                                cout << endl;
                                Faculty* fac = new Faculty();
                                Order* order = new Order();
                                Date orderDate = Date();
                                Date returnDate = Date();
                                bool phuchaser = true;


                                Magazine* mag = new Magazine();
                                int itemType = 2; // Magazine


                                cout << ">>>> Your Order ID is: " << orderid << endl;
                                orderid++;


                                cout << "Enter Email: ";
                                cin.ignore();
                                getline(cin, email);
                                cout << "Enter Faculty Name: ";
                                getline(cin, name);


                                fac->setId(id);
                                fac->setName(name);
                                fac->setEmail(email);


                                cout << "Enter ISBN: ";
                                cin >> isbn;

                                if (magazine->searchMagazineByISBN(isbn)) {
                                    cout << "Magazine found!\n";
                                    mag->setisbn(isbn);
                                }
                                else {
                                    cout << "Book not found!\n";
                                }

                                // Set status of book false if order
                                Magazine obj = magazine->getmagazineobj(isbn);
                                obj.setstatus(false);


                                cout << "Enter Order Date (day month year): ";
                                cin >> day >> month >> year;
                                orderDate.setDay(day);
                                orderDate.setMonth(month);
                                orderDate.setYear(year);

                                cout << "Enter Return Date (day month year): ";
                                cin >> day >> month >> year;
                                returnDate.setDay(day);
                                returnDate.setMonth(month);
                                returnDate.setYear(year);

                                order->issuedMagazinetoFaculty(orderid, phuchaser, itemType, *mag, *fac, orderDate, returnDate);

                                orderarray->addOrder(*order);

                                delete fac;
                                delete mag;
                                delete order;
                                break;
                            }

                            case 3: {
                                cout << endl;
                                Faculty* fac = new Faculty();
                                Order* order = new Order();
                                Date orderDate = Date();
                                Date returnDate = Date();
                                bool phuchaser = true;

                                Newspaper* newspaper = new Newspaper();
                                int itemType = 3; // Newspaper

                                cout << ">>>> Your Order ID is: " << orderid << endl;
                                orderid++;

                                cout << "Enter Email: ";
                                cin.ignore();
                                getline(cin, email);
                                cout << "Enter Faculty Name: ";
                                getline(cin, name);

                                fac->setId(id);
                                fac->setName(name);
                                fac->setEmail(email);


                                cout << "Enter ISSN: ";
                                cin >> isbn;

                                if (news->searchNewspaperByISBN(isbn)) {
                                    cout << "Newspaper found!\n";
                                    newspaper->setisbn(isbn);
                                }
                                else {
                                    cout << "Newspaper not found!\n";
                                }

                                // Set status of newspaper false if ordered
                                Newspaper obj = news->getnewspaperobj(isbn);
                                obj.setstatus(false);

                                cout << "Enter Order Date (day month year): ";
                                cin >> day >> month >> year;
                                orderDate.setDay(day);
                                orderDate.setMonth(month);
                                orderDate.setYear(year);

                                cout << "Enter Return Date (day month year): ";
                                cin >> day >> month >> year;
                                returnDate.setDay(day);
                                returnDate.setMonth(month);
                                returnDate.setYear(year);

                                order->issuedNewspapertoFaculty(orderid, phuchaser, itemType, *newspaper, *fac, orderDate, returnDate);

                                orderarray->addOrder(*order);

                                delete fac;
                                delete newspaper;
                                delete order;
                                break;
                                break;
                            }

                            case 4: {
                                cout << endl;
                                Faculty* fac = new Faculty();
                                Order* order = new Order();
                                Date orderDate = Date();
                                Date returnDate = Date();
                                bool phuchaser = true;

                                Journal* jar = new Journal();
                                int itemType = 1; // Journal

                                cout << ">>>> Your Order ID is: " << orderid << endl;
                                orderid++;

                                cout << "Enter Email: ";
                                cin.ignore();
                                getline(cin, email);
                                cout << "Enter Faculty Name: ";
                                getline(cin, name);

                                fac->setId(id);
                                fac->setName(name);
                                fac->setEmail(email);


                                cout << "Enter ISBN: ";
                                cin >> isbn;

                                if (journal->searchJournalByISBN(isbn)) {
                                    cout << "Journal found!\n";
                                    jar->setisbn(isbn);
                                }
                                else {
                                    cout << "Journal not found!\n";
                                }

                                // Set status of journal false if ordered
                                Journal obj = journal->getjournalobj(isbn);
                                obj.setstatus(false);

                                cout << "Enter Order Date (day month year): ";
                                cin >> day >> month >> year;
                                orderDate.setDay(day);
                                orderDate.setMonth(month);
                                orderDate.setYear(year);

                                cout << "Enter Return Date (day month year): ";
                                cin >> day >> month >> year;
                                returnDate.setDay(day);
                                returnDate.setMonth(month);
                                returnDate.setYear(year);

                                order->issuedJournaltoFaculty(orderid, phuchaser, itemType, *jar, *fac, orderDate, returnDate);

                                orderarray->addOrder(*order);

                                delete fac;
                                delete journal;
                                delete order;
                                break;

                            }
                            case 0:
                                cout << "Logging out..." << endl;
                                loggedIn = 0;
                                break;
                            default:
                                cout << "Invalid choice. Please try again." << endl;
                            }
                        }
                    }
                    else {
                        cout << "ID not found!!" << endl;
                    }
                    break;
                }//login
                case 2:
                {
                    cout << endl;
                    Faculty* fab = new Faculty();

                    cout << "Enter Faculty ID: ";
                    cin >> id;


                    cout << "Enter Faculty Name: ";
                    cin.ignore();
                    getline(cin, name);

                    cout << "Enter Email: ";
                    getline(cin, email);

                    fab->setId(id);
                    fab->setName(name);
                    fab->setEmail(email);

                    ftdarray->addFaculty(*fab);

                    cout << "Signup successfully!" << endl;
                    delete fab;

                    break;
                }//Signup
                case 3:
                {
                    cout << endl;
                    int subchoice = -1;
                    switch (subchoice != 0)
                    {
                        cout << "\n--- Item Menu ---" << endl;
                        cout << "1. Book" << endl;
                        cout << "2. Journal" << endl;
                        cout << "3. Magazine" << endl;
                        cout << "4. Newspaper" << endl;
                        cout << "0. Back to Student Portal" << endl;
                        cout << "Enter your choice: ";
                        cin >> subchoice;
                        int isbn = 0;
                        switch (subchoice) {
                        case 1:
                        {
                            cout << endl;
                            cout << "Please enter Book ISBN: ";
                            cin >> isbn;
                            book->searchBook(isbn);
                            break;
                        }

                        case 2:
                            cout << endl;
                            cout << "Please enter Journal ISBN: ";
                            cin >> isbn;
                            journal->searchjournal(isbn);
                            break;
                        case 3:
                            cout << endl;
                            cout << "Please enter Magazine ISBN: ";
                            cin >> isbn;
                            magazine->searchmagazine(isbn);
                            break;
                        case 4:
                            cout << endl;
                            cout << "Please enter Newspaper ISBN: ";
                            cin >> isbn;
                            news->searchnewspaper(isbn);
                            break;
                        case 0:
                            cout << endl;
                            cout << "Returning to Faculty Portal..." << endl;
                            break;
                        default:
                            cout << endl;
                            cout << "Invalid choice. Please try again." << endl;
                        }
                        break;
                    }
                    break;
                }//Search
                case 4:
                {
                    cout << endl;
                    int subchoice = -1;
                    switch (subchoice != 0)
                    {
                        cout << "\n--- Item Menu ---" << endl;
                        cout << "1. Book" << endl;
                        cout << "2. Journal" << endl;
                        cout << "3. Magazine" << endl;
                        cout << "4. Newspaper" << endl;
                        cout << "0. Back to Student Portal" << endl;
                        cout << "Enter your choice: ";
                        cin >> subchoice;
                        int isbn = 0;
                        switch (subchoice) {
                        case 1:
                        {
                            cout << endl;
                            book->printreturnBook();
                            break;
                        }

                        case 2:
                            cout << endl;
                            journal->printreturnJournals();
                            break;
                        case 3:
                            cout << endl;
                            magazine->printreturnMagazines();
                            break;
                        case 4:
                            cout << endl;
                            news->printreturnNewspaper();
                            break;
                        case 0:
                            cout << endl;
                            cout << "Returning to Faculty Portal..." << endl;
                            break;
                        default:
                            cout << endl;
                            cout << "Invalid choice. Please try again." << endl;
                        }
                        break;
                    }
                    break;
                }//All available
                case 0:
                    cout << endl;
                    cout << "Returning to Main Menu..." << endl;
                    break;
                default:
                    cout << endl;
                    cout << "Invalid choice. Please try again." << endl;
                }
            }
            facultyChoice = -1;
            break;
        }
  
             //Admin portal
        case 3:
        {
            int facultyChoice = -1;
            while (facultyChoice != 0) {
                cout << endl;
                cout << "\n--- Admin Portal ---" << endl;
                cout << endl;
                cout << "1. For Student Details" << endl;
                cout << "2. For Faculty Details" << endl;
                cout << "3. For Admin Details" << endl;
                cout << "4. For Document Details" << endl;                
                cout << "5. For Order Details" << endl;
                cout << "6. For Returned" << endl;
                cout << "0. Back to Main Menu" << endl;
                cout << "Enter your choice: ";
                cin >> facultyChoice;
                cout << endl;
                switch (facultyChoice) {
                case 1: // for Students
                {
                    cout << endl;
                    Student* std = new Student();
                    int choice = -1;
                    int id = -1;
                    string name, email;
                    while (choice != 0) {
                        cout << "Menu:\n";
                        cout << "1. Add student\n";
                        cout << "2. Search student by ID\n";
                        cout << "3. Update student by ID\n";
                        cout << "4. Delete student by ID\n";
                        cout << "5. Print all students\n";
                        cout << "0. Exit\n";
                        cout << "Enter your choice: ";
                        cin >> choice;
                        cout << endl;
                        switch (choice) {
                        case 1:
                        {
                            cout << endl;
                            cout << "Enter Student ID: ";
                            cin >> id;
                            cin.ignore();

                            cout << "Enter Student Name: ";
                            getline(cin, name);

                            cout << "Enter Email: ";
                            getline(cin, email);

                            std->setId(id);
                            std->setName(name);
                            std->setEmail(email);

                            stdarray->addStudent(*std);
                            cout << "Added SuccessFull" << endl;
                            delete std;
                            break;
                        }

                        case 2:
                        {
                            cout << endl;
                            cout << "Enter student ID to search: ";
                            cin >> id;
                            if (stdarray->searchStudentById(id)) {
                                cout << "Student found!\n";
                            }
                            else {
                                cout << "Student not found!\n";
                            }
                            
                            break;
                        }

                        case 3:
                        {
                            cout << endl;
                            std = new Student();
                            cout << "Enter Student ID: ";
                            cin >> id;
                            cin.ignore();

                            cout << "Enter Student Name: ";
                            getline(cin, name);

                            std->setId(id);
                            std->setName(name);
                         
                            stdarray->updateStudentById(id, *std);
                            delete std;
                            break;
                        }
                        case 4:
                        {
                            cout << endl;
                            cout << "Enter student ID to delete: ";
                            cin >> id;
                            stdarray->deleteStudentById(id);
                            break;
                        }
                        case 5:
                        {
                            cout << endl;
                            stdarray->printAllStudents();
                            break;
                        }

                        case 0:
                        {
                            break;
                        }

                        default:
                            cout << endl;
                            cout << "Invalid choice. Try again.\n";
                        }
                        
                        
                    }
                    break;
                }
                case 2:// for Faculty
                {
                    cout << endl;
                    Faculty* fac = new Faculty();

                    int choice = -1;
                    int id = -1;
                    string name, email;

                    while (choice != 0) {
                        cout << "Menu:\n";
                        cout << "1. Add faculty\n";
                        cout << "2. Search faculty by ID\n";
                        cout << "3. Update faculty by ID\n";
                        cout << "4. Delete faculty by ID\n";
                        cout << "5. Print all faculty\n";
                        cout << "0. Exit\n";
                        cout << "Enter your choice: ";
                        cin >> choice;

                        switch (choice) {
                        case 1: {
                            cout << endl;
                            cout << "Enter Faculty ID: ";
                            cin >> id;
                            cin.ignore();

                            cout << "Enter Faculty Name: ";
                            getline(cin, name);

                            cout << "Enter Faculty Email: ";
                            getline(cin, email);

                            fac->setId(id);
                            fac->setName(name);
                            fac->setEmail(email);

                            ftdarray->addFaculty(*fac);
                            delete fac;
                           
                            break;
                        }

                        case 2: {
                            cout << endl;
                            cout << "Enter faculty ID to search: ";
                            cin >> id;
                            if (ftdarray->searchFacultyById(id)) {
                                cout << "Faculty found!\n";
                            }
                            else {
                                cout << "Faculty not found!\n";
                            }
                            break;
                        }

                        case 3: {
                            cout << endl;
                            cout << "Enter Faculty ID: ";
                            cin >> id;
                            cin.ignore();

                            cout << "Enter Faculty Name: ";
                            getline(cin, name);

                            fac->setId(id);
                            fac->setName(name);

                            ftdarray->updateFacultyById(id, *fac);
                            delete fac;
                            break;
                        }

                        case 4: {
                            cout << endl;
                            cout << "Enter faculty ID to delete: ";
                            cin >> id;
                            ftdarray->deleteFacultyById(id);
                            break;
                        }

                        case 5: {
                            cout << endl;
                            ftdarray->printAllFaculties();
                            break;
                        }
                        case 0:
                        {
                            break;
                        }

                        default:
                            cout << endl;
                            cout << "Invalid choice. Try again.\n";
                        }
                        
                    }
                    break;
                }
                case 3:
                {
                    cout << endl;
                    Admin* adm = new Admin();
                    int choice = -1;
                    int id = -1;
                    string name, email;

                    while (choice != 0) {
                        cout << "Menu:\n";
                        cout << "1. Add admin\n";
                        cout << "2. Search admin by ID\n";
                        cout << "3. Update admin by ID\n";
                        cout << "4. Delete admin by ID\n";
                        cout << "5. Print all admins\n";
                        cout << "0. Exit\n";
                        cout << "Enter your choice: ";
                        cin >> choice;
                        cout << endl;

                        switch (choice) {
                        case 1:
                        {
                            cout << endl;
                            cout << "Enter Admin ID: ";
                            cin >> id;
                            cin.ignore();

                            cout << "Enter Admin Name: ";
                            getline(cin, name);

                            cout << "Enter Email: ";
                            getline(cin, email);

                            adm->setId(id);
                            adm->setName(name);
                            adm->setEmail(email);

                            adminarray->addAdmin(*adm);
                            cout << "Added Successfully" << endl;
                            delete adm;
                            break;
                        }

                        case 2:
                        {
                            cout << endl;
                            cout << "Enter admin ID to search: ";
                            cin >> id;
                            if (adminarray->searchAdminById(id)) {
                                cout << "Admin found!\n";
                            }
                            else {
                                cout << "Admin not found!\n";
                            }
                            break;
                        }

                        case 3:
                        {
                            cout << endl;
                            adm = new Admin();
                            cout << "Enter Admin ID: ";
                            cin >> id;
                            cin.ignore();

                            cout << "Enter Admin Name: ";
                            getline(cin, name);

                            adm->setId(id);
                            adm->setName(name);

                            adminarray->updateAdminById(id, *adm);
                            delete adm;
                            break;
                        }

                        case 4:
                        {
                            cout << endl;
                            cout << "Enter admin ID to delete: ";
                            cin >> id;
                            adminarray->deleteAdminById(id);
                            break;
                        }

                        case 5:
                        {
                            cout << endl;
                            adminarray->printAllAdmins();
                            break;
                        }

                        case 0:
                        {
                            break;
                        }

                        default:
                            cout << endl;
                            cout << "Invalid choice. Try again.\n";
                        }
                    }

                    break;
                }
                case 4: // for Document
                {
                    int choice = -1;
                    cout << endl;
                    while (choice != 0) {
                        cout << endl;
                        cout << "Document Menu:\n";
                        cout << "1. Books\n";
                        cout << "2. Magazines\n";
                        cout << "3. Journals\n";
                        cout << "4. Newspapers\n";
                        cout << "0. Exit\n";
                        cout << "Enter your choice: ";
                        cin >> choice;
                        cout << endl;
                        switch (choice) {
                        case 1:
                        {
                            Book* bk = new Book();
                            int choice = -1, isbn = -1, yearofp = -1, librarycode = -1, pages = -1;
                            string name, author;
                            bool status;

                            while (choice != 0) {
                                cout << "Books Menu:\n";
                                cout << "1. Add Book\n";
                                cout << "2. Search Book by ISBN\n";
                                cout << "3. Update Book by ISBN\n";
                                cout << "4. Delete Book by ISBN\n";
                                cout << "5. Print Ordered Books (Not Available)\n";
                                cout << "6. Print Returned Books (Available)\n";
                                cout << "7. Print All Books\n";
                                cout << "0. Exit\n";
                                cout << "Enter your choice: ";
                                cin >> choice;

                                switch (choice) {
                                case 1: {
                                    cout << endl;
                                    cout << "Enter Book ISBN: ";
                                    cin >> isbn;
                                    cin.ignore();

                                    cout << "Enter Book Name: ";
                                    getline(cin, name);

                                    cout << "Enter Author Name: ";
                                    getline(cin, author);

                                    cout << "Enter Year of Publication: ";
                                    cin >> yearofp;

                                    cout << "Enter Library Code: ";
                                    cin >> librarycode;

                                    cout << "Enter Number of Pages: ";
                                    cin >> pages;

                                    cout << "Enter Status (1 for Available, 0 for Not Available): ";
                                    cin >> status;

                                    bk->setisbn(isbn);
                                    bk->setname(name);
                                    bk->setauthor(author);
                                    bk->setyearofp(yearofp);
                                    bk->setlibrarycode(librarycode);
                                    bk->setpages(pages);
                                    bk->setstatus(status);

                                    book->addBook(*bk);                                  
                                    break;
                                }

                                case 2: {
                                    cout << endl;
                                    cout << "Enter Book ISBN to search: ";
                                    cin >> isbn;
                                    if (book->searchBookByISBN(isbn)) {
                                        cout << "Book found!\n";
                                    }
                                    else {
                                        cout << "Book not found!\n";
                                    }
                                    break;
                                }

                                case 3: {
                                  
                                    
                                    cout << endl;
                                    cout << "Enter New Book Name: ";
                                    cin.ignore();
                                    getline(cin, name);

                                    cout << "Enter New Author Name: ";
                                    getline(cin, author);

                                    cout << "Enter New Year of Publication: ";
                                    cin >> yearofp;

                                    cout << "Enter New Library Code: ";
                                    cin >> librarycode;

                                    cout << "Enter New Number of Pages: ";
                                    cin >> pages;

                                    cout << "Enter New Status (1 for Available, 0 for Not Available): ";
                                    cin >> status;

                                    
                                    bk->setname(name);
                                    bk->setauthor(author);
                                    bk->setyearofp(yearofp);
                                    bk->setlibrarycode(librarycode);
                                    bk->setpages(pages);
                                    bk->setstatus(status);

                                    
                                    book->updateBookByISBN(isbn, *bk);
                                    delete book;
                                    break;
                                }

                                case 4: {
                                    cout << endl;
                                    cout << "Enter Book ISBN to delete: ";
                                    cin >> isbn;
                                    book->deleteBookByISBN(isbn);
                                    break;
                                }

                                case 5: {
                                    cout << endl;
                                    book->printOrderedBook();  // Books with status == false (Not Available)
                                    break;
                                }

                                case 6: {
                                    cout << endl;
                                    book->printreturnBook();  // Books with status == true (Available)
                                    break;
                                }

                                case 7: {
                                    cout << endl;
                                    book->printAllBooks();
                                    break;
                                }

                                default:
                                    if (choice != 0) {
                                        cout << "Invalid choice. Try again.\n";
                                    }
                                }
                            }

                            
                            break;

                        }
                        case 2:
                        {
                            cout << endl;
                            Magazine* mgz = new Magazine();
                            int choice = -1, isbn = -1, yearofp = -1, librarycode = -1, issueNumber = -1;
                            string name, author;
                            bool status;

                            while (choice != 0) {
                                cout << "Magazines Menu:\n";
                                cout << "1. Add Magazine\n";
                                cout << "2. Search Magazine by ISBN\n";
                                cout << "3. Update Magazine by ISBN\n";
                                cout << "4. Delete Magazine by ISBN\n";
                                cout << "5. Print Ordered Magazines (Not Available)\n";
                                cout << "6. Print Returned Magazines (Available)\n";
                                cout << "7. Print All Magazines\n";
                                cout << "0. Exit\n";
                                cout << "Enter your choice: ";
                                cin >> choice;
                                cout << endl;
                                switch (choice) {
                                case 1: {
                                    cout << endl;
                                    cout << "Enter Magazine ISBN: ";
                                    cin >> isbn;
                                    cin.ignore();

                                    cout << "Enter Magazine Name: ";
                                    getline(cin, name);

                                    cout << "Enter Author/Editor Name: ";
                                    getline(cin, author);

                                    cout << "Enter Year of Publication: ";
                                    cin >> yearofp;

                                    cout << "Enter Library Code: ";
                                    cin >> librarycode;

                                    cout << "Enter Issue Number: ";
                                    cin >> issueNumber;

                                    cout << "Enter Status (1 for Available, 0 for Not Available): ";
                                    cin >> status;

                                    mgz->setisbn(isbn);
                                    mgz->setname(name);
                                    mgz->setauthor(author);
                                    mgz->setyearofp(yearofp);
                                    mgz->setlibrarycode(librarycode);
                                    mgz->setissueNumber(issueNumber);
                                    mgz->setstatus(status);

                                    magazine->addMagazine(*mgz);
                                    break;
                                }

                                case 2: {
                                    cout << endl;
                                    cout << "Enter Magazine ISBN to search: ";
                                    cin >> isbn;
                                    if (magazine->searchMagazineByISBN(isbn)) {
                                        cout << "Magazine found!\n";
                                    }
                                    else {
                                        cout << "Magazine not found!\n";
                                    }
                                    break;
                                }

                                case 3: {
                                    cout << endl;
                                    cout << "Enter New Magazine Name: ";
                                    cin.ignore();
                                    getline(cin, name);

                                    cout << "Enter New Author/Editor Name: ";
                                    getline(cin, author);

                                    cout << "Enter New Year of Publication: ";
                                    cin >> yearofp;

                                    cout << "Enter New Library Code: ";
                                    cin >> librarycode;

                                    cout << "Enter New Issue Number ";
                                    cin >> pages;

                                    cout << "Enter New Status (1 for Available, 0 for Not Available): ";
                                    cin >> status;

                                    mgz->setname(name);
                                    mgz->setauthor(author);
                                    mgz->setyearofp(yearofp);
                                    mgz->setlibrarycode(librarycode);
                                    mgz->setissueNumber(issueNumber);
                                    mgz->setstatus(status);

                                    magazine->updateMagazineByISBN(isbn, *mgz);
                                    delete mgz;
                                    break;
                                }

                                case 4: {
                                    cout << endl;
                                    cout << "Enter Magazine ISBN to delete: ";
                                    cin >> isbn;
                                    magazine->deleteMagazineByISBN(isbn);
                                    break;
                                }

                                case 5: {
                                    cout << endl;
                                    magazine->printOrderedMagazines();  // Magazines with status == false (Not Available)
                                    break;
                                }

                                case 6: {
                                    cout << endl;
                                    magazine->printreturnMagazines();  // Magazines with status == true (Available)
                                    break;
                                }

                                case 7: {
                                    cout << endl;
                                    magazine->printAllMagazines();
                                    break;
                                }

                                default:
                                    if (choice != 0) {
                                        cout << endl;
                                        cout << "Invalid choice. Try again.\n";
                                    }
                                }
                            }

                            ;
                            break;
                        }                           
                        case 3:
                        {
                            cout << endl;
                            Journal* jrnl = new Journal();
                            int choice = -1, isbn = -1, yearofp = -1, librarycode = -1;
                            string name, author, volume;
                            bool status;

                            while (choice != 0) {
                                cout << "Journals Menu:\n";
                                cout << "1. Add Journal\n";
                                cout << "2. Search Journal by ISBN\n";
                                cout << "3. Update Journal by ISBN\n";
                                cout << "4. Delete Journal by ISBN\n";
                                cout << "5. Print Ordered Journals (Not Available)\n";
                                cout << "6. Print Returned Journals (Available)\n";
                                cout << "7. Print All Journals\n";
                                cout << "0. Exit\n";
                                cout << "Enter your choice: ";
                                cin >> choice;
                                cout << endl;
                                switch (choice) {
                                case 1: {
                                    cout << endl;
                                    cout << "Enter Journal ISBN: ";
                                    cin >> isbn;
                                    cin.ignore();

                                    cout << "Enter Journal Name: ";
                                    getline(cin, name);

                                    cout << "Enter Author/Editor Name: ";
                                    getline(cin, author);

                                    cout << "Enter Year of Publication: ";
                                    cin >> yearofp;

                                    cout << "Enter Library Code: ";
                                    cin >> librarycode;

                                    cout << "Enter Number of Voulmn: ";
                                    getline(cin, volume);

                                    cout << "Enter Status (1 for Available, 0 for Not Available): ";
                                    cin >> status;

                                    jrnl->setisbn(isbn);
                                    jrnl->setname(name);
                                    jrnl->setauthor(author);
                                    jrnl->setyearofp(yearofp);
                                    jrnl->setlibrarycode(librarycode);
                                    jrnl->setvolume(volume);
                                    jrnl->setstatus(status);

                                    journal->addJournal(*jrnl);
                                    break;
                                }

                                case 2: {
                                    cout << endl;
                                    cout << "Enter Journal ISBN to search: ";
                                    cin >> isbn;
                                    if (journal->searchJournalByISBN(isbn)) {
                                        cout << "Journal found!\n";
                                    }
                                    else {
                                        cout << "Journal not found!\n";
                                    }
                                    break;
                                }

                                case 3: {
                                    cout << endl;
                                    cout << "Enter New Journal Name: ";
                                    cin.ignore();
                                    getline(cin, name);

                                    cout << "Enter New Author/Editor Name: ";
                                    getline(cin, author);

                                    cout << "Enter New Year of Publication: ";
                                    cin >> yearofp;

                                    cout << "Enter New Library Code: ";
                                    cin >> librarycode;

                                    cout << "Enter New Number of Pages: ";
                                    cin >> pages;

                                    cout << "Enter New Status (1 for Available, 0 for Not Available): ";
                                    cin >> status;

                                    jrnl->setname(name);
                                    jrnl->setauthor(author);
                                    jrnl->setyearofp(yearofp);
                                    jrnl->setlibrarycode(librarycode);
                                    jrnl->setvolume(volume);
                                    jrnl->setstatus(status);

                                    journal->updateJournalByISBN(isbn, *jrnl);
                                    delete jrnl;
                                    break;
                                }

                                case 4: {
                                    cout << endl;
                                    cout << "Enter Journal ISBN to delete: ";
                                    cin >> isbn;
                                    journal->deleteJournalByISBN(isbn);
                                    break;
                                }

                                case 5: {
                                    cout << endl;
                                    journal->printOrderedJournals();  // Journals with status == false (Not Available)
                                    break;
                                }

                                case 6: {
                                    cout << endl;
                                    journal->printreturnJournals();  // Journals with status == true (Available)
                                    break;
                                }

                                case 7: {
                                    cout << endl;
                                    journal->printAllJournals();
                                    break;
                                }

                                default:
                                    if (choice != 0) {
                                        cout << "Invalid choice. Try again.\n";
                                    }
                                }
                            }

                            
                            break;
                        }                           
                        case 4:
                        {
                            cout << endl;
                            Newspaper* np = new Newspaper();
                            int choice = -1, isbn = -1, yearofp = -1, librarycode = -1;
                            string name, publisher, edition;
                            bool status;

                            while (choice != 0) {
                                cout << "Newspapers Menu:\n";
                                cout << "1. Add Newspaper\n";
                                cout << "2. Search Newspaper by ISBN\n";
                                cout << "3. Update Newspaper by ISBN\n";
                                cout << "4. Delete Newspaper by ISBN\n";
                                cout << "5. Print Ordered Newspapers (Not Available)\n";
                                cout << "6. Print Returned Newspapers (Available)\n";
                                cout << "7. Print All Newspapers\n";
                                cout << "0. Exit\n";
                                cout << "Enter your choice: ";
                                cin >> choice;
                                cout << endl;
                                switch (choice) {
                                case 1: {
                                    cout << endl;
                                    cout << "Enter Newspaper ISBN: ";
                                    cin >> isbn;
                                    cin.ignore();

                                    cout << "Enter Newspaper Name: ";
                                    getline(cin, name);

                                    cout << "Enter Edition Name: ";
                                    getline(cin, edition);

                                    cout << "Enter Year of Publication: ";
                                    cin >> yearofp;

                                    cout << "Enter Library Code: ";
                                    cin >> librarycode;


                                    cout << "Enter Status (1 for Available, 0 for Not Available): ";
                                    cin >> status;

                                    np->setisbn(isbn);
                                    np->setname(name);
                                    np->setyearofp(yearofp);
                                    np->setlibrarycode(librarycode);
                                    np->setedition(edition);
                                    np->setstatus(status);

                                    news->addNewspaper(*np);
                                    break;
                                }

                                case 2: {
                                    cout << endl;
                                    cout << "Enter Newspaper ISBN to search: ";
                                    cin >> isbn;
                                    if (news->searchNewspaperByISBN(isbn)) {
                                        cout << "Newspaper found!\n";
                                    }
                                    else {
                                        cout << "Newspaper not found!\n";
                                    }
                                    break;
                                }

                                case 3: {
                                    cout << endl;
                                    cout << "Enter New Newspaper Name: ";
                                    cin.ignore();
                                    getline(cin, name);

                                    cout << "Enter New Publisher Name: ";
                                    getline(cin, publisher);

                                    cout << "Enter New Year of Publication: ";
                                    cin >> yearofp;

                                    cout << "Enter New Library Code: ";
                                    cin >> librarycode;

                                    cout << "Enter New Number of Pages: ";
                                    cin >> pages;

                                    cout << "Enter New Status (1 for Available, 0 for Not Available): ";
                                    cin >> status;

                                  
                                    np->setname(name);
                                    np->setyearofp(yearofp);
                                    np->setlibrarycode(librarycode);
                                    np->setedition(edition);
                                    np->setstatus(status);

                                    news->updateNewspaperByISBN(isbn, *np);
                                    delete np;
                                    break;
                                }

                                case 4: {
                                    cout << endl;
                                    cout << "Enter Newspaper ISBN to delete: ";
                                    cin >> isbn;
                                    news->deleteNewspaperByISBN(isbn);
                                    break;
                                }

                                case 5: {
                                    cout << endl;
                                    news->printOrderedNewspaper();  // Newspapers with status == false (Not Available)
                                    break;
                                }

                                case 6: {
                                    cout << endl;
                                    news->printreturnNewspaper();  // Newspapers with status == true (Available)
                                    break;
                                }

                                case 7: {
                                    cout << endl;
                                    news->printAllNewspapers();
                                    break;
                                }

                                default:
                                    if (choice != 0) {
                                        cout << "Invalid choice. Try again.\n";
                                    }
                                }
                            }

                            
                            break;
                        }
                           
                        case 0:
                            cout << "Exiting...\n";
                            break;
                        default:
                            cout << "Invalid choice. Try again.\n";
                        }
                    }
                    break;
                }
                case 5:
                {
                    int choice = -1;
                    while (choice != 0)
                    {                      
                        cout << "1. Add Order" << endl;
                        cout << "2. Search Order" << endl;
                        cout << "3. Remove Order" << endl;
                        cout << "4. Print all Orders" << endl;
                        cout << "0. Back to Main Menu" << endl;
                        cout << "Enter your choice: ";
                        cin >> choice;
                        switch (choice)
                        {
                        case 1:
                        {
                            cout << endl;
                            int main = -1;
                            while (main != 0)
                            {
                                cout << "1. Add Order For Student" << endl;
                                cout << "2. Add Order For Faculty" << endl;
                                cout << "0. Back to Main Menu" << endl;
                                cout << "Enter your choice: ";
                                cin >> main;
                                switch (main)
                                {
                                case 1:
                                {                                 
                                    cout << endl;
                                        int loggedIn = -1;
                                        int logchoice = -1;
                                        while (loggedIn != 0) {
                                            cout << "1. Order Book" << endl;
                                            cout << "2. Order Magazine" << endl;
                                            cout << "3. Order Newspaper" << endl;
                                            cout << "4. Order Journal" << endl;
                                            cout << "0. Logout" << endl;
                                            cout << "Enter your choice: ";
                                            cin >> logchoice;
                                            cout << endl;

                                            switch (logchoice) {
                                            case 1: {
                                                cout << endl;
                                                Student* student = new Student();
                                                Order* order = new Order();
                                                Date orderDate = Date();
                                                Date returnDate = Date();
                                                bool phuchaser = false;


                                                Book* bk = new Book();
                                                int itemType = 0; // Book


                                                cout << ">>>> Your Order ID is: " << orderid << endl;
                                                orderid++;

                                                cout << "Enter Student ID: ";
                                                cin >> id;
                                                cout << "Enter Email: ";
                                                cin.ignore();
                                                getline(cin, email);
                                                cout << "Enter Student Name: ";
                                                getline(cin, name);


                                                student->setId(id);
                                                student->setName(name);
                                                student->setEmail(email);

                                                cout << "Enter ISBN: ";
                                                cin >> isbn;

                                                if (book->searchBookByISBN(isbn)) {
                                                    cout << "Book found!\n";
                                                    bk->setisbn(isbn);
                                                }
                                                else {
                                                    cout << "Book not found!\n";
                                                }

                                                // Set status of book false if order
                                                Book obj = book->getbookobj(isbn);
                                                obj.setstatus(false);


                                                cout << "Enter Order Date (day month year): ";
                                                cin >> day >> month >> year;
                                                orderDate.setDay(day);
                                                orderDate.setMonth(month);
                                                orderDate.setYear(year);

                                                cout << "Enter Return Date (day month year): ";
                                                cin >> day >> month >> year;
                                                returnDate.setDay(day);
                                                returnDate.setMonth(month);
                                                returnDate.setYear(year);

                                                order->issuedBooktoStudent(orderid, phuchaser, itemType, *bk, *student, orderDate, returnDate);

                                                orderarray->addOrder(*order);

                                                delete student;
                                                delete bk;
                                                delete order;

                                                break;
                                            }
                                            case 2: {
                                                cout << endl;
                                                Student* student = new Student();
                                                Order* order = new Order();
                                                Date orderDate = Date();
                                                Date returnDate = Date();
                                                bool phuchaser = false;


                                                Magazine* mag = new Magazine();
                                                int itemType = 2; // Magazine


                                                cout << ">>>> Your Order ID is: " << orderid << endl;
                                                orderid++;

                                                cout << "Enter Student ID: ";
                                                cin >> id;
                                                cout << "Enter Email: ";
                                                cin.ignore();
                                                getline(cin, email);
                                                cout << "Enter Student Name: ";
                                                getline(cin, name);


                                                student->setId(id);
                                                student->setName(name);
                                                student->setEmail(email);

                                                cout << "Enter ISBN: ";
                                                cin >> isbn;

                                                if (magazine->searchMagazineByISBN(isbn)) {
                                                    cout << "Magazine found!\n";
                                                    mag->setisbn(isbn);
                                                }
                                                else {
                                                    cout << "Book not found!\n";
                                                }

                                                // Set status of book false if order
                                                Magazine obj = magazine->getmagazineobj(isbn);
                                                obj.setstatus(false);


                                                cout << "Enter Order Date (day month year): ";
                                                cin >> day >> month >> year;
                                                orderDate.setDay(day);
                                                orderDate.setMonth(month);
                                                orderDate.setYear(year);

                                                cout << "Enter Return Date (day month year): ";
                                                cin >> day >> month >> year;
                                                returnDate.setDay(day);
                                                returnDate.setMonth(month);
                                                returnDate.setYear(year);

                                                order->issuedMagazinetoStudent(orderid, phuchaser, itemType, *mag, *student, orderDate, returnDate);

                                                orderarray->addOrder(*order);

                                                delete student;
                                                delete mag;
                                                delete order;
                                                break;
                                            }

                                            case 3: {
                                                cout << endl;
                                                Student* student = new Student();
                                                Order* order = new Order();
                                                Date orderDate = Date();
                                                Date returnDate = Date();
                                                bool purchaser = false;

                                                Newspaper* newspaper = new Newspaper();
                                                int itemType = 3; // Newspaper

                                                cout << ">>>> Your Order ID is: " << orderid << endl;
                                                orderid++;

                                                cout << "Enter Student ID: ";
                                                cin >> id;
                                                cout << "Enter Email: ";
                                                cin.ignore();
                                                getline(cin, email);
                                                cout << "Enter Student Name: ";
                                                getline(cin, name);

                                                student->setId(id);
                                                student->setName(name);
                                                student->setEmail(email);

                                                cout << "Enter ISSN: ";
                                                cin >> isbn;

                                                if (news->searchNewspaperByISBN(isbn)) {
                                                    cout << "Newspaper found!\n";
                                                    newspaper->setisbn(isbn);
                                                }
                                                else {
                                                    cout << "Newspaper not found!\n";
                                                }

                                                // Set status of newspaper false if ordered
                                                Newspaper obj = news->getnewspaperobj(isbn);
                                                obj.setstatus(false);

                                                cout << "Enter Order Date (day month year): ";
                                                cin >> day >> month >> year;
                                                orderDate.setDay(day);
                                                orderDate.setMonth(month);
                                                orderDate.setYear(year);

                                                cout << "Enter Return Date (day month year): ";
                                                cin >> day >> month >> year;
                                                returnDate.setDay(day);
                                                returnDate.setMonth(month);
                                                returnDate.setYear(year);

                                                order->issuedNewspapertoStudent(orderid, purchaser, itemType, *newspaper, *student, orderDate, returnDate);

                                                orderarray->addOrder(*order);

                                                delete student;
                                                delete newspaper;
                                                delete order;
                                                break;
                                                break;
                                            }

                                            case 4: {
                                                cout << endl;
                                                Student* student = new Student();
                                                Order* order = new Order();
                                                Date orderDate = Date();
                                                Date returnDate = Date();
                                                bool purchaser = false;

                                                Journal* jar = new Journal();
                                                int itemType = 1; // Journal

                                                cout << ">>>> Your Order ID is: " << orderid << endl;
                                                orderid++;

                                                cout << "Enter Student ID: ";
                                                cin >> id;
                                                cout << "Enter Email: ";
                                                cin.ignore();
                                                getline(cin, email);
                                                cout << "Enter Student Name: ";
                                                getline(cin, name);

                                                student->setId(id);
                                                student->setName(name);
                                                student->setEmail(email);

                                                cout << "Enter ISBN: ";
                                                cin >> isbn;

                                                if (journal->searchJournalByISBN(isbn)) {
                                                    cout << "Journal found!\n";
                                                    jar->setisbn(isbn);
                                                }
                                                else {
                                                    cout << "Journal not found!\n";
                                                }

                                                // Set status of journal false if ordered
                                                Journal obj = journal->getjournalobj(isbn);
                                                obj.setstatus(false);

                                                cout << "Enter Order Date (day month year): ";
                                                cin >> day >> month >> year;
                                                orderDate.setDay(day);
                                                orderDate.setMonth(month);
                                                orderDate.setYear(year);

                                                cout << "Enter Return Date (day month year): ";
                                                cin >> day >> month >> year;
                                                returnDate.setDay(day);
                                                returnDate.setMonth(month);
                                                returnDate.setYear(year);

                                                order->issuedJournaltoStudent(orderid, purchaser, itemType, *jar, *student, orderDate, returnDate);

                                                orderarray->addOrder(*order);

                                                delete student;
                                                delete journal;
                                                delete order;
                                                break;

                                            }
                                            case 0:
                                                cout << "Logging out..." << endl;
                                                loggedIn = 0;
                                                break;
                                            default:
                                                cout << "Invalid choice. Please try again." << endl;
                                            }
                                        
                                        }
                                    
                                    break;
                                }
                                case 2:
                                {
                                 
                                    cout << endl;
                                    


                                        int loggedIn = -1;
                                        int logchoice = -1;
                                        while (loggedIn != 0) {
                                            cout << "1. Order Book" << endl;
                                            cout << "2. Order Magazine" << endl;
                                            cout << "3. Order Newspaper" << endl;
                                            cout << "4. Order Journal" << endl;
                                            cout << "0. Logout" << endl;
                                            cout << "Enter your choice: ";
                                            cin >> logchoice;
                                            cout << endl;

                                            switch (logchoice) {
                                            case 1: {

                                                Faculty* fac = new Faculty();
                                                Order* order = new Order();
                                                Date orderDate = Date();
                                                Date returnDate = Date();
                                                bool phuchaser = true;


                                                Book* bk = new Book();
                                                int itemType = 0; // Book


                                                cout << ">>>> Your Order ID is: " << orderid << endl;
                                                orderid++;

                                                cout << "Enter Faculty ID: ";
                                                cin >> id;
                                                cout << "Enter Email: ";
                                                cin.ignore();
                                                getline(cin, email);
                                                cout << "Enter Faculty Name: ";
                                                getline(cin, name);


                                                fac->setId(id);
                                                fac->setName(name);
                                                fac->setEmail(email);

                                                cout << "Enter ISBN: ";
                                                cin >> isbn;

                                                if (book->searchBookByISBN(isbn)) {
                                                    cout << "Book found!\n";
                                                    bk->setisbn(isbn);
                                                }
                                                else {
                                                    cout << "Book not found!\n";
                                                }

                                                // Set status of book false if order
                                                Book obj = book->getbookobj(isbn);
                                                obj.setstatus(false);


                                                cout << "Enter Order Date (day month year): ";
                                                cin >> day >> month >> year;
                                                orderDate.setDay(day);
                                                orderDate.setMonth(month);
                                                orderDate.setYear(year);

                                                cout << "Enter Return Date (day month year): ";
                                                cin >> day >> month >> year;
                                                returnDate.setDay(day);
                                                returnDate.setMonth(month);
                                                returnDate.setYear(year);

                                                order->issuedBooktoFaculty(orderid, phuchaser, itemType, *bk, *fac, orderDate, returnDate);

                                                orderarray->addOrder(*order);

                                                delete fac;
                                                delete bk;
                                                delete order;

                                                break;
                                            }
                                            case 2: {
                                                Faculty* fac = new Faculty();
                                                Order* order = new Order();
                                                Date orderDate = Date();
                                                Date returnDate = Date();
                                                bool phuchaser = true;


                                                Magazine* mag = new Magazine();
                                                int itemType = 2; // Magazine


                                                cout << ">>>> Your Order ID is: " << orderid << endl;
                                                orderid++;

                                                cout << "Enter Faculty ID: ";
                                                cin >> id;
                                                cout << "Enter Email: ";
                                                cin.ignore();
                                                getline(cin, email);
                                                cout << "Enter Faculty Name: ";
                                                getline(cin, name);


                                                fac->setId(id);
                                                fac->setName(name);
                                                fac->setEmail(email);


                                                cout << "Enter ISBN: ";
                                                cin >> isbn;

                                                if (magazine->searchMagazineByISBN(isbn)) {
                                                    cout << "Magazine found!\n";
                                                    mag->setisbn(isbn);
                                                }
                                                else {
                                                    cout << "Book not found!\n";
                                                }

                                                // Set status of book false if order
                                                Magazine obj = magazine->getmagazineobj(isbn);
                                                obj.setstatus(false);


                                                cout << "Enter Order Date (day month year): ";
                                                cin >> day >> month >> year;
                                                orderDate.setDay(day);
                                                orderDate.setMonth(month);
                                                orderDate.setYear(year);

                                                cout << "Enter Return Date (day month year): ";
                                                cin >> day >> month >> year;
                                                returnDate.setDay(day);
                                                returnDate.setMonth(month);
                                                returnDate.setYear(year);

                                                order->issuedMagazinetoFaculty(orderid, phuchaser, itemType, *mag, *fac, orderDate, returnDate);

                                                orderarray->addOrder(*order);

                                                delete fac;
                                                delete mag;
                                                delete order;
                                                break;
                                            }

                                            case 3: {
                                                Faculty* fac = new Faculty();
                                                Order* order = new Order();
                                                Date orderDate = Date();
                                                Date returnDate = Date();
                                                bool phuchaser = true;

                                                Newspaper* newspaper = new Newspaper();
                                                int itemType = 3; // Newspaper

                                                cout << ">>>> Your Order ID is: " << orderid << endl;
                                                orderid++;

                                                cout << "Enter Faculty ID: ";
                                                cin >> id;
                                                cout << "Enter Email: ";
                                                cin.ignore();
                                                getline(cin, email);
                                                cout << "Enter Faculty Name: ";
                                                getline(cin, name);

                                                fac->setId(id);
                                                fac->setName(name);
                                                fac->setEmail(email);


                                                cout << "Enter ISSN: ";
                                                cin >> isbn;

                                                if (news->searchNewspaperByISBN(isbn)) {
                                                    cout << "Newspaper found!\n";
                                                    newspaper->setisbn(isbn);
                                                }
                                                else {
                                                    cout << "Newspaper not found!\n";
                                                }

                                                // Set status of newspaper false if ordered
                                                Newspaper obj = news->getnewspaperobj(isbn);
                                                obj.setstatus(false);

                                                cout << "Enter Order Date (day month year): ";
                                                cin >> day >> month >> year;
                                                orderDate.setDay(day);
                                                orderDate.setMonth(month);
                                                orderDate.setYear(year);

                                                cout << "Enter Return Date (day month year): ";
                                                cin >> day >> month >> year;
                                                returnDate.setDay(day);
                                                returnDate.setMonth(month);
                                                returnDate.setYear(year);

                                                order->issuedNewspapertoFaculty(orderid, phuchaser, itemType, *newspaper, *fac, orderDate, returnDate);

                                                orderarray->addOrder(*order);

                                                delete fac;
                                                delete newspaper;
                                                delete order;
                                                break;
                                                break;
                                            }

                                            case 4: {
                                                Faculty* fac = new Faculty();
                                                Order* order = new Order();
                                                Date orderDate = Date();
                                                Date returnDate = Date();
                                                bool phuchaser = true;

                                                Journal* jar = new Journal();
                                                int itemType = 1; // Journal

                                                cout << ">>>> Your Order ID is: " << orderid << endl;
                                                orderid++;

                                                cout << "Enter Faculty ID: ";
                                                cin >> id;
                                                cout << "Enter Email: ";
                                                cin.ignore();
                                                getline(cin, email);
                                                cout << "Enter Faculty Name: ";
                                                getline(cin, name);

                                                fac->setId(id);
                                                fac->setName(name);
                                                fac->setEmail(email);


                                                cout << "Enter ISBN: ";
                                                cin >> isbn;

                                                if (journal->searchJournalByISBN(isbn)) {
                                                    cout << "Journal found!\n";
                                                    jar->setisbn(isbn);
                                                }
                                                else {
                                                    cout << "Journal not found!\n";
                                                }

                                                // Set status of journal false if ordered
                                                Journal obj = journal->getjournalobj(isbn);
                                                obj.setstatus(false);

                                                cout << "Enter Order Date (day month year): ";
                                                cin >> day >> month >> year;
                                                orderDate.setDay(day);
                                                orderDate.setMonth(month);
                                                orderDate.setYear(year);

                                                cout << "Enter Return Date (day month year): ";
                                                cin >> day >> month >> year;
                                                returnDate.setDay(day);
                                                returnDate.setMonth(month);
                                                returnDate.setYear(year);

                                                order->issuedJournaltoFaculty(orderid, phuchaser, itemType, *jar, *fac, orderDate, returnDate);

                                                orderarray->addOrder(*order);

                                                delete fac;
                                                delete journal;
                                                delete order;
                                                break;

                                            }
                                            case 0:
                                                cout << "Logging out..." << endl;
                                                loggedIn = 0;
                                                break;
                                            default:
                                                cout << "Invalid choice. Please try again." << endl;
                                            }
                                        }
                                    
                                    break;
                                }
                                }
                            }


                        }
                        case 2:
                        {
                            cout << endl;
                            int main = -1;
                            while (main != 0)
                            {
                                cout << "1. Search Order For Student" << endl;
                                cout << "2. Search Order For Faculty" << endl;
                                cout << "0. Back to Main Menu" << endl;
                                cout << "Enter your choice: ";
                                cin >>main;
                                switch (main)
                                {
                                case 1:
                                {
                                    cout << endl;
                                    cout << "Please Enter Order Id: ";
                                    cin >> orderid;
                                    if (orderarray->searchOrder((orderid)))
                                    {
                                        cout << "Order Found" << endl;
                                        Order obj = orderarray->search(orderid);
                                        cout << "Email: "<<obj.getStudent().getEmail() << endl;
                                        cout << "Student ID: " << obj.getStudent().getId() << endl;
                                        cout << "Student Name: "<< obj.getStudent().getName() << endl;

                                        if (obj.getBook().getisbn()!=0)
                                        {
                                            cout << "Book ISBN: "<< obj.getBook().getisbn() << endl;
                                        }
                                        if (obj.getJournal().getisbn() != 0)
                                        {
                                            cout << "Journal ISBN: "<< obj.getJournal().getisbn() << endl;
                                        }
                                        if (obj.getMagazine().getisbn() != 0)
                                        {
                                            cout << "Magazine ISBN: "<< obj.getMagazine().getisbn() << endl;
                                        }
                                        if (obj.getNewspaper().getisbn() != 0)
                                        {
                                            cout << "Newspaper ISBN: "<< obj.getNewspaper().getisbn() << endl;
                                        }
                                    }
                                    else
                                    {
                                        cout<<"Order Not Found"<<endl;
                                    }

                                    break;
                                }
                                case 2:
                                {
                                    cout << endl;
                                    cout << "Please Enter Order Id: ";
                                    cin >> orderid;
                                    if (orderarray->searchOrder((orderid)))
                                    {
                                        cout << "Order Found" << endl;
                                        Order obj = orderarray->search(orderid);
                                        cout << "Email: " << obj.getFaculty().getEmail() << endl;
                                        cout << "Student ID: " << obj.getFaculty().getId() << endl;
                                        cout << "Student Name: " << obj.getFaculty().getName() << endl;

                                        if (obj.getBook().getisbn() != 0)
                                        {
                                            cout << "Book ISBN: " << obj.getBook().getisbn() << endl;
                                        }
                                        if (obj.getJournal().getisbn() != 0)
                                        {
                                            cout << "Journal ISBN: " << obj.getJournal().getisbn() << endl;
                                        }
                                        if (obj.getMagazine().getisbn() != 0)
                                        {
                                            cout << "Magazine ISBN: " << obj.getMagazine().getisbn() << endl;
                                        }
                                        if (obj.getNewspaper().getisbn() != 0)
                                        {
                                            cout << "Newspaper ISBN: " << obj.getNewspaper().getisbn() << endl;
                                        }
                                    }
                                    else
                                    {
                                        cout << "Order Not Found" << endl;
                                    }

                                    break;
                                }
                                default:
                                    break;
                                }
                            }


                            break;
                        }
                        case 3:
                        {
                            cout << endl;
                            cout << "Please Enter Order Id: ";
                            cin >> orderid;
                            orderarray->removeOrder(orderid);
                            break;
                        }
                        case 4:
                        {
                            cout << endl;
                            orderarray->printOrders();
                            break;
                        }
                        default:
                            break;
                        }

                    }



                    break;
                }
                case 6:
                {
                    cout << endl;
                    int main = -1;
                    while (main != 0) {
                        cout << "1. Return Book For Student" << endl;
                        cout << "2. Return Book For Faculty" << endl;
                        cout << "0. Back to Main Menu" << endl;
                        cout << "Enter your choice: ";
                        cin >> main;

                        switch (main) {
                        case 1:
                        {


                            cout << endl;
                            cout << "Please Enter Student id: ";
                            cin >> id;


                            Date returnDate = Date();
                            cout << "Enter Order Date (day month year): ";

                            cin >> day >> month >> year;
                            returnDate.setDay(day);
                            returnDate.setMonth(month);
                            returnDate.setYear(year);

                            int loggedIn = -1;
                            int logchoice = -1;
                            while (loggedIn != 0) {
                                cout << "1. Return Book" << endl;
                                cout << "2. Return Magazine" << endl;
                                cout << "3. Return Newspaper" << endl;
                                cout << "4. Return Journal" << endl;
                                cout << "0. Logout" << endl;
                                cout << "Enter your choice: ";
                                cin >> logchoice;
                                cout << endl;

                                switch (logchoice) {
                                case 1:
                                {


                                    if (orderarray->searchOrder(id))
                                    {
                                        orderarray->returned(orderid, 0, returnDate);
                                        Book bookobj = book->getbookobj(isbn);
                                        bookobj.setstatus(true);
                                    }
                                    break;
                                }

                                case 2:
                                {
                                    if (orderarray->searchOrder(id))
                                    {
                                        orderarray->returned(orderid, 2, returnDate);
                                        Magazine magobj = magazine->getmagazineobj(isbn);
                                        magobj.setstatus(true);
                                    }
                                    break;
                                }
                                case 3:
                                {
                                    if (orderarray->searchOrder(id))
                                    {
                                        orderarray->returned(orderid, 3, returnDate);
                                        Newspaper newsobj = news->getnewspaperobj(isbn);
                                        newsobj.setstatus(true);
                                    }
                                    break;
                                }
                                case 4:
                                {
                                    if (orderarray->searchOrder(id))
                                    {
                                        orderarray->returned(orderid, 1, returnDate);
                                        Journal jouobj = journal->getjournalobj(isbn);
                                        jouobj.setstatus(true);
                                    }
                                    break;
                                }
                                case 0:
                                    cout << "Logging out..." << endl;
                                    loggedIn = 0;
                                    break;
                                default:
                                    cout << "Invalid choice. Please try again." << endl;
                                }
                            }
                            break;
                        }
                        case 2: {
                            cout << endl;
                            cout << "Please Enter Faculty ID: ";
                            cin >> id;

                            Date returnDate = Date();
                            cout << "Enter Order Date (day month year): ";
                            cin >> day >> month >> year;
                            returnDate.setDay(day);
                            returnDate.setMonth(month);
                            returnDate.setYear(year);

                            int loggedIn = -1;
                            int logchoice = -1;
                            while (loggedIn != 0) {
                                cout << "1. Return Book" << endl;
                                cout << "2. Return Magazine" << endl;
                                cout << "3. Return Newspaper" << endl;
                                cout << "4. Return Journal" << endl;
                                cout << "0. Logout" << endl;
                                cout << "Enter your choice: ";
                                cin >> logchoice;
                                cout << endl;

                                switch (logchoice) {
                                case 1: {
                                    if (orderarray->searchOrder(id)) {
                                        orderarray->returned(orderid, 0, returnDate);
                                        Book bookobj = book->getbookobj(isbn);
                                        bookobj.setstatus(true);
                                    }
                                    break;
                                }

                                case 2: {
                                    if (orderarray->searchOrder(id)) {
                                        orderarray->returned(orderid, 2, returnDate);
                                        Magazine magobj = magazine->getmagazineobj(isbn);
                                        magobj.setstatus(true);
                                    }
                                    break;
                                }

                                case 3: {
                                    if (orderarray->searchOrder(id)) {
                                        orderarray->returned(orderid, 3, returnDate);
                                        Newspaper newsobj = news->getnewspaperobj(isbn);
                                        newsobj.setstatus(true);
                                    }
                                    break;
                                }

                                case 4: {
                                    if (orderarray->searchOrder(id)) {
                                        orderarray->returned(orderid, 1, returnDate);
                                        Journal jouobj = journal->getjournalobj(isbn);
                                        jouobj.setstatus(true);
                                    }
                                    break;
                                }

                                case 0:
                                    cout << "Logging out..." << endl;
                                    loggedIn = 0;
                                    break;

                                default:
                                    cout << "Invalid choice. Please try again." << endl;
                                }
                            }
                            break;
                        }

                        }

                    }

                    break;
                }

                case 0:
                    cout << "Returning to Admin Portal..." << endl;
                    break;
                default:
                    cout << "Invalid choice. Please try again." << endl;


                }

            }
            break;
        }
            
        case 0:
            cout << "Exiting the program. Goodbye!" << endl;
            cout << endl;
            break;
        default:
            cout << "Invalid choice. Please select a valid option." << endl;
            cout << endl;
        }

    }
    cout << endl;
}