#include <iostream>
#include <map>
#include <vector>

using namespace std;

/*
 * Complete the 'minimumBribes' function below.
 *
 * The function accepts INTEGER_ARRAY q as parameter 
*/
void printPosition( map<int,int>& pos ) {
    for( auto itr = pos.begin(); itr!=pos.end(); itr++ ) {
        cout << itr->first << ":" << itr->second << ",";
    }
    cout << endl;
}

void minimumBribes( vector<int> q ) {
    map<int,int> pos;
    int i = 0, place;
    int jumps = 0;
    int bribes = 0;
    for( i=1; i<= q.size(); i++ ) {
        pos [ i ] = i; 
    }

    for( i = 0; i< q.size(); i++ ) {
        printPosition( pos );
        place = i+1;

        // is person in his place.
        if( place != q[ i ] ) {
            // lets find the jump
            jumps = pos[ q [ i ] ] - place;
            if( jumps > 2 ) {
                cout << "Too chaotic" << endl;
                return;
            }
            for(int j = place; j < pos[ q [i ] ]; j++ ) {
                pos[ j ] = pos[ j ] + 1;
            }
            pos[ q [i ] ] = place;
            bribes += jumps;
        }
    }
    cout << bribes << endl;
}

int main() {
    static const int arr[] = { 1,2,5,3,7,8,6,4 };
    vector<int> q( arr, arr + sizeof(arr)/sizeof(arr[0]) );
    minimumBribes( q );
    return 0;
}

