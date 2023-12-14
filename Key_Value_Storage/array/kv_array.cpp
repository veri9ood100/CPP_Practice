#include "kv_array.h"
#include <iostream>
//#include <cmath>
#include <cstring>

using namespace std;

array_storage::array_storage() : A() {}

array_storage::~array_storage() {
    //delete A;
}

int array_storage::BS(string _key, int _begin, int _end){ // binary search
    if(_end == _begin){ //find index
        return _begin;
    }

    else{ //searching continue
        int d = (_begin + _end + 1) / 2;

        if(A[d].first <= _key){
            return BS(_key, d, _end);
        }

        else{
            return BS(_key, _begin, d-1);
        }
    }
}

void array_storage::put(string _key, string _value, bool sortFlag){
    Node newNode = make_pair(_key, _value);
    
    if(tail == 0){
        A[tail] = newNode;
    }

    else if(!sortFlag){//non-sorting
        tail++;
        A[tail] = newNode;
    }
    
    else{//sorting need to fix using memcpy or memmove
        
        if(tail != NR_TESTS-1){ // array is not full
            int idx = BS(_key, 0, tail - 1);
            memmove(&A[idx+1], &A[idx], sizeof(A[0]) * (tail-idx+1)); //right shift
            A[idx] = newNode;
            tail++;
        }

        else{ //array is full
            cout<<"array is full!\n";
            exit(-1);
        }
    }
}

string array_storage::get(string _key){

    if(tail != 0){
        int idx = BS(_key, 0 , tail-1);
        if(_key == A[idx].first){ //searching success
            return A[idx].second;
        }
    }
    
    //searching failed
    return "";
}

void array_storage::remove(string _key){

    if(tail != 0){ //array is not empty
        int idx = BS(_key, 0 , tail-1);
        if(_key == A[idx].first){ //searching success
            memmove(&A[idx], &A[idx+1], sizeof(A[0]) * (tail-idx+1));//left shift
            tail--;
        }
    }
    
}

void array_storage::display(){
    int i = 0;
    while(i <= tail){
        i++;
        cout<<A[i].second<<"\n";
    }
}