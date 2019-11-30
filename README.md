# Ramsey Number Analyzer

A program to analyze and check a specific colorize in Ramsey Number **R(5, 5)**.

## Features

- Analyze randomly colors
- Run for a specific colorize

Less results are better colors.

> If we found a colorize with 0 result, So R(5,5) is 43.

## Ramsey Test 1

Production of 5,000 random colors:

| Name  | Value |
| ----- | ---- | 
| Min |	50687 |
| Repeat min |	1 |
| Max |	87573 |
| Repeat max | 	1 |
| Sum | 	300527812 |
| Average |	60105.5624 |
| Repeat average |	1 |
| Median | 	59623 |
| Repeat > average |	2250 |
| Mode |	56788 |
| Repeat < average	| 2748 |

#### [View colors results](1/graph-rank-result.txt)
#### [View all colors of edges](1/graph-result.txt)

## Ramsey Test 2

Production of 10,054 random colors:

| Name  | Value |
| ----- | ---- | 
| Min |	50687 |
| Repeat min |	1 |
| Max |	88164 |
| Repeat max | 	1 |
| Sum | 	604532396 |
| Average |	6042.061247 |
| Repeat average |	1 |
| Median | 	63869 |
| Repeat > average |	4579 |
| Mode |	58255 |
| Repeat < average	| 5473 |

#### [View colors results](2/graph-rank-result.txt)
#### [View all colors of edges](2/graph-result.txt)


# Ramsey Number R(5,5)

The goal is to focus on solving a problem that hasn't been answered for more than 20 years.
At least we should be able to improve it or come near of result.

# The Ramsey numbers R(s,t)

The Ramsey number R(s, t) is defined to be the smallest n such that every graph of order n contains either a clique of s vertices or an independent set of t vertices. Understanding the values of R(s,t) is among the most important, fruitful, and frustrating questions in combinatorics.

# R(5,5)

# 43 ≤ R(5,5) ≤ 48

Vigleik Angeltveit and  Brendan D. McKay proved that the value of the diagonal Ramsey number R(5,5) is at most 48. [Here is the paper.](https://arxiv.org/abs/1703.08768)

The proof of  is via computer verification, checking approximately two trillion separate cases! Congratulations Brendan and Vigleik! (I heard about it from Greg Kuperberg.)

The best known lower bound of 42 was established  by Exoo in 1989.  The previous best upper bound of 49 was proved by Brendan McKay and Stanislaw P. Radziszowski.

By this 4-days old theorem we now have 43 ≤ R(5, 5) ≤ 48. Brendan and Vigleik write “The actual value of R(5, 5) is widely believed to be 43, because a lot of computer resources have been expended in an unsuccessful attempt to construct a Ramsey (5,5)-graph of order 43.” 

# R(4,5) = 25

In 1995 Brendan McKay and Stanislaw Radziszowski famously proved that R(4, 5) = 25. Listing all graphs with 24 vertices which admit a coloring without a clique on 5 vertices or an independent set with 4 vertices is a major part of the current proof.

Here is, more or less,  how Greg described the achievement on FB: How many people can you have at a party such that no 5 are all acquainted and no 5 are all strangers? It has been known for nearly 30 years that 42 people is possible, and known for 20 years that 49 is not possible. The momentous news  is that 48 is also not possible.

Greg continuation was a little cryptic to me: According to the paper, most mathematicians with any opinion on the matter agree with Douglas Adams that 42 is the answer. (By convention, the question is phrased in terms of the first impossible value, which is now known to be at least 43 and at most 48, and conjectured to be the former.) In response to my confusion Barry Simon added a ring theoretic aspect:  Gil Kalai Isn’t the answer to “the ring of what” always: “one ring to rule them all” sort of like what “42” always means. 

---------

# Max Base

My nickname is Max, Programming language developer, Full-stack programmer. I love computer scientists, researchers, and compilers.

## Asrez Team

A team includes some programmer, developer, designer, researcher(s) especially Max Base.

[Asrez Team](https://www.asrez.com/)
