#pragma once
#include "interfaces/ITree.hpp"
#include <string>
#include <sstream>
#include <algorithm>
#include <math.h>

namespace DataStructures {
	template<typename TData>
	class RawBinaryTree :public ITree<TData> {
	private:
		struct Node {
			Node* _left = nullptr;
			Node* _right = nullptr;
			Node* _parrent = nullptr;
			TData _value;
			Node(Node* parrent, TData val) :_parrent(parrent), _value(val) {}
			~Node() {
				delete _left;
				delete _right;
				_parrent = nullptr;
			}
		};
		Node* _root = nullptr;
		size_t _size = 0;
	public:
		~RawBinaryTree() {
			delete _root;
		}
		void Insert(TData input) {
			Insert(&_root, nullptr, input);
		}
		const bool IsEmpty() const {
			return _root == nullptr;
		}
		const size_t Depth() const {
			return Depth(_root);
		}
		const size_t Count() const {
			return _size;
		}
		int Root() const {
			return _root->_value;
		}
		const bool Contain(int input) {
			return true;
		}
		std::string Print() const {
			return std::string();
		}
	private:

		void Insert(Node** node, Node* parrentNode, TData input) {
			if (*node == nullptr) {
				*node = new Node(parrentNode, input);
				_size++;
				return;
			}
			if ((*node)->_value > input) {
				Insert(&(*node)->_left, *node, input);
				return;
			}
			Insert(&(*node)->_right, *node, input);
		}
		const size_t Depth(Node* node) const {
			if (node == nullptr) {
				return 0;
			}
			return std::max(Depth(node->_left), Depth(node->_right)) + 1;
		}
	};
}