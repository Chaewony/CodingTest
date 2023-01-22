#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

int main()
{
    vector<string> input;
    string str;
    getline(cin, str);
    stringstream ss(str);
    string str2;
    while (ss >> str2) {
        input.push_back(str2);
    }
    cout << input.size();
}