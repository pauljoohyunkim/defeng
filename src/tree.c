#include <stdlib.h>
#include "tree.h"

DefEngTreeNode createTree(DefEngTreeNode parent, uint8_t depth, DefSpace initial)
{
    // If parent == NULL, it is the root node.
    // Else, create a child of the tree.
    if (parent == NULL)
    {
        DefEngTreeNode rootnode = calloc(1, sizeof(DefEngTreeNode_st));
        if (rootnode == NULL)
        {
            return NULL;
        }
        
        rootnode->space_type = initial;
        rootnode->depth = depth;
        if (depth == 0)
        {
            rootnode->nChild = 0;
            return rootnode;
        }

        // Create children.
        // If rootnode is VOWEL, then one child with CONSONANT.
        // If rootnode is CONSONANT, then two children. One CONSONANT and one vowel.
        if (initial == VOWEL)
        {
            rootnode->nChild = 1;
            rootnode->children[0] = createTree(rootnode, depth-1, CONSONANT);
        }
        else
        {
            rootnode->nChild = 2;
            rootnode->children[0] = createTree(rootnode, depth-1, CONSONANT);
            rootnode->children[1] = createTree(rootnode, depth-1, VOWEL);
        }

        return rootnode;
    }
    else
    {
        DefEngTreeNode node = NULL;

        node = calloc(1, sizeof(DefEngTreeNode_st));

        node->parent = parent;
        node->depth = depth;
        node->space_type = initial;

        if (node->depth == 0)
        {
            node->nChild = 0;
            return node;
        }
        
        // Create children.
        // If rootnode is VOWEL, then one child with CONSONANT.
        // If rootnode is CONSONANT, then two children. One CONSONANT and one vowel.
        if (initial == VOWEL)
        {
            node->nChild = 1;
            node->children[0] = createTree(node, depth-1, CONSONANT);
        }
        else
        {
            node->nChild = 2;
            node->children[0] = createTree(node, depth-1, CONSONANT);
            node->children[1] = createTree(node, depth-1, VOWEL);
        }



        return node;
        
    }
}