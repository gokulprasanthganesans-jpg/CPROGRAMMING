#include <stdio.h>

#define MAX 10

int adj[MAX][MAX];
int visited[MAX];
int queue[MAX];
int front = -1, rear = -1;


void enqueue(int x)
{
    queue[++rear] = x;
}

int dequeue()
{
    return queue[++front];
}


void bfs(int n, int start)
{
    int i, v;
    for (i = 0; i < n; i++)
        visited[i] = 0;

    enqueue(start);
    visited[start] = 1;

    printf("BFS Traversal: ");

    while (front != rear)
    {
        v = dequeue();
        printf("%d ", v);

        for (i = 0; i < n; i++)
        {
            if (adj[v][i] == 1 && visited[i] == 0)
            {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

void dfs(int n, int v)
{
    int i;
    visited[v] = 1;
    printf("%d ", v);

    for (i = 0; i < n; i++)
    {
        if (adj[v][i] == 1 && visited[i] == 0)
            dfs(n, i);
    }
}

int main()
{
    int n, i, j;
    int A, B, S;

    printf("Enter number of cities: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);

    printf("Enter two cities A and B: ");
    scanf("%d %d", &A, &B);

    if (adj[A][B] == 1)
        printf("Connected\n");
    else
        printf("Not Connected\n");

    printf("Enter starting vertex: ");
    scanf("%d", &S);

    bfs(n, S);

    for (i = 0; i < n; i++)
        visited[i] = 0;

    printf("DFS Traversal: ");
    dfs(n, S);
    printf("\n");

    return 0;
}