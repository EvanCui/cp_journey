# Profile
Difficulty|Type|Tags
-|-|-
Medium|DFS or BFS|Grid,Flags,Walk

# Problem link
[1019 Illusive Chase](https://zoj.pintia.cn/problem-sets/91827364500/problems/91827364518)

# Analysis
To find out where Tom could start, walk backwards from each possible ends - the grid position with 0.
Since in each chase trip the log only indicates an interval of steps Tom walked, there could be multiple next possible points in the path.
BFS is one of the choice to walk from the ending points to starting points. On the end of the walk, all points in the BFS queue are possible starting points. The size of the queue is the answer to this question.
## Tricks & traps
The next points in the BFS is determined by the current point and the reverse indication in the chase trip.
* The direction should be reversed as the algorithm walk backwards.
* The walk should start from 1 to the max steps of the interval, instead of starting from the min steps, because there should be obstacles in the range [1, min], in which case the path should be stopped.
* The next possible points should be within the interval.

## Pruning
In case the next point is already walked from another path and in the same chase trip, it needn't be put into the queue again. The problem only counts the possible starting points but not the possible paths.

## Time complexity
The count of all possible ending points corelates to the size of the grid: m * n.
BFS takes c rounds, where c is the count of chase trips. There won't be duplicate insertions in the queue with the pruning method above.\
Thus the final time complexity is 
```
O(m*n*c)
```