#include <stdio.h>
#include <stdint.h>
int main() {
    uint8_t canDataArray[8] = { 0x64, 0xC9, 0x00, 0x00, 0x01, 0x32, 0x4E, 0x28 };
    //Current Data : 164,32,0,4 G Sensor : 32,38,4,a
    
    uint16_t currentData1 = (canDataArray[0]) | (((uint16_t)canDataArray[1] & 0x03) << 8); //0x03 : 0011
    uint16_t currentData2 = (canDataArray[1] >> 2) | (((uint16_t)canDataArray[2] & 0x0F) << 6); //0x0F : 1111
    uint16_t currentData3 = (canDataArray[2] >> 4) | (((uint16_t)canDataArray[3] & 0x3F) << 4);
    uint16_t currentData4 = (canDataArray[3] >> 6) | ((uint16_t)canDataArray[4] << 2);

    uint8_t gsensor1 = canDataArray[5] & 0x3F;
    uint8_t gsensor2 = (canDataArray[5] >> 6) | ((canDataArray[6] & 0x0F) << 2);
    uint8_t gsensor3 = (canDataArray[6] >> 4) | ((canDataArray[7] & 0x03) << 4);
    uint8_t gsensor4 = canDataArray[7] >> 2;

    printf("Current Data:\n");
    printf("Current 1: %x\n", currentData1);
    printf("Current 2: %x\n", currentData2);
    printf("Current 3: %x\n", currentData3);
    printf("Current 4: %x\n", currentData4);
    printf("\nGsensor Data:\n");
    printf("Gsensor 1: %x\n", gsensor1);
    printf("Gsensor 2: %x\n", gsensor2);
    printf("Gsensor 3: %x\n", gsensor3);
    printf("Gsensor 4: %x\n", gsensor4);
    return 0;
}
