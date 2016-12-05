int findmin(int *arr,int n)
{
    int m=arr[0];
    for(int i=1;i<n;i++)
    {
        if(m>arr[i])
            m=arr[i];
    }
    return m;
}
