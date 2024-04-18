#include <iostream>
#include <vector>
#include <climits>
#include <fstream>
using namespace std;

const int INF = INT_MAX;
const int MAXN = 100005;

vector<pair<int, int>> graph[MAXN];
int dist[MAXN];
bool visited[MAXN];

int minDistance(int n) {
    int minDist = INF, minNode = -1;
    for (int i = 1; i <= n; i++) {
        if (!visited[i] && dist[i] < minDist) {
            minDist = dist[i];
            minNode = i;
        }
    }
    return minNode;
}

void dijkstra(int start, int n, string output) {
    ofstream fout(output);

    for (int i = 1; i <= n; i++) {
        dist[i] = INF;
        visited[i] = false;
    }
    dist[start] = 0;

    for (int i = 1; i <= n; i++) {
        int u = minDistance(n);
        visited[u] = true;

        for (auto neighbor : graph[u]) {
            int v = neighbor.first;
            int w = neighbor.second;
            if (!visited[v] && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    // Afisam distantele minime
    for (int i = 1; i <= n; i++) {
        if (dist[i] == INF) {
            fout << "INF ";
        }
        else {
            fout << dist[i] << " ";
        }
    }
    fout.close();
}

int main() {
    int n, m,s;
    string input = "input.txt";
    string output = "output.txt";

    ifstream fin(input);
    fin >> n >> m >> s;

    for (int i = 1; i <= m; i++) {
        int u, v, w;
        fin >> u >> v >> w;
        graph[u].push_back({ v, w });
        //graph[v].push_back({ u, w }); // Daca graful este neorientat, adaugam muchiile in ambele directii
    }
    fin.close();
    dijkstra(s, n, output);

    return 0;
}
/*
9 14
0 1 4
1 2 8
2 3 7
3 4 9
4 5 10
5 3 14
5 2 4
2 8 2
8 6 6
6 5 2
6 7 1
0 7 8
1 7 11
7 8 7



5 7
1 3 4
1 4 1
2 1 1
2 3 4
3 1 1
3 4 1
4 5 1
*/