//
// Created by Lix Xeil on 09.05.2022.
//
#pragma once
#include "Controller.h"
#include "Repository.h"
#include "Record.h"

#include <string>
// #include <iostream>
// #include <algorithm>

//  constructor/deconstructor of the controller
Controller::Controller() {}

Controller::Controller(Repository& repo)
{
    this->repo = repo;
}
Controller::~Controller() {}


//  function that inserts/adds an element(record object) in the repository
//  doesn't return anything
void Controller::add(string i, unsigned int dur, string artName, string recName, unsigned int yr, float p)
{
    Record *r= new Record(i, dur, artName, recName, yr, p);
    this->repo.addRecord(r);
}


//  function that deletes an element(record object) from the repository
//  returns 1 if the record gets deleted, else returns an exception
int Controller::del(string i, unsigned int dur, string artName, string recName, unsigned int yr, float p) {
    Record r(i, dur, artName, recName, yr, p);
    return this->repo.deleteRecord(&r);
}


//  function that searches for/finds an element(record object) in the repository
//  returns 1 if the record is in the repository, else returns an exception
int Controller::find(string i, unsigned int dur, string artName, string recName, unsigned int yr, float p) {
    Record r(i, dur, artName, recName, yr, p);
    return this->repo.findRecord(&r);
}


//  function that updates the information of an element(record object) in the repository
//  returns 1 if it's updated, else returns an exception
int Controller::update(string i, unsigned int dur, string artName, string recName, unsigned int yr, float p, string new_i,
                   unsigned int new_dur, string new_artName, string new_recName, unsigned int new_yr, float new_p) {
    Record r(i, dur, artName, recName, yr, p);
    Record r_new(new_i, new_dur, new_artName, new_recName, new_yr, new_p);
    return this->repo.updateRecord(&r, &r_new);
}


//  getter for the records in the controller repository
vector<Record *> Controller::getAll() {
    return this->repo.getAllRecords();
}

//  getter for the number of records in the controller repository
int Controller::getNumberRecords() {
    return this->repo.getSize();
}

//  function that displays a record's information
//void Controller::showRecord(Record &r) {
//    r.toString();
//}

//  function that returns the most expensive record
Record* Controller::mostExpensiveRecord() {
    vector<Record*> recs = getAll();
    int maxprice = -1;
    Record* r;
    for(int i = 0; i <= recs.size() - 1; i++)
    {
        if(recs[i]->getPrice() > maxprice)
        {
            maxprice = recs[i]->getPrice();
            r = recs[i];
        }
    }
    return r;
}


//  function that filters all records by year
//  returns the records that have the inputted/given year
vector<Record *> Controller::filterByYear(unsigned int yr) {
    vector<Record*> recs = getAll();
    vector<Record*> final_recs;
    for(int i = 0; i <= recs.size() - 1; i++)
    {
        if(recs[i]->getYear() == yr)
            final_recs.push_back(recs[i]);
    }
    return final_recs;
}


//  function that filters all records by price
//  returns the records that have the inputted/given price
vector<Record *> Controller::filterByPrice(float p) {
    vector<Record*> recs = getAll();
    vector<Record*> final_recs;
    for(int i = 0; i <= recs.size() - 1; i++)
    {
        if(recs[i]->getPrice() == p)
            final_recs.push_back(recs[i]);
    }
    return final_recs;
}


//  function that filters all records by artist
//  returns the records that were created/sang by the inputted/given artist
vector<Record *> Controller::filterByArtist(string artName)
{
    vector<Record*> recs = getAll();
    vector<Record*> final_recs;
    for(int i = 0; i <= recs.size() - 1; i++)
    {
        if(recs[i]->getArtistName() == artName)
            final_recs.push_back(recs[i]);
    }
    return final_recs;
}

//void Controller::undo_version()
//{
//	if (this->undo.get_size() == 0)
//		cout << "Can't undo last command" << endl;
//	else if (this->undo.get_size() == 1)
//	{
//		vector<vector<Record*>> ver = this->undo.get_versions();
//		this->repo.undo_version(ver[ver.size() - 1]);
//	}
//}