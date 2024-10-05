#pragma once

void BuildTree(int* a, int n);
void LinkTree(int* t, int* a, int n);
void Update(int* t, int idx, int val, int n);
int PartialSum(int* t, int l, int r);