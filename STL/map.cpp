#include <iostream>
#include <map>

using namespace std;

/*
 * map stores unique keys in sorted order...
 * All Operations will work in O(log n) time
 * */

/*
 * erase, size, find, emplace, insert()....
 * */

template<typename K, typename V>
void print(map<K,V> &mp)
{
	cout << endl << "{\n";
	for(const pair<K,V> &nodeData: mp)
	{
		cout << "	{" << nodeData.first << " : " << nodeData.second << " } " << endl;
	}
	cout << "}" << endl;
}

void exercise()
{
	map<int,int> mp;
	mp.insert({1,2});
	mp.emplace(2,2);
	mp[0] = 10;

	print<int,int>(mp);	
}

int main()
{
	exercise();
	return 0;
}
