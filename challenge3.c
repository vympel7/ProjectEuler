#include <stdio.h>
#include <math.h>

int solve(long);
int isprime(long);

int main(void)
{
	int sol = solve(600851475143);
	printf("%d\n", sol);
	return 0;
}

int isprime(long x)
{
	if (!(x & 1)) return 0;
	long sq = pow(x, 0.5);
	for (long i = 3; i <= sq; i += 2)
	{
		if (!(x % i)) return 0;
	}
	return 1;
}

int solve(long x)
{
	long sq = pow(x, 0.5);
	long mi = 1;
	for (long i = 3; i <= sq; ++i)
	{
		if (x % i) continue;
		if (isprime(i)) mi = i;
	}
	return mi;
}