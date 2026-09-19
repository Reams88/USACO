#include <iostream>
#include <cstdio>
#include <vector>
#include <climits>
#include <cmath>

using namespace std;
using ll = long long;

template<class T>
void printer(const T& cont) {
  for(const auto& el : cont) cout << el << ' ';
  cout << endl;
}

template<class T>
ll add(const T& cont) {
  ll sum = 0;
  for(const auto& el : cont) sum += el;
  return sum;
}


int main() {
  //freopen("blist.in", "r", stdin);
  //freopen("blist.out", "w", stdout);


  ll n;
  cin >> n;

  vector<ll> weights(n);
  for(int i = 0; i < n; ++i) cin >> weights[i];
  
  ll lowestDiff = LLONG_MAX;
  for(ll b = 0; b < (1<<n); ++b) {
    vector<ll> sub;
    vector<ll> opp;
    for(ll i = 0; i < n; ++i) {
      if(b&(1<<i)) sub.push_back(weights[i]);
      else opp.push_back(weights[i]);
    }
    //printer(sub);
    //printer(opp);
    //cout << endl;
    
    ll diff = abs(add(sub) - add(opp));
    lowestDiff = min(lowestDiff, diff);
  }

  cout << lowestDiff << endl;

  return 0;
}
