#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> cases;
vector<int> ca, wa;
bool visited[21][21][21];

void dfs(vector<int> state){
    if(visited[state[0]][state[1]][state[2]]) return;
    cases.push_back(state);
    visited[state[0]][state[1]][state[2]] = true;

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(i==j) continue;

            vector<int> next = state;
            int amount = min(state[i], ca[j] - state[j]);

            next[i] -= amount;
            next[j] += amount;

            dfs(next);
        }
    }
}

void input(){
    int n;
    for(int i=0;i<3;i++) {cin >> n; ca.push_back(n);}
    for(int i=0;i<3;i++) {cin >> n; wa.push_back(n);}
}

int main() {
    input();
    dfs(wa);

    cout << cases.size() << endl;

    return 0;
}
