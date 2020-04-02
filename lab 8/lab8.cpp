//lab 8
#include<iostream>
#include<fstream>
#include<ctime>
using namespace std;

void swap(int *xp, int *yp){
    int tmp = *xp;
    *xp = *yp;
    *yp = tmp;
}
void bubbleSort(int arr[], int n){
    int i,j;
    bool swapped;

    for (i=0; i < n-1; i++) {
        swapped = false;
        for (j=0; j < n-i-1; j++){
            if (arr[j] > arr[j+1]){
                swap(&arr[j], &arr[j+1]);
                swapped = true;
            }
        }
        if (swapped == false) break;
    }
}

void selectionSort(int arr[], int n) {
    int i, j, min;
    for (i=0; i<n-1; i++){
        min = i;
        for (j=i+1;j<n; j++){
            if(arr[j] < arr[min]){
                swap(&arr[j],&arr[min]);
            }
        }
    }
}

//incorrect - 
void insertionSort(int arr[], int n) {
    int i;
    for(int i=1; i<n; i++){
        if(arr[i] < arr[i-1]){
            swap(&arr[i],&arr[i-1]);
        }
    }
}

int main() {
    ofstream fout;
    int arr[100];
    fout.open("file.txt");

    srand(time(NULL));
    
    if (fout.is_open()){
        for(int i=0;i<100;i++){
            int tmpvar;
            tmpvar = rand()%1000;
            arr[i]=tmpvar;
            fout << tmpvar << endl;
            // output 100
        }
    }
    fout.close();

    ofstream fout2;
    fout2.open("file2.txt");
    
    if (fout2.is_open()){
        for(int i=0; i<100; i++){
            fout2 << arr[i]*arr[i] << endl;
        } 
    }
    fout2.close();

    int tmparr[100];
    for(int i=0; i<100;i++){
        cout << arr[i] << endl;
        tmparr[i] = arr[i];
    }
    
    ofstream fout3;
    fout3.open("file3.txt");

    if (fout3.is_open()){
        // selectionSort(tmparr,100);
        bubbleSort(tmparr,100);
        for(int i=0;i<100;i++){
            fout3 << tmparr[i] << ":" <<arr[i] << endl;
        }
    }

    fout3.close();

    return 0;
}