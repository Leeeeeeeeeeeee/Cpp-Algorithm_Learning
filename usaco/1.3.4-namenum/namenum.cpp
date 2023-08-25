/*
ID: qq267181
TASK: namenum
LANG: C++
*/

#include <cstring>
#include <forward_list>
#include <fstream>
#include <iostream>
#include <map>

using namespace std;

int main()
{
  // init
  map<char, array<char, 3>> phoneMap;
  forward_list<string> dictList;
  forward_list<string> outList;
  phoneMap['2'] = {'A', 'B', 'C'};
  phoneMap['3'] = {'D', 'E', 'F'};
  phoneMap['4'] = {'G', 'H', 'I'};
  phoneMap['5'] = {'J', 'K', 'L'};
  phoneMap['6'] = {'M', 'N', 'O'};
  phoneMap['7'] = {'P', 'R', 'S'};
  phoneMap['8'] = {'T', 'U', 'V'};
  phoneMap['9'] = {'W', 'X', 'Y'};
  char namenum[5] = {' ', ' ', ' ', ' ', '\0'};
  char at;
  string dict;
  // input
  ifstream fin1("namenum.in");
  fin1 >> namenum;
  ifstream fin2("dict.txt");
  while (fin2 >> dict)
  {
    dictList.push_front(dict);
  };
  ofstream fout("namenum.out");
  auto it = dictList.begin();
  while (it != dictList.end())
  {
    for (int i = 0; i < 4; i++)
    {
      // cout << "OUTTER" << endl;
      for (int a = 0; a < 3; a++)
      {
        // cout << "MIDDLE" << endl;
        at = phoneMap[namenum[i]][a];
        // cout << "at:"<<at << endl;
        auto it_t = it;
        while (it_t != dictList.end())
        {
          // cout << "INNER" << endl;
          // cout << "it_t[i]:"<< (*it_t)[i] << endl;
          if (at == (*it_t)[i])
          {
            // cout << (*it_t)[i] << endl;
            it = it_t;
            // cout << "Inner Break" << endl;
            break;
          }
          it_t++;
        }
        // cout << "NODE" << endl;
        if (at == (*it)[i])
        {
          // cout << "Later Break" << endl;
          break;
        }
      }
      if (at != (*it)[i])
      {
        // cout << "NONE" << endl;
        fout << "NONE" << endl;
        break;
      }
    }
    fout << (*it) << endl;
    it++;
  }
  return 0;
}
