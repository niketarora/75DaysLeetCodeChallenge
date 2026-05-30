#include <vector>
#include <queue>

class Solution {
public:
    std::vector<std::vector<int>> pacificAtlantic(std::vector<std::vector<int>>& heights) {
        if (heights.empty() || heights[0].empty()) return {};

        int m = heights.size();
        int n = heights[0].size();

        std::vector<std::vector<bool>> pacific(m, std::vector<bool>(n, false));
        std::vector<std::vector<bool>> atlantic(m, std::vector<bool>(n, false));

        std::queue<std::pair<int, int>> pacQueue;
        std::queue<std::pair<int, int>> atlQueue;

        // Initialize queues with the ocean borders
        for (int i = 0; i < m; ++i) {
            pacQueue.push({i, 0});
            atlQueue.push({i, n - 1});
            pacific[i][0] = true;
            atlantic[i][n - 1] = true;
        }
        for (int j = 0; j < n; ++j) {
            pacQueue.push({0, j});
            atlQueue.push({m - 1, j});
            pacific[0][j] = true;
            atlantic[m - 1][j] = true;
        }

        // Directions for traversal: Up, Down, Left, Right
        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        auto bfs = [&](std::queue<std::pair<int, int>>& q, std::vector<std::vector<bool>>& ocean) {
            while (!q.empty()) {
                auto [r, c] = q.front();
                q.pop();

                for (auto& dir : dirs) {
                    int nr = r + dir[0];
                    int nc = c + dir[1];

                    // Check boundaries, if visited, and if water can flow from new cell to current
                    if (nr >= 0 && nr < m && nc >= 0 && nc < n && !ocean[nr][nc] && heights[nr][nc] >= heights[r][c]) {
                        ocean[nr][nc] = true;
                        q.push({nr, nc});
                    }
                }
            }
        };

        // Run BFS for both oceans
        bfs(pacQueue, pacific);
        bfs(atlQueue, atlantic);

        // Collect all cells that can reach both oceans
        std::vector<std::vector<int>> result;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (pacific[i][j] && atlantic[i][j]) {
                    result.push_back({i, j});
                }
            }
        }

        return result;
    }
};
