/*************************************************************************
	> File Name: sudokucrack.h
	> Author: zj
	> Mail: zhangjian0395@163.com
	> Created Time: Sat 27 May 2017 11:53:05 AM CST
 ************************************************************************/

#ifndef _SUDOKUCRACK_H
#define _SUDOKUCRACK_H

#include <vector>
#include <set>

typedef std::vector<int> vint;
typedef std::vector<vint> vvint;
typedef std::set<int> sint;
class SudokuCrack
{
public:
    const vvint& getResult(){return result;}
    void showResult();
    SudokuCrack(vvint &);
    void setInitNum(vvint&);
    int beginCrack();
private:
    int isBad();
    bool checkwin();
    int selectBetter();
    int countLackNum(int i, int j);
    sint& getLackedNumSet( int i, int j );
    int attemptLocate( int i, int j);


    vvint vvnum;//0是没有数字，1-9为正常数字
    static vvint result;
};

#endif
