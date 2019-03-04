//
// Created by work on 03.03.2019.
//

#include <malloc.h>
#include <cstring>
#include <cstdio>
#include <limits.h>
#include "structs.h"

#ifndef MR2018_TREES_H
#define MR2018_TREES_H

#endif //MR2018_TREES_H

class binaryTreePoint;

class binaryTreePointStack;

class binaryTreePointList;

class binaryTreePoint {
private:
    binaryTreePoint * leftChild;
    binaryTreePoint * rightChild;
public:
    bool hasLeftChild;
    bool hasRightChild;
    int value;
    binaryTreePoint(binaryTreePoint &input) {
        if(input.hasLeftChild) {
            this->leftChild = input.leftChild;
        }
        this->hasLeftChild = input.hasLeftChild;
        if(input.hasRightChild) {
            this->rightChild = input.rightChild;
        }
        this->hasRightChild = input.hasRightChild;
        this->value = input.value;
    }
    binaryTreePoint() : hasLeftChild(false), hasRightChild(false) {

    }
    binaryTreePoint(int value) : hasLeftChild(false), hasRightChild(false) {
        this->value = value;
    }
    /*   void operator = (binaryTreePoint &input) {
           if(input.hasLeftChild) {
               this->hasLeftChild = true;
               this->leftChild = input.leftChild;
           }
           if(input.hasRightChild) {
               this->hasRightChild = true;
               this->rightChild = input.rightChild;
           }
           this->value = input.value;
       }*/

    void setLeftChild(binaryTreePoint * child) {
        hasLeftChild = true;
        leftChild = child;
    }
    void setRightChild(binaryTreePoint * child) {
        hasRightChild = true;
        rightChild = child;
    }
    void setValue(int value) {
        this->value = value;
    }

    binaryTreePoint returnLeftChild() {
        if(hasLeftChild) {
            return *leftChild;
        }
        binaryTreePoint voidret;
        return voidret;
    }

    binaryTreePoint returnRightChild() {
        if(hasRightChild) {
            return *rightChild;
        }
        binaryTreePoint voidret;
        return voidret;
    }
};

class binaryTreePointStack {
private:
    binaryTreePoint * data;
    unsigned int size;
public:
    binaryTreePointStack() : size(0) {
        data = (binaryTreePoint * )0;
    }

    binaryTreePointStack(binaryTreePointStack &input) {
        this->size = input.size;
        this->data = (binaryTreePoint * )malloc(size * sizeof(binaryTreePoint));
        memcpy(this->data, input.data, sizeof(binaryTreePoint) * size);
    }

    void push(binaryTreePoint input) {
        binaryTreePoint * temp = (binaryTreePoint * )malloc((size + 1) * sizeof(binaryTreePoint));
        memcpy(temp, data, sizeof(binaryTreePoint) * size);
        temp[size] = input;
        size++;
        free(data);
        data = temp;
    }

    binaryTreePoint pop() {
        if(size == 0) {
            binaryTreePoint voidOut;
            return voidOut;
        }
        size--;
        binaryTreePoint * temp = (binaryTreePoint * )malloc((size) * sizeof(binaryTreePoint));
        memcpy(temp, data, sizeof(binaryTreePoint) * size);
        binaryTreePoint out = data[size];
        free(data);
        data = temp;
        return out;
    }

    unsigned int getSize() {
        return size;
    }
};

class binaryTreePointList {
private:
    binaryTreePoint * data;
    unsigned int size;
public:
    binaryTreePointList() : size(0) {
        data = (binaryTreePoint * )0;
    }

    binaryTreePointList(binaryTreePointList &input) {
        this->size = input.size;
        this->data = (binaryTreePoint * )malloc(size * sizeof(binaryTreePoint));
        memcpy(this->data, input.data, sizeof(binaryTreePoint) * size);
    }

    void Add(binaryTreePoint input) {
        binaryTreePoint * temp = (binaryTreePoint * )malloc((size + 1) * sizeof(binaryTreePoint));
        memcpy(temp, data, sizeof(binaryTreePoint) * size);
        temp[size] = input;
        size++;
        free(data);
        data = temp;
    }

    void Print() {
        for(int i = 0; i < size; i++) {
            printf("%d\t", data[i].value);
        }
    }

    void search1(binaryTreePoint head) {

        Add(head);
        int i = 0;

        while(i < size) {
            binaryTreePoint temp;

            if(data[i].hasLeftChild) {
                temp = data[i].returnLeftChild();
                Add(temp);
            }

            if (data[i].hasRightChild) {
                temp = data[i].returnRightChild();
                Add(temp);
            }
            i++;
        }
        Print();
    }

