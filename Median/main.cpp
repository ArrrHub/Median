#include <iostream>
#include "FastMedianFinderBehaviour.h"
#include "BHFinderBehaviour.h"
#include "STLPrioQFinderBehaviour.h"
#include <vector>

using namespace std;


int main()
{
	STLPrioQFinderBehaviour<int> stlPrioQueue;

	vector<int> inputData= { 6,3,1,2,5,4,7};

	for (auto v : inputData)
	{
		stlPrioQueue.insert(v);
		cout << stlPrioQueue.getMedian() << endl;
	}
	return 0;
}
