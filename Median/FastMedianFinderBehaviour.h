#include "MedianFinderBehaviour.h"
#include <set>
#include "BlackRedTree.h"

#pragma once
template<class dataType> class FastMedianFinderBehaviour : public MedianFinderBehaviour<dataType>
{
public:
	FastMedianFinderBehaviour()
	{
	}

	void insert(dataType element);
	dataType  getMedian();

private:
	BlackRedTree::BRTree<dataType> tree;
};

template<class dataType> void FastMedianFinderBehaviour<dataType>::insert(dataType element)
{

}

template<class dataType> dataType FastMedianFinderBehaviour<dataType>::getMedian()
{
	dataType a = 0;
	return a;
}