#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_POINTS 20
#define MAX_COORD 100

int main()
{
    FILE *fp;
    int i;
    double x[NUM_POINTS], y[NUM_POINTS];

    // 乱数初期化
    srand((unsigned int)time(NULL));

    // データ生成
    fp = fopen("points.dat", "w");
    if (fp == NULL)
    {
        perror("ファイルオープンに失敗しました");
        return 1;
    }

    for (i = 0; i < NUM_POINTS; i++)
    {
        x[i] = (double)(rand() % (MAX_COORD + 1));
        y[i] = (double)(rand() % (MAX_COORD + 1));
        fprintf(fp, "%lf %lf\n", x[i], y[i]);
    }

    fclose(fp);

    // gnuplotスクリプトを実行してpng出力
    fp = fopen("plot.gp", "w");
    if (fp == NULL)
    {
        perror("gnuplotスクリプト作成に失敗しました");
        return 1;
    }

    fprintf(fp,
            "set terminal png size 500,500\n"
            "set output 'points.png'\n"
            "set xrange [0:%d]\n"
            "set yrange [0:%d]\n"
            "set title 'Random Points'\n"
            "plot 'points.dat' using 1:2 with points pt 7 ps 2 lc rgb 'blue' notitle\n",
            MAX_COORD, MAX_COORD);

    fclose(fp);

    // gnuplotスクリプトを実行
    system("gnuplot plot.gp");

    printf("points.png を出力しました。\n");
    return 0;
}
