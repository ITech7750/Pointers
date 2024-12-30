#ifndef LAB2_QUICKSORTER_H
#define LAB2_QUICKSORTER_H

#include "../BaseSorter.h"

template<typename T>
class QuickSorter : public BaseSorter<T> {
public:
    void Sort(MutableSequence<T>* seq, int (*cmp)(const T&, const T&)) override {
        quickSort(seq, 0, seq->size() - 1, cmp);
    }

private:
    void quickSort(MutableSequence<T>* seq, int low, int high, int (*cmp)(const T&, const T&)) {
        if (low < high) {
            int pivotIndex = partition(seq, low, high, cmp);
            quickSort(seq, low, pivotIndex - 1, cmp);
            quickSort(seq, pivotIndex + 1, high, cmp);
        }
    }

    int partition(MutableSequence<T>* seq, int low, int high, int (*cmp)(const T&, const T&)) {
        T pivot = seq->get(high);
        int i = low;
        for (int j = low; j < high; ++j) {
            if (cmp(seq->get(j), pivot) <= 0) {
                this->swap(seq, i, j);
                ++i;
            }
        }
        this->swap(seq, i, high);
        return i;
    }
};

#endif