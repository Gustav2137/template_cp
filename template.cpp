#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

// {{{ MAKRA
#define pb push_back
#define pf push_front
#define turbo                                                                  \
  cin.tie(0);                                                                  \
  cout.tie(0);                                                                 \
  ios_base::sync_with_stdio(false)
#define fi first
#define sc second
#define ll long long
#define un unsigned
#define vi vector<int>
#define vb vector<bool>
#define vll vector<ll>
#define pii pair<int, int>
#define pll pair<ll, ll>
// }}}

#define debug 0

// {{{ TEMPLATE
// -----------------------------------------------------
// {{{ SVECTOR
// vector alokujacy dokladnie tyle pamieci ile potrzebuje
// UWAGA nie wola destruktorów
template <class T> class svector {
  T *tab;
  size_t sz;

public:
  svector() {
    tab = nullptr;
    sz = 0;
  }
  svector(size_t s) {
    sz = s;
    tab = calloc(s, sizeof(T));
  }
  ~svector() { free(tab); }
  size_t size() const { return sz; }
  void push_back(T x) {
    tab = (T *)realloc(tab, (sz + 1) * sizeof(T));
    tab[sz] = x;
    sz++;
  }
  void resize(size_t nsize) {
    tab = (T *)realloc(tab, nsize * sizeof(T));
    sz = nsize;
  }
  T &operator[](size_t i) { return tab[i]; }
};
// }}}
// {{{ BINARY_HEAP
// kopiec minimowy z operacją decrease_priority w log(n)
// używa 2*więcej pamięci niż zwykły kopiec
// unordered_map loc mozna zmienić na tablice gdy T to int
template <class key, class T, class Compare = less<T>> class binary_heap {
  vector<T> V;
  unordered_map<key, size_t> loc;
  /* boost::unordered_map<key, size_t> loc; */
  Compare comp;

public:
  binary_heap() { V = vector<T>(1); }
  ~binary_heap() = default;
  bool empty() const { return V.size() == 1; }
  T top() const {
    if (empty())
      throw runtime_error("no top in empty");
    return V[1];
  }
  void insert(const T &x) {
    V.pb(x);
    size_t i = V.size() - 1;
    loc[x.key()] = i;
    while (i != 1 and comp(V[i], V[i / 2])) {
      loc[V[i].key()] = i / 2;
      loc[V[i / 2].key()] = i;
      swap(V[i], V[i / 2]);
      i = i / 2;
    }
  }
  void pop() {
    if (empty()) {
      throw runtime_error("trying to pop empty");
    }
    loc.erase(V[1].key());
    loc[V[V.size() - 1].key()] = 1;
    swap(V[1], V[V.size() - 1]);
    V.pop_back();
    size_t i = 1;
    while (true) {
      size_t s = i;
      size_t l = 2 * i;
      size_t r = 2 * i + 1;
      if (l < V.size() and comp(V[l], V[s])) {
        s = l;
      }
      if (r < V.size() and comp(V[r], V[s])) {
        s = r;
      }
      if (s != i) {
        loc[V[i].key()] = s;
        loc[V[s].key()] = i;
        swap(V[i], V[s]);
        i = s;
      } else {
        break;
      }
    }
  }
  void decrease_priority(const T &x) {
    if (!loc.contains(x.key())) {
      insert(x);
      return;
    }
    V[loc[x.key()]] = x;
    size_t i = loc[x.key()];
    while (i != 1 and comp(V[i], V[i / 2])) {
      loc[V[i].key()] = i / 2;
      loc[V[i / 2].key()] = i;
      swap(V[i], V[i / 2]);
      i = i / 2;
    }
  }
};
// }}}
// {{{ LL RANGE
// by default step = 1 is used
// if u want to have reverse range then step should be negative
template <ll from, ll to, ll step = 1> class Range {
public:
  class iterator : public std::iterator<random_access_iterator_tag, ll, ll> {
    ll n = from;

  public:
    explicit iterator(ll a) : n(a) {}
    iterator &operator++() {
      n += step;
      return *this;
    }
    iterator operator++(int) {
      iterator other = *this;
      ++(*this);
      return other;
    }
    iterator &operator--() {
      n -= step;
      return *this;
    }
    iterator operator--(int) {
      iterator other = *this;
      --(*this);
      return other;
    }
    bool operator==(iterator other) const { return n == other.n; }
    bool operator!=(iterator other) const { return !(*this == other); }
    ll operator*() { return n; }
    iterator operator+(ll a) const {
      iterator other = *(this);
      other.n += step * a;
    }
    iterator &operator+=(ll a) {
      n += step * a;
      return *(this);
    }
    iterator operator-(ll a) {
      iterator other = *(this);
      other.n -= a;
      return other;
    }
    iterator &operator-=(ll a) {
      n -= step * a;
      return *(this);
    }
    ll operator-(iterator other) { return n - other.n; }
    ll operator[](ll i) { return n + i; }
    bool operator<=(iterator other) { return n <= other.n; }
    bool operator>=(iterator other) { return n >= other.n; }
    bool operator<(iterator other) { return n < other.n; }
    bool operator>(iterator other) { return n > other.n; }
  };
  iterator begin() { return iterator(from); }
  iterator end() { return iterator(from <= to ? to + 1 : to - 1); }
};
//
// }}} LL_RANGE_END
// ordered_set
template <class T, class ORD = less<T>>
using ordered_set =
    tree<T, null_type, ORD, rb_tree_tag, tree_order_statistics_node_update>;
// TEMPLATE_END
// ----------------------------------------------
// }}}

int main() {
  turbo;
  return 0;
}
