#include<bits/stdc++.h>
using namespace std;
int tree[1000][100];
int idx[1000][100];
int arr[1000];

void filltable(int n){
	int i,j,k;
	//base case tree[0][i+2^0-1] --> tree[0][i] so minimum in range [i,i] :P
	for( i =0 ;i<n ; i++){
		tree[0][i] = arr[i];
		idx[0][i] = i ;
	}
	int maxj = log2(n);
	for( j = 1 ; j<=maxj ; j++)
	{
		for( i = 0 ; i<n ; i++)
		{
			k = (1<<(j-1))+i ;
			if( k<n){
			if( tree[j-1][i] > tree[j-1][k])
			{
				tree[j][i] = tree[j-1][k];
				idx[j][i] = idx[j-1][k];
			}
			else{
				tree[j][i] = tree[j-1][i];
				idx[j][i] = idx[j-1][i];	
			}

		}
		}
	}
}

int query(int i,int j){
	int k,len,m;
	k = log2(j - i + 1);
	if( tree[k][i] > tree[k][j-(1<<k)+1])
		return idx[k][j-(1<<k)+1] ;
	return idx[k][i];
}

int main(){
	int i,k,tc,j,n;
	cout<<"Enter the no. of elements to be stored :\n";
	cin>>n;
	cout<<"Enter the elements\n";
	for(i =0  ; i<n; i++)cin>>arr[i]; 
	for(i = 0 ;i<n;i++)for(j = 0 ; j<n ;j++)tree[i][j] = -1;
	filltable(n);
 	for(j = 0 ; j<n;j++){
 		for(i = 0 ; i<=ceil(log2(n)) ;i++)
 		{	
 			if( )
 			cout<<tree[i][j]<<" ";
 		}cout<<"\n";
 	}
	cout<<"Enter the number of queries you want to do :\n";
	cin>>tc;while(tc--){
		cin>>i>>j;
		int ans = query(i,j);
		cout<<"Lowest value is "<<ans<<" It's index is "<<arr[ans];
	}
	return 0;
}