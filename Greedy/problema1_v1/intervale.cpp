#include <iostream>
#include <fstream>
#include <list>
#include <algorithm>
using namespace std;

ifstream f("date.in");
ofstream g("date.out");

struct Interval {
	int x, y;
};

int  comFunc(const void* a, const void* b)
{
	Interval* fa = (Interval*)a;
	Interval* fb = (Interval*)b;

	if (fa->x == fb->x) return fa->y > fb->y;
	else return fa->x > fb->x;
};

int main()
{
	Interval principal;
	int nrInt=50;

	f >> principal.x >> principal.y >> nrInt;

	Interval intervals[50];
	for (int i = 0; i < nrInt; i++) {
		f >> intervals[i].x >> intervals[i].y;
	}

	qsort(intervals, nrInt, sizeof(Interval), comFunc);
	for (int i = 0; i < nrInt; i++) {
		cout << intervals[i].x << ' ' << intervals[i].y << endl;
	}

	int left = principal.x;
	int right = principal.y;
	bool ok = true;
	Interval maxim_interval;

	if (intervals[0].x <= left) {
		maxim_interval = intervals[0];
	}
	else
		ok = false;

	list<Interval> intervalList;


	for (int i = 0; i < nrInt - 1; i++) {
		if (intervals[i + 1].x < left) {
			if (maxim_interval.y < intervals[i].y)
				maxim_interval = intervals[i];
		}
		else {
			intervalList.push_back(maxim_interval);
			left = maxim_interval.y;
			maxim_interval.x = 0;
			maxim_interval.y = 0;
		}
	}

	if (left < right && intervals[nrInt - 1].x <= left) {
		if (maxim_interval.y < intervals[nrInt - 1].y) {
			intervalList.push_back(intervals[nrInt - 1]);
			left = intervals[nrInt - 1].y;
		}
		else {
			intervalList.push_back(maxim_interval);
			left = maxim_interval.y;

		}
	}

	if (left < right)
		ok = false;

	if (ok == false) g << -1;
	else {
		for (list<Interval>::iterator i = intervalList.begin(); i != intervalList.end(); i++)
			g << i->x << ' ' << i->y << endl;

	}

	return 0;

}
