#include <math.h>
#include <stdio.h>

double do_nothing(double x){
	return x;
}

int main(){
	int n, k;
	scanf("%d %d", &n, &k);
	double e0=1.0, d=1.0/(double)n;
	while(do_nothing(1.0+e0/2.0)>1.0){
		e0=e0/2.0;
	}
	printf("Machine epsilon equals %.8e\n", e0);
	printf("--------------------------------------\n");
	double acc=e0*pow(10, 16-k);
	double x=0.0, ans1, ans2, count, cur;
	int step;
	for(int i=0; i<=n; i++){
		ans1=0;
		ans2=sin(x);
		step=0;
		count=1.0;
		cur=x;
		while(fabs(ans1-ans2)>acc){
			ans1+=cur;
			count+=2;
			cur*=(-1)*x*x/(count*(count-1.0));
			step++;
		}
		printf("%.2f | %.*f | %.*f | %d | %.*f\n", x, k+1, ans1, k+1, ans2, step, k+1, fabs(ans2-ans1));
		x+=d;
	}
	return 0;
}
