#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<string> vec;
    for (int i = 0; i < n; i++) {
        string c;
        cin >> c;
        vec.push_back(c);
    }
     
    vector<string> str;
    
    for (int i = 0; i < n; i++) {
        vector<char> vec2;
        for (int j = 0; j < vec[i].size(); j++) {
            if (vec[i][j] == '(')
                vec2.push_back('(');
            else if (vec2.empty()) {
                vec2.push_back(')');
                break;
            }
            else
                vec2.pop_back();
        }
        if (vec2.empty())
            str.push_back("YES");
        else
            str.push_back("NO");
    }

    for (auto i : str)
        cout << i << "\n";
}