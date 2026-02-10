//
// Created by kanishka on 5/2/26.
//

#ifndef VMA_H
#define VMA_H

#include "types.h"

#define PROT_READ 1
#define PROT_WRITE 2
#define PROT_EXEC 4

struct vma {

    uint64 start;
    uint64 end;
    int prot;
    struct vma* next;
};

struct vma* find_vma(struct vma* vm, uint64 addr);
struct vma* create_node();
#endif //VMA_H
