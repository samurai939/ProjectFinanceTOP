#include "menu.h"
#include "finance.h"
#include <iostream>
using namespace std;
void menu_show_welcome() {
    cout << "=================================" << endl;
    cout << "   ÑÈÑÒÅÌÀ ÓÏÐÀÂËÅÍÈß ÔÈÍÀÍÑÀÌÈ   " << endl;
    cout << "=================================" << endl;
}
void menu_show_goodbye() {
    cout << "=================================" << endl;
    cout << "    Ñïàñèáî çà èñïîëüçîâàíèå!    " << endl;
    cout << "          Äî ñâèäàíèÿ!           " << endl;
    cout << "=================================" << endl;
}
void menu_show_main() {
    cout << "\n=== ÃËÀÂÍÎÅ ÌÅÍÞ ===" << endl;
    cout << "1. Äîáàâèòü òðàíçàêöèþ" << endl;
    cout << "2. Ïîêàçàòü âñå òðàíçàêöèè" << endl;
    cout << "3. Ïîêàçàòü áàëàíñ" << endl;
    cout << "4. Óäàëèòü òðàíçàêöèþ" << endl;
    cout << "5. Cîõðàíèòü â ôàéë" << endl;
    cout << "6. Çàãðóçèòü èç ôàéëà" << endl;
    cout << "7. Âûõîä" << endl;
    cout << "Âûáåðèòå äåéñòâèå: ";
}

void menu_show_add() {
    cout << "\n=== ÄÎÁÀÂËÅÍÈÅ ÒÐÀÍÇÀÊÖÈÈ ===" << endl;
}

void menu_show_delete() {
    cout << "\n=== ÓÄÀËÅÍÈÅ ÒÐÀÍÇÀÊÖÈÈ ===" << endl;
}

void menu_process_choice(int choice) {
    switch (choice) {
    case 1:
        menu_show_add();
        finance_add_trans();
        break;
    case 2:
        finance_show_all();
        break;
    case 3:
        finance_show_balance();
        break;
    case 4:
        menu_show_delete();
        finance_delete_trans();
        break;
    case 5:
        finance_save_to_file();
        break;
    case 6:
        finance_load_from_file();
        break;
    case 7:
        menu_show_goodbye();
        break;
    default:
        cout << "Íåâåðíûé âûáîð! Ïîïðîáóéòå ñíîâà." << endl;
    }
}