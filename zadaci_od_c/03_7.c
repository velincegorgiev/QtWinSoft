// 7. Да се модифицира задачата p03_04.c за да дава излез на променливите total  и average со три децимални места.

/* Program p03_04.c
Manipulacija so niza, sobiranje i sredna vrednost na elementi */
#include <stdio.h>
float data[5]; /* podatocite kje bidat smesteni vo niza*/
float total; /* sumata na elementite na nizata data */
float average; /* sredna vrednost na elementite od nizata data */
int main()
{
data[0] = 34.0;
data[1] = 27.0;
data[2] = 45.0;
data[3] = 82.0;
data[4] = 22.0;
total = data[0] + data[1] + data[2] + data[3] + data[4];
average = total / 5.0;
printf("Vkupno %.3f Sredna vrednost %.3f\n", total, average);
return (0);
}
