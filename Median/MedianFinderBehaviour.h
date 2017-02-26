#pragma once
template<class dataType> class MedianFinderBehaviour
{
public:
	virtual void insert(dataType data) = 0;
	virtual dataType  getMedian() = 0;
};