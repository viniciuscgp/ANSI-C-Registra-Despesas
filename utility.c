#include "utility.h"
#include "stdio.h"

// clear input buffer
void clearBuffer() {
  char c;
  while ((c = getchar()) != '\n' && c != EOF) {
  }
}

/**
Show a error message and wait for ENTER
*/
void error(const char *format, ...) {
  va_list arg;
  va_start(arg, format);
  vprintf(format, arg);
  va_end(arg);
  waitForEnter();
}

void waitForEnter() {
  char c;

  printf("\nPush <ENTER>\n");

  clearBuffer();
  scanf("%c", &c);
}
