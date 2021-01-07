#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void plot(int d[][10]);
int check(int d[][10]);
void victory(void);

int main()
{
	int x, y, side, count;
	int loop = 1;
	int d[10][10] = { 0 };

	side = 1;
	count = 0;
	plot(d);

	do
	{
		printf("請輸入座標(x,y)=");
		scanf_s("%d%d", &y, &x);
		if (d[x][y] == 0)
		{
			d[x][y] = side;
			side *= -1;
			count++;
		}
		plot(d);
		if (count == 9 || check(d) == 1 || check(d) == -1)
			loop = 0;
	} while (loop);
	victory(d);
}
void plot(int d[][10])
{
	int i, j;
	printf("y/x  0    1    2\n");
	for (i = 0; i < 3; i++)
	{
		printf("%d", i);
		for (j = 0; j < 3; j++)
		{
			if (d[i][j] == 0)
			{
				printf("   □");
			}
			if (d[i][j] == 1)
			{
				printf("   ○");
			}
			if (d[i][j] == -1)
			{
				printf("   ●");
			}
		}
		printf("\n");
	}
	printf("\n");
}
int check(int d[][10])
{
	int v1, v2, v3, v4, v5, v6, v7, v8;
	v1 = d[0][0] + d[0][1] + d[0][2];
	v2 = d[1][0] + d[1][1] + d[1][2];
	v3 = d[2][0] + d[2][1] + d[2][2];
	v4 = d[0][0] + d[1][0] + d[2][0];
	v5 = d[0][1] + d[1][1] + d[2][1];
	v6 = d[0][2] + d[1][2] + d[2][2];
	v7 = d[0][0] + d[1][1] + d[2][2];
	v8 = d[0][2] + d[1][1] + d[2][0];

	if (v1 == 3 || v2 == 3 || v3 == 3 || v4 == 3 || v5 == 3 || v6 == 3 || v7 == 3 || v8 == 3)
		return 1;
	else if (v1 == -3 || v2 == -3 || v3 == -3 || v4 == -3 || v5 == -3 || v6 == -3 || v7 == -3 || v8 == -3)
		return -1;
	else
		return 0;
}
void victory(int d[][10])
{
	if (check(d) == 1)
		printf("○獲勝\n");
	else if (check(d) == -1)
		printf("●獲勝\n");
	else
		printf("雙方平手\n");
}