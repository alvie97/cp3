#include <cstdio>
using namespace std;

int p[20001], n;

void init() {
  int end = 2 * n;
  for (int i = 0; i < end; ++i) {
    p[i] = i;
  }
}

int enemies(int i) { return i + n; }

int find(int i) { return (p[i] == i) ? i : p[i] = find(p[i]); }

void merge(int x, int y) { 
  int u = find(x); int v = find(y);
  if (u == v)
    return;
  p[u] = v;
}

int main(int argc, char** argv) {
  //freopen("in.in", "r", stdin);
  //freopen("out.out", "w", stdout);
  int c, x, y;

  scanf("%d", &n);

  init();

  while(scanf("%d%d%d", &c, &x, &y), c || x || y) {
    switch(c) {
      case 1: // set friends
        if(find(x) == find(enemies(y)))
          puts("-1");
        else {
          merge(x, y);
          merge(enemies(x), enemies(y));
        }
        break;
      case 2: // set enemies
        if (find(x) == find(y))
          puts("-1");
        else {
          merge(x, enemies(y));
          merge(y, enemies(x));
        }
        break;
      case 3: // are friends
        (find(x) == find(y))? puts("1") : puts("0");
        break;
      default: // are enemies
        (find(x) == find(enemies(y))) ? puts("1") : puts("0");
    }
  }

  return 0;
}

