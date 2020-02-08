#include <locale>
#include <assert.h>
#include <map>
#include <string>
#include <iostream>
#include <cstdlib>
#include <limits>
using namespace std;

class Solution {
public:
  static const int myAtoi(const string &str) {
    int neg=1, break1=false; char curChar;
    int cur=0, strSize=str.size();
    while (cur<strSize) {
      curChar=str[cur];
      switch (curChar) {
        case ' ': break;
        case '-': neg=-1;
        case '+': break1=true; ++cur; break;
        default:
          if (isdigit(curChar)) break1=true;
          else return 0;
          break;
      }
      if (break1) break;
      ++cur;
    }
    if (cur>str.size()) return 0;
    curChar=str[cur]; 

    long res=0;
    int imin = numeric_limits<int>::min(),
        imax = numeric_limits<int>::max();
    while (isdigit(curChar)) {
      res = 10*res+(long)(curChar-'0');
      if (neg*res>(long)imax) return imax;
      else if (neg*res<(long)imin) return imin;
      else if (++cur>=strSize) break;
      curChar=str[cur]; 
    }
    return (int)(neg*res);
  }

  static void test(const map<const string,const int>&ta) {
    for (auto ini=ta.begin(), end=ta.end(); ini!=end; ++ini) {
      //assert(myAtoi(ini->first)==ini->second);
      int transStr=myAtoi(ini->first);
      if (transStr!=ini->second) {
        cout << transStr << " != " << ini->second << endl;
        abort();
      }
    }
  }
};


/*
int main() {
  // Test configuration
  map<const string,const int> ta = {
    {"11",11},
    {"",0},
    {"  ",0},
    {"   +21",21},
    {"   -42",-42},
    {"88fsdf",88},
    {"4193 with words",4193},
    {"words and 987",0},
    {"-123j",-123},
    {"2147483646", 2147483646},
    {"2147483647", numeric_limits<int>::max()},
    {"2147483648", numeric_limits<int>::max()},
    {"-2147483647", -2147483647},
    {"-2147483648", numeric_limits<int>::min()},
    {"-2147483649", numeric_limits<int>::min()},
    {"-91283472332", numeric_limits<int>::min()},
  };

  // Test execution
  Solution::test(ta);
}*/
