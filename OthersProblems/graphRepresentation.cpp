#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Graph {
private:
    int n;
    int e;
    vector<pair<int,int>> edges;
    vector<vector<bool>> matrix;
    vector<vector<int>> list;
    enum Color { WHITE, GRAY, BLACK };
    void dfsTraversal(int node,vector<Color>&color) {
    color[node] = GRAY; // discovered
    cout << "Pre-order: " << node << "\n"; // pre-order processing
    for (int neighbor : list[node]) {
        if (color[neighbor] == WHITE) {
            dfsTraversal(neighbor,color); // go deeper
        }
    }

    cout << "Post-order: " << node << "\n"; // post-order processing
    color[node] = BLACK; // fully processed
}
public:
  Graph(){};
  void input()  {
    edges.clear();
    cout<<"Enter the Number of Nodes and Edges: ";
    cin>>n>>e;
    int e1,e2;
    cout<<"Enter the edges: ";
    for(int i=1;i<=e;i++)   {
        cin>>e1>>e2;
        edges.push_back({e1,e2});
    }
    storeInMatrix();
    storeInList();
  }
  void storeInMatrix() {
    matrix.clear();
    matrix.resize(n+1,vector<bool>(n+1,false));
    for(auto& p:edges)  {
      matrix[p.first][p.second]=true;
      matrix[p.second][p.first]=true;
    }
    // for(int r=0;r<=n;r++) {
    //   for(int c=0;c<=n;c++) {
    //     cout<<matrix[r][c]<<" ";
    //   }
    //   cout<<endl;
    // }
  }
  void storeInList()  {
    list.clear();
    list.resize(n+1);
    for(auto& p:edges)  {
     list[p.first].push_back(p.second);
     list[p.second].push_back(p.first);
    }
    // for(int i=1;i<=n;i++)  {

    //   cout<<i<<" : ";

    //   for(int k:list[i]) cout<<k<<" ";
    //   cout<<endl;
    // }

  }
void bfs(int start = 1) {
    vector<Color> color(n + 1, WHITE); // initially all WHITE
    queue<int> q;
    q.push(start);
    color[start] = GRAY; // discovered

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        cout << node << " ";  // process node
        color[node] = BLACK;  // processed

        for (int neighbor : list[node]) {
            if (color[neighbor] == WHITE) { // not discovered yet
                q.push(neighbor);
                color[neighbor] = GRAY; // discovered
            }
        }
    }
   
}
void dfs(int start=1) {
    vector<Color> color(n + 1, WHITE); // initially all WHITE
    dfsTraversal(start,color);
}

};

int main()  {
    Graph g;
    g.input();
    g.dfs(1);

}