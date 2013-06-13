#ifndef TH_GENERIC_FILE
#define TH_GENERIC_FILE "generic/THTensorRandom.h"
#else

typedef struct THRandomState THRandomState;

TH_API void THTensor_(random)(THTensor *self, THRandomState *state);
TH_API void THTensor_(geometric)(THTensor *self, THRandomState *state, double p);
TH_API void THTensor_(bernoulli)(THTensor *self, THRandomState *state, double p);

#if defined(TH_REAL_IS_FLOAT) || defined(TH_REAL_IS_DOUBLE)
TH_API void THTensor_(uniform)(THTensor *self, THRandomState *state, double a, double b);
TH_API void THTensor_(normal)(THTensor *self, THRandomState *state, double mean, double stdv);
TH_API void THTensor_(exponential)(THTensor *self, THRandomState *state, double lambda);
TH_API void THTensor_(cauchy)(THTensor *self, THRandomState *state, double median, double sigma);
TH_API void THTensor_(logNormal)(THTensor *self, THRandomState *state, double mean, double stdv);
#endif

#endif
