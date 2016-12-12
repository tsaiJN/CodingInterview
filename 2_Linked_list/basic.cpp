#include<stdio.h>
#include<stdlib.h>

class Node {

public:
    Node* next;
    Node* prev;
    int data;

    Node(int d) {
        this->data = d;
        this->prev = NULL;
        this->next = NULL;
    }

    Node* findHead() {
        Node* n = this;
        while (n->prev) {
            n = n->prev;
        }
        return n;
    }

    Node* findTail() {
        Node* n = this;
        while (n->next) {
            n = n->next;
        }
        return n;
    }

    Node* findMiddle() {
        // using the runner technique
        Node* b1, * b2;
        b1 = this->findHead();
        b2 = b1;
        while(b2) {
            if(!b2->next) break;
            b2 = b2->next->next;
            b1 = b1->next;
        }
        return b1;
    }
    
    void appendToTail(int d) {
        Node* end = new Node(d);
        Node* n = this->findTail();
        end->prev = n;
        n->next = end;
    }

    void insertToHead(int d) {
        Node* head = new Node(d);
        Node* n = this->findHead();
        head->next = n;
        n->prev = head;
    }


    void printWholeList() {
        Node* n = this->findHead();
        while (n->next) {
            printf("%d ", n->data);
            n = n->next;
        }
        printf("%d \n", n->data);
    }

    void detach() {
        // won't deallocate

        if(this->prev) this->prev->next = this->next;
        if(this->next) this->next->prev = this->prev;
        this->next = NULL;
        this->prev = NULL;
    }

    void insertInFront(Node* n) {
        if (this->prev) this->prev->next = n;
        n->prev = this->prev;
        n->next = this;
        this->prev = n;
    }

    void insertBehind(Node* n) {
        if (this->next) this->next->prev = n;
        n->next = this->next;
        n->prev = this;
        this->next = n;
    }

    Node* mergesort() {
        // in-place mergesort
        // return: Head of the sortedList
        if (!this->next) return this;

        // divide
        Node* head = this->findHead();
        Node* middle = this->findMiddle();
        if(middle->prev) {
            // assign middle to second sublist
            middle->prev->next = NULL;
            middle->prev = NULL;
        }
        Node* left = head->mergesort();
        Node* right = middle->mergesort();
        Node* ret = left;

        // combine
        while(left && right) {
            if(right->data < left->data) {
                Node* cache = right;
                right = right->next;
                cache->detach();
                left->insertInFront(cache);
            }else left = left->next;
        }
        if (right) {
            Node* temp = ret->findTail();
            temp->next = right;
            right->prev = temp;
        }

        return ret->findHead();


    }

    int reportKthToTheEndR() {
        // recursive version
        if (!this->next) return 1; // the last node
        return this->next->reportKthToTheEndR()+1;
    }
    
    Node* reportKthToTheEnd(int k) {
        // non-recursive version (runner method)
        Node* p1 = this->findHead();
        Node* p2 = p1;
        int i;
        for (i=0; i<k-1; i++) {
            if (p2->next) p2 = p2->next;
            else return NULL; // the list is shorter than k
        }
        while(p2->next) {
            p1 = p1->next;
            p2 = p2->next;
        }
        return p1;
    }

    static Node* ListAdd(Node* list1, Node* list2) {
        // a linked list adder that can handle big numeric add
        Node* p1 = list1->findHead();
        Node* p2 = list2->findHead();
        Node* ret = new Node(1); // dummy head;
        int sum;
        while(p1 && p2) {
            sum = p1->data + p2->data;
            if (p1->next) p1->next->data += sum / 10;
            else if (p2->next) p2->next->data += sum / 10;
            ret->insertBehind(new Node(sum%10));
            ret = ret->next;
            p1 = p1->next;
            p2 = p2->next;
        }
        Node* stillRunning = (p1)?p1:p2;
        while(stillRunning) {
            sum = stillRunning->data;
            if (stillRunning->next) stillRunning->next->data += sum / 10;
            ret->insertBehind(new Node(sum%10));
            stillRunning = stillRunning->next;
            ret = ret->next;
        }
        if (sum/10 > 0) {
            ret->insertBehind(new Node(sum/10));
        }
        ret = ret->findHead();
        Node* ret2 = ret->next;
        ret->detach();
        return ret2;
    }
};

int main() {

    // basic check
    Node list = Node(5);
    list.appendToTail(4);
    list.insertToHead(2);
    list.printWholeList();


    // 2.1 check
    list.appendToTail(6);
    list.appendToTail(6);
    list.appendToTail(3);
    list.appendToTail(4);
    list.insertToHead(2);
    list.insertToHead(3);
    list.printWholeList();
    
    list.findHead()->mergesort()->printWholeList();

    // 2.2 check
    printf("%dth to the end: %d\n", 3, list.reportKthToTheEnd(3)->data);

    // 
    Node list2 = Node(4);
    list2.appendToTail(5);
    list2.appendToTail(7);
    list2.appendToTail(9);
    list2.appendToTail(9);
    list2.appendToTail(9);
    list2.appendToTail(9);
    list2.appendToTail(9);
    list2.appendToTail(9);
    printf("Adding: \n");
    list.printWholeList();
    list2.printWholeList();
    Node* addResult = Node::ListAdd(&list, &list2);
    addResult->printWholeList();
}
