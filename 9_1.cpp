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

bool compare_pos(point p1, point p2)
{
	if (p1.y != p2.y)
	{
		return p1.y < p2.y;
	}
	else
	{
		return p1.x < p2.x;
	}
}
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
//bool compare_rad(vector<point> &vec,point p1, point p2)// 라디안 비교 가장큰거
//{
//	double cc = ComputeAngle(p1, p2);
//	if (cc)//라디안이 비교가능
//		return cc > 0;
//	else//라디안이 동일 , 수평일때
//		return p1.x + p1.y < p2.x + p2.y; // 가장큰순서대로
//}


Polygon::Polygon(vector<point>& poly, int N)

{

	computeCount = 0; compareCount = 0;


	compute(poly, N); // 수평각 계산
	sort(poly.begin(), poly.end(), compare_pos);
	//sort(poly.begin(), poly.end(), compare_rad);

	heapsort(poly, N);


	cout << "\n\n";

	printPoly(poly, N); // 수평각이 계산된 후 정렬된 점들 출력



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



void main()

{
	int N;
	cin >> N;
	vector<point> poly1;
	for (int i = 0; i < N;i++) {
		int x, y;
		char c;
		cin >> c >> x >> y;
		poly1.push_back({ x, y, c });
	}


	Polygon POLY1(poly1, N);

}


