#include "UserInterface.h"
#include "Controller.h"
#include "Record.h"
#include "Repository.h"
#include <iostream>
using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    std::cout << " Functions are available and working only on the parent class." << std::endl;

    Repository repo;
    Controller ctrl;
    UserInterface UserInterface(ctrl);
    UserInterface.showMenu();
    return 0;
}
