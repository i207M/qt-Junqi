#ifndef m_debug_H
#define m_debug_H

#include <iostream>
#include <cassert>

// #define M_DEBUG

template<class T>
void err(const T &x, const char c = '\n')
{
// #ifdef M_DEBUG
    std::cerr << x << c;
// #endif
}

template<class T, class ...Args>
void err(const T &x, const Args &...args)
{
    err(x, ' ');
    err(args...);
}

template<class T>
void errprt(T arr, int n)
{
    for(int i = 0; i < n; ++i) {
        err(arr[i], i == n - 1 ? '\n' : ' ');
    }
}

#ifdef M_DEBUG
#define check(flag) assert(flag)
#else
#define check(flag) "NO_DEBUG"
#endif

#endif // m_debug_H
