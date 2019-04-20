#pragma once

#include "stdafx.h"
#include "headers.h"
#include "functions.h"



void vvod() //функция наполнения
{
	for(int i=1; i<=p; i++)
	{
		for(int j=1; j<=m; j++)
		{
			for(int k=1; k<=n; k++)
			{
				A[i][j][k] = rand()%125; //наполняем случайными числами
			}
		}
	}
}



void tomatrix() //функция работы над сечением
{
	int obhod;
	cout<<"Obhod = ";
	cin>>obhod;
	cout<<endl<<"-Pererizy (P) = "<<p<<endl;
	for(int i=1; i<=p; i++)
	{
		cout<<endl;
		cout<<"--"<<i<<')'<<endl;
		cout<<endl;
		cout<<"---Unsorted: "<<endl;

		for(int j=1; j<=m; j++)
		{
			cout<<endl;
			for(int k=1; k<=n; k++)
			{
				Ac[j][k]=A[i][j][k]; //записываем в матрицу
				cout<<setw(5)<<Ac[j][k];
			}
		}


		if (obhod==1)
			algorytm1();
		if (obhod==2)
			algorytm1();
		if (obhod==3)
			algorytm3();


		cout<<endl<<endl;
		cout<<"---Sorted: "<<endl;

		for(int j=1; j<=m; j++)
		{
			cout<<endl;
			for(int k=1; k<=n; k++)
			{
				A[i][j][k]=Ac[j][k]; //записываем отсортированую матрицу
				cout<<setw(5)<<A[i][j][k];
			}
		}
		cout<<endl<<endl<<endl;
	}

}










void algorytm1() //алгоритм сортировки для обхода н1 (вектор)
{
	for(int j=1; j<=n; j++)
	{		
		for(int i=1; i<=m; i++) //запись столба в вектор
		{
			B[i]=Ac[i][j];
		}
	
		int L,R,imin,imax,min,max;
		L=1; R=m;
		while (L<R)
		{
			min=B[L]; imin=L;
			max=B[L]; imax=L;
			for(int i=L+1; i<=R; i++)
			{
				if (B[i]<min)
				{
					min=B[i];
					imin=i;
				}
				else
				{
					if (B[i]>max)
					{
						max=B[i];
						imax=i;
					}
				}
			}
			B[imin]=B[L];
			B[L]=min;
			if (imax==L)
				B[imin]=B[R];
			else
				B[imax]=B[R];

			B[R]=max;
			L=L+1;
			R=R-1;
		}

		for(int i=1; i<=m; i++) //запись отсортированого столба в матрицу
		{
			Ac[i][j]=B[i];
		}
	
	}

}





void algorytm2() //алгоритм сортировки для обхода н2 
{/*
	for(int j=1; j<=n; j++)
	{
		int L,R,imin,imax,min,max;
		L=j; R=m*n;
		while (L<R)
		{
			min=Ac[L]; imin=L;
			max=Ac[L]; imax=L;
			for(int i=L; i<R; i=i+n)
			{
				if (Ac[i]<min)
				{
					min=Ac[i];
					imin=i;
				}
				else
				{
					if (Ac[i]>max)
					{
						max=Ac[i];
						imax=i;
					}
				}
			}
			Ac[imin]=Ac[L];
			Ac[L]=min;
			if (imax==L)
				Ac[imin]=Ac[R];
			else
				Ac[imax]=Ac[R];

			Ac[R]=max;
			L=L+n;
			R=R-n;
		}
	}*/
}





void algorytm3() //алгоритм сортировки для обхода н3
{
	for(int j=1; j<=n; j++)
	{
		int L,R,imin,imax,min,max;
		L=1; R=m;
		while (L<R)
		{
		
			min=Ac[L][j]; imin=L;
			max=Ac[L][j]; imax=L;
			for(int i=L+1; i<=R; i++)
			{
				if (Ac[i][j]<min)
				{
					min=Ac[i][j];
					imin=i;
				}
				else
				{
					if (Ac[i][j]>max)
					{
						max=Ac[i][j];
						imax=i;
					}
				}
			}
			Ac[imin][j]=Ac[L][j];
			Ac[L][j]=min;

			if (imax==L)
				Ac[imin][j]=Ac[R][j];
			else
				Ac[imax][j]=Ac[R][j];

			Ac[R][j]=max;
			L=L+1;
			R=R-1;
		}
	}
}