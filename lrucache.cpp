#include "lrucache.h"

template<typename T,typename T1>
void LRUCACHE<T,T1>::update(Node<T,T1> *node){
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

template<typename T,typename T1>
void LRUCACHE<T,T1>::insertKeyValuePair(T key,T1 value){
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

template<typename T,typename T1>
T LRUCACHE<T,T1>::getMostRecentKey(){
    if(head){
        cout<<head->key<<endl;
        return head->key; 
    }else{
        cout<<"NONE"<<endl;
        return "-   ";
    }
}

template<typename T,typename T1>
T1 LRUCACHE<T,T1>::getValueFromKey(T key){
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