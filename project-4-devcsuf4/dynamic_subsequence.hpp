///////////////////////////////////////////////////////////////////////////////
// dynamic_subsequence.hpp
//
// Dynamic programming algorithms for the longest substring, and longest
// subsequence, problems.
//
///////////////////////////////////////////////////////////////////////////////

#pragma once

std::string dynamic_longest_substring(const std::string& a,
                                      const std::string& b) {
    int m = a.length();
    int n = b.length();
    
    std::string A[m+1][n+1];
    std::string longest = "";
    
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (a[i-1] != b[j-1]) {
                A[i][j] = "";
            } else {
                A[i][j] = A[i-1][j-1] + a[i-1];
                if (A[i][j].length() > longest.length()) { longest = A[i][j]; }
            }
        }
    }
    
    
    
    return longest;
}

std::string dynamic_longest_subsequence(const std::string& a,
                                        const std::string& b) {

    int m = a.length();
    int n = b.length();
    
    std::string A[m+1][n+1];
    std::string longest = "";
    std::vector<std::string> cands;
    
    
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (a[i-1] == b[j-1]) {
                A[i][j] = A[i-1][j-1] + a[i-1];
                cands.push_back(A[i][j]);
            } else if (A[i-1][j].length() > A[i][j-1].length()) {
                A[i][j] = A[i-1][j];
            } else {
                A[i][j] = A[i][j-1];
            }
        }
    }
    
    for (std::string s : cands) {
        if (s.length() >= longest.length()) { longest = s; }
    }
    
    return longest;
    
}
