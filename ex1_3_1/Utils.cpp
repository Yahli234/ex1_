#include "Utils.h"
#include "../ex1_02/ex1_02_2/Stack.h"
#include "../ex1_02/ex1_02_2/Stack.cpp"
#include <iostream>

void reverse(int* nums, unsigned int size)
{
	Stack stack;
	initStack(stack);
	for (int i = 0; i < size; i++)
	{
		push(stack,nums[i]);
	}
	for (int i = 0; i < size; i++)
	{
		pop(stack);
	}
	cleanStack(stack);
}

int* reverse10()
{
    Stack stack;
    initStack(stack);

    std::cout << "Please enter 10 integers:" << std::endl;
    int* nums = new int[10];
    for (int i = 0; i < 10; i++)
    {
        int input;
        std::cin >> input;
        push(stack, input);
    }

    for (int i = 0; i < 10; i++)
    {
        nums[i] = pop(stack);
    }

    cleanStack(stack);

    return nums;
}


void printArray(const int* nums, int size) {
    for (int i = 0; i < size; i++) {
        std::cout << nums[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{
    int* reversedArray = reverse10();
    std::cout << "Reversed array from reverse10: ";
    printArray(reversedArray, 10);

    reverse(reversedArray, 10);

    std::cout << "Array after applying reverse: ";
    printArray(reversedArray, 10);
    delete[] reversedArray;

    return 0;
}
