#include <stdio.h>

int main(void)
{
	int t = 3, f = 5, ts = 0, fs = 0;
	for (; t < 1000; t += 3, f += 5)
	{
		if (t % 5) ts += t;
		if (f < 1000) fs += f;
	}
	printf("Result: %d\n", ts + fs);
	return 0;
}