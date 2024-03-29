#include "assignment/merge_sort.hpp"

#include "assignment/partitioning.hpp"  // middle_of
#include "assignment/merging.hpp"       // merge

namespace assignment {

  void MergeSort::Sort(std::vector<int>& arr) const {

    // буфер памяти для операции слияния (merge)
    std::vector<int> buf(arr.size());

    // забыл что-то здесь вызвать ...
    merge_sort(arr, 0, arr.size()-1, buf);
  }

  void MergeSort::merge_sort(std::vector<int>& arr, int start, int stop, std::vector<int>& buf) const {

    // выход из рекурсии: подмассив длины один
    if (start >= stop) {
      return;
    }

    // вычисляем индекс середины области
    const int middle = middle_of(start, stop);

    // рекурсивный вызов сортировки левой [start, middle] и правой [middle + 1, stop] подмассивов ...

    merge_sort(arr, start, middle, buf);
    merge_sort(arr, middle+1, stop, buf);

    // слияния двух подмассивов [start, middle] и [middle + 1, stop] ...

    merge(arr, start, middle, stop, buf);
  }

}  // namespace assignment
