#include<iostream>
#include<vector>

using namespace std;

struct value {
    int n;
    int r;
    int c;
};

int N;
vector<vector<int>> blocks;

void Init()
{
    blocks = vector<vector<int>>(N);

    for (int r = 0; r < N; r += 1) {
        blocks[r].push_back(r);
    }
}

void Find(value &a, value &b)
{
    for (int r = 0; r < N; r += 1) {
        int csize = blocks[r].size();

        for (int c = 0; c < csize; c += 1) {
            if (blocks[r][c] == a.n) {
                a.r = r;
                a.c = c;
            }

            if (blocks[r][c] == b.n) {
                b.r = r;
                b.c = c;
            }
        }
    }
}

void Reset(value v)
{
    int top = blocks[v.r].back();

    while (top != v.n) {
        blocks[top].push_back(top);
        blocks[v.r].pop_back();
        top = blocks[v.r].back();
    }
}

void MoveBlocks(value a, value b)
{
    vector<int> box;
    int i = blocks[a.r].size() - 1;

    while (i >= a.c) {
        box.push_back(blocks[a.r].back());
        blocks[a.r].pop_back();
        i -= 1;
    }

    while (!box.empty()) {
        blocks[b.r].push_back(box.back());
        box.pop_back();
    }
}

void MoveOnto(value a, value b)
{
    Reset(a);
    Reset(b);
    MoveBlocks(a, b);
}

void MoveOver(value a, value b)
{
    Reset(a);
    MoveBlocks(a, b);
}

void PileOnto(value a, value b)
{
    Reset(b);
    MoveBlocks(a, b);
}

void PileOver(value a, value b)
{
    MoveBlocks(a, b);
}

void Cout()
{
    for (int r = 0; r < N; r += 1) {
        cout << r << ":";
        int csize = blocks[r].size();

        for (int c = 0; c < csize; c += 1) {
            cout << " " << blocks[r][c];
        }

        cout << endl;
    }
}

int main(int argc, char *argv[])
{
    cin >> N;
    Init();
    string s1, s2, s3;
    value a, b;

    while (cin >> s1 >> a.n >> s2 >> b.n) {
        if (s1 == "quit") {
            break;
        }

        if (a.n < 0 || a.n > (N - 1)) {
            return 0;
        }

        if (b.n < 0 || b.n > (N - 1)) {
            return 0;
        }

        Find(a, b);

        if (a.r == b.r) {
            continue;
        }

        s3 = s1 + s2;

        if (s3 == "moveonto") {
            MoveOnto(a, b);
        }

        if (s3 == "moveover") {
            MoveOver(a, b);
        }

        if (s3 == "pileonto") {
            PileOnto(a, b);
        }

        if (s3 == "pileover") {
            PileOver(a, b);
        }
    }

    Cout();
}