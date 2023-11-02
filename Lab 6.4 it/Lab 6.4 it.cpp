#include <iostream>
#include <cmath>

void createArray(double* arr, int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = 1.0 * rand() / RAND_MAX * 200 - 100; 
    }
}

void printArray(const double* arr, int n) {
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int findMinIndex(const double* arr, int n) {
    int minIndex = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[minIndex]) {
            minIndex = i;
        }
    }
    return minIndex;
}

double sumNegatives(const double* arr, int n) {
    double sum = 0;
    int firstNegIndex = -1;

    for (int i = 0; i < n; i++) {
        if (arr[i] < 0) {
            if (firstNegIndex == -1) {
                firstNegIndex = i;
            }
            else {
                for (int j = firstNegIndex + 1; j < i; j++) {
                    sum += arr[j];
                }
                break;
            }
        }
    }

    return sum;
}

void transformArray(double* arr, int n) {
    int positiveIndex = 0;
    for (int i = 0; i < n; i++) {
        if (std::abs(arr[i]) <= 1.0) {
            std::swap(arr[i], arr[positiveIndex]);
            positiveIndex++;
        }
    }
}

int main() {
    int n;
    std::cout << "Print masive size: ";
    std::cin >> n;

    double* arr = new double[n];
    createArray(arr, n);

    std::cout << "initial masive: ";
    printArray(arr, n);

    int minIndex = findMinIndex(arr, n);
    double sumBetween = sumNegatives(arr, n);

    std::cout << "Number of minimal element: " << minIndex << std::endl;
    std::cout << "The sum of elements the first and second negative: " << sumBetween << std::endl;

    transformArray(arr, n);

    std::cout << "mod masive: ";
    printArray(arr, n);

    delete[] arr; 

    return 0;
}
