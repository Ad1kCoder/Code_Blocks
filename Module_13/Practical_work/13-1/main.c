#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define SAMPL 3 // количество точек на радиан
#define AMP 300 // величина амлитуды синусоиды

float noize = 0.2; // коэф. шума; 0 - без шума, 1 - шум равен амплитуде

int main()
{
    int num;
    srand (time(NULL));
    printf("Enter the number of array elements: \n");
    scanf("%d", &num);
    puts("");
    float *arr = malloc(num*sizeof(float));
    if (arr == NULL) return 0;
    for (int i = 0; i < num; i++)
    {
        arr[i] = AMP*sin(((float)1/SAMPL)*i);
        arr[i] += rand()%2 ? (rand()%AMP)*noize : (-1)*(rand()%AMP)*noize;
        printf (" %f\n", arr[i]);
    }
    free(arr);
    return 0;
}
