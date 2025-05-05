#ifndef __GENERATOR_H__
#define __GENERATOR_H__

#include <stdio.h>
#include <stddef.h>
#include "cluster.h"
#include "tree.h"

void generate(DefEngTreeNode node, ClusterList *consonant_former_clusterlist, ClusterList* consonant_latter_clusterlist, ClusterList *vowel_clusterlist, FILE *fp, Cluster *prefix);

#endif
