#include <bits/stdc++.h>

using namespace std;

void printNext(int* next, int len) {
    for (int i = 0; i < len; i++) {
        printf("%4d ", next[i]);
    }
    printf("\n");
}

#if 0
// kmp的next数组的第一种实现方法
// next[0] = 0; j = next[j - 1]; 统一不减1的方式
void getNext(int* next, const string s) {
    int len = s.size();
    int j = 0;
    next[0] = 0;

    for (int i = 1; i < len; i++) {
        while (j > 0 && s[i] != s[j]) {
            j = next[j - 1];
        }

        if (s[i] == s[j]) {
            j++;
        }
        next[i] = j;
    }
}

int kmp(const string strSrc, const string strSub) {
    if (strSrc.size() == 0) {
        return 0;
    }

    int j = 0;
    int next[strSub.size()];

    getNext(next, strSub);
    // printNext(next, strSub.size());
    for (int i = 1; i < strSrc.size(); i++) {
        while (j > 0 && strSrc[i] != strSub[j]) {
            j = next[j - 1];
        }

        if (strSrc[i] == strSub[j]) {
            j++;
        }

        if (j == strSub.size()) {
            return i - strSub.size() + 1;
        }
    }
    return -1;
}
#endif

#if 1
// kmp的next数组的第二种实现方法，
// next[0] = -1; 把第一种方法的元素统一右移一位
void getNext(int* next, const string s) {
    int len = s.size();
    int i = 0;
    int j = -1;
    next[0] = -1;

    while (i < len - 1) {
        if (j == -1 || s[i] == s[j]) {
            i++;
            j++;
            next[i] = j;
        }
        else {
            j = next[j];
        }
    }
}

int kmp(const string strSrc, const string strSub) {
    if (strSrc.size() == 0) {
        return 0;
    }

    int srcLen = strSrc.size();
    int subLen = strSub.size();
    int i = 0;
    int j = 0;
    int next[strSub.size()];

    getNext(next, strSub);
    // printNext(next, strSub.size());
    while (i < srcLen && j < subLen) {
        if (j == -1 || strSrc[i] == strSub[j]) {
            i++;
            j++;
        }
        else {
            j = next[j];
        }
    }

    if (j == strSub.size()) {
        return i - strSub.size();
    }
    else {
        return -1;
    }
}
#endif

int main() {
    int result = kmp("aafaab1234aabaafaac", "aabaafaac");
    cout << result << endl;

    system("pause");
    return 0;
}
