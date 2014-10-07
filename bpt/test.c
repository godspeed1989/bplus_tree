#include "bpt.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void run_test_bpt()
{
	KEY_T i;
	node * root = NULL, *left;

	for(i = 0; i < 0xFFF; i++)
		root = Insert(root, i, i);

	for(i = 0; i < 0xFFF; i+=2)
		root = Delete(root, i);

	left = Get_Leftmost_Leaf(root);
	while(left)
	{
		for(i = 0; i < left->num_keys; i++)
			printf("(%ld,%ld)", left->keys[i], ((record*)left->pointers[i])->value );
		printf("\n");
		left = left->pointers[order - 1];
	}
#ifdef SUPPORT_PRINT
	Print_To_File(root);
#endif
	Destroy_Tree(root);
}

int main( int argc, char ** argv )
{
	printf("bpt: Our bpt is loading...\r\n");
	run_test_bpt();
	return 0;
}
