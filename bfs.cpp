#include"bfs.h"

solution::solution(){

    this->Maze_length = row;
    this->Maze_width = column;
    this->Maze = G;
}

solution::solution(int x,int y):maze(x,y){

    this->Maze_length = row;
    this->Maze_width = column;
    this->Maze = G;
};


// void set_start()

int solution::find_step(){
    vector<pair<int,int>> start = {{1,1}};

    if(Maze[start[0].first][start[0].second]!=0){
        cout<<"the starting is not supported"<<endl;
        return INF;
    }

    int time = bfs(start);
    return time;
}



int solution::bfs(vector<pair<int,int>>& q){
    vector<vector<int>> time(this->Maze_length,vector<int>(this->Maze_width,-1)); //�ж϶�Ӧλ����û�б�������ͬʱ��¼����
    for(auto& [i,j]:q){
        //���λ�ü�Ϊ0
        time[i][j] = 0;
    }

    //ͨ��bfs���㵽��ÿ�����ӵĲ���
    for(int t = 1;!q.empty();t++){
        vector<pair<int,int>> nq;
        
        //����ʼλ�ÿ�ʼ���ҳ���·��
        for(auto &[i,j]:q){
            for(auto &[dx,dy]:this->dir){
                int x = i+dx;
                int y = j+dy;
                if(x>=1&&x<this->Maze_length&&y>=1&&y<this->Maze_width&&Maze[x][y] == 0&&time[x][y] == -1){
                    nq.emplace_back(x,y);
                    time[x][y] = t;
                }
            }
            
        }
        q = move(nq);

    }

    //����Ż��������·�������յ㿪ʼ���ң�ȷ��·����ȷ��
    if(time[this->Maze_length-2][this->Maze_width-2]!=-1){
        int pos_x = this->Maze_length -2,pos_y = this->Maze_width -2;
        this->route.emplace_back(pos_x,pos_y);
        Maze[pos_x][pos_y] = tube;

        _sleep(1*20);
        system("cls");
        print_tube();


        for(int r =time[this->Maze_length-2][this->Maze_width-2]-1;r>=0;r--){
            
            //���ĸ��������
            for(auto &[dx,dy]:this->dir){
                int x = pos_x+dx;
                int y = pos_y+dy;    
                if(x>=1&&x<this->Maze_length&&y>=1&&y<this->Maze_width&&time[x][y] == r){
                    this->route.emplace_back(x,y);
                            Maze[x][y] = tube;

                            _sleep(1*20);
                            system("cls");
                            print_tube();

                    pos_x = x;pos_y = y;
                    break;
                } 
            }    

        }
        reverse_route();

    }

    else {
        cout<<"unable to get the destination"<<endl;
        return INF;
    }
    
    //����ֵΪȷ����������Ϊ�ҵ�·���������ʾδ�ҵ�
    return time[this->Maze_length-2][this->Maze_width-2];
}

void solution::print_route(){
    if(route.size()==1){
        return;
    }
    else {
        cout<<"the route is: "<<endl;
        cout<<"start->";
        for(auto &[i,j]:this->route){
            cout<<"["<<i<<","<<j<<"]->";
        }
        
        cout<<"destination"<<endl;
    }
}

void solution::reverse_route(){
    vector<pair<int,int>> tmp;
    for(int n = this->route.size()-1;n>=0;n--){
        tmp.emplace_back(this->route[n]);
    }
    route = tmp;
}

void solution::print_tube(){
    for(int i = 0;i<=row-1;i++){
        for(int j = 0;j<=column-1;j++){
            if(Maze[i][j]==air){
                printf("  ");
            }
            else if(Maze[i][j]==wall){
                printf("%c%c ",0xa8,0x80);
            }
            else if(Maze[i][j]==tube){
                printf("\033[32;1m%c%c \033[0m",0xa8,0x80);
            }

        }
        cout<<endl;
    }
}


