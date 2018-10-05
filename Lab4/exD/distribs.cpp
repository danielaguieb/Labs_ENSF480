// distribs.cpp

#include "distribs.h"

#include <assert.h>
#include <stdlib.h>

double continuous_unif()
{
  return rand() / (1.0 + RAND_MAX);
}

int discrete_unif(int lo, int hi)
{
  assert(lo <= hi);
  return lo + int((hi - lo + 1) * continuous_unif());
}
