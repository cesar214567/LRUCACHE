
#include "lrucache.cpp"



int main(){
    LRUCACHE<string,int> temp(3);
    temp.insertKeyValuePair("b",2);
    temp.insertKeyValuePair("a",1);
    temp.insertKeyValuePair("c",3);
    temp.getMostRecentKey();
    temp.getValueFromKey("a");
    temp.getMostRecentKey();
    temp.insertKeyValuePair("d", 4);
    temp.getValueFromKey("b");
    temp.insertKeyValuePair("a", 5);
    temp.getValueFromKey("a");


}
