include<iostream>
using namespace std;
struct node
{
	int data;
	node* left;
	node* right;
};
class AVL
{
public:
	node* right_Rotation(node* r)
	{
		node* temp;
		temp = r->right;
		r->right = temp->left;
		temp->left = r;
		return temp;

		

	}
	node* leftRotation(node* r)
	{
		node* temp;
		temp = r->left;
		r->left = temp->right;
		temp->right = r;
		return temp;

	}
	node* left_Right(node* r)
	{
		node* temp;
		temp = r->left;
		r->left = right_Rotation(temp);
		return leftRotation(r);

	}
	node* right_Left(node* root)
	{
		node* temp;
		temp = root->right;
		root->right = leftRotation(temp);
		return right_Rotation(root);
	}
	int height(node* root)
	{
		if (root == NULL)
			return -1;
		else {
			int leftHieght = height(root->left);
			int rightHieght = height(root->right);
			if (leftHieght > rightHieght)
			{
				return (leftHieght + 1);
			}
			else
			{
				return (rightHieght + 1);
			}
		}


	}
	int BalanceFactor(node* r)
	{
		int leftHieght = height(r->left);
		int rightHieght = height(r->right);
		int b_factor = leftHieght - rightHieght;
		return b_factor;


	}
	node* balanceTree(node* r)
	{
		int BF = BalanceFactor(r);
		if (BF > 1)
		{
			if (BalanceFactor(r->left) > 0)
			{
				r = leftRotation(r);
			}
			else
			{
				r = left_Right(r);
			}
		}
		if (BF < -1)
		{
			if (BalanceFactor(r->right) > 0)
			{
				r = right_Left(r);
			}
			else
			{
				r = right_Rotation(r);
			}
		}
		return r;


	}
	void display(node* root)
	{
		if (root != NULL) {
			display(root->left);
			cout << root->data << " -> ";
			display(root->right);
		}


	}
	node* insertion(node* root, int n)
	{
		if (root == NULL)
		{
			node* temp = new node();
			temp->data = n;
			temp->right = NULL;
			temp->left = NULL;
			return temp;


		}
		else if ((root->data < n))
		{
			root->right = insertion(root->right, n);
			root=balanceTree(root);

		}
		else
		{
			root->left = insertion(root->left, n);
			root=balanceTree(root);
		}
		return root;


	}
};
int main()
{
	AVL obj;
	node* root = NULL;
	int value = 0;
	while (true)
	{

		cout << " MENU\n";
		cout << "1.For insertion\n ";
		cout << " 2. for display\n";
		int get;
		cin >> get;
		switch (get)
		{
		case 1:

			cout << " ENTER THE VALUE IN THE NODE";
			cin >> value;
			root = obj.insertion(root, value);
			break;
		case 2:
			obj.display(root);
			break;
		default:
			break;
		}
	}
}

