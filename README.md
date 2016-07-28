# GridLocalMin
Find a local minimum in a n by n grid

Theory problem from [Coursera's course: Algorithms: Design and analysis, Part 1](https://www.coursera.org/learn/algorithm-design-analysis/home/welcome)

All codes are done from scratch except Mersenne twister (borrowed from [here](http://my.opera.com/metrallik/blog/2013/04/19/c-class-for-random-generation-with-mersenne-twister-method)).

# Proof of correctness

The global minimum of our n by n grid G is always a local minimum.

For the global minimum m of G', defined as any sub-grid of G, to be a local minimum of G, it suffice that any node of G sharing a connection with G' be grater than m.

Let's now take 2 lines n[i] and n[i+1] of G and find the minimum l of those 2 lines. Let's G' be the sub-grid formed by the line n[1] to n[i] of G if l is part of n[i], the sub-grid formed by the lines n[i+1] to n[n] of G otherwise. In that case, the global minimum of G' will be a local minimum of G.

Recursing on G' is already enough to get a O(n) time complexity (and number of comparisons): posing N = n², we can use the master method (a=1, b=2, d=1/2) to get an O(sqrt(N)) time complexity which become O(n) when replacing N by n².

# Alternatives

We can also take 3 groups of 2 lines at 25%, 50% and 75% of n to recurse on a forth of G.

There is nothing specific to lines over columns in this partitioning of G so we can use columns instead.

There is a pitfall if we want to alternate lines and columns.
