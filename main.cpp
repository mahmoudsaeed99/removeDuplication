#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct node{
    node* next;
    int data;
};
node *n;
node* head_1=NULL;
node* head_2=NULL;

void push1(int data){
    node* new_node= new node();
    new_node->data=data;
    if(head_1==NULL){
        head_1=new_node;
        return;
    }
    else{
        node* crr=head_1;
        while(crr->next!=NULL){
            crr=crr->next;
        }
        crr->next=new_node;
    }
}

void push2(int data){
    node* new_node= new node();
    new_node->data=data;
    if(head_2==NULL){
        head_2=new_node;
        return;
    }
    else{
        node* crr=head_2;
        while(crr->next!=NULL){
            crr=crr->next;
        }
        crr->next=new_node;
    }
}
void merge_list(){
    if(head_1==NULL){
        if(head_2==NULL){
            return;
        }
        node* crr=head_1;
        while(crr->next!=NULL){
            crr=crr->next;
        }
        crr->next=head_2;

    }
    else{
        node* crr=head_1;
        while(crr->next!=NULL){
            crr=crr->next;
        }
        crr->next=head_2;
    }

}
void print_list(node* n){
    if(n==NULL){
        return ;
    }
    node* crr=n;
    while(crr!=NULL){
        cout<<crr->data;
        crr=crr->next;
    }
    cout<<endl;
}
void delete_node(node* per){
    if(per==NULL||per->next==NULL){
        return;
    }
    node* delete_node=per->next;
    per->next=delete_node->next;
    delete(delete_node);
}
void remove_duplication(){
    if(head_1==NULL){
        return;
    }
    node* crr1=head_1;
    while(crr1->next!=NULL){
        node* crr2=crr1->next;
        node* per2=crr1;
        while(crr2!=NULL){
            if(crr2->data==crr1->data){
                delete_node(per2);
                crr2=per2;
            }
            per2=crr2;
            if(crr2->next!=NULL){
                crr2=crr2->next;
            }
            else{
                break;
            }

        }
        if(crr1->next!=NULL){
            crr1=crr1->next;
        }
    }
}

int main()
{
    int x,y;
    cout<<" enter size of the first list"<<endl;
    cin>>x;
    for(int i=0;i<x;i++){
        cin>>y;
        push1(y);
    }
    cout<<" enter size of the second list"<<endl;
    cin>>x;
    for(int i=0;i<x;i++){
        cin>>y;
        push2(y);
    }
    while(true){
    cout<<"do you want to merge two link with make duplication"<<endl;
    string a;
    cin>>a;
    if(a=="yes"){
      merge_list();
      remove_duplication();
      print_list(head_1);
     return false;
    }
    else if(a=="no"){
        merge_list();
        print_list(head_1);
        return false;
    }
    else{
        cout<<"put yes or no only \n note that : write small alphabetic"<<endl;
    }
    }


    return 0;
}
