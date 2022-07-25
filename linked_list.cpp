#include<iostream>
using namespace std;

struct Node {
  int data;
  Node *next;

  Node(int data) {
    this->data = data;
    next = nullptr;
  }
};

struct List {
  Node* head;

  List() {
    head = nullptr;
  }

  void sortedInser(int data) {
  Node* temp = new Node(data);
  if (head == nullptr) {
      head = temp;
    return;
    }
  Node* iterator = head;
    while (iterator->next) {
      if((temp->data >= iterator->data) && (temp->data <= iterator->next->data)){
        temp->next = iterator->next;
        iterator->next = temp;
        return;
      }
      iterator = iterator->next;
    }
  }

  void insert(int data) {
    Node* temp = new Node(data);
    if (head == nullptr) {
      head = temp;
    return;
    }

    Node* iterator = head;
    while (iterator->next) {
      iterator = iterator->next;
    }
    iterator->next = temp;
  }

  void display() {
    Node* temp = head;
    while (temp) {
      cout << temp->data << ' ';
      temp = temp->next;
    }
    cout << endl;
  }
  int numNodes() {
      int res=0;
      Node* temp = head;
    while (temp) {
      res++;
      temp = temp->next;
    }
    return res;
  }
  int sum() {
      int res=0;
      Node* temp = head;
      while(temp) {
        res+=temp->data;
        temp=temp->next;
      }
      return res;
  }
  int maxELE() {
      int res = INT_MIN;
      Node* temp = head;
      while(temp) {
        if(temp->data > res){res=temp->data;}
        temp=temp->next;
      }
      return res;
  }
  int searchEle(int x) {
  Node* temp = head;
  int pos=0;
  int ans = -1;
  while(temp){
    if(temp->data == x){ans=pos;}
    else{pos++;}
    temp=temp->next;
  }
  return ans;
  }

  int _delete(int index) {
  Node* temp = nullptr;
  if(index==0){
    int res = head->data;
    temp = head;
    head = head->next;
    delete(temp);
    return res;
  }
  else{
        Node* iterator = head;
        for(int i=0;i<index-1;i++){
            iterator = iterator->next;
        }
        int res = iterator->next->data;
        temp = iterator->next;
        iterator->next = iterator->next->next;
        delete(temp);
        return res;
  }
  }
  bool isSorted(){
  Node* temp = head;
  while(temp->next){

  }
  }

};

int main() {
  List l;
  l.insert(1);
  l.insert(2);
  l.insert(30);
  l.insert(40);
  int numOfNodes = l.numNodes();
  cout << numOfNodes << endl;
  int sum = l.sum();
  cout << sum << endl;
  int max_ele = l.maxELE();
  cout << max_ele << endl;
  l.display();
  int pos = l.searchEle(4);
  cout << pos << endl;
  l.sortedInser(7);
  l.display();
  int del = l._delete(2);
  l.display();

  return 0;
}
