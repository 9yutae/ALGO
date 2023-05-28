#include <iostream>
#include <algorithm>

using namespace std;

int lastday, price[4], cnt[365] = {0, };
bool ride[365] = {0, };

void input(){
    int N, di, ri;

    for(int i=0;i<4;i++) cin >> price[i];
    cin >> N;

    while(N--){
        cin >> di >> ri;
        ride[di-1] = true;
        cnt[di-1] = ri;
        lastday = di;
    }
}

int DP(){
    int dp[lastday+3] = {};
    int mon = -4;

    for(int i=3;i<=lastday+2;i++){
        if(i%7 == 3) mon += 7;
        dp[i] = min({dp[i-1]+ride[i-3]*cnt[i-3]*price[0], dp[i-1]+price[1],
                     dp[i-3]+price[2], dp[mon-1]+price[3]});
    }

    return dp[lastday+2];
}

int main(){
    input();
    cout << DP();

    return 0;
}
