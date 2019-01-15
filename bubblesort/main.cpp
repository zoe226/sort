#include <iostream>
#include <algorithm>
#include <chrono>

using namespace std;
using Clock = std::chrono::steady_clock;

#define __TIC__(tag) \
    auto __##tag##_start_time = Clock::now();

#define __TOC__(tag) \
    auto __##tag##_end_time = Clock::now(); \
cout << #tag << " : " << \
std::chrono::duration_cast<std::chrono::microseconds>( \
        __##tag##_end_time - __##tag##_start_time).count() << "us" << endl;

void print_array(int arr[], int len)
{
    for(int i = 0; i < len; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void bubble_sort(int arr[], int len)
{
    for(int i = len - 1; i > 0; i--)
    {
        int flag = 0;
        for(int j = 0; j < i; j++)
        {
            if(arr[j] > arr[j+1])
            {
                swap(arr[j], arr[j+1]);
                flag = 1;
            }
        }
        if(flag == 0)
            return;
    }
}

void quicksort(int arr[], int leftend, int rightend)
{
    if(leftend >= rightend) return;
    int leftcursor = leftend;   //从左到右移动的索引
    int rightcursor = rightend + 1; //从右到左移动的索引
    int pivot = arr[leftend];
    // 将位于左侧不小于支点的元素和位于右侧不大于支点的元素交换
    while(true)
    {
        do
        {//寻找左侧不小于支点的元素
            leftcursor ++;
        }while(arr[leftcursor] < pivot);

        do
        {//寻找右侧不大于支点的元素
            rightcursor --;
        }while(arr[rightcursor] > pivot);

        if(leftcursor >= rightcursor) break; //没有找到交换的元素对
        swap(arr[leftcursor], arr[rightcursor]);
    }

    //放置支点
    arr[leftend] = arr[rightcursor];
    arr[rightcursor] = pivot;

    for(int i = leftend; i <= rightend; i++)
        cout << "arr[" << i << "]=" << arr[i] << "   ";
    cout << endl;
    quicksort(arr, leftend, rightcursor - 1);  //对左段的数段排序
    quicksort(arr, rightcursor + 1, rightend); //对右段的数段排序
}


void quick_sort(int arr[], int len)
{
    if(len <= 1) return;
    int max = arr[0];
    int indexofmax = 0;
    for(int i = 1; i < len; i++)
    {
        if(arr[i] > max)
        {
            max = arr[i];
            indexofmax = i;
        }
    }
    cout << "indexofmax = " << indexofmax << endl;
    if(indexofmax < len - 1)
        swap(arr[len - 1], arr[indexofmax]);
    print_array(arr, len);
    quicksort(arr, 0, len - 2);
}

int main(int argc, char *argv[])
{
    const int LEN = 8;

__TIC__(ALLTIME)

    int arr[LEN] = {0};
    int arr2[LEN] = {4,2,3,7,1,5,6,8};
    int arr1[LEN] = {0};
    srand(unsigned(time(0)));
    for(int i = 0; i < LEN; i++)
    {
        arr[i] = rand() % 100 + 1;
        arr1[i] = rand() % 100 + 1;
    }

    cout << "Before sort:" << endl;
    print_array(arr, LEN);

__TIC__(BUBBLESORT)
    bubble_sort(arr, LEN);
__TOC__(BUBBLESORT)

    cout << "After sort:" << endl;
    print_array(arr, LEN);

    cout << endl;

    cout << "Before sort:" << endl;
    print_array(arr2, LEN);

__TIC__(QUICKSORT)
    quick_sort(arr2, LEN);
__TOC__(QUICKSORT)

    cout << "After sort:" << endl;
    print_array(arr2, LEN);

__TOC__(ALLTIME)

    return 0;


}

