#ifndef __GENERATOR_H__
#define __GENERATOR_H__

#include <stdio.h>
#include <stddef.h>
#include "cluster.h"
#include "tree.h"

void generate(DefEngTreeNode node, Cluster *consonant_clusters, size_t nConsonants, Cluster *vowel_clusters, size_t nVowels, FILE *fp, Cluster *prefix, size_t nSpace);

#endif
