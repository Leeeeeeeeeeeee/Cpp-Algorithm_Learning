/*
ID: qq267181
TASK: milk2
LANG: C++
*/

#include <fstream>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

bool comparePairs(const std::pair<int, int> &a, const std::pair<int, int> &b)
{
  return a.first < b.first;
}

int main()
{
  int i = 0, j = 0;
  int temp;
  int num_farmer, now_farmer = 0;
  int interval_1 = 0, interval_1_head;
  int interval_0 = 0, interval_0_head;

  // input
  ifstream fin("milk2.in");
  fin >> num_farmer;
  vector<pair<int, int>> time;
  for (i = 0; i < num_farmer; i++)
  {
    fin >> temp;
    // 1 stand for enter
    time.push_back(make_pair(temp, 1));
    // -1 stand for leave
    fin >> temp;
    time.push_back(make_pair(temp, -1));
  }

  // compute

  // 1.arrange in ascending order
  sort(time.begin(), time.end(), comparePairs);

  vector<pair<int, int>> timef;
  for (std::vector<pair<int, int>>::iterator it = time.begin(); it != time.end(); ++it)
  {
    if (it != time.end() && (*it).first == (*(it + 1)).first && 0 == (*it).second + (*(it + 1)).second)
    {
      ++it;
    }
    else
    {
      timef.push_back(*it);
    }
  }

  // for (std::vector<pair<int, int>>::iterator it = timef.begin(); it != timef.end(); ++it)
  // {
  //   cout << (*it).first << ' ' << (*it).second << endl;
  // }

  for (std::vector<pair<int, int>>::iterator it = timef.begin(); it != timef.end(); ++it)
  {
    // 2.compute num of farmer
    // new farmer entered
    if (1 == (*it).second)
    {
      // before a >1 farmer gap
      if (0 == now_farmer)
      {
        // 3.setup the head of >1 farmer gap
        interval_1_head = (*it).first;
      }
      now_farmer++;
      // after a 0 farmer gap
      if (it != timef.begin() && 1 == now_farmer)
      {
        // 4.reset the max 0 farmer gap
        if (interval_0 < (*it).first - interval_0_head)
        {
          interval_0 = (*it).first - interval_0_head;
        }
      }
    }
    // a farmer left
    else if (-1 == (*it).second)
    {
      // before a 0 farmer gap
      if (1 == now_farmer)
      {
        // 3.setup the head of 0 farmer gap
        interval_0_head = (*it).first;
      }
      now_farmer--;
      // after a >1 farmer gap
      if (0 == now_farmer)
      {
        // 4.reset the max >1 farmer gap
        if (interval_1 < (*it).first - interval_1_head)
        {
          interval_1 = (*it).first - interval_1_head;
        }
      }
    }
  }

  // output
  ofstream fout("milk2.out");
  fout << interval_1 << ' ' << interval_0 << endl;
  return 0;
}
