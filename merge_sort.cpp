#include <iostream>
using namespace std;

// 全局变量声明
const int N = 100;          // 数组最大容量（可根据实际需求调整）
int a[N],temp[N];          // a[]存储待排序数组，temp[]用于合并时暂存数据

/*
归并排序的核心函数：
- 采用自顶向下的递归方式
- 先将数组分成两半
- 分别对两半进行排序
- 最后将排好序的两半合并
*/
void merge_sort(int *a, int l,int r)
{

    if(l>=r) return ;
    // Step 1: 递归划分
    merge_sort(a, l, (l+r)/2);         // 递归排序左半部分 [l, mid]
    merge_sort(a, (l+r)/2+1, r);       // 递归排序右半部分 [mid+1, r]

    // Step 2: 合并准备
    int i = l;              // 左半部分起始指针
    int mid = (l+r)/2;      // 中间分割点
    int j = mid+1;          // 右半部分起始指针
    int k = 0;              // 临时数组指针

    // Step 3: 有序合并
    // 比较两个有序序列的元素，按顺序放入临时数组
    for(;i <= mid && j <= r; k++ )
    {
        if(a[i]<a[j])
        temp[k] = a[i++];   // 左边元素更小，存入临时数组
        else
        temp[k] = a[j++];   // 右边元素更小，存入临时数组
    }

    // Step 4: 处理剩余元素
    while(i <= mid) temp[k++] = a[i++];  // 如果左半部分还有剩余，直接追加
    while(j <= r) temp[k++] = a[j++];    // 如果右半部分还有剩余，直接追加

    // Step 5: 回写到原数组
    // 将临时数组中的有序序列复制回原数组对应位置[l,r]
    for(i=l,j=0;i <= r ; i++,j++)
    /*注意，这里i写为l的原因是因为数组a是所有递归同名函数共享的，
    因此不同的递归过程在独立地使用由i索引的，不同的内存块*/
    {
        a[i] = temp[j];
    }

}

int main(){
    // 读入数组大小
    int n;
    cout << "请输入数组大小: ";
    cin >> n;
    
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
    
    // 调用归并排序函数
    // 参数说明：数组a，起始位置0，结束位置n-1
    merge_sort(a, 0, n-1);

    
    // 打印排序后的数组
    cout << "排序后数组: ";
    for(int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    
    // 注意：此处不需要释放内存，因为使用的是静态数组
    // 如果使用动态数组，需要在这里释放内存
    //delete[] a;

    
    return 0;
}