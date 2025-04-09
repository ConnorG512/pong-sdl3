#include "number_gen_util.h"
#include <cstdlib>
#include <ctime>

int RandomNum::GenerateRandomNumber(const int max_value) {
  int result = rand() % (max_value + 1);
  return result;
} 
