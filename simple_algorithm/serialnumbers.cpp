/**
 * 编写一个函数，输入整数n，判断是否等于某个连续整数序列的和，
 * 若是，则输出所有可能的序列，否则输出“找不到”。
 * 例如：当输入100时，输出
 * 100=9+10+11+12+13+14+15+16
 * 100=18+19+20+21+22
 */
#include <iostream>
using namespace std;
// 创建1-->n-1的一个序列
void creatNumbers(int *seq, int n)
{
  int i = 1;
  for (i = 1; i < n; i++)
  {
    *(seq + i) = i;
  }
}
//判断是否有连续整数序列满足条件
//原理是遍历穷举
void isSerialNumbers(int *seq, int n)
{
  //i用于指向序列的头，j用于指向序列的尾，z用于遍历输出序列
  int i = 0, j = 0, z = 0;
  int sum = 0;
  for (i = 1; i < n; i++)
  {
    sum = 0;
    j = 0;
    //当sum>=n时，没有必要再向后延伸下去
    while (sum < n)
    {
      sum = sum + *(seq + i + j);
      // cout << "sum:" << sum;
      if (sum == n)
      {
        cout << n << ": ";
        for (z = 0; z <= j; z++)
        {
          cout << *(seq + i + z) << " ";
        }
        cout << endl;
      }
      j++;
    }
  }
}
int main()
{
  int n = 0;
  cin >> n;
  int numbers[n-1] = {};
  //创建1-->n-1的一个序列
  creatNumbers(numbers, n-1);
  //判断里面是否有连续整数序列满足条件
  isSerialNumbers(numbers, n);
}
