//
// Created by Lix Xeil on 09.05.2022.
//

#include "UserInterface.h"
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;


UserInterface::UserInterface() {}

UserInterface::UserInterface(Controller &ctrl)
{
    this->ctrl = ctrl;
}

UserInterface::~UserInterface() {}

void UserInterface::showMenu()
{
    cout << "----Menu----" << endl;
    cout << "1. Add a new record in the repository." << endl;
    cout << "2. Delete an existent record from the repository." << endl;
    cout << "3. Find a record in the repository." << endl;
    cout << "4. Update an existing record's information in the repository." << endl;
    cout << "5. Display all records present in the repository." << endl;
    cout << "6. Display the total number of records in the repository." << endl;
    cout << "7. Display a given/locally inputted record from the repository." << endl;
    cout << "8. Display the most expensive record in the repository." << endl;
    cout << "9. Filter and display records by their release year." << endl;
    cout << "10. Filter and display records by their price." << endl;
    cout << "11. Filter and display records by their artist." << endl;
    cout << "12. Undo -> redoes the last modification(?)." << endl;
    cout << "0. Exit app/program." << endl;
    int option;
    while(true)
    {
        cout << endl;
        cout << "Input preferred option >>> ";
        cin >> option;
        switch (option)
        {
            case 0: { break; }
            case 1: { add_fct(); break; }
            case 2: { delete_fct(); break; }
            case 3: { find_fct(); break; }
            case 4: { update_fct(); break; }
            case 5: { getAll_fct(); break; }
            case 6: { getNumberRecords_fct(); break; }
            case 7: { showRecord_fct(); break; }
            case 8: { mostExpensiveRecord_fct(); break; }
            case 9: { filterByYear_fct(); break; }
            case 10: { filterByPrice_fct(); break; }
            case 11: { filterByArtist_fct(); break; }
            case 12: { break; }
            default:
                cout << "Invalid option, please try again." << endl;
        }
        if(option == 0)
        {
            cout << "Exiting program..." << endl;
            break;
        }
    }
}

void UserInterface::add_fct()
{
    string id;
    string artistName;
    string recordName;
    int duration, year;
    float price;
    cout << "Enter id >>> ";
    cin >> id;
    cout << endl << "Enter duration >>> ";
    cin >> duration;
    cout << endl << "Enter artist name >>> ";
    cin >> artistName;
    cout << endl << "Enter record name >>> ";
    cin >> recordName;
    cout << endl << "Enter year >>> ";
    cin >> year;
    cout << endl << "Enter price >>> ";
    cin >> price;
    this->ctrl.add(id, duration, artistName, recordName, year, price);
    cout << endl << endl;
}

