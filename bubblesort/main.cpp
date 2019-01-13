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

int main(int argc, char *argv[])
{
    const int LEN = 100;

__TIC__(ALLTIME)

    int arr[LEN] = {0};
    srand(unsigned(time(0)));
    for(int i = 0; i < LEN; i++)
    {
        arr[i] = rand() % 100 + 1;
    }

    cout << "Before sort:" << endl;
    print_array(arr, LEN);

__TIC__(BUBBLESORT)
    bubble_sort(arr, LEN);
__TOC__(BUBBLESORT)

    cout << "After sort:" << endl;
    print_array(arr, LEN);

__TOC__(ALLTIME)

    return 0;


}

