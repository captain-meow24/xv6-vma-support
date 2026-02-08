//
// Created by kanishka on 5/2/26.
//
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
