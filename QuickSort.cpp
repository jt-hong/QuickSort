#include<iostream>
#include<cstdlib>

using namespace std;

const int N = 19;
void Swap(int *,int ,int );
void QuickSort(int* ,int ,int);
void Insertsort(int x[], int Count);
void Swap(int *x,int *y);     //Swap by Address

int main()
{    
    int NList[20];
    for(int i = 0;i<20;i++)
    {
        NList[i] = rand()%11;
    }
    QuickSort(NList,0,N);
    for(int i = 0;i<20;i++)
    {
        cout<<NList[i]<<endl;
    }
}

void QuickSort(int* Array,int Left,int Right)
{
    int Mid = (Right-Left)/2;
    cout<<"Mid: "<<Mid<<endl;
    int Key = Array[Mid];
    int LP = Left;
    int RP = Right-1;
    if(Left+3<=Right)
    {
        Insertsort(Array+Left, Right - Left+1);
        return;
    }
    if(Array[Left]>Array[Right])
    {
        Swap(Array,Left,Right);
    }
    if(Array[Left]>Array[Mid])
    {
        Swap(Array,Left,Mid);
    }
    if(Array[Mid]>Array[Right])
    {
        Swap(Array,Mid,Right) ;      
    }
    Swap(Array, Mid,Right);
    while(LP < RP)
    {
        while(Array[LP]<=Key&&LP<RP)LP++;
        while(Array[RP]>=Key&&LP<RP)RP--;
        Swap(Array,LP,RP);
    }
    Swap(Array, Mid,Right);
    QuickSort(Array,Left,LP-1);
    QuickSort(Array,LP+1,RP);
    return;

}

void Swap(int  *x, int  *y)
{
	int Temp;
	Temp = *x;
	*x = *y;
	*y = Temp;
}

void Swap(int *Array,int a,int b)
{
    int Temp = Array[a];
    Array[a] = Array[b];
    Array[b] = Temp;
}

void Insertsort(int x[], int Count)
{
	int j=0;
	for (int i = 1; i < Count; i++)
	{
		j = i;
		while (j > 0 && x[j] < x[j - 1])
		{
			Swap(&x[j], &x[j - 1]);
			j--;
		}
	}
}