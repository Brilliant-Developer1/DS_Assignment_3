// #include<bits/stdc++.h>
#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <complex>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cwchar>
#include <cwctype>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <random>
#include <regex>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <strstream>
#include <tuple>
#include <typeinfo>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <valarray>
#include <vector>

// #include<bits/stdc++.h>
using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    // Take input of Stack and Queue
    stack<int> st;
    queue<int> que;
    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;
        st.push(x);
    }

    for (int i = 0; i < M; i++)
    {
        int x;
        cin >> x;
        que.push(x);
    }
    // Transfer values to list
    list<int> stList;
    list<int> queList;
    while (!st.empty())
    {
        stList.push_back(st.top());
        st.pop();
    }
    while (!que.empty())
    {
        queList.push_back(que.front());
        que.pop();
    }
    // check the lists
    if (stList == queList)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }

    return 0;
}