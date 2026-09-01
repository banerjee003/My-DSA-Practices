#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    struct State {
        int row;
        int col;
        int e;
        int step;
        int mask;
    };

    int minMoves(vector<string>& classroom, int energy) {

        int n = classroom.size();
        int m = classroom[0].size();

        int startRow = -1, startCol = -1;
        int litterCount = 0;

        vector<vector<int>> litterIndex(
            n,
            vector<int>(m, -1)
        );

        // Find start and assign an index to every litter
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (classroom[i][j] == 'S') {
                    startRow = i;
                    startCol = j;
                }

                if (classroom[i][j] == 'L') {
                    litterIndex[i][j] = litterCount++;
                }
            }
        }

        // No litter
        if (litterCount == 0) {
            return 0;
        }

        int totalMasks = 1 << litterCount;
        int targetMask = totalMasks - 1;

        /*
            bestEnergy[row][col][mask]

            Maximum energy remaining when reaching
            (row, col) with this collected mask.
        */
        vector<vector<vector<int>>> bestEnergy(
            n,
            vector<vector<int>>(
                m,
                vector<int>(totalMasks, -1)
            )
        );

        queue<State> q;

        q.push({
            startRow,
            startCol,
            energy,
            0,
            0
        });

        bestEnergy[startRow][startCol][0] = energy;

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, -1, 0, 1};

        while (!q.empty()) {

            State curr = q.front();
            q.pop();

            if (curr.mask == targetMask) {
                return curr.step;
            }

            // Cannot make any more moves
            if (curr.e == 0) {
                continue;
            }

            for (int i = 0; i < 4; i++) {

                int nr = curr.row + dr[i];
                int nc = curr.col + dc[i];

                // Boundary check
                if (nr < 0 || nr >= n ||
                    nc < 0 || nc >= m) {
                    continue;
                }

                // Obstacle
                if (classroom[nr][nc] == 'X') {
                    continue;
                }

                int newEnergy = curr.e - 1;
                int newMask = curr.mask;

                // Collect litter
                if (classroom[nr][nc] == 'L') {

                    int index = litterIndex[nr][nc];

                    newMask |= (1 << index);
                }

                // Reset energy
                if (classroom[nr][nc] == 'R') {
                    newEnergy = energy;
                }

                /*
                    If we have already reached this
                    position + mask with equal or
                    more energy, skip it.
                */
                if (bestEnergy[nr][nc][newMask] >= newEnergy) {
                    continue;
                }

                bestEnergy[nr][nc][newMask] = newEnergy;

                q.push({
                    nr,
                    nc,
                    newEnergy,
                    curr.step + 1,
                    newMask
                });
            }
        }

        return -1;
    }
};