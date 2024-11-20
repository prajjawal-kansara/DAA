#include <iostream>
using namespace std;

int partition(int *a, int low, int high); 
void QS(int *a, int low, int high) {
    int q;
    if (low < high) {
        q = partition(a, low, high);
        QS(a, low, q - 1);
        QS(a, q + 1, high);
    }
}

int partition(int *a, int low, int high) {
    int x = a[high];
    int i = low - 1;
    int temp;
    for (int j = low; j < high; j++) {
        if (a[j] <= x) {
            i = i + 1;
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }

    temp = a[i + 1];
    a[i + 1] = a[high];
    a[high] = temp;
    
    return i + 1;
}

int main() {
    int a[6];

    cout << "Enter the elements in the array: ";
    for (int i = 0; i < 6; i++)  {
        cin >> a[i];   
    }

    cout << "BEFORE SORTING: ";
    for (int i = 0; i < 6; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    QS(a, 0, 5);  

    cout << "AFTER SORTING: ";
    for (int i = 0; i < 6; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}