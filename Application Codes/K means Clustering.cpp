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

 class point
 {
     public:
     ld x,y;
     void setPoint(ld x,ld y)
     {
         this->x=x;
         this->y=y;
     }

     void getPoint()
     {
         cout<<" ("<<x<<","<<y<<") ";
     }
     ld euclidean(ld a,ld b)
     {
         ld res=(pow((x-a),2)+pow((y-b),2));
         return sqrt(res);
     }
     ld euclidean(point p)
     {
         ld a=p.x;
         ld b=p.y;
         ld res=(pow((x-a),2)+pow((y-b),2));
         return sqrt(res);
     }

     point getMean(point p)
     {
         point res;
         res.x=(x+p.x)/2;
         res.y=(y+p.y)/2;
         return res;
     }
 };

 int main()
 {
     ll n,k;pr("Enter N: ");re(n);
     ll temp,i=0;
     pr("\nEnter no of centroids:");re(k);
     pr("\nEnter ",n," Points:\n");
     point a[n];
     rep(i,n)
     {
         ld x,y;re(x,y);
         a[i].setPoint(x,y);
     }

     cout<<"\nEnter k centroids position:";
     set<ll> posCentroid;
     rep(i,k)cin>>temp,posCentroid.insert(temp);

     pr("\nThe centroids are: ");
     point centroids[k];
     vl result[k];
     for(auto it:posCentroid)
     {
         centroids[i].setPoint(a[it-1].x,a[it-1].y);
         centroids[i].getPoint();
         result[i].pb(it);
         i++;
     }
     cout<<"\n";

     rep(i,n)
     {
         if(posCentroid.find(i+1)==posCentroid.end())
         {
             ld dis[k];
             ll pos;
             ld disMin=large;
             for(ll curr=0;curr<k;curr++)
             {
                 dis[curr]=a[i].euclidean(centroids[curr]);
                 if(dis[curr]<disMin)
                 {
                     disMin=dis[curr];
                     pos=curr;
                 }
             }


             cout<<"\nThe euclidean dist of point ";
             a[i].getPoint();
             cout<<" from clusters is:\n";
             rep(curr,k)pr(dis[curr]," ");
             cout<<"\nLowest distance is from cluster "<<pos+1<<" is "<<disMin;
             cout<<"\nNew mean of cluster: ";
             centroids[pos]=centroids[pos].getMean(a[i]);
             centroids[pos].getPoint();
             cout<<endl;
             result[pos].pb(i+1);
         }
     }

     cout<<"\nFinal Cluster:\n";
     rep(i,k)
     {
         cout<<"Cluster "<<i+1<<" : ";
         rep(j,result[i].size())cout<<result[i][j]<<" ";
         cout<<endl;
     }

     cout<<"\nFinal centroid values:\n";
     rep(i,k)centroids[i].getPoint();
     return 0;
 }
