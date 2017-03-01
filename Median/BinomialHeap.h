#pragma once
#include "BinomialTree.h"
#include <list>
#include <vector>

template <class T> class BinomialHeap
{
public:
	void insert(T element);

private:
	std::vector<std::shared_ptr<BinomialTree<T>>> trees;
	std::vector<bool> orders;
};

template <class T> void BinomialHeap<T>::insert(T element)
{
	shared_ptr<BinomialTree<T>> elementHolder = std::make_shared<BinomialTree<T>> (element);
	
	if (trees.empty())
	{
		trees.push_back(elementHolder);
		orders.push_back(1);
	}
	else
	{
		for (int i = 0; i < trees.size(); i++)
		{
			if (i == elementHolder->getOrder())
			{
				if ((orders[i] == 1) && )
				{
					elementHolder = elementHolder->merge(trees[i]);
					trees[i].reset();
					orders[i] = 0;
				}
				else
				{
					if (i == orders.size() - 1)
					{
						trees.push_back(elementHolder);
						orders.push_back(1);
					}
					else
					{
						trees[i] = elementHolder;
						orders[i] = 1;
					}
				}
			}

		}
	}

}