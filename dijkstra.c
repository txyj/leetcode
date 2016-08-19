//dijkstra core lines


for(i = 1; i < n-1; i++){
	//find the nearest vode from source
	min = inf;
	for(j = 1; j <= n; j++){
		if(book[j] == 0 && dis[j] < min){
			min = dis[j];
			u = j;
		}
	}
	book[u] = 1;

	//update
	for(v = 1; v <= n; v++){
		if(e[u][v] < inf){
			if(dis[v] > dis[u] + e[u][v])
				dis[v] = dis[u] + e[u][v];
		}
	}
}
