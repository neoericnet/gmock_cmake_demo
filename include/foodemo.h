//
// Created by yaodi on 2020/1/8.
//
#include <utility>
#include <map>

class FooDemo {
public:
    virtual ~FooDemo() {};
    virtual std::pair<bool, int> GetPair() = 0;
    virtual bool CheckMap(std::map<int, double> reqMap, bool flag) = 0;

protected:
    virtual void Resume() = 0;

private:
    virtual int GetTimeOut() = 0;
};
