 #include<bits/stdc++.h>
 using namespace std;

 #define mod         1000000007
 #define small       INT_MIN
 #define large       INT_MAX
 #define BigInt      __int128

 #define inl         long long
 #define ll          long long
 #define lli         long long int
 #define ld          long double
 #define db          double

 #define rep(i,n)    for(ll i=0;i<n;i++)
 #define f(i,a,b)    for(ll i=(ll)a;i<(ll)b;i++)
 #define rep2(i,j,n) rep(i,n) rep(j,n)
 #define trav(a,x)   for (auto& a : x)

 #define pb          push_back
 #define mp          make_pair
 #define ff          first
 #define ss          second

 #define pii         pair<int,int>
 #define mii         map<int,int>
 #define mll         map<ll,ll>
 #define pll         pair<ll,ll>
 #define vi          vector<int>
 #define vl          vector<ll>
 #define vpi         vector<pii>
 #define vpl         vector<pll>
 #define cd          complex<ld>

 #define inp(a,n)    int a[n]; for(int i=0;i<n;i++)  cin>>a[i];
 #define inpl(a,n)   ll a[n];  for(ll i=0;i<n;i++)   cin>>a[i];
 #define out(a,n)    for(int i=0;i<n;i++) cout<<a[i]<<" "; cout<<endl;
 #define outl(a,n)   for(ll i=0;i<n;i++)  cout<<a[i]<<" "; cout<<endl;
 #define ass(x,a)    memset(x,a,sizeof(x))
 #define all(x)      begin(x), end(x)
 #define rall(x)     rbegin(x), rend(x)
 #define sz(a)       a.size()
 #define test        ll t; cin>>t; while(t--)
 #define fast        ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

 namespace input {
     template<class T>              void re(complex<T>& x);
     template<class T1,             class T2> void re(pair<T1,T2>& p);
     template<class T>              void re(vector<T>& a);
     template<class T, size_t SZ>   void re(array<T,SZ>& a);

     template<class T> void re(T& x) { cin >> x; }
     void re(double& x)              { string t; re(t); x = stod(t); }
     void re(ld& x)                  { string t; re(t); x = stold(t); }

     template<class T, class... Ts> void re(T& t, Ts&... ts) {
         re(t); re(ts...);
     }

     template<class T> void re(complex<T>& x) { T a,b; re(a,b); x = cd(a,b); }
     template<class T1, class T2> void re(pair<T1,T2>& p) { re(p.ff,p.ss); }
     template<class T> void re(vector<T>& a) { rep(i,sz(a)) re(a[i]); }
     template<class T, size_t SZ> void re(array<T,SZ>& a) { rep(i,SZ) re(a[i]); }
 }
 using namespace input;

 namespace output {
     void pr(int x) { cout << x; }
     void pr(long x) { cout << x; }
     void pr(ll x) { cout << x; }
     void pr(unsigned x) { cout << x; }
     void pr(unsigned long x) { cout << x; }
     void pr(unsigned long long x) { cout << x; }
     void pr(float x) { cout << x; }
     void pr(double x) { cout << x; }
     void pr(ld x) { cout << x; }
     void pr(char x) { cout << x; }
     void pr(const char* x) { cout << x; }
     void pr(const string& x) { cout << x; }
     void pr(bool x) { pr(x ? "true" : "false"); }
     template<class T> void pr(const complex<T>& x) { cout << x; }

     template<class T1, class T2> void pr(const pair<T1,T2>& x);
     template<class T> void pr(const T& x);

     template<class T, class... Ts> void pr(const T& t, const Ts&... ts) {
         pr(t); pr(ts...);
     }
     template<class T1, class T2> void pr(const pair<T1,T2>& x) {
         pr("{",x.f,", ",x.s,"}");
     }
     template<class T> void pr(const T& x) {
         pr("{"); // const iterator needed for vector<bool>
         bool fst = 1; for (const auto& a: x) pr(!fst?", ":"",a), fst = 0;
         pr("}");
     }

     void ps() { pr("\n"); } // print w/ spaces
     template<class T, class... Ts> void ps(const T& t, const Ts&... ts) {
         pr(t); if (sizeof...(ts)) pr(" "); ps(ts...);
     }

     void pc() { pr("]\n"); } // debug w/ commas
     template<class T, class... Ts> void pc(const T& t, const Ts&... ts) {
         pr(t); if (sizeof...(ts)) pr(", "); pc(ts...);
     }
     #define dbg(x...) pr("[",#x,"] = ["), pc(x);
 }
 using namespace output;
 mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

 int main()
 {
     pr("\nNo of values:");
     ll n;re(n);
     vl x(n),y(n);
     ld avg_x=0,avg_y=0;
     pr("\nEnter data for Feature 1:\n");
     rep(i,n)cin>>x[i],avg_x+=x[i];
     pr("\nEnter data for Feature 2:\n");
     rep(i,n)cin>>y[i],avg_y+=y[i];
     avg_x/=n;
     avg_y/=n;
     pr("\nMean Feature 1: ",avg_x);
     pr("\nMean Feature 2: ",avg_y);

     ll cov[2][2]={};
     rep(i,2)
     {
         rep(j,2)
         {
             //(x-u1)*(y-u2)
             ld temp=0;
             if(i!=j)
             {
                 rep(k,n)
                 {
                     temp+=( (x[k]-avg_x)*(y[k]-avg_y) );
                 }
             }
             if(i==j&&i==0)
             {
                 rep(k,n)
                 {
                     temp+=( (x[k]-avg_x)*(x[k]-avg_x) );
                 }
             }
             if(i==j&&i==1)
             {
                 rep(k,n)
                 {
                     temp+=( (y[k]-avg_y)*(y[k]-avg_y) );
                 }
             }
             temp/=(n-1);
             cov[i][j]=temp;
         }
     }

     pr("\nCovar Matrix:\n");
     rep(i,2)
     {
         rep(j,2)cout<<setw(6)<<cov[i][j];
         pr("\n");
     }

     //Eqn: X^2-(a+d)x+ad-bc=0;
     ld C=((cov[0][0]*cov[1][1])-(cov[1][0]*cov[0][1]));
     ld B=-(cov[0][0]+cov[1][1]);

     ld D=(B*B-4*C);
     ld temp=sqrt(D);
     pr("\nEquation :\n");
     cout<<"X^2 + ("<<B<<") X + ("<<C<<")"<<endl;

     ld root1=(-B+temp)/2;
     ld root2=(-B-temp)/2;

     pr("\nRoot1: ",root1);
     pr("\nRoot2: ",root2);

     ld pca=max(root1,root2);
     pr("\nEigen Vector Matrix:\n");

     ld a00=cov[0][0]-pca,a01=cov[0][1],a10=cov[1][0],a11=cov[1][1]-pca;
     cout<<cov[0][0]-pca<<"X + ("<<cov[0][1]<<")Y=0\n";
     cout<<cov[1][0]<<"X + ("<<cov[1][1]-pca<<")Y=0\n";

     pr("\nNormalized U1:\n");
     temp=pow(a00,2)+pow(a01,2);
     temp=sqrt(temp);

     pr("\n[",-a01/temp,"  ",a00/temp,"]\n");
     return 0;
 }
