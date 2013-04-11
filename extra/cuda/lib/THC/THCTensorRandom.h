#ifndef TH_CUDA_TENSOR_RANDOM_INC
#define TH_CUDA_TENSOR_RANDOM_INC

#include "THCTensor.h"

THC_API unsigned long THCRandom_seed();
THC_API void THCRandom_manualSeed(unsigned long the_seed_);
THC_API unsigned long THCRandom_initialSeed();
THC_API unsigned long THCRandom_random();
THC_API unsigned long THCRandom_random1(long b);
THC_API unsigned long THCRandom_random2(long a, long b);
THC_API double THCRandom_uniform(double a, double b);
THC_API double THCRandom_normal(double mean, double stdv);
THC_API double THCRandom_exponential(double lambda);
THC_API double THCRandom_cauchy(double median, double sigma);
THC_API double THCRandom_logNormal(double mean, double stdv);
THC_API int THCRandom_geometric(double p);
THC_API int THCRandom_bernoulli(double p);

THC_API void THCudaTensor_random(THCudaTensor *self);
THC_API void THCudaTensor_random1(THCudaTensor *self, long b);
THC_API void THCudaTensor_random2(THCudaTensor *self, long a, long b);
THC_API void THCudaTensor_geometric(THCudaTensor *self, double p);
THC_API void THCudaTensor_bernoulli(THCudaTensor *self, double p);
THC_API void THCudaTensor_uniform(THCudaTensor *self, double a, double b);
THC_API void THCudaTensor_normal(THCudaTensor *self, double mean, double stdv);
THC_API void THCudaTensor_exponential(THCudaTensor *self, double lambda);
THC_API void THCudaTensor_cauchy(THCudaTensor *self, double median, double sigma);
THC_API void THCudaTensor_logNormal(THCudaTensor *self, double mean, double stdv);

#endif
