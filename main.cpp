#include <algorithm>
#include <climits>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "../utils/PrintUtils.hpp"
#include "../utils/VectorUtils.hpp"
// #include "../utils/HeapUtils.hpp"
// #include "../utils/BinarySearch.hpp"
// #include "../utils/TreeUtils.hpp"

using namespace std;

#pragma GCC diagnostic ignored "-Wunknown-pragmas"

// https://leetcode.com/problems/check-if-it-is-a-straight-line/
// Live coding problems, watch at
// https://www.twitch.tv/yipcubed
// https://www.youtube.com/channel/UCTV_UOPu7EWXvYWsBFxMsSA/videos
//

// makes code faster, but larger. Just for LeetCode fun!
#pragma GCC optimise("Ofast")

// makes stdin not synced so it is faster. Just for LeetCode fun!
static auto __ __attribute__((unused)) = []() { // NOLINT
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  return nullptr;
}();

class Solution {
public:
  vector<int> kWeakestRows(vector<vector<int>> &mat, int k) {
    vector<int> result;
    using pt = pair<int, int>;
    priority_queue<pt, vector<pt>, greater<pt>> pq;
    if (mat.size() == 0 || k == 0)
      return result;
    int rows = mat.size();
    int cols = mat[0].size();
    for (int row = 0; row < rows; row++) {
      int strength = 0;
      while (strength < cols && mat[row][strength] == 1)
        ++strength;
      // PV2(row, strength);
      //pq.push(make_pair(strength, row));
      pq.push({strength, row});
    }
    while (k > 0) {
      pair<int, int> top = pq.top();
      result.push_back(top.second);
      pq.pop();
      --k;
    }
    return result;
  }
};

void test1() {
  cout << boolalpha;
  vector<vector<int>> m{{1, 1, 0, 0, 0},
                        {1, 1, 1, 1, 0},
                        {1, 0, 0, 0, 0},
                        {1, 1, 0, 0, 0},
                        {1, 1, 1, 1, 1}};

  int k = 3;

  cout << "[2,0,3] ? " << Solution().kWeakestRows(m, k) << endl;
}

void test2() {}

void test3() {}