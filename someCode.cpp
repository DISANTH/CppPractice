#include <iostream>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> PLI;

int getMst(vector<vector<PLI>> &adj, int x, int vertices)
{
	int miniSpanTreeSum = 0;
	priority_queue< PLI, vector<PLI>, greater<PLI> > priorityQueue;
	priorityQueue.push(make_pair(0,x));
	vector<int> visited(vertices+1, false);
	while(!priorityQueue.empty())
	{
		PLI nodeData = priorityQueue.top();
        priorityQueue.pop();
		int vertex = nodeData.second;
		if(visited[vertex])
			continue;
		visited[vertex] = true;
		miniSpanTreeSum += nodeData.first;

		for(PLI adjNodeData:adj[vertex])
		{
			if(!visited[adjNodeData.second])
				priorityQueue.push(adjNodeData);
		}
	}
	return miniSpanTreeSum;
}

int main1() {
	int vertices, edges;
	cin >> vertices >> edges;
	vector<vector<PLI>> adj(vertices+1, vector<PLI>());
	for(int i = 0; i < edges;i++)
	{
		int u,v;
		int weight;
		cin >> u >> v >> weight;
		adj[u].push_back(make_pair(weight,v));
		adj[v].push_back(make_pair(weight,u));
	}

    cout << "Input Done" << endl;

	cout << getMst(adj,1,vertices) << endl;
    return 0;
}

long long minCost(int vertices,vector<vector<long long>> &adj, int x)
{
	vector<int> visited(vertices+1, false);
    long long minCostVal = 0;
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> Q;
    Q.push(make_pair(0,x));
    while(!Q.empty())
    {
        pair<long long, int> pairData = Q.top();
        Q.pop();
        if(visited[pairData.second])
            continue;
        visited[pairData.second] = true;
        minCostVal += pairData.first;

        for(int i = 1; i < vertices+1; i++)
        {
            if(!visited[i] && adj[pairData.second][i] > 0)
            {
                Q.push(make_pair(adj[pairData.second][i],i));
            }
        }
    }
    return minCostVal;
}

int main() {
	int testcases;
	cin >> testcases;
	while(testcases-- > 0)
	{
		int numberOfCities;
		cin >> numberOfCities;
		vector<pair<long long, long long>> coords;
		vector<vector<long long>> adj(numberOfCities+1,vector<long long>(numberOfCities+1,0));
		vector<long long> xCords, yCords;

		for(int i = 0; i < numberOfCities;i++)
		{
			long long xCord;
			cin >> xCord;
			xCords.push_back(xCord);
		}

		for(int i = 0; i < numberOfCities;i++)
		{
			long long yCord;
			cin >> yCord;
			yCords.push_back(yCord);
		}

		for(int i = 0; i < numberOfCities;i++)
		{
			coords.push_back(make_pair(xCords[i],yCords[i]));
		}

		for(int i = 1; i < numberOfCities+1; i++)
		{
			for(int j = 1; j < numberOfCities+1; j++)
			{
				//if(i != j)
				//{
					long long cost = min(abs(coords[i-1].first-coords[j-1].first), abs(coords[i-1].second-coords[j-1].second));
					adj[i][j] = cost;
				//}
			}
		}

        cout << minCost(numberOfCities, adj, 1) << endl;
	}
    return 0;
}