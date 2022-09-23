# 1
```c++
binaryTree* first(){
    while(this->lc || this->rc){//在左右孩子都有的情况下优先遍历左子树左子树为空则转到右子树
        if(this->lc) this = this->lc;
        else this = this->rc;
    }
    return this;
}
# 2
```c++
binnaryTree* realBinaryTree::first(){
    if(!this->parent) return NULL;//当前节点是根节点直接返回空
    if(this->parent->lc && !this->parent->rc){//当前有左子树且右子树非空则直接后继是右子树中后序遍历的第一个节点
        return this->parent->rc->first();
    }else{//左孩子为空直接返回他的父亲根节点或者是右孩子
        return this->parent;
    }
}
# 3
+ 遍历过程无非考考虑到最坏情况也就是退化为单链的情况时间复杂度最大为O(n) //待考究