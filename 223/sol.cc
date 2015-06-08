#include <climits>
#include <cmath>

#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::map;
using std::string;
using std::vector;

int GetRecArea(const int bottom_left_x, const int bottom_left_y,
	const int top_right_x, const int top_right_y)
{
	return (top_right_x - bottom_left_x) * (top_right_y - bottom_left_y);
}

bool IsInRec(const int x, const int y, const int bottom_left_x, const int bottom_left_y,
	const int top_right_x, const int top_right_y)
{
	if (x < bottom_left_x || x > top_right_x)
		return false;
	if (y < bottom_left_y || y > top_right_y)
		return false;
	return true;
}

int GetCommonArea(int A, int B, int C, int D, int E, int F, int G, int H)
{
	const int b_l_x = A;
	const int b_l_y = B;

	const int t_r_x = C;
	const int t_r_y = D;

	const int b_r_x = C;
	const int b_r_y = B;

	const int t_l_x = A;
	const int t_l_y = D;

	int count = 0;
	int b_l = 0;
	int b_r = 0;
	int t_l = 0;
	int t_r = 0;

	if (IsInRec(b_l_x, b_l_y, E, F, G, H)) {
		b_l = 1;
		count++;
	}
	if (IsInRec(b_r_x, b_r_y, E, F, G, H)) {
		b_r = 1;
		count++;
	}
	if (IsInRec(t_l_x, t_l_y, E, F, G, H)) {
		t_l = 1;
		count++;
	}
	if (IsInRec(t_r_x, t_r_y, E, F, G, H)) {
		t_r = 1;
		count++;
	}
	if (0 == count)
		return 0;
	if (4 == count)
		return (C - A) * (D - B);
	if (2 == count) {
		if (b_l && t_l)
			return (G - A) * (D - B);
		else if (b_l && b_r)
			return (C - A) * (H - B);
		else if (t_l && t_r)
			return (C - A) * (D - F);
		else if (t_r && b_r)
			return (C - E) * (D - B);
	}
	if (1 == count) {
		if (b_l)
			return GetRecArea(A, B, G, H);
		if (t_l)
			return GetRecArea(A, F, G, D);
		if (b_r)
			return GetRecArea(E, B, C, H);
		if (t_r)
			return GetRecArea(E, F, C, D);
	}
}

class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        const int area1 = GetRecArea(A, B, C, D);
	const int area2 = GetRecArea(E, F, G, H);
	const int common_area1 = GetCommonArea(A, B, C, D, E, F, G, H);
	const int common_area2 = GetCommonArea(E, F, G, H, A, B, C, D);
	const int common_area = std::max(common_area1, common_area2);
	return area1 + area2 - common_area;
    }
};

int main()
{
	Solution sln;

cout << sln.computeArea(-3, 0, 3, 4, 0, -1, 9, 2) << endl;
cout << sln.computeArea(0, -1, 9, 2, -3, 0, 3, 4) << endl;

cout << sln.computeArea(0, 0, 3, 3, 4, 4, 6, 6) << endl;
cout << sln.computeArea(4, 4, 6, 6, 0, 0, 3, 3) << endl;

cout << sln.computeArea(0, 0, 3, 3, 1, 2, 6, 6) << endl;
cout << sln.computeArea(1, 2, 6, 6, 0, 0, 3, 3) << endl;

cout << sln.computeArea(0, 0, 6, 6, 1, 2, 2, 7) << endl;
cout << sln.computeArea(1, 2, 2, 7, 0, 0, 6, 6) << endl;

cout << sln.computeArea(0, 0, 6, 6, 0, 0, 6, 6) << endl;
cout << sln.computeArea(0, 0, 6, 6, 0, 0, 6, 6) << endl;

	return 0;
}
