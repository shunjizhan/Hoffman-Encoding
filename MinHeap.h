#include <iostream>
#include <string>
#include <cstdio>
#include <map>
using namespace std;

//////////////////////// Node //////////////////////////

class Node {
 public:
  Node(){
    this->character = '#';
    this->freq = 0;
    this->left = NULL;
    this->right = NULL;
    code = "";
    }

  Node(char c, int freq) {
    this->character = c;
    this->freq = freq;
    this->left = NULL;
    this->right = NULL;
    code = "";
  }
  
   Node(char c){
    this->character = c;
    this->freq = 1;
    this->left = NULL;
    this->right = NULL;
    code = "";
    }

  Node(Node* left, Node* right, char c, int freq){
    this->character = c;
    this->freq = freq;
    this->left = left;
    this->right = right;
    code = "";
  }
  
  ~Node(){
  }

  char getC() {
    return character;
  }

  int getF() {
    return freq;
  }
  
  char character;
  int freq;
  Node* left;
  Node* right;
  string code, decode;
};

////////////////////////// Heap //////////////////////////////

class Heap { 
 public:

  Node* array;
  Node* tree;
  Node** treeStar;
  Node* Minheap;
  int sizeOfTree;
  std::map<char,std::string> map;
  std::map<std:: string,char> decodeMap;

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
    buildMinHeap();
  }

  // This is OK
  void buildMinHeap(){
    int k;
    for(int i=sizeOfTree-1; i>=1; i--) {
      percolateDown(i);
    }
   
    //cout << "print tree........" << endl;
    //printTree();
    
    // switch the tree to Node**
    buildTreeStar();

    //cout << "print treeStar...." << endl;
    //printTreeStar();
  }

  Node* getMin(){
    Node* temp = treeStar[1];
       
    //cout << "before swap:" << endl;
    //printTreeStar();
    
    sizeOfTree -= 1;
    treeStar[1] = treeStar[sizeOfTree];      // put the last Node to the root
    treeStar[sizeOfTree] = NULL;
    
    //cout << "before percolate down" << endl;
    //printTreeStar();

    percolateDown2(1);   // This function is OK

    //cout << "after percolate down" << endl;
    //printTreeStar();
    
    return temp;
  }
    
 
  void merge(){  
    while(sizeOfTree > 2) {
      //cout << "size is:" << sizeOfTree << endl;
      
      Node* tmp1 = getMin();
      Node* tmp2 = getMin();
      //Node* tmp3 = new Node(tmp1.character, tmp1.freq);
      //Node* tmp4 = new Node(tmp2.character, tmp2.freq);
      //cout << "tmp1->freq =" << tmp1->freq << endl;
      //cout << "tmp2->freq =" << tmp2->freq << endl;
      int newfreq = (tmp1->freq + tmp2->freq);
      //cout << "newfreq=" << newfreq << endl;

      //cout << "size is:" << sizeOfTree << endl;
      
      sizeOfTree += 1;
      Node** temp = new Node*[sizeOfTree];
      for(int i=0; i<sizeOfTree-1; i++) {
	temp[i] = treeStar[i];
      }
      
      Node* T = new Node(tmp2, tmp1, 'T', newfreq);
      temp[sizeOfTree-1] = T;

      treeStar = new Node*[sizeOfTree];
      for(int i=0; i<sizeOfTree; i++) {
	treeStar[i] = temp[i];
      }
      int index = sizeOfTree-1;

      //cout << "!!!!!!!!!!!!!!!!!!" << endl;
      //cout << treeStar[0]->getC() << treeStar[2]->getF() << endl;
      // percoalte up
      while(index/2 >= 1){
	//cout << "1" ;
	//cout << "index=" << index;
	//cout << "size is:" << sizeOfTree << endl;
	//cout << "treeStar is: " << endl;
	//printTreeStar();
	if(treeStar[index/2]->freq > treeStar[index]->freq) {
	  //cout << "111111111111111111" << endl;
	  swap(treeStar[index/2],treeStar[index]);
	  index = index/2;
	}
	else{
	  break;
	  }
      }
    }
  }

  void buildMap() {
    Node* root = treeStar[1];
    buildMap(root);
  }

  void buildMap(Node* node) {
    if(node->left != NULL) {
      node->left->code = node->code + "1";   
      buildMap(node->left);
    }
    if(node->right != NULL) {
      node->right->code = node->code + "0";
      buildMap(node->right);
    }
    else if(node->right == NULL && node->left == NULL) {
      //cout << "key=" << node->code << " ";
      //cout << "character=" << node->character << endl;
      map[node->character] = node->code;
    }
  }

  void buildDecodeMap(){
    Node* root = treeStar[1];
    buildDecodeMap(root);
  }

  void buildDecodeMap(Node* node){
    if(node->left != NULL) {
      node->left->decode = node->decode + "1";
      buildDecodeMap(node->left);
    }
    if(node->right != NULL) {
      node->right->decode = node->decode + "0";
      buildDecodeMap(node->right);
    }
    else if(node->right == NULL && node->left == NULL) {
      decodeMap[node->decode] = node->character;
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
    //cout << "Start buildHeap" << endl;
    buildHeap(s);

    //cout << "Start buildMinHeap" << endl;
    buildMinHeap();

    //cout << "Start merge" << endl;
    merge();

    //cout << "Start buildmap" << endl;
    buildMap();

    //cout << "Start printcode" << endl;
    printCode(s);

    //cout << "finished" << endl;
  }

  void printDecode(std::string s) {
    string decode = "";
    buildDecodeMap();
    string output = "";
    for(int i=0; i<s.length(); i++){
      decode += s[i];
      std::map<std::string, char>::iterator it = decodeMap.find(decode);
      if(it != decodeMap.end()){
	output += decodeMap[decode];
	decode = "";
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
    //cout << "Swap!!!" << endl;
    Node c = a;
    a = b;
    b = c;
  }

  void swap(Node* &a, Node* &b) {
    //cout << "Swap!!!" << endl;
    Node* c = a;
    a = b;
    b = c;
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

   void percolateDown2(int i) {
    int left = 2*i;
    int right = 2*i + 1;  
    if(2*i >= sizeOfTree){      // leaf
      return;
    }
    else if(left == sizeOfTree-1) {   // only has left child
      if(treeStar[i]->freq > treeStar[left]->freq)
	swap(treeStar[i],treeStar[left]);
    }
    else if(treeStar[i]->freq > treeStar[left]->freq
	    || treeStar[i]->freq > treeStar[right]->freq) {
      if(treeStar[right]->freq <= treeStar[left]->freq) {
	swap(treeStar[i], treeStar[right]);
	percolateDown2(right);
      }
      else {
	swap(treeStar[i], treeStar[left]);
	percolateDown2(left);
      }
    }
    else {
      return;
    }
  }

   /*void printArray(){
    for(int i=0; i<27; i++) {
      cout << array[i].character << array[i].freq << " ";
    }
    cout << endl;
  }

   void printTree(){
    for(int i=0; i<sizeOfTree; i++) {
      cout << tree[i].character << tree[i].freq << " ";
    }
    cout << endl;
  }

   void printTreeStar() {
    for(int i=0; i<sizeOfTree; i++) {
      cout << treeStar[i]->getC() << treeStar[i]->getF() << " ";
    }
    cout << endl;
  }

  void printTrie(){
    cout << "start printing Trie" << endl;
    printTrie(treeStar[1]);
  }
  
  void printTrie(Node* node){
    // print this node and its children
    cout << "this: " << node->getC() << node->getF() << " ";
    if(node->left != NULL) {
      cout << "this->left: " << node->left->getC() << node->left->getF() << " ";
    }
    if(node->right != NULL) {
      cout << "this->right: " << node->right->getC() << node->right->getF() << " ";
    }
    cout << endl;
    
    // recursive call
    if(node->left != NULL) {
      //cout << "left: " << node->left->getC() << node->left->getF() << endl;
      printTrie(node->left);
    }
    if(node->right != NULL) {
      //cout << "right: " << node->right->getC() << node->right->getF() << endl;
      printTrie(node->right);
    }
    return;
  }

  void printMap() {
    std::map<char,std::string>::const_iterator i;   
    for(i=map.begin(); i!=map.end(); i++) {
      cout << i->first << " ";
      cout << i->second;
      cout << endl;
    } 
    }*/

  void buildTreeStar(){
    treeStar = new Node*[sizeOfTree];
    for(int i=0; i<sizeOfTree; i++) {
      treeStar[i] = new Node(tree[i].character, tree[i].freq);
    }
  }

  /*
  string getPreviousKey(string s) {\
    string v;
    for(int i=0; i<s.length()-1; i++) {
      v += s[i];
    }
    return v;
  }
  */
 
};



