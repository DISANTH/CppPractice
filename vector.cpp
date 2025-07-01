#include<iostream>
#include <vector>

using namespace std;

#include <iostream>
using namespace std;

int findMin(vector<int>& numbers,int L, int R)
{
	if(L == R)
	{
		return numbers[R];
	}
	return numbers[L]+ min(findMin(numbers));
}

int main() {
	int num;
	cin >> num;    //Reading input from STDIN
	cout << "Input number is " << num << endl;	// Writing output to STDOUT
}

int main()
{
    vector<int> vec(2);
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    cout << vec.size() << endl;
    return 0;
}