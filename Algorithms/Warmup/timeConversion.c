//@author: Varun Patel
//Time Conversion
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main() {
    char* s = (char *)malloc(512000 * sizeof(char));
    int hour;
    int minute;
    int second;
    char type[3];
    scanf("%d:%d:%d%s",&hour, &minute, &second, type);
    if(strcmp(type, "PM")==0 && hour != 12){
        hour += 12;
    }
    if (strcmp(type, "AM")==0 && hour == 12) {
        hour = 0;
    }
    printf("%02d:%02d:%02d", hour,minute,second);
    free(s);
    return 0;
}
