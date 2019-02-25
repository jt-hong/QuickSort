
#include<stdio.h>
#include<iostream>
 
int Partition(int*Array,int n,int p,int r);
void QuickSort(int* Array,int n,int p,int r);
 using namespace std;
int main()
{
	int Array[8]={4,8,7,1,3,8,6,4};
	int n=sizeof(Array)/sizeof(int);
	int p=0;
	int r=n-1;
	QuickSort(Array,n,p,r);
 
	for(int k=0;k<n;k++)
		printf("%d ",Array[k]);
	printf("\n");
}
 
 
int Partition(int*Array,int n,int p,int r)
{
    cout<<"Partition"<<endl<<" Key: "<<Array[r]<<endl;
	int x=Array[r];
	int i=p-1;
	int temp=0;
	for(int j=p;j<=r-1;j++)
	{
		if(Array[j]<=x)
		{
			i++;
            cout<<"j = "<<j<<"  i = "<<i<<endl;
			temp=Array[i];
			Array[i]=Array[j];
			Array[j]=temp;
		}
	}
	temp=Array[i+1];
	Array[i+1]=Array[r];
	Array[r]=temp;
 
	return i+1;
}
 
 
void QuickSort(int* Array,int n,int p,int r)
{
	int q=0;
	if(p<r)
	{
		q=Partition(Array,n,p,r);
		QuickSort(Array,n,p,q-1);
		QuickSort(Array,n,q+1,r);
	}
}

void Swap(int  *x, int  *y)
{
	int Temp;
	Temp = *x;
	*x = *y;
	*y = Temp;
}