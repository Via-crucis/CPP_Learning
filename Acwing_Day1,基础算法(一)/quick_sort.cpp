#include <iostream>
using namespace std;

/**
 * 快速排序算法的核心函数
 * @param a: 待排序的整型数组
 * @param l: 当前处理区间的左边界
 * @param r: 当前处理区间的右边界
 * 
 * 算法思想：
 * 1. 选择基准值（pivot）将数组分成两部分
 * 2. 通过双指针将小于基准值的元素放在左边，大于基准值的元素放在右边
 * 3. 递归处理左右两个子区间
 */
void quick_sort(int *a, int l, int r)
{
    // 递归终止条件：区间长度为1或无效区间
    if(l >= r) return;

    // 选择中间位置的元素作为基准值（pivot）
    int x = a[(l+r)/2];//如果一直取端点，时间复杂度很高。
    // i指针从左边界开始向右移动，j指针从右边界开始向左移动
    int i = l-1;
    int j = r+1;
    
    // 主循环：将数组按基准值分区
    while(i < j)
    {
        // 找到左边第一个大于等于基准值的元素
        do i++; while(a[i] < x);
        // 找到右边第一个小于等于基准值的元素
        do j--; while(a[j] > x);
        
        // 如果两个指针未相遇，交换找到的两个元素
        if(i < j) swap(a[i], a[j]);
    }
    
    // 递归处理左右两个子区间
    quick_sort(a, l, i-1);  // 处理左半部分
    quick_sort(a, i, r);    // 处理右半部分
}

int main(){
    // 读入数组大小
    int n;
    cout << "请输入数组大小: ";
    cin >> n;
    
    // 动态分配数组空间
    int *a = new int[n];
    
    // 读入数组元素
    cout << "请输入" << n << "个整数，以空格分隔：" << endl;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    // 打印原始数组
    cout << "原始数组: ";
    for(int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    
    // 调用快速排序函数
    quick_sort(a, 0, n-1);
    
    // 打印排序后的数组
    cout << "排序后数组: ";
    for(int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    
    // 释放动态分配的内存
    delete[] a;
    
    return 0;
}