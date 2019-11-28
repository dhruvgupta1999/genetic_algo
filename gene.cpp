/*input
6
5
*/
#include <bits/stdc++.h>
#define endl "\n"
#define ll long long int
#define vi vector<int>
#define vll vector<ll>
#define vvi vector < vi >
#define pii pair<int,int>
#define pll pair<long long, long long>
#define mod 1000000007
#define inf 1000000000000000001;
#define all(c) c.begin(),c.end()
#define mp(x,y) make_pair(x,y)
#define mem(a,val) memset(a,val,sizeof(a))
#define eb emplace_back
#define f first
#define s second
#define watch(x) cout << (#x) << " is " << (x) << endl
#define N 100002

using namespace std;


float myrand(int x)
{
	return (rand()/(float)RAND_MAX)*x;
}


int main()
{
	ll T=1000,n,m;string str;
	cin>>n>>m;
	// cin>>T;	
	// cin.ignore(); put after cin, just b4 a getline(cin, s) to avoid getline() directly getting \n
	while(T--)
	{
		// watch(T);
		ll p=0,q=0,tmp=0,sum=0,count=0; //tmp variable
		int flag=0;
		int root_m = (int)sqrt(m);
		// cout << "hello" << endl;
		vector < pair<float,float> > v;
		for (ll i = 0; i < n; ++i)
		{
			v.eb(mp(myrand(root_m),myrand(root_m)));
		}
		// cout << "debugging >>>>>>>>" << endl;
		for (ll i = 0; i < n; ++i)
		{
			cout << v[i].f << " " << v[i].s << endl;
		}
		cout  << endl;
		float obj_fn[n];
		for (ll i = 0; i < n; ++i)
		{
			obj_fn[i] = abs(v[i].f*v[i].f + v[i].s*v[i].s - m*m);
		}
		float fitness[n];
		for (ll i = 0; i < n; ++i)
		{
			fitness[i]= 1/(1 + obj_fn[i]);	
			watch(fitness[i]);		
		}
		float sum_fitness=0;
		for (ll i = 0; i < n; ++i)
		{
			sum_fitness += fitness[i];
		}
		watch(sum_fitness);
		
		float prob[n];
		for (ll i = 0; i < n; ++i)
		{
			prob[i]=fitness[i]/sum_fitness;
		}cout  << endl;
		float cum_prob[n];
		float sum_prob=0;
		for (ll i = 0; i < n; ++i)
		{
			sum_prob+=prob[i];
			cum_prob[i]=sum_prob;
			watch(cum_prob[i]);
		}cout << endl;
		float rand_arr[n];
		for (ll i = 0; i < n; ++i)
		{
			rand_arr[i]=myrand(1);
		}
		vector < pair<float,float> > new_chromo;
		for (ll i = 0; i < n; ++i)  // wrong
		{
			int j=0;
			while(j<(n-1) && rand_arr[i] > cum_prob[j])
			{
				j++;
			}
			new_chromo.eb(v[j]);
		}
		
		watch(new_chromo.size());
		for (ll i = 0; i < new_chromo.size(); ++i)
		{
			watch(new_chromo[i].f);
		}cout  << endl;
		
		
		for (ll i = 0; i < new_chromo.size(); ++i)
		{
			v[i] = new_chromo[i];	
		}
		
		float crossover_rate = 0.25;
		vector < int > crossover_v;
		for (ll i = 0; i < n; ++i)
		{
			rand_arr[i]=myrand(1);
			if(rand_arr[i] < crossover_rate)
			{
				crossover_v.eb(i);
			}
		}
		
		int cross_size = crossover_v.size();
		
		for (ll i = 0; i < cross_size; ++i)
		{
			watch(crossover_v[i]);
		}
		
		
		
		for (ll i = 0; i < cross_size; ++i)
		{
			v[crossover_v[i]]= mp(v[crossover_v[i]].f,v[crossover_v[(i+1)%cross_size]].s);
			 
		}
		int par_num = n*2;
		
		float mut_rate = 0.1;
		
		int mut_num = (int)round(par_num * mut_rate);
		
		for (ll i = 0; i < mut_num; ++i)
		{
			int ind = (int)myrand(par_num);
			if(ind%2==0)
			{
				v[ind/2].f = (int)ceil(myrand(root_m));
			}
			else if(ind%2==1)
			{
				v[ind/2].s = (int)ceil(myrand(root_m));
			}
		}
		
		for (ll i = 0; i < n; ++i)
		{
			cout << v[i].f << " " << v[i].s << " :" << v[i].f*v[i].f +  v[i].s*v[i].s<< endl;
		}
		cout  << endl;	
	}
	return 0;
}