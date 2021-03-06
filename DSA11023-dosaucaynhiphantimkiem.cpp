#include<bits/stdc++.h>
using namespace std;
typedef struct Node
{
    int infor;
    Node *left;
    Node *right;
} * Tree;
Tree root;
int dem = 0;
void Init(Tree &root)
{
    root = NULL;
}
bool isLeft(int val, Tree root)
{
    return val < root -> infor;
}
bool isRight(int val, Tree root)
{
    return val > root -> infor;
}
Tree Insert(Tree root, int val)
{
    if (root == NULL)
    {
        root = new Node;
        root -> infor = val;
        root -> left = NULL;
        root -> right = NULL;
        return root;
    }
    if (isLeft(val, root))
        root -> left = Insert(root -> left, val);
    else
        if (isRight(val, root))
            root -> right = Insert(root -> right, val);
    return root;
}
void HowDeep(Tree root, int deep)
{
    if (root == NULL) return;
    if (root -> left == NULL && root -> right == NULL) dem = max(dem, deep);
    else
    {
        HowDeep(root -> left, deep + 1);
        HowDeep(root -> right, deep + 1);
    }
}
void solve()
{
    Init(root);
    int n;
    cin >> n;
    dem = 0;
    for(int i = 0; i < n; i++)
    {
        int so;
        char c;
        cin >> so;
        root = Insert(root, so);
    }
    HowDeep(root, 0);
    cout <<dem << endl;
}
int main()
{
    int t;
    cin >> t;
    while(t--) solve();
}