#pragma once
#include "MedianFinderBehaviour.h"
#include "BinomialHeap.h"

/**
Binomial Heap Finder Behaviour
**/

template<class T> class BHFinderBehaviour : public MedianFinderBehaviour<T>
{
public:
	BHFinderBehaviour()
	{
	}
	 
	void insert(T data);
	double  getMedian();
private:
	BinomialHeap<T> heap;
};

template<class T>  void BHFinderBehaviour<T>::insert(T data)
{
	heap.insert(data);
}

template<class T>  double BHFinderBehaviour<T>::getMedian()
{
	double returnValue = 0;
	return returnValue;
}