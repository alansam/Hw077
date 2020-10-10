
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <limits.h>
#include <string.h>

#include "snap.h"

typedef struct ap ap;
struct ap {
  char name[10];
  void * a_ptr;
  size_t a_sz;
};

void show(ap const, ap const);

int main(int argc, char const * argv[]) {

  ap a0;
  ap a1;

  char carry[9] = { 'd', 'e', 'a', 'd', 'b', 'e', 'e', 'f', '\0', };
  size_t carry_sz = sizeof(carry);
  short sarry[2] = { SHRT_MIN, SHRT_MAX, };
  size_t sarry_sz = sizeof(sarry);
  int iarry[2] = { INT_MIN, INT_MAX, };
  size_t iarry_sz = sizeof(iarry);

  strcpy(a0.name, "cap");
  a0.a_ptr = &carry;
  a0.a_sz = carry_sz;
  strcpy(a1.name, "sap");
  a1.a_ptr = &sarry;
  a1.a_sz = sarry_sz;

  show(a0, a1);

  strcpy(a0.name, "sap");
  a0.a_ptr = &sarry;
  a0.a_sz = sarry_sz;
  strcpy(a1.name, "iap");
  a1.a_ptr = &iarry;
  a1.a_sz = iarry_sz;

  show(a0, a1);

  strcpy(a0.name, "cap");
  a0.a_ptr = &carry;
  a0.a_sz = carry_sz;
  strcpy(a1.name, "iap");
  a1.a_ptr = &iarry;
  a1.a_sz = iarry_sz;

  show(a0, a1);

  return 0;
}

void show(ap const ap0, ap const ap1) {
  void * ap0_b;
  void * ap0_e;
  void * ap1_b;
  void * ap1_e;
  void * sb;
  void * se;
  size_t s_sz;

  ap0_b = ap0.a_ptr;
  ap0_e = ap0_b + ap0.a_sz;
  ap1_b = ap1.a_ptr;
  ap1_e = ap1_b + ap1.a_sz;

  if (ap0_b > ap1_b) {
    sb = ap1_b;
    se = ap0_e;
  }
  else {
    sb = ap0_b;
    se = ap1_e;
  }
  s_sz = se - sb;

  printf("%1$6s - %2$p, %3$p, %4$3zu [0x%4$04zx]\n", ap0.name, ap0_b, ap0_e, ap0.a_sz);
  printf("%1$6s - %2$p, %3$p, %4$3zu [0x%4$04zx]\n", ap1.name, ap1_b, ap1_e, ap1.a_sz);

  printf("%1$6s - %2$p, %3$p, %4$3zu [0x%4$04zx]\n", "snap", sb, se, s_sz);
  snap(stdout, sb, s_sz);

  return;
}
