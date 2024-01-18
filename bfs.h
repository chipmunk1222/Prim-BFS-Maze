#pragma once

#include<iostream>
#include<vector>
#include"maze.h"
#include"maze.cpp"
using namespace std;

#define INF 1e9
class solution:virtual public maze{
public:

    int bfs(vector<pair<int,int>>&);
    void print_route();
    int find_step(); 
    void reverse_route();   
    // void print_maze();
    solution();
    void print_tube();
    solution(int,int);
    void set_start();

private:
    vector<pair<int,int>> route;
    vector<vector<int>> Maze;
    int Maze_length;
    int Maze_width;
    int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};

};