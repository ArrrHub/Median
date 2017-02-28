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
	T  getMedian();
private:
	BinomialHeap<T> heap;
};

template<class T>  void BHFinderBehaviour<T>::insert(T data)
{
	heap.insert(data);
}

template<class T>  T BHFinderBehaviour<T>::getMedian()
{
	T returnValue = 0;
	return returnValue;
}