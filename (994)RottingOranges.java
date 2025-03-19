//Rotting Oranges
import java.util.LinkedList;
import java.util.Queue;

class Solution {
    public int orangesRotting(int[][] grid) {
        if (grid == null || grid.length == 0) return -1;

        int rows = grid.length, cols = grid[0].length;
        Queue<int[]> queue = new LinkedList<>();
        int freshCount = 0;

        // Step 1: Add all rotten oranges to queue & count fresh oranges
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 2) {
                    queue.add(new int[]{i, j});  // Add rotten orange position
                } else if (grid[i][j] == 1) {
                    freshCount++;  // Count fresh oranges
                }
            }
        }

        if (freshCount == 0) return 0; // No fresh oranges, return 0

        int minutes = -1; // Start at -1 because first step doesn't count as a full minute
        int[][] directions = {{-1,0}, {1,0}, {0,-1}, {0,1}}; // Up, Down, Left, Right

        // Step 2: Perform BFS
        while (!queue.isEmpty()) {
            int size = queue.size();
            minutes++; // Each BFS level represents 1 minute

            for (int i = 0; i < size; i++) {
                int[] curr = queue.poll();
                int r = curr[0], c = curr[1];

                // Try all 4 directions
                for (int[] dir : directions) {
                    int newRow = r + dir[0];
                    int newCol = c + dir[1];

                    // If it's a fresh orange, rot it and add to queue
                    if (newRow >= 0 && newCol >= 0 && newRow < rows && newCol < cols && grid[newRow][newCol] == 1) {
                        grid[newRow][newCol] = 2; // Mark as rotten
                        queue.add(new int[]{newRow, newCol});
                        freshCount--; // Reduce fresh orange count
                    }
                }
            }
        }

        return (freshCount == 0) ? minutes : -1; // If any fresh oranges remain, return -1
    }
}
