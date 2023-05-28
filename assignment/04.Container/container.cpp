#include <numeric>
#include <queue>
#include "container.h"

using namespace std;

vector<vector<int>> next_max;
queue<int> box;

int find_next(){
    int max_idx = box.front() - 1;
    int ans = next_max[max_idx][0];

    for(int i=1;i<next_max[max_idx].size();i++){
        if(box_comp(ans, next_max[max_idx][i]) < 0) ans = next_max[max_idx][i];
    }

    return ans;
} //end of find_next()

void comp_max(int N){
    while(N>1){
        for(int i=0;i<N-1;i+=2) {
            int a = box.front(); box.pop();
            int b = box.front(); box.pop();

            if(box_comp(a, b) < 0) {box.push(b); next_max[b-1].push_back(a);}
            else {box.push(a); next_max[a-1].push_back(b);}
        }
        N = (N+1)/2;
    }
} //end of comp_max()

int main() {
    box_ready();

    int N = box_size();
    next_max.resize(N);
    for(int i=1;i<=N;i++) box.push(i);

    comp_max(N);
    box_report(find_next());

    return 0;
} //end of main()
