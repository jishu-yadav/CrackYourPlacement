#include <iostream>
using namespace std;

//implement a Hashmap
//separate chaining technique

template <Typename T>
class Node{
    
    public:
    string key;
    T value;
    Node<T>*next;
    Node(string key, T val){
        this->key = key;
        value = val;
        next = NULL;
    }
    ~Node(){
        if(next!=NULL){
            delete next;
        }
    }
};
template<typename T>
class HashTable{

    Node<T>**table;//pointer to array of pointers
    int current_size;
    int table_size;
    int hashFn(string key){
        int idx=0;
        int p = 1;
        for(int j=0;j<key.length();j++){
            idx = idx + (key[j]*p) % table_size ;
            idx = idx % table_size;
            p = (p*27)%table_size;
        }
        return idx;
    }

public:
    HashTable(int ts=7){
        table_size = ts;
        table = new Node<T>*[table_size];
        current_size=0;
        for(int i=0;i<table_size;i++){
            table[i] = NULL;
        }
    }
    
  }
void insert(string key, T value){
    int idx = hashFn(key);
    Node<T>* n = new Node<T>(key,val);
    //insert at head of the linked list with id = idx;
    n->next = table[idx];
    table[idx]=n;
    current_size++;
    
}
T search(string key){

}
void erase(string key){
    
}

};
int main() {
    cout<<"Hello World!";
}
// hashtable implementation insert function
