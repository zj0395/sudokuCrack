/*************************************************************************
	> File Name: sudokucrack.cpp
	> Author: zj
	> Mail: zhangjian0395@163.com
	> Created Time: Sat 27 May 2017 11:52:43 AM CST
 ************************************************************************/

#include<iostream>
#include <random>
static std::default_random_engine e(time(0));
static std::uniform_int_distribution<int> u(0,1);
#include "sudokucrack.h"
vvint SudokuCrack::result;
SudokuCrack::SudokuCrack(vvint& tt) : vvnum(tt)
{}
void SudokuCrack::setInitNum( vvint& tt)
{
    vvnum = tt;
}
int SudokuCrack::beginCrack()
{
    int n=isBad();
    if( n!=0 )
        return n;
    result = vvint(1,vint(1,0));
    selectBetter();
    return 0;
}
int SudokuCrack::selectBetter()
{
    vint min_locate ( 2,0 );
    int min_lack=10;
    int lack_num = 10;
    for( int i=0 ; i<9 ;++i )
    {
        for( int j=0; j<9; ++j )
        {
            lack_num =  vvnum[i][j] ? 10 :  countLackNum(i,j);
            if( lack_num < min_lack  )
            {
                min_lack = lack_num;
                min_locate[0]=i;
                min_locate[1]=j;
            }
            else if(lack_num == min_lack)
            {
                if( u(e)  )
                {
                    min_locate[0]=i;
                    min_locate[1]=j;
                }
            }
        }
    }
    if( min_lack == 10 )
    {
        if( checkwin() )
        {
            result=vvnum;
            return 1;
        }    
        else return 0;
    }
    return attemptLocate( min_locate[0]  ,min_locate[1] );
}
int SudokuCrack::countLackNum(int i ,int j)
{
    return getLackedNumSet(i,j).size();
}
sint& SudokuCrack::getLackedNumSet(int i,int j )
{
    static sint d;
    sint s_temp={1,2,3,4,5,6,7,8,9};
    using std::swap;
    swap(d , s_temp);
    for(int m=0; m<9; ++m)
    {
        d.erase(vvnum[i][m]);
        d.erase(vvnum[m][j]);
    }
    int m =i/3*3, n=j/3*3;
    for( int q=0; q<3; ++q )
    {
        for( int p=0 ;p<3; ++p )
        {
            d.erase( vvnum[m+q][n+p] );
        }
    }
    return d;
}
int SudokuCrack::attemptLocate( int i, int j )
{
    sint d = getLackedNumSet( i , j );
    sint::iterator it=d.begin();
    for( ; it!=d.end(); ++it )
    {
        vvint vvnum_new=vvnum;
        vvnum_new[i][j]=*it;
        SudokuCrack sucr_t(vvnum_new);
        if( sucr_t.selectBetter() )
            return 1;
    }
    return 0;
}
bool SudokuCrack::checkwin()
{
    const sint ss={1,2,3,4,5,6,7,8,9};
    for( int i=0 ;i<9; ++i )
    {
        sint a,b;
        for(int j=0; j<9; ++j)
        {
            a.insert(vvnum[i][j]);
            b.insert(vvnum[j][i]);
        }
        if( a!=ss || b!=ss )
            return 0;
    }
    for( int m=0 ;m<7; m+=3 )
    {
        for( int n=0; n<7 ; n+=3 )
        {
            sint d;
            for(int i=0 ;i<3; ++i)
            {
                for( int j=0 ;j<3; ++j )
                {
                    d.insert(vvnum[m+i][n+j]);
                }
            }
            if(d!=ss)
                return 0;
        }
    }
    return 1;
}
void SudokuCrack::showResult()
{
    for(vint & s : result)
    {
        for( int & d : s )
            std::cout<<d<<" ";
        std::cout<<"\n";
    }
    std::cout<<std::endl;
}
int SudokuCrack::isBad()
{
    for( int i=0 ;i<9; ++i )
    {
        sint a,b;
        for(int j=0; j<9; ++j)
        {
            if(vvnum[i][j]!=0)
            {
                if( a.find(vvnum[i][j])==a.end() ) 
                    a.insert(vvnum[i][j]);
                else
                {
                    std::cout<<i<<j<<"  "<<vvnum[i][j]<<std::endl;
                    return 1;
                }
            }
            if(vvnum[j][i]!=0)
            {
                if( b.find(vvnum[j][i])==b.end() )
                    b.insert(vvnum[j][i]);
                else
                    return 2;
            }
        }
    }
    for( int m=0 ;m<7; m+=3 )
    {
        for( int n=0 ;n<7; n+=3 )
        {
            sint d;
            for(int i=0 ;i<3; ++i)
            {
                for( int j=0 ;j<3; ++j )
                {
                    if(vvnum[m+i][n+j]==0)
                        continue;
                    if( d.find(vvnum[m+i][n+j])==d.end() ) 
                        d.insert(vvnum[m+i][n+j]);
                    else
                    {
                        std::cout<<m+i<<n+j<<"   "<<vvnum[m+i][n+j]<<std::endl;
                        return 3;   
                    }
                }
            }
        }
    }
    return 0;
}
