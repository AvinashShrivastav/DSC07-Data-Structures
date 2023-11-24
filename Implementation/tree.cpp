#include <iostream>
using namespacce std;

template <typename E>
class Position <E> {
    public:
    E& operator*();
    Position parent() const;
    PositionList children() const;
    bool isRoot() const;
    bool isExternal() const;

};

template <typename E>
class Tree<E> {
    public: //Data Menbers
    class Position;
    class PositionList;

    public: //Functions
    int size() const;
    bool empty() const;
    Position root() const;
    PositionList positions() const;
};

//Where is PositionList definition??