#include "utility.h"
#include "stdio.h"
#include "stdarg.h"
#include "stdlib.h"

/**
 *  clear input buffer
 */
void clearBuffer()
{
  char c;
  while ((c = getchar()) != '\n' && c != EOF);
}

/**
Show a error message and wait for ENTER
*/
void error(const char *format, ...)
{
  va_list arg;
  va_start(arg, format);
  vprintf(format, arg);
  va_end(arg);
  waitForEnter();
}

/**
Waits for user to push enter
*/
void waitForEnter()
{
  char c;

  printf("\nPush <ENTER>\n");

  clearBuffer();
  scanf("%c", &c);
}

void clearScreen() 
{
#ifdef _WIN32 
  system("cls");
#else
  system("clear");
#endif
}