#include <stdio.h>
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int get_edge(int* graph, int row, int column, int width) // width is always just the number of edges
{
    return graph[row + column*width];
}

void set_edge_value(int* graph, int row, int column, int width, int edge_value) // same here, width is always just the number of edges
{
    graph[row + column*width];
}

string convert_to_str(int x)
{
    char buffer [100];
    char *xSTR = itoa(x, buffer, 10);
    return string(xSTR);
}

int main()
{
    int height;
    int width;
    int* graph = new int[height*width];
    cout << "How many edges will your graph have? ";
    int number_of_edges;
    cin >> number_of_edges;
    height = number_of_edges;
    width = number_of_edges;
    string matrix_representation = "";
    int edge_value;
    for(int i = 0; i < number_of_edges; i++) // Iterate through columns
    {
        for(int j = 0; j < number_of_edges; j++) //Iterate through rows (this is not a mistake, i inverted it)
        {
            if(i == j) // If it's the same then just set it as zero cause edges can't be adjacent to themselves
            {
                edge_value = 0;
                set_edge_value(graph, i, j, number_of_edges, 0);
            }
            else
            {
                if((i-j) % 2 == 0) // statement can be modified to make different kinds of graphs
                {
                    edge_value = 1;
                    set_edge_value(graph, i, j, number_of_edges, 1);
                }
                else
                {
                    edge_value = 2;
                    set_edge_value(graph, i, j, number_of_edges, 2);
                }
            }
            cout << "i = " << i << ", j = " << j << "\n";
            if(j == number_of_edges-1) // If it's at the end of a row then make new line and end bracket
            {
                matrix_representation += convert_to_str(edge_value) + "]\n";
            }
            else
            {
                if(j == 0) // If it's at the start of a row then start new bracket
                {
                    matrix_representation += "[" + convert_to_str(edge_value) + ", ";
                }
                if(j != 0) // If it's not at the start nor at the end of a row then just add number normally
                {
                    matrix_representation += convert_to_str(edge_value) + ", ";
                }
            }
        }
    }
    cout << matrix_representation;
}
