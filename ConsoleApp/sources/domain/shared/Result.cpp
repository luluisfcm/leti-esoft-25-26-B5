#include <stdexcept>
#include "headers/domain/shared/Result.h"

Result::Result(const int result, const wstring &message) {
    this->result = result;
    this->resultMsg = message;
}

const int Result::getResult() const {
    return this->result;
}

const wstring Result::getMessage() const {
    return this->resultMsg;
}

bool Result::operator==(const Result &other) const {
    if (&other == this) return true;
    return (this->result == other.result);
}

bool Result::isOK() const {
    return (this->result == 0);
}

bool Result::isNOK() const {
    return !this->isOK();
}

const Result Result::OK() {
    return Result(0,L"");
}

const Result Result::OK(const wstring &message) {
    return Result(0,message);
}

const Result Result::NOK(const wstring &message) {
    return Result(-1,message);
}

const Result Result::NOK(int number, const wstring &message) {
    if (number != 0)
        return Result(number, message);
    throw invalid_argument("A NOK result cannot have a 'zero' error number.");
}