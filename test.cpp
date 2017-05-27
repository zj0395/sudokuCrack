/*************************************************************************
	> File Name: test.cpp
	> Author: zj
	> Mail: zhangjian0395@163.com
	> Created Time: Sat 27 May 2017 12:52:59 PM CST
 ************************************************************************/

#include<iostream>
#include "sudokucrack.h"
using namespace std;
int main()
{
    vvint d{
        {4,0,0,5,2,0,7,0,3},
        {0,0,0,0,0,3,0,0,0},
        {1,0,0,0,0,7,0,0,0},
        {0,1,4,0,0,0,0,0,6},
        {7,0,0,0,5,0,0,0,1},
        {5,0,0,0,0,0,4,2,0},
        {0,0,0,4,0,0,0,0,5},
        {0,0,0,8,0,0,0,0,0},
        {2,0,1,0,7,6,0,0,8}
    };
    SudokuCrack s(d);
    int m=s.beginCrack();
    if(m==0)
    {
        const vvint &r=s.getResult();
        for(const vint & a : r)//c++11，基于范围的for循环
        {
        	for( int d : a)
            	cout<<d<<" ";
            cout<<"\n";
        }
        cout<<endl;
    }
    else if(m==1)
        cout<<"数独非法！在某行中有重复数字！"<<endl;
    else if(m==2)
    	cout<<"数独非法！在某列中有重复数字！"<<endl;
    else if(m==3)
        cout<<"数独非法！在某3×3矩阵中有重复数字！"<<endl;
    return 0;
}

