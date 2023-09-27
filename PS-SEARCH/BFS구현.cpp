#include<iostream>
#include<vector>
#include<queue>

using namespace std;

bool visited[9];
vector<int>graph[9];


//BFS 함수 정의.
void bfs(int x) {
    //queue 자료구조를 이용해서 구현.
    queue<int>q;
    q.push(x);

    //방문처리
    visited[x] = true;

    //매번 front를 빼고, 그와 연결된 방문하지 않은 노드들을 queue에 집어넣음.
    while (!q.empty()) {
        int y = q.front();
        q.pop();
        cout << y << " ";

        //queue에 집어넣고 방문처리를 함.
        for (int i = 0; i < graph[y].size(); i++) {
            if (visited[graph[y][i]] != true) {
                q.push(graph[y][i]);
                visited[graph[y][i]] = true;
            }
        }
    }
}

int main(void) {
    // 노드 1에 연결된 노드 정보 저장 
    graph[1].push_back(2);
    graph[1].push_back(3);
    graph[1].push_back(8);

    // 노드 2에 연결된 노드 정보 저장 
    graph[2].push_back(1);
    graph[2].push_back(7);

    // 노드 3에 연결된 노드 정보 저장 
    graph[3].push_back(1);
    graph[3].push_back(4);
    graph[3].push_back(5);

    // 노드 4에 연결된 노드 정보 저장 
    graph[4].push_back(3);
    graph[4].push_back(5);

    // 노드 5에 연결된 노드 정보 저장 
    graph[5].push_back(3);
    graph[5].push_back(4);

    // 노드 6에 연결된 노드 정보 저장 
    graph[6].push_back(7);

    // 노드 7에 연결된 노드 정보 저장 
    graph[7].push_back(2);
    graph[7].push_back(6);
    graph[7].push_back(8);

    // 노드 8에 연결된 노드 정보 저장 
    graph[8].push_back(1);
    graph[8].push_back(7);

    bfs(1);
}