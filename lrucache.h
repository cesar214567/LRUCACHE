#include <iostream>
#include <map>
#include <vector> 
using namespace std; 


template<typename T, typename T1>
struct Node{
    T key;
    T1 value;
    Node<T,T1> *previous,*next; 
    Node(T1 value_,T key_):value(value_),previous(nullptr),next(nullptr),key(key_){};

};

template<typename T, typename T1>
struct LRUCACHE{
    int maxsize,size;
    map<string, Node<T,T1>*> hash;
    Node<T,T1> *head,*tail;
    LRUCACHE(int maxsize_):maxsize(maxsize_),size(0),head(nullptr),tail(nullptr){};

    void update(Node<T,T1> *node){
        if (node==head){
            return;
        }
        if (node==tail){
            tail=node->previous;
            tail->next=nullptr;
            node->previous=nullptr;
            node->next=head;
            head->previous=node;
            head=head->previous;
        }else{
            node->next->previous=node->previous;
            node->previous->next=node->next;
            node->previous=nullptr;
            node->next=head;
            head->previous=node;
            head=head->previous;
        }

    }

    void insertKeyValuePair(T key,T1 value){
        if (hash.find(key)!=hash.end()){
            hash[key]->value=value;
            return;
        }
        if (size==maxsize){
            tail->value=value;
            hash.erase(tail->key);
            tail->key=key;
            hash[key]=tail;
            update(tail);
            
        }else if (!head){
            head=new Node<T,T1>(value,key);
            tail=head;
            hash[key]=head;
        }else{
            head->previous=new Node<T,T1>(value,key);
            head->previous->next=head;            
            head=head->previous;
            hash[key]=head;
        }
        size++;
        
    }
    T getMostRecentKey(){
        if(head){
            cout<<head->key<<endl;
            return head->key; 
        }else{
            cout<<"NONE"<<endl;
            return "-   ";
        }
        
    }

    T1 getValueFromKey(T key){
        if(hash.find(key)==hash.end()){
            cout<<"NONE"<<endl;
            return -1;
        }else{
            Node<T,T1> *temp= hash[key];
            int retorno=temp->value;
            cout<<retorno<<endl;
            update(temp);
            return retorno;
        }
    }


};