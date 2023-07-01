#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int ispalindrome(int);

int main(void)
{
	int m = 999, n = 999, mn = 0;
	for (; m >= 100; --m)
	{
		for (n = m; n >= 100; --n)
		{
			if (ispalindrome(m*n) && (m*n > mn))
			{
				mn = m*n;
			}
		}
	}
	printf("Result: %d\n", mn);
	return 0;
}

int ispalindrome(int x)
{
	int n = log10(x) + 1, i = 0;
	int* digits = (int*) calloc(n, sizeof(int));

	for (i = 0; i < n; ++i)
	{
		digits[i] = x % 10;
		x -= digits[i];
		x /= 10;
	}
	for (i = 0; i <= (n >> 1); ++i)
	{
		if (digits[i] != digits[n-i-1])
		{
			free(digits);
			return 0;
		}
	}
	free(digits);
	return 1;
}