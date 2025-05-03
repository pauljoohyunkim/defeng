#ifndef __TREE_H__
#define __TREE_H__

#include <stdint.h>
#include <stdbool.h>
#include "common.h"

typedef struct 
{
    DefSpace space_type;
    uint8_t depth;
    DefEngTreeNode parent;
} DefEngTreeNode_st;

typedef DefEngTreeNode_st * DefEngTreeNode;

#endif