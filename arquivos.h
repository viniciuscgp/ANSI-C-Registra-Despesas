#ifndef ARQUIVOS_GUARD
#define ARQUIVOS_GUARD

void showMenu();
void newExpense();
void listExpense();
void error(const char *format, ...);

#define ARQUIVO "expenses.dat"

#endif