#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

using ll = long long;
using vb = vector<bool>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using pii = pair<int, int>;
using qii = queue<pii>;

constexpr auto inf = int{ 987654321 };

const auto& dx = vi{ -1,1,-2,2,-2,2,-1,1 };
const auto& dy = vi{ -2,-2,-1,-1,1,1,2,2 };

int solve(int l, int bx, int by, int ex, int ey) {
	auto dist = vvi(l, vi(l, inf));
	dist[by][bx] = 0;

	auto q = qii{};
	q.push({ bx, by });

	while (!q.empty()) {
		auto f = q.front();
		q.pop();

		if (ex == f.first && ey == f.second) {
			break;
		}

		for (auto d = 0; d < 8; ++d) {
			const auto& nx = f.first + dx[d];
			const auto& ny = f.second + dy[d];

			if (nx < 0 || l <= nx ||
				ny < 0 || l <= ny) {
				continue;
			}

			const auto& newDist = dist[f.second][f.first] + 1;
			if (newDist < dist[ny][nx]) {
				dist[ny][nx] = newDist;
				q.push({ nx, ny });
			}
		}
	}

	return dist[ey][ex];
}

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t;
	cin >> t;
	while (0 < (t--)) {
		int l;
		cin >> l;

		int bx, by;
		cin >> bx >> by;
		int ex, ey;
		cin >> ex >> ey;
		const auto& ans = solve(l, bx, by, ex, ey);

		cout << ans << '\n';
	}

	return 0;
}