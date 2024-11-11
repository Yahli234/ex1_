#include "Queue.h"
#include "Queue.cpp"
#include <iostream>
#include <sstream>
#include <windows.h> // WinApi header - needed for setting console color

using std::cout;
using std::endl;

#define BLACK 0
#define BLUE 1
#define GREEN 2
#define AQUA 3
#define RED 4
#define PURPLE 5
#define YELLOW 6
#define WHITE 7
#define GRAY 8
#define LIGHT_BLUE 9
#define LIGHT_GREEN 10
#define LIGHT_AQUA 11
#define LIGHT_RED 12
#define LIGHT_PURPLE 13
#define LIGHT_YELLOW 14
#define BRIGHT_WHITE 15


void set_console_color(unsigned int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hConsole == INVALID_HANDLE_VALUE) {
        std::cerr << "Error: Unable to get console handle." << std::endl;
        return;
    }
    SetConsoleTextAttribute(hConsole, color);
}


std::string removeElementsAndGetPrintedQueue(Queue* q)
{
    std::stringstream output;
    while (!isEmpty(q))
    {
        output << dequeue(q) << " ";
    }
    // removing the last letter (space)
    std::string outputString = output.str();
    outputString = outputString.substr(0, outputString.length() - 1);
    return outputString;
}

bool test1()
{
    bool result = false;

    try
    {
        set_console_color(LIGHT_BLUE);
        // check basic data structure functions
        cout <<
            "*******************************\n" <<
            "Test 1 - basic queue functions\n" <<
            "*******************************\n" << endl;
        set_console_color(WHITE);

        cout << "Initializing queue with size 5 ... \n" << endl;
        Queue* q0 = new Queue;
        initQueue(q0, 5);

        bool empty = isEmpty(q0);
        cout << "Checking if queue is empty ... \n"
            << "Expected: true\n"
            << "Got     : " << (empty ? "true" : "false")
            << "\n" << endl;

        if (!empty)
            // queue is not empty - test failed
            return false;

        const std::string queue0elements = "1 4 9 16 25";

        cout << "Adding elements to queue ... " << queue0elements << "\n" << endl;
        for (int i = 0; i < 5; i++)
        {
            enqueue(q0, (i + 1) * (i + 1));
        }

        bool full = isFull(q0);
        cout << "Checking if queue is full ... \n"
            << "Expected: true\n"
            << "Got     : " << (full ? "true" : "false")
            << "\n" << endl;

        if (!full)
            // queue is not empty - test failed
            return false;

        std::string output = removeElementsAndGetPrintedQueue(q0);
        cout << "Removing elements and printing queue ...\n"
            << "Expected: " << queue0elements << "\n"
            << "Got     : " << output
            << "\n " << endl;

        if (output != queue0elements)
        {
            return false;
        }

        cout << "Cleaning queue...\n" << endl;
        cleanQueue(q0);
        delete q0;
    }
    catch (...)
    {
        std::cerr << "Test crashed" << endl;
        return false;
    }

    return true;

}


bool test2()
{
    bool result = false;

    try
    {
        set_console_color(LIGHT_BLUE);
        // check basic data structure functions
        cout <<
            "*******************************\n" <<
            "Test 2 - two queues\n" <<
            "*******************************\n" << endl;
        set_console_color(WHITE);

        cout << "Initializing first queue with size 3 ... \n" << endl;
        Queue* q1 = new Queue;
        initQueue(q1, 3);

        const std::string queue1elements = "10 20 30";

        cout << "Adding elements to first queue ... " << queue1elements << "\n" << endl;
        for (int i = 0; i < 3; i++)
        {
            enqueue(q1, (i + 1) * 10);
        }

        cout << "Initializing second queue with size 5 ... \n" << endl;
        Queue* q2 = new Queue;
        initQueue(q2, 5);

        bool empty = isEmpty(q2);
        cout << "Checking if second queue is empty ... \n"
            << "Expected: true\n"
            << "Got     : " << (empty ? "true" : "false")
            << "\n" << endl;

        if (!empty)
            // queue is not empty - test failed
            return false;

        const std::string queue2elements = "1 2 3 4 5";

        cout << "Adding elements to second queue ... " << queue2elements << "\n" << endl;
        for (int i = 0; i < 5; i++)
        {
            enqueue(q2, i + 1);
        }

        bool full = isFull(q2);
        cout << "Checking if second queue is full ... \n"
            << "Expected: true\n"
            << "Got     : " << (full ? "true" : "false")
            << "\n" << endl;

        if (!full)
            // queue is not empty - test failed
            return false;

        int dequeueResult = dequeue(q1);
        cout << "Using dequeue() on first queue and printing element... \n" << endl
            << "Expected: 10\n"
            << "Got     : " << dequeueResult
            << "\n" << endl;

        if (dequeueResult != 10)
        {
            return false;
        }

        dequeue(q2);
        dequeue(q2);
        std::string q2output = removeElementsAndGetPrintedQueue(q2);
        cout << "Using dequeue() twice on second queue and printing queue... \n" << endl
            << "Expected: 3 4 5\n"
            << "Got     : " << q2output
            << "\n" << endl;

        if (q2output != "3 4 5")
        {
            return false;
        }

        empty = isEmpty(q1);
        cout << "Checking if first queue is empty ... \n"
            << "Expected: false\n"
            << "Got     : " << (empty ? "true" : "false")
            << "\n" << endl;

        if (empty)
            // queue is not empty - test failed
            return false;


        cout << "Cleaning first queue...\n" << endl;
        cleanQueue(q1);
        delete q1;

        cout << "Cleaning second queue...\n" << endl;
        cleanQueue(q2);
        delete q2;
    }
    catch (...)
    {
        std::cerr << "Test crashed" << endl;
        return false;
    }

    return true;

}



int main()
{

    bool test1Result = test1();
    bool test2Result = test2();
    if (test1Result && test2Result)
    {
        set_console_color(GREEN);
        std::cout << "\n########## Ex1 Part1 Tests Passed!!! ##########\n" << endl;
        set_console_color(WHITE);
    }
    else
    {
        set_console_color(RED);
        std::cout << "\n########## TEST Failed :( ##########\n";
        set_console_color(WHITE);
    }


    return 0;
}