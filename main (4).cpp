#include <iostream>

int getMax(int arr[], int n)
{
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}

void countSort(int arr[], int n, int exp)
{
    int output[n];
    int i, count[10] = {0};
    for (i = 0; i < n; i++)
        count[ (arr[i]/exp)%10 ]++;
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
    for (i = n - 1; i >= 0; i--)
    {
        output[count[ (arr[i]/exp)%10 ] - 1] = arr[i];
        count[ (arr[i]/exp)%10 ]--;
    }
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}

void RadixSort(int arr[], int n)
{
    int m = getMax(arr, n);
    for (int exp = 1; m/exp > 0; exp *= 10)
        countSort(arr, n, exp);
}

void quickSort(int arr[], int left, int right)
{
    int i = left;
    int j = right;
    int tmp;
    int pivot = arr[(left + right) / 2];

    /* partition */
    while (i <= j)
    {
        while (arr[i] < pivot)
        {
            ++i;
        }
        while (arr[j] > pivot)
        {
            --j;
        }
        if (i <= j)
        {
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
    };
    if (left < j)
    quickSort(arr, left, j);
    if (i < right)
    quickSort(arr, i, right);

}
int main()
{
    std::size_t size = 15;
    int A[size];
    for(std::size_t i = 0; i<size; ++i)
    {
        A[i] = rand() %100 + 1;
        std::cout << A[i] << " ";
    }
    std::cout << std::endl;
    quickSort(A,0,size-1);
    for(std::size_t i = 0; i<size; ++i)
    {
        std::cout << A[i] << " ";
    }
    return 0;
}
