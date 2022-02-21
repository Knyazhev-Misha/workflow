#include"exceptions.h"

const char* fileException::what() const noexcept {
    return "ERROR : File not open\n";
}

const char* DescException::what() const noexcept {
    return "ERROR : File should start with desc\n";
}

const char* CsedException::what() const noexcept {
    return "ERROR : File should start with desc\n";
}

const char* BlockException::what() const noexcept {
    return  "ERROR : use another blocks!\n";
}

const char* equalsException::what() const noexcept {
    return  "ERROR : use equals after id blocks!\n";
}

const char* RightBlockException::what() const noexcept {
    return  "ERROR : use right id blocks!\n";
}

const char* textException::what() const noexcept {
    return  "ERROR : wrong text!\n";
}

const char* queueException::what() const noexcept {
    return  "ERROR : wrong queue!\n";
}
