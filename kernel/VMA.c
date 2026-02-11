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
    temp->start = 0;
    temp->end = 0;
    return temp;
}
struct vma* init_vma(struct vma* root, uint64 start, uint64 end, int prot) {
    if(root == 0) {
        root = create_node();
        if(root == 0) {
            return root; //ran out of memory, allocation failed
        }
        root->start = start;
        root->end = end;
        root->prot = prot;
    }
    else{
        struct vma* tmp = root;
        while(tmp->next != 0){
            tmp = tmp->next;
        }
        tmp->next = create_node();
        if(tmp->next == 0) {
            return root; //ran out of memory, allocation failed
        }
        tmp->next->start = start;
        tmp->next->end = end;
        tmp->next->prot = prot;
    }
    return root;
}
