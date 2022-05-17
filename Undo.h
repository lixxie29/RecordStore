//
// Created by Lix Xeil on 10.05.2022.
//

#ifndef RECORDSTORE_UNDO_H
#define RECORDSTORE_UNDO_H

#pragma once
#include "Record.h"
#include <vector>


class Undo {
public:
    Undo();
    ~Undo();
    int getSize() { return this->size;};
    void addVersion(vector<Record *>& r)    {this->ver[size++] = r;};
    vector<vector<Record*>> getVersions()   {return this->ver;};

private:
    vector<vector<Record*>> ver;
    int size;
};


#endif //RECORDSTORE_UNDO_H
