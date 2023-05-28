#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<pair<vector<int>,int>> blocks;
vector<int> fish, block;

int divide(int start, int last){
    blocks.clear();
    block.clear();

    int i;
    for(i=start-1;i<last;i++){
        if(!block.empty() && fish[i]!=block.back()+1){
            blocks.push_back({block, i});
            block.clear();
        }
        if(fish[i]!=i+1) block.push_back(fish[i]);
    }

    if(!block.empty()) blocks.push_back({block, i});

    return blocks.size();
}//end of divide()

void flip(int a, int b){
    stack<int> flip;
    int i = blocks[a].second - blocks[a].first.size();
    int j = blocks[b].second;

    for(int k=i;k<j;k++) flip.push(-fish[k]);
    for(int k=i;k<j;k++) {fish[k] = flip.top(); flip.pop();}
}//end of flip()

bool is_twice(int N, int cnt){
    if(cnt == 2){
        if(blocks[0].first.front() > blocks[1].first.front() && blocks[0].first.front() < 0) flip(0,0);
        else flip(0,1);
    }
    else if(cnt == 3){
        if(blocks[0].first.front() > 0) flip(0,1);
        else if(blocks[2].first.front() < 0) flip(0,2);
        else flip(1,2);
    }

    if(divide(1,N) == 1) return true;
    return false;
}//end of is_twice()

int res(int N){
    int block_cnt = divide(1, N);
    if(block_cnt == 1) return 1;
    else if(is_twice(N, block_cnt)) return 2;
    else return 0;
}//end of res()

int main() {
    int N, num;
    cin >> N;

    for(int i=0;i<5;i++){
        fish.clear();

        for(int j=0;j<N;j++){
            cin >> num;
            fish.push_back(num);
        }

        switch(res(N)){
            case 1:
                cout << "one" << endl; break;
            case 2:
                cout << "two" << endl; break;
            case 0:
                cout << "over" << endl; break;
        }
    }

    return 0;
} //end of main()
