#include <errno.h>
#include <stdio.h>

#include "arquivos.h"
#include "utility.h"
#include "new_expense.h"
#include "list_expense.h"

int main(void)
{
  showMenu();
  return 0;
}

void showMenu()
{
  short op = 0;
  while (op != 9)
  {
    clearScreen();
    printf("+-----------------------------+\n");
    printf("| Welcome to Expenses Control |\n");
    printf("+-----------------------------+\n");
    printf("What do you want to do ?:\n\n");
    printf("1-Enter a new expense\n");
    printf("2-List all expenses\n");
    printf("3-Delete an expense\n");
    printf("\n");
    printf("9-Exit\n\n");
    
    scanf("%hd", &op);
    switch (op)
    {
    case 1:
      newExpense();
      break;
    case 2:
      listExpense();
      break;
    }
  }
}
