solve(i , left , right)
{
    int left = nums[left] * i + solve(i + 1 , left + 1 , right):
    int right = nums[right] * i + solve(i + 1 , left  , right - 1):

    return max(left , right) ;
}

// https://www.codingninjas.com/codestudio/library/wine-selling