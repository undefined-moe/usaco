#include <algorithm>
#include <cstdio>
#include <memory.h>
#define M 300009
#define Maxm 100000
using namespace std;
struct node {
    int u, v, next;
} edge[M * 2];
struct Tree {
    int l, r, sum;
} tree[M * 4];

int t, head[M], fp[M], p[M], top[M], deep[M], fa[M], son[M], pos, x[M], num[M], Sum, Max, n, q, i, u, v, op;

void init() {
    t = pos = 0;
    memset(head, -1, sizeof(head));
    memset(son, -1, sizeof(son));
}

void add(int u, int v) {
    edge[t].u = u;
    edge[t].v = v;
    edge[t].next = head[u];
    head[u] = t++;
}

void dfs(int u, int f, int d) {
    deep[u] = d;
    fa[u] = f;
    num[u] = 1;
    for (int i = head[u]; i != -1; i = edge[i].next) {
        int v = edge[i].v;
        if (v == f) continue;
        dfs(v, u, d + 1);
        num[u] += num[v];
        if (son[u] == -1 || num[v] > num[son[u]])
            son[u] = v;
    }
}

void getpos(int u, int sp) {
    top[u] = sp;
    p[u] = ++pos;
    fp[p[u]] = u;
    if (son[u] == -1) return;
    getpos(son[u], sp);
    for (int i = head[u]; i != -1; i = edge[i].next) {
        int v = edge[i].v;
        if (v != son[u] && v != fa[u])
            getpos(v, v);
    }
}

void pushup(int i) {
    tree[i].sum = tree[i << 1].sum ^ tree[i << 1 | 1].sum;
}

void make(int l, int r, int i) {
    tree[i].l = l;
    tree[i].r = r;
    if (l == r) {
        tree[i].sum = x[fp[l]];
        return;
    }
    int mid = (l + r) >> 1;
    make(l, mid, i << 1);
    make(mid + 1, r, i << 1 | 1);
    pushup(i);
}

void updata(int p, int q, int i) {
    if (tree[i].l == tree[i].r && tree[i].l == p) {
        tree[i].sum = q;
        return;
    }
    int mid = (tree[i].l + tree[i].r) >> 1;
    if (p <= mid)
        updata(p, q, i << 1);
    else
        updata(p, q, i << 1 | 1);
    pushup(i);
}

void query_xor(int l, int r, int i) {
    if (tree[i].l == l && tree[i].r == r) {
        Sum ^= tree[i].sum;
        return;
    }
    int mid = (tree[i].l + tree[i].r) >> 1;
    if (r <= mid)
        query_xor(l, r, i << 1);
    else if (l > mid)
        query_xor(l, r, i << 1 | 1);
    else {
        query_xor(l, mid, i << 1);
        query_xor(mid + 1, r, i << 1 | 1);
    }
}

int lcp_xor(int u, int v) {
    int f1 = top[u];
    int f2 = top[v];
    int ans = 0;
    while (f1 != f2) {
        if (deep[f1] < deep[f2]) {
            swap(f1, f2);
            swap(u, v);
        }
        Sum = 0;
        query_xor(p[f1], p[u], 1);
        ans ^= Sum;
        u = fa[f1];
        f1 = top[u];
    }
    if (deep[u] > deep[v])
        swap(u, v);
    Sum = 0;
    query_xor(p[u], p[v], 1);
    ans ^= Sum;
    return ans;
}

int main() {
    scanf("%d %d", &n, &q);
    init();
    for (i = 1; i <= n; i++)
        scanf("%d", &x[i]);
    for (i = 1; i < n; i++) {
        scanf("%d %d", &u, &v);
        add(u, v);
        add(v, u);
    }
    dfs(1, 1, 1);
    getpos(1, 1);
    make(1, n, 1);
    for (int it = 1; it <= q; it++) {
        scanf("%d %d %d", &op, &u, &v);
        if (op == 2)
            printf("%d\n", lcp_xor(u, v));
        else
            updata(p[u], v, 1);
    }
    return 0;
}