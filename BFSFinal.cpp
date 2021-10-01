#include<iostream>
#include<iterator>
#include<list>
#include<vector>

using namespace std;

class Graph//adjacency list representation
{
    int numberVertices;
    list<int> *adj;

public:

    Graph(int numberVertices); //Constructor(Initializes the members in the private view)

    void addEdge(int v, int c); //adding an edge to the graph

    void BFS(int n); //prints the BFS traversal from a given source s



};

Graph::Graph(int v)
{
    this->numberVertices = numberVertices;

    adj = new list<int>[numberVertices];
}

void Graph::addEdge(int v, int c)
{
    adj[v].push_back(c);// Adding c to v's list(pushing back the one at the end and increasing the size of the list)
}

void Graph::BFS(int n)
{
    bool *visited = new bool[numberVertices];

    for(int i=0; i<numberVertices; i++)//marking all the vertices as not visited
        visited[i] = false;

        list<int> queue;//create a queue for BFS

        visited[n] = true; //marking the current node as visited and enqueue it
        queue.push_back(n);

        list<int>::iterator i;

        while(!queue.empty())
        {
            n = queue.front();//dequeue a vertex from queue and print it
            cout<< n <<" ";
            queue.pop_front();
        

        for(i = adj[n].begin(); i != adj[n].end(); ++i)//get all the adjacent vertices of the dequeued vertex n. If a adjacent has not been visited, mark it as visited and enqueue it.
        {
            if(!visited[*i])
            {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }    
}

int main()
{
    int a;
    int n1,n2;

    cout<<"Enter the total number of vertices";
    cin>>a;
    
    Graph g(a);

    for(int b=0; b<a; b++)
        {
            n1=0;
            n2=0;
            cout<<"Enter two numbers";
            cin>>n1>>n2;

            g.addEdge(n1,n2);
        }
    cout<<"Following is Breadth First Traversal "
        <<"(starting from vertex 2) \n";

    g.BFS(0);

    return 0;     

}