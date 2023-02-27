#include <iostream>
#include <vector>
#include <cstring>
#include <bits/stdc++.h>
using namespace std;

int n, m;
map<int, bool> visited;
map<int, vector<int> > adj;
vector<int> start_state;

void task1(int v)
{
    visited[v] = true;
    cout << v << "\n";

    for (vector<int>::iterator i = adj[v].begin(); i != adj[v].end(); ++i) {
        if (visited[*i] == false) {
            task1(*i);
        }
    }
}


void task2(vector<int> path, int size)
{
    int count = 0, path_size = path.size();
    start_state.clear();
    for (int i = 0;  i < n; ++i) {
        start_state.push_back(i);                                
    }
    

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < path_size; j++) {
            start_state[i] = adj[start_state[i]][path[j]];
        }
        int first = start_state[0];
        if (start_state[i] == first) {
            count++;
            if (count == n) {
                for (int i = 0; i < path_size; i++) {
                    cout << path[i] << endl;
                }
                exit(0);
            }
        }
    }

    if (path_size == size) {
        return;
    }

    for (int i = 0; i < m; i++) {
        path.push_back(i);
        task2(path, size);
        path.pop_back();
    }
}

int main(int argc, char* argv[]) {
    int s;
    cin >> n >> m >> s;
    int states[s];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int nr;
            cin >> nr;
            adj[i].push_back(nr);
        }
    }

    int nr;
    for (int i = 0; i < s; i++) {
        cin >> nr;
        states[i] = nr;
    }

    if (strcmp(argv[1], "accessible") == 0) {
        for (int i = 0; i < s; i++) {
            if (visited[states[i]] == false) {
                task1(states[i]);
            }
        }
    }

    if (strcmp(argv[1], "synchronize") == 0) {
        for (int i = 0; i < n; i++) {
            vector<int> path;
            task2(path, i);
        }
    }

    return 0;
}
