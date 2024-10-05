#include "FenwickTree.h"


// i & -i this operation preserves the right-most 1 of i and change all other bits to 0

char ConvertTree(int* a, int n)
{
	if (a[0] != 0x7fffffff) {
		printf("error: a[] shouldn't start from index zero.\n");
		return -1;
	}
	for (int i = 1; i <= n; i++)
		if (i + (i & -i) <= n)  a[i + (i & -i)] += a[i];
	return 1;
}



void CreateTree(int* t, int* a, int n)
{
	t[0] = 0x7fffffff;
	memset(t + 1, 0, n * sizeof(int));
	for (int i = 1; i <= n; i++) {
		t[i] += a[i - 1];
		if (i + (i & -i) <= n)  t[i + (i & -i)] += t[i];
	}
}



char Update(int* t, int idx, int val, int n)
{
	if (t[0] != 0x7fffffff) {
		printf("error: t[] is not a tree.\n");
		return -1;
	}
	if (idx <= 0) {
		printf("error: idx <= 0.\n");
		return -2;
	}
	int dif = val - t[idx];
	for (; idx <= n; idx += (idx & -idx))  t[idx] += dif;
	return 1;
}



int PartialSum(int* t, int l, int r)
{
	if (t[0] != 0x7fffffff) {
		printf("error: t[] is not a tree.\n");
		return 0x7fffffff;
	}
	int sum = 0;
	for (; r; r -= r & -r)  sum += t[r];
	for (l--; l; l -= l & -l)  sum -= t[l];
	return sum;
}