/*  
	gcc main.cpp -o main
*/
#include <stdio.h>
//#include <cstring>

void function(const char* p, const int x)
{
    printf("p is \"%s\" and x is %i\n", p, x);
}

int main() {

   printf("Hello World!\n");

	const char* h = "Hello";
	const char* w= "World!";
	printf("%s %s\n", h, w);

	function("foo",7);
	function("moo",8);
	function("roo",9);

	return 0;
}