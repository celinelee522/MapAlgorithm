#include <stdio.h>
#include <string.h>

#define MAX_VERTICES 17
#define Inf 10000
#define Zero 0
#define TRUE 1
#define FALSE 0

int cost[MAX_VERTICES][MAX_VERTICES] = {
        {0,13,Inf,Inf,Inf,Inf,Inf,Inf,Inf,Inf,Inf,Inf,Inf,Inf,Inf,Inf,Inf},//0
        {13,0,Inf,Inf,Inf,Inf,Inf,Inf,Inf,Inf,Inf,Inf,7,Inf,Inf,Inf,Inf},//1
        {Inf,Inf,0,Inf,Inf,Inf,Inf,Inf,Inf,Inf,Inf,Inf,10,Inf,Inf,Inf,12},//2
        {Inf,Inf,Inf,0,Inf,Inf,Inf,Inf,Inf,Inf,Inf,Inf,Inf,Inf,Inf,Inf,10},//3
        {Inf,Inf,Inf,Inf,0,Inf,Inf,Inf,Inf,Inf,Inf,Inf,Inf,Inf,12,Inf,Inf},//4
        {Inf,Inf,Inf,Inf,Inf,0,Inf,Inf,Inf,Inf,Inf,Inf,Inf,Inf,4,Inf,Inf},//5
        {Inf,Inf,Inf,Inf,Inf,Inf,0,Inf,Inf,Inf,Inf,Inf,Inf,Inf,Inf,4,Inf},//6
        {Inf,Inf,Inf,Inf,Inf,Inf,Inf,0,2,Inf,Inf,Inf,Inf,Inf,Inf,Inf,Inf},//7
        {Inf,Inf,Inf,Inf,Inf,Inf,Inf,2,0,8,Inf,Inf,Inf,Inf,Inf,6,Inf},//8
        {Inf,Inf,Inf,Inf,Inf,Inf,Inf,Inf,8,0,5,Inf,Inf,Inf,Inf,Inf,Inf},//9
        {Inf,Inf,Inf,Inf,Inf,Inf,Inf,Inf,Inf,5,0,6,Inf,Inf,Inf,Inf,Inf},//10
        {Inf,Inf,Inf,Inf,Inf,Inf,Inf,Inf,Inf,Inf,6,0,4,Inf,Inf,Inf,Inf},//11
        {Inf,7,10,Inf,Inf,Inf,Inf,Inf,Inf,Inf,Inf,4,0,5,Inf,Inf,Inf},//12
        {Inf,Inf,Inf,Inf,Inf,Inf,Inf,Inf,Inf,Inf,Inf,Inf,5,0,4,Inf,2},//13
        {Inf,Inf,Inf,Inf,12,4,Inf,Inf,Inf,Inf,Inf,Inf,Inf,4,0,7,Inf},//14
        {Inf,Inf,Inf,Inf,Inf,Inf,4, Inf,6,Inf,Inf,Inf,Inf,Inf,7,0,Inf},//15
        {Inf,Inf,12,10,Inf,Inf,Inf,Inf,Inf,Inf,Inf,Inf,Inf,2,Inf,Inf,0},//16
};

int distance[MAX_VERTICES];
short int found[MAX_VERTICES];
char trace[MAX_VERTICES][1];

int choose(int distance[], int n, short int found[]){
    int i, min, minpos;
    min = Inf; // initialize
    minpos = -1; // �츮�� ������� �ʴ� ���� ��ġ�� �ʱ����� ���Ƿ� -1�� �ʱ�ȭ
    for(i=0 ; i<n ; i++){
        if(distance[i] < min && !found[i]){ // minimum distance index among unchecked routes
            min = distance[i];
            minpos = i;
        }
    }
    return minpos;
}
void shortestpath(int v, int cost[][MAX_VERTICES], int distance[], int n, short int found[]){
    // v : start node, cost[][] : cost array, distance[] : array of each distance from v
    // n : number of nodes, found[] : if the shortest path is computed(Bool)
    int i, u, w;
    for(i=0 ; i<n ; i++){ // initialize, if not connected to v, initialize as Infinity
        found[i] = FALSE;
        distance[i] = cost[v][i];
    }
    found[v] = TRUE; // distance from v is obviously 0, so TRUE
    distance[v] = 0; // obvious
    trace[v][0] = -1;

    for(i=0 ; i<n-2 ; i++){ //  when one node is left except node v,
        // no need to update. that makes n-2
        u = choose(distance, n, found);
        // get the index of shortest distance among unchecked nodes
        found[u] = TRUE;

        if( trace[u][0] == 0){ // suppose it directly
            trace[u][0] = v;
        }

        for(w=0 ; w<n ; w++){
            if(!found[w]){ // ã������ ���� �� �߿���...
                if(distance[u] + cost[u][w] < distance[w]){ // ���� ������ �Ÿ� ���� ���ؼ�
                    // ���� ���� ������ �ּ� �Ÿ� �� ����
                    distance[w] = distance[u] + cost[u][w];
                    trace[w][0] = u;
                }
            }
        }
    }
}
void show_route(int v, int target){
    int temp;
    printf("shotest path from %d to %d\n", v, target);
        printf("\nfrom %d to %d = %4d\n", v, target, distance[target]);
        temp = target;
        int reverse[MAX_VERTICES] = {0};
        int cnt = MAX_VERTICES;
        while(temp != -1){
            temp = trace[temp][0];
            if( temp != -1)
                reverse[--cnt]= temp;
        }
        for(int j=0 ; j<MAX_VERTICES ; j++){
            if(reverse[j] != 0)
                printf("%d -> " , reverse[j]);
        }
        printf("%d" , target);
        printf("\n");
}

int main(){

    int start_node = 0, target_node = 0;

    printf("Input start node number : ");
    scanf("%d", &start_node);

    printf("\nInput target node number : ");
    scanf("%d", &target_node);

    shortestpath(start_node, cost, distance, MAX_VERTICES, found);
    show_route(start_node, target_node);
    return 0;
}