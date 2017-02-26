#include <iostream>
#include <map>
#include "FastMedianFinderBehaviour.h"
#include <vector>

using namespace std;


int main()
{
	FastMedianFinderBehaviour<int> finder;

	vector<int> inputData= { 6,3,1,2,5,4,7};

	for (auto v : inputData)
	{
		finder.insert(v);
		int a = 4;
	}

}
