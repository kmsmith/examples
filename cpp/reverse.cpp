#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <iterator>
#include <algorithm>
#include <istream>
#include <ostream>

using namespace std;

void reverse(string & input) {
    int len = input.length();
    for (int i = 0; i < len/2; i++) {
        char a = input[i];
        input[i] = input[len-1-i];
        input[len-1-i] = a;
    }
}

void split(vector<string> & results, const string & input) {
    stringstream ss(input);

    istream_iterator<string> it(ss);
    istream_iterator<string> stream_end();  // default ctor makes eos iter
    //copy(it, stream_end, back_inserter(results));  // assuming given vector is empty
    //vector<string> words(it, stream_end);
    //results = words;
}

int main() {

    deque<std::string> user_nums;
    copy(istream_iterator<std::string>(cin), istream_iterator<std::string>(), front_inserter(user_nums));
    copy(user_nums.begin(), user_nums.end(), ostream_iterator<std::string>(cout, " "));

    string input;
    getline(cin, input);
    reverse(input);
    cout << input << endl;

    vector<string> words;
    //split(words, input);
    stringstream ss(input);

    istream_iterator<string> ss_begin(ss);
    istream_iterator<string> ss_end();  // default ctor makes eos iter
    //vector<string>(ss_begin, ss_end);
    //copy(ss_begin, ss_end, back_inserter(words));  // assuming given vector is empty

    //copy(words.begin(), words.end(), ostream_iterator<string>(cout));

    return 0;
}
