#include <queue>
#include <vector>
#include <iostream>
#include <utility>




using namespace std;

int main(){
    queue <pair<int, int>> q;

    int row,col;
    cin>>row>>col;
    cin.ignore();
    vector<vector<char>> maze;
    maze = vector<vector<char>>(row, vector<char>(col)); 
    pair<int, int>  start, end; 
    string inp;
    vector<vector<pair<int, int>>> parent;
    vector<vector<int>> distance; 
    distance = vector<vector<int>>(row, vector<int>(col));
    parent = vector<vector<pair<int, int>>>(row, vector<pair<int, int>>(col));

    for(int i = 0; i<row; i++){
        getline(cin, inp);
        for(int j = 0; j<col; j++){
            maze[i][j]= inp[j];
            distance [i][j]=100;
            if (inp[j]=='S') q.push(make_pair(i, j));
            if (inp[j]=='S') distance[i][j]=0;
            if (inp[j]=='S') start = (make_pair(i,j));
            if (inp[j]=='G') end = (make_pair(i,j));
        }
            
    }
    /*for(int i = 0; i<row; i++){
        for(int j = 0; j<col; j++){
            cout<<maze[i][j];
        }
        cout<<endl;
    } */
    // Breadth first Search
    bool goal = false;
    
    while (goal == false&&!q.empty()){
        pair<int, int> curr, u, d, l, r;
        curr = q.front();
        q.pop();
        
        // Down
        u = make_pair(curr.first-1, curr.second);
        if(curr.first!=0)
        if(maze[u.first][u.second]!='x'&&distance[u.first][u.second]>distance[curr.first][curr.second]){
            distance[u.first][u.second]=distance[curr.first][curr.second]+1;
            parent[u.first][u.second]=curr;
            q.push(u);
        }
        // Left
        u = make_pair(curr.first, curr.second-1);
        if(curr.second!=0)
        if(maze[u.first][u.second]!='x'&&distance[u.first][u.second]>distance[curr.first][curr.second]){
            distance[u.first][u.second]=distance[curr.first][curr.second]+1;
            parent[u.first][u.second]=curr;
            q.push(u);
        }
         // Right 
        u = make_pair(curr.first, curr.second+1);
        if(curr.second!=maze[0].size())
        if(maze[u.first][u.second]!='x'&&distance[u.first][u.second]>distance[curr.first][curr.second]){
            distance[u.first][u.second]=distance[curr.first][curr.second]+1;
            parent[u.first][u.second]=curr;
            q.push(u);
        }
        // Up 
        u = make_pair(curr.first+1, curr.second);
        if(curr.first!=maze.size())
        if(maze[u.first][u.second]!='x'&&distance[u.first][u.second]>distance[curr.first][curr.second]){
            distance[u.first][u.second]=distance[curr.first][curr.second]+1;
            parent[u.first][u.second]=curr;
            q.push(u);
        }
       
        if(distance[end.first][end.second]<100)goal=true;
    }
    if (q.empty()&&!goal){
        cout<<"No Path"<<endl;
    }else{
        pair<int, int> curr = end;
        while (curr!=start){
            pair<int, int> next = parent[curr.first][curr.second]; 
            maze[next.first][next.second]='*';
            curr=next;
        }
        maze[curr.first][curr.second]='S';
        for(int i = 0; i<row; i++){
            for(int j = 0; j<col; j++){
                cout<<maze[i][j];
            }
            cout<<endl;
        }    
    }

    


    
}