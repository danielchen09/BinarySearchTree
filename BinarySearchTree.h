#include "Node.h"
#include <stdio.h>
#include <vector>

class BinarySearchTree{
    public:
        BinarySearchTree(std::vector<int>& arr){
            this->arr = arr;
            this->head = new Node(arr[0], 0);
            for(unsigned int i=1; i<arr.size(); i++){
                add(arr[i], i);
            }
        }

        void add(int value, int index){
            this->add(this->head, new Node(value, index));
        }

        Node* min(Node* min = NULL){
            if(!min) min = head;
            while(min->leftChild){
                min = min->leftChild;
            }
            printf("minimum of tree(@%p): %d\n", (void*)min, min->value);
            return min;
        }

        Node* max(Node* max = NULL){
            if(!max) max = head;
            while(max->rightChild){
                max = max->rightChild;
            }
            printf("maximum of tree(@%p): %d\n", (void*)max, max->value);
            return max;
        }

        Node* find(int value){
            Node* target = head;
            while(target->value != value){
                if(value < target->value){
                    if(target->leftChild){
                        target = target->leftChild;
                    }else{
                        printf("value %d not found\n", value);
                        return NULL;
                    }
                }else{
                    if(target->rightChild){
                        target = target->rightChild;
                    }else{
                        printf("value %d not found\n", value);
                        return NULL;
                    }
                }
            }
            printf("value %d found at %p\n", value, (void*)target);
            return target; 
        }

        void remove(int value){
            Node* target = this->find(value);
            if(!target){
                printf("value %d not found\n", value);
                return;
            }
            this->remove(target); 
        }

        void remove(Node* target){
            Node* replacement = target->rightChild;
            if(target->leftChild){
                replacement = this->max(target->leftChild);
                replacement->leftChild = target->leftChild;
                if(replacement->leftChild == replacement) replacement->leftChild = NULL;
                replacement->rightChild = target->rightChild;
            }

            if(replacement) replacement->parent->rightChild = NULL;

            if(target == head){
                head = replacement;
                target->leftChild->parent = replacement;
            }else{
                if(target->value < target->parent->value){
                    target->parent->leftChild = replacement;
                }else{
                    target->parent->rightChild = replacement;
                }
            }

            printf("deleted value %d (@%p)\n", target->value, target);
            delete target;
        }

        void print(){
        
        }

    private:
        std::vector<int> arr;
        Node* head;

        void add(Node* target, Node* current){
            if(current->value < target->value){
                if(!target->leftChild){
                    target->leftChild = current;
                    current->parent = target;
                    return;
                }
                this->add(target->leftChild, current);
            }else{
                if(!target->rightChild){
                    target->rightChild = current;
                    current->parent = target;
                    return;
                }
                this->add(target->rightChild, current);
            }
        }
};
