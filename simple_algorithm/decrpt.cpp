

#include <iostream>
#include <cstring>
using namespace std;
/**
 * 程序目标：输入a-z或者A-Z，a输出z A输出Z b输出y，以此类推
 * 可以输入20个字母
*/
int main(){
  int i=0;
  //memset()方法用于将一块内存区域的值设置为指定的值
  char letters[20];
  memset(letters,0,sizeof(char)*20);
  char letters_new[20];
  memset(letters_new,0,sizeof(char)*20);
  //input
  cin >> letters;
  //compute
for(i=0;i<20;i++){
  if(letters[i]>='A' && letters[i]<='Z'){
    //letters[i]-'A'使得A-Z分别编码为0-25
    //25-(...) 使得A-Z调转编码
    //(...)+'A'使得0-25重新转换为字符的ASCII值
    letters_new[i]=(25-(letters[i]-'A'))+'A';
  } else if(letters[i]>='a' && letters[i]<='z'){
    letters_new[i]=(25-(letters[i]-'a'))+'a';
  }
}
cout << letters_new << endl;
  //output
  return 0;
}
