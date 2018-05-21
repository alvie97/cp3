#include <cstdio>
#include <set>
#include <cstring>
using namespace std;

#define MAX_BUFF 256
class ufd {
public:
	int p[105], r[105], set_size[105], sets;
	ufd(int n) {
		sets = n;
		for (int i = 0; i < n; ++i) 
			p[i] = i, r[i] = 0, set_size[i] = 1;
	}

	bool same_set(int u, int v) { return find(u) == find(v); }

	int find(int x) { 
		return (p[x] == x)? x: p[x] = find(p[x]); 
	}

	void merge(int x, int y) {
		int px = find(x), py = find(y);
		if (px != py) {
			if (r[px] > r[py]) {
				p[px] = py;
			} else {
				p[py] = px;
				if (r[px] == r[py])
					++r[py];
			}
			--sets;
		}
	}

	int number_sets() { return sets; }
};

int main() {
	#ifdef DEBUG
	freopen("in.in", "r", stdin);
	#endif
	int tt;
	int p, t, n_p, n_t;
	set<int> person[105];
	scanf("%d", &tt);

	while (tt--) {
		char line[MAX_BUFF];
		scanf("%d %d", &n_p, &n_t);
		ufd people(n_p);
		while (getchar() != '\n');
		while ( fgets(line, MAX_BUFF, stdin) != NULL && line[0] != '\n' ) {
			p = line[0] - '0';
			t = line[2] - '0';
			--p; --t;
			person[p].insert(t);
		}

		for (int i = 0; i < n_p; ++i) {
			for (int j = 0; j < n_p; ++j) {
				if (i == j || people.same_set(i, j)) continue;
				if (person[i] == person[j])
					people.merge(i, j);
			}
		}
		printf("%d\n", people.number_sets());	
		if (tt) puts("");
		for (int i = 0; i < n_p; ++i)
			person[i].clear();
	}

	return 0;
}
