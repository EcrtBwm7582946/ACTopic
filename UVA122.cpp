#include <iostream>
#include <string>
#include <queue>
#include <vector>

using namespace std;

struct node {
    node *left;
    node *right;
    int *value;
};

node *newnode()
{
    node *p = (node *)malloc(sizeof(node));

    if (p != NULL) {
        p->left = NULL;
        p->right = NULL;
        p->value = NULL;
    }

    return p;
}

node *freenode(node *p)
{
    if (p != NULL) {
        p->left = freenode(p->left);
        p->right = freenode(p->right);
        free(p);
        p = NULL;
    }

    return p;
}

vector<int> check(node *p)
{
    vector<int> R;
    queue<node *> Q;
    Q.push(p);
    node *n;

    while (!Q.empty()) {
        n = Q.front();

        if (n->value == NULL) {
            R.clear();
            return R;
        }

        R.push_back(*(n->value));

        if (n->left != NULL) {
            Q.push(n->left);
        }

        if (n->right != NULL) {
            Q.push(n->right);
        }

        Q.pop();
    }

    return R;
}

int main(int argc, char *argv[])
{
    int m = 0;
    int ic;
    char c;
    string number = "";
    node *root = newnode();
    node *p = root;
    int repeat_size = 0;
    vector<int> R;

    while ((ic = getchar()) != EOF) {
        c = (char)ic;

        if (m == 0) {
            if (c == '\n' || c == ' ') {
                m = 0;
                continue;
            }

            if (c == '(') {
                m = 1;
                continue;
            }
        }

        if (m == 1) {
            if (ic >= 48 && ic <= 57) {
                number += c;
                m = 1;
                continue;
            }

            if (c == ',') {
                m = 2;
                continue;
            }

            if (c == ')') {
                R = check(root);

                if (repeat_size == 0 && R.size() != 0) {
                    cout << R[0];

                    for (int i = 1; i < R.size(); i += 1) {
                        cout << " " << R[i];
                    }
                } else {
                    cout << "not complete";
                }

                cout << endl;
                R.clear();
                root = freenode(root);
                root = new node();
                p = root;
                repeat_size = 0;
                m = 0;
                continue;
            }
        }

        if (m == 2) {
            if (c == ')') {
                if (p->value == NULL) {
                    p->value = (int *)malloc(sizeof(int));

                    if (p->value == NULL) {
                        return 0;
                    }

                    *(p->value) = stoi(number);
                } else {
                    repeat_size += 1;
                }

                number.clear();
                p = root;
                m = 0;
                continue;
            }

            if (c == 'L') {
                if (p->left == NULL) {
                    p->left = newnode();
                }

                p = p->left;
                m = 2;
                continue;
            }

            if (c == 'R') {
                if (p->right == NULL) {
                    p->right = newnode();
                }

                p = p->right;
                m = 2;
                continue;
            }
        }
    }

    return 0;
}