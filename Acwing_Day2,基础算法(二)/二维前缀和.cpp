/*
题目：二维区域和检索
给定一个 n×n 的矩阵 a[N][N]，要求计算给定区域内所有元素的和。
输入格式：
第一行包含三个整数 n,m,p，分别表示矩阵大小、矩阵元素个数和询问次数
接下来 n 行，每行包含 n 个整数，表示矩阵元素
接下来 p 行，每行包含四个整数 x1,y1,x2,y2，表示询问区域的左上角和右下角坐标

输出格式：
对于每个询问，输出一个整数表示给定矩阵区域的元素和
*/

/* 
解题思路：二维前缀和 + 容斥原理
1. 二维前缀和的定义：
   s[i][j] 表示左上角为(1,1)、右下角为(i,j)的矩阵元素和
   
2. 二维前缀和的递推公式：
   s[i][j] = s[i-1][j] + s[i][j-1] - s[i-1][j-1] + a[i][j]
   解释：防止重复计算，需要减去重叠部分s[i-1][j-1]
   
3. 利用容斥原理求子矩阵的和：
   以(x1,y1)为左上角，(x2,y2)为右下角的子矩阵和
   = s[x2][y2] - s[x2][y1-1] - s[x1-1][y2] + s[x1-1][y1-1]
   解释：
   - s[x2][y2]：大矩阵的和
   - 减去左边多余的 s[x2][y1-1]
   - 减去上边多余的 s[x1-1][y2]
   - 加回重复减去的左上角 s[x1-1][y1-1]
*/
#include <iostream>
using namespace std;
const int N = 1000;

int a[N][N] , s[N][N];

int main()
{
    int n,m,p;
    cin >> n >> m >> p;
    for(int i = 1 ; i <= n ; i++)
        for(int j = 1 ; j <= n ; j++) cin >> a[i][j];
    for(int i = 1 ; i <= n ; i++)
        for(int j = 1 ; j <= n ; j++) s[i][j] = s[i-1][j] + s[i][j-1] + a[i][j] - s[i-1][j-1];
    while(p--)
        {
            int x1 , x2 , y1 , y2;
            cin >> x1 >> y1 >> x2 >> y2;
            cout<< s[x2][y2] - s[x2][y1] - s[x1][y2] + s[x1][y1] <<endl ;           
        }
}