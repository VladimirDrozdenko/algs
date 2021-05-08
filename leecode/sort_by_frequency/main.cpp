#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;


int main()
{
    string in = "fuck this shit";

    vector<pair<char, int> > tbl;
    for (int ch = 0; ch < 256; ++ch)
        tbl.push_back(make_pair(static_cast<char>(ch), 0));

    for (size_t i = 0; i < in.size(); ++i)
        ++(tbl[(char)in[i]].second);

    sort(tbl.begin(), tbl.end(), [](const pair<char, int>& a, const pair<char, int>& b) -> bool
    {
        return a.second > b.second;
    });

    string out;
    for (auto i = tbl.cbegin(); i != tbl.cend(); ++i)
    {
        if (i->second == 0)
            break;
        //for (int c = 0; c < i->second; ++c)
        out += i->first;
    }

    cout << out;
}
