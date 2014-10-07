Interactive B+ Tree

# Interactive B+ Tree

A B+ tree ("bee plus tree") is a data structure 

At the bottom level of the B+ tree are the _leaves_. Each pointer on the leaf

A search starts at the root node (top ancestor) of the tree. Each node has its

The B+ tree preserves this efficient search capability even as you insert or remove

When you delete a datum with its key, it may happen that duplicates of that key in

The attached code is an implementation of a B+ tree, written in C, whose purpose is merely

This interactive B+ tree demonstration is based on the description and pseudocode

You are allowed to download, use, redistribute, and change the source code according

This code should be regarded as a "beta release." Please e-mail me

Please download TWO FILES into the same directory:

- [B+ tree source code (C '99) (Version 1.13 – 15 April 2014)](bpt.c)
- [License](LICENSE.txt)

Then compile bpt.c using your C '99 compiler, such as GCC.

#### Recent Version History

- Version 1.13 corrects an array bounds violation and eliminates dead code.
- Version 1.12 enables you to delete an empty tree without causing a segmentation fault.
- Version 1.11 finds ranges by sequential search.
- Version 1.10 adds a "range" command: r  .
- Version 1.9 makes the bounds on order into #defined
- Version 1.8 removes a special condition from the GPL v. 3 license. The license text
- Version 1.7 corrects a test condition in insert\_into\_leaf\_after\_splitting.
- Version 1.6 adds GNU GPL v. 3 notifications and output features, cleans up
- Version 1.5 moves enqueueing to the outer loop in print\_tree and 
- Version 1.4 corrects the opening “usage” message to report
- Version 1.3 fixes a bug in the redistribution routine for when a deletion
- Version 1.2 fixes two bugs: (1) an array bounds mistake and (2) failure to
- Version 1.1 fixes two bugs: missing return value in start\_new\_tree and 
- Version 1.0 fixes a bug (non-initialization) and makes the code more portable
- Version 0.12 allows you to start with input from a file containing integers, with one

#### Acknowledgements

Many thanks to the following kind users for sending me their bug reports

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