#include <iostream>
#include <exception>
#include <string>
#include <cstdio>
#include <ctime>
#include "MinHeap.h"
using namespace std;

int main() {

  freopen("input.txt","r",stdin);

      
    Heap h;
    
    //h.buildHeap("aaaaaaahfgdhfgdaaaaaaabiiighfdhgfdghfiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiddddddddddddddd   dddddghfddddhhhhh  hhhhhhhhhhhhtrhhjtyrjdtyurjuydrhhhhhhhhhhhhhheeeeeeeeeeeeeeeeeeeeeeeeeehgfdhftgdfgkfyjhdghfujgf   ythreeeeeeefdmmmmmmmmmmmmmmmmmmmytrju  yrujyhgfdhgfdhf   gdghfrjtrhytg  hfgdhfdhfg vchgfjkuyfkuyfjujudyrmmmmmmmmmmmmmmmmdhfgdmmcccccccccccu    ytfjydtjydtjytccccccccccccccccccccccbbbbbbbbbbbbbbbhtfdhfdhgdbbbbbbbaaaaaaaaaaaccccccccccccccccccccccaaaaa");
    //cout << "Start building Heap" << endl;
    //h.buildHeap("ytu erh fgsdh xcvsd ue   rbc xbe hbyhcvb rbcygegh");
    //h.buildHeap("aabbcccd");
    //h.buildHeap("aabcccddddddde");
    // h.buildHeap("asjhdfgjuhdfgjuhwegujyfhgsdjyfugqwqwpoiudsfughehrvhgdvzxcvmnsdfgbyjxgfjhserfgjygxjshnfbjwehgxvnbsdjhfbsjmdhgfjhxgvbjnzbxmnbqmwebqwkruhodiufh");


    
    string str;
    cin >> str;
    h.encode(str);
    
   

  return 0;

}

