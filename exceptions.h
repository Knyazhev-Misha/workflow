#pragma once
#include <stdexcept>

class fileException : public std::exception {
public:
    const char* what() const noexcept override;
};

class DescException : public std::exception {
public:
    const char* what() const noexcept override;
};

class CsedException : public std::exception {
public:
    const char* what() const noexcept override;
};

class BlockException : public std::exception {
public:
    const char* what() const noexcept override;
};

class equalsException : public std::exception {
public:
    const char* what() const noexcept override;
};

class RightBlockException : public std::exception {
public:
    const char* what() const noexcept override;
};

class textException : public std::exception {
public:
    const char* what() const noexcept override;
};

class queueException : public std::exception {
public:
    const char* what() const noexcept override;
};
