#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

void showVector(std::vector<int> &vec)
{
  for (vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
  {
    cout << *it << "  ";
  }
  cout << endl;
}

int main()
{
  vector<int> a;
  int b_i[7] = {1, 2, 3, 4, 5, 6, 7};
  vector<int> b(b_i, b_i + sizeof(b_i) / sizeof(int));

  /**********定义部分***********/
  {
    // 定义具有10个整型元素的向量（尖括号为元素类型名，它可以是任何合法的数据类型），不具有初值，其值不确定
    vector<int> a(10);

    // 定义具有10个整型元素的向量，且给出的每个元素初值为1
    vector<int> a_1(10, 1);

    // 用向量b给向量a赋值，a的值完全等价于b的值
    int b[7] = {1, 2, 3, 4, 5, 6, 7};
    vector<int> a_b(b, b + sizeof(b) / sizeof(int));

    // 将向量b中从0-2（共三个）的元素赋值给a，a的类型为int型
    vector<int> a_b3(a_b.begin(), a_b.begin() + 3);

    // 从数组中获得初值
    vector<int> a_fb(b, b + 7);
  }

  /**********赋值部分***********/

  {
    // a含有4个值为2的元素(从头赋值)
    a.assign(4, 2);
    showVector(a);

    // b为向量，将b的0-2个元素赋值给向量a
    a.assign(b.begin(), b.begin() + 3);
    showVector(a);

    // 返回a的最后一个元素
    int t = a.back();
    cout << t << endl;

    // 返回a的第一个元素
    t = a.front();
    cout << t << endl;

    // 返回a的第i元素,当且仅当a存在
    int i = 2;
    t = a[i];
    cout << t << endl;

    // 清空a中的元素
    a.clear();
    showVector(a);

    // 判断a是否为空，空则返回true，非空则返回false
    bool f = a.empty();
    cout << f << endl;

    // 删除a向量的最后一个元素
    a.assign(b.begin(), b.begin() + 3);
    a.pop_back();
    showVector(a);

    // 删除a中第一个（从第0个算起）到第二个元素，也就是说删除的元素从a.begin()+1算起（包括它）一直到a.begin()+3（不包括它）结束
    a.assign(b.begin(), b.begin() + 4);
    a.erase(a.begin() + 1, a.begin() + 3);
    showVector(a);

    // 在a的最后一个向量后插入一个元素，其值为5
    a.push_back(5);
    showVector(a);

    // 在a的第一个元素（从第0个算起）位置插入数值5,
    a.insert(a.begin() + 1, 5);
    showVector(a);

    // 在a的第一个元素（从第0个算起）位置插入3个数，其值都为5
    a.insert(a.begin() + 1, 3, 5);
    showVector(a);

    // b为数组，在a的第一个元素（从第0个元素算起）的位置插入数组b_i的第三个元素到第5个元素（不包括b_i+6）
    a.insert(a.begin() + 1, b_i + 3, b_i + 6);
    showVector(a);

    // 返回a中元素的个数
    i = a.size();
    cout << i << endl;

    // 返回a在内存中总共可以容纳的元素个数
    i = a.capacity();
    cout << i << endl;

    // 将a的现有元素个数调整至12个，多则删，少则补，其值为0
    a.resize(12);
    showVector(a);

    // 将a的现有元素个数调整至14个，多则删，少则补，其值为2
    a.resize(14, 2);
    showVector(a);

    // 将a的容量扩充至100，
    a.reserve(100);
    i = a.capacity();
    cout << i << endl;

    // b为向量，将a中的元素和b中的元素整体交换
    a.swap(b);
    showVector(b);
    // b为向量，向量的比较操作还有 != >= > <= <
    f = a == b;
    cout << f << endl;
  }

  /***********几种常见赋值方式的整理*************/
  // 1.向向量a中添加元素
  {
    vector<int> a;
    for (int i = 0; i < 10; ++i)
    {
      a.push_back(i);
    }
    showVector(a);
  }
  // 2.从数组中选择元素向向量中添加
  {
    int a[6] = {1, 2, 3, 4, 5, 6};
    vector<int> b;
    for (int i = 0; i <= 4; ++i)
    {
      b.push_back(a[i]);
    }
    showVector(b);
  }
  // 3.从现有向量中选择元素向向量中添加
  {
    int a[6] = {1, 2, 3, 4, 5, 6};
    vector<int> b;
    vector<int> c(a, a + 4);
    for (vector<int>::iterator it = c.begin(); it < c.end(); ++it)
    {
      b.push_back(*it);
    }
    showVector(b);
  }
  // 4.从文件中读取元素向向量中添加
  {
    ifstream in("vector_data.txt");
    if (in.is_open())
    {
      vector<int> a;
      for (int i; in >> i;)
      {
        a.push_back(i);
      }
      in.close();
      showVector(a); // 按空格分割，读入了12345、1、2、3
    }
  }
  // 5.常见错误赋值方式
  //  vector<int>a;
  //  for(int i=0;i<10;++i){a[i]=i;}//下标只能用来获取已经存在的元素

  /***********几种常见获取方式的整理*************/
  // 1.通过下标方式获取
  {
    int a[6] = {1, 2, 3, 4, 5, 6};
    vector<int> b(a, a + 4);
    for (int i = 0; i <= b.size() - 1; ++i)
    {
      cout << b[i] << " ";
    }
    cout << endl;
  }
  // 2.通过迭代器方式读取
  {
    int a[6] = {1, 2, 3, 4, 5, 6};
    vector<int> b(a, a + 4);
    for (vector<int>::iterator it = b.begin(); it != b.end(); it++)
    {
      cout << *it << "  ";
    }
    cout << endl;
  }

  /***********几种常用算法的整理*************/
  {
    a.assign(10, 0);
    a.insert(a.begin() + 1, b_i + 3, b_i + 6);

    // 对a中的从a.begin()（包括它）到a.end()（不包括它）的元素进行从小到大排列
    sort(a.begin(), a.end());
    showVector(a);

    // 对a中的从a.begin()（包括它）到a.end()（不包括它）的元素倒置，但不排列，如a中元素为1,3,2,4,倒置后为4,2,3,1
    reverse(a.begin(), a.end());
    showVector(a);
    // 把a中的从a.begin()（包括它）到a.end()（不包括它）的元素复制到b中，从b.begin()+1的位置（包括它）开始复制，覆盖掉原有元素
    copy(a.begin(), a.end(), b.begin() + 1);
    showVector(b);
    // 在a中的从a.begin()（包括它）到a.end()（不包括它）的元素中查找4，若存在返回其在向量中的位置
    int value = 4;
    auto i = find(a.begin(), a.end(), value);
    showVector(a);
    if (i != a.end())
    {
      cout << i - a.begin() << endl;//输出的是位置下标(从0开始)
    }
  }

  return 0;
}
