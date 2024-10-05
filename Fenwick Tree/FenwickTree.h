#pragma once

// Convert a[] into a Fenwick tree.
char ConvertTree(int* a, int n);
// Create a new Fenwick tree t[] based on a[].
void CreateTree(int* t, int* a, int n);\
// Update t[idx] into val.
char Update(int* t, int idx, int val, int n);
// Compute the partial sum t[l, r].
int PartialSum(int* t, int l, int r);