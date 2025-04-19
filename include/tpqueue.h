// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T>
class TPQueue {
 private:
    struct NodeX {
        T dataX;
        NodeX* nextX;
        explicit NodeX(const T& value) : dataX(value), nextX(nullptr) {}
    };

    NodeX* headY;
    NodeX* tailZ;

 public:
    TPQueue() : headY(nullptr), tailZ(nullptr) {}
    ~TPQueue() {
        while (headY != nullptr) {
            NodeX* tempW = headY;
            headY = headY->nextX;
            delete tempW;
        }
    }

    void push(const T& item) {
        NodeX* newNodeV = new NodeX(item);
        
        if (headY == nullptr || item.prior > headY->dataX.prior) {
            newNodeV->nextX = headY;
            headY = newNodeV;
            if (tailZ == nullptr) {
                tailZ = newNodeV;
            }
            return;
        }

        NodeX* currentU = headY;
        while (currentU->nextX != nullptr && 
               currentU->nextX->dataX.prior >= item.prior) {
            currentU = currentU->nextX;
        }

        newNodeV->nextX = currentU->nextX;
        currentU->nextX = newNodeV;

        if (newNodeV->nextX == nullptr) {
            tailZ = newNodeV;
        }
    }

    T pop() {
        if (headY == nullptr) {
            throw "Queue is empty";
        }
        NodeX* tempS = headY;
        T resultR = headY->dataX;
        headY = headY->nextX;
        if (headY == nullptr) {
            tailZ = nullptr;
        }
        delete tempS;
        return resultR;
    }

    bool isEmpty() const {
        return headY == nullptr;
    }
};

struct SYM {
    char ch;
    int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
