//Code Forces -  1077 C
#include <iostream>

#define ll long long
#define u unsigned

int main()
{
    u int n;          //number of array elements,
    u ll int sum = 0; //total sum of the elements
    u int k = 0;      //umber of elements that can be cut to form good array
    u int max = 0;    //
    int arr[200001];  //the array
    int val[1000001]; //wich and how many values are present in the array
    int end[200001];  //wich values can be cut to form a good array

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        //getting the array, adding to sum and
        //setting val
        scanf("%d", &arr[i]);
        sum += arr[i];
        val[arr[i]]++;
        if (arr[i] > max)
            max = arr[i];
    }
    //printf("sum-%lld\n\n", sum);

    for (int i = 0; i < n; i++)
    {
        int s = sum - arr[i]; // the sum of the values left

        //this is checks if it  can be good array
        //if s is uneven then there is no number that can be the sum of the others
        //because the sum of the rest and the number in question would be the same
        //and even + even = even and uneven + uneven = even
        if (s % 2 != 0)
            continue;

        //iterating trough the array
        //simulate removal
        val[arr[i]] -= 1;

        //if s/2 is present in arr
        //then it forms a good array after taking arr[i] out
        if ((s / 2) <= max && val[s / 2] > 0)
        {
            end[k] = i;
            //printf("i-%d\narr[i]-%d\nval[%d]-%d\nk-%d\nend[k]-%d\n\n", i, arr[i], s / 2, val[s / 2], k, end[k]);
            k++;
        }
        //reeintroducing previously taken value
        val[arr[i]] += 1;
    }

    //output
    printf("%d\n", k);
    for (int i = 0; i < k; i++)
        printf("%d ", end[i] + 1);
    printf("\n");
}
