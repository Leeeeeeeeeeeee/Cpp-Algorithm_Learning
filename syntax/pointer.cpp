#include <iostream>
using namespace std;

int add(int a, int b)
{
  return a + b;
}

int mul(int a, int b)
{
  return a * b;
}

int main()
{

  /********定义int型与int型的指针与指向int型指针的指针,以及它们之前的互相使用********/
  int a = 1;   // 定义int型
  int *p = &a; // 定义指向int型的指针

  cout << &(*p) << endl; // a的地址（64位二进制）
  cout << *(&a) << endl; // a的内容
  cout << endl;

  int *p2 = NULL;
  p2 = p;
  int **p3 = &p2; // 定义指向int型的指针的指针

  cout << p2 << endl;   // p2的内容,即p,即a的地址
  cout << &p2 << endl;  // p2的地址,即p3的内容
  cout << p3 << endl;   // p3的内容,即p2的地址,即p3的内容
  cout << *p3 << endl;  // p3指向的内容,即p2的内容,即p的内容,即a的地址,
  cout << **p3 << endl; // p3指向的内容指向的内容,即a的内容
  cout << endl;

  /***************数组与指针***************/
  int b[] = {1, 2, 3, 4, 5};
  int *p4 = b;
  // int* p4 = &b[0]; //两种不同的定义方式
  cout << b << endl;         // 数组b的首地址
  cout << b[2] << endl;      // 数组b中第三个元素
  cout << *(b + 2) << endl;  // 数据b中第三个元素
  cout << *(++p4) << endl;   // 数组b中第二个元素
  cout << *(p4++) << endl;   // 数组b中第二个元素（p4已经改变了，指向b中第二个元素，++先用后加，所以输出显示数组第二个元素，但是此时p4已经指向b中第三个元素）
  cout << *(p4 - 2) << endl; // 数组b中第一个元素
  cout << endl;

  /*************数组指针与指针数组**************/
  int c[3][2] = {{1, 2}, {3, 4}, {5, 6}};
  int(*p6)[2] = c;                 // 数组指针. 此声明代表p6是个指针,指向一个包含两个int型的数组,c一开始指向{1,2}的位置
  int *p5[3] = {c[0], c[1], c[2]}; // 指针数组. 此声明代表p5是个数组,其中每个元素都是指针
  int **p7 = p5;                   // p5指向c[0]的首个元素的地址,所以是双重指针
  // int** p7 = c;                  // 此声明错误, 二维数组不等于二级指针，二维数组要用数组指针的方式去理解(如上声明p6)
  int *p8 = &c[0][0]; // 此声明因为取址符操作所以为一级指针,顺序便利就可以得到全部的int值
  for (int i = 0; i < 3; ++i)
  {
    for (int j = 0; j < 2; ++j)
    {
      cout << p8[i * 2 + j];
    }
  }
  cout << endl;
  cout << endl;

  /***********函数的指针***********/
  int (*f)(int, int); // 定义的函数输入两个int，返回一个int
  f = add;
  // f = &add;
  cout << f(2, 3) << endl;
  // cout << (*f)(2,3) << endl;
  f = mul;
  cout << f(2, 3) << endl;

  /************注意判断中不要将'=='写错成'='************/
  int x = 1, y = 1;
  int *p9 = &x;
  int *p10 = &y;
  // if(p9=p10) 缺少了一个=，判断的是将p10赋值于p9后p9的值

  return 0;
}
