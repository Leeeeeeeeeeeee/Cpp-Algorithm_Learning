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
  map<string, int> players_account;

  ifstream fin("gift1.in");
  ofstream fout("gift1.out", ios_base::out);

  // init players
  fin >> temp_int;
  string players_name[temp_int];
  for (i = 0; i < temp_int; i++)
  {
    fin >> temp_str;
    players_account[temp_str] = 0;
    players_name[i] = temp_str;
  }

  // give money circle
  while (fin >> temp_str)
  {
    // money to give and number of people to share
    fin >> temp_int >> temp_int2;
    // receiver
    for (i = 0; i < temp_int2; i++)
    {
      fin >> temp_str2;
      players_account[temp_str2] += temp_int / temp_int2;
    }
    players_account[temp_str] -= temp_int;
    if (0 != temp_int2)
      players_account[temp_str] += temp_int % temp_int2;
  }

  // output
  for (i = 0; i < sizeof(players_name) / sizeof(players_name[0]); i++)
  {
    fout << players_name[i] << ' ' << players_account[players_name[i]] << endl;
  }

  return 0;
}
