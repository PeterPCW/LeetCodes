class Solution {
    public int minReorder(int n, int[][] connections) {
        List<List<Integer>> adjList = new ArrayList<>(n); // Create a list of lists to track which cities are connected
        for (int i = 0; i < n; i++) { // Initialize the list of lists to match the number of cities
            adjList.add(new ArrayList<>());
        }
        for (int[] conn : connections) {
            adjList.get(conn[0]).add(conn[1]); // Add all connections that exist to the adjcency list
            adjList.get(conn[1]).add(-conn[0]); // Negate the number to show the connection exists but in the wrong direction
        }
        Queue<Integer> queue = new LinkedList<>();
        queue.offer(0); // Add a 0 to the queue to start
        boolean[] checked = new boolean[n]; // Boolean array to track which cities were already checked
        checked[0] = true; // City zero is the destination
        int count = 0; // Counter for number of roads to change
        while (!queue.isEmpty()) {
            int curr = queue.poll(); // Get the current city from the front of the queue
            for (int neighbor : adjList.get(curr)) { // Check every neighbor...
                if (!checked[Math.abs(neighbor)]) { // That wasn't already checked...
                    checked[Math.abs(neighbor)] = true; // And mark it as checked
                    if (neighbor > 0) { // Started at city 0 so a positive neighbor is the wrong direction
                        count++; // Then increment the counter of roads to change
                    }
                    queue.offer(Math.abs(neighbor)); // Add the neighbor to continue checking
                }
            }
        }
        return count;
    }
}

// Source: https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/ 

/*
Explanation:
Populate a list of lists to show which cities are connected and in what direction.
Start a queue to move through each city and check for its neighbors and determine if the road needs the direction to be changed.
*/