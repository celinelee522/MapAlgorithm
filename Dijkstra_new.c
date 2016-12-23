#include<stdio.h>
#include<math.h>
#include<malloc.h>

#define MAX_VERTICES 101 // Set maximum number of vertices
#define INF 10000.0 // Set arbitrary infinite number
#define NON -1
#define TRUE 1

// Structure for a heap V-S ans a set S

typedef struct setNode HeapNode;
typedef struct setNode SetNode;
typedef HeapNode Heap;
typedef SetNode Set;

struct setNode {
	int vertex;
	double best;
	int prev_vertex;
};

// Node structure for a adjacent liked list
typedef struct Node *PtrToNode;
typedef PtrToNode Vertex;
typedef struct listHead *List;
struct Node{
	int adjNode;
	double cost;
	PtrToNode Next;
};
struct listHead{
	PtrToNode head;
};



/****Collection of global variables****/
Heap VS_heap[MAX_VERTICES]; int itrHeap = 0; // Variable to check the number of nodes in a heap
Set S[MAX_VERTICES]; int itrS = 1; // Final Path and Best
int Vertices[MAX_VERTICES]; // Data about node coordinate x, y
List AdjList[MAX_VERTICES]; // A linked list to store adjacent vertices
int Previous[MAX_VERTICES]; // An array to store previous
double Best[MAX_VERTICES]; // An array to stroe minimum cost
int Visited[MAX_VERTICES]; // An array to check visited Node




/****Collection of Functions****/
int IsEmpty(List L);
void Insert(List adj_list, int index, double dist);
List Make_list();
void Build_adjList(); // Add each other nodes whose distance between (x1,y1) and (x2, y2) is the same or below 13
void Init_adjList(); // Initialize adjacent list
void Init_Vertices(); // Calculate y-coordinate and initialize it
double sumOfCost(List adj_list); // Sum all of the cost in the node linked wiht the list
void Print_adjList(List adj_list);

void Insert_heap(HeapNode vertex);
HeapNode getMin_heap();
int Search_heap(int vertex); // Find an index whoes vertex element is the same with an input parametre.
void Build_heap(int st_vertex);
void Init_Best();
void Show_path(int st_vertex, int end_vertex);



/****Main function****/
int main(){
	int i, stVertex, endVertex=0;
	int select=0;
	HeapNode H_node;
	HeapNode* tmpNode = (HeapNode*) malloc(sizeof(struct setNode));
	PtrToNode tmpList = (PtrToNode) malloc(sizeof(struct Node));

	printf("----------------------------------------------NOTICE----------------------------------------------\n");
	printf(" This program is originally to show a path from a start node to an end node which you would enter.\n");
	printf("If you want to get all paths from an arbitrary vertex, please enter -1 at the end node position. (ex 74 -1 ) \n");
	printf("If not, please just enter generally like 'start_node end_node' (ex. 23 49)\n");
	printf("--------------------------------------------------------------------------------------------------\n\n");

	while(TRUE){
		printf("Input a start vertex and end vertex: ");
		scanf("%d %d", &stVertex, &endVertex);
		if(stVertex<MAX_VERTICES && stVertex > 0 && endVertex<MAX_VERTICES && endVertex >=-1)
				break;
		else
			printf("You entered worng point. Please input again(0<v<=100).\n");
		fflush(stdin); // Clear the buffer.
		printf("\n");
	}

	Init_Vertices();  // Build set of nodes
	Init_adjList(); // Initialize adjacent list
	Build_adjList(); // Build adjacent lists
	Init_Best();


	H_node.vertex = stVertex;
	H_node.best = 0;
	H_node.prev_vertex = -1;
	Best[H_node.vertex] = H_node.best;
	Insert_heap(H_node);
	Build_heap(stVertex);


	//Implemetation of Dijkstra's algorithm
	while(itrS < MAX_VERTICES){
		S[itrS] = getMin_heap();
		Visited[(S[itrS]).vertex] = 1;

		tmpList = AdjList[((S[itrS]).vertex)]->head;
		while(TRUE) {
			if(Visited[tmpList->adjNode] == 0 && Best[((S[itrS]).vertex)] + tmpList->cost < Best[tmpList->adjNode]) {
				Best[tmpList->adjNode] =  Best[((S[itrS]).vertex)] + tmpList->cost;

				tmpNode =&VS_heap[Search_heap(tmpList->adjNode)]; //Update new information
				tmpNode->best = Best[tmpList->adjNode];
				tmpNode->prev_vertex = (S[itrS]).vertex;
				Previous[tmpList->adjNode] = S[itrS].vertex;
				}
			if(tmpList->Next == NULL)
				break;
			tmpList = tmpList->Next;
		}
		itrS++;
	}

	//Print part.
	if(endVertex == -1){ // When you want to see all paths,
		for(i=1; i<MAX_VERTICES;i++)
			Show_path(stVertex, i);
	}
	else
		Show_path(stVertex, endVertex); // Just want to see a path


	return 0;
}




