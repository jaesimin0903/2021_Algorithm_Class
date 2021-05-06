#include <iostream>

#include <stdlib.h>

#include <time.h>

#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

int radCompare = 0;
int computeRad = 0;
// 점(point) 구조체

struct point

{

	int x;

	int y;

	char c;

	double angle;

};



// 선(line) 구조체

struct line

{

	struct point p1;

	struct point p2;

};

inline void swap(vector<point>& v, int i, int j) {

	point t;
	t = v[i]; v[i] = v[j]; v[j] = t;

};


void makeHeap(vector<point>& v, int Root, int LastNode)

{

	int Parent, LeftSon, RightSon, Son;

	point RootValue;
	Parent = Root;

	RootValue = v[Root];

	LeftSon = 2 * Parent + 1;

	RightSon = LeftSon + 1;



	while (LeftSon <= LastNode) {

		if (RightSon <= LastNode && v[LeftSon].angle < v[RightSon].angle)

		{
			radCompare++;
			Son = RightSon;
		}

		else { Son = LeftSon; radCompare++; }

		if (RootValue.angle < v[Son].angle) {


			radCompare++;
			v[Parent] = v[Son];

			Parent = Son;

			LeftSon = Parent * 2 + 1;

			RightSon = LeftSon + 1;

		}

		else break;

	}

	v[Parent] = RootValue;


}

void heapsort(vector<point>& v, int N)

{



	int i;

	for (i = N / 2; i >= 1; i--)

		makeHeap(v, i - 1, N - 1);

	for (i = N - 1; i >= 1; i--)

	{

		swap(v, 0, i);

		makeHeap(v, 0, i - 1);

	}

	for (i = 0; i <= N;i++) {
		if (v[i].angle == v[i + 1].angle && v[i].x > v[i + 1].x)
			swap(v, i, i + 1);
		else if (v[i].angle < v[i + 1].angle) break;
	}
}



int direction(struct point A, struct point B, struct point C) {
	int dxAB, dxAC, dyAB, dyAC, Dir;
	dxAB = B.x - A.x; dxAC = C.x - A.x;
	dyAB = B.y - A.y; dyAC = C.y - A.y;

	if (dxAB * dyAC < dyAB * dxAC) Dir = 1;
	if (dxAB * dyAC > dyAB * dxAC) Dir = -1;
	if (dxAB * dyAC == dyAB * dxAC) {

		if ((dxAB * dxAC < 0) || (dyAB * dyAC < 0)) Dir = -1;
		else if ((dxAB * dxAB + dyAB * dyAB) >= (dxAC * dxAC + dyAC * dyAC)) Dir = 0;
		else if (dxAB == 0 && dyAB == 0) Dir = 0;
		else Dir = 1;
	}
	return Dir;
}

int intersection(struct line AB, struct line CD) {
	int LineCrossing;
	if ((direction(AB.p1, AB.p2, CD.p1) * direction(AB.p1, AB.p2, CD.p2) <= 0) && (direction(CD.p1, CD.p2, AB.p1) * direction(CD.p1, CD.p2, AB.p2) <= 0)) {
		LineCrossing = 1;
	}
	else LineCrossing = 0;
	return LineCrossing;
}

int isPointInside(struct point A, vector<point>& v, int N) {
	int Count, i, LastPoint;
	bool PointOnTestLine = false;
	struct line TestLine, PolyLine;
	Count = LastPoint = 0;
	TestLine.p1 = A; TestLine.p2 = A;
	TestLine.p2.x = 9999;
	for (i = 0;i <= N;i++) {
		PolyLine.p1 = PolyLine.p2 = v[i];
		if (intersection(TestLine, PolyLine)) {
			PointOnTestLine = true;
			LastPoint = i;
		} //테스트 라인에 점이 있다
		else {// 테스트 라인과 변끼리 교차 확인
			PolyLine.p2 = v[LastPoint];
			LastPoint = i;
			if (!PointOnTestLine) {// false 라면
				if (intersection(PolyLine, TestLine)) Count++;
				/*else if (!(intersection(PolyLine, TestLine))) {
					if (direction(TestLine.p1, TestLine.p2, PolyLine.p1) * direction(TestLine.p1, TestLine.p2, PolyLine.p2) < 0) {
						Count++; PointOnTestLine = false;
					}
				}*/
			}
			else {// true 라면
				if (direction(TestLine.p1, PolyLine.p2, PolyLine.p1) * direction(TestLine.p1, PolyLine.p2, v[LastPoint - 2]) < 0) {
					Count++; PointOnTestLine = false;
				}
			}
		}
	}
	if ((Count % 2) == 1) {
		cout << "true"; return 0;
	}
	else {
		cout << "false";
		return 0;
	}
}
// Polygon Class

class Polygon

{

private:



	int computeCount; // 수평각 계산회수

	int compareCount; // 각의 비교회수



public:



	Polygon(vector<point>& poly, int N); // Polygon 생성자

	void printPoly(vector<point>& poly, int N); // 다각형 출력

	void compute(vector<point>& poly, int N);

	double ComputeAngle(struct point p1, struct point p2); // 수평각 계산


};



Polygon::Polygon(vector<point>& poly, int N)

{

	computeCount = 0; compareCount = 0;


	compute(poly, N); // 수평각 계산


	heapsort(poly, N);

	cout << "\n\n";

	printPoly(poly, N); // 수평각이 계산된 후 정렬된 점들 출력

	poly.push_back(poly[0]);

	cout << "\n\n수평각 계산 회수 : ";

	cout << computeRad << "\n";

	cout << "각의 비교 회수 : ";

	cout << radCompare << "\n\n";


}



void Polygon::printPoly(vector<point>& poly, int N)

{

	int i;

	for (i = 0; i < N; i++)

	{

		cout << poly[i].c << " - ";

	}



}


//bool Polygon::compare_pos(point p1, point p2) {
//	if (p1.y != p2.y) return p1.y < p2.y;
//	else return p1.x < p2.x;
//}
void Polygon::compute(vector<point>& poly, int N)

{

	int i, k = 1;

	for (i = 0; i < N - 1; i++) // 기준점 계산(Y축이 가장 작은 점)

	{

		if (poly[k].y > poly[i + 1].y)

			k = i + 1;

	}

	for (i = 0;i < N;i++)

	{





		// 수평각 계산, angle에 정보를 저장

		poly[i].angle = ComputeAngle(poly[k], poly[i]);

	}

}



double Polygon::ComputeAngle(struct point p1, struct point p2)

{

	int dx, dy, ax, ay;

	double t;



	computeRad++;



	dx = p2.x - p1.x; ax = abs(dx);

	dy = p2.y - p1.y; ay = abs(dy);



	t = (ax + ay == 0) ? 0 : (float)dy / (ax + ay);



	if (dx < 0) t = 2 - t; else if (dy < 0) t = 4 + t;

	return (double)t * 90.0;

}



// 삽입정렬을 사용하여 다각형의 angle 순으로 정렬




void main()

{
	int N, a, b;
	cin >> N >> a >> b;
	struct point A;
	A.x = a; A.y = b;
	vector<point> poly1;
	for (int i = 0; i < N;i++) {
		int x, y;
		char c;
		cin >> c >> x >> y;
		poly1.push_back({ x, y, c });
	}




	Polygon POLY1(poly1, N);
	isPointInside(A, poly1, N);




}


