#include <iostream>
void fillRandom(int** array, int rows, int cols) {
    std::srand(std::time(nullptr));
    int temp;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            temp = std::rand() % 70;
            if (temp < 10) {
                array[i][j] = temp + 10;

            }
            else {
                array[i][j] = temp;
            }
        }
    }
}

void printArray(int** array, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << array[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
int sumDiag(int** array, int rows, int cols) {
    int j=cols-1;
    int sum = 0;
    for (int i = 0; i < rows; ++i) {
        sum += array[i][j];
        --j;
    }
    return sum;
}
void task3() {
    int rows, cols;
    std::cout << "Введите количество строк и столбцов: ";
    std::cin >> rows >> cols;

    int** dynamicArray = new int* [rows];
    for (int i = 0; i < rows; ++i) {
        dynamicArray[i] = new int[cols];
    }
    

    fillRandom(dynamicArray, rows, cols);

    std::cout << "Двумерный массив случайных чисел:" << std::endl;
    printArray(dynamicArray, rows, cols);
    std::cout << "Сумма элементов побочной диагонали: " <<sumDiag(dynamicArray, rows, cols)<<std::endl;


    for (int i = 0; i < rows; ++i) {
        delete[] dynamicArray[i];
    }
    delete[] dynamicArray;
}
// 4 не сделана до конца
struct User {
    int id;
    int age;
};
void createNew(User*& arr, int* size, int id, int age) {
    User* tempArr = arr;
    delete[] arr;
    arr = new User[*size + 1];
    for (int i = 0; i < *size; ++i) {
        arr[i] = tempArr[i];
    }
    delete[] tempArr;
    *size += 1;
}
void deleteAcc(User*& arr, int* size, int id, int age) {
    User* tempArr = arr;
    delete[] arr;
    arr = new User[*size - 1];
    for (int i = 0; i < *size-1; ++i) {
        arr[i] = tempArr[i];
    }
    delete[] tempArr;
    *size -= 1;
}
void update(User*& arr, int* size, int id, int age) {
    arr[*size - 1] = User{ id,age };
}
void show(User*& arr, int* size, int id, int age) {
    std::cout << "Массив: ";
    for (int i = 0; i < *size; i++) {
        std::cout << arr[i].id << " "<< arr[i].age<<std::endl;
    }
}

void task4() {
    User* arr;
    int size1 = 0,id,age;
    int* size;
    size = &size1;
    char operation;
    void (*func)(User *&, int*, int, int);

    std::cout << "Введите номер операции(0 - выход,1 -добавление,2-удаление,3 - обновление, 4 - вывод информации), для 1,2 действия над последним элементом в массиве: ";
    std::cin >>operation;
     
    while (operation != '0') {
        switch (operation) {
        case '1':
            func = &createNew;
            func(arr, size, 0, 0);
            break;
        case '2':
            func = &deleteAcc;
            func(arr, size, 0, 0);
            break;
        case '3':
            std::cout << "Введите id, age(int):";
            std::cin >> id>>age;
            func = &update;
            func(arr, size, id, age);
            break;
        case '4':
            func = &show;
            func(arr, size, 0, 0);
            break;
        default:
            std::cout << "Неподдерживаемая операция." << std::endl;
        }
        std::cout << "Введите номер операции(0 - выход,1 -добавление,2-удаление,3 - обновление, 4 - вывод информации), для 1,2 действия над последним элементом в массиве: ";
        std::cin >>operation;
    }
    }
int main()
{
    setlocale(LC_ALL, "Russian");
    task3();
}

