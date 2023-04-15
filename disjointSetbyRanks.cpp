// I intend to live life, not just exist.
// Aeron
#include <bits/stdc++.h>
using namespace std;
#define size 8

vector<pair<int, int>> v(size);

void make_set(int x) {
  v[x].first = x;
  v[x].second = 0;
}
int find_set(int x) { return (v[x].first == x) ? x : find_set(v[x].first); }
void union_set(int x, int y) {
  int xx = find_set(x);
  int yy = find_set(y);
  if (xx == yy) {
    return;
  }
  if (v[xx].second < v[yy].second) {
    v[xx].first = yy;
  } else if (v[xx].second > v[yy].second) {
    v[yy].first = xx;
  } else {
    v[yy].first = xx;
    v[xx].second++;
  }
}
void prr() {
  cout << "  Value  |  Parent  |  Rank  " << endl;
  for (int i = 1; i < size; i++) {
    cout << "    " << i << "    |    " << v[i].first << "     |   "
         << v[i].second << endl;
  }
}

int main() {
  for (int i = 1; i < size; i++) {
    make_set(i);
  }
  union_set(1, 2);
  union_set(4, 7);
  union_set(5, 3);
  union_set(6, 4);
  union_set(2, 4);
  union_set(7, 3);
  union_set(1, 3);
  prr();
  return 0;
}