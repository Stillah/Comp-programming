ll f(ll a) {
     ll res[] = {a, 1, a+1, 0};
     return res[a%4];
}

// XOR on [a, b]
ll XOR(ll a, ll b) {
     return f(b) ^ f(max(0ll, a-1));
}
