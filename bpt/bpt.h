#ifndef __BPT_H__
#define __BPT_H__

#define SUPPORT_PRINT

#include <stdlib.h>
#include <assert.h>
#define MALLOC(n)       malloc(n)
#define FREE(p)         free(p)
#define ASSERT(expr)    assert(expr)

#ifndef TRUE
#define TRUE    1
#endif
#ifndef FALSE
#define FALSE   0
#endif
#ifndef BOOL
#define BOOL    int
#endif
#ifndef ULONG
typedef unsigned long ULONG;
#endif

#define KEY_T           ULONG
#define VAL_T           ULONG
#define order           (KEY_T)(16)

typedef struct _node
{
    // node: array of nodes corresponding to keys
    // leaf: with a maximum of order-1 key-pointer
    //       The last pointer points to the right leaf
    void             ** pointers;
    KEY_T             * keys;
    KEY_T               num_keys;
    BOOL                is_leaf;
    struct _node      * parent;
    struct _node      * next;
} node;

typedef struct _record
{
    VAL_T               value;
} record;

KEY_T       CUT ( KEY_T length );

node *      Make_Node ( void );
void        Free_Node ( node * n );
record *    Make_Record ( VAL_T value );
void        Free_Record ( record * n );

node *      Insert ( node * root, KEY_T key, VAL_T value );
node *      Delete ( node * root, KEY_T key );

node *      Find_Leaf ( node * root, KEY_T key );
record *    Find_Record ( node * root, KEY_T key );
node*       Get_Leftmost_Leaf(node *root);
node *      Destroy_Tree ( node * root );

#ifdef SUPPORT_PRINT
void        Print_To_File( node * root );
#endif

#endif
