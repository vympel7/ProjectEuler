#include <stdio.h>
#include <math.h>
#include "../vector/vector.h"

DECLARE_VECTOR(size_t)

vector_size_t* primes_sieve(size_t limit, vector_size_t* known);

int main(void)
{
	size_t limit = 104744;
	vector_size_t* curr = primes_sieve(limit, NULL);
	printf("%lu\n", curr->size);
	printf("%lu\n", curr->data[10000]);
	vector_free_size_t(curr);
	return 0;
}

vector_size_t* primes_sieve(size_t limit, vector_size_t* known)
{
	size_t i = 0, j = 0;
	vector_size_t* primes;
	if (known != NULL)
	{
		primes = vector_create_size_t(limit);
		vector_assign_size_t(primes, known, 0, 0, known->size);
		i = known->data[known->size - 1];
	}
	else
		primes = vector_create_size_t(limit);

	for (; i < primes->capacity && (i + 2) < limit; ++i)
		vector_push_back_size_t(primes, i + 2);

	for (i = 2; i < (limit >> 1) + 1;)
	{
		j = i + i;
		while (j < limit)
		{
			vector_remove_first_size_t(primes, j);
			j += i;
		}
		for (j = 0; j < primes->size; ++j)
		{
			if (vector_at_size_t(primes, j) > i) break;
		}
		i = vector_at_size_t(primes, j);
	}
	vector_shrink_to_fit_size_t(primes);
	return primes;
}