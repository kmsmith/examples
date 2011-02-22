#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void rand_pick(int* a, int sz, int n) {
    srand((unsigned)time(0));
    while (n > 0) {
        int i = rand() % sz;
        cout << i << endl;
        int r = a[sz-1];
        a[sz-1] = a[i];
        a[i] = r;
        --n; --sz;
    }
}


int main() {
    int a[5] = {1,2,3,4,5};
    rand_pick(a,5,3);
    cout << endl;
    for (int i = 0; i < 5; i++) {
        cout << a[i] << endl;
    }
    return 0;
}
