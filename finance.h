#pragma once
#ifndef FINANCE_H
#define FINANCE_H
struct Transaction {
    int id;
    char desc[50];
    double amount;
    int type; 
};
extern Transaction finance_transactions[100];
extern int finance_count;
void finance_init();
void finance_add_trans();
void finance_show_all();
void finance_show_balance();
void finance_delete_trans();
void finance_save_to_file();
void finance_load_from_file();
int finance_get_count();
#endif