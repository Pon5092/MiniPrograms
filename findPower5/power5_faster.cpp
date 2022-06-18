#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<chrono>
#include <climits>
#include<fstream>

using namespace std;
typedef long long ll;
#define loop(i,k,n) for((i) = (k); (i) < (n); (i)++)
#define rloop(i,k,n) for((i) = (k); (i) >= (n); (i)--)
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
    vector<ll> powerfive;
    powerfive.reserve(6300);
    ll sum, sumback;
    ll now=1;
    
    chrono::system_clock::time_point begin;
    begin = std::chrono::system_clock::now();
    
    i=0;
    powerfive.push_back(0);
    while(powerfive[i] < LLONG_MAX/4){i++; powerfive.push_back(i*i*i*i*i);}
    maxnum = i;
    bool is_over=false;
    ll inst=1;
    while(!is_over){
        i++; 
        inst=1;
        loop(k,0,4){
            inst *= i; 
            if(inst > LLONG_MAX/i){
                is_over = true; 
                break;
            }
        }
        inst *= i;
        powerfive.push_back(inst);
    }
    maxsum =i-1;

    while(powerfive[maxnum] < powerfive[maxsum]/4){
        maxsum--;
    }
    std::cout << "maxnum:" << maxnum <<" maxsum:" << maxsum << "\n";
    std::cout << "begin" << "\n";
    ll sumj,sumjk,sumjkl,last,sumlast;
    rloop(i,maxsum,2){
        cout << "start:" << i << " ";
        if(i < maxnum) maxnum = i-1;
        sum = powerfive[i];
        rloop(j,maxnum,2){
            sumj = sum - powerfive[j];
            if(sumj <= 0) continue;
            if(sumj/3 > powerfive[j]) break;
            rloop(k,j,2){
                sumjk = sumj - powerfive[k];
                if(sumjk <= 0) continue;
                if(sumjk/2 > powerfive[k]) break;
                rloop(l,k,2){
                    sumjkl = sumjk - powerfive[l];
                    if(sumjkl <= 0) continue;
                    if(sumjkl > powerfive[l]) break;
                    rloop(last,l,2){
                        sumlast = sumjkl - powerfive[last];
                        if(sumlast < 0) continue;
                        if(sumlast > 0) break;
                        if(!sumlast) {
                            cout << "found";
                            ia[numa] = j; 
                            ja[numa] = k;
                            ka[numa] = l;
                            la[numa] = last;
                            nowa[numa] = i; 
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
                    }
                    
                }
            }
        }
    }
    
    std::ofstream writing_file;
    std::string filename = "sample.txt";
    writing_file.open(filename, std::ios::out);
    std::cout << endl;
    chrono::system_clock::time_point end;
    end = std::chrono::system_clock::now();
    writing_file << "numberunder:" << maxsum << "\n";
    writing_file << "発見個数：" << numa <<"個" << " " << "所要時間：" << chrono::duration_cast<std::chrono::minutes>(end-begin).count() << "分" << endl;
    loop(i,0,numa) writing_file << ia[i] << "^5+" << ja[i] << "^5+" << ka[i] << "^5+" << la[i] << "^5=" << nowa[i] << "^5"  << "\n";
    std::cout << "発見個数：" << numa <<"個" << " " << "所要時間：" << chrono::duration_cast<std::chrono::minutes>(end-begin).count() << "分" << endl;
    loop(i,0,numa) std::cout << ia[i] << "^5+" << ja[i] << "^5+" << ka[i] << "^5+" << la[i] << "^5=" << nowa[i] << "^5"  << "\n";

    writing_file.close();

    return 0;
}