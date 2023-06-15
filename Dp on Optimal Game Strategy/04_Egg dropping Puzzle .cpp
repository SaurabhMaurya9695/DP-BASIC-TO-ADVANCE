// questions pattern 
                                    // based on
// 1 ->  N floors 1 egg             trivaial case(linear serach)
// 2 ->  N floors 2 egg             greedy algo
// 3 ->  N floors k egg             DP
// 4 ->  N floors infinite egg      Binary search
// 5 -> infinite floors infinite eggs Binary search on ans 



// 1st variation   N floors 1 egg 
// Minimum number of attemps to find out the threshold floor
// in worst case we can drop one egg from the top floor , so that egg can be distroyed 
// here we can use linear serach , failed binary search beacause , if you find ans at some point then
// your egg distroyed , so we can say this is our ans ;
// if n == 0 , then we can find the threshold floor then ans is zero 


// if N == N floor , and 2 Eggs ;
// we have take a gap of x every time then our ans can be same or inceresed . but we want to
// minimize the ans tf (threshold frequency)  then each time we have to minimize the gap
// x + (x - 1) + (x - 2) + (x - 3) + ....... + 1 = N floors
// (x * (x + 1) / 2) = N 
// x^2 + x - 2*N = 0 ;
// ans = -1 +_ sqrt(1 * 1 - 4 * 1 * -2 ) / 2 * 1
// x = ceil(ans) ;


// N floors , K eggs
// this is a dp variation , at a time give all the possibility to throw from each floor 
// if n == 7 , and k == 3 eggs 
// then  you can throw from 1 , 2,  3,  4 , 5, 6, 7... 
// one 1st floor there are two possibilty 
// case 1 :  break  if break then go dowm on 0th floor , with k - 1 eggs 
// case 2 :  not break if not then go up with floor + 1 , with k eggs ;
