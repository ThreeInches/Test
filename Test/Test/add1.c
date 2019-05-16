#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void bubble(int a[],int n) {
	int i, j;
	int tmp;
	for (i = 0; i <= n - i - 1; i++) {
		for (j = 0; j <= n - 1 - i; j++) {
			if (a[j] > a[j + 1]) {
				tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;
			}
		}
	}
}

int bag() {
	int i;
	int num, size;
	int weight[20] = { 0 };
	int sum = 0;
	scanf("%d %d", &num, &size);
	for (i = 0; i < num; i++) {
		scanf("%d", weight + i);
	}
	bubble(weight, num);
	for (i = 0;sum + weight[i] < size && i < num; i++) {
		sum += weight[i];
	}
	printf("%d", i);
	system("pause");
	return 0;
}

int boat() {
	int count = 0;
	int i,j;
	int num, size;
	int weight[20] = { 0 };
	int sum = 0;
	scanf("%d %d", &num, &size);
	for (i = 0; i < num; i++) {
		scanf("%d", weight + i);
	}
	bubble(weight, num);
	for (i = 0, j = num - 1; i <= j; j--) {
		if (weight[i] + weight[j] <= size) {
			i++;
		}
		count++;
	}
	printf("%d", count);
	system("pause");
	return 0;
}

int stone() {
	int count = 0;
	int i, j;
	int n, size;
	int num[20] = { 0 };
	int sum = 0;
	scanf("%d %d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", num + i);
	}
	for (i = 0; i < n - 1; i++) {
		bubble(num + i, n - i);
		num[i + 1] = num[i] + num[i + 1];
		sum += num[i + 1];
	}
	printf("%d", sum);
	system("pause");
	return 0;
}

int main2() {
	int a[10][10] = { 0 };
	int x, y;
	int x2 = 2, y2 = 3;
	scanf("%d %d", &x, &y);
	int i, j;
	for (i = 1; i <= x; i++) {
		for (j = 1; j <= y; j++) {
			if (i == x2 && j == y2) {
				continue;
			}
			if (i == 1 && j == 1) {
				a[i][j] = 1;
			}
			else {
				a[i][j] = a[i - 1][j] + a[i][j - 1];
			}
		}
	}
	printf("%d", a[i][j]);
	system("pause");
	return 0;
}