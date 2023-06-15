// Find Subarray at every point , to take at least K element you have to find k size window sum
// and at previous max sum at that point ;


#define ll long long 

long long int maxSumWithK(long long int a[], long long int n, long long int k) 
{
    
    ll Max_Sum_AtThatPoint[n]; // to store max sum at that point 
    Max_Sum_AtThatPoint[0] = a[0];
 
    // We use Kadane's algorithm to fill Max_Sum_AtThatPoint[]
    ll curr_max = a[0];
    for (ll i = 1; i < n; i++)
    {
        curr_max = max(a[i], curr_max+a[i]);
        Max_Sum_AtThatPoint[i] = curr_max;
    }
 
    // here using Sliding window Concept 
    // Sum of first k elements
    ll sum = 0;
    for (ll i = 0; i < k; i++)
        sum += a[i];
 
    // Use the concept of sliding window
    ll result = sum;
    for (ll i = k; i < n; i++)
    {
        // Compute sum of k elements ending
        // with a[i].
        sum = sum + a[i] - a[i-k];
 
        // Update result if required
        result = max(result, sum);
 
        // Include maximum sum till [i-k] also
        // if it increases overall max.
        result = max(result, sum + Max_Sum_AtThatPoint[i-k]);
    }
    return result;
}