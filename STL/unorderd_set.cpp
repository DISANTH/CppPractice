#include <iostream>
#include <unordered_set>

using namespace std;

/*
 * They do not store everything sorted order
 * All Operations works on O(1) and in worst case once in a moon it will take O(n)
 * Lowebound and Upper Bound will not work on unorder map
 */

template<typename T>
void print(unordered_set<T> &uSet)
{
	cout << endl;

	for(const T &data: uSet)
	{
		cout << data << " " ;
	}

	cout  << endl;
}


void exercise()
{
	unordered_set<int> st;
	st.insert(10);
	st.insert(2);
	st.insert(30);
	st.insert(-1);

	print<int>(st);
}

int main()
{
	exercise();
	return 0;
}

