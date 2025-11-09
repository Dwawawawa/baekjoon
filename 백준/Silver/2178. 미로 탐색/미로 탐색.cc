#include <iostream>
#include <vector>
#include <algorithm>
#include <queue> 
#include <stack> 
#include <unordered_map>

using namespace std;

constexpr const int INF = 999;

struct Vertex
{
    int index;         
    int number_before; 
    int distance;      
};

static void BFS(int start_vertex_index, vector< vector<int> >& adj_list)
{
    //cout << "\nBreadth First Search(너비 우선 탐색)를 수행합니다. \n\n";

    int size = adj_list.size();
    vector<Vertex> vertexes(size);

    for (int i = 0; i < size; i++)
    {
        vertexes[i].index = i;  
        vertexes[i].number_before = INF;
        vertexes[i].distance = INF;
    }


    queue<int> q;

    vertexes[start_vertex_index].distance = 0;
    q.push(start_vertex_index);


    while (!q.empty())
    {
        int current_index = q.front();
        q.pop();
        int current_distance = vertexes[current_index].distance; 

;

        for (const auto& neighbor_index : adj_list[current_index])
        {
            
            if (neighbor_index == current_index) continue;
            if (vertexes[neighbor_index].number_before != INF)continue;

            
            q.push(neighbor_index);
            vertexes[neighbor_index].distance = current_distance + 1;
            vertexes[neighbor_index].number_before = current_index;
        }
    }

    //cout << "\n\nBreadth First Search(너비 우선 탐색)의 수행 결과입니다. \n\n";
    //cout << "값 | 거리 | 이전 값\n";
    //cout << "---|---|---\n";
    //for (const auto& v : vertexes)
    //{
    //    cout << v.index << " | " << v.distance << " | " << v.number_before << endl;
    //}

    cout << vertexes[size - 1].distance + 1;

}

int main()
{
    int N = 0;int M = 0;
    cin >> N >> M;


    bool** arr = new bool* [N];
    for (int i = 0; i < N ; i++)
    {
        arr[i] = new bool[M];
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            char c;
            cin >> c;

            if( c== '0' )
            {
                arr[i][j] = false;
            }
            else if( c == '1')
            {
                arr[i][j] = true;
            }
            else
            {

            }

        }
    }


    //vector<vector<int>> adj_list; // 24 
    vector<vector<int>> adj_list{ }; // 24 
    adj_list.resize(N * M);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (arr[i][j]) 
            {
                vector<int> tmp;
                tmp.push_back(i * M + j);

                if (i > 0) // top
                {
                    if (arr[i - 1][j]) { tmp.push_back((i-1)*M + j); }
                }

                if (j > 0) // left
                {
                    if (arr[i][j - 1]) { tmp.push_back(i * M + (j - 1)); }
                }

                if (j < M - 1) // left
                {
                    if (arr[i][j + 1]) { tmp.push_back(i * M + (j + 1)); }
                }

                if (i < N-1) // bottom
                {
                    if (arr[i + 1][j]) { tmp.push_back((i + 1) * M + j); }
                }

                //adj_list.push_back(tmp);
                adj_list[i * M + j] = tmp;
            }


        }
    }

    //cout << "\nAdjacency List(인접 리스트)를 만듭니다. \n";

    //for (auto list : adj_list)
    //{
    //    for (auto i : list)
    //    {
    //        cout << i << " ";
    //    }
    //    cout << "\n";
    //}
    BFS(0,  adj_list);


    for (int i = 0; i < N; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}
