#include <fstream>
#include <iostream>
#include <cstring>
#include <map>

using namespace std;

// int check(char name[4]){
//   int i=0;
//   string dict_name;
//   ifstream dict("dict.txt");
//   dict >> dict_name;
//   for(i=0;i<4;i++){
//     if(name[i]!=dict_name[i]) return 0;
//   }
//   return 1;
// }

int main()
{
  // init
  std::map<char, std::array<char, 3>> phoneMap;
  phoneMap['2'] = {'A','B','C'};
  phoneMap['3'] = {'D','E','F'};
  phoneMap['4'] = {'G','H','I'};
  phoneMap['5'] = {'J','K','L'};
  phoneMap['6'] = {'M','N','O'};
  phoneMap['7'] = {'P','R','S'};
  phoneMap['8'] = {'T','U','V'};
  phoneMap['9'] = {'W','X','Y'};
  char namenum[5] = {' ', ' ', ' ', ' ', '\0'};
  char name[5] = {' ', ' ', ' ', ' ', '\0'};
  // input
  ifstream fin("namenum.in");
  fin >> namenum;
  ifstream fin("dict.txt");
  for(int i = 0;i<4;i++){
    namenum[i]
  }
  // compute
  // 可能性：3x3x3x3=81
  //  for(i=0;i<3;i++){
  //    for(j=0;j<3;j++){
  //      for(m=0;m<3;m++){
  //        for(n=0;n<3;n++){
  //          name[0]=letter[temp[0]-2][i];
  //          name[1]=letter[temp[1]-2][j];
  //          name[2]=letter[temp[2]-2][m];
  //          name[3]=letter[temp[3]-2][n];
  //          result = check(name);
  //          if(result==1) break;
  //        }
  //        if(result==1) break;
  //      }
  //      if(result==1) break;
  //    }
  //    if(result==1) break;
  //  }
  //  //output
  //  ofstream fout("namenum.out");
  //  if(result==0){
  //    fout << "no name" << endl;
  //  }else{
  //    fout << name[0] << name[1] << name[2] << name[3] << endl;
  //  }
  //  return 0;
}
