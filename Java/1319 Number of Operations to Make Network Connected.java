class Solution {
    public int makeConnected(int n, int[][] connections) {
        if (connections.length < n - 1) { // There aren't enough cables to connect all of the computers
            return -1;
        }
        List<List<Integer>> connected = new ArrayList<>(); // List of lists to keep track of which computers are connected to which others
        for (int i = 0; i < n; i++) {
            connected.add(new ArrayList<>()); // Initialize the top-level list to the number of computers
        }
        for (int[] conn : connections) {
            connected.get(conn[0]).add(conn[1]); // List the second computer as connected to the first
            connected.get(conn[1]).add(conn[0]); // List the first computer as connected to the second
        }
        int stranded = 0; // Counter for the number of computers that aren't connected
        boolean[] visited = new boolean[n]; // Boolean array to label each computer as visited during the depth-first search
        for (int i = 0; i < n; i++) { // Iterate through every computer
            if (!visited[i]) { // If the current computer isn't visited yet...
                stranded++; // Add it to the stranded counter...
                dfs(connected, i, visited); // And depth-first search the connected computers to find all of the connections
            }
        }
        return stranded - 1; // stranded is a misnomer because the original fully-connected network is counted as a "stranded" node, so we have to subtract 1 
    }
    private void dfs(List<List<Integer>> connected, int i, boolean[] visited) {
        visited[i] = true; // Change a computer to visited once its connections are searched
        for (int j : connected.get(i)) { // For every connected computer...
            if (!visited[j]) { // If it wasn't already visited...
                dfs(connected, j, visited); // Search again from that computer for more unvisited tails of the network
            }
        }
    }
}

// Source: https://leetcode.com/problems/number-of-operations-to-make-network-connected/ 

/*
Explanation:
Use a list of lists to collect the information about which other computers are connected to each computer. For each connection in the provided list, add the two computers referenced to the connected list of the other.
Once the connected list is filled a depth-first search can be used to find all of the sub-networks in the network that are not already connected to each other. Keep track of these in a counter because each node will need a cable moved to complete the network.
The depth-first search runs recursively by checking if a computer was already visited by a previous search. The first dive into the search will identify, and mark as visited, the entire network around the first computer. After that the logic will skip to any unconnected computers or sub-networks and search their connectins as well.
Incrementing the stranded counter keeps track of how many cables must be moved, with a caveat that the largest network is counted in this as well, so there will always be one more stranded sub-network than actual cables to move.
*/