def run():
    dp[L, R, len] = dp[L, R-1, len] + dp[l+1, r, len] - dp[l+1,r-1,len]