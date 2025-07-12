#include <iostream>
#include <set>

using namespace std;

void print(set<int> &st)
{
	cout << endl;
	for(const int& data: st)
	{
		cout << data << " " ;
	}

	cout << endl;
}

void basicSet()
{
	set<int> st; 
	st.insert(5);
	st.insert(4);
	st.insert(3);
	st.insert(2);
	st.insert(1);
	
	print(st);

	set<int>::iterator itr = st.find(3);

	if(itr != st.end())
	{
		itr = st.erase(itr);
		cout << *itr << endl;
	}

	st.erase(5);


	int cnt = st.count(4);

	cout << "4 contains " << cnt << endl;

	cnt = st.count(3);

	cout << "3 contains :: " << cnt << endl;

	print(st);

	st.insert(5);
	st.insert(3);

	print(st);

	set<int>::iterator itr1 = st.find(2);
	set<int>::iterator itr2 = st.find(4);

	st.erase(itr1, itr2); // erase in the range [2,4)
	
	print(st);
}

int main()
{
	basicSet();
	return 0;	
}
