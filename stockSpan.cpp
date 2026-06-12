#include <iostream>
using namespace std;

vector<int> calculateSpan(vector<int>& price) {
    int n = price.size();

    vector<int> span(n);
    stack<int> s;

    for (int i = 0; i < n; i++) {

        while (!s.empty() && price[s.top()] <= price[i])
            s.pop();

        if (s.empty())
            span[i] = i + 1;
        else
            span[i] = i - s.top();

        s.push(i);
    }

    return span;
}

int main() {
    vector<int> price = {100, 80, 60, 70, 60, 75, 85};

    vector<int> ans = calculateSpan(price);

    for (int x : ans)
        cout << x << " ";

    return 0;
}