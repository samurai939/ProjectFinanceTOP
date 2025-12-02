#include "menu.h"
#include "finance.h"
#include <iostream>
using namespace std;
void menu_show_welcome() {
    cout << "Система управления финансами" << endl;
}
void menu_show_goodbye() {
    cout << "Спасибо за использование!" << endl;
    cout << "До свидания!" << endl;
}
void menu_show_main() {
    cout << "\n=== УПРАВЛЕНИЕ ФИНАНСАМИ ===" << endl;
    cout << "1. Добавить транзакцию" << endl;
    cout << "2. Показать все транзакции" << endl;
    cout << "3. Показать баланс" << endl;
    cout << "4. Удалить транзакцию" << endl;
    cout << "5. Cохранить в файл" << endl;
    cout << "6. Загрузить из файла" << endl;
    cout << ". Выход" << endl;
    cout << "Выберите действие: ";
}

void menu_show_add() {
    cout << "\n=== ДОБАВЛЕНИЕ ТРАНЗАКЦИИ ===" << endl;
}

void menu_show_delete() {
    cout << "\n=== УДАЛЕНИЕ ТРАНЗАКЦИИ ===" << endl;
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
        cout << "Неверный выбор! Попробуйте снова." << endl;
    }
