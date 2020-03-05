#include <stdio.h>

int main()
{
   FILE *fp;
   char buff[255];

   fp = fopen("/home/kn/vsCode/trainingC/vidu.txt", "r");
   fgets(buff, 255, fp);
   printf("%s", buff);
   fgets(buff, 255, fp);
   printf("%s", buff);
   fclose(fp);
}