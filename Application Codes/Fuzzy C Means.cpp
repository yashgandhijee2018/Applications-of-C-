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
     point(ld x,ld y)
     {
         this->x=x;
         this->y=y;
     }
     point()
     {
         this->x=0;
         this->y=0;
     }
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
     ll n,k,p;cout<<"\nEnter no of points: ";cin>>n;
     cout<<"\nEnter no of clusters: ";cin>>k;
     cout<<"\nValue of P:";cin>>p;

     ld x,y;
     cout<<"\nEnter n points:\n";
     point a[n],centroids[k];
     rep(i,n)re(x,y),a[i].setPoint(x,y);

     cout<<"\n\nSTEP 1:Assigning of weights\n";
     ld method;
     cout<<"\nMethod? \n1)Assign weights random\n2)Give weights\n";cin>>method;

     ld W[k][n];
     if(method==1)
     {
         ld temp=k;
         rep(i,k)
         {
             rep(j,n)W[i][j]=((ld)(((ld)1)/temp));
         }

     }
     else if(method=2)
     {
         cout<<"\nEnter the weights for k clusters:\n";
         rep(i,k)
         {
             rep(j,n)cin>>W[i][j];
         }
     }

     rep(itr,5)
     {
         cout<<"\nITERATION "<<itr+1<<":\n";
         if(itr==0)
         {
            cout<<"\nThe Weights are:\n";
             rep(i,k)
             {
                 rep(j,n)cout<<setw(10)<<W[i][j];
                 pr("\n");
             }
         }

         cout<<"\n\nSTEP 2: calculation of new centroids\n";
         rep(i,k)
         {
             point num((ld)0,(ld)0);
             ld den=0;
             rep(j,n)
             {
                 num.x+=((pow(W[i][j],p))*(a[j].x));
                 num.y+=((pow(W[i][j],p))*(a[j].y));
                 den+=pow(W[i][j],p);
             }

             cout<<"\nFor cluster "<<i+1<<": ("<<num.x<<","<<num.y<<")/"<<den<<endl;
             centroids[i].setPoint((num.x)/den,(num.y)/den);
         }
         cout<<"\nNew centroids:\n";
         rep(i,k)centroids[i].getPoint();

         cout<<"\n\nSTEP 3:Updating the weights\n";
         ld dist[k][n];
         rep(i,k)
         {
             rep(j,n)dist[i][j]=a[j].euclidean(centroids[i]);
         }
         cout<<"\nDistance matrix:\n";
         rep(i,k)
         {
             rep(j,n)cout<<setw(10)<<dist[i][j];
             cout<<endl;
         }
         cout<<"Assigning new weights:\n";

         rep(i,n)
         {
             rep(j,k)
             {
                 ld distance=dist[j][i];

                 ld numerator=pow(1/distance,1/(p-1));
                 ld denominator=0;
                 ld temp,temp2;
                 rep(pos,k)
                 {
                     temp=dist[pos][i];
                     denominator+=(pow(1/temp,1/(p-1)));
                 }

                 cout<<"\nW("<<j+1<<","<<i+1<<") :"<<numerator<<"/"<<denominator<<endl;
                 W[j][i]=(numerator/denominator);
             }
         }

         cout<<"\nNew weights:\n";
         rep(i,k)
         {
             rep(j,n)cout<<W[i][j]<<" ";
             cout<<endl;
         }
     }

     vl result[k];
     rep(i,n)
     {
         ld maxWeight=small;
         ll pos;
         rep(j,k)
         {
             if(W[j][i]>maxWeight)maxWeight=W[j][i],pos=j;
         }
         result[pos].pb(i+1);
     }

     cout<<"\nFinal Classification:\n";
     rep(i,k)
     {
         cout<<"\nCluster "<<i+1<<": ";
         rep(j,result[i].size())cout<<result[i][j]<<" ";
     }

 }
