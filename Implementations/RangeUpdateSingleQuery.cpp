struct RUSQ {

    int sz;
    ll *tree;

    RUSQ(int sz) {
        this->sz = sz;
        tree = new ll[sz + 1];
        memset(tree, 0, (sz + 1) * sizeof(ll));
    }

    void update(int idx, ll v) {
        for(idx++; idx <= sz; idx += (idx & -idx)) tree[idx] += v;
    }

    void updateRange(int lo, int hi) {
        update(lo, 1);
        update(hi + 1, -1);
    }

    ll query(int idx) {
        ll total = 0;
        for(idx++; idx > 0; idx -= (idx & -idx)) total += tree[idx];
        return total;
    }
};
