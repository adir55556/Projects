#include <stdio.h>
#include <stdint.h>  // מביא משתנים מדוייקים
#include <fcntl.h>   // מביא את האפשרות לפתיחת קבצים (open)
#include <unistd.h>  // מביא אפשרות להשהיות וסגירת קבצים (close usleep)
#include <sys/mman.h>// מביא פקודות למיפוי זכרון (mmap)
#include "hps_0.h"   // הקובץ שיצרתי מכיל את הכתובות של הלדים

#define LW_ADDRESS_BASE 0xFF200000 // כתובת הגשר
#define LW_SIZE 0x00200000 // גודל הגשר

struct pointer {

       volatile uint32_t led_addr;
};

int main() {
    int fd; 
    void *virtual_base; // HPSמצביע  זכרון פיזי  לוירטואלי של ה
    struct pointer *ptr;

      fd = open("/dev/mem", O_RDWR | O_SYNC); // 
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
   
      ptr = (struct pointer *)(virtual_base + LEDS_COMP_0_BASE);
     

   while(1){
      ptr -> led_addr=0xFF;
      usleep(1000000);
      ptr -> led_addr=0x00;
      usleep(1000000);
   }

}
