// #include <bits/stdc++.h>
// using namespace std;

// class Edge
// {
//     public:
//     long long int a, b, c;
//     Edge(long long int a, long long int b, long long int c)
//     {
//         this->a = a;
//         this->b = b;
//         this->c = c;
//     }
// };

// long long int dis[1005];

// int main()
// {
//     int n, e;
//     cin >> n >> e;
//     vector <Edge> edge_list;
//     while (e--)
//     {
//         long long int a, b, c;
//         cin >> a >> b >> c;
//         edge_list.push_back(Edge(a, b, c));
//     }

//     int src;
//     cin >> src;
//     int q;
//     cin >> q;

//     for (int i = 0; i < n; i++) dis[i] = LLONG_MAX;
//     dis[src] = 0;

//     for (int i = 0; i < n - 1; i++)
//     {
//         for (auto ed : edge_list)
//         {
//             long long int a, b, c;
//             a = ed.a;
//             b = ed.b;
//             c = ed.c;

//             if (dis[a] != LLONG_MAX && dis[a] + c < dis[b]) dis[b] = dis[a] + c;
//         }
//     }

//     bool cycle = false;
//     for (auto ed : edge_list)
//     {
//         int a, b, c;
//         a = ed.a;
//         b = ed.b;
//         c = ed.c;

//         if (dis[a] != LLONG_MAX && dis[a] + c < dis[b])
//         {
//             cycle = true;
//             break;
//         }
//     }

//     if (cycle) cout << "Negative Cycle Detected" << endl;
//     else
//     {
//         while (q--)
//         {
//             int destination;
//             cin >> destination;
//             if (dis[destination] == LLONG_MAX) cout << "Not Possible" << endl;
//             else cout << dis[destination] << endl;
//         }
//     }
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

class Edge
{
public:
    long long int a, b, c;
    Edge(long long int a, long long int b, long long int c)
    {
        this->a = a;
        this->b = b;
        this->c = c;
    }
};

long long int dis[1005];

int main()
{

    int n, e;
    cin >> n >> e;
    vector<Edge> edge_list;
    while (e--)
    {
        long long int a, b, c;
        cin >> a >> b >> c;
        edge_list.push_back(Edge(a, b, c));
    }

    int src;
    cin >> src;
    int q;
    cin >> q;

    for (int i = 1; i <= n; i++)
        dis[i] = LLONG_MAX;
    dis[src] = 0;

    for (int i = 0; i < n - 1; i++)
    {
        for (auto ed : edge_list)
        {
            long long int a, b, c;
            a = ed.a;
            b = ed.b;
            c = ed.c;

            if (dis[a] != LLONG_MAX && dis[a] + c < dis[b])
            {
                dis[b] = dis[a] + c;
            }
        }
    }

    bool cycle = false;
    for (auto ed : edge_list)
    {
        long long int a, b, c;
        a = ed.a;
        b = ed.b;
        c = ed.c;

        if (dis[a] != LLONG_MAX && dis[a] + c < dis[b])
        {
            cycle = true;
            break;
        }
    }

    if (cycle)
        cout << "Negative Cycle Detected" << endl;
    else
    {
        while (q--)
        {
            int destination;
            cin >> destination;
            if (dis[destination] == LLONG_MAX)
                cout << "Not Possible" << endl;
            else
                cout << dis[destination] << endl;
        }
    }
    return 0;
}