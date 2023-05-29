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
  int interval_1, interval_1_start, interval_1_end;
  int interval_0, interval_0_start, interval_0_end;

  // input
  ifstream fin("milk2.in");
  fin >> num_farmer;
  vector<pair<int, int>> time;
  for (i = 0; i < num_farmer; i++)
  {
    fin >> temp;
    time.push_back(make_pair(temp, 0));
    fin >> temp;
    time.push_back(make_pair(temp, 1));
  }

  // compute
  sort(time.begin(), time.end(), comparePairs);

  for (std::vector<pair<int, int>>::iterator it = time.begin(); it != time.end(); ++it)
  {
    // new farmer entered
    if (0 == (*it).second)
    {
      now_farmer++;
    }
    // a farmer left
    else if (1 == (*it).second)
    {
      now_farmer--;
    }
    if (0 == now_farmer)
    {
      interval_0_start = (*it).first;
    }
    else if (0 < now_farmer)
    {
      if (0 == (*it).second)
      {
        interval_1_start = (*it).first;
        if (1 == now_farmer)
        {
          interval_0_end = (*it).first;
        }
      }
      else
      {
        interval_1_end = (*it).first;
      }
    }
    if (interval_1 < interval_1_end - interval_1_start)
    {
      interval_1 = interval_1_end - interval_1_start;
    }
    if (interval_0 < interval_0_end - interval_0_start)
    {
      interval_0 = interval_0_end - interval_0_start;
    }
  }

  // output
  ofstream fout("milk2.out");
  fout << interval_1 << ' ' << interval_0 << endl;
  return 0;
}
