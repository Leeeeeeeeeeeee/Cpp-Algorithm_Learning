#include "addFunc.cpp"
#include <iostream>
using namespace std;
int main(){
  short a_s=1,b_s=2;
  int a_i=1,b_i=2;
  long a_l=1,b_l=2;
  float a_f=1,b_f=2;
  double a_d=1,b_d=2;
  char a_c=1,b_c=2;

  //typeid是一个运算符，用于获取一个表达式的类型信息
  cout << addFunc(a_s,b_s) << typeid(addFunc(a_s,b_s)).name() << endl;
  cout << addFunc(a_i,b_i) << typeid(addFunc(a_i,b_i)).name() << endl;
  cout << addFunc(a_l,b_l) << typeid(addFunc(a_l,b_l)).name() << endl;
  cout << addFunc(a_f,b_f) << typeid(addFunc(a_f,b_f)).name() << endl;
  cout << addFunc(a_d,b_d) << typeid(addFunc(a_d,b_d)).name() << endl;
  //ASCII码为3的字符是控制字符，表示结束文本符（ETX，End of Text）
  cout << addFunc(a_c,b_c) << typeid(addFunc(a_c,b_c)).name() << endl;

}
