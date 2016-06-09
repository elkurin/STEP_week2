/********************************

O(1)になったと思います。
K個の要素からなる環状につなげて保存します。
環状だと、ちょうどK種類たまったときにもっとも古いものを書き換える操作が出来る。
重複が発生した時は、vectorを使うと、それ以降のものをすべて移動させなければならずO(N)かかるが、このデータ構造ではつなぎ変えるだけで済み、下のコードの通り定数倍で完了する。

多分バグっていないが、自信はないです。

********************************/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define vec vector

int main(void)
{
	int k;
	cin >> k;
	vec<int> cash(k);
	rep(i, k) cash[i] = 0; //簡単のため初期状態を適当に定義
	vec<int> next(k), before(k);
	rep(i, k - 1) next[i] = i + 1;
	rep(i, k - 1) before[i + 1] = i;
	next[k - 1] = 0;
	before[0] = k - 1;
	unordered_map<int, int> check; //place + 1を保存
	int current = 0;
	while(1) {
		int get;
		cin >> get;
		if (!get) break;
		if (!check[get]) {
			check[cash[current]] = 0;
			cash[current] = get;
			check[get] = current + 1;
			current = next[current];
		} else {
			int place = check[get] - 1;
			if (current == place) continue;
			int prev_next_place = next[place];
			int prev_before_place = before[place];
			next[before[place]] = next[place];
			next[next[place]] = place;
			next[place] = current;
			before[current] = place;
			before[place] = prev_next_place;
			before[prev_next_place] = prev_before_place;
		}
	}
	rep(i, k) cout << cash[i] << " ";
	cout << endl;
	return 0;
}
