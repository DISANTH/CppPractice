#include <iostream>

using namespace std;

string reverseString(string data)
{
    int start = 0, end = data.size() - 1;

    while(start < end)
    {
        char startChar = data.at(start);
        char endChar = data.at(end);
        data.replace(start,1,1,endChar);
        data.replace(end,1,1,startChar);
        start++;
        end--;
    }
    return data;
}

int main()
{
    string data;
    cin >> data;
    cout << endl;
    cout << "reverseString :: " << reverseString(data) << endl;
    return 0;
}