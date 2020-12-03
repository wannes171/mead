#include <stdio.h>
#include<time.h>

#define FILE_NAME "mead.csv"

int main()
{
    float m1, m2, m3, m4, m5, avg, freq;
    
    printf("m1: ");
    scanf("%f", &m1);
    printf("m2: ");
    scanf("%f", &m2);
    printf("m3: ");
    scanf("%f", &m3);
    printf("m4: ");
    scanf("%f", &m4);
    printf("m5: ");
    scanf("%f", &m5);

    avg = (m1+m2+m3+m4+m5)/5;
    freq = 60/avg;
    
    FILE *f = fopen(FILE_NAME, "a");
    if (f == NULL) 
        return -1;
    
    time_t t;
    t = time(NULL);
    struct tm tm = *localtime(&t);
    
    fprintf(f, "%d/%d/%d,%d:%d:%d,%f,%f,%f,%f,%f,%f,%f\n", tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900, tm.tm_hour, tm.tm_min, tm.tm_sec, m1, m2, m3, m4, m5, avg, freq);
    
    fclose(f);

    return 0;
}

