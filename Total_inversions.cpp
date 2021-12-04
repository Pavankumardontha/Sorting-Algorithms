#include<bits/stdc++.h>
#include <iostream>
using namespace std;

int combined_inversions_count(vector<int> &a , int l, int m, int r); // returns no. of inversions while combining the 2 sorted halfs(a[l,m] and a[m+1,r]).
int total_inversions_count(vector<int> &a, int l, int r) // find totoal inversions in an array a[l,r]
{
    if(l<r)
    {
        int m = l + (r-l)/2;
        int left_inversions = total_inversions_count(a,l,m);  // left half inversions count 
        int right_inversions = total_inversions_count(a,m+1,r); // right half inversions count 
        int combined_inversions = combined_inversions_count(a,l,m,r); // inversions arising by combining left half and right half
        int total_inversions = left_inversions + right_inversions + combined_inversions; //total inversions count
        return total_inversions;
    }
    else
    return 0;
}

int combined_inversions_count(vector<int> &a , int l, int m, int r)
{
    int n1 = m-l+1; //left array size
    int n2 = r-m; //right array size
    int L[n1]; //left array
    int R[n2]; //right array
    
    //copying the array data into left and right array
    for(int i=0;i<n1;i++)
    L[i] = a[l+i];
    for(int i=0;i<n2;i++)
    R[i] = a[m+1+i];
    
    int i = 0; // L index
    int j = 0; // R index 
    int k = l; // a index
    
    int combined_inversions = 0 ; 
    while(i<n1 && j<n2)
    {
        if(L[i]<=R[j])
        {
            // no inversion 
            a[k] = L[i];
            i++;
        }
        else
        {
            //there are inversions
            combined_inversions = combined_inversions + n1 - i;
            a[k] = R[j];
            j++;
        }
        k++;
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
    return combined_inversions;
}


int main() 
{
	// brute force time complexity = O(n^(2)) 
	// expected time complexity = O(nlogn). Done by modifying merge sort !!
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++)
	cin>>a[i];
	int ans = total_inversions_count(a,0,n-1);
	cout<<"total inversions : " << ans<<endl;
}
