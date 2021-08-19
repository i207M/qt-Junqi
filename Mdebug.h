#ifndef MDEBUG_H
#define MDEBUG_H

#define M_DEBUG

#include <iostream>

template<class T>inline void err(const T &x, const char c = '\n')
{
#ifdef M_DEBUG
    std::cerr << x << c;
#endif
}

template<class T, class ...Args>inline void err(const T &x, const Args &...args)
{
    err(x, ' ');
    err(args...);
}

template<class T>inline void errprt(T a, int n)
{
    for(int i = 0; i < n; ++i) {
        err(a[i], i == n - 1 ? '\n' : ' ');
    }
}

#endif // MDEBUG_H
