#include<iostream>
using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[],int n,int i){
    int largest = i;
    int left = 2*i;
    int right = 2*i+1;

    if(left<=n && arr[largest] < arr[left]){
        largest = left;
    }
    if(right<=n && arr[largest] < arr[right]){
        largest = right;
    }

    if(largest != i){
        swap(&arr[largest],&arr[i]);
        heapify(arr,n,largest);
    }

}

void make_heap(int arr[],int n){
    for(int i=n/2;i>=1;i--){
        heapify(arr,n,i);
    }
}

int main() {
    int n, i, a[10], ch;
    for (;;) {
        cout << "\n 1. Create Heap\n 2. Extractmax\n 3. Exit\n Read Choice :";
        cin >> ch;
        switch (ch) {
            case 1:
                cout << "\n Read no of elements :";
                cin >> n;
                cout << "\n Read Elements\n";
                for (i = 1; i <= n; i++)
                    cin >> a[i];
                make_heap(a, n);
                cout << "\n Elements after heap\n";
                for (i = 1; i <= n; i++)
                    cout << a[i] << "\t";
                break;
            case 2:
                if (n >= 1) {
                    cout << "\n Element deleted is " << a[1] << "\n";
                    a[1] = a[n];
                    n = n - 1;
                   make_heap(a, n);
                    if (n != 0) {
                        cout << "\n Elements after reconstructing heap\n";
                        for (i = 1; i <= n; i++)
                            cout << a[i] << "\t";
                    }
                } else
                    cout << "\n No element to delete";
                break;
            default:
                exit(0);
        }
    }
    return 0;
}