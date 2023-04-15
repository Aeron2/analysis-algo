// I intend to live life, not just exist.
// Aeron
#include <bits/stdc++.h>
using namespace std;
#define max_size 7
vector<int> v(max_size);

void make_set(int x) { v[x] = x; }

int find_set(int x) { return (x == v[x]) ? x : find_set(v[x]); }
int union_set(int x, int y) {
  int xparent = find_set(x);
  int yparent = find_set(y);
  if (xparent == yparent)
    return xparent;
  v[yparent] = xparent;
  return xparent;
}
void prr() {
  for (int i = 1; i < max_size; i++) {
    cout << i << " : " << v[i] << endl;
  }
}
int main() {
  for (int i = 1; i < max_size; i++) {
    make_set(i);
  }
  union_set(2, 4);
  union_set(1, 3);
  union_set(3, 4);
  union_set(6, 5);
  union_set(6, 1);
  prr();
  cout << find_set(2) << endl;
  return 0;
}