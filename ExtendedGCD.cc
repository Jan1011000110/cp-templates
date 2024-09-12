int extended_gcd(int a, int b, int& x, int& y) {
	if (b == 0) {
		x = 1;
		y = 0;
		return a;
	}
	int x1, y1;
	int d = extended_gcd(b, a % b, x1, y1);
	x = y1;
	y = x1 - y1 * (a / b);
	return d;
}

// gcd(a, b) = gcd(b, a%b) = g
// so we got that x*a+y*b=g and x1*b+y1*(a%b)=g
// also we know a%b = a-floor(a/b)*b
// we got x*a+y*b=x1*b+y1*(a-floor(a/b)*b) => x*a+y*b=x1*b+y1*a-y1*floor(a/b)*b => x*a+y*b=y1*a+(x1-y1*floor(a/b))*b
// we can deduce that x=y1 and y=x1-y1*floor(a/b)