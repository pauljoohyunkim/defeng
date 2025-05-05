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
        rootnode->root = rootnode;
        if (depth == 0)
        {
            rootnode->nChild = 0;
            return rootnode;
        }

        // Create children.
        // If rootnode is VOWEL, create two children, One CONSONANT_FORMER, one CONSONANT_LATTER
        // If rootnode is CONSONANT_FORMER, then one child. One VOWEL
        // If rootnode is CONSONANT_LATTER, then one child. One CONSONANT_FORMER
        if (initial == VOWEL)
        {
            rootnode->nChild = 2;
            rootnode->children[0] = createTree(rootnode, depth-1, CONSONANT_FORMER);
            rootnode->children[1] = createTree(rootnode, depth-1, CONSONANT_LATTER);
        }
        else if (initial == CONSONANT_FORMER)
        {
            rootnode->nChild = 1;
            rootnode->children[0] = createTree(rootnode, depth-1, VOWEL);
        }
        else if (initial == CONSONANT_LATTER)
        {
            rootnode->nChild = 1;
            rootnode->children[0] = createTree(rootnode, depth-1, CONSONANT_FORMER);
        }

        return rootnode;
    }
    else
    {
        DefEngTreeNode node = NULL;

        node = calloc(1, sizeof(DefEngTreeNode_st));

        node->parent = parent;
        node->root = parent->root;
        node->depth = depth;
        node->space_type = initial;

        if (node->depth == 0)
        {
            node->nChild = 0;
            return node;
        }
        
        // Create children.
        // If rootnode is VOWEL, create two children, One CONSONANT_FORMER, one CONSONANT_LATTER
        // If rootnode is CONSONANT_FORMER, then one child. One VOWEL
        // If rootnode is CONSONANT_LATTER, then one child. One CONSONANT_FORMER
        if (initial == VOWEL)
        {
            node->nChild = 2;
            node->children[0] = createTree(node, depth-1, CONSONANT_FORMER);
            node->children[1] = createTree(node, depth-1, CONSONANT_LATTER);
        }
        else if (initial == CONSONANT_FORMER)
        {
            node->nChild = 1;
            node->children[0] = createTree(node, depth-1, VOWEL);
        }
        else if (initial == CONSONANT_LATTER)
        {
            node->nChild = 1;
            node->children[0] = createTree(node, depth-1, CONSONANT_FORMER);
        }

        return node;
    }
}

// Set *counted = 0, factor = 1 for calling from defeng.c
void outputSizeTree(DefEngTreeNode node, size_t n_consonants, size_t n_vowels, size_t *counted, size_t factor)
{
    if (node->depth == 0)
    {
        *counted += factor * (node->space_type == CONSONANT ? n_consonants : n_vowels);
    }
    else
    {
        if (node->nChild == 1)
        {
            outputSizeTree(node->children[0], n_consonants, n_vowels, counted, factor * (node->space_type == CONSONANT ? n_consonants : n_vowels));
        }
        else if (node->nChild == 2)
        {
            outputSizeTree(node->children[0], n_consonants, n_vowels, counted, factor * (node->space_type == CONSONANT ? n_consonants : n_vowels));
            outputSizeTree(node->children[1], n_consonants, n_vowels, counted, factor * (node->space_type == CONSONANT ? n_consonants : n_vowels));
        }
    }
}

void freeTree(DefEngTreeNode rootnode)
{
    if (rootnode->depth == 0)
    {
        free(rootnode);
    }
    else
    {
        if (rootnode->nChild == 1)
        {
            freeTree(rootnode->children[0]);
        }
        else if (rootnode->nChild == 2)
        {
            freeTree(rootnode->children[0]);
            freeTree(rootnode->children[1]);
        }
        free(rootnode);
    }
}
