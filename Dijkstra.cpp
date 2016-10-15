#include <stdio.h>
#include <string.h>

#define MAX_VERTICES 17
#define Inf 10000 //���Ƿ� ū ���� ����
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
	min = Inf; // INF�� �ʱ�ȭ
	minpos = -1; // �츮�� ������� �ʴ� ���� ��ġ�� �ʱ����� ���Ƿ� -1�� �ʱ�ȭ
	for(i=0 ; i<n ; i++){
		if(distance[i] < min && !found[i]){ // �߰ߵ��� ���� �ּ� ��� �߿��� �ּ� �Ÿ� ���� �ε���
			min = distance[i];
			minpos = i;
		}
	}
	return minpos;
}
void shortestpath(int v, int cost[][MAX_VERTICES], int distance[], int n, short int found[]){
	// v�� ��� ���, cost[][]�� ��� �迭, distance[]�� ��߳�� v�� ������ �� ����� �Ÿ� �迭,
	// n�� ����� ����, found[]�� �ִ� ��� ���� �迭 
	int i, u, w;
	for(i=0 ; i<n ; i++){ // �ʱ�ȭ �����ش�. ���� ��߳��� ������� ������ Infinity
		found[i] = FALSE;
		distance[i] = cost[v][i];
	}
	found[v] = TRUE; // ��� ������ �Ÿ��� �翬�� 0�̱� ������ True
	distance[v] = 0; // �翬�� 0~
	trace[v][0] = -1; 

	for(i=0 ; i<n-2 ; i++){ // �ϴ� ��߳��� ���� ��尡 �ϳ� ������ ����
								// ���Ž����� ���� ���� ������ n-2������..
		u = choose(distance, n, found); // found ���� ���� ����߿��� �Ÿ��� ���� ����
												 // ����� �ε����� �����´�.
		found[u] = TRUE;
	
		if( trace[u][0] == 0){ // ��������� �ٷ� �´ٰ� �ľ��Ѵٸ�?
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
void show_route(int v){ 
	int temp;
	printf("%d �κ��� �ִܰ�� ã��\n", v);
	for(int i=0 ; i<MAX_VERTICES ; i++){
		printf("\n%d from to %d = %4d\n", v, i, distance[i]);
		temp = i;
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
		printf("%d" , i);
		printf("\n");
	}
}

int main(){
	int node_num = 0;
	printf("Input just one node number : ");
	scanf("%d", &node_num);
	
	shortestpath(node_num, cost, distance, MAX_VERTICES, found);
	show_route(node_num);
	return 0;
}