#include "FenwickTree.h"


// i & -i this operation preserves the right-most 1 of i and change all other bits to 0

// Convert array a to a Fenwick tree
void BuildTree(int* a, int n)
{
	a[0] = 0x7fffffff;
	for (int i = 1; i <= n; i++)
		if (i + (i & -i) <= n)  a[i + (i & -i)] += a[i];
}



// Link the array a to a tree t
void LinkTree(int* t, int* a, int n)
{
	t[0] = 0x7fffffff;
	memset(t + 1, 0, n * sizeof(int));
	for (int i = 1; i <= n; i++) {
		t[i] += a[i - 1];
		if (i + (i & -i) <= n)  t[i + (i & -i)] += t[i];
	}
}



// 
void Update(int* t, int idx, int val, int n)
{
	if (t[0] != 0x7fffffff) {
		printf("t[] is not a tree!\n");
		return;
	}
	if (idx <= 0) {
		printf("idx should be >0!\n");
		return;
	}
	int dif = val - t[idx];
	for (; idx <= n; idx += (idx & -idx))  t[idx] += dif;
}



int PartialSum(int* t, int l, int r)
{
	if (t[0] != 0x7fffffff) {
		printf("t[] is not a tree!\n");
		return;
	}
	int sum = 0;
	for (; r; r -= r & -r)  sum += t[r];
	for (l--; l; l -= l & -l)  sum -= t[l];
	return sum;
}