#include"maze.h"



maze::maze(){

    this->row = m_row;
    this->column = m_column;
    vector<vector<int>> tmp(row,vector<int> (column,wall));
    this->G = tmp;
    G[pos_x][pos_y] = air;
    create_maze();
}

maze::maze(int row,int col){
    this->row = row;
    this->column = col;
    vector<vector<int>> tmp(row,vector<int> (column,wall));
    this->G = tmp;
    G[pos_x][pos_y] = air;
    create_maze();

    // this->row = row;
    // this->column = col;
}

//查找上下左右四个方向是否为墙，若是，则记录
//若碰到边界里1格，则停止检索，因为不能挖穿边界围墙
void maze::find_block(){
    if(pos_x+1<=row-3&&G[pos_x+1][pos_y]==wall){
        my_block.push_back(block(pos_x+1,pos_y,down));
        if(G[pos_x+2][pos_y]==wall)
            G[pos_x+2][pos_y]=interface;
    }

    if(pos_x-1>=2&&G[pos_x-1][pos_y]==wall){
        my_block.push_back(block(pos_x-1,pos_y,up));
        if(G[pos_x-2][pos_y]==wall)
            G[pos_x-2][pos_y]=interface;
    }

    if(pos_y+1<=column-3&&G[pos_x][pos_y+1]==wall){
        my_block.push_back(block(pos_x,pos_y+1,right));
        if(G[pos_x][pos_y+2]==wall)
            G[pos_x][pos_y+2]=interface;
    }

    if(pos_y-1>=2&&G[pos_x][pos_y-1]==wall){
        my_block.push_back(block(pos_x,pos_y-1,left));
        if(G[pos_x][pos_y-2]==wall)
        G[pos_x][pos_y-2]=interface;
    }
    
}

void maze::create_maze(){
    //初始化迷宫
    // if(f1==0&&f2==0)
    //     init();

    // init(f1,f2);    
    find_block();

    while(my_block.size()){

        srand(time(NULL));
        //利用prim算法，随机找待挖穿的墙
        int index = rand()%(my_block.size());        
        pos_x = my_block[index].m_x;
        pos_y = my_block[index].m_y;
        
        switch (my_block[index].dir){
            case down:
                pos_x++;
                break;
            case up:
                pos_x--;
                break;
            case right:
                pos_y++;
                break;
            case left:
                pos_y--;
                break;
            default:
                cout<<"cannot find the wall"<<endl;
                break;
        }
        //两种情况：
        //1.如果墙连接的另一边也为墙，则直接挖穿
        //2.若墙另一边为通道，则continue
        if(G[pos_x][pos_y]==wall||G[pos_x][pos_y]==interface){
            G[pos_x][pos_y]=G[my_block[index].m_x][my_block[index].m_y] = air;
            //刷新迷宫绘制状态
            _sleep(1*20);
            system("cls");
            print_maze();

            find_block();
        }

        my_block.erase(my_block.begin()+index);

    }
   
}

    void maze::print_maze(){
        for(int i = 0;i<=row-1;i++){
            for(int j = 0;j<=column-1;j++){
                if(G[i][j]==air){
                    printf("  ");
                }
                
                else if(G[i][j]==interface){
                    printf("\033[31;1m%c%c \033[0m",0xa8,0x80);
                }
                else if(G[i][j]==wall){
                    printf("%c%c ",0xa8,0x80);
                }
            }
            cout<<endl;
        }
    }

