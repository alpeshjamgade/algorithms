#include <bits/stdc++.h>
using namespace std;

    // 1. Naive Pattern Searching  O(n*(n-m+1));
    // 2. KMP Algorithm O(n);          
    // 3. Rabin-Karp Algorithm
    // 4. Z algorithm (Linear time pattern searching Algorithm)
    // 5. Finite Automata
    // 6. Efficient Construction of Finite Automata
    // 7. Boyer Moore Algorithm – Bad Character Heuristic
    // 8. Suffix Array
    // 9. Anagram Substring Search (Or Search for all permutations)
    // 10. Pattern Searching using a Trie of all Suffixes
    // 11. Aho-Corasick Algorithm for Pattern Searching
    //* kasai’s Algorithm for Construction of LCP array from Suffix Array
    



// The following functions returns the index at which the pattern is found.
// If the pattern isnt present in the text then the functions returns -1;



// 1. Naive

vector<int> greedy(string text, string pat)
{
    int l1 = text.length();
    int l2 = pat.length();

    vector<int> res; 

    for(int i=0; i < l1-l2+1; i++){
        int j;
        for(j =0; j < l2; j++){
            if(text[i+j] != pat[j]){
                break;
            }
        }
        if(j == l2){
            res.emplace_back(i);
        }
    }

    return res;
}

int main()
{
    string text = "alpesh";
    string pat  = "es";

    auto res = greedy(text, pat);
    for(auto i: res){
        cout << i << ' ';
    }
    return 0;
}









