#include "include/bonzini.h"

int main(int, char**)
{
	Bonzini bonzini("examples\\mov01.mp4");
	bonzini.start(1);
	return 0;
}