#include "finance.h"
#include "menu.h"
#include <iostream>
using namespace std;
int main() {
    setlocale(0, "");
    finance_init();
    menu_show_welcome();
    finance_load_from_file();
    int choice;
    do {
        menu_show_main();
        cin >> choice;
        menu_process_choice(choice);

    } while (choice != 8);
    return 0;
}