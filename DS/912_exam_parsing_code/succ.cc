#include<bit/stds.h>
using namespace std;

struct BinNode{
    BinNodePosi(T) lc;
    BinNodePosi(T) rc;
    BinNodePosi(T) preTralsucc();
    BinNodePosi(T) inTralsucc();
}

template <tyname T>
BinNodePosi(T) BinNode<T>::preTralsucc(){
    BinNodePosi(T) s = this;//记录后继
    if(lc){//有左孩子则直接后继在左孩子中
        return lc;
    }else if(rc) {//没有左孩子
        return rc;
    }else{//左右孩子为空，找到包含在左子树中且右孩子不为空的最低祖先
        while(s){
            while(IsRChild(*s)) s = s->parent;
            s = s->parent;
            if(!s && s->rc) return s->rc;
        }
        return NULL;
    }
}

template <tyname T>
BinNodePosi(T) BinNode<T>::inTralsucc(){
    BinNodePosi(T) s = this;//记录后继
    if(rc){//若有右孩子直接后继就是右孩子中最小的节点
        s = rc;
        while(hasChild(*s)) s = s->lc;
    }else{
        while(IsRChild(*s)) s = s->parent;//右孩子逆向沿右侧分支朝着左上方移动
        s = s->parent;//(如果是左孩子后继就是其父亲节点如果是右孩子那么经过上面的移动就只需要再最后移动一次)在朝着右上方移动一步
    }
    return s;
}
