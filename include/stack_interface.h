//
// Created by yaodi on 2020/1/9.
//

template <typename Elem>
class StackInterface {
public:
    // Must be virtual as we'll inherit from StackInterface.
    virtual ~StackInterface() {};

    virtual int GetSize() const = 0;
    virtual void Push(const Elem& x) = 0;
};
