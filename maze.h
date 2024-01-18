#pragma once
#include<iostream>
#include<vector>
#include<random>
#include<cstdio>
#include<ctime>
using namespace std;

#define m_row 21
#define m_column 21

#define up 'u'
#define down 'd'
#define left 'l'
#define right 'r'
#define air 0
#define wall -1
#define tube 1
#define interface 2

class block{
public:
    int m_x;
    int m_y;
    char dir;
    block(int x,int y,char d):m_x(x),m_y(y),dir(d){};

};

class maze{
public:
    void print_maze();
    // void init();
    void find_block();
    void create_maze();
    maze();
    maze(int,int);
protected:

    vector<vector<int>> G;
    vector<block> my_block; 
    int pos_x = 1,pos_y = 1;
    int row ;
    int column ;
};

