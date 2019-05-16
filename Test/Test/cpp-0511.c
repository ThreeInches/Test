#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>
#include <string.h>

#if 0
int main() {
	int a = 5, b = 7;
	int max = (a + b + abs(a - b))/2;
	printf("%d", max);
	system("pause");
	return 0;
}

//sizeof,strlen
//strlen是求字符串的实际长度不包括\0
//sizeof是计算字符空间的运算符
int main() {
	char a[] = "abc\012abc";
	char b[] = "abc\0abc";
	int n = sizeof(a);
	int m = sizeof(b);
	printf("%d,%d\n", n, m);
	n = strlen(a);
	m = strlen(b);
	printf("%d,%d\n", n, m);
	system("pause");
	return 0;
}


int fn() {
	printf("fn\n");
	return 0;
}

int main() {
	int a = 6;
	//int n = sizeof(a++);
	int n = sizeof(fn());
	printf("%d %d", a, n);
	system("pause");
	return 0;
}


int main() {
	unsigned int a = -2;
	printf("a = %d,a = %u\n", a, a);
	system("pause");
	return 0;
}
//0000 0000 0000 0000 0000 0000 0000 0010 => 2 (源码)
//1111 1111 1111 1111 1111 1111 1111 1101(取反)
//1111 1111 1111 1111 1111 1111 1111 1110 => -2(补码)


int main() {
	int a = -10;
	unsigned int b = -5;
	if (a + b > 0) {
		printf(">0\n");
	}
	else {
		printf("<0\n");
	}
	system("pause");
	return 0;
}

int main() {
	char a = 258;//1 0000 0010‬
	printf("%d\n", a);
	system("pause");
	return 0;
}

int main() {
	int a = 200;
	int b = 16;
	int r;
	//int m[10];
	char str[20] = "";
	int i = 0;
	scanf("%d%d", &a, &b);
	while (a != 0) {
		r = a%b;
		if (r < 10) {
			str[i] = r + '0';
		}
		else {
			str[i] = r - 10 + 'A';
		}
		a = a / b;
		++i;
	}
	for (--i; i >= 0; --i) {
		printf("%c ", str[i]);
	}
	putchar('\n');
	system("pause");
	return 0;
}

int main() {
	char a = 0x80;
	unsigned char b = 0x80;
	unsigned int c = a;
	int d = a;
	printf("a=%d,a=%u\n", a, a);//128 =>1000 0000(直接存) -128=> 1000 0000(取反再加一)
	printf("b=%d,b=%u\n", b, b);
	printf("c=%d,c=%u\n", c, c);
	printf("d=%d,d=%u\n", d, d);
	system("pause");
	return 0;
}

int main() {
	char str[1000];
	for (int i = 0; i < 1000; i++) {
		str[i] = -1 - i;//str[255] = -256
	}
	printf("%d\n", strlen(str));
	system("pause");
	return 0;
}
//\0当前值是0,在控制台不可显示的字符,作为结束标志队字符串没有影响

int main() {
	int a = 6;
	int b = 0;
	//++a = b;
	system("pause");
	return 0;
}

int main() {
	int a = 3, b = 4, c = 5;
	while (a < b < c) {
		int t = a;
		a = b;
		b = t;
		c--;
	}
	printf("%d %d %d", a, b, c);
	system("pause");
	return 0;
}

int main() {
	int a = 3, b = 4, c = 5;
	int n = 0;
	while (--a && ++b && c--) {
		n++;
	}
	printf("%d,%d,%d", a, b, c, n);
	system("pause");
	return 0;
}//0232

int main() {
	int a = 0x11223344;
	short int b = a;
	char c = a;
	printf("%x,%x,%x\n", a, b, c);
	printf("%d,%d,%d\n", &a, &b, &c);
	system("pause");
	return 0;
}
//大端 地位存在高地址,高位存在低地址
//小端 地位存在低地址,高位存在高地址

int main() {
	int a = 6;
	float b = 4.6;
	printf("%d\n", (int)b);
	system("pause");
	return 0;
}
//SEM 32 S符号位 E指数位 M

/*
|||||||||||||
*/
#include <stdlib.h>
#include <Windows.h>
int main() {
	int i, j;
	/*while (1) {
		for (i = 0; i < 10; i++) {
			printf("|||||||||||");
			Sleep(100);
			system("cls");
			for (j = 0; j <= i; j++) {
				putchar('\n');
			}
		}
	}*/
	//\b backspace
	HANDLE handle;
	COORD pos(0, 0);
	while (1) {
		for (i = 0; i < 10; i++) {
			printf("||||||||||");
			Sleep(100);
			printf("\b\b\b\b\b\b\b\b\b\b");
			printf("          ");
			putchar('\n');
	}
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(handle, pos);
	system("pause");
	return 0;
}

//1 11 21 1211 111221 312211
//1%-100%
int main() {
	int p = 10;
	for (p = 10; p < p + 10; p++) {
		;
	}
	printf("%d", p);
	system("pause");
	return 0;
}
#endif