//
// Created by Lix Xeil on 09.05.2022.
//

#ifndef RECORDSTORE_CONTROLLER_H
#define RECORDSTORE_CONTROLLER_H

#pragma once
//#include "Undo.h"
#include "Repository.h"
#include <string>

class Controller {
public:
    //  constructor for the controller class
    Controller();
    Controller(Repository& repo);

    //  deconstructor for the controller class
    ~Controller();

    //  function that inserts/adds an element(record object) in the repository
    void add(string i, unsigned int dur, string artName, string recName, unsigned int yr, float p);

    //  function that deletes an element(record object) from the repository
    int del(string i, unsigned int dur, string artName, string recName, unsigned int yr, float p);

    //  function that searches for/finds an element(record object) in the repository
    int find(string i, unsigned int dur, string artName, string recName, unsigned int yr, float p);

    //  function that updates the information of an element(record object) in the repository
    int update(string i, unsigned int dur, string artName, string recName, unsigned int yr, float p,
               string new_i, unsigned int new_dur, string new_artName, string new_recName, unsigned int new_yr, float new_p);

    //  function that gets all objects(?) (record objects) from the repository
    vector<Record*> getAll();

    //  function that gets the number of records/objects in the current(?) repository;
    //  i mean like, in the repository created here in this class
    int getNumberRecords();

    //  function that displays a record's/an object's information/fields
    // void showRecord(Record& r);

    //  function that shows/returns the most expensive record
    Record* mostExpensiveRecord();

    //  function that filters the records by year
    vector<Record*> filterByYear(unsigned int yr);

    //  function that filters the records by price
    vector<Record*> filterByPrice(float p);

    //  function that filters the records by artist
    vector<Record*> filterByArtist(string artName);

    // undo function
    // void undo_version();

private:
    Repository repo;
    // Undo undo;
};


#endif //RECORDSTORE_CONTROLLER_H
