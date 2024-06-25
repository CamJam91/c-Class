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

void selectionSort (vector<int>& list){
	int size = list.size();
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
	//for sorting through parallel vectors all that is needed is an extra swap
void selectionSortParallels (vector<int>& list,vector<int>& parallel){
        int size = list.size()-1;
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
                swap (parallel[minIndex], parallel[start]);
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
