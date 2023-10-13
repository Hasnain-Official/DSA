// #include<iostream>

// using namespace std;

// struct Node {
//     char Data;
//     Node *next;
// };



// int main() {

// }


#include <iostream>

using namespace std;

int main() {
    int n, k;
    
    // Input the number of nodes in A and the limit k
    cout << "Enter the number of nodes in A: ";
    cin >> n;
    cout << "Enter the limit k for edges A can hold: ";
    cin >> k;
    
    // Calculate the maximum number of nodes B can connect to A
    int maxNodesB = min(n - 1, k);
    
    cout << "Node A can be connected to at most " << maxNodesB << " nodes from B." << endl;
    
    return 0;
}
