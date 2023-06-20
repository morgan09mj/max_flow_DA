### max_flow_DA
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

![q1](https://github.com/morgan09mj/max_flow_DA/assets/119484000/47d8fd3e-eb36-4817-a237-ede243170ec5)


## Question 2)
It is a concept in graph theory. This concept is related to the problem of finding the largest set of edges
In the graph, it refers so that no two edges have a common endpoint.
Consider a bipartite graph where two parts of the graph are connected by edges.
matching maximum is called the largest set of edges (in terms of number) in which
No two edges have a common endpoint.
In this question, you have the task to find the matching-maximum in the bipartite graph in
The input will be given to you, find it.
In the first line of input, you will be given two numbers, m and n. These two numbers are respectively the number of vertices of each
are one of the parts of our graph. Then, in the next n lines, receive numbers in each of the m lines
You can see that if the j-th line of the i-th line is equal to one, it shows that the vertex i from the first part to the vertex j of
The second part has a mane. In fact, you get the adjacency matrix of this bipartite graph.
In the only output line, you have to print n lines, the i-th number indicates the i-th vertex of the first section
To which vertex has it been matched? If vertex i was not in your matching-maximum,
The i-th number of your output must be negative one. Note that this question is for every possible test case
It has several answers and you only need to print one of these answers.

![q2](https://github.com/morgan09mj/max_flow_DA/assets/119484000/e0f3cf06-fc1e-4cab-b4ff-e32d78da7590)


## 
