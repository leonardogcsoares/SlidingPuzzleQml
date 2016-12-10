#include "block.h"

Block::Block(QObject *parent) : QObject(parent)
{

}

Block::Block(int index, int value) {
    this->mIndex = index;
    this->mValue = value;
}

int Block::index() {
    return this->mIndex;
}

void Block::setIndex(int index) {
    this->mIndex = index;
}


int Block::value() {
    return this->mValue;
}

void Block::setValue(int value) {
    this->mValue = value;
}
