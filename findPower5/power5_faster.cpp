#include<iostream>
#include<vector>
#include<string>
#include<chrono>
#include<climits>
#include<fstream>

using namespace std;
typedef long long ll;
#define loop(i,k,n) for((i) = (k); (i) < (n); (i)++)
#define rloop(i,k,n) for((i) = (k); (i) >= (n); (i)--)
//const ll mod =  998244353;
//const ll mod = 1e9+7;

int main()
{   
    //定数定義
    const int max_ansnum = 10000; //発見最大数
    const int max_ans = 500; //見つける答の最大数(この数値と五乗が符号付き64ビットの最大数の小さい値が実際の最大数になります)
    string filename = "power5_under" + to_string(max_ans) +".txt"; //出力ファイル名
    //変数定義
    ll maxnum,maxsum;
    ll i,j,k,l;
    ll numa=0, a[max_ansnum]={0},b[max_ansnum]={0},c[max_ansnum]={0},d[max_ansnum]={0},e[max_ansnum]={0};
    vector<ll> powerfive;
    powerfive.reserve(6300);
    ll sum;
    //時間計測開始
    chrono::system_clock::time_point begin;
    begin = std::chrono::system_clock::now();
    //初期化（あらかじめその数の5乗を記録）
    i=0;
    powerfive.push_back(0);
    while(max_ans > i && powerfive[i] < LLONG_MAX/4){i++; powerfive.push_back(i*i*i*i*i);}
    maxnum = i;
    bool is_over=false;
    ll inst=1;
    while(max_ans > i && !is_over){
        i++;
        inst=1;
        loop(k,0,4){
            inst *= i; 
            if(inst > LLONG_MAX/i){
                is_over = true;
                i--; 
                break;
            }
        }
        inst *= i;
        powerfive.push_back(inst);
    }
    maxsum =i;

    while(powerfive[maxnum] < powerfive[maxsum]/4){
        maxsum--;
    }
    //探索開始
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
                            a[numa] = j; 
                            b[numa] = k;
                            c[numa] = l;
                            d[numa] = last;
                            e[numa] = i; 
                            numa++;
                            //発見数が上限を超えた場合までの結果すべて出力し強制終了
                            if(numa == max_ansnum){
                                ofstream writing_file;
                                string text;
                                writing_file.open(filename, std::ios::out);
                                cout << endl;                            
                                text = "out of stock-----\n";
                                cout << text;
                                writing_file << text;
                                chrono::system_clock::time_point end;
                                end = std::chrono::system_clock::now();
                                text = "numberunder:" + to_string(maxsum) + "\n";
                                writing_file << text;
                                cout << text;
                                text = "発見個数：" + to_string(numa) + "個" + " " + "所要時間：" + to_string(chrono::duration_cast<std::chrono::minutes>(end-begin).count()) + "分\n";
                                writing_file << text;
                                cout << text;
                                loop(i,0,numa){
                                    text = to_string(a[i]) + "^5+" + to_string(b[i]) + "^5+" + to_string(c[i]) + "^5+" + to_string(d[i]) + "^5=" + to_string(e[i]) + "^5"  + "\n";
                                    writing_file << text;
                                    cout << text;
                                }
                                text = "-----stop produceing in \"" + to_string(i)  + "\"\n";
                                writing_file << text;
                                cout << text;
                                writing_file.close();
                                abort();
                            }               
                        }
                    }
                    
                }
            }
        }
    }
    //結果出力
    ofstream writing_file;
    writing_file.open(filename, std::ios::out);
    cout << endl;
    chrono::system_clock::time_point end;
    end = std::chrono::system_clock::now();
    string text;
    text = "numberunder:" + to_string(maxsum) + "\n";
    writing_file << text;
    cout << text;
    text = "発見個数：" + to_string(numa) + "個" + " " + "所要時間：" + to_string(chrono::duration_cast<std::chrono::minutes>(end-begin).count()) + "分\n";
    writing_file << text;
    cout << text;
    loop(i,0,numa){
        text = to_string(a[i]) + "^5+" + to_string(b[i]) + "^5+" + to_string(c[i]) + "^5+" + to_string(d[i]) + "^5=" + to_string(e[i]) + "^5"  + "\n";
        writing_file << text;
        cout << text;
    } 
    writing_file.close();

    return 0;
}