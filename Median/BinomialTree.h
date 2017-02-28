#pragma once
#include <memory>

template <class T> class BinomialTree
{
public:
	class Node;

	BinomialTree(T val) : order(0), root(new Node(null, val))
	{

	}

	shared_ptr<BinomialTree<T>> merge(shared_ptr<BinomialTree<T>> tree);
	void joinMinTree(BinomialTree<T>& minTree, BinomialTree<T>& other);
	std::shared_ptr<Node> getRoot();
	int& getOrder();

	class Node
	{
	public:
		Node() : child(0), right(0), parent(0), col(Red), value(0)
		{
		}

		Node(std::shared_ptr<Node> par, T val) : left(0), right(0), parent(par), value(val)
		{
		}

		std::shared_ptr<Node> child, right, parent;

		T getValue()
		{
			return value;
		}

	protected:
		T value;
	};

protected:
	int order;
	std::shared_ptr<Node> root;
};

template <class dataType> int& BinomialTree<dataType>::getOrder()
{
	return order;
}

template <class dataType> std::shared_ptr<typename BinomialTree<dataType>::Node> BinomialTree<dataType>::getRoot()
{
	return root;
}

template <class T> void BinomialTree<T>::joinMinTree(BinomialTree<T>& minTree, BinomialTree<T>& other)
{	
	other.getRoot()->parent = minTree.getRoot();
	other.getRoot()->right = minTree.getRoot()->child;
	minTree.getRoot()->child = other.getRoot();
	minTree.getOrder()++;
}

template <class T> shared_ptr<BinomialTree<T>> BinomialTree<T>::merge(shared_ptr<BinomialTree<T>> tree)
{
	if (root->value <= tree->getRoot())
	{
		joinMinTree(this, tree);
		return this;
	}
	else
	{
		joinMinTree(tree, this);
		return tree;
	}
}