class Node{
public:
    Node(Node* parent, Node* leftChild, Node* rightChild, int value, int index){
        this->parent = parent;
        this->leftChild = leftChild;
        this->rightChild = rightChild;
        this->value = value;
        this->index = index;    
    }

    Node(int value, int index){
        this->value = value;
        this->index = index;
    }

    Node(){
    }

    Node* parent;
    Node* leftChild;
    Node* rightChild;
    int value;
    int index;
};
