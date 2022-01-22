#include <stack>
#include <bits/stdc++.h>

#include <algorithm>
using namespace std;
int minJumps(const vector<int> &arr) {
  int n = arr.size();
  vector<int> dist(n, INT32_MAX);
  unordered_map<int, vector<int>> idSameValue;
  for (int i = 0; i < n; i++) {
    idSameValue[arr[i]].push_back(i);
  }

  queue<int> q;
  q.push(0);
  dist[0] = 0;
  while (!q.empty()) {
    auto id = q.front();
    auto step = dist[id];
    q.pop();
    if (id == n - 1) {
      return step;
    }
    if (id > 0 && dist[id - 1] != INT32_MAX) {
      q.push(id - 1);
      dist[id - 1] = step + 1;
    }
    if (id < n - 1 && dist[id + 1] != INT32_MAX) {
      q.push(id + 1);
      dist[id + 1] = step + 1;
    }
    if (idSameValue.count(arr[id])) {
      auto &sameValue = idSameValue[arr[id]];
      for (auto x : sameValue) {
        if (dist[x] != INT32_MAX) {
          q.push(x);
          dist[x] = step + 1;
        }
      }
      idSameValue.erase(arr[id]);
    }
  }
  return -1;
}

int main() {
    minJumps({100,-23,-23,404,100,23,23,23,3,404});
    return 0;

    std::less<int>(1, 2);
}