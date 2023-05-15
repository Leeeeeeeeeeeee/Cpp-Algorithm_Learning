/*
ID: qq267181
TASK: ride
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
  int i;
  int sum1 = 1, sum2 = 1;
  char s1[8], s2[8];

  ofstream fout("ride.out");
  ifstream fin("ride.in");

  fin >> s1;
  fin >> s2;

  for (i = 0; i < 8; i++)
  {
    if ('\n' == s1[i] || '\0' == s1[i] || 0 == s1[i])
    {
      break;
    }
    sum1 = sum1 * (s1[i] - 64);
  }

  for (i = 0; i < 8; i++)
  {
    if ('\n' == s2[i] || '\0' == s2[i] || 0 == s2[i])
    {
      break;
    }
    sum2 = sum2 * (s2[i] - 64);
  }

  if (sum1 % 47 == sum2 % 47)
    fout << "GO" << endl;
  else
    fout << "STAY" << endl;
  return 0;
}
