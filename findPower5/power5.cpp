#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<chrono>
#include <climits>

using namespace std;
typedef long long ll;
#define loop(i,k,n) for((i) = (k); (i) < (n); (i)++)
#define rloop(i,k,n) for((i) = (k); (i) > (n); (i)--)
#define outyes cout << "Yes" << endl  
#define outno cout << "No" << endl
#define outans cout << ans << endl
//const ll mod =  998244353;
//const ll mod = 1e9+7;

int main()
{
    ll maxnum,maxsum;
    //ios::sync_with_stdio(false);
    //cin.tie(nullptr);
    ll i,j,k,l,m;
    ll numa=0, ia[10000]={0},ja[10000]={0},ka[10000]={0},la[10000]={0},nowa[10000]={0};
    ll powerfive[6300] = {1};
    ll sum, sumback;
    ll now=1;
    
    chrono::system_clock::time_point begin;
    begin = std::chrono::system_clock::now();
    
    i=0;
    powerfive[0] = 0;
    while(powerfive[i] < LLONG_MAX/4){i++; powerfive[i] = i*i*i*i*i;}
    maxnum = i;
    bool is_over=false;
    while(!is_over){
        i++; 
        loop(k,0,5){
            powerfive[i] *= i; 
            if(powerfive[i] > LLONG_MAX/i){
                is_over = true; 
                break;
            }
        }
    }
    maxsum =i-1;
    cout << "begin" << "\n";
    loop(i,2,maxnum){ 
        loop(j,i,maxnum){
            cout << i << "-" << j << "start";
            loop(k,j,maxnum){
                loop(l,k,maxnum){
                    now = l+1;
                    loop(now,k+1,maxsum){
                        sum = powerfive[now];
                        sum -= powerfive[l];
                        if(sum <0) continue;
                        sum -= powerfive[k];
                        if(sum <0) continue;
                        sum -= powerfive[j];
                        if(sum <0) continue;
                        sum -= powerfive[i];
                        if(sum <0) continue;
                        if(sum == 0) {
                            cout << "found";
                            ia[numa] = i; 
                            ja[numa] = j;
                            ka[numa] = k;
                            la[numa] = l;
                            nowa[numa] = now; 
                            numa++;
                            if(numa == 10000){
                                cout << "out of stock-----"<< endl;
                                chrono::system_clock::time_point end;
                                end = std::chrono::system_clock::now();
                                cout << "発見個数：" << numa <<"個" << " " << "所要時間：" << chrono::duration_cast<std::chrono::minutes>(end-begin).count() << "分" << endl;
                                loop(m,0,numa) cout << ia[m] << "^5+" << ja[m] << "^5+" << ka[m] << "^5+" << la[m] << "^5=" << nowa[m] << "^5"  << "\n";                            
                                cout << "-----stop produceing in \"" << i  << "\""<< endl;
                                abort();
                            }
                        }
                        if(sum>0) break;
                    }
                }
                sumback =0;
            }
        }
    }
    cout << endl;
    chrono::system_clock::time_point end;
    end = std::chrono::system_clock::now();
    cout << "発見個数：" << numa <<"個" << " " << "所要時間：" << chrono::duration_cast<std::chrono::minutes>(end-begin).count() << "分" << endl;
    loop(i,0,numa) cout << ia[i] << "^5+" << ja[i] << "^5+" << ka[i] << "^5+" << la[i] << "^5=" << nowa[i] << "^5"  << "\n";
    return 0;
}