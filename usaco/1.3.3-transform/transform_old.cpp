/*
ID: qq267181
TASK: transform
LANG: C++
*/

#include <fstream>
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>

using namespace std;

struct Block
{
  int x;
  int y;
  bool isBlack = true;
};

Block *getMatrix(Block *p_block, int size)
{
  int k = 0;
  for (int i = 0; i < size; i++)
  {
    for (int j = 0; j < size; j++)
    {
      p_block[k].x = j;
      p_block[k].y = i;
      k++;
    }
  }
  return &p_block[0];
}

Block *getCenterMatrix(Block *p_block, int size)
{
  if (size < 3)
  {
    for (int i = 0; i < size * size; i++)
    {
      p_block[i].x = (p_block[i].x * 2 - size / 2);
      p_block[i].y = (p_block[i].y * 2 - size / 2);
    }
    return &p_block[0];
  }
  for (int i = 0; i < size * size; i++)
  {
    p_block[i].x = (p_block[i].x - size / 2);
    p_block[i].y = (p_block[i].y - size / 2);
  }
  return &p_block[0];
}

Block *reflectMatrix(Block *p_block,int size){
  for (int i = 0; i < size * size; i++)
  {
    p_block[i].x = p_block[i].x * -1;
  }
  return &p_block[0];
}

void printMatrix(Block *p_block, int size)
{
  for (int i = 0; i < size * size; ++i)
  {
    cout << "Block " << i << " : x > " << p_block[i].x << ", y > " << p_block[i].y << ", isBlack > " << (p_block[i].isBlack ? "true" : "false") << endl;
  }
}

bool isMatrixEqual(Block *p_block,int size){

}

int main()
{
  // // Matrix 1
  // cout << "Matrix 1 " << endl;
  // Block blocks_1[1];
  // getMatrix(blocks_1, 1);
  // printMatrix(blocks_1, 1);
  // getCenterMatrix(blocks_1, 1);
  // printMatrix(blocks_1, 1);
  // // Matrix 2
  // cout << "Matrix 2 " << endl;
  // Block blocks_2[4];
  // getMatrix(blocks_2, 2);
  // printMatrix(blocks_2, 2);
  // getCenterMatrix(blocks_2, 2);
  // printMatrix(blocks_2, 2);
  // // Matrix 3
  // cout << "Matrix 3 " << endl;
  // Block blocks_3[9];
  // getMatrix(blocks_3, 3);
  // printMatrix(blocks_3, 3);
  // getCenterMatrix(blocks_3, 3);
  // printMatrix(blocks_3, 3);
  // // Matrix 4
  // cout << "Matrix 4 " << endl;
  // Block blocks_4[16];
  // getMatrix(blocks_4, 4);
  // printMatrix(blocks_4, 4);
  // getCenterMatrix(blocks_4, 4);
  // printMatrix(blocks_4, 4);
  return 0;
}
