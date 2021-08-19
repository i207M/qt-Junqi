#ifndef MDEBUG_H
#define MDEBUG_H

#include <iostream>
using std::cerr;

template<class T>inline void err(const T &x, const char c = '\n')
{
    cerr << x << c;
}

template<class T, class ...Args>inline void err(const T &x, const Args &...args)
{
    err(x, ' ');
    err(args...);
}

template<class T>inline void errprt(T a, int n)
{
    --n;
    for(int i = 0; i < n; ++i) {
        err(a[i], ' ');
    }
    err(a[n], '\n');
}

#endif // MDEBUG_H
