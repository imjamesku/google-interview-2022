#include <map>
#include <set>
using namespace std;
class StockPrice {
   public:
    StockPrice() {
        // map<time, price> how to get maximum?
        // set<price>
    }

    void update(int timestamp, int price) {
        // O(logN)
        if (history.count(timestamp)) {
            prices.erase(prices.lower_bound(history[timestamp]));
        }
        history[timestamp] = price;
        prices.insert(price);
    }

    int current() {
        // O(1)
        return history.rbegin()->second;
    }

    int maximum() {
        // O(1)
        return *prices.rbegin();
    }

    int minimum() {
        // O(1)
        return *prices.begin();
    }

   private:
    map<int, int> history;
    multiset<int> prices;
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */