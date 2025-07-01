#include <iostream>
#include <vector>

using namespace std;

int lengthOfLongestSubstring(string s)
{
    vector<int> character(256,0);

    int left = 0, right = 0;
    int longestSubString = 0;
    
    while(right < s.size())
    {
        char charAtEnd = s[right];
        while(character[charAtEnd] > 0)
        {
            char charAtStart = s[left];
            character[charAtStart] -= charAtStart;
            left++;
        }
        character[charAtEnd] = charAtEnd;

        longestSubString = max(longestSubString, right-left+1);
        right++; 
    }
    return longestSubString;
}

int main()
{
    string data;
    cin >> data;

    cout << lengthOfLongestSubstring(data) << endl;
    return 0;
}