#include <iostream>
#include <string>
#include <cstring>
#include <math.h>

using namespace std;

int a2i(const char* a) {
    int len = strlen(a);
    cout << len << endl;
    int sum = 0;
    int i = 0;
    for (int mult = pow(10,len-1); mult >= 1; mult /= 10, i++) {
        sum += (a[i]-'0') * mult;
    }
    return sum;
}

int main() {
    string test("123");
    cout << a2i(test.c_str()) << endl;
    return 0;
}
