#pragma once

#include <iostream>
#include <functional>
#include <queue>
#include <memory>
#include <list>
#include <vector>

template<class T> class STLPrioQFinderBehaviour : public MedianFinderBehaviour<T>
{
public:
	STLPrioQFinderBehaviour()
	{
		firstInStream = nullptr;
		median = 0;
	}

	void insert(T data);
	double getMedian();

private:
	std::priority_queue<int, std::vector<int>, std::less<int> > lowQueue;
	std::priority_queue<int, std::vector<int>, std::greater<int> > highQueue;
	int* firstInStream;
	double median;
};


template<class T> void STLPrioQFinderBehaviour<T>::insert(T data)
{
	int castedData = static_cast<int>(data);

	if (lowQueue.size() > 0)
	{
		if (castedData <= median)
		{
			lowQueue.push(castedData);
			if (lowQueue.size() > highQueue.size()+1)
			{
				int extractedElement = lowQueue.top();
				lowQueue.pop();

				highQueue.push(extractedElement);
			}
		}
		else
		{			
			highQueue.push(castedData);
			if (highQueue.size() > lowQueue.size()+1)
			{				
				int extractedElement = highQueue.top();
				highQueue.pop();

				lowQueue.push(extractedElement);
			}
		}

		if (lowQueue.size() < highQueue.size()) median = highQueue.top();
		else if (lowQueue.size() > highQueue.size()) median = lowQueue.top();
		else median = (lowQueue.top() + highQueue.top()) / 2.0;
	}
	else
	{
		if (!firstInStream)
		{
			firstInStream = new int(castedData);
			median = castedData;
		}
		else
		{
			lowQueue.push(castedData < *firstInStream ? castedData : *firstInStream);
			highQueue.push(castedData > *firstInStream ? castedData : *firstInStream);

			median = (*firstInStream + castedData) / 2.0;
		}
	}
}


template<class T> double STLPrioQFinderBehaviour<T>::getMedian()
{
	return median;
}