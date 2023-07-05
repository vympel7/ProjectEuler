#include <stdio.h>

size_t primes_sum(size_t limit);

int main(void)
{
	size_t result = primes_sum(2000000);
	printf("Result: %lu\n", result);
	return 0;
}

size_t primes_sum(size_t limit)
{
	size_t i = 0, j = 0, s = 2, size = limit >> 1, hsize = limit >> 2;
	size_t primes[size];
	primes[size - 1] = 0;

	for (; i < size - 1; ++i)
		primes[i] = i + i + 3;

	for (i = 0; i < hsize; ++i)
	{
		if (!primes[i]) continue;
		j = 3 * primes[i];
		while (j < limit)
		{
			primes[(j - 3) >> 1] = 0;
			j += 2 * primes[i];
		}
	}
	for (i = 0; i < size; ++i)
	{
		s += primes[i];
	}
	return s;
}