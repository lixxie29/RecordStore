//
// Created by Lix Xeil on 09.05.2022.
//

#ifndef RECORDSTORE_REPOSITORY_H
#define RECORDSTORE_REPOSITORY_H

#pragma once
#include "Record.h"
#include <vector>
#include <iostream>
using std::vector;
using std::ostream;


class Repository {
public:
    //  constructor for the repository
    Repository();

    //  deconstructor for the repository
    ~Repository();

    //  adds/inserts a record object in the repository
    void addRecord(Record* r);

    //  deletes a record from the repository
    int deleteRecord(Record* r);

    //  finds a record in the repository
    int findRecord(Record* r);

    //  updates a record's information in the repository
    int updateRecord(Record* r, Record* r_new);

    //  getter for a record given by position
    //  Record getElement(int pos);

    //  getter for all elements in the repository
    vector<Record*>& getAllRecords()    {return records;}

    //  getter for the repository size
    int getSize();

    //  friend function for displaying objects/repository
    friend ostream& operator<<(ostream& s, const Repository& repo);

private:
    vector<Record*> records;
};


#endif //RECORDSTORE_REPOSITORY_H
