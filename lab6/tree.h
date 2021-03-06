// ---------------------------------------------------------------------------

#ifndef treeH
#define treeH

#include <iostream>
#include <vector>
#include <string>
#include <vcl.h>

using namespace std;

class BinarySearchTree
{
public:
	struct node
	{
		UnicodeString data;
		int key;
		node *left;
		node *right;
		int height;

		node(int _key, UnicodeString _data)
		{
			key = _key;
			left = right = 0;
			height = 0;
			data = _data;
		}

		node()
		{
			data = "";
			left = right = 0;
			height = 0;
			key = 0;
		}
	};

	node* root;

	int height(node *_node)
	{
		if (!_node)
			return 0;
		return _node->height;
	}

	int balance_factor(node *_node)
	{
		return height(_node->right) - height(_node->left);
	}

	void fix_height(node *_node)
	{
		int hl = height(_node->left);
		int hr = height(_node->right);
		if (hl > hr)
			_node->height = hl + 1;
		else
			_node->height = hr + 1;
	}

	node* rotate_right(node* _node)
	{
		node* q = _node->left;
		_node->left = q->right;
		q->right = _node;
		fix_height(_node);
		fix_height(q);
		return q;
	}

	node* rotate_left(node *_node)
	{
		node* q = _node->right;
		_node->right = q->left;
		q->left = _node;
		fix_height(_node);
		fix_height(q);
		return q;
	}

	node* balance(node* _node)
	{
		fix_height(_node);
		if (balance_factor(_node) == 2)
		{
			if (balance_factor(_node->right) < 0)
				_node->right = rotate_right(_node->right);
			return rotate_left(_node);
		}
		if (balance_factor(_node) == -2)
		{
			if (balance_factor(_node->left) > 0)
				_node->left = rotate_left(_node->left);
			return rotate_right(_node);
		}
		return _node;
	}

	node* find_min(node *p)
	{
		if (p->left)
			return find_min(p->left);
		else
			return p;
	}

	node* remove_min(node *p)
	{
		if (p->left == NULL)
			return p->right;
		p->left = remove_min(p->left);
		return balance(p);
	}

	node* remove(node *p, int k)
	{
		if (!p)
			return NULL;
		if (k < p->key)
			p->left = remove(p->left, k);
		else
			if (k > p->key)
				p->right = remove(p->right, k);
			else
			{
				node *q = p->left;
				node *r = p->right;
				delete p;
				if (!r)
					return q;
				node *min = find_min(r);
				min->right = remove_min(r);
				min->left = q;
				return balance(min);
			}
		return balance(p);
	}

	node* add(int _key, UnicodeString _data, node *_node)
	{
		if (!_node)
			return new node(_key, _data);
		if (_key < _node->key)
		{
			_node->left = add(_key, _data, _node->left);
		}
		else
		{
			_node->right = add(_key, _data, _node->right);
		}
		return balance(_node);
	}

	UnicodeString pre_order(node *p)
	{
		UnicodeString ans = "";
		if (!p) return ans;
		ans = p->data + " = " + IntToStr(p->key) + "\r\n";
		return ans + pre_order(p->left) + pre_order(p->right);
	}

	UnicodeString post_order(node *p)
	{
		UnicodeString ans = "";
		if (!p) return ans;
		ans = p->data + " = " + IntToStr(p->key) + "\r\n";
		return post_order(p->left) + post_order(p->right) + ans;
	}

	UnicodeString in_order(node *p)
	{
		UnicodeString ans = "";
		if (!p) return ans;
		ans = p->data + " = " + IntToStr(p->key) + "\r\n";
		return in_order(p->left)+ ans + in_order(p->right);
	}

	int get_left_nodes(node *p)
	{
		if (!p) return 0;
		return int_order(p->left);
	}

	int int_order(node *p)
	{
		if (!p) return 0;
		return int_order(p->left) + 1 + int_order(p->right);
    }
};

// ---------------------------------------------------------------------------
#endif
