#include <iostream>
#include <string.h>
using namespace std;

int main(void)
{
    char txbuffer[] =  "Dummy Sensor Value is 123456789abcdef";
    cout << "char(ASCII): ";
    for(int i = 0; i< strlen(txbuffer); i++)
    {
        printf("%02x\t", txbuffer[i]);
    }
    return 0;
}