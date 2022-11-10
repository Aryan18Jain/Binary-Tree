#include<iostream>
using namespace std;
class binary_tree
{
	private:
		struct node
		{
			int data;
			node * left=NULL;
			node * right=NULL;
		};
		node * root;
	public:
		void put_root()
		{
			root=create_tree();
		}
		node * get_root()
		{
			return root;
		}
		node * create_tree()
		{
			int x;
			node * root = new node;
			cout<<"Enter the data:";
			cin>>x;
			if(x==-1)
			{
				root->data=x;
				return root;
			}
			else
			{
				root->data=x;
				cout<<"Enter left of "<<x<<endl;
				root->left=create_tree();
				cout<<"Enter right of "<<x<<endl ;
				root->right=create_tree();
			}
		}
		void preorder(node * root)
		{
			if(root==NULL)
			{
				return;
			}
			else
			{
				if(root->data!=-1)
				cout<<root->data<<" ";
				preorder(root->left);
				preorder(root->right);
			}
		}
		void inorder(node * root)
		{
			if(root==NULL)
			{
				return;
			}
			else
			{
				inorder(root->left);
				if(root->data!=-1)
				cout<<root->data<<" ";
				inorder(root->right);
			}
		}
		void postorder(node * root)
		{
			if(root==NULL)
			{
				return;
			}
			else
			{
				postorder(root->left);
				postorder(root->right);
				if(root->data!=-1)
				cout<<root->data<<" ";
			}
		}
};
int main()
{
	binary_tree bt;
	cout<<"Enter -1 if no value for that node"<<endl;
	bt.put_root();
	cout<<"Preorder of given tree:"<<endl;
	bt.preorder(bt.get_root());
	cout<<endl;
	cout<<"Inorder of given tree:"<<endl;
	bt.inorder(bt.get_root());
	cout<<endl;
	cout<<"Inorder of given tree:"<<endl;
	bt.postorder(bt.get_root());
	cout<<endl;
	return 0;
}

