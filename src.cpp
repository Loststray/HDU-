#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
struct task
{
    int id;
    string correct_answer;
    string text;
    vector<string> options;
    task(){};
    friend ostream &operator<< (ostream &out, const task &a)
    {
        out << a.text << '\n';
        char opt = 'A';
        for (const auto &it : a.options)
            out << opt++ << ":" << it << '\n';
        return out;
    }
};

int main()
{
    ifstream fin;
    fin.open("2023.csv");
    vector<task> wow;
    string line;
    while (getline(fin, line))
    {
        stringstream ss(line);
        string elem;
        task tmp;
        int cnt = 0;
        while (getline(ss, elem, ','))
        {
            if (!cnt)
                tmp.correct_answer = elem;
            else if (cnt == 1)
                tmp.text = elem;
            else if (!elem.empty())
                tmp.options.emplace_back(elem);
            cnt++;
        }
        tmp.id = wow.size() + 1;
        wow.emplace_back(tmp);
    }
    cout << "shuffle ?[1/0]";
    int op;
    cin >> op;
    srand(time(0));
    if (op)
        random_shuffle(wow.begin(), wow.end());
    for (auto it : wow)
    {
        cout << it.id << ' ';
        if (it.correct_answer.size() > 1)
            cout << "multi-ans\n";
        else
            cout << "single-ans\n";
        cout << it;
        string res;
        cin >> res;
        for (auto &it : res)
            it = toupper(it);
        sort(res.begin(), res.end());
        auto ed = unique(res.begin(), res.end());
        while (res.end() != ed)
            res.pop_back();
        if (res == it.correct_answer)
        {
            cout << "Accepted\n";
            system("pause");
        }
        else
        {
            cout << "Wrong Answer" << '\n'
                 << "Answer " << it.correct_answer << '\n';
            system("pause");
        }
        system("cls");
    }
    return 0;
}
