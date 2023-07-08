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

string magicColors(string s)
{
    stack<char> st;
    string ans;
    for (char c : s)
    {
        if (!st.empty() && ((c == 'R' && st.top() == 'B') || (c == 'B' && st.top() == 'R')))
        {
            ans = ans + 'P';
            st.pop();
        }
        else if (!st.empty() && ((c == 'R' && st.top() == 'G') || (c == 'G' && st.top() == 'R')))
        {
            ans = ans + 'Y';
            st.pop();
        }
        else if (!st.empty() && ((c == 'B' && st.top() == 'G') || (c == 'G' && st.top() == 'B')))
        {
            ans = ans + 'C';
            st.pop();
        }
        else if (!st.empty() && c == st.top())
        {
            st.pop();
        }
        else
        {
            st.push(c);
        }
    }
    if (st.empty())
    {
        return ans;
    }
    else
    {
        return ans + st.top();
    }
}

int main()
{
    int input;
    cin >> input;

    for (int i = 0; i < input; i++)
    {
        int N;
        cin >> N;

        stack<char> st;
        for (int i = 0; i < N; i++)
        {
            char x;
            cin >> x;
            st.push(x);
        }
        // Revers the Stack
        queue<char> que;

        while (!st.empty())
        {
            que.push(st.top());
            st.pop();
        }

        while (!que.empty())
        {
            st.push(que.front());
            que.pop();
        }

        // Conver to String
        string s;
        while (!st.empty())
        {
            s = s + st.top();
            st.pop();
        }

        // Call the function to get result
        string res = magicColors(s);

        stack<char> st2;
        // Find if there is same color in result
        for (char c : res)
        {
            if (!st2.empty() && c == st2.top())
            {
                st2.pop();
            }
            else
            {
                st2.push(c);
            }
        }
        if (st2.empty())
        {
            cout << endl;
            continue;
        }

        // Revers the New Stack2
        queue<char> que2;
        while (!st2.empty())
        {
            que2.push(st2.top());
            st2.pop();
        }

        while (!que2.empty())
        {
            st2.push(que2.front());
            que2.pop();
        }
        // Print
        while (!st2.empty())
        {
            cout << st2.top();
            st2.pop();
        }
        cout << endl;
    }

    return 0;
}

/*
input
6
6
RGGRRG
6
RGRGRG
4
RGGR
5
RGGGR
4
RGGB
18
RBRBRBGRBRRGBGGBGB

output
Y
Y

YR
YC
PYPYC

*/