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
class LRUCACHE{
    int maxsize,size;
    map<string, Node<T,T1>*> hash;
    Node<T,T1> *head,*tail;
    public:
    LRUCACHE(int maxsize_):maxsize(maxsize_),size(0),head(nullptr),tail(nullptr){};
    

    void update(Node<T,T1> *node);

    void insertKeyValuePair(T key,T1 value);
    
    T getMostRecentKey();

    T1 getValueFromKey(T key);


};