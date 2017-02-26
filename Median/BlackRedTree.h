#pragma once
#include <memory>

namespace BlackRedTree
{
	enum NodeColor
	{
		Black,
		Red
	};

	template <class dataType> class BRTree
	{
		class Node;

	public:
		BRTree()
		{
			root = std::make_shared<Node>();
			root->col = Black;
		}

		void insert(dataType value)
		{

		}
		dataType getRootValue()
		{
			return root->value;
		}



	private:
		std::shared_ptr<Node> root;




		class Node
		{
		public:
			Node() : left(0), right(0), parent(0), col(Red), value(0)
			{
			}

			Node(std::shared_ptr<Node> par, dataType val) : left(0), right(0), parent(par), col(Red), value(val)
			{
			}

			std::shared_ptr<Node> left, right, parent;
			NodeColor col;
			dataType value;
		};
	};
}
