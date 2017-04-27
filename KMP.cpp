//  C++ program for implementation of KMP pattern searching
//  algorithm
//
//  Created by Steve DengZishi on 4/25/17.
//  Copyright © 2017 Steve DengZishi. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cmath> // To use sqrt()
#include <list> // To use STL linked-list in dfs topological sort
#include <stack> // To use STL stack in topological sort
#include <queue> // To use STL queue in bfs, dijkstra's, maxflow
#include <cstring> // To use memset()
#include <cstdlib> // To use atoi(), abs(), malloc()
#include <algorithm> // To use sort(), next_permutation(), min(), max() etc.
#include <unordered_map> // To allow O(1) mapping access using key->value
#include <set> // To sort and remove duplicate when inserted
#include <unordered_set> //To remove duplicates and count size

using namespace std;

void computeLPSArray(string pat, int M, int *lps);

// Prints occurrences of txt[] in pat[]
int KMPSearch(string pat, string txt)
{
    int M = pat.size();
    int N = txt.size();
    
    // create lps[] that will hold the longest prefix suffix
    // values for pattern
    int lps[M];
    
    // Preprocess the pattern (calculate lps[] array)
    computeLPSArray(pat, M, lps);
    
    int i = 0;  // index for txt[]
    int j  = 0;  // index for pat[]
    while (i < N)
    {
        if (pat[j] == txt[i])
        {
            j++;
            i++;
        }
        
        if (j == M)
        {
            printf("Found pattern at index %d \n", i-j);
            int index = i-j;
            j = lps[j-1];
            return index;
        }
        
        // mismatch after j matches
        else if (i < N && pat[j] != txt[i])
        {
            // Do not match lps[0..lps[j-1]] characters,
            // they will match anyway
            if (j != 0)
                j = lps[j-1];
            else
                i = i+1;
        }
    }
    printf("There is no matching substring \n");
    return -1;
}

// Fills lps[] for given patttern pat[0..M-1]
void computeLPSArray(string pat, int M, int *lps)
{
    // length of the previous longest prefix suffix
    int len = 0;
    
    lps[0] = 0; // lps[0] is always 0
    
    // the loop calculates lps[i] for i = 1 to M-1
    int i = 1;
    while (i < M)
    {
        if (pat[i] == pat[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else // (pat[i] != pat[len])
        {
            // This is tricky. Consider the example.
            // AAACAAAA and i = 7. The idea is similar
            // to search step.
            if (len != 0)
            {
                len = lps[len-1];
                
                // Also, note that we do not increment
                // i here
            }
            else // if (len == 0)
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

// Driver program to test above function
int main()
{
    string txt = "ABABDABACDABABCABAABABABCABAB";
    string pat = "ABABCABAB";
    int index = KMPSearch(pat, txt);
    cout<<index<<endl;
    
    string txt2 = "No body can stop me now";
    string pat2 = "stop";
    index = KMPSearch(pat2, txt2);
    cout<<index<<endl;
    
    string txt3 = "I love basketball";
    string pat3 = "soccer";
    index = KMPSearch(pat3, txt3);
    cout<<index<<endl;
    
    return 0;
}
