struct point //Replace double with int if not required
{
	long double x, y;
	point () {}
	point(int x, int y) : x(x), y(y) {}
	void operator =(const point &p) { x = p.x, y = p.y; }

	bool operator <(const point&p) {
		if (x == p.x) return y < p.y;
		return x < p.x;
	}
	point operator +(const point&p) const {
		point pt(x + p.x, y + p.y);
		return pt;
	}
	point operator -(const point&p) const {
		point pt(x - p.x, y - p.y);
		return pt;
	}

	long double crossProduct(const point &p) const { return x * p.y - y * p.x; }
	int dotProduct(const point &p) const { return x * p.x + y * p.y; }
	long double dist() { return x * x + y * y; }
};

bool comp(point &p1, point &p2)
{
	if (p1.x != p2.x) return p1.x < p2.x;
	return p1.y < p2.y;
}
bool cw(point &a, point &b, point &c)
{
	int area = a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y);
	return area < 0;
}
bool ccw(point &a, point &b, point &c)
{
	int area = a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y);
	return area > 0;
}
vector<point> convex_hull(vector<point> &v)
{
	if (v.size() == 1)
		return v;

	sort(v.begin(), v.end(), comp);
	point p1 = v[0], p2 = v.back();
	vector<point> up, down, full;
	up.push_back(p1);
	down.push_back(p1);

	for (int i = 1; i < v.size(); i++)
	{
		// upper convex hull
		if (i == v.size() - 1 || cw(p1, v[i], p2))
		{
			while (up.size() >= 2 && !cw(up[up.size() - 2], up[up.size() - 1], v[i]))
				up.pop_back();
			up.push_back(v[i]);
		}
		// lower convex hull
		if (i == v.size() - 1 || ccw(p1, v[i], p2))
		{
			while (down.size() >= 2 && !ccw(down[down.size() - 2], down[down.size() - 1], v[i]))
				down.pop_back();
			down.push_back(v[i]);
		}
	}

	full = up;
	for (int i = down.size() - 2; i > 0; i--)
		full.push_back(down[i]);

	return full;
}
