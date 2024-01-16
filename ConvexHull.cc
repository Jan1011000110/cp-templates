vector<Point> convex_hull(vector<Point> points) {
	sort(points.begin(), points.end(), [&](const Point &a, const Point &b) {
		return make_pair(a.x, a.y) < make_pair(b.x, b.y);
	});
	vector<Point> hull;
	for (int rep = 0; rep < 2; ++rep) {
		const int S = sz(hull);
		for (Point &C : points) {
			while (sz(hull) > 1 + S) {
				Point A = end(hull)[-2];
				Point B = end(hull)[-1];
				if (cross(B - A, C - A) <= 0) { // good
					break;
				}
				hull.pop_back();
			}
			hull.push_back(C);
		}
		hull.pop_back();
		reverse(points.begin(), points.end());
	}
	return hull;
}