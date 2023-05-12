/*
输入一个字符串（C语言的字符数组形式），提取其中的数字字符，将每个连续的数字串单独转换成整数并且相加，输出相加后的结果，要求：使用指针实现。

例如：输入tre89a533uert ier2567jr4p

输出3193（89+533+2567+4）
*/
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int myatoi(char *str, int length)
{
  int result = 0;
  for (int i = 0; i < length; i++)
    result = result * 10 + (str[i] - '0');
  return result;
}

bool isTempEmpty(char temp[10])
{
  for (int i = 0; i < 10; i++)
  {
    if (temp[i] != 0)
    {
      return false;
    }
  }
  return true;
}
int main()
{
  char str_input[100];
  int i = 0, j = 0;
  char str_temp[10];
  int sum = 0;
  memset(str_input, 0, sizeof(str_input));
  memset(str_temp, 0, sizeof(str_temp));

  cout << "最多输入100个字符，每个以空格分隔的字符最长10位：" << endl;
  scanf("%[^\n]", &str_input);

  cout << "您输入的字符：" << str_input << " 开始找数字..." << endl;
  cout << "找到了数字：";

  while ((str_input[i] != '\0'))
  {
    cout << i << endl;
    // 来到了数字阶段
    if (*(str_input + i) >= '0' && *(str_input + i) <= '9')
    {
      cout << "number" << endl;
      str_temp[j] = str_input[i];
      j++;
    }
    // 来到了字母阶段
    else
    {
      cout << "letter" << endl;
      if (isTempEmpty(str_temp))
      {
        i++;
        continue;
      }
      cout << str_temp << " ";
      // cout << "myatoi:" << myatoi(str_temp,j) << endl;
      sum = sum + myatoi(str_temp, j);
      // cout << sum << endl;
      memset(str_temp, 0, sizeof(str_temp));
      j = 0;
    }
    i++;
  };

  // 最后还得再检查一下，不然会有最后一项不是字母导致没有加到总数里的情况
  if (!isTempEmpty(str_temp))
  {
    cout << str_temp << " ";
    // cout << "myatoi:" << myatoi(str_temp,j) << endl;
    sum = sum + myatoi(str_temp, j);
    // cout << sum << endl;
    memset(str_temp, 0, sizeof(str_temp));
    j = 0;
  }
  cout << " 总数: " << sum;
    
  return 0;
}
