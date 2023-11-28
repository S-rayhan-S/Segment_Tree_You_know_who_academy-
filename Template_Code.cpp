#include<bits/stdc++.h>
#include<iostream>
using namespace std;
#define fasterIO ios::sync_with_stdio(0); cin.tie(0);
//Snippet_list:snippet for algos
typedef vector<int> vi;
typedef vector<long long> vll;
//typedef pair<int,int> Pii;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
#define Pll pair<ll,ll>
#define Pii pair<int,int>
#define ld  long double
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define FF first
#define SS second
#define SZ(x) ((int)(x).size())
#define mset(a,x) memset(a, x, sizeof(a))
#define forn(i,a,n) for (int i=a;i<n;i++)
#define printclock  cerr<<"Time : "<<1000*(ld)clock()/(ld)CLOCKS_PER_SEC<<"ms\n";
const ll MOD=1000000007;
// Bitmask:     for(int i=1;i<(1<<n);i++){for(int j=1;j<=n;j++){if(i&(1<<(j-1))){}}}
ll   gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
ll   Lcm(ll a,ll b) {return ((a*b)/__gcd(a,b));}
ll   POW(ll a,ll b) {ll res = 1;while (b > 0) {if (b & 1)res = res * a;a = a * a;b >>= 1;}return res; }
int  sum_digit(int x) { int sum=0; while(x>0){ sum+=x%10; x/=10; } return sum; }
ll   reverse_num(ll n){ ll tmp=n, ans=0, r; while(tmp>0){ r=tmp%10; ans=ans*10+r; tmp/=10; } return ans; }
bool isSquare(ll x){ll sq=sqrt(x);return sq*sq==x;}
bool prime(ll n) { if(n<2) return false; for(ll i=2;i<=sqrt(n);i++){ if(n%i==0)return false;} return true; }
ll   string_to_int(string s){ int len = (int)s.size();ll ans=0;forn(i,0,len)ans=ans*10+(int)s[i]-'0';return ans; }

#define CY cout<<"YES\n";
#define CN cout<<"NO\n";
#define CYR cout<<"YES\n";return;
#define CNR cout<<"NO\n";return;
#define C(s) cout<<s<<endl;

const int lim=1e5+9;
int seg_ar[lim];
int seg_tre[lim*4];

//b=begin,e=end
void build_tree(int node,int b,int e){

	if(b==e){
		seg_tre[node]=seg_ar[b];
		return ;
	}
	int l=2*node,r=2*node+1;
	int mid=(b+e)/2;
	build_tree(l,b,mid);
	build_tree(r,mid+1,e);
	seg_tre[node]=seg_tre[l]+seg_tre[r];
}

int query(int node,int b,int e,int i,int j){
	if(b>j||e<i)return 0;
	if(b>=i && e<=j)
		return seg_tre[node];
	int l=2*node,r=2*node+1;
	int mid=(b+e)/2;
	return query(l,b,mid,i,j)+query(r,mid+1,e,i,j);
}

void update_segtre(int node,int b,int e,int i,int x){
	if(b>i||e<i)return;
	if(b==e && b==i){
		seg_tre[node]=x;
		return;
	}
	int l=2*node,r=2*node+1;
	int mid=(b+e)/2;
	update_segtre(l,b,mid,i,x);
	update_segtre(r,mid+1,e,i,x);
	seg_tre[node]=seg_tre[l]+seg_tre[r];

}


void fun()
{
	int n=5;
	for(int i=1;i<=n;i++){
		seg_ar[i]=i;
	}
	for(int i=1;i<=n;i++)cout<<seg_ar[i]<<" ";
		cout<<endl;
	build_tree(1,1,n);
	for(int i=1;i<=11;i++)
		cout<<i<<":"<<seg_tre[i]<<",";
	cout<<endl;

    cout<<query(1,1,n,2,4)<<endl;
    //update index 2
    update_segtre(1,1,n,3,10);
    //updated sum of idex 2 to 4
    cout<<query(1,1,n,2,4)<<endl;

}


int main()
{
    fasterIO
    #ifndef ONLINE_JUDGE
    freopen("D:/input_output/input.txt", "r", stdin);
    freopen("D:/input_output/output.txt", "w", stdout);
    #endif
    int t=1;//cin>>t;
    while(t--)
    {
        fun();
    }
    
    printclock

}

