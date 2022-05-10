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
    Controller(Repository* repo);

    //  deconstructor for the controller class
    ~Controller();

    // function that inserts/adds an element(record object) in the repository
    void add(string i, unsigned int dur, string artName, string recName, unsigned int yr, float p);

    //  function that deletes an element(record object) from the repository
    int del(string i, unsigned int dur, string artName, string recName, unsigned int yr, float p);

    //  function that searches for/finds an element(record object) in the repository
    int find(string i, unsigned int dur, string artName, string recName, unsigned int yr, float p);

    //  function that
private:
    Repository repo;
};


#endif //RECORDSTORE_CONTROLLER_H
