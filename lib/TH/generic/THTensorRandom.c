#ifndef TH_GENERIC_FILE
#define TH_GENERIC_FILE "generic/THTensorRandom.c"
#else

TH_API void THTensor_(random)(THTensor *self, THRandomState *state)
{
#if defined(TH_REAL_IS_BYTE)
  TH_TENSOR_APPLY(real, self, *self_data = (unsigned char)(THRandom_random(state) % (UCHAR_MAX+1)););
#elif defined(TH_REAL_IS_CHAR)
  TH_TENSOR_APPLY(real, self, *self_data = (char)(THRandom_random(state) % (CHAR_MAX+1)););
#elif defined(TH_REAL_IS_SHORT)
  TH_TENSOR_APPLY(real, self, *self_data = (short)(THRandom_random(state) % (SHRT_MAX+1)););
#elif defined(TH_REAL_IS_INT)
  TH_TENSOR_APPLY(real, self, *self_data = (int)(THRandom_random(state) % (INT_MAX+1UL)););
#elif defined(TH_REAL_IS_LONG)
  TH_TENSOR_APPLY(real, self, *self_data = (long)(THRandom_random(state) % (LONG_MAX+1UL)););
#elif defined(TH_REAL_IS_FLOAT)
  TH_TENSOR_APPLY(real, self, *self_data = (float)(THRandom_random(state) % ((1UL << FLT_MANT_DIG)+1)););
#elif defined(TH_REAL_IS_DOUBLE)
  TH_TENSOR_APPLY(real, self, *self_data = (float)(THRandom_random(state) % ((1UL << DBL_MANT_DIG)+1)););
#else
#error "Unknown type"
#endif
}

TH_API void THTensor_(geometric)(THTensor *self, THRandomState *state, double p)
{
  TH_TENSOR_APPLY(real, self, *self_data = (real)THRandom_geometric(state, p););
}

TH_API void THTensor_(bernoulli)(THTensor *self, THRandomState *state, double p)
{
  TH_TENSOR_APPLY(real, self, *self_data = (real)THRandom_bernoulli(state, p););
}

#if defined(TH_REAL_IS_FLOAT) || defined(TH_REAL_IS_DOUBLE)

TH_API void THTensor_(uniform)(THTensor *self, THRandomState *state, double a, double b)
{
  TH_TENSOR_APPLY(real, self, *self_data = (real)THRandom_uniform(state, a, b););
}

TH_API void THTensor_(normal)(THTensor *self, THRandomState *state, double mean, double stdv)
{
  TH_TENSOR_APPLY(real, self, *self_data = (real)THRandom_normal(state, mean, stdv););
}

TH_API void THTensor_(exponential)(THTensor *self, THRandomState *state, double lambda)
{
  TH_TENSOR_APPLY(real, self, *self_data = (real)THRandom_exponential(state, lambda););
}

TH_API void THTensor_(cauchy)(THTensor *self, THRandomState *state, double median, double sigma)
{
  TH_TENSOR_APPLY(real, self, *self_data = (real)THRandom_cauchy(state, median, sigma););
}

TH_API void THTensor_(logNormal)(THTensor *self, THRandomState *state, double mean, double stdv)
{
  TH_TENSOR_APPLY(real, self, *self_data = (real)THRandom_logNormal(state, mean, stdv););
}

#endif

#endif
