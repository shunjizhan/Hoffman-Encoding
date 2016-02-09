#include <iostream>
#include <exception>
#include <string>
#include <cstdio>
#include <ctime>
#include "MinHeap.h"
using namespace std;

int main() {

  //freopen("input.txt","r",stdin);

      
    Heap h;
    
    //h.buildHeap("aaaaaaahfgdhfgdaaaaaaabiiighfdhgfdghfiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiddddddddddddddd   dddddghfddddhhhhh  hhhhhhhhhhhhtrhhjtyrjdtyurjuydrhhhhhhhhhhhhhheeeeeeeeeeeeeeeeeeeeeeeeeehgfdhftgdfgkfyjhdghfujgf   ythreeeeeeefdmmmmmmmmmmmmmmmmmmmytrju  yrujyhgfdhgfdhf   gdghfrjtrhytg  hfgdhfdhfg vchgfjkuyfkuyfjujudyrmmmmmmmmmmmmmmmmdhfgdmmcccccccccccu    ytfjydtjydtjytccccccccccccccccccccccbbbbbbbbbbbbbbbhtfdhfdhgdbbbbbbbaaaaaaaaaaaccccccccccccccccccccccaaaaa");
    //cout << "Start building Heap" << endl;
    //h.buildHeap("ytu erh fgsdh xcvsd ue   rbc xbe hbyhcvb rbcygegh");
    h.buildHeap("aabbcccd");
    //h.buildHeap("aabcccddddddde");
    // h.buildHeap("asjhdfgjuhdfgjuhwegujyfhgsdjyfugqwqwpoiudsfughehrvhgdvzxcvmnsdfgbyjxgfjhserfgjygxjshnfbjwehgxvnbsdjhfbsjmdhgfjhxgvbjnzbxmnbqmwebqwkruhodiufh");
    cout << "finished building Heap" << endl;
    h.printTree();
    cout << endl;

    cout << "Start merging" << endl;
    h.merge();
    cout << "finished merging" << endl;
    h.printTreeStar();
    h.printTrie();

    cout << "start building map...." << endl;
    h.buildMap();
    cout << "finished building map" << endl;
    cout << "map is:" << endl;
    h.printMap();
    
    cout << "start encode...." << endl;
    cout << "the code is: ";
    h.printCode("aabbcccd");
    cout << "print code finsihed!" << endl;

    /*
    string str;
    cin >> str;
    h.encode(str);
    */
   

  return 0;

}

