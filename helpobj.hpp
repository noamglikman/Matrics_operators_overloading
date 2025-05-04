#ifndef HELPOBJ_H
#define HELPOBJ_H
#include <stdexcept>
#include <iostream>
#include <iomanip>

namespace matrix {
    class helpobj {
        private:
            int size;
            double* mat;
        public:
            helpobj(int size, double* mat) : size(size), mat(mat) {}
            ~helpobj() {
            }

            double & operator[](int index) {
                if (index < 0 || index >= size) {
                    throw std::out_of_range("Index out of bounds");
                }
                return mat[index];
            }
    };

}

#endif