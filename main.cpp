#include <random>
#include <vector>
#include <iostream>
#include <iomanip>

#include "kruskal.hpp"

int main(int argc, char *argv[])
{
    
    int n = atoi(argv[1]);
    int n_iter = atoi(argv[2]);

    std::mt19937 mt;
    std::uniform_real_distribution<> dist(0.0, 1.0);

    for (int i=0; i<n_iter; i++)
    {
        // create edges
        std::vector<Edge> edges;
        for(int u=0; u<n; u++)
        {
            for (int v=u+1; v<n; v++)
            {
                double cost = dist(mt);
                Edge e = {u, v, cost};
                edges.push_back(e);
            }
        }
        // calculate MST
        Kruskal krs(n, edges);

        //output
        std::cout << std::fixed << std::setprecision(15) << krs.sum << std::endl;
    }
}