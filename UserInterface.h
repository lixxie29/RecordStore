//
// Created by Lix Xeil on 09.05.2022.
//

#ifndef RECORDSTORE_USERINTERFACE_H
#define RECORDSTORE_USERINTERFACE_H

#pragma once
#include "Controller.h"


class UserInterface {
public:
    UserInterface();
    UserInterface(Controller& ctrl);
    void showMenu();
    ~UserInterface();

private:
    Controller ctrl;
    void add_fct();
    void delete_fct();
    void find_fct();
    void update_fct();
    void getAll_fct();
    void getNumberRecords_fct();
    static void showRecord_fct();
    void mostExpensiveRecord_fct();
    void filterByYear_fct();
    void filterByPrice_fct();
    void filterByArtist_fct();
};


#endif //RECORDSTORE_USERINTERFACE_H
