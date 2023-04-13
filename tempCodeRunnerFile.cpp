Here's the modified code without using vectors:

```
#include <iostream>
#include <queue>

using namespace std;

const int MAXN = 1005;
int indeg[MAXN];
int adj[MAXN][MAXN];
int order[MAXN];

int* topologicalSort(int n) {
    queue<int> que;
    for (int i = 0; i < n; i++) {
        if (indeg[i] == 0) {
            que.push(i);
        }
    }

    int k = 0;
    while (!que.empty()) {
        int x = que.front();
        que.pop();
        order[k++] = x;
        for (int i = 0; i < n; i++) {
            if (adj[x][i]) {
                indeg[i]--;
                if (indeg[i] == 0) {
                    que.push(i);
                }
            }
        }
    }

    if (k != n) {
        cout << "Cycle Present!" << endl;
        return nullptr;
    }
    
    return order;
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
        indeg[v]++;
    }

    int* order = topologicalSort(n);
    
    if (order != nullptr) {
        for (int i = 0; i < n; i++) {
            cout << order[i] << \" ";
        }
    }
    
    return 0;
}
```