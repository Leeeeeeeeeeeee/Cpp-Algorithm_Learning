/*
ID: qq267181
TASK: beads
LANG: C++
*/

#include <fstream>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
  int i = 0, r, l, p;
  char target;
  int n = 0, max = 0;

  ifstream fin("beads.in");
  fin >> n;
  char beads[n];
  fin >> beads;

  while (i < n)
  {
    // 认为当前的珠子是右边第一个珠子
    // 左右两边的珠子相同的时候不切
    // 优化：record which color we're going to collect
    if (beads[i] != beads[(n + i - 1) % n])
    {
      // cout << "i:" << i;
      // 重置计数器
      l = 1, r = 1;
      // 先向右计数，注意如果target是w需要在找到r或b后更新
      target = beads[i];
      // pointer 指向target右边的珠子。
      p = (i + 1) % n;
      // cout << "  right:" << target;
      while ('w' == beads[p] || ('w' == target ? target = beads[p] : target == beads[p]))
      {
        // cout << beads[p];
        r++;
        p = (i + r) % n;
      }
      // 向左计数
      target = beads[(n + i - 1) % n];
      p = (n + i - l - 1) % n;
      // cout << "  left:" << target;
      while ('w' == beads[p] || ('w' == target ? target = beads[p] : target == beads[p]))
      {
        // cout << beads[p];
        l++;
        p = (n + i - l - 1) % n;
      }
      // 更新珠子最大值
      if (l + r > max)
      {
        max = l + r;
        // cout << "  max:" << max;
      }
      // cout << endl;
    }
    i++;
  }

  if (0 == max || max > n)
  {
    max = n;
  }
  ofstream fout("beads.out");
  fout << max << endl;
  return 0;
}
