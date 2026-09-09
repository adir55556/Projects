#include <stdio.h>
#include <stdint.h>  // מביא משתנים מדוייקים
#include <fcntl.h>   // מביא את האפשרות לפתיחת קבצים (open)
#include <unistd.h>  // מביא אפשרות להשהיות וסגירת קבצים (close usleep)
#include <sys/mman.h>// מביא פקודות למיפוי זכרון (mmap)
#include "hps_0.h"   // הקובץ שיצרתי מכיל את הכתובות של הלדים

#define LW_ADDRESS_BASE 0xFF200000 // כתובת הגשר
#define LW_SIZE 0x00200000 // גודל הגשר

int main() {
    int fd; 
    void *virtual_base; // HPSמצביע  זכרון פיזי  לוירטואלי של ה
     volatile int32_t *calc;
     int32_t a;
     int32_t b;
     int32_t op;


      fd = open("/dev/mem", O_RDWR | O_SYNC);  
         if(fd == -1) {
            perror("failed to open");
            return 1;
      }

      virtual_base = mmap(NULL, LW_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, LW_ADDRESS_BASE); //
         if(virtual_base == MAP_FAILED) {
            perror("failed to mmap");
            close(fd);
            return 1;
      }
   
      calc = (volatile int32_t *)(virtual_base + CALC_COMP_0_BASE);
     
while (1) {
      
      printf("enter first number: ");
      scanf("%d", &a);

      printf("enter second number: ");
      scanf("%d", &b);
      
      printf("enter operation (0 for add, 1 for minus, 2 for divide, 3 for multiply, 4 for reminder):");
      scanf("%d", &op);

if ((op == 2 || op == 4) && b == 0) {
    printf("error cant do this op with 0");
    return 0;
}

      *calc = a;
      *calc = b;
      *calc = op;

      int32_t result = *calc;
      printf("result: %d\n", result);

 }
}

