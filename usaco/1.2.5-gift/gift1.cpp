/*
ID: qq267181
TASK: gift1
LANG: C++
*/

#include <iostream>
#include <cstring>
#include <fstream>
#include <map>

using namespace std;

int main()
{
  int i;
  int temp_int, temp_int2;
  string temp_str, temp_str2;
  map<string, int> players;

  ifstream fin("gift1.in");
  ofstream fout("gift1.out", ios_base::out);

  // init players
  fin >> temp_int;
  for (i = 0; i < temp_int; i++)
  {
    fin >> temp_str;
    players[temp_str] = 0;
  }

  // give money circle
  while (!fin.eof())
  {
    // giver
    fin >> temp_str;
    // money to give and number of people to share
    fin >> temp_int >> temp_int2;
    if (temp_int2 != 0)
    {
      // receiver
      for (i = 0; i < temp_int2; i++)
      {
        fin >> temp_str2;
        players[temp_str2] += temp_int / temp_int2;
      }
      players[temp_str] += -temp_int + temp_int % temp_int2;
    }
  }

  // output
  for (auto it = players.begin(); it != players.end(); ++it)
  {
    fout << it-> first << ' ' << it-> second << endl;
  }

  return 0;
}
