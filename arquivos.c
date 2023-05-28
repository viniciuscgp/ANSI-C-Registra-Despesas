#include "arquivos.h"
#include "utility.h"
#include <errno.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  short op = 0;
  while (op != 3) {
    showMenu();
    scanf("%hd", &op);
    switch (op) {
    case 1:
      newExpense();
      break;
    case 2:
      listExpense();
      break;
    }
  }

  return 0;
}

void showMenu() {
  system("clear");
  printf("+-----------------------------+\n");
  printf("| Welcome to Expenses Control |\n");
  printf("+-----------------------------+\n");
  printf("What do you want to do ?:\n\n");
  printf("1-Enter a new expense\n");
  printf("2-List all expenses\n");
  printf("3-Exit\n\n");
}

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
