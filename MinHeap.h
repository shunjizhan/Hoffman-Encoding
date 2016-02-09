#include <iostream>
#include <string>
#include <cstdio>
#include <map>
using namespace std;

/////////////////////// Node //////////////////////////

class Node {
 public:
  Node(){
    this->character = '#';
    this->freq = 0;
    this->left = NULL;
    this->right = NULL;
    }

  Node(char c, int freq) {
    this->character = c;
    this->freq = freq;
    this->left = NULL;
    this->right = NULL;
  }
  
   Node(char c){
    this->character = c;
    this->freq = 1;
    this->left = NULL;
    this->right = NULL;
    }

  Node(Node* left, Node* right, char c, int freq){
    this->character = c;
    this->freq = 1;
    this->left = left;
    this->right = right;
  }
  
  ~Node(){
  }
  
  char character;
  int freq;
  Node* left;
  Node* right;
};

////////////////////////// Heap //////////////////////////////

class Heap { 
 public:

  Node* array;
  Node* tree;
  Node* Minheap;
  int sizeOfTree;
  std::map<char,std::string> map;
  
  const static int SIZE = 27;

  Heap() {
    array = new Node[SIZE];
    array[0].character = 'a';
    array[1].character = 'b';
    array[2].character = 'c';
    array[3].character = 'd';
    array[4].character = 'e';
    array[5].character = 'f';
    array[6].character = 'g';
    array[7].character = 'h';
    array[8].character = 'i';
    array[9].character = 'j';
    array[10].character = 'k';
    array[11].character = 'l';
    array[12].character = 'm';
    array[13].character = 'n';
    array[14].character = 'o';
    array[15].character = 'p';
    array[16].character = 'q';
    array[17].character = 'r';
    array[18].character = 's';
    array[19].character = 't';
    array[20].character = 'u';
    array[21].character = 'v';
    array[22].character = 'w';
    array[23].character = 'x';
    array[24].character = 'y';
    array[25].character = 'z';
    array[26].character = ' ';   
  }

  // this is OK
  void buildHeap(std::string s){ 
    for(int i=0; i<s.length(); i++){
      int index = findIndex(s[i]);
      array[index].freq ++;
    }

    sizeOfTree = findNoneZero()+1;
    tree = new Node[sizeOfTree];
    int count = 1;
    for(int i=0; i<SIZE; i++) {
      if(array[i].freq != 0){
	tree[count] = array[i];
	count++;
      }
    }
  }

  // this is OK
  void buildMinHeap(){
    int k;
    for(int i=sizeOfTree-1; i>=1; i--) {
      percolateDown(i);
    }
  }

  Node deleteMin(){
    Node temp = tree[1];
    int index = 1;
    sizeOfTree -= 1;
    tree[index] = tree[sizeOfTree];        // put the last Node to the root
    while(2*index+1 <= sizeOfTree){
      if(tree[index].freq < tree[2*index].freq || tree[index].freq < tree[2*index+1].freq){
	if(tree[2*index+1].freq <= tree[2*index].freq){
	  swap(tree[2*index+1], tree[index]);
	  index = index*2+1;
	}
	else {
	  swap(tree[2*index], tree[index]);
	  index = 2*index;
	}
      }
    }
    if(2*index < sizeOfTree) {
      if(tree[index].freq > tree[2*index].freq) {
	swap(tree[index], tree[2*index]);
      }
    }
    
    
    Node* tmp = new Node[sizeOfTree];
    for(int i=0; i<sizeOfTree; i++){
      tmp[i] = tree[i];
    }
    tree = tmp;
    return temp;
  }

  
  void merge(){
    while(sizeOfTree > 2) {
    Node tmp1 = deleteMin();
    Node tmp2 = deleteMin();
    Node* tmp3 = &tmp1;
    Node* tmp4 = &tmp2;
    int newfreq = (tmp3->freq + tmp4->freq);
  
    sizeOfTree += 1;
    int index = sizeOfTree-1;

    Node* temp = new Node[sizeOfTree];
    for(int i=1; i<sizeOfTree-1; i++) {
      temp[i] = tree[i];
    }

    Node* a = new Node(tmp4, tmp3, 'T', newfreq);
    temp[sizeOfTree-1] = *a;
    tree = temp;

    // percoalte up
    while(index/2 >= 1){
      if(tree[index/2].freq > tree[index].freq)
	swap(tree[index/2],tree[index]);
    }
    }
  }

  void buildmap() {
    Node* root = &tree[1];
    buildmap(root);
  }

  void buildmap(Node* node) {
    string key = "";
    if(node->left != NULL) {
      key += "1";
      buildmap(node->left);
    }
    if(node->right != NULL) {
      key += "0";
      buildmap(node->right);
    }
    else if(node->right == NULL && node->left == NULL) {
      map[node->character] = key;
    }
  }

  void printCode(std::string s) {
    string code = "";
    for(int i=0; i<s.length(); i++) {
      code += map[s[i]];
    }
    cout << code << endl;
  }

  void encode(std::string s) {
    cout << "Start buildHeap" << endl;
    buildHeap(s);

    cout << "Start buildMinHeap" << endl;
    buildMinHeap();

    cout << "Start merge" << endl;
    merge();

    cout << "Start buildmap" << endl;
    buildmap();

    cout << "Start printcode" << endl;
    printCode(s);

    cout << "finished" << endl;
  }

  void printDecode(std::string s) {
    string code = "";
    string output = "";
    for(int i=0; i<s.length(); i++){
      code += s[i];
      if(map.find(s[i])== map.end()){
	output += map[s[i]];
	code = "";
      } 
    }
    cout << output << endl;
  }

  ///////////////////////  helper ///////////////////////////
 
  int findIndex(char c) {
    for(int i=0; i<SIZE; i++){
     if(array[i].character == c){
	return i;
      }
    }
    return 0;
  }

  int findNoneZero(){
    int count = 0;
    for(int i=0; i<SIZE; i++) {
      if(array[i].freq != 0)
	count++;
    }
    return count;
  }

  void swap(Node &a, Node &b) {
    cout << "Swap!!!" << endl;

    char c = a.character;
    int f = a.freq;
    
    a.freq = b.freq;
    a.character = b.character;
    
    b.freq = f;
    b.character = c;
  }

  void percolateDown(int i) {
    int left = 2*i;
    int right = 2*i + 1;  
    if(2*i >= sizeOfTree){      // leaf
      return;
    }
    else if(left == sizeOfTree-1) {   // only has left child
      if(tree[i].freq > tree[left].freq)
	swap(tree[i],tree[left]);
    }
    else if(tree[i].freq > tree[left].freq || tree[i].freq > tree[right].freq) {
      if(tree[right].freq <= tree[left].freq) {
	swap(tree[i], tree[right]);
	percolateDown(right);
      }
      else {
	swap(tree[i], tree[left]);
	percolateDown(left);
      }
    }
    else {
      return;
    }
  }

  void printArray(){
    for(int i=0; i<27; i++)
      cout << array[i].character << " " << array[i].freq << endl;
  }

   void printTree(){
    for(int i=0; i<sizeOfTree; i++)
      cout << tree[i].character << " " << tree[i].freq << endl;
  }
 
};



