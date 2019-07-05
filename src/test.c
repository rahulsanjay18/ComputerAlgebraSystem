#include <stdio.h>
#include "postfix.h"
int testNum = 1;
int passed = 0;
int failed = 0;
void assert(int condition){
	
	if(!condition){
		printf("Test number %i failed.\n", testNum);
    failed++;
  }
  else {
    printf("Test number %i passed!.\n", testNum);
    passed++;
  }
  testNum++;
}

void getTestStatusMessage() {
  printf("Results: %i test(s) passed, %i test(s) failed\n", passed, failed);
}

int isEqual(const char * first, const char * second) {
  int total = 0;
  int i = 0;
  while (first[i] != '\0' && second[i] != '\0') {
    total += first[i] - second[i];
    i++;
   }

  if (first[i] != '\0' || second[i] != '\0') {
    return 0;
  }

  return !(total);
}

void runAllTestCases() {
  assert(isEqual(convertToPostfix("3+4"), "3 4 +"));
  assert(isEqual(convertToPostfix("3-4*5"), "3 4 5 * -"));
  assert(isEqual(convertToPostfix("2x+1"), "1 x 2 * +"));
  assert(isEqual(convertToPostfix("3(x+7)^2"), "3 x 7 + 2 ^ *"));
  assert(isEqual(convertToPostfix("(cos(3x^2+4)+45x)/170"), "| 3 x 2 ^ * 4 + cos 45 x * + 170 /"));

  getTestStatusMessage();
}

/**
	This file is going to be for all test cases. put all test cases above
	this function
*/
int main() {
  runAllTestCases();
  return 0;
}