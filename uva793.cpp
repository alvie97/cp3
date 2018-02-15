#include <vector>
#include <stdio.h>

#define vi std::vector<int>

class ufd{
  public:
    vi p, rank;
    ufd(int n){
      rank.assign(n, 0);
      p.assign(n, 0);
      for(int i = 0; i < n; i++)
        p[i] = i;
    }
    int find(int i){ return (p[i] == i)? i: (p[i] = find(p[i])); }
    bool same_set(int x, int y) { return find(x) == find(y); }
    void merge(int x, int y){
      if (!same_set(x, y)){
        int u = find(x); int v = find(y);
        if (rank[u] > rank[v])
          p[v] = u;
        else {
          p[u] = v;
          if (rank[u] == rank[v])
            ++rank[v];
        }
      }
    }
};

int main(int argc, char* argv[]) {
  int t, n, successful, unsuccessful, idx0, idx1;
  char line[256], c, query[5];

  scanf("%d", &t);

  while (t--) {
    successful = unsuccessful = 0;
    scanf("%d", &n);
    ufd network(n);
    while((c = getchar()) != '\n' && c != EOF) {}
    while (fgets(line, sizeof(line), stdin) && line[0] != '\n') {
      sscanf(line, "%s %d %d", query, &idx0, &idx1);
      if (line[0] == 'c') {
        network.merge(idx0 - 1, idx1 - 1);
      } else {
        if (network.same_set(idx0 - 1, idx1 - 1)) {
          ++successful;
        } else {
          ++unsuccessful;
        }
      }
    }

    printf("%d,%d\n", successful, unsuccessful);
    if (t) puts("");
  }
  return 0;
}


