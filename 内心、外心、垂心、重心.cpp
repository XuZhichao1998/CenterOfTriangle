/*2018��4��29����������G�� ������������������ �� ��һ���㣬
����һ���������ġ����ġ����ġ����ĵ�����һ�������Yes�����������No 
AC
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <set>
#include <vector> 
#include <cstdlib> 
#define LL long long
using namespace std;
const int maxn = 1e5 + 100;
double distance(double x1,double y1,double x2,double y2){
	double ss = sqrt(  (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2)  );
	return ss;
}

// ���(x,y) ��ֱ�� L �ľ��룬��֪L����(x1,y1)(x2,y2)����
double dis(double x,double y,double x1,double y1,double x2,double y2){   
	//double ans = ((x1-x2)*y - (y1-y2)*x + (y1-y2)*x1 - (x1-x2)*y1)/(sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)));
	double ans = ((x1-x)*(y2-y) - (y1-y)*(x2-x)   )/(sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)));

	
	if(ans<0) ans *= -1.0;
	return ans;
} 
int main()
{
	double xx,yy,x1,y1,x2,y2,x,y;
	scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&xx,&yy,&x1,&y1,&x2,&y2,&x,&y);
	//���� 
	if(    ( fabs(x1+x2+xx-x*3)<1e-8  )  &&  (  fabs(yy+y1+y2-y*3)<1e-8  )    ){
		printf("Yes\n");
		return 0;
	}
	x1 -= xx;	x2 -= xx;	
	y1 -= yy;	y2 -= yy;
	x  -= xx;   y  -= yy;
	if(     fabs((y-y1)*y2+(x-x1)*x2)<1e-8   &&   fabs((y2-y1)*y+(x2-x1)*x)<1e-8   ) //���� 
	{
		printf("Yes\n");
		return 0;
	}	
	double s1,s2,s3;                  //����  
	s1 = distance(0.0,0.0,x,y);
	s2 = distance(x,y,x1,y1);
	s3 = distance(x,y,x2,y2);
	if(fabs(s1-s2)<1e-8  &&  fabs(s1-s3)<1e-8  &&  fabs(s2-s3)<1e-8 ){
		printf("Yes\n"); 
		return 0;
	} 
	double r = fabs(x1*y2-y1*x2)/(distance(0.0,0.0,x1,y1) + distance(0.0,0.0,x2,y2) + distance(x1,y1,x2,y2)); 
	s1 = dis(x,y,0.0,0.0,x1,y1);   //���� 
	s2 = dis(x,y,0.0,0.0,x2,y2);
	s3 = dis(x,y,x1 , y1,x2,y2);
	if(fabs(s1-r)<1e-8  &&  fabs(s1-r)<1e-8  &&  fabs(s2-r)<1e-8 ){
		printf("Yes\n");
		return 0;
	} 
	
	printf("No\n");
	
	
	return 0;
}
