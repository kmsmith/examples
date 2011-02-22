#include <iostream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

double average(const vector<double> & v);

int main() {
    vector<double> v(0);
    string temp;

    while (!getline(cin, temp).eof()) {
        stringstream ss(temp);
        double d;
        if (!(ss >> d).fail()) {
            v.push_back(d);
        }
    }

    cout << "Average:  " << average(v) << endl;

    return 0;
}

double average(const vector<double> & v) {
    double sum = 0;
    for (int i = 0; i < v.size(); i++) {
        sum += v[i];
    }
    return sum/v.size();
}
