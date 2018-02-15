#include <vector>
#include <map>
#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
  // freopen("out.out", "w", stdout);
  int n, m, input, k, v;
  int test_max;
  map< int, vector<int> > graph;

  while (scanf("%d %d", &n, &m) != EOF) {
    for (int i = 0; i < n; ++i) {
      scanf("%d", &input);
      graph[input].push_back(i);
    }
    
   while (m--) {
     scanf("%d%d", &k, &v);
     if (graph.find(v) != graph.end() && graph[v].size() >= k) {
       printf("%d\n", graph[v][k - 1] + 1);
     } else {
       puts("0");
     }
    }

    graph.clear();

  }
  return 0;
}