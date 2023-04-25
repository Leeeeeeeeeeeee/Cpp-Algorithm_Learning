#include <iostream>
using namespace std;
/**
 * 位计算方法
*/
int main(){
  int a=25,b=18,m,n,i,j,k;
  //按位与 --> 1&1=1 1&0=0 0&1=0 0&0=0
  m=a&b;  cout << "m=" << m << endl;
  //按位或 --> 1|1=1 1|0=1 0|1=1 0|0=0
  n=a|b;  cout << "n=" << n << endl;
  //按位异或 --> 1^1=0 1^0=1 0^1=1 0^0=0
  i=a^b;  cout << "i=" << i << endl;
  //乘以2
  j=a<<1; cout << "j=" << j << endl;
  //除以2，注意因为这里都是整型，会去掉小数位，所以得到12
  k=a>>1; cout << "k=" << k << endl;
  return 0;
}
