#include "test.h"

int main() {
  int no_failed = 0;

  no_failed |= test_regular();
  no_failed |= test_sprintf();
  no_failed |= test_sscanf();
  no_failed |= test_csharp();

  return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
