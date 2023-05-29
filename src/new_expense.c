#include "main.h"
#include "utility.h"
#include "new_expense.h"

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Add a new expense
 *
 * @return void
 */

void newExpense() {
  FILE *file;
  char description[80];
  char value[12];
  char line[255] = {0};
  char *aux;

  clearBuffer();
  printf("\nEnter expense description:");
  fgets(description, sizeof(description), stdin);
  // Remove the new line at the end
  description[strcspn(description, "\n")] = 0;
  if (strlen(description) == 0) {
    return;
  }

  printf("\nEnter the value:");
  fgets(value, sizeof(value), stdin);
  if (strlen(value) == 0) {
    return;
  }

  if (!(file = fopen(ARQUIVO, "a"))) {
    error("Error reading file:%s\n", strerror(errno));
  }

  strcat(line, description);
  strcat(line, ";");
  strcat(line, value);

  fprintf(file, "%s", line);
  fclose(file);
}
