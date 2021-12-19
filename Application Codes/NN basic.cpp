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

 ld activation(ld x,ll choice)
 {
     ld res;
     if(choice==1)
     {
         return (1.0 / (1.0 + exp(-x)));
     }
     else if(choice==2)
     {
         if(x>=0)return x;
         else return 0;
     }
     else if(choice==3)
     {
         return ((exp(x)-exp(-x))/(exp(x)+exp(-x)));
     }
     else if(choice==4)
     {
         return x;
     }
     return x;
 }

 ld calc_error(ld op,ld act)
 {
     ld temp=pow((op-act),2);
     temp/=2;
     return temp;
 }
 int main()
 {
     ll n,m;
     cout<<"\nDimensions: (I/p Layer x Next Layer): ";re(n,m);
     ld label[n];
     ld weights[n][m];
     cout<<"\nEnter "<<n<<" labels:\n";rep(i,n)cin>>label[i];

     cout<<"\nEnter the weight matrix ("<<n<<"X"<<m<<"):\n";
     rep(i,n)
     {
         rep(j,m)cin>>weights[i][j];
     }

     ld bias;cout<<"\nBias value:\n";re(bias);
     ll actFunction;cout<<"\nActivation function:\n1)Sigmoid\n2Relu\n3)Tanh\n4)Linear: ";re(actFunction);

     ld hidden_1[m];
     rep(j,m)
     {
         cout<<"\nFor Y"<<j+1<<":  ";
         ld temp=0;
         rep(i,n)
         {
             cout<<"("<<label[i]<<"x"<<weights[i][j]<<") +";
             temp+=label[i]*weights[i][j];
         }
         cout<<" "<<bias;
         temp+=bias;
         cout<<"= "<<temp;
         temp=activation(temp,actFunction);
         cout<<"\nAfter Activation function for Y"<<j+1<<" :"<<temp;
         hidden_1[j]=temp;
     }

     char choice;cout<<"\nFurther Layer present: y/n? ";re(choice);

     if(choice=='y')
     {
         ll m2;
         cout<<"\nDimension of 2nd hidden layer:";re(m2);
         cout<<"\nEnter the weight matrix ("<<m<<"X"<<m2<<"):\n";
         ld weights_2[m][m2];
         rep(i,m)
         {
             rep(j,m2)cin>>weights_2[i][j];
         }

         ld bias_2;cout<<"\nBias value:\n";re(bias_2);
         ld hidden_2[m2];

         rep(j,m2)
         {
             cout<<"\nFor Y"<<j+1<<":  ";
             ld temp=0;
             rep(i,m)
             {
                 cout<<"("<<hidden_1[i]<<"x"<<weights_2[i][j]<<") +";
                 temp+=hidden_1[i]*weights_2[i][j];
             }
             cout<<" "<<bias_2;
             temp+=bias_2;
             cout<<"= "<<temp;
             temp=activation(temp,actFunction);
             cout<<"\nAfter Activation function for Y"<<j+1<<" :"<<temp;
             hidden_2[j]=temp;
         }


         //OUTPUT LAYER
         ll m_final;cout<<"\nEnter no of outputs:";re(m_final);
         cout<<"\nEnter the weight matrix ("<<m2<<"X"<<m_final<<"):\n";
         ld weights_final[m2][m_final];
         rep(i,m2)
         {
             rep(j,m_final)cin>>weights_final[i][j];
         }

         ld bias_final;cout<<"\nBias value:\n";re(bias_final);
         ld out[m_final];

         rep(j,m_final)
         {
             cout<<"\nFor Y"<<j+1<<":  ";
             ld temp=0;
             rep(i,m2)
             {
                 cout<<"("<<hidden_2[i]<<"x"<<weights_final[i][j]<<") +";
                 temp+=hidden_2[i]*weights_final[i][j];
             }
             cout<<" "<<bias_final;
             temp+=bias_final;
             cout<<"= "<<temp;
             temp=activation(temp,actFunction);
             cout<<"\nAfter Activation function for Y"<<j+1<<" :"<<temp;
             out[j]=temp;
         }

         ld actual[m_final],error[m_final],totalError=0;cout<<"\nEnter the actual outputs:";rep(i,m_final)cin>>actual[i];
         cout<<"\nERROR CALCULATION:\nThe errors are: ";
         rep(i,m_final)
         {
             error[i]=calc_error(actual[i],out[i]);
             cout<<error[i]<<"+ ";
             totalError+=error[i];
         }
         cout<<"= "<<totalError<<endl;
         return 0;
     }

     //FINAL LAYER
     ll m_final;cout<<"\nEnter no of outputs:";re(m_final);
     cout<<"\nEnter the weight matrix ("<<m<<"X"<<m_final<<"):\n";
     ld weights_final[m][m_final];
     rep(i,m)
     {
         rep(j,m_final)cin>>weights_final[i][j];
     }

     ld bias_final;cout<<"\nBias value:\n";re(bias_final);
     ld out[m_final];

     rep(j,m_final)
     {
         cout<<"\nFor Y"<<j+1<<":  ";
         ld temp=0;
         rep(i,m)
         {
             cout<<"("<<hidden_1[i]<<"x"<<weights_final[i][j]<<") +";
             temp+=hidden_1[i]*weights_final[i][j];
         }
         cout<<" "<<bias_final;
         temp+=bias_final;
         cout<<"= "<<temp;
         temp=activation(temp,actFunction);
         cout<<"\nAfter Activation function for Y"<<j+1<<" :"<<temp;
         out[j]=temp;
     }

     ld actual[m_final],error[m_final],totalError=0;cout<<"\nEnter the actual outputs:";rep(i,m_final)cin>>actual[i];
     cout<<"\nERROR CALCULATION:\nThe errors are: ";
     rep(i,m_final)
     {
         error[i]=calc_error(actual[i],out[i]);
         cout<<error[i]<<"+ ";
         totalError+=error[i];
     }
     cout<<"= "<<totalError<<endl;


     cout<<"\nBACK PROPAGATION: (sigmoid)\n";
     ld t1[m_final],t2[m_final],t3[m_final];
     rep(i,m_final)
     {
         cout<<"For output"<<i+1<<":\n";
         t1[i]=out[i]-actual[i];
         t2[i]=(out[i]*(1-out[i]));
         t3[i]=hidden_1[i];
         cout<<"d(ErrorTotal)/d(out"<<i+1<<"): "<<t1[i]<<endl;
         cout<<"d(out)/d(net"<<i+1<<"): "<<t2[i]<<endl;
         cout<<"d(net)/d(W"<<i+1<<"): "<<t3[i]<<endl;

         ld tot=t1[i]*t2[i];
         tot*=t3[i];
         cout<<"d(ErrorTotal)/d(W"<<i+1<<"): "<<tot<<endl;
     }
     return 0;
 }
