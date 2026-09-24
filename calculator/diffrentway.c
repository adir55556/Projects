#include <stdio.h>
#include <stdint.h>  // מביא משתנים מדוייקים
#include <fcntl.h>   // מביא את האפשרות לפתיחת קבצים (open)
#include <unistd.h>  // מביא אפשרות להשהיות וסגירת קבצים (close usleep)
#include <sys/mman.h>// מביא פקודות למיפוי זכרון (mmap)
#include "hps_0.h"   // הקובץ שיצרתי מכיל את הכתובות של הלדים
#include <stdlib.h>
#include <ctype.h>


#define LW_ADDRESS_BASE 0xFF200000 // כתובת הגשר
#define LW_SIZE 0x00200000 // גודל הגשר

struct calc_numbers {
    int32_t  a;
    int32_t  b;
    uint32_t op;
    int32_t result;
};


 int lettercheck(char numbers[]) {
    int k = 0;

    if (numbers[0] == '\0') {
        printf("not a number\n");
        return 1;
    }

    if (numbers[0] == '+' || numbers[0] == '-')
        k = 1;

    for (; numbers[k] != '\0'; k++) {
        if (!isdigit((unsigned char)numbers[k])) {
            printf("letter was sent\n");
            return 1;
        }
    }
    return 0;
}

int main(int count, char *numbers[]) {
    int fd; 
    void *virtual_base; // HPSמצביע  זכרון פיזי  לוירטואלי של ה
    volatile struct calc_numbers *calc;


 if (count != 4) {
        printf("error- not good\n");
        return 1;
    }
if(lettercheck(numbers[1]) || lettercheck(numbers[2]) || lettercheck(numbers[3])) {
        return 1;
    }
    
      fd = open("/dev/mem", O_RDWR | O_SYNC);  
         if(fd == -1) {
            perror("failed to open\n");
            return 1;
      }

      virtual_base = mmap(NULL, LW_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, LW_ADDRESS_BASE); //
         if(virtual_base == MAP_FAILED) {
            perror("failed to mmap\n");
            close(fd);
            return 1;
      }
   
      calc = (volatile struct calc_numbers *)(virtual_base + ALU_COMP_0_BASE);

      calc->a  = (int32_t)atoi(numbers[1]);
      calc->b  = (int32_t)atoi(numbers[2]);
      calc->op = (uint32_t)atoi(numbers[3]);

    if ((calc->op == 2 || calc->op == 4) && calc->b == 0) {
    printf("error- cant do this op with 0\n");
    return 1;
}

      printf("result: %d\n", calc->result);
    
      munmap(virtual_base, LW_SIZE);
      close(fd);
      return 0;
 
}
