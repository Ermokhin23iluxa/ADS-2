// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
  if (n == 0) {
    return 1;
  }
  else if (n == 1) {
    return value;
  }
  else {
    return value * pown(value, n - 1);
  }
}

uint64_t fact(uint16_t n) {
  if (n<0) {
    return 0;
  }
  if (n == 0) {
    return 1;
  }
  else {
    return n * fact(n - 1);
  }
}

double calcItem(double x, uint16_t n) {
  return pown(x, n) / fact(n);
}

double expn(double x, uint16_t count) {
  double result = 1;
  for (count; count > 0; count--) {
    result += calcItem(x, count);
  }
  return result;
}

double sinn(double x, uint16_t count) {
  double res = 0;
  for (count; count > 0; count--) {
    res += pown(-1, count - 1)*calcItem(x, 2 * count - 1);
  }
  return res;
}

double cosn(double x, uint16_t count) {
  double res = 0;
  for (count; count > 0; count--) {
    res += pown(-1, count - 1)*calcItem(x, 2 * count - 2);
  }
}
