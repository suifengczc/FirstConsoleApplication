
#include "stdafx.h"
#include<iostream>

extern int support_count;
void write_extern(void) 
{
	std::cout << "Count = " << support_count << std::endl;
}