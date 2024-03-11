/**
 STL : 
    Containers :
            Sequence Containers : 
                    Array
                    Vector
                    List
                    Dequeue
                    Forward_list

            Container Adapters : 
                    Stack
                    Queue
                    Priority Queue
            Associative Containers : 
                    Set
                    Map
                    MultiSet
                    MultiMap

            unordered Containers : 
                    Unordered Set
                    Unordered map
                    Unordered MultiSet
                    Unordered MultiMap
    Algorithms : 
            Binary Search
            Lower/Upper bound
            min/max
            reverse/rotate
            sort/swap
            ... etc
*/


#include<iostream>
#include<array>
#include<vector>
#include<deque>
#include<list>
#include<stack>
#include<queue>
#include<set>
#include<unordered_set>
#include<map>
#include<unordered_map>
#include<algorithm>

using namespace std;

int main(){

    // Array
    // int arra[3] = {1,2,3};
    array<int, 3> arr;
    cout<<arr.size()<<endl;
    cout<<arr.at(2)<<endl;
    cout<<arr.front()<<endl;
    cout<<arr.end()<<endl;
    cout<<arr.empty()<<endl;

    // Vector
    vector<int> vect; // Each time the vector becomes full then it recreates the new vector with double its current size( check with the capacity function )
    vector<int> v(10,1);
    vector<int> la(v);
    vect.push_back(5);
    cout<<vect.size()<<endl; // gives the size of the vector or no. of elements
    cout<<vect.capacity()<<endl; // give the amount of space a vector is holding in memory.
    cout<<vect.front()<<endl;
    cout<<vect.back()<<endl;
    // before pop
    for( int i: vect) {
        cout<<i<<endl;
    }
    vect.pop_back();

    for(int i : v) {
        cout<<i<<endl;
    }

    // Dequeue
    deque<int> d;
    d.push_back(5)   ;
    d.push_front(6);
    cout<<endl;

    cout<<d.front()<<endl;
    cout<<d.back()<<endl;
    cout<<d.empty()<<endl;
    cout<<d.size()<<endl;
    d.erase(d.begin(), d.begin() + 1);
    cout<<d.size()<<endl;
    for(int i : d) {
        cout<<i<<endl;
    }

    // List
    list<int> l;
    list<int> nl(l);

    for(int i  : l){
        cout<<i<<endl;
    }
    l.push_back(5);
    l.push_front(6);
    l.erase(l.begin());
    cout<<l.size()<<endl;

    // Stack
    stack<int> s;
    s.push(5);
    s.push(6);
    cout<<s.empty()<<endl;
    cout<<s.size()<<endl;
    cout<<s.top()<<endl;


    // Queue
    queue<string> q;
    q.push("Syed");
    q.push("Hasnain");
    q.push("Shaukat");
    q.push("Abidi");
    cout<<q.size()<<endl;
    cout<<q.front()<<endl;
    q.pop();
    // all operations complexity is o(1)

    // Priority Queue
    priority_queue<int> maxi; // max heap
    priority_queue<int, vector<int>, greater<int>> mini;

    maxi.push(5);
    maxi.push(6);
    maxi.push(1);
    maxi.push(2);


    // Set - behind the scenes bst - cannot be modify - immmutable - 
    /**
     unordered-set : is faster than set, and elements fetched in unsorted order
     complexity - O(log n)
    */
    set<int> se;
    se.insert(5);
    se.insert(6);
    se.insert(4);
    se.insert(4);
    se.insert(6);
    se.insert(6);
    se.insert(6);
    se.insert(2);

    for(int i : se) {
        cout<<i<<endl;
    }

    set<int>::iterator it = se.begin();
    it = it++;
    se.erase(it);

    // Map - complexity - O(log n) - underlying container : Red black tree
    map<int, string> m;
    m.insert({4, "syed"});
    m[1] = "Hasnain";

    // sort() - intro sort - combination of insertion, quick, heap sort

    
    return 0;
}