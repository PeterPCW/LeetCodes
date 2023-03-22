class Solution {
    public int minScore(int n, int[][] roads) {
        List<List<Pair>> adj = new ArrayList<>(); // Define an ArrayList of ArrayLists which will hold pairs of connected cities and their distances for each city
        for (int i = 0; i < n+1; i++) { // Initialize an empty ArrayList of Pairs for each of the n+1 cities
            adj.add(new ArrayList<>());
        }
        for (int i = 0; i < roads.length; i++) { // Add the connected cities and their distances to the adjacency list for each of the edges in the roads array
            adj.get(roads[i][0]).add(new Pair(roads[i][1], roads[i][2]));
            adj.get(roads[i][1]).add(new Pair(roads[i][0], roads[i][2]));
        }
        Queue<Pair> queue = new LinkedList<>(); // Initialize a Queue of Pairs and a boolean array of "visited" flags for each of the nodes
        boolean visited[] = new boolean[n+1]; // Boolean array to track which cities were already visited
        queue.add(new Pair(1, Integer.MAX_VALUE)); // Add the starting node (node 1) with a very large distance to the Queue

        int result = Integer.MAX_VALUE; // Initialize the answer to the maximum integer value
        while (!queue.isEmpty()) { // Continue looping until the Queue is empty, it is refilled pseudo-recursively
            Pair p = queue.poll(); // Remove the first Pair from the Queue
            visited[p.node] = true; // Mark the node as visited
            result = Math.min(result, p.dist); // Update the answer to the minimum of the current answer and the distance of the current Pair
            for (Pair adjcity : adj.get(p.node)) { // Add all unvisited neighbors of the current Pair to the Queue
                if (!visited[adjcity.node]) {
                    queue.add(adjcity);
                }
            }
        }
        return result;
    }
}

class Pair { // Define a class Pair which holds the adjacent city and the distance to it
    int node;
    int dist;
    Pair(int node, int dist) { // Constructor for the Pair class that sets the values of "node" and "dist"
        this.node = node;
        this.dist = dist;
    }
}

// Source: https://leetcode.com/problems/minimum-score-of-a-path-between-two-cities/ 

/*
Explanation:
Use a List of Lists of objects to store each city and connect rode combo. Iterate through the roads to fill the Lists.
Create a Queue that will store cities and a boolean flag indicating if they have already been visited. Pull cities from the queue and compare their distance score with the current result.
Add all non-visited pairs of the current city to the queue so that it will continue checking until all paths have been explored.
*/