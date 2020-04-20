#include <iostream>
#include <iomanip>

using namespace std;

struct BSTNode
{
    BSTNode * left;
    BSTNode * right;
    int key;
};

BSTNode * readBST()
{
    BSTNode ** vp;
    int key, l, r, i, n;

    cin >> n;   // quantity of tree parts(?)

    vp = new BSTNode*[n];

    for (i = 0 ; i < n ; i++) 
    {
        vp[i] = new BSTNode;
    }

    for (i = 0 ; i < n ; i++)
    {
        cin >> key >> l >> r; // read key; and left and right derived
        vp[i]->key = key; // set a key
        vp[i]->left = l ? vp[l] : nullptr; // set left son
        vp[i]->right = r ? vp[r] : nullptr; // set right son
    }

    BSTNode * root = vp[0]; // root of the tree
    delete [] vp;

    return root;
}

BSTNode * findBST(BSTNode * p, int k)
{
    while( p && p->key != k )
    {
        p = (k < p->key) ? p->left : p->right;
    }

    return p;
}

BSTNode * minBST(BSTNode * p)
{
    if (p)
    {
        while (p->left)
        {
            p = p->left;
        }
    }

    return p;
}

BSTNode * maxBST(BSTNode * p)
{
    if (p)
    {
        while(p->right)
        {
             p = p->right;
        }
    }

    return p;
}

void DFSRelease(BSTNode * v)
{
    if (v)
    {
        DFSRelease(v->left); // usuwamy lewe poddrzewo
        DFSRelease(v->right); // usuwamy lewe poddrzewo
        delete v;
    }
}

int main()
{
    BSTNode * root, * p;
    int k, mink, maxk;

    root = readBST(); // read our bst tree

    if (root)
    {
        mink = minBST(root)->key; // min key read
        maxk = maxBST(root)->key; // max keyu read

        // go through queued key values

        for ( k = mink ; k <= maxk ; k++ )
        {
            p = findBST(root, k); // search wezla o kluczu k

            cout << "key = " << setw(3) << k << ": " ;

            if (p)
            {
                if (!p->left && !p->right) 
                {
                    cout << "Leaf" << endl;
                }
                else
                {
                    cout << "inner node" << endl;
                }
            }
            else
            {
                cout << "None" << endl;
            }

        }
    }
    else
    {
        cout << "BST is empty" << endl;
    }

    DFSRelease(root); // free

}
