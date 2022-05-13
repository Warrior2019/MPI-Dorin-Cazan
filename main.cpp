#include <bits/stdc++.h>
#include <time.h>
using namespace std;
int a[1000000],aux[1000000],n,size_heap;

void gen_array(int n)
{
    int i;
    for (i=1;i<=n;i++) a[i]=rand()%n;
}

//bubblesort
void bubble_sort(int a[],int n)
{
    int i,ok;
    do
    {
        ok=1;
        for (i=1;i<n;i++)
            if (a[i]>a[i+1]) {swap(a[i],a[i+1]);ok=0;}
    }while (ok==0);
}

//quicksort
int pivot(int s,int d)
{
    int di=0,aux;
    while (s<d)
    {
        if (a[s]>a[d]) {swap(a[s],a[d]);di=1-di;}
        s+=di;d-=1-di;
    }
    return s;
}
void qs(int a[],int s,int d)
{
    int i,k;
    if (s<d)
    {
        k=pivot(s,d);
        qs(a,s,k-1);
        qs(a,k+1,d);
    }
}

//insertion-sort
void insertion_sort(int a[],int n)
{
    int i,j;
    for (i=2;i<=n;i++)
    {
        j=i;
        while (j>1 && a[j-1]>a[j]) {swap(a[j],a[j-1]);j--;}
    }
}

//selection-sort
void selection_sort(int a[],int n)
{
    int i,j;
    for (i=1;i<n;i++)
        for (j=n;j>=i+1;j--)
            if (a[j]<a[j-1]) swap(a[j],a[j-1]);
}

//mergesort
void merge(int a[],int st,int mid,int dr)
{
    int i,j,k,n1=mid-st+1,n2=dr-mid;
    int left_array[n1],right_array[n2];
    for (i=0;i<n1;i++) left_array[i]=a[st+i];
    for (j=0;j<n2;j++) right_array[j]=a[mid+j+1];
    i=j=0;
    k=st;
    while(i<n1&&j<n2)
    {
        if (left_array[i]<=right_array[j])
        {
            a[k]=left_array[i];
            i++;
        }
        else
        {
            a[k]=right_array[j];
            j++;
        }
        k++;
    }
    while(i<n1)
    {
        a[k]=left_array[i];
        i++;
        k++;
    }
    while(j<n2)
    {
        a[k]=right_array[j];
        j++;
        k++;
    }
}
void merge_sort(int a[],int st,int dr)
{
    if(st>=dr) return;
    int mid=(st+dr-1)/2;
    merge_sort(a,st,mid);
    merge_sort(a,mid+1,dr);
    merge(a,st,mid,dr);
}

//counting sort
void counting_sort(int a[],int n,int k)
{
    int i,c[k+1];
    for (i=0;i<=k;i++) c[i]=0;
    for (i=1;i<=n;i++) c[a[i]]++;
    for (i=2;i<=k;i++) c[i]+=c[i-1];
    for (i=n;i>=1;i--)
    {
        aux[c[a[i]]]=a[i];
        c[a[i]]--;
    }
}

//heap sort
void heapify(int a[],int n,int i)
{
    int largest=i,l=2*i,r=2*i+1;
    if (l<n && a[l]>a[largest]) largest=l;
    if (r<n && a[r]>a[largest]) largest=r;
    if (largest!=i)
    {
        swap(a[i],a[largest]);
        heapify(a,n,largest);
    }
}
void heapsort(int a[],int n)
{
    int i;
    for (i=n/2;i>=1;i--) heapify(a,n,i);
    for (i=n;i>1;i--)
    {
        swap(a[1],a[i]);
        heapify(a,i,1);
    }
}

//bucketsort
struct bucket
{
    int b[10];
}p[10000000];
void bucket_sort(int a[],int n)
{
    int i,aux;
    for (i=1;i<=n;i++) p[a[i]/10].b[a[i]%10]=a[i];
    for (i=0;i<=n;i++) sort(p[i].b+1,p[i].b+10);
}

int main()
{
    gen_array(800000);
    clock_t start,time;
    start=clock();
    //bubble_sort(a,n);
    //qs(a,1,800000);
    //insertion_sort(a,n);
    //selection_sort(a,n);
    //merge_sort(a,n);
    //counting_sort(a,n,mx);
    heapsort(a,800000);
    //bucket_sort(a,n);
    time=clock()-start;
    double time_taken=((double)time)/CLOCKS_PER_SEC;
    cout <<time_taken<<endl;
    return 0;
}
