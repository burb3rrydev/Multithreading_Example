# Multithreading_Example

This is a C program that demonstrates the use of multithreading using the pthread library. It creates two threads, thread1 and thread2, which run concurrently and perform different tasks. Each thread prints a series of messages with a delay between them. The main function waits for both threads to finish before exiting.
Compilation

Before running the program, you need to compile it using a C compiler. You can use the gcc compiler as follows:

gcc -o multithreading_example multithreading_example.c -lpthread

This command compiles the code in multithreading_example.c and links it with the pthread library using the -lpthread flag. The resulting executable is named multithreading_example.
Usage

After compilation, you can run the program by executing the following command:

./multithreading_example

Code Explanation

    #include statements: Include necessary header files for standard input/output (stdio.h), memory allocation (stdlib.h), POSIX threads (pthread.h), and sleep functionality (unistd.h).

    #define NUM_MESSAGES 10: Define a constant NUM_MESSAGES with a value of 10, representing the number of messages each thread will print.

    void *thread1_function(void *arg): This function is the entry point for thread1. It prints 10 messages with a delay of 1 second between each message and then exits.

    void *thread2_function(void *arg): This function is the entry point for thread2. It prints 10 messages with a delay of 2 seconds between each message and then exits.

    int main(): The main function is where the program starts execution.

        pthread_t thread1, thread2;: Declare two variables of type pthread_t to represent the two threads.

        pthread_create(): Create thread1 and thread2 using pthread_create(). Each call to pthread_create() specifies the thread variable, attributes (NULL in this case), the thread function, and any arguments to the thread function.

        pthread_join(): Wait for both thread1 and thread2 to finish their execution using pthread_join(). This ensures that the main thread waits for the two child threads to complete before continuing.

        The printf() statement at the end of the main function prints a message indicating that all threads have finished.

    The program demonstrates concurrent execution of thread1 and thread2, with thread1 printing messages more frequently than thread2. This illustrates the concept of multithreading, where multiple threads run independently and concurrently.

    The program uses the sleep() function to introduce delays between message printing to simulate concurrent execution.

    Error checking is performed using perror() to handle any potential errors during thread creation or joining.

    The program exits with a return value of 0 in the main() function to indicate successful execution.
