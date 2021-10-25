//PLEASE FINISH THE MAIN FUNCTION OF THIS PROGRAM

#include <stdio.h>
#include <stdlib.h>

#define MAXNODES 10
#define SIZE 40

typedef struct node node;
typedef struct node* nodes;
typedef struct Graph graph;
typedef struct Graph* graphs;

struct node
{
    int dest;
    node *next;
    node *head;
};


struct Graph
{
    int V;
    nodes array;
    nodes* adjLists;
    int* visited;
};

nodes newAdjListNode(int dest)
{
    nodes newNode = (nodes) malloc(sizeof(node));

    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

graphs createGraph(int v)
{
    graphs gr = (graphs) malloc(sizeof(graph));
    gr->V = v;

    gr->array = (nodes) malloc(v * sizeof(node));

    int i;
    for(i=0; i<v; ++i)
        gr->array[i].head = NULL;

    return gr;
}

void addEdge(graphs gr, int src, int dest)
{
    nodes newNode = newAdjListNode(dest);
    newNode->next = gr->array[src].head;
    gr->array[src].head = newNode;
  
}

void printGraph(graphs gr)
{
    int v;
    for(v=0; v< gr->V; ++v)
    {
        nodes pCrawl = gr->array[v].head;
        printf("\n Adjacency list of vertex %d\n head ", v);
        while(pCrawl)
        {
            printf("-> %d", pCrawl->dest);
            pCrawl = pCrawl->next;
        }
        printf("\n");
    }
}

//  BFS Algorithm starts here.....
struct queue
{
    int items[SIZE];
    int front;
    int rear;
};

typedef struct queue* qs;

qs createQueue()
{
    qs q = malloc(sizeof(struct queue));
    q->front = -1;
    q-> rear = -1;
    return q;
}

int isEmpty( qs q )
{
    if (q->rear == -1)
        return 1;
    else
        return 0;
}
void enqueue( qs q, int value)
{
    if (q->rear == SIZE-1)
        printf("\nQueue is full\n");
    else
    {
        if (q->front == -1)
            q->front = 0;
        q->rear++;
        q->items[q->rear] = value;
    }

}

int dequeue( qs q)
{
    int item;
    if (isEmpty(q))
    {
        printf("Queue is Empty");
        item = -1;
    }
    else
    {
        item = q->items[q->front];
        q->front++;
        if( q->front > q-> rear)
        {
            printf("Resetting queue");
            q->front = q->rear = -1;
        }
    }
    return item;
    
}

void printQueue(qs q)
{
    int i = q->front;

    if (isEmpty(q))
        printf("Queue is empty");
    else
    {
        printf("\nQueue contains \n");
        for( i = q->front; i < q->rear+1; i++)
            printf("%d", q->items[i]);
    }
}

void bfs(graphs dgraph, int startVertex)
{
    qs queue = createQueue();

    dgraph->visited[startVertex] = 1;
    enqueue(queue, startVertex);

    while(!isEmpty(queue))
    {
        printQueue(queue);
        int currentVertex = dequeue(queue);
        printf("Visited %d\n", currentVertex);

        nodes temp = dgraph->adjLists[currentVertex];

        while(temp)
        {
            int adjVertex = temp->dest;

            if(dgraph-> visited[adjVertex] == 0)
            {
                dgraph->visited[adjVertex] = 1;
                enqueue(queue, adjVertex);
            }
            temp = temp->next;
        }
    }

}


int main()
{
    

    graphs GR = createGraph(V);

    bfs(GR, 0);
    printGraph(GR);

    return 0;

}
