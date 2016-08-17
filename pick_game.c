#include<stdio.h>

struct queue{
	int data[10000];
	int head;
	int tail;
};

struct stack{
	int data[10];
	int top;
};

int main()
{
	struct queue q1,q2;
	struct stack s;
	int book[10];
	int i,t;

	q1.head = 1; q1.tail = 1;
	q2.head = 1; q2.tail = 1;
	
	s.top = 0;
	
	for(i = 0; i < 10; i++){
		book[i] = 0;
	}
	
	printf("input 6 number for A1\n");
	for(i = 1; i <= 6; i++){
		scanf("%d", &q1.data[q1.tail]);
		q1.tail++;
	}

	printf("intput 6 number for B2\n");
	for(i = 1; i <= 6; i++ ){
		scanf("%d", &q2.data[q2.tail]);
		q2.tail++;
	}

	while(q1.head < q1.tail && q2.head < q2.tail){
		
		t = q1.data[q1.head];
		if(book[t] == 0){
			q1.head++;
			s.top++;
			s.data[s.top] = t;
			book[t] = 1;
		}else{
			q1.head++;
			q1.data[q1.tail] = t;
			q1.tail++;
			while(s.data[s.top] != t){
				book[s.data[s.top]] = 0;
				q1.data[q1.tail] = s.data[s.top];
				s.top--;
			}
			q1.data[q1.tail] = s.data[s.top];
			s.top--;
			book[t] = 0;
		}
		printf("A1 put %d\n", t);
		printf("cards in A1 hands:\t");
		for(i = q1.head; i < q1.tail; i++){
			printf("%d\t", q1.data[i]);
		}
		printf("\n");
		printf("cards in B2 hands:\t");
		for(i = q2.head; i < q2.tail; i++){
			printf("%d\t", q2.data[i]);
		}
		printf("\n");
		printf("cards on the desk:\t");
		for(i = s.top; i > 0; i--){
			printf("%d\t", s.data[i]);
		}
		printf("\n");

		t = q2.data[q2.head];
		if(book[t] == 0){
			q2.head++;
			s.top++;
			s.data[s.top] = t;
			book[t] = 1;
		}else{
			q2.head++;
			q2.data[q2.tail] = t;
			q2.tail++;
			while(s.data[s.top] != t){
				book[s.data[s.top]] = 0;
				q2.data[q2.tail] = s.data[s.top];
				s.top--;
			}	
			q2.data[q2.tail] = s.data[s.top];
			s.top--;
			book[t] = 0;
		}
		
		printf("B2 put %d\n", t);
		printf("cards in A1 hands:\t");
		for(i = q1.head; i < q1.tail; i++){
			printf("%d\t", q1.data[i]);
		}
		printf("\n");
		printf("cards in B2 hands:\t");
		for(i = q2.head; i < q2.tail; i++){
			printf("%d\t", q2.data[i]);
		}
		printf("\n");
		printf("cards on the desk:\t");
		for(i = s.top; i > 0; i--){
			printf("%d\t", s.data[i]);
		}
		printf("\n");

	}

	if(q2.head == q2.tail){
		printf("A1 win\n");
	}else{
		printf("B2 win\n");
	}
}
