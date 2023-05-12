// 编写一个函数，输入两个3x3的二维数组（当做矩阵），求出矩阵相乘的结果并返回，要求：使用指针实现。
// 矩阵相乘：C(i,j) = ΣA(i,k) × B(k,j) C中第i行第j列代表A的第i行与B的第j列每个元素两两相称累加后的结果
#include <iostream>
#define MATRIX_SIZE 3
using namespace std;
void matrixAdd(int (*x)[3], int (*y)[3], int (*z)[3])
{

  for (int i = 0; i < MATRIX_SIZE; i++)
  {
    for (int j = 0; j < MATRIX_SIZE; j++)
    {
      z[i][j] = 0;
      for (int k = 0; k < MATRIX_SIZE; k++)
      {
        z[i][j] += x[i][k] * y[k][j];
      }
    }
  }
}
int main()
{
  int i = 0, j = 0; // 定义行和列
  // 定义三个矩阵，两个输入，一个结果
  int x[MATRIX_SIZE][MATRIX_SIZE];
  int y[MATRIX_SIZE][MATRIX_SIZE];
  int z[MATRIX_SIZE][MATRIX_SIZE];

  cout << "请输入第一个矩阵的值:" << endl;
  for (i = 0; i < MATRIX_SIZE; i++)
  {
    for (j = 0; j < MATRIX_SIZE; j++)
    {
      cin >> x[i][j];
    }
  }

  cout << "请输入第二个矩阵的值:" << endl;
  for (i = 0; i < MATRIX_SIZE; i++)
  {
    for (j = 0; j < MATRIX_SIZE; j++)
    {
      cin >> y[i][j];
    }
  }

  // 矩阵相乘
  matrixAdd(x, y, z);
  cout << "矩阵相乘的结果:" << endl;
  for (i = 0; i < MATRIX_SIZE; i++)
  {
    for (j = 0; j < MATRIX_SIZE; j++)
    {
      cout << z[i][j] << ' ';
    }
    cout << endl;
  }
  return 0;
}
