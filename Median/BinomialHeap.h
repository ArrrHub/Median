#pragma once
#include "BinomialTree.h"
#include <list>
#include <vector>

template <class T> class BinomialHeap
{
public:
	void insert(T element);
	std::shared_ptr<typename BinomialTree<T>::Node> removeMin();

	BinomialHeap()
	{
		minNode = 0;
	}

private:
	std::vector<std::shared_ptr<BinomialTree<T>>> trees;
	std::vector<bool> orders;
	std::shared_ptr<typename BinomialTree<T>::Node> minNode;
};


template <class T> void BinomialHeap<T>::insert(T element)
{
	shared_ptr<BinomialTree<T>> elementHolder = std::make_shared<BinomialTree<T>> (element);
	
	if ((!minNode) || (minNode->getValue()>elementHolder->getRoot()->getValue())) minNode = elementHolder->getRoot();

	if (trees.empty())
	{
		trees.push_back(elementHolder);
		orders.push_back(1);
	}
	else
	{
		int i = 0;
		while ((i < orders.size()) && (orders[i] == 1))
		{
			elementHolder = elementHolder->merge(trees[i]);
			trees[i].reset();
			orders[i] = 0;
			i++;
		}

		if (i == orders.size())
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

template <class T> std::shared_ptr<typename BinomialTree<T>::Node> BinomialHeap<T>::removeMin()
{
	shared_ptr<BinomialTree<T>::Node> oldMin = minNode;
	shared_ptr<BinomialTree<T>::Node> oldMinChild = minNode->child;

	for(int i = 0; i < trees.size(); i++)
	{
		if (trees[i]->getRoot()->getValue() == oldMin)
		{
			trees[i].reset();

		}
	}
	std::vector<std::shared_ptr<BinomialTree<T>>> trees;


	return oldMin;

}