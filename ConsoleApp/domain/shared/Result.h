#ifndef RESULT_H
#define RESULT_H

#include <string>

using namespace std;

class Result {
private:
    int result;
    wstring resultMsg;

    Result(const int result, const wstring &message);

public:
    const int getResult() const;
    const wstring getMessage() const;
    bool isOK() const;
    bool isNOK() const;
    bool operator == (const Result& other) const;
    static const Result OK();
    static const Result OK(const wstring &message);
    static const Result NOK(const wstring &message);
    static const Result NOK(int number,const wstring &message);
};

#endif //RESULT_H