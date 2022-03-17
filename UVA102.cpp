#include<iostream>
#include<vector>

using namespace std;

// struct node{
//     int value;
//     vector<node*> chilren;
// };

// void add_node(node* p,int value){
//     p->chilren.push_back((node *)malloc(sizeof(node)));
//     p->chilren[p->chilren.size()-1]->value = value;
//     return;
// }

// void remove_node(node* p){
//     if(p->chilren.size()>0){
//         node* rp = p->chilren.back();
//         p->chilren.pop_back();
//         free(rp);
//     }
//     return;
// }

// void pcout(node* p){

//     for(size_t i = 0;i<p->chilren.size();i += 1){
//         cout << (p->chilren[i])->value << endl;
//     }

// }

//          brown-棕色-B    green-绿色-G    clear-透明-C  
// 1号箱        1               2               3
// 2号箱        4               5               6
// 3号箱        7               8               9

// B-1
// G-2
// C-3

// void pattr(node* p){

//     cout << p->value;
//     cout << '-';
//     cout << p->chilren.size() << endl;
// }

// void pcout(node* p){
    
//     cout << p->value <<" ";

//     if(p->chilren.size() != 0){
        
//         cout << endl;
//         for(int i=0; i<p->chilren.size(); i+=1){
//             pcout(p->chilren[i]);
//         }
//     }

//     return;
// }


int main(int argc, char *argv[]){

    // vector<char> array = { 'B', 'G', 'C' };
    // cout << array[0] << endl;

    // node *root = (node *)malloc(sizeof(node));
    // root->value = 123;

    //pattr(root);
    //root->chilren = vector<node*>();
    

    //root->chilren.push_back((node *)malloc(sizeof(node)));
    // add_node(root,12);
    // add_node(root,23);
    // add_node(root,34);
    // root = root->chilren[0];
    // add_node(root->chilren[0],45);

    // pcout(root);
    // cout << root->value << endl;
    // cout << root->chilren.size() << endl;

    // pcout(root);
    //remove_node(root);
    // cout << root->chilren.size() << endl;
    //pcout(root);


    
    return 0;

}