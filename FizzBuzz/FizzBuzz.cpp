#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
    for (int i = 1; i < 101; i++)
    {
        string line;
        if (i % 3 == 0)
            line += "Fizz";
        if (i % 5 == 0)
            line += "Buzz";
        if (i % 3 && i % 5)
            line = static_cast<ostringstream*>(&(ostringstream() << i))->str();
        cout << line << endl;
    }
    return 0;
}
