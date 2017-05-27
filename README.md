# sudokuCrack
## 使用代码实例
至此我们有了一个稳健的求解方法，下面是一个实例  

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
瞬间完成，输出如下

        4 9 6 5 2 8 7 1 3 
        8 7 5 1 4 3 6 9 2 
        1 3 2 9 6 7 8 5 4 
        3 1 4 2 8 9 5 7 6 
        7 2 9 6 5 4 3 8 1 
        5 6 8 7 3 1 4 2 9 
        6 8 7 4 9 2 1 3 5 
        9 4 3 8 1 5 2 6 7 
        2 5 1 3 7 6 9 4 8 