    void search2(binaryTreePoint head) {

        int i = size;
        binaryTreePointStack stack;
        stack.push(head);
        while(1) {
            binaryTreePoint temp1;
            temp1 = stack.pop();
            Add(temp1);

            binaryTreePoint temp2;

            if(temp1.hasRightChild) {
                temp2 = temp1.returnRightChild();
                stack.push(temp2);
            }

            if (temp1.hasLeftChild) {
                temp2 = temp1.returnLeftChild();
                stack.push(temp2);
            }
            if(stack.getSize() == 0) break;
        }
        Print();
    }
};



class B_TreePoint {
private:

    List<B_TreePoint *> list;
    List<unsigned long int> keys;

    B_TreePoint * parent;
    unsigned int size;
    unsigned int keyMax;

public:
    int value;
    unsigned long int getKey() {
        return keys.getItem(0);
    }
    B_TreePoint() : size(0), keyMax(UINT_MAX) {
        keys.add(0);
        parent = (B_TreePoint *)0;
    }
    B_TreePoint(unsigned int size) {
        this->size = size;
        keys.add(0);
        parent = (B_TreePoint *)0;
    }
    B_TreePoint(B_TreePoint &input) {
        this->size = input.size;

        this->keys = input.keys;
        this->list = input.list;

        this->value = input.value;
        this->parent = input.parent;
    }

    void keysRestruct(unsigned long int NewKey) {
        List<unsigned long int> temp;
        temp.add(NewKey);
        if(list.getSize() != 0) {
            unsigned long int keyStep = (keyMax - keys.getItem(0)) / size;
            for (int i = 1; i < list.getSize(); i++) {
                temp.add(temp.getItem(0) + keyStep * i);
                (*list.getItem(i - 1)).keyMax = temp.getItem(i);
                (*list.getItem(i - 1)).keysRestruct(temp.getItem(i - 1));
            }
            if(list.getSize() > 0) {
                (*list.getItem(list.getSize() - 1)).keyMax = keyMax;
                (*list.getItem(list.getSize() - 1)).keysRestruct(temp.getItem(temp.getSize() - 1));
            }
        }
        keys = temp;
    }

    unsigned int getChildNumber() {
        return list.getSize();
    }

    B_TreePoint * returnChild(unsigned int number) {
        if(number < list.getSize()) return list.getItem(number);
        printf("there aren't any child with this number");
        exit(1);
    }

    void addChild(B_TreePoint * child) {
        if(list.getSize() < size) {
            list.add(child);
            unsigned long int keyStep = ( keyMax - keys.getItem(0) ) / size;
            keys.add(keys.getItem(keys.getSize() - 1) + keyStep);
            keysRestruct(keys.getItem(0));
            return;
        }
        printf("Error: overflau of point");
        exit(1);
    }


    void deleteChild(unsigned int number) {
        if(number >= size) {
            printf("there aren't any child with this number");
            exit(1);
        }
        list.deleteItem(number);
        keysRestruct(keys.getItem(0) + 1);
    }


    void setValue(int value) {
        this->value = value;
    }

    void resize(unsigned int size) {

        this->size = size;
        if(list.getSize() > size) {
            printf("Error: Overflau of point");
            exit(1);
        }

    }

    void Print() {
        printf("%d\t", value);
    }


    template <typename Ret>
    void visiting1WithAction(Ret (*action)(B_TreePoint *)) {
        List<B_TreePoint*> List;
        List.add(this);
        action(this);

        int i = 0;
        while(i < List.getSize()) {
            B_TreePoint * temp = List.getItem(i);
            for(int j = 0; j < (*temp).list.getSize(); j++) {
                List.add((*temp).returnChild(j));
                action((*temp).returnChild(j));
            }
            i++;
        }
    }

    template <typename Ret>
    Ret search(unsigned long int key, Ret (*action)(B_TreePoint *)) {

        if(keys.getItem(0) == key) {
           return action(this);
        }

        if(keyMax < key) {
            printf("Error: can't find item");
            exit(1);
        }

        unsigned int i;
        for(i = 1; i < keys.getSize(); i++) {
            if( keys.getItem(i) >= key ) {
                break;
            }
        }
        i--;
        (*returnChild(i)).search(key, action);
    }


    template <typename Ret>
    void visiting2WithAction(Ret (*action)(B_TreePoint *)) {
        Stack<B_TreePoint*> Stack;
        Stack.push(this);

        int i = Stack.getSize();
        while(i > 0) {
            B_TreePoint * temp = Stack.pop();
            action(temp);
            for(int j = (*temp).list.getSize() - 1; j >= 0; j--) {
                Stack.push((*temp).returnChild(j));
            }
            i = Stack.getSize();
        }
    }

};

