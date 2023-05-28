#include <iostream>
#include <vector>

using namespace std;

struct coord{
    double x, y, z;
};

vector<coord> station;

int main() {
    double x, y, z;
    for(int i=0;i<4;i++){
        coord tmp;
        cin >> tmp.x >> tmp.y >> tmp.z;
        station.push_back(tmp);
    }

    double dist1, dist2;

    while(){
        dist1 = shortest_dist(f)
    }


    return 0;
} //end of main()
