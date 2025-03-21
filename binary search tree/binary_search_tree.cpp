#include "binary_search_tree.h"
using namespace std;
binarySearchTreeType::binarySearchTreeType()
{
	root = NULL;
}


bool binarySearchTreeType::isEmpty()
{
	return (root == NULL);
}


void binarySearchTreeType::inorderTraversal()
{
	inorder(root);
}


void binarySearchTreeType::preorderTraversal()
{
	preorder(root);
}


void binarySearchTreeType::postorderTraversal()
{
	postorder(root);
}


int binarySearchTreeType::treeHeight()
{
	return height(root);
}


int binarySearchTreeType::treeNodeCount()
{
	return nodeCount(root);
}


int binarySearchTreeType::treeLeavesCount()
{
	return leavesCount(root);
}


void binarySearchTreeType::inorder(nodeType *p)
{
	if(p != NULL)
	{
		inorder(p->left);
		cout<<p->info<<" ";
		inorder(p->right);
	}
}


void binarySearchTreeType::preorder(nodeType *p)
{
	if(p != NULL)
	{
		cout<<p->info<<" ";
		preorder(p->left);
		preorder(p->right);
	}
}


void binarySearchTreeType::postorder(nodeType *p)
{
	if(p != NULL)
	{
		postorder(p->left);
		postorder(p->right);
		cout<<p->info<<" ";
	}
}


void  binarySearchTreeType::clear(nodeType* &p)
{
	if(p != NULL)
	{
		clear(p->left);
		clear(p->right);
		delete p;
		p = NULL;
	}
}


void  binarySearchTreeType::clearTree()
{
	clear(root);
}

binarySearchTreeType::~binarySearchTreeType()
{
	clear(root);
}


int binarySearchTreeType::height(nodeType *p)
{
	if(p == NULL)
		return 0;
	else
		return 1 + max(height(p->left), height(p->right));
}


int binarySearchTreeType::max(int x, int y)
{
	if(x >= y)
		return x;
	else
		return y;
}


int binarySearchTreeType::nodeCount(nodeType *p)
{
	if(p == NULL)
		return 0;
	else
		return 1 + nodeCount(p->left) + nodeCount(p->right);
}


int binarySearchTreeType::leavesCount(nodeType *p)
{
	if(p == NULL)
		return 0;
	else if ((p->left == NULL) && (p->right == NULL))
		return 1;
	else
		return leavesCount(p->left) + leavesCount(p->right);
}

bool binarySearchTreeType::search(int item)
{
	nodeType *current = root;

	while(current != NULL)
	{
		if(current->info == item)
			return true;
		else if(current->info > item)
			current = current->left;
        else
            current = current->right;
	}

    return false;
}

bool binarySearchTreeType::searchRec(int item)
{
	return searchRecPriv(root, item);
}

bool binarySearchTreeType::searchRecPriv(nodeType *p, int item)
{
	if(p == NULL)
		return false;
	else if (p->info == item)
		return true;
	else if(p->info > item)
		return searchRecPriv(p->left, item);
	else
		return searchRecPriv(p->right, item);
}

void binarySearchTreeType::insert(int item)
{
    nodeType *current;  //pointer to traverse the tree
    nodeType *trailCurrent; //pointer behind current
    nodeType *newNode;  //pointer to create the node

    newNode = new nodeType;
    assert(newNode != NULL);
    newNode->info = item;
    newNode->left = NULL;
    newNode->right = NULL;

    if(root == NULL)
       root = newNode;
    else
    {
       current = root;

       while(current != NULL)
       {
           trailCurrent = current;

           if(current->info == item)
           {
              cout<<"The insert item is already in the list -- ";
              cout<<"duplicates are not allowed."<<endl;
              return;
           }
           else
              if(current->info > item)
                 current = current->left;
              else
                 current = current->right;
       }//end while

       if(trailCurrent->info > item)
          trailCurrent->left = newNode;
       else
          trailCurrent->right = newNode;
   }
}
//this function only determines the node to be deleted
void binarySearchTreeType::remove(int item)
{
	nodeType *current;  //pointer to traverse the tree
	nodeType *trailCurrent; //pointer behind current

	if(root == NULL)
	{
		cout<<"Cannot delete from the empty tree."<<endl;
		return;
	}
	if(root->info == item)
	{
		deleteFromTree(root);
		return;
	}

	//if you get here, then the item to be deleted is not the root
	trailCurrent = root;

	if(root->info > item)
		current = root->left;
	else
		current = root->right;

	//search for the item to be deleted.
	while(current != NULL)
	{
		if(current->info == item)
			break;
		else
		{
			trailCurrent = current;
			if(current->info > item)
				current = current->left;
			else
				current = current->right;
		}
	}// once the while is done, current points to either NULL or to the node to be deleted

	if(current == NULL)
		cout<<"The delete item is not in the tree."<<endl;
	else if(trailCurrent->info > item)
		deleteFromTree(trailCurrent->left);
	else
		deleteFromTree(trailCurrent->right);
}

void binarySearchTreeType::deleteFromTree
                                 (nodeType* &p)
{
     nodeType *current;    //pointer to traverse
                                     //the tree
     nodeType *trailCurrent;   //pointer behind current
     nodeType *temp;        //pointer to delete the node

	 if(p->left == NULL && p->right == NULL)
     {
		delete p;
		p = NULL;
     }
     else if(p->left == NULL)
     {
		temp = p;
        p = p->right;
        delete temp;
     }
     else if(p->right == NULL)
     {
		temp = p;
        p = p->left;
        delete temp;
     }
     else
     {
        current = p->left;
        trailCurrent = NULL;

        while(current->right != NULL)
        {
            trailCurrent = current;
            current = current->right;
        }//end while

        p->info = current->info;

        if(trailCurrent == NULL) //current did not move;
                                 //current == p->left; adjust p
           p->left = current->left;
        else
           trailCurrent->right = current->left;

        delete current;
     }//end else
}//end deleteFromTree

int main()
{
    binarySearchTreeType b;
    b.insert(10);
    b.insert(20);
    b.insert(5);
	b.remove(10);
	b.inorderTraversal();
	b.postorderTraversal();
	b.preorderTraversal();
	return 0;
}
