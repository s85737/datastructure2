//
//  main.c
//  26
//
//  Created by 최제현 on 2020/11/26.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(void) {
   struct tm* timeNow;
   time_t tnow;
   tnow = time(NULL);
   timeNow = (struct tm*)localtime(&tnow);

    
    
   FILE* file;
   file = fopen(
      "/Users/s85737/Desktop/mat.txt", "w+");
//
//    fseek(seek_, +1, <#int#>)
//    fscanf(, <#const char *restrict, ...#>);
//    fprintf(, <#const char *restrict, ...#>);
//    fgets(<#const char *restrict#>, <#FILE *restrict#>);

   int a, b;
   printf("매트릭스 크기는? : ");
   scanf("%d %d", &a, &b);//a는 행, b는 열

   float **arr = malloc(sizeof(int*) * a);
   
   for (int i = 0; i < a; i++) {
      for (int j = 0; j < b; j++) {
         arr[i] = malloc(sizeof(int) * b);
         printf("%d\n", arr[i]);
      }
   }

   srand(time(0));//매번 다른 수를 생성하고 싶을 때.

   for (int i = 0; i < a; i++) {
      for (int j = 0; j < b; j++) {
         arr[i][j] = rand() % 100 + 1;
         if (arr[i][j] < 10) {
            fprintf(file, " %f\t", arr[i][j]);//file이 가리키는(경로) 파일에다 대입.
            //이유는 모르겠으나, 난수가 1자리수이면 탭상수 대신 space상수가 작성되어 구분했음
         }
         else {
            fprintf(file, "%f\t", arr[i][j]);
         }
         printf("%.3f\t", arr[i][j]);
      }
      fprintf(file, "\n");
      printf("\n");
   }

   for (int i = 0; i < a; i++) {
       free(arr[i]);
   }
    free(arr);
    
    arr = NULL;
    
    fclose(file);

   char date[30] = { 0x00, };
   sprintf(date, "%d-%d-%d %d시%d분%d초",
      timeNow->tm_year + 1900, timeNow->tm_mon + 1, timeNow->tm_mday, timeNow->tm_hour, timeNow->tm_min, timeNow->tm_sec);

   int change_name = rename("mat.txt", date);

   system("pause");
   return 0;
}
