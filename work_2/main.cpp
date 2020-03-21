#include <bits/stdc++.h>

using namespace std;

vector <int> p;

int main(int argc, char* argv[]) {
	string toFind = argv[1];
	int n = toFind.size();
	p.resize(n);
	p[0] = 0;
	for (int i = 1; i < n; i++) {
		p[i] = p[i - 1];
		while (p[i] > 0 && toFind[i] != toFind[p[i]]) {
			p[i] = p[p[i] - 1];
		}
		if (toFind[i] == toFind[p[i]]) {
			p[i]++;
		}
	}

	FILE *f;
	f = fopen(argv[2], "r");
	int cur = 0;
	char ch;
	while ((ch = getc(f)) != EOF) {
		while (cur > 0 && ch != toFind[cur]) {
			cur = p[cur - 1];
		}
		if (ch == toFind[cur]) {
			cur++;
		}
		if (cur == n) {
			printf("true\n");
			fclose(f);
			return 0;
		}
	}

	printf("false\n");
	fclose(f);
	return 0;
}
