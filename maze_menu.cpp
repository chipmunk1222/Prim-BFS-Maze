#include"bfs.h"
#include"bfs.cpp"


int main(){

    while(true){
        cout<<"1.create a random maze according to the input row and column"<<endl;
        cout<<"2.automatically perform the whole process"<<endl;

        int sel;
        cin>>sel;
        int step;

        if(sel == 1){
            int row,column;
            cout<<"please enter the row and column of the maze:"<<endl;
            cin>>row>>column;
            solution M(row,column);
            // cout<<"please enter the start point"<<endl;

         


            step = M.find_step();
            // M.print_maze();
            if(step!=1e9){
                cout<<"the minimun step to get the destination is: "<<step<<endl;
                M.print_route();
            }
            system("pause");
        }
        else if(sel ==2){
            solution M2;
            step = M2.find_step();
            if(step!=1e9){
                cout<<"the minimun step to get the destination is: "<<step<<endl;
                M2.print_route();
            }
            system("pause"); 
        }
        else{
            cout<<"please enter the right number"<<endl;
            system("pause");
        }

        system("cls");
    }

    return 0; 
}