#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BUFFER_SIZE 1000
#define PRINT_SIZE 50
#define TOTAL_TIME 100

unsigned char buffer[MAX_BUFFER_SIZE];
int bufferCount = 0;

/* Add random bytes to the global buffer */
void generateSensorData()
{
    int bytesToGenerate = rand() % 6;   // Generates 0 to 5 bytes

    printf("\nGenerated %d byte(s): ", bytesToGenerate);

    for (int i = 0; i < bytesToGenerate; i++)
    {
        if (bufferCount < MAX_BUFFER_SIZE)
        {
            unsigned char value = rand() % 256;
            buffer[bufferCount++] = value;
            printf("%02X ", value);
        }
    }

    printf("\nCurrent Buffer Size = %d\n", bufferCount);
}

/* Print latest 50 bytes and remove them */
void printLatest50Bytes()
{
    if (bufferCount < PRINT_SIZE)
    {
        printf("Buffer has only %d bytes. Not enough data to print.\n", bufferCount);
        return;
    }

    printf("\nLatest 50 Bytes:\n");

    int start = bufferCount - PRINT_SIZE;

    for (int i = start; i < bufferCount; i++)
    {
        printf("%02X ", buffer[i]);
    }

    printf("\n");

    /* Remove printed bytes */
    bufferCount -= PRINT_SIZE;

    printf("50 bytes removed.\n");
    printf("Remaining Buffer Size = %d\n", bufferCount);
}

int main()
{
    srand(time(NULL));

    printf("Sensor Data Simulation Started\n");

    for (int second = 1; second <= TOTAL_TIME; second++)
    {
        printf("\n========== Second %d ==========\n", second);

        generateSensorData();

        if (second % 10 == 0)
        {
            printf("\n----- 10 Second Check -----\n");
            printLatest50Bytes();
        }
    }

    return 0;
}
