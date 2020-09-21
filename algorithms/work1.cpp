#include <stdio.h>
#define VMAX 21

typedef struct {
    char name[20];
    int height;
    double vision;
} PhysCheck;

double ave_height(const PhysCheck dat[], int n)
{
    int i;
    double sum = 0;
    for (i = 0; i < n; i++)
        sum += dat[i].height;
    return sum / n;
}

void dist_vision(const PhysCheck dat[], int n, int dist[])
{
    int i;
    for (i = 0; i < VMAX; i++)
        dist[i] = 0;
    for (i = 0; i < n; i++)
        if (dat[i].vision >= 0.0 && dat[i].vision <= VMAX / 10.0)
            dist[(int)(dat[i].vision * 10)]++;
}

int main(void)
{
    int i;
    PhysCheck x[] = {
       { "김현지", 162, 0.3 },
       { "안병현", 182, 2.0 },
       { "이순주", 175, 1.5 },
       { "박선정", 165, 0.8 },
       { "한지선", 164, 0.3 },
       { "이지연", 158, 0.2 },
       { "한승희", 153, 0.7 }
    };
    int nx = sizeof(x) / sizeof(x[0]);
    int vdist[VMAX];
    puts("■□■ 신체검사표 ■□■");
    puts("   이름     키  시력  ");
    puts("---------------------------");
    for (i = 0; i < nx; i++)
        printf("%-18.18s%4d%5.1f\n", x[i].name, x[i].height, x[i].vision);
    printf("\n 평균 키 : %5.1f cm\n", ave_height(x, nx));
    dist_vision(x, nx, vdist);
    printf("\n 시력분포\n");
    for (i = 0; i < VMAX; i++)
        printf("%3.1f  : %2d명\n", i / 10.0, vdist[i]);

    return 0;
}