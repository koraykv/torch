#ifndef TH_RANDOM_INC
#define TH_RANDOM_INC

#include "THGeneral.h"

typedef struct THRandomState THRandomState;
void THRandom_init(THRandomState *state);
void THRandom_done(THRandomState *state);

/* In the functions below, you can pass NULL as @state to use a per-thread
 * common random generator state. */

/* Initializes the random number generator with the current time (granularity: seconds) and returns the seed. */
TH_API unsigned long THRandom_seed(THRandomState *state);

/* Initializes the random number generator with the given long "the_seed_". */
TH_API void THRandom_manualSeed(THRandomState *state, unsigned long the_seed_);

/* Returns the starting seed used. */
TH_API unsigned long THRandom_initialSeed(THRandomState *state);

/* Generates a uniform 32 bits integer. */
TH_API unsigned long THRandom_random(THRandomState *state);

/* Generates a uniform random number on [0,1[. */
TH_API double THRandom_uniform(THRandomState *state, double a, double b);

/** Generates a random number from a normal distribution.
    (With mean #mean# and standard deviation #stdv >= 0#).
*/
TH_API double THRandom_normal(THRandomState *state, double mean, double stdv);

/** Generates a random number from an exponential distribution.
    The density is $p(x) = lambda * exp(-lambda * x)$, where
    lambda is a positive number.
*/
TH_API double THRandom_exponential(THRandomState *state, double lambda);

/** Returns a random number from a Cauchy distribution.
    The Cauchy density is $p(x) = sigma/(pi*(sigma^2 + (x-median)^2))$
*/
TH_API double THRandom_cauchy(THRandomState *state, double median, double sigma);

/** Generates a random number from a log-normal distribution.
    (#mean > 0# is the mean of the log-normal distribution
    and #stdv# is its standard deviation).
*/
TH_API double THRandom_logNormal(THRandomState *state, double mean, double stdv);

/** Generates a random number from a geometric distribution.
    It returns an integer #i#, where $p(i) = (1-p) * p^(i-1)$.
    p must satisfy $0 < p < 1$.
*/
TH_API int THRandom_geometric(THRandomState *state, double p);

/* Returns true with probability $p$ and false with probability $1-p$ (p > 0). */
TH_API int THRandom_bernoulli(THRandomState *state, double p);

#endif
