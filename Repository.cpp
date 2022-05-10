//
// Created by Lix Xeil on 09.05.2022.
//

#include "Repository.h"
#include <exception>

    //  constructor of the repository
    Repository::Repository()= default;

    //  deconstructor of the repository
    Repository::~Repository()= default;

    //  inserts/adds record to the repository
    void Repository::addRecord(Record *r)
    {
        records.push_back(r);
    }

    // deletes record from the repository
    int Repository::deleteRecord(Record *r)
    {
        vector<Record*>::iterator it = find(records.begin(), records.end(), r);
        if (it == records.end()) throw std::exception();
        if (it != records.end())
        {
            records.erase(it);
            return 1;
        }
        //return 0;             // commented because i'm not sure if it's needed after that throw exception line
    }

    // finds record in the repository
    int Repository::findRecord(Record *r)
    {
        vector<Record*>::iterator it = find(records.begin(), records.end(), r);
        if (it == records.end()) throw std::exception();
        if (it != records.end()) return 1;
        //return 0;             // commented because i'm not sure if it's needed after that throw exception line
    }

    // updates record's information with a new record's information in the repository
    int Repository::updateRecord(Record *r, Record* r_new)
    {
        vector<Record*>::iterator it = find(records.begin(), records.end(), r);
        if (it == records.end()) throw std::exception();
        if (it != records.end())
        {
            *it = r_new;
            return 1;
        }
        //return 0              // same situation as in the previous functions
    }

    //  getter for the size of the repository
    int Repository::getSize()
    {
        return (int)this->records.size();
    }

    // getter for a record placed on a given position in the repository
    //Record Repository::getElement(int pos)
    //{
    //    return repo.records[pos];
    //}

    // print(?)/display friend operator
    ostream& operator<<(ostream& s, const Repository& repo)
    {
        for(size_t i = 0; i < repo.records.size(); i++)
        {
            s << repo.records[i]->toString() << std::endl;
        }
        return s;
    }