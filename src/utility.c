#include "utility.h"
#include "stdio.h"
#include "stdarg.h"
#include "stdlib.h"

/**
 * @brief clear input buffer
 * @return void
 */
void clearBuffer()
{
  char c;
  while ((c = getchar()) != '\n' && c != EOF);
}

/**
* @brief Show a error message and wait for ENTER
* @returns void
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
 * @brief  for user to push enter
 * @return void
*/
void waitForEnter()
{
  char c;

  printf("\nPush <ENTER>\n");

  clearBuffer();
  scanf("%c", &c);
}

/**
 * @brief Clear the console screen
 * @return void
*/
void clearScreen() 
{
#ifdef _WIN32 
  system("cls");
#else
  system("clear");
#endif
}