/*
ID: qq267181
TASK: transform
LANG: C++
*/

#include <fstream>
#include <iostream>
#include <vector>

using namespace std;
using Matrix = std::vector<std::vector<bool>>;

// 旋转90
Matrix rotateMatrix(Matrix matrix_o)
{
  int size = matrix_o.size();
  if (1 == size)
  {
    return matrix_o;
  }
  Matrix martix_r = matrix_o;
  for (int i = 0; i < size; ++i)
  {
    for (int j = 0; j < size; ++j)
    {
      matrix_o[i][j] = martix_r[size - j - 1][i];
    }
  }
  return matrix_o;
}

// // 旋转180
// Matrix rotateMatrix180(Matrix matrix_o){
//   int size = matrix_o.size();
//   if(1==size){
//     return matrix_o;
//   }
//   Matrix martix_r = matrix_o;
//   for (int i = 0; i < size; ++i) {
//     for (int j = 0; j < size; ++j) {
//         matrix_o[i][j] = martix_r[size-i-1][size-j-1];
//     }
//   }
//   return matrix_o;
// }

// // 旋转270
// Matrix rotateMatrix270(Matrix matrix_o){
//   int size = matrix_o.size();
//   if(1==size){
//     return matrix_o;
//   }
//   Matrix martix_r = matrix_o;
//   for (int i = 0; i < size; ++i) {
//     for (int j = 0; j < size; ++j) {
//         matrix_o[i][j] = martix_r[j][size-i-1];
//     }
//   }
//   return matrix_o;
// }

// x轴镜像
Matrix reflectMatrix(Matrix matrix_o)
{
  int size = matrix_o.size();
  if (1 == size)
  {
    return matrix_o;
  }
  Matrix martix_r = matrix_o;
  for (int i = 0; i < size; ++i)
  {
    for (int j = 0; j < size; ++j)
    {
      matrix_o[i][j] = martix_r[i][size - j - 1];
    }
  }
  return matrix_o;
}

// 判断两个矩阵是否相等
bool areMatricesEqual(const Matrix &matrix1, const Matrix &matrix2)
{
  if (matrix1.size() != matrix2.size() || matrix1[0].size() != matrix2[0].size())
  {
    return false;
  }
  for (int i = 0; i < matrix1.size(); ++i)
  {
    for (int j = 0; j < matrix1[0].size(); ++j)
    {
      if (matrix1[i][j] != matrix2[i][j])
      {
        return false;
      }
    }
  }
  return true;
}

// // 打印矩阵
// void printMatrix(const Matrix &matrix)
// {
//   for (int i = 0; i < matrix.size(); ++i)
//   {
//     for (int j = 0; j < matrix[0].size(); ++j)
//     {
//       cout << matrix[i][j];
//     }
//     cout << endl;
//   }
//   cout << endl;
// }

int workMatrix(Matrix matrix_o, Matrix matrix_t)
{
  int step = 0;
  bool areMatricsEqual = false;
  while (!areMatricsEqual && step < 4)
  {
    step++;
    matrix_o = rotateMatrix(matrix_o);
    areMatricsEqual = areMatricesEqual(matrix_o,matrix_t);
    if(areMatricsEqual){
      return step; //1-3 rotation
    }
  }
  matrix_o = reflectMatrix(matrix_o);
  areMatricsEqual = areMatricesEqual(matrix_o,matrix_t);
  if(areMatricsEqual){
    return 4; //reflection
  }
  while (!areMatricesEqual(matrix_o, matrix_t)&&step < 8)
  {
    step++;
    matrix_o = rotateMatrix(matrix_o);
    areMatricsEqual = areMatricesEqual(matrix_o,matrix_t);
    if(areMatricsEqual){
      return 5; //combination
    }
  }
  matrix_o = reflectMatrix(matrix_o);
  areMatricsEqual = areMatricesEqual(matrix_o,matrix_t);
  if(areMatricsEqual){
    return 6; //no change
  }
  return 7; //invalid
}

int main()
{
  // init
  int size;
  char temp;
  int step = 0;
  Matrix matrix_o;
  Matrix matrix_t;
  // input
  ifstream fin("transform.in");
  fin >> size;
  matrix_o.resize(size, vector<bool>(size));
  matrix_t.resize(size, vector<bool>(size));
  for (int i = 0; i < size; i++)
  {
    for (int j = 0; j < size; j++)
    {
      fin >> temp;
      matrix_o[i][j] = '-' == temp;
    }
  }
  for (int i = 0; i < size; i++)
  {
    for (int j = 0; j < size; j++)
    {
      fin >> temp;
      matrix_t[i][j] = '-' == temp;
    }
  }
  int pattern = workMatrix(matrix_o,matrix_t);
  ofstream fout("transform.out");
  fout << pattern <<endl ;
  return 0;
}
