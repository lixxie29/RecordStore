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


//  add a record in the repository

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


//  delete an existing record from the repository

void UserInterface::delete_fct()
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

    if(this->ctrl.del(id, duration, artistName, recordName,year,price) == 1)
    { cout << "The record was successfully deleted." << endl << endl; }
    else
    { cout << "The record doesn't exist in repository." << endl << endl;}
}


//  finds a record in the repository

void UserInterface::find_fct()
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

    if(this->ctrl.find(id, duration,artistName,recordName,year,price) == 1)
    { cout << "The record was found in the repository." << endl << endl; }
    else
    { cout << "The record doesn't exist in repository." << endl << endl;}
}


// updates a record's information

void UserInterface::update_fct()
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
    cout << endl;

    string new_id;
    string new_artistName;
    string new_recordName;
    int new_duration, new_year;
    float new_price;
    cout << "Enter new id >>> ";
    cin >> new_id;
    cout << endl << "Enter new duration >>> ";
    cin >> new_duration;
    cout << endl << "Enter new artist name >>> ";
    cin >> new_artistName;
    cout << endl << "Enter new record name >>> ";
    cin >> new_recordName;
    cout << endl << "Enter new year >>> ";
    cin >> new_year;
    cout << endl << "Enter new price >>> ";
    cin >> new_price;

    if(1 == this->ctrl.update(id, duration, artistName, recordName, year, price, new_id, new_duration, new_artistName,
                              new_recordName, new_year, new_price))
    { cout << "The record's information were successfully updated." << endl << endl; }
    else
    { cout << "The record doesn't exist in repository." << endl << endl;}
}


// displays all records present in the repository

void displayEveryRecord(vector<Record*> &r)
{
    cout << " >>>> List of records <<<< " << endl;
    for(Record* rec : r)
    {
        cout << rec->toString() << endl;
    }
    cout << endl;
}

void UserInterface::getAll_fct()
{
    vector <Record*> r = this->ctrl.getAll();
    displayEveryRecord(r);
}


// returns number of records in repository

void UserInterface::getNumberRecords_fct()
{
    cout << " The number of records present in repository are: " << this->ctrl.getNumberRecords() << endl << endl;
}


// displays a locally inputted record

void UserInterface::showRecord_fct()
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
    Record r(id, duration, artistName, recordName, year, price);
    cout << r.toString();
    cout << endl;
}


// displays the most expensive record in the repository

void UserInterface::mostExpensiveRecord_fct()
{
    Record *r = this->ctrl.mostExpensiveRecord();
    cout << "The most expensive record is ";
    cout << r->toString();
    cout << endl;
}


// filters and displays records based on the year they were created/produced in

void UserInterface::filterByYear_fct()
{
    cout << "Enter preferred filtering year >>>";
    unsigned int year;
    cin >> year;
    vector <Record*> rez = this->ctrl.filterByYear(year);
    if (rez.size() != 0)
    {
        cout << "Filtered list of records by year: " << endl;
        displayEveryRecord(rez);
    }
    else
        cout << "There's no record that contains inputted information." << endl;
}


// filters and displays records based on the price they have

void UserInterface::filterByPrice_fct()
{
    cout << "Enter preferred filtering price >>>";
    float price;
    cin >> price;
    vector <Record*> rez = this->ctrl.filterByPrice(price);
    if (rez.size() != 0)
    {
        cout << "Filtered list of records by price: " << endl;
        displayEveryRecord(rez);
    }
    else
        cout << "There's no record that contains inputted information." << endl;
}


// filters and displays records based on the artist that produced/created them

void UserInterface::filterByArtist_fct()
{
    cout << "Enter preferred filtering price >>>";
    string artistName;
    cin >> artistName;
    vector <Record*> rez = this->ctrl.filterByArtist(artistName);
    if (rez.size() != 0)
    {
        cout << "Filtered list of records by artist: " << endl;
        displayEveryRecord(rez);
    }
    else
        cout << "There's no record that contains inputted information." << endl;
}
