#ifndef FIXEDPOINT_H
#define FIXEDPOINT_H

#include <stdint.h>

#define FP_BITS 24
#define FP_WBITS 11
#define FP_FBITS 13

typedef int32_t fp;
typedef int64_t fpd;

#define FP_ONE (1 << FP_FBITS)
#define FP_HALF (1 << (FP_FBITS - 1))
#define FP_MAX ((1 << (FP_BITS - 1)) - 1)
#define FP_MIN (-(1 << (FP_BITS - 1)))

// Conversion functions
#define fl2fp(R) ((fp)((R) * FP_ONE + ((R) >= 0 ? 0.5 : -0.5)))
#define i2fp(I) ((fp)(I) << FP_FBITS)
#define fp2i(F) ((F) >> FP_FBITS)
#define fp2fl(F) ((float)(F) / FP_ONE)

// Basic arithmetic operations
static inline fp fp_add(fp A, fp B) { return A + B; }
static inline fp fp_sub(fp A, fp B) { return A - B; }
static inline fp fp_mul(fp A, fp B)
{
  return (fp)(((fpd)A * (fpd)B) >> FP_FBITS);
}
static inline fp fp_div(fp A, fp B)
{
  return (fp)(((fpd)A << FP_FBITS) / B);
}

// Square root function
static inline fp fp_sqrt(fp A)
{
  if (A < 0)
    return FP_MIN;
  fp res = A, delta;
  do
  {
    delta = (fp_div(A, res) - res) >> 1;
    res += delta;
  } while (delta != 0);
  return res;
}

#endif // FIXEDPOINT_H
