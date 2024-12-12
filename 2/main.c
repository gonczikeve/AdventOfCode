#include <stdio.h>

int is_safe(const int * arr, const int len){
	int i = 0;
	// is increasing?
	while(arr[i + 1] - arr[i] >= 1 && arr[i + 1] - arr[i] <=3){
		i++;
		if ( i == len-1){
			return 1;
		}
	}
	i = 0;
	// is decreasing?
	while (arr[i] - arr[i + 1] >= 1 && arr[i] - arr[i + 1] <=3){
		i++;
		if ( i == len-1){
			return 1;
		}		
	}
	
	return 0;
}

int is_safe_dampener(const int * arr, const int len){
	// int i = 0;
	// is increasing?
	
	int problem_dampened = 0;
	for(int i = 0; i<len; i++){
		if(!(arr[i + 1] - arr[i] >= 1 && arr[i + 1] - arr[i] <=3)){
			if(!problem_dampened){
				problem_dampened = 1;
			else{
				return 0;
			}
		}
	}
	problem_dampened = 0;
	// is decreasing?
	for(int i=0; i<len; i++){
	
		if(arr[i] - arr[i + 1] >= 1 && arr[i] - arr[i + 1] <=3){
			if(!problem_dampened){
				problem_dampened = 1;
			else{
				return 0;
			}
		}
	}
	return 1;
}

int parse_line(int * arr, int * len, FILE * file){

	int c, i, number = 0;
	*len = 0;
	while(1){
		c = fgetc(file);
		if ((char)c == ' '){
			arr[(*len)++] = number;
			number = 0;
		}
		else if((char)c == '\n'){
			arr[(*len)++] = number;
			return 0;
		}
		else if((char)c == EOF){
			arr[(*len)++] = number;
			return 1;
		}
		else{
			number = 10 * number + c - 48; // 48 for ascii lmao
;
		}
	}
}


int main(void){
	FILE * input = fopen("input.txt","r");
	int len;
	int arr[50];
	int safe_count = 0;
	int end_reached = 0;

	while(!end_reached){
		end_reached = parse_line(arr, &len, input);
		//printf("line ");
		//for (int i = 0; i<len; i++){
		//	printf("%d ", arr[i]);
		//}
		//printf("\n");
		safe_count += is_safe(arr, len);
	}
	
	printf("result %d", safe_count);
	
	fclose(input);
	return 0;
}