#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// https://leetcode.com/problem-list/7p5x763/?sorting=W3sic29ydE9yZGVyIjoiREVTQ0VORElORyIsIm9yZGVyQnkiOiJGUkVRVUVOQ1kifV0%3D&page=1


class Solution {
public:
    int getNextIndex(string &s, int currentIndex, char lastCharacter)
    {
        if(currentIndex == -1)
        {
            return 0;
        }
        int nextIndex = -1;
        for(int i = currentIndex; i < s.size(); i++)
        {
            if(s[i] != lastCharacter)
            {
                nextIndex = i;
                break;
            }
        }
        return nextIndex;
    }

    void print(vector<int> vec)
    {
        for(int& data:vec)
        {
            cout << " " << data;
        }
        cout << endl;
    }

    long long numberOfWays(string &s, vector<int> result, int currentIndex, char lastCharacter)
    {
        if(result.size() == 3)
        {
            print(result);
            return 1;
        }
        else if(currentIndex == s.size())
        {
            return 0;
        }
        else{
            int nextIndex = getNextIndex(s,currentIndex,lastCharacter);            
            if(nextIndex != -1)
            {
                long long numWays = numberOfWays(s,result, nextIndex+1, lastCharacter);
                result.push_back(nextIndex);
                lastCharacter = s[nextIndex];
                numWays += numberOfWays(s,result,nextIndex+1,lastCharacter);
                return numWays;
            }
            else{
                return 0;
            }
        }
    }
    long long numberOfWays(string s) {
        vector<int> result;
        return numberOfWays(s,result, -1, '2');
    }
};

int main()
{
    Solution sol;
    string inputData;
    cin >> inputData;
    cout << sol.numberOfWays(inputData);
}