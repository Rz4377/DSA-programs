#include <vector>
#include <iostream>
#include <climits>
using namespace std;

void solve(vector<int>& prices, int i, int& maxProfit, int &minPrice) {
    if (prices.size() == i) {
        return;
    }
    if (minPrice > prices[i]) {
        minPrice = prices[i];
    }
    if (maxProfit < (prices[i] - minPrice)) {
        maxProfit = prices[i] - minPrice;
    }

    solve(prices, i + 1, maxProfit, minPrice);
}

int maxProfit(vector<int>& prices) {
    if (prices.size() == 1) {
        return 0;
    }
    int i = 1;
    int maxProfit = INT_MIN;
    int minPrice = prices[0];
    solve(prices, i, maxProfit, minPrice);
    return maxProfit;
}

int main() {
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    int profit = maxProfit(prices);
    cout << "Maximum Profit: " << profit << endl;
    return 0;
}
