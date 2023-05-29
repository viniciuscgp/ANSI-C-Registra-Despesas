#include "arquivos.h"
#include "utility.h"
#include "list_expense.h"

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief List all expenses
 *
 * This function lists all expense in the DB
 *
  * @return void
 */

void listExpense() {
  FILE *file;
  char line[255] = {0};
  char *parts[10];
  float total, value;

  if (!(file = fopen(ARQUIVO, "r"))) {
    error("Error reading file:%s\n", strerror(errno));
    return;
  }

  puts("\n");
  printf("==========================================\n");
  printf("%-15.15s | %12.12s\n", "Expense", "Value");
  printf("==========================================\n");

  total = 0;
  while (fgets(line, 255, file) != NULL) {
    // retira o \n retornado por fgets
    line[strcspn(line, "\n")] = 0;
    parts[0] = strtok(line, ";");
    parts[1] = strtok(NULL, ";");

    // Esta tudo ok ? Imprime e calcula
    if (parts[0] != NULL && parts[1] != NULL) {
      value = atof(parts[1]);
      printf("%-15.15s | %12.2f\n", parts[0], value);
      total += value;
    }
  }

  printf("==========================================\n");
  printf("%-15.15s | %12.2f\n", "Total->", total);

  fclose(file);
  waitForEnter();
}
