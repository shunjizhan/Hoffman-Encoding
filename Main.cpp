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

    h.printArray();
    cout << endl;

    h.buildHeap("aaaaaaahfgdhfgdaaaaaaabiiighfdhgfdghfiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiddddddddddddddd   dddddghfddddhhhhh  hhhhhhhhhhhhtrhhjtyrjdtyurjuydrhhhhhhhhhhhhhheeeeeeeeeeeeeeeeeeeeeeeeeehgfdhftgdfgkfyjhdghfujgf   ythreeeeeeefdmmmmmmmmmmmmmmmmmmmytrju  yrujyhgfdhgfdhf   gdghfrjtrhytg  hfgdhfdhfg vchgfjkuyfkuyfjujudyrmmmmmmmmmmmmmmmmdhfgdmmcccccccccccu    ytfjydtjydtjytccccccccccccccccccccccbbbbbbbbbbbbbbbhtfdhfdhgdbbbbbbbaaaaaaaaaaaccccccccccccccccccccccaaaaa");
  
    h.printArray();
    
    /*string str;
    cin >> str;
    h.encode(str);
  
    catch(exception& ex){
    cerr << ex.what() << endl;
    }*/

  return 0;

}

