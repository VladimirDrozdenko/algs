/*
Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.
Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.
The order of output does not matter.

1. Example:
Input:
s: "cbaebabacd" p: "abc"

Output:
[0, 6]

Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".

2. Example:
Input:
s: "abab" p: "ab"

Output:
[0, 1, 2]

Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".
*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;


bool compareTables(const vector<size_t>& st, const vector<size_t>& pt)
{
    for (size_t i = 0; i < st.size(); ++i)
    {
        if (st[i] != pt[i])
            return false;
    }
    return true;
}

vector<size_t> findAnagrams(const string& s, const string& p)
{
    vector<size_t> res;
    if (s.size() < p.size())
        return res;

    vector<size_t> pTable(255, 0);
    for_each(p.cbegin(), p.cend(), [&](char c){
        ++pTable[(size_t)c];
    });

    vector<size_t> sTable(255, 0);
    for (size_t i = 0; i < p.size(); ++i) {
        ++sTable[(size_t)s[i]];
    }

    if (compareTables(sTable, pTable))
        res.push_back(0);

    for (size_t i = p.size(); i < s.size(); ++i)
    {
        --sTable[(size_t)s[i - p.size()]];
        ++sTable[(size_t)s[i]];
        if (compareTables(sTable, pTable))
            res.push_back(i-p.size()+1);
    }

    return res;
}

void printResultsNicely(const string& s, const string& p)
{
    cout << "[ ";
    const vector<size_t>& anagrams = findAnagrams(s, p);
    for_each(anagrams.cbegin(), anagrams.cend(), [](size_t n) -> void {
        cout << n << " ";
    });
    cout << "]" << endl;
}

int main()
{
    printResultsNicely("cbaebabacdmmcab", "abc");
    printResultsNicely("abab", "ab");
}
