#include "finance.h"
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
Transaction finance_transactions[100];
int finance_count = 0;
void finance_init() {
    finance_count = 0;
}
int finance_get_count() {
    return finance_count;
}
bool finance_check_amount(double amount) {
    if (amount <= 0) {
        cout << "Ошибка: Сумма должна быть больше 0!" << endl;
        return false;
    }
    if (amount > 1000000) {
        cout << "Ошибка: Слишком большая сумма!" << endl;
        return false;
    }
    return true;
}
bool finance_check_type(int type) {
    if (type != 0 && type != 1) {
        cout << "Ошибка: Тип должен быть 0 (расход) или 1 (доход)!" << endl;
        return false;
    }
    return true;
}
void finance_add_trans() {
    if (finance_count >= 100) {
        cout << "Ошибка: Достигнут лимит транзакций!" << endl;
        return;
    }
    Transaction t;
    cout << "Введите описание: ";
    cin.ignore();
    cin.getline(t.desc, 50);

    if (strlen(t.desc) == 0) {
        cout << "Ошибка: Описание не может быть пустым!" << endl;
        return;
    }
    cout << "Введите сумму: ";
    cin >> t.amount;
    if (!finance_check_amount(t.amount)) {
        return;
    }
    cout << "Введите тип (1=доход, 0=расход): ";
    cin >> t.type;
    if (!finance_check_type(t.type)) {
        return;
    }

    t.id = finance_count + 1;
    finance_transactions[finance_count] = t;
    finance_count++;

    cout << "Транзакция добавлена! ID: " << t.id << endl;
}
void finance_show_all() {
    if (finance_count == 0) {
        cout << "Нет транзакций." << endl;
        return;
    }
    cout << "\n=== ВСЕ ТРАНЗАКЦИИ ===" << endl;
    for (int i = 0; i < finance_count; i++) {
        Transaction t = finance_transactions[i];
        cout << "ID: " << t.id
            << " | " << (t.type ? "ДОХОД " : "РАСХОД")
            << " | " << t.amount << " руб."
            << " | " << t.desc << endl;
    }
}
void finance_show_balance() {
    if (finance_count == 0) {
        cout << "Нет транзакций для расчета баланса." << endl;
        return;
    }
    double income = 0, expenses = 0;
    for (int i = 0; i < finance_count; i++) {
        if (finance_transactions[i].type == 1) {
            income += finance_transactions[i].amount;
        }
        else {
            expenses += finance_transactions[i].amount;
        }
    }
    double balance = income - expenses;
    cout << "\n=== ФИНАНСОВЫЙ ОТЧЕТ ===" << endl;
    cout << "Всего доходов: " << income << " руб." << endl;
    cout << "Всего расходов: " << expenses << " руб." << endl;
    cout << "Баланс: " << balance << " руб." << endl;
    if (balance > 0) {
        cout << "Отлично! У вас положительный баланс!" << endl;
    }
    else if (balance < 0) {
        cout << "Внимание! У вас отрицательный баланс!" << endl;
    }
    else {
        cout << "Баланс нулевой." << endl;
    }
}
void finance_delete_trans() {
    if (finance_count == 0) {
        cout << "Нет транзакций для удаления." << endl;
        return;
    }
    finance_show_all();
    int id;
    cout << "Введите ID транзакции для удаления: ";
    cin >> id;

    if (id < 1 || id > finance_count) {
        cout << "Ошибка: Неверный ID!" << endl;
        return;
    }
    for (int i = 0; i < finance_count; i++) {
        if (finance_transactions[i].id == id) {
            cout << "Удаляем: " << finance_transactions[i].desc << " - " << finance_transactions[i].amount << " руб." << endl;

            for (int j = i; j < finance_count - 1; j++) {
                finance_transactions[j] = finance_transactions[j + 1];
            }
            finance_count--;
            cout << "Транзакция удалена!" << endl;
            return;
        }
    }
    cout << "Транзакция с ID " << id << " не найдена!" << endl;
}
void finance_save_to_file() {
    if (finance_count == 0) {
        cout << "Нет данных для сохранения." << endl;
        return;
    }

    ofstream file("finance.txt");
    if (!file) {
        cout << "Ошибка создания файла!" << endl;
        return;
    }

    file << finance_count << endl;
    for (int i = 0; i < finance_count; i++) {
        file << finance_transactions[i].id << endl;
        file << finance_transactions[i].desc << endl;
        file << finance_transactions[i].amount << endl;
        file << finance_transactions[i].type << endl;
    }

    file.close();
    cout << "Данные сохранены в файл finance.txt" << endl;
}

void finance_load_from_file() {
    ifstream file("finance.txt");
    if (!file) {
        cout << "Файл с данными не найден. Будет создан новый." << endl;
        return;
    }

    file >> finance_count;
    for (int i = 0; i < finance_count; i++) {
        file >> finance_transactions[i].id;
        file.ignore();
        file.getline(finance_transactions[i].desc, 50);
        file >> finance_transactions[i].amount;
        file >> finance_transactions[i].type;
    }

    file.close();
    cout << "Данные загружены из файла finance.txt" << endl;
    cout << "Загружено транзакций: " << finance_count << endl;
}