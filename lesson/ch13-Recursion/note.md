# compiler optimized tail recursion and this called tail call elimination

// An example of tail recursive function
void print(int n)
{
    if (n < 0) 
       return;
    cout << " " << n;

    print(n-1);
}

// Above code after tail call elimination
void print(int n)
{
start:
    if (n < 0)
    return;
    cout << " " << n;

    // Update parameters of recursive call
    // and replace recursive call with goto
    n = n-1;
    goto start;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
           at right place */
        int pi = partition(arr, low, high);

        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void quickSort(int arr[], int low, int high)
{
start:
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
           at right place */
        int pi = partition(arr, low, high);
 
        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
 
        // Left half is sorted, sort right part
        // Update parameters of recursive call
        // and replace recursive call with goto
        low = pi+1;
        high = high;
        goto start;
    }
}