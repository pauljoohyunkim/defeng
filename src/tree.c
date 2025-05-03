#include <stdlib.h>
#include "tree.h"

DefEngTreeNode createTree(DefEngTreeNode parent, uint8_t depth, DefSpace initial)
{
    // If parent == NULL, it is the root node.
    // Else, create a child of the tree.
    if (parent == NULL)
    {

    }
    else
    {
        DefEngTreeNode child = NULL;

        // If depth is zero, stop.
        if (depth == 0)
        {
            return NULL;
        }

        child = calloc(1, sizeof(DefEngTreeNode_st));

        child->parent = parent;
        child->depth = depth - 1;
        
        // If space type is vowel, the child has space type consonant.
        // Otherwise, split
        if (parent->space_type == VOWEL)
        {
            child->space_type = CONSONANT;
        }
        else
        {
            
        }
    }
}