/*
ID: qq267181
TASK: friday
LANG: C++
*/

/*怎么计算？
  从头到尾的检索
  设置一个变量为当前是一个星期的哪个日子
  设置一个变量为当前是当前月的几号，为13号时计数一次
*/

#include <fstream>
using namespace std;

int main()
{
  int i, j;                                     // 循环变量
  int year_amount;                              // 计算的年数为1900-(1900+n-1)
  int weekday_count[7] = {0, 0, 0, 0, 0, 0, 0}; // 存储每个星期是13号的次数
  int year_this;                                // 当前的年份
  int days_month;                               // 当前月的天数
  int days_count = 0;                           // 从1900年1月1号起累计的天数，用于取余获得星期代号

  ifstream fin("friday.in");
  ofstream fout("friday.out");

  // input
  fin >> year_amount;

  // year loop
  for (i = 0; i < year_amount; i++)
  {
    year_this = 1900 + i;
    // month loop
    for (j = 1; j < 13; j++)
    {
      // 优化点：每个月的天数用数组会更快days_of_months = [31,28,31,30,31,30,31,31,30,31,30,31]
      if (4 == j || 6 == j || 9 == j || 11 == j)
      {
        days_month = 30;
      }
      else if (2 == j)
      {
        // leap year
        if (0 == year_this % 400 || (0 == year_this % 4 && 0 != year_this % 100))
        {
          days_month = 29;
        }
        else
        {
          days_month = 28;
        }
      }
      else
      {
        days_month = 31;
      }
      days_count += 12;
      weekday_count[days_count % 7]++;
      days_count += days_month - 12;
    }
  }

  // output
  for (i = 5; i < 11; i++)
    fout << weekday_count[i % 7] << ' ';
  fout << weekday_count[4] << endl;

  return 0;
}
