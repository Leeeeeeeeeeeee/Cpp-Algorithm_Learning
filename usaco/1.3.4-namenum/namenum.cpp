/*
ID: qq267181
TASK: namenum
LANG: C++
*/
#include <cstring>
#include <fstream>
#include <iostream>

using namespace std;
int main()
{
  string namenum;
  string dictstr;
  char phone[8][3] = {
      {'A', 'B', 'C'},
      {'D', 'E', 'F'},
      {'G', 'H', 'I'},
      {'J', 'K', 'L'},
      {'M', 'N', 'O'},
      {'P', 'R', 'S'},
      {'T', 'U', 'V'},
      {'W', 'X', 'Y'}};
  int i = 0;
  bool isEnd = false;
  bool hasName = false;
  ifstream num("namenum.in");
  num >> namenum;
  int n = namenum.length();
  ifstream dict("dict.txt");
  ofstream out("namenum.out");
  dict >> dictstr;
  while (!isEnd)
  {
    // cout << "start" << endl;
    dict >> dictstr;
    if (dict.eof())
    {
      isEnd = true;
    }
    if (n != (int)dictstr.length())
    {
      continue;
    }
    for (i = 0; i < n; i++)
    {
      // cout << i << endl;
      if (dictstr[i] < phone[namenum[i] - '2'][0])
      {
        // cout << "small" << endl;
        break;
      }
      else if (dictstr[i] > phone[namenum[i] - '2'][2])
      {
        // cout << "large" << endl;
        break;
      }
    }
    if (i == n)
    {
      // cout << dictstr << endl;
      hasName = true;
      out << dictstr << endl;
    }
  };
  if (!hasName)
  {
    out << "NONE" << endl;
  }
  return 0;
}
