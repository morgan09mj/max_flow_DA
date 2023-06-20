# max_flow_DA
max_flow
## Question 1)
The traffic police has decided to install speed cameras on the roads due to the increase in the number of accidents
slow According to the high statistics of the Tehran-Mashhad route, this route has been prioritized. Police in
He intends to place hidden cameras in the middle of the roads (all roads are two-way) to
Every car that travels from Tehran to Mashhad (or by photo) must use at least one road
The camera passes.
The police decided to minimize the cost of installing cameras, the number of cameras
Minimize the need. You need the minimum number of cameras required and the roads that the cameras are on
They are placed in the report (pay attention to the number of driving lanes or the same capacity).
Roads should be sensored.
Entrance :
In the first line, the number of graph vertices is n, in the second line is the origin vertex, in the third line is the destination vertex and so on
Continue until the expression 1- is not reached, each line represents a graph edge.
Output:
In the output of the program, there are paths (edges) in which the camera should be installed, each in one line
They must be printed separately.

Example 1:
input:
5
0
4
0 2 5
0 3 3
2 3 3
2 1 3
2 4 3
3 1 5
1 4 4
2 4 3
-1
output:
1 - 4
2 - 4
