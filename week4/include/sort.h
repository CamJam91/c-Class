#include<vector>
using namespace std;
void bubbleSort (vector<float>& list, int size){
	for (int maxElement = size -1; maxElement > 0; maxElement--){
		for (int index = 0; index < maxElement; index++){
				if (list[index] > list[index + 1]){
					swap(list[index], list[index + 1]);
				}
		}
	}
}

void selectionSort (vector<float>& list, int size){
	for (int start = 0; start < (size - 1); start++){
		int minIndex = start;
		float minValue = list[start];
		for (int index = start + 1; index < size; index++){
			if (list[index] < minValue){
				minValue = list[index];
				minIndex = index;
			}
		}
		swap (list[minIndex], list[start]);
	}
}

void selectionSort (float* listPtr, int size){
	for (int start = 0; start < (size - 1); start++){
		int minIndex = start;
		float minValue = *(listPtr + start);
		for (int index = start + 1; index < size; index++){
			if (*(listPtr + index) < minValue){
				minValue = *(listPtr + index);
				minIndex = index;
			}
		}
		swap (*(listPtr + minIndex), *(listPtr + start));
	}
}
void swap (float& a, float& b){
	float temp = a;
	a = b;
	b = temp;
}