/****Functions****/
int IsEmpty(List L){
	return L->head == NULL;
}
void Insert(List adj_list, int index, double dist) {
	Vertex tmpNode = (Vertex) malloc(sizeof(struct Node));
	PtrToNode tmpList = (PtrToNode) malloc(sizeof(struct Node));

	tmpList->adjNode = -1;
	tmpList->cost = -1;
	tmpList->Next =NULL;


	if(IsEmpty(adj_list)) { // If adjacent list does not have any node
		tmpNode->adjNode = index;
		tmpNode->cost = dist;
		tmpNode->Next = NULL;
		adj_list->head = tmpNode;
	}
	else { // If adjacent list has some nodes
		tmpList = adj_list->head;

	while(1){ //Go to the end of list
		if(tmpList->Next ==NULL)
			break;
		tmpList = tmpList->Next;

	}
		tmpNode->adjNode = index;
		tmpNode->cost = dist;
		tmpNode->Next = NULL;
		tmpList->Next = tmpNode;
	}
}
List Make_list(){ //Create list
	List L = (List) malloc(sizeof(struct listHead));
    if(L==NULL)
        printf("Node could not be created\n");
    L->head = NULL;
	return L;
}
void Build_adjList() { // Add each other nodes whose distance between (x1,y1) and (x2, y2) is the same or below 13
	int x1, x2, y1, y2;
	double res_dist;

	for(x1=1 ; x1<MAX_VERTICES ; x1++){
		y1 = Vertices[x1];
		for(x2=x1+1 ; x2<MAX_VERTICES ; x2++){
			y2 = Vertices[x2];
			res_dist = sqrt((double)((x1-x2)*(x1-x2))+ (double)((y1-y2)*(y1-y2)));
			if(res_dist>0 && res_dist<=13) {
				Insert(AdjList[x1], x2, res_dist);
				Insert(AdjList[x2], x1, res_dist);
			}
		}
	}
}
void Init_adjList(){
	int i;
	for(i=0; i<MAX_VERTICES;i++)
		AdjList[i] = Make_list();
}
void Init_Vertices(){
	int i;
	for(i=1; i<MAX_VERTICES ; i++){
		Vertices[i] = (i*i) % 100;
	}
}
double sumOfCost(List adj_list){ // Calculate sum of costs in an adjacent list
	double sum = 0;
	PtrToNode tmpList =  (PtrToNode) malloc(sizeof(struct Node));
	tmpList = adj_list->head;

	if( tmpList == NULL)
		printf("The vertex is not connected with any other vertices\n");
	else {
		while(1){
			sum += tmpList->cost;
			if(tmpList->Next==NULL)
				break;

			tmpList = tmpList->Next;
		}
	}
	return sum;
}
void Print_adjList(List adj_list) { // Print elements of an adjacent list.
	PtrToNode tmpList = (PtrToNode) malloc(sizeof(struct Node));
	tmpList = adj_list -> head;
	while(1){
		printf(" (%d / %.3f) ", tmpList->adjNode, tmpList->cost);
		if(tmpList->Next==NULL)
			break;

		tmpList = tmpList->Next;
	}
}


void Insert_heap(HeapNode vertex){
	int last = ++itrHeap;

	int cur = itrHeap;
	int parent = cur/2;

	VS_heap[last] = vertex;

	while( VS_heap[parent].best > VS_heap[cur].best){
		VS_heap[cur] = VS_heap[parent];
		cur /=2;
	}
	VS_heap[cur] = vertex;
}
HeapNode getMin_heap(){
	int i;
	int min_index=1;
	HeapNode tmpNode;
	for(i=1; i<=itrHeap ; i++) {
		if(VS_heap[min_index].best > VS_heap[i].best)
			min_index = i;
	}
	tmpNode = VS_heap[min_index];
	VS_heap[min_index].best = INF;
	return tmpNode;
}
void Init_Best(){
	int i;
	for(i=0;i<MAX_VERTICES;i++)
		Best[i] =INF;
}
int Search_heap(int vertex){ // Find an index whoes vertex element is the same with an input parametre.
	int i;
	for(i= 1; i < MAX_VERTICES ; i++)
		if(VS_heap[i].vertex == vertex )
			return i;
}
void Build_heap(int st_vertex){ // Build heap
	int i;
	HeapNode tmpNode;

	for(i=1; i<MAX_VERTICES ; i++){
		if(i == st_vertex)
			continue;
		tmpNode.vertex = i;
		tmpNode.best = INF;
		tmpNode.prev_vertex = -1;
		Insert_heap(tmpNode);
	}
}
void Show_path(int st_vertex, int end_vertex){
	int tmp, i;
	int backtrace[MAX_VERTICES];

	for(i=0; i<MAX_VERTICES ; i++)
		backtrace[i] = NULL;

	i=0;
	if(Best[end_vertex] ==INF)
		printf("There does not exist a path from %d to %d\n", st_vertex, end_vertex);
	else {
		printf("\nThe cost from node %d to node %d is %.3f\n", st_vertex, end_vertex, Best[end_vertex]);

		if(st_vertex != end_vertex) {
			tmp = end_vertex;
			backtrace[i] = tmp;

			while( tmp != st_vertex ){
				tmp = Previous[tmp];
				backtrace[++i] = tmp;
			}

			printf("The path is ");
			while(backtrace[i] != NULL && backtrace[i] <INF && backtrace[i]>0)	{
				printf("%d", backtrace[i--]);
				if(backtrace[i+1] == end_vertex)
					break;
				else
					printf(" -> ");
			}
			printf("\n");
		}
	}
}

