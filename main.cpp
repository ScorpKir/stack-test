#include "fill.h"

int main() {
    try {
        // заполняем столбец Начислено
        fillAccruals();
        // заполняем начисления по домам
        fillHomeAccruals();
    }
    catch (const std::exception& ex) {
        std::cout << "ERROR: " << ex.what() << std::endl;
    }
    return 0;
}

