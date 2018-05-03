/* 
ID:greenty2
PROG: maze1
LANG: C++ 
*/  
#include <iostream>  
#include <fstream>  
#include <string>  
#include<memory.h>  
using namespace std;  
char ch;  
int map1[300][100];  
int record[300][100];  
int dir[4][2]={{-1,0},{0,-1},{0,1},{1,0}};  
int row,col;  
int countNum=0;  
int ok=0;  
void DFS(int i,int j,int step)  
{  
  int newr,newc;  
  record[i][j]=step;  
  for(int a=0;a<4;a++)  
  {  
    newr=i+dir[a][0];  
    newc=j+dir[a][1];  
    if(i>=0&&j>=0&&newr<=row&&newc<=col&&map1[newr][newc]==0&&step+1<record[newr][newc])  
      DFS(newr,newc,step+1);  
  }  
}  
int main() {  
    ofstream fout ("maze1.out");  
    ifstream fin ("maze1.in");  
    int W,H;  
    int start[2][2],num=0;  
    cin>>W>>H;  
    row=2*H+1;col=2*W+1;  
    string str;  
    getline(cin,str);  
    memset(map1,0,sizeof(map1));  
    for(int i=0;i<row;i++)  
    {  
         getline(cin,str);  
       for(int j=0;j<str.length();j++)  
         if(str[j]!=' ')  
           map1[i][j]=1;  
    }  
    for(int i=0;i<row;i++)  
        for(int j=0;j<col;j++)  
         if((i==0||j==0||i==row-1||j==col-1)&&map1[i][j]==0)  
          {  
           start[num][0]=i;start[num++][1]=j;  
          }  
      for(int i=0;i<row;i++)  
        for(int j=0;j<col;j++)  
         record[i][j]=100000;  
      DFS(start[0][0],start[0][1],1);  
      DFS(start[1][0],start[1][1],1);  
      int max=0;  
        for(int i=0;i<row;i++)  
         {  
          for(int j=0;j<col;j++)  
           if(record[i][j]!=100000&&max<record[i][j])  
             max=record[i][j];  
         }  
         cout<<max/2;  
    return 0;  
}  
