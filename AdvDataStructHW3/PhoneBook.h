#include<person.h>
#include<iostream>
#include<vecetor>
#include<string>
using namespace std;

class Node {
 public:
string data;

Node* left;

Node* right;

Node(){
    
}

~Node(){};

};
class PhoneBook{
    public:
    
Node* CreateNode(Person data){

Node* newNode = new Node(); // allocate memory for new node in dynamic memory(heap)

newNode->data = data;

newNode->left = newNode->right = NULL;

return newNode;

}

Node* Insert(Node* root, Person data){

if(root == NULL){   //empty tree
    root = CreateNode(data);
    //cout<<"Node created"<<endl;
    return root;
}

else if(data->getLname() < root->data->getLname()){

root->left = Insert(root->left, data);//recursive call for children
//cout<<root->left->data<<" is left child"<<endl;
} 
    
else{

root->right = Insert(root->right,data);
    //cout<<root->right->data<<" is right child"<<endl;
}

return root;

}

Node* Min(Node* root){
while( root->left != NULL) root = root->left;
return root;
}  


Node* Remove(Node* root, Person data){ 
 if(root == NULL) return root; 
	else if(data->getLname() < root->data->getLname()) root->left = Remove(root->left,data);
	else if (data->getLname() > root->data) root->right = Remove(root->right,data);
	// Wohoo... I found you, Get ready to be deleted	
	else {
		// Case 1:  No child
		if(root->left == NULL && root->right == NULL) { 
			delete root;
			root = NULL;
		}
		//Case 2: One child 
		else if(root->left == NULL) {
			struct Node *temp = root;
			root = root->right;
			delete temp;
		}
		else if(root->right == NULL) {
			struct Node *temp = root;
			root = root->left;
			delete temp;
		}
		// case 3: 2 children
		else { 
            
		 Node *temp = Min(root->right);
			root->data = temp->data;
			root->right = Remove(root->right,temp->data);
		}
	}
	return root;
}
 
bool Find(Node* root, Person data) {

if(root == NULL) return false;

else if(root->data->getLname() == data->getLname()) return true;

else if(data->getLname() <= root->data->getLname()) return Find(root->left, data);

else return Find(root->right, data);

}

int Size(Node* root){
    if (root == NULL) {
        
        return 0 ;
        }

    int leftSize = Size(root->left); //traverses left side
    int rightSize = Size(root->right);//traverses right side

    return leftSize + rightSize + 1; //
}

Node* EmptyTree(Node* root){  //complete
    
    if (root == NULL)
        return NULL;

    root->left = EmptyTree(root->left);
    root->right = EmptyTree(root->right);
    
     if(root->left == NULL && root->right == NULL){
         //delete root;
        return root;
    } 

    if(root->left != NULL){
        delete root->left;

    }
    if(root->right != NULL){
        delete root->right;

    }
root = NULL;
return root;

}

void PrintTree(Node* t ){ //functional
   //cout<<endl<<endl;

    if(t->left != NULL)
    PrintTree(t->left);

    cout <<t->data <<endl;

    if(t->right != NULL)
    PrintTree(t->right);
}

int height(Node* root){
    if (root==NULL)
    return 0;
else{
    return 1+max(height(root->left),height(root->right));
}
}

bool isBalanced(Node* root)
{
    int lefth; // height of left subtree 
    int righth; // height of right subtree 
 
    // If tree is empty then return true 
    if (root == NULL)
        return 1;
 
    //Get the height of left and right sub trees 
    lefth = height(root->left);
    righth = height(root->right);
 
    if (abs(lefth - righth) <= 1 && isBalanced(root->left) && isBalanced(root->right))  //If this is true it is balanced
        return 1;
 
    //Tree isnt height balanced if we reach this point
    return 0;
}

};