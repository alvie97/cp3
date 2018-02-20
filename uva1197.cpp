#include <cstdio>
#include <vector>
using namespace std;

#define vi vector<int>
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

int main(int argc, char** argv) {
  int n, m, k, first_suspect; 


  while (scanf("%d %d", &n, &m), n || m) {

    ufd dt(n);

    for (int i = 0; i < m; i++) {
      int ln, inpt, inpt2;
      scanf("%d", &ln);
      scanf("%d", &inpt);
      --ln;
      while (ln--) {
        scanf("%d", &inpt2);
        dt.merge(inpt, inpt2);
      }
    }

    int cnt = 1;

    for (int i = 1; i < n; ++i) {
      if (dt.same_set(0, i)) {
        ++cnt;
      }
    } 
    printf("%d\n", cnt);
  }


  return 0;
}
