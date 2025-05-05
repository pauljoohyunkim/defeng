#ifndef __TREE_H__
#define __TREE_H__

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include "common.h"

typedef struct DefEngTreeNode_st DefEngTreeNode_st;
typedef DefEngTreeNode_st * DefEngTreeNode;

struct DefEngTreeNode_st
{
    DefSpace space_type;
    uint8_t depth;
    DefEngTreeNode root;
    DefEngTreeNode parent;
    uint8_t nChild;
    DefEngTreeNode children[2];
};

DefEngTreeNode createTree(DefEngTreeNode parent, uint8_t depth, DefSpace initial);
void outputSizeTree(DefEngTreeNode node, size_t n_consonants, size_t n_vowels, size_t *counted, size_t factor);
void freeTree(DefEngTreeNode rootnode);


#endif
