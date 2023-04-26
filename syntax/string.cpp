#include <string>
#include <iostream>
using namespace std;

int main()
{
  // 在 C++ 中，对于 char 类型的数组，使用 == 运算符进行比较时，
  // 实际上比较的是两个数组的地址，而不是它们存储的字符串内容。
  // false
  char a[] = "jinan";
  char b[] = "jinan";

  // 如果需要比较两个字符串的内容是否相同，可以使用 C++ 标准库中的 std::string 类型，
  // 并使用其提供的 == 运算符进行比较。
  // true
  // string a = "jinan";
  // string b = "jinan";
  if (a == b)
  {
    cout << "true" << endl;
  }
  else
  {
    cout << "false" << endl;
  }
  return 0;
}
