Interactive B+ Tree  [Amittai's Home](http://www.amittai.com) > [Prose](http://www.amittai.com/prose)

# Interactive B+ Tree

A B+ tree ("bee plus tree") is a data structure  used as an index to facilitate fast access to the elements of a larger body of data,  such as the entries in a database or the blocks of memory storage ("pages") in an operating system. Each target object (entry, page) is associated with an index _key_. The B+ tree is laid out like a family tree, where each node has some number of keys that is between some predetermined maximum limit and half that limit (inclusive).  Each node also has one more pointer than the number of its keys. (A "pointer" is the address of a location in the computer's memory.) You can picture the node as having alternating pointers and keys, starting and ending with pointers.

At the bottom level of the B+ tree are the _leaves_. Each pointer on the leaf except the last (rightmost) one points to the data object whose key stands immediately to the right of that pointer. The  rightmost pointer points to the next leaf over to the right.  Then, each bunch of leaves has its own parent node. If there are enough of these parents, then they, in turn, are divided into bunches, each of which shares but one parent — and this one-parent-many-children family tree goes all the way up to a single ancestor at the top, the _root_. The _internal nodes_, which are the parents, grandparents, etc., of the leaf nodes,  also have keys,  which are (initially) duplicates of _some_ of the keys on the leaves. A given internal node's keys are "representative" copies of a few of the keys to be found on the leaves that are the (ultimate) descendants of that node.  The pointers on the internal nodes point  to nodes at the next level down on the tree, which may be leaves or other internal nodes.

A search starts at the root node (top ancestor) of the tree. Each node has its keys in sorted order. Suppose you are searching for the data associated with some key. Starting at the root and working your way downward through the nodes, you find the smallest-value key in your current node whose value is _greater_ than the value of the key you are seeking, and you follow the pointer to that key's left. If the sought key is greater than the rightmost key in the node, you follow the pointer at  the node's extreme right. You repeat this procedure for each node you encounter as you move down the tree toward the leaves. When you reach a leaf, the key must be there if it exists in the tree at all. If it is, you follow the pointer to that key's left to reach the desired data. If the key is not in the leaf,  then you know that no such data exist. Thus the whole search involves but a few hops through the ranks of the tree. To be more exact, the number of steps in the process is proportional to the logarithm of the whole number of keys. Thus, as data objects and keys are added, the length of the search path grows only very slowly.

The B+ tree preserves this efficient search capability even as you insert or remove data objects and their respective keys arbitrarily. It does so by allowing the nodes to grow and shrink as keys and data are inserted and deleted. When a node has too many keys, it splits in half. When it has too few, it coalesces with a neighboring node.

When you delete a datum with its key, it may happen that duplicates of that key in the internal nodes will remain. This does not harm the B+ tree's efficient operation: the key, though obsolete if it were in a leaf node, still works to direct the search path efficiently through the internal nodes.

The attached code is an implementation of a B+ tree, written in C, whose purpose is merely to show how it works. Once you've successfully compiled the program, you can insert or delete keys and see how the tree grows or shrinks. You can also trace a search path for a specific key through the tree — and various other interactive commands are  available. (Enter **h** at the prompt to see them all.)

This interactive B+ tree demonstration is based on the description and pseudocode of the B+ tree presented in Abraham Silberschatz, Henry F. Korth, and S. Sudarshan, Database System Concepts, 5th ed. (New York: McGraw Hill, 2006), Section 12.3, 489-501. For more information on B+ trees in general, see [B+ tree (Wikipedia)](http://en.wikipedia.org/wiki/B%2B_tree).

You are allowed to download, use, redistribute, and change the source code according to the [GNU GPL v. 3 license](LICENSE.txt).

This code should be regarded as a "beta release." Please e-mail me (amittai dot aviram at gmail dot edu) with comments, questions, bug reports, and corrections. Thank you!

Please download TWO FILES into the same directory:

- [B+ tree source code (C '99) (Version 1.13 – 15 April 2014)](bpt.c)
- [License](LICENSE.txt)

Then compile bpt.c using your C '99 compiler, such as GCC.

#### Recent Version History

- Version 1.13 corrects an array bounds violation and eliminates dead code.
- Version 1.12 enables you to delete an empty tree without causing a segmentation fault.
- Version 1.11 finds ranges by sequential search.
- Version 1.10 adds a "range" command: r  . This displays all records found within this range, including both range\_start and range\_end, if present.
- Version 1.9 makes the bounds on order into #defined symbolic constants and adds more informative comments, an error message, and a usage note pertaining to the order bounds.
- Version 1.8 removes a special condition from the GPL v. 3 license. The license text is now the same as the generic license text provided by Gnu.
- Version 1.7 corrects a test condition in insert\_into\_leaf\_after\_splitting.
- Version 1.6 adds GNU GPL v. 3 notifications and output features, cleans up switch statement in main, and fixes cast mismatches in print statements.
- Version 1.5 moves enqueueing to the outer loop in print\_tree and  corrects the logic of shifting keys in redistribution after deletion.
- Version 1.4 corrects the opening “usage” message to report the actual order and removes the redundant assignment of the default order in main.
- Version 1.3 fixes a bug in the redistribution routine for when a deletion causes a leftmost internal node to become too small, so that it must take a pointer from its neighbor to the right.
- Version 1.2 fixes two bugs: (1) an array bounds mistake and (2) failure to distinguish between leaf and nonleaf nodes in deciding between coalescence and redistribution.
- Version 1.1 fixes two bugs: missing return value in start\_new\_tree and  the use of close instead of fclose. It also eliminates other causes of GCC warnings.
- Version 1.0 fixes a bug (non-initialization) and makes the code more portable by providing alternative definitions for the bool type and its values. If you are  compiling under Windows, please uncomment the definition of WINDOWS. Since this version comes after testing by other users (see below), it starts the "1.x" series.
- Version 0.12 allows you to start with input from a file containing integers, with one integer per line. (See the start-up usage message.) It also provides a  _destroy tree_ function with the 'x' command, which deletes the entire tree at once and returns an empty tree.

#### Acknowledgements

Many thanks to the following kind users for sending me their bug reports and suggestions:

- Hari Krishna Doredla
- Naresh Kosaraju
- Ajay Kumar Patibandla
- Kiran Shankar Ambati
- Kiril Fabisevich
- Jens Alfke
- Han Feng
- Kevin Schultz
- Jiang Shi Yi
- Majed Sahli
- Zhensong Qian
- Dai Son Nguyen
- Zhang Hubin
- Yán Lín
