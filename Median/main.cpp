#include <iostream>
#include <map>
#include "FastMedianFinderBehaviour.h"
#include "BHFinderBehaviour.h"
#include <vector>

using namespace std;


int main()
{
	FastMedianFinderBehaviour<int> finder;
	BHFinderBehaviour<int> f2;

	vector<int> inputData= { 6,3,1,2,5,4,7};

	for (auto v : inputData)
	{
		f2.insert(v);
		int a = 4;
	}

}
