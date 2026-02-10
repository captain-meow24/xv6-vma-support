//
// Created by kanishka on 5/2/26.
//
#include "types.h"
#include "riscv.h"
#include "defs.h"
#include "VMA.h"

struct vma* find_vma(struct vma* vm, uint64 addr){
    struct vma* temp = vm;
    while(temp){
        if(temp->start <= addr && temp->end > addr){
            return temp;
        }
        temp = temp->next;
    }
    return 0;
}
struct vma* create_node(){
    struct vma* temp = (struct vma*) kalloc();
    if(temp ==0){
        return 0;
    }
    temp->next = 0;
    return temp;
}

