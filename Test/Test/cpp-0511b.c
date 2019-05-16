#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
/*
基类型(当前指针指向的那个变量类型)*指针变量名
野指针:指向垃圾内存的指针
(野指针出现的两种情况,1.声明一个指针,没有给它合法化;2.malloc用完当前堆空间没有free或者没有置空.)
(右左法则)
int* p单指针
int** p1双指针
int(*p2)[3]数组指针
int* p3[4]指针数组
int(*p4)(int,int)函数指针
int* p5(int,int)指针函数
int(*p4[3])(int,int)函数指针数组
*/

#if 0
void swap1(int a, int b) {
	int tmp;
	tmp = a;
	a = b;
	b = tmp;
}

void swap2(int* x, int* y) {
	int* tmp;
	tmp = x;
	x = y;
	y = tmp;
}

void swap3(int* x, int* y) {
	int tmp;
	tmp = *x;
	*x = *y;
	*y = tmp;
}

void main() {
	int a = 5,b = 7;//栈空间
	int* p = &a;//堆空间p -> a
	//swap1(a, b);
	//swap2(&a, &b);
	swap3(&a, &b);
	printf("%d,%d\n", a, b);
	system("pause");
}
#endif

#if 0
void main() {
	char a[] = { 1, 1, 1, 1, 1 };
	int *p = (int*)a;
	printf("*p=%d\n", *p);
	system("pause");
}
#endif

#if 0
void main() {
	int a[] = { 1, 2, 3, 4, 5 };
	int* p = (int*)(&a + 1);
	printf("%d\n", *(p - 1));
	system("pause");
}
#endif

#if 0
void main() {
	int a[3][4];
	printf("%d,%d,%d\n", a, a[0], &a[0][0]);
	printf("%d,%d,%d\n", a, a + 1,&a[1]);
	system("pause");
}
#endif

#if 0
void main() {
	int a[] = { 7, 6, 8, 9, 0, 1, 2, 3, 4, 5 };
	int i, j, t;
	int* p = a;
	int n = sizeof(a) / sizeof(a[0]);
	for (i = 0; i < n-1; i++) {
		for (j = 0; j < n-i-1; j++) {
			if (a[j] < a[j + 1]) {
				t = a[j];
				a[j] = a[j + 1];
				a[j + 1] = t;
			}
		}
	}
	for (i = 0; i < n;i++) {
		printf("%d ", a[i]);
	}
	putchar('\n');
	for (i = 0; i < n; i++) {
		printf("%d ", *(a+i));
	}
	putchar('\n');
	for (i = 0; i < n; i++) {
		printf("%d ", *(p+i));
	}
	putchar('\n');
	for (i = 0; i < n; i++) {
		printf("%d ", p[i]);
	}
	putchar('\n');
	for (i = 0; i < n; i++) {
		printf("%d ", *p-i);
	}
	putchar('\n');
	system("pause");
}
#endif

#if 0
void main() {
	int a[] = { 7, 6, 8, 9, 0, 1, 2, 3, 4, 5 };
	int n = sizeof(a) / sizeof(a[0]);
	//int* p = a, *q = a + n - 1;
	/*while (q < p) {
		int t = *p;
		*p = *q;
		*q = t;
		++ p;
		--q;
	}*/
	int* p = a, *q = a + 1, *end =a + n - 1;
	for (p = a; p < a + n - 1; p++) {
		for (q = a; q < end; q++) {
			if (*q < *(q + 1)) {
				int t = *q;
				*q = *(q+1);
				*(q+1) = t;
				end--;
			}
		}
	}
	for (p = a; p < a + n; p++) {
		printf("%d ", *p);
	}
	putchar('\n');
	system("pause");
}
#endif

/*
int a;
int b[10];
int c[2[3];
int* p;
*/
#if 0
void main() {
	int a[3][4] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 9, 8 };
	int* p = &a[0][0];
	int i;
	int j;
	for (int i = 0; i < 3 * 4; i++) {
		printf("%d ", *(p + i));//表示的时候不方便,对于二维数组用两个二维数组表示出来
	}
	putchar('\n');
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 4; j++) {
			printf("%d ", *(p + i * 4 + j));
		}
		putchar('\n');
	}
	system("pause");
}
#endif

