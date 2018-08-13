/*
	题目描述：
	输入一个复杂链表（每个节点中有节点值，以及两个指针，
	一个指向下一个节点，另一个特殊指针指向任意一个节点），
	返回结果为复制后复杂链表的head。
	（注意，输出结果中请不要返回参数中的节点引用，否则判题程序会直接返回空）
*/
/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if(!pHead) return NULL;
        RandomListNode* pNode = pHead;
        RandomListNode* cloneNode;
        while(pNode)
        {
            cloneNode = new RandomListNode(pNode->label);
            cloneNode->next = pNode->next;
            cloneNode->random = NULL;
            pNode->next = cloneNode;
            pNode = cloneNode->next;
        }
        pNode = pHead;
        while(pNode)
        {
            cloneNode = pNode->next;
            if(pNode->random)
            {
                cloneNode->random = pNode->random->next;
            }
            pNode = cloneNode->next;
        }
        RandomListNode* cloneHead = pHead->next;
        RandomListNode* tmp;
        pNode = pHead;
        while(pNode->next)
        {
            tmp = pNode->next;
            pNode->next = tmp->next;
            pNode = tmp;
        }
        return cloneHead;
    }
};