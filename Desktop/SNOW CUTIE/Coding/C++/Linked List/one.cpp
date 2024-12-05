#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
    Node(int value){
        data=value;
        next=NULL;
    }
};

int main(){
    Node *start;
    // start=new Node(4);
    // cout<<start->data<<endl;
    // cout<<start->next<<endl;
    start=NULL;
    // Node A1(4);

    int arr[]={2,4,6,8,10};

    //Insert the node at beginning
//Linked list doesn't exist
for (int i=0;i<5;i++){
if(start==NULL){
    start=new Node(arr[i]);
}
//Linked List exists
else{
    Node *temp;
    temp=new Node(arr[i]);
    temp->next=start;
    start=temp;
}

}
 // Print the values
    Node *temp = start;
    while (temp != NULL) {
        cout << temp->data << ' ';
        temp = temp->next;
    }

    return 0; // Added return statement
} // Removed extra semicolon
