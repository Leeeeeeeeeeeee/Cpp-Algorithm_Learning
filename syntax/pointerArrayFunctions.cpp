#include <iostream>
using namespace std;

void swap(int sc[]){
  //这里int sc[]是语法糖,实际上int *sc ,可判断sc==mc,如果int sc[]，则sc!=mc
  int t = sc[0];
  sc[0] = sc[1];
  sc[1] = t;

  cout << "In swap(): (sc[0],sc[1])=("<< sc[0] << "," << sc[1] <<")" << endl;
  cout << "In swap(): size(sc) = " << sizeof(sc) << endl;//这里为4因为sc是数组指针
}

int main(){
  int a=1,b=2;
  int mc[]={1,2};

  cout << "[Before swap] In main(): (mc[0],mc[1])=("<< mc[0] << "," << mc[1] <<")" << endl;
  cout << "[Before swap] In main(): size(mc) = " << sizeof(mc) << endl;//这里为8因为mc是数组

  swap(mc);

  cout << "[After swap] In main(): (mc[0],mc[1])=("<< mc[0] << "," << mc[1] <<")" << endl;
  cout << "[After swap] In main(): size(mc) = " << sizeof(mc) << endl;//这里为8因为mc是数组

  //主函数的mc[]和swap的sc[]并不是同一个，swap中的sc[]属于swap的局部变量
  //main中的mc代表&mc[0],swap中的c也指向&mc[0],故可以改变主函数中mc[]的值

  return 0;

}
