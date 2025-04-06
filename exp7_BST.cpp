#include <iostream>

using namespace std;
struct node
{
    int data;
    node *left;
    node *right;
};
class BST
{

public:
    node *root;
    void create();
    void insert(node *, node *);
    void display();
    void inorder(node *);   // left-root-right
    void preorder(node *);  // root-left-right
    void postorder(node *); // left - right - root
    void mini(node *);
    void maxi(node *);
    int height(node *);
    bool search(node *);
    void mirror(node *);
    int leafcnt(node *);

    BST()
    {
        root = NULL;
    }
};
void BST::create()
{
    char ch;
    do
    {
        node *nn = new node;
        cout << "Enter data : ";
        cin >> nn->data;
        nn->left = NULL;
        nn->right = NULL;
        if (root == NULL)
        {
            root = nn;
        }
        else
        {
            insert(root, nn);
        }
        cout << "Do you want to add more nodes (y/n) :  ";
        cin >> ch;
    } while (ch == 'y');
}
void BST::insert(node *root, node *nn)
{
    if (nn->data < root->data)
    {
        if (root->left == NULL)
        {
            root->left = nn;
        }
        else
        {
            insert(root->left, nn);
        }
    }
    else
    {
        if (root->right == NULL)
        {
            root->right = nn;
        }
        else
        {
            insert(root->right, nn);
        }
    }
}
void BST::inorder(node *root)
{

    if (root == NULL)
    {
        return;
    }
    else
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}
void BST::preorder(node *root)
{
    node *temp;
    if (root == NULL)
    {
        return;
    }
    else
    {
        cout << root->data << " ";
        inorder(root->left);

        inorder(root->right);
    }
}
void BST::postorder(node *root)
{
    node *temp;
    if (root == NULL)
    {
        return;
    }
    else
    {

        inorder(root->left);
        inorder(root->right);
        cout << root->data << " ";
    }
}
void BST::display()
{
    cout << "\nInorder Traversal is : ";
    inorder(root);
    cout << "\nPreorder Traversal is : ";
    preorder(root);
    cout << "\nPostorder Traversal is : ";
    postorder(root);
}
void BST::mini(node *root)
{
    if (root == NULL)
    {
        cout << "Tree is empty." << endl;
        return;
    }

    while (root->left != NULL)
    {
        root = root->left;
    }

    cout << "Minimum value is: " << root->data << endl;
}
void BST::maxi(node *root)
{
    if (root == NULL)
    {
        cout << "Tree is empty." << endl;
        return;
    }

    while (root->right != NULL)
    {
        root = root->right;
    }

    cout << "Maximum value is: " << root->data << endl;
}
int BST::height(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int hl = height(root->left);
    int hr = height(root->right);
    return (hl > hr ? hl : hr) + 1;
}
bool BST::search(node *root)
{
    int n;
    cout << "Enter node to search: ";
    cin >> n;
    node *t = root;
    while (t != NULL)
    {
        if (n == t->data)
        {
            return true;
        }
        else if (n < t->data)
        {
            t = t->left;
        }
        else
        {
            t = t->right;
        }
    }
    return false;
}
void BST::mirror(node *root)
{
    if (root == NULL)
    {
        return;
    }
    mirror(root->left);
    mirror(root->right);
    node *temp = root->left;
    root->left = root->right;
    root->right = temp;
}
int BST::leafcnt(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    if (root->left == NULL && root->right == NULL)
    {
        return 1;
    }
    return (leafcnt(root->left) + leafcnt(root->right));
}
int main()
{
    BST b;
    char ch;
    do
    {
        int choice;
        cout<<"                   ------------Operations-------------"<<endl;
        cout << "1.Insert \n2.Display\n3.Minimum \n4.Maximum\n5.Height of the tree \n6.Search Node\n7.Mirror\n8.Leaf Node\n";
        cout << "Enter your choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            b.create();
            break;

        case 2:
            b.display();
            break;

        case 3:
            b.mini(b.root);
            break;
        case 4:
            b.maxi(b.root);
            break;

        case 5:

            cout << "Height is " << b.height(b.root) << endl;
            break;
        case 6:
            if (b.search(b.root))
            {
                cout << "Node found \n";
            }
            else
            {
                cout << "Node not found";
            }
            break;
        case 7:
            b.mirror(b.root);
            cout << "\nmirror sucessfull\n";
            break;
        case 8:
            cout << "Leaf count : " << b.leafcnt(b.root);
            break;
        default:
            break;
        }

        cout << "\nContinue (y/n) : ";
        cin >> ch;
    } while (ch == 'y');

    return 0;
}
