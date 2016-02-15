#include <iostream>
#include <exception>
#include <string>
#include <cstdio>
#include <ctime>
#include <fstream>
#include "MinHeap.h"
using namespace std;

int main() {

  string plain, encoded;
  ifstream myfile1 ("plain.input");
  ifstream myfile2 ("encoded.input");
  
  getline(myfile1, plain);
  getline(myfile2, encoded);
  
  Heap h;
  h.buildHeap(plain);
  h.merge();
  h.buildMap();
  h.printCode(plain);
  h.printDecode(encoded);    
  
  myfile1.close();
  myfile2.close();
  
  return 0;
}
    //freopen("input.txt","r",stdin);

    //h.buildHeap("aaaaaaahfgdhfgdaaaaaaabiiighfdhgfdghfiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiddddddddddddddd   dddddghfddddhhhhh  hhhhhhhhhhhhtrhhjtyrjdtyurjuydrhhhhhdfdsafhhhhhhhhheeeeeeeeeeeeeeeeeeeeeeeeeehgfdhftgdfgkfyjhdghfujgf   ythreeeeeeefdmmmmmmmmmmmmmmmmmmmytrju  yrujyhgfdhgfdhf   gdghfrjtrhytg  hfgdhfdhfg vchgfjkuyfkuyfjujudyrmmmmmmmmmmmmmmmmdhfgdmmcccccccccccu    ytfjydtjydtjytccccccccccccccccccccccbbbbbbbbbbbbbbbhtfdhfdhgdbbbbbbbaaaaaaaaaaaccccccccccccccccccccccaaaaa");
    //cout << "Start building Heap" << endl;
    //h.buildHeap("ytu erh fgsdh xcvsd ue   rbc xbe hbyhcvb rbcygegh");
    
    //h.buildHeap("aabcccddddddde");
    // h.buildHeap("asjhdfgjuhdfgjuhwegujyfhgsdjyfugqwqwpoiudsfughehrvhgdvzxcvmnsdfgbyjxgfjhserfgjygxjshnfbjwehgxvnbsdjhfbsjmdhgfjhxgvbjnzbxmnbqmwebqwkruhodiufh");
    //cout << "finished building Heap" << endl;
    //h.printTree();
    //cout << endl;

    //cout << "Start merging" << endl;
    
    //cout << "finished merging" << endl;
    //h.printTreeStar();
    //h.printTrie();

    //cout << "start building map...." << endl;
   
    //cout << "finished building map" << endl;
    //cout << "map is:" << endl;
    //h.printMap();
    
    // cout << "start encode...." << endl;
    //cout << "the code is: ";
    
    //cout << "print code finsihed!" << endl;

    //cout << "start decoding...." << endl;
    //cout << "the text is: ";
    
    //cout << "print decode finished!" << endl;
    
    /*
    string str;
    cin >> str;
    h.encode(str);
    */
   

