#include<bits/stdc++.h>
using namespace std;
class Process {
	float Arrival;
	float Burst;
	public:
		void Nhap() { cin>>Arrival>>Burst;}
		float getArrival() {
			return Arrival;
		}
		float getBurst() {
			return Burst;
		}
};
int main(){
	int n;
	cin>>n;
	Process *p=new Process[n];
	for(int i=0;i<n;i++) {
		p[i].Nhap();
	}
	float *end,*wait,*save;
	end=new float[n];
	wait=new float[n];
	save=new float[n];
	for(int i=0;i<n;i++) {
		if(i==0) {
			end[i]=p[i].getArrival()+p[i].getBurst();
		} else {
			end[i]=max(end[i-1],p[i].getArrival())+p[i].getBurst();
		}
		wait[i]=end[i]-p[i].getArrival()-p[i].getBurst();
		save[i]=wait[i]+p[i].getBurst();
	}
	for(int i=0;i<n;i++) {
		cout<<"Process "<<i+1<<" wait time: "<<wait[i]<<" save time: "<<save[i]<<endl;
	}
	float Wtb=0;
	float Stb=0;
	for(int i=0;i<n;i++) {
		Wtb+=wait[i];
		Stb+=save[i];
	}
	cout<<" average wait time: "<<fixed<<setprecision(2)<<Wtb/n*1.0
		<<" average save time: "<<fixed<<setprecision(2)<<Stb/n*1.0;
	delete[] p;
	delete[] end;
	delete[] wait;
	delete[] save;
	return 0;
}
