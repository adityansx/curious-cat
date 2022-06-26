// #include <iostream>

// using namespace std;

void bubbleSort(int* arr, int size) {
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size - 1; j++) {
            if(*(arr + j) > *(arr + j + 1)) {
                int temp = *(arr + j);
                *(arr + j) = *(arr + j + 1);
                *(arr + j + 1) = temp;
            }
        }
    }
}

// int main() {
//     int a[] = {4, 3, 2, 1, 0};

//     bubbleSort(a, (sizeof(a) / sizeof(int)));

//     for(int i: a) {
//         cout << i << " ";
//     }

//     cout << endl;

//     return 0;
// }