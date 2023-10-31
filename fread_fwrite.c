 #include <stdio.h>
 #include <stdlib.h>
 #define READ 4
 #define WRITE 4
 int main(void)
 {
    FILE *file_ptr, *fp;
    int iCount;
    char *person[10];
    person[0]="name0";
    person[1]="name1";
    person[2]="name2";
    person[3]="name3";
 
    char *rPerson[40]; //at <40, stack smash error occurs
    file_ptr = fopen("sample.txt", "w");
    iCount = fwrite(person, sizeof(person), WRITE, file_ptr);
    printf("write: %d\n",iCount);
    fclose(file_ptr);
    
    fp = fopen("sample.txt", "r");
    iCount = fread(rPerson, sizeof(person), READ, fp);
    printf("read: %d\n",iCount);
    
    // printf("read = %s\n", rPerson[0]);
    for(int i = 0; i < iCount; i++) {
        printf("read[%d] = %s\n", i, rPerson[i]);
    }
    fclose(fp);
    
    return 0;
 }
