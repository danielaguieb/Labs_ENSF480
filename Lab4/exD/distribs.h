// distribs.h

#ifndef DISTRIBS_H
#define DISTRIBS_H

double continuous_unif();
// PROMISES:
//   Calls rand once.
//   Return value is >= 0.0 and < 1.0.
//   Making successive calls to continuous_unif approximates
//   sampling from a continuous uniform distribution over the
//   interval from 0 to 1.

int discrete_unif(int lo, int hi);
// REQUIRES:
//   lo <= hi.
// PROMISES:
//   Calls rand once.
//   Return value is >= lo and <= hi.
//   Making successive calls to discrete_unif approximates
//   sampling from a discrete uniform distribution over the
//   set { lo, lo + 1, ..., hi - 1, hi }.

#endif
