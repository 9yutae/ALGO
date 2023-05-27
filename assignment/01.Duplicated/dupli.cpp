#include <iostream>
#include <cmath>

using namespace std;

int N, init, tmp, root;
int min_val = 10001, comp_tot = 0, pow_tot = 0;

int calculate(int B){
    int pow_diff = 0, C;
    for(int i=min_val;i<min_val+N;i++) pow_diff += pow(i-init, 2);
    C = pow_tot - pow_diff;

    return sqrt(2*C - B*B);
} //end of calculate

int min_value(int tmp, int min_val){
    if(tmp<min_val) return tmp;
    return min_val;
} //end of min_value

int main() {
    cin >> N >> init;
    min_val = min_value(init, min_val);

    while(cin >> tmp) {
        min_val = min_value(tmp, min_val);
        comp_tot += (tmp - init);
        pow_tot += pow(tmp - init, 2);
    }

    int B = comp_tot + init*N - (2*min_val + N - 1)*N/2;

    root = calculate(B);
    cout << init + (B - root)/2 << "\n" << init + (B + root)/2 << endl;

    return 0;
} //end of main()
