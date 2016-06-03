#include <iostream>

using namespace std;

void swap(int& a, int& b){
	int tmp;
	tmp = a;
	a = b;
	b = tmp;
}

void stupidSort(int* array, int len, int& count){
	int i = 0;
	while (i < len - 1){
		count++;
		if (array[i] < array[i+1]){
			swap(array[i], array[i+1]);
			i = 0;
		}
		else{
			i++;
		}
	}
}

void bubbleSort(int* array, int len, int& count){
	for (int i = 0; i < len - 1; i++){
		for (int j = 0; j < len - i - 1; j++){
			count++;
			if (array[j] < array[j+1]){
				swap(array[j], array[j+1]);
			}
		}
	}
}

void shakerSort(int* array, int len, int& count){
	int leftIndex = 0;
	int rightIndex = len - 1;
	while (leftIndex < rightIndex){
		for (int i = leftIndex; i < rightIndex; i++){
			count++;
			if (array[i] < array[i+1]){
				swap(array[i], array[i+1]);
			}
		}
		rightIndex--;
		for (int i = rightIndex; i > leftIndex; i--){
			count++;
			if (array[i] > array[i-1]){
				swap(array[i], array[i-1]);
			}
		}
		leftIndex++;
	}
}

void oddEvenSort(int* array, int len, int& count){
	for (int i = 0; i < len; i++){
		for (int j = (i % 2) ? 0 : 1; j < len - 1; j += 2){
			count++;
			if (array[i] < array[i+1]){
				swap(array[i], array[i+1]);
			}
		}
	}
}

void combSort(int* array, int len, int& count){
	double factor = 1.2473309;
	int step = len - 1;
	while (step > 1){
		for (int i = 0; i + step < len; i++){
			count++;
			if (array[i] < array[i+step]){
				swap(array[i], array[i+step]);
			}
		}
		step /= factor;
	}
	for (int j = 0; j < len - 1; j++){
		count++;
		if (array[j] < array[j+1]){
			swap(array[j], array[j+1]);
		}
	}
}

void gnomeSort(int* array, int len, int& count){
	int i = 0;
	int j = 1;
	while (i < len - 1){
		count++;
		if (array[i] < array[i+1]){
			swap(array[i], array[i+1]);
			i--;
			if (i == -1){
				i = j;
				j++;
			}
		}
		else{
			i = j;
			j++;
		}
	}
}

void insertSort(int* array, int len, int& count){
	int key;
	int j;
	for (int i = 1; i < len; i++){
		key = array[i];
		j = i - 1;
		while (j >= 0 && array[j] < key){
			count++;
			array[j+1] = array[j];
			j--;
		}
		array[j+1] = key;
	}
}

void selectSort(int* array, int len, int& count){
	int max_id;
	for (int i = 0; i < len - 1; i++){
		max_id = i;
		for (int j = i + 1; j < len; j++){
			count++;
			if (array[max_id] < array[j]){
				max_id = j;
			}
		}
		if (max_id != i){
			swap(array[i],array[max_id]);
		}
	}
}


void printArray(int* array, int len, int count){
	cout << "Count of compares: " << count << endl;
	for (int i = 0; i < len; i++)
		cout << "[" << i << "] " << array[i] << endl;
}

void main(){
	int array[10] = {0,9,8,3,6,4,7,5,2,1};
	int count = 0;
	selectSort(array, 10, count);
	printArray(array, 10, count);
	system("pause");
}