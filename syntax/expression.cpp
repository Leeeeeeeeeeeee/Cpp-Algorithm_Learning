#include <iostream>
using namespace std;
/**
 * 运算符及优先级
*/
int main(){
  int x=1;
  int y=2;

  cout << (x=y) << endl;//2
  cout << (x==y) << endl;//1
  cout << ('a'==97) << endl;//1
  //++ 操作符是一元操作符，它用于将变量的值加 1。它的优先级比 + 操作符高，因此 x++ 会先被执行，然后再执行 +y。
  cout << "a = " << x+++y << endl;//a = 4 //x已经被赋值为2 2+2=4

  return 0;
}
