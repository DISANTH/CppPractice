#include <iostream>
#include <queue>

using namespace std;

void maxQueue()
{
	priority_queue<int,vector<int>, less<int> > pq;
	pq.push(5);
	pq.push(10);
	pq.push(20);
	pq.emplace(30);

	cout << pq.top() << endl;
	pq.pop();

	cout << pq.top() << endl;
}


void minQueue()
{
	priority_queue<int, vector<int>, greater<int>> pq;
	pq.push(5);
	pq.push(10);
	pq.push(3);
	pq.push(1);
	pq.emplace(-1);

	cout << pq.top() << endl;
	pq.pop();

	cout << pq.top() << endl;
}

int main()
{
	maxQueue();
	minQueue();
	return 0;
}