/*
字符串与指针
*/
#if 0
void main() {
	char a[5] = { '1', '2', '3', '4', '5' };
	char b[5] = "12345";
	
	system("pause");
}
#endif
#if 0
void main() {
	char a[] = "12345";//把1234存储到char所开辟的地址中去
	char* p = "12345";//声明指针字符变量p,指向字符串常量首地址
	char b[10] = "12345";//数组名不能左值,
	//char* p;//初始化
	//p = "1234";//赋初值
	b[3] = 'k';
	p++;
	puts(b);
	puts(p);
	system("pause");
}
#endif

#if 0
void main()  {
	char a[] = "123";
	char b[] = "123";
	const char c[] = "123";
	const char d[] = "123";
	char* p = "123";
	char* q = "123";
	const char* pp = "123";
	const char* qq = "123";
	if (a == b)
		printf("a==b\n");
	if (c == d)
		printf("c==d\n");
	if (p == q)
		printf("p==q\n");
	if (pp == qq)
		printf("pp==qq\n");
	if (p == qq)
		printf("p==qq\n");
	system("pause");
}
#endif

#if 0
#include <string.h>
void main() {
	char a[] = "123";
	char b[] = "456";
	char tmp[20];
	strcpy(tmp, a);
	strcpy(a, b);
	strcpy(b, tmp);
	puts(a);
	puts(b);
	system("pause");
}
#endif

#if 0
void main() {
	char* p = "123";
	char* q = "456";
	char* t;
	t = p;
	p = q;
	q = t;
	puts(p);
	puts(q);
	//char a[] = "sfsfasasd";
	//char* p = a;
	system("pause");
}
#endif

#if 0
/*
int a[3][4] a(int(*)[4]),a[i](int*), a[i][j](int)
*/
void main() {
	int a[3][4];
	int(*p)[4];
	int* q[3];
	int i;
	p = a;
	for (i = 0; i < 3; i++) {
		q[i] = a[i];
	}
	system("pause");
}
#endif

#if 0
//转移表
int add(int a, int b){
	return a + b;
}

int sub(int a, int b) {
	return a - b;
}

int mul(int a, int b) {
	return a * b;
}

int div(int a, int b) {
	if (b != 0) {
		return a / b;
	}
}

int mod(int a, int b)  {
	return a % b;
}

void main() {
	/*int(*p)(int, int);//函数指针
	p = add;
	printf("%d\n", p(4, 5));
	p = sub;
	printf("%d\n", p(4, 5));
	p = mul;
	printf("%d\n", p(4, 5));
	p = div;
	printf("%d\n", p(4, 5));*/
	int(*p[])(int, int) = { add, sub, mul, div, mod};//函数指针数组
	int n = sizeof(p) / sizeof(p[0]);
	for (int i = 0; i < n; i++) {
		printf("%d\n", p[i](5, 4));
	}
	system("pause");
}
#endif

#if 0
//函数指针作为参数
int add(int a, int b){
	return a + b;
}

int sub(int a, int b) {
	return a - b;
}

int mul(int a, int b) {
	return a * b;
}

int div(int a, int b) {
	if (b != 0) {
		return a / b;
	}
}

int mod(int a, int b)  {
	return a % b;
}

void test(int a, int b, int(*p) (int, int)) {//add -> p
	printf("%d\n", p(a, b));//add(a, b)
}

void main() {
	test(4, 7, add);
	test(4, 7, sub);
	test(4, 7, mul);
	test(4, 7, div);
	test(4, 7, mod);
	system("pause");
}
#endif

#if 0
//signal函数指针作为返回值
int add(int a, int b){
	return a + b;
}

int sub(int a, int b) {
	return a - b;
}

int mul(int a, int b) {
	return a * b;
}

int div(int a, int b) {
	if (b != 0) {
		return a / b;
	}
}

int mod(int a, int b)  {
	return a % b;
}
//fn函数的返回值是个指针(指向函数(int xx(int, int)))的指针)
int(*fn(int n))(int, int) {
	printf("fn:n = %d\n", n);
	return add;
}
void main(){
	int value = fn(100)(3, 9);//add(3,9)
	//int(*p)(int, int);
	//p = fn(100);
	//p(3, 9);
	printf("%d\n", value);
	system("pause");
}
#endif