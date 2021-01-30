#include<bits/stdc++.h>
#include<iostream>
using namespace std;

void merge(vector<int> &a,int l,int m,int r);
void mergesort(vector<int> &a,int l,int r)
{
/*We will check whether we have one element or not in our [l,r] range. If we have only 
one element then we return without doing anything.If we have more than one element then 
we will calculate the middle element,Apply merge sort on both the halfs and then merge 
them back.
*/
      if(l<r)
      {
          int m = (r-l)/2 + l ;
          mergesort(a,l,m);
          mergesort(a,m+1,r);
          merge(a,l,m,r);
          return;
      }
      else
      return;
    
}

void merge(vector<int> &a,int l,int m,int r)
{
    /* we have to merge the 2 sorted arrays(left and right) now.*/
    int n1 = m-l+1;
    int n2 = r-m;
    
    int L[n1];
    int R[n2];
    
    /* we will copy the elements of a into L and R.*/
    for(int i=0;i<n1;i++)
    L[i]=a[l+i];
    for(int i=0;i<n2;i++)
    R[i] = a[m+1+i];
    
    int i = 0; // L starting index
    int j = 0; // R starting index 
    int k = l; // sorted array starting index
    
    while(i<n1 && j<n2)
    {
        if(L[i]<=R[j])
        {
            a[k]=L[i];
            i++;
            k++;
        }
        else
        {
            a[k]=R[j];
            j++;
            k++;
        }
    }
    
    while(i<n1)
    {
        a[k]=L[i];
        i++;
        k++;
    }
    
    while(j<n2)
    {
        a[k]=R[j];
        j++;
        k++;
    }
    
    return;
}

int main()
{
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
    cin>>a[i];
    
    mergesort(a,0,n-1);
    for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
    cout<<endl;
}
