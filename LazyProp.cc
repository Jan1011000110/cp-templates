struct segTree {
	int size = 1;
	int null_value = 0; // CHANGE THIS
	vector<int> t, upd;
	
	segTree(int n) {
		while (size < n) size *= 2;
		t.assign(2*size, null_value);
		upd.assign(2*size, 0);
	}
	
	int merge(int a, int b) { // CHANGE THIS
		return a + b;
	}
	
	void propagate(int v, int l, int r) {
		if (upd[v] == 0 or r - l == 1) {
			return;
		}
		int m = (l + r) / 2;
		
		t[2*v + 1] += upd[v] * (m - l);
		t[2*v + 2] += upd[v] * (r - m);
		upd[2*v + 1] += upd[v];
		upd[2*v + 2] += upd[v];
		
		upd[v] = 0;		
	}
	
	void modify(int v, int l, int r, int x, int y, int k) {
		propagate(v, l, r);
		if (l >= x and r <= y) {
			t[v] += (r - l) * k;
			upd[v] += k;
			return;
		}
		if (l >= y or r <= x) {
			return;
		}
		
		int m = (l + r) / 2;
		modify(2*v + 1, l, m, x, y, k);
		modify(2*v + 2, m, r, x, y, k);
		
		t[v] = merge(t[2*v + 1], t[2*v + 2]);
	}
	
	void modify(int x, int y, int k) {
		modify(0, 0, size, x, y, k);
	}
	
	int query(int v, int l, int r, int x, int y) {
		propagate(v, l, r);
		if (l >= x and r <= y) {
			return t[v];
		}
		if (l >= y or r <= x) {
			return null_value;
		}
		
		int m = (l + r) / 2;
		return merge(query(2*v + 1, l, m, x, y), query(2*v + 2, m, r, x, y));
	}
	
	int query(int x, int y) {
		return query(0, 0, size, x, y);
	}
};
