#include <stdio.h>

int solve(int, int, int);

int main(void)
{
	int sol = solve(0, 1, 1);
	printf("%d\n", sol);
	return 0;
}

int f = 0;
int solve(int s, int f1, int f2)
{
	f = f1 + f2;
	if (f >= 4000000) return s;
	if (!(f & 1)) s += f;
	solve(s, f2, f);
}