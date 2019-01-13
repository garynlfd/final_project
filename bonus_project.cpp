#include <iostream>
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;
#define INF 0x3f3f3f3f
typedef pair<city, city> bridge;

class city
{
public:
    string name;
    int h_credit;
    int open_t;
    int close_t;
};

class Map
{
    int V;
    int t_time, s_time;
    list<bridge> *adj;
public:
    Map(int V, int t_tome, int s_time)
    {
        this->V = V;
        this->t_time = t_time;
        this->s_time = s_time;
        adj = new list<bridge> [V];
    }
    void addEdge(city u, city v, int w)
    {
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }
    void shortestPath(int src);
};

int main(int argc, const char *argv[]) {
    std::string file = "./";
    std::string studentID = argv[1];
    std::string fileinput = file + studentID + "/tp.data";
    std::string fileoutput = file + studentID + "/ans1.txt";
    std::ifstream input;
    std::ofstream output;
    input.open(fileinput.c_str());
    if(input)
    {
        int nodes, edges, t_time, s_time;
        input >> nodes >> edges >> t_time >> s_time;
        city *a = new city[nodes];
        city city1, city2;
        int distance, k, m;
        Map m(nodes, t_time, s_time);
        for(int i = 0; i < nodes; ++i)
        {
            input >> a[i].name >> a[i].h_credit >> a[i].open_t >> a[i].close_t;
        }
        for(int j = 0; j < edges; ++j)
        {
            input >> city1 >> city2 >> distance;
            for(k = 0; k < nodes; ++k)
            {
                if(a[k].name == city1.name) break;
            }
            for(m = 0; m < nodes; ++m)
            {
                if(a[m].name == city2.name) break;
            }
            addEdge(a[k], a[m], distance);
        }
        output.open(fileoutput.c_str());
        std::vector<FloorCleaner::Cell> path = robot->CleaningPath();
        output << robot->TotalSteps() << std::endl;
        output.close();
        input.close();
    }
    else std::cerr << "failed to open \"floor.data\"" << std::endl;
    return 0;
}
