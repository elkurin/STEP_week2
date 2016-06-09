#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <list>

using namespace std;

list<int> clean(list<int> cash)
{
	list<int> ret;
	map<int, int> check;
	while(!cash.empty()) {
		int give = cash.front();
		cash.pop_front();
		if (check[give]) continue;
		ret.push_back(give);
		check[give]++;
	}
	return ret;
}


int main(void)
{
	map<int, int> check;
	int get;
	int k;
	int count = 0;
	cin >> k;
	list<int> cash;
	while(1) {
		cin >> get;
		if (!get) break;
		if (get < 0) {
			cash = clean(cash);
			continue;
		}
		
		if (check[get]) {
			int keep = cash.back();
			if (keep == get) continue;
			cash.push_back(get);
			check[get]++;
		} else {
			int keep = cash.front();
			if (keep == get) {
				cash.pop_front();
				check[get]--;
			}
			cash.push_back(get);
			count++;
			check[get]++;
			if (count > k) {
				check[cash.front()]--;
				cash.pop_front();
			}
		}
	}
	
	while(!cash.empty()) {
		cout << cash.front() << " ";
		cash.pop_front();
	}
	cout << endl;
	return 0;
}

