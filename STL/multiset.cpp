#include <iostream>
#include <set>

using namespace std;

template<typename T>
void print(multiset<T> &mst)
{
	cout << endl;
	for(const T& data: mst)
	{
		cout << data << " ";
	}
	cout << endl;
}


void multiSetExample()
{
	multiset<int> mst;

	mst.insert(1);
	mst.insert(1);
	mst.insert(1);

	print<int>(mst);

	int cnt = mst.count(1);

	cout << "1 count is " << cnt << endl;

//	mst.erase(1); //  all 1's will be erased
	
//	cnt = mst.count(1);

//	cout << "1 count :: " << cnt << endl;
	
	multiset<int>::iterator itr = mst.find(1);

	//mst.erase(mst.find(1), mst.find(1) + 2);

	print<int>(mst);


		
}

int main()
{
	multiSetExample();
	return 0;
}

