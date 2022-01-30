# BadmintonReturnOptimizer
Find the best return one can give to the opponent in the game of badminton.

## How to run?
```sh
g++ main.cc optimizer/bad_optimizer.cc optimizer/distance_based_return_optimizer.cc  -std=c++11 -o ReturnOptimizer
./ReturnOptimizer <optimizer>
```
for ex: to use bad optimizer:
```sh
./ReturnOptimizer bad_optimizer
 ```

The following optimizers are available as of now:
1. bad_optimizer: returns to the opponent position 
2. distance_based_optimizer: returns to position furthest away from opponent. 

## Motivation
I am taking a course on optimization and i wanted to get hands-on. I found badminton to be one area where i can improve my game by finding out the optimal position to return so that the opponent will find it very tough to return. I learnt badminton by playing on streets where the game is optimized for continuity(infinite game) i.e we return the shuttle to where the player is, but recently i started playing games where the game is optimized for winning(finite game) i.e we return the shuttle in a place where the player will find it tough to return.    

Also, i am new to C++. My hope is to pickup good practices along the way.

## Setup
Find the position where return needs to be placed. It's highlighted in green in the image below:
![Setup](/img/return-optimizer-setup.png)


## Grid based setup

Given that the court is not big, we can divide the court into 100\*100 grid and evaluate the optimization function at each point. This way we will meet the constraint of return being in the court and come up with the grid coordinate where we maximize our objective function in O(1)~O(100\*100) time.


