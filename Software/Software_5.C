#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAXN 32  // Maximum size of the map
#define MAX_KEYS 7

typedef struct {
    int x, y, keys, steps;
} State;

typedef struct Node {
    State state;
    struct Node *next;
} Node;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void enqueue(Node **front, Node **rear, State s) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->state = s;
    node->next = NULL;
    if (*rear) (*rear)->next = node;
    else *front = node;
    *rear = node;
}

bool dequeue(Node **front, State *s) {
    if (!*front) return false;
    Node *tmp = *front;
    *s = tmp->state;
    *front = tmp->next;
    free(tmp);
    return true;
}

int minMoves(char **grid, int rows, int cols) {
    int total_keys = 0, start_x = -1, start_y = -1;
    int key_idx[256] = {0};  // Maps key char to index
    int idx = 0;

    // Scan grid to find start and artifacts
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++) {
            char c = grid[i][j];
            if (c == '@') { start_x = i; start_y = j; }
            else if (c >= 'a' && c <= 'z') {
                if (!key_idx[(int)c]) key_idx[(int)c] = ++idx;
            }
        }
    total_keys = idx;
    if (total_keys == 0) return 0; // No keys, no moves needed

    // Visited[x][y][key_mask]
    bool visited[MAXN][MAXN][1<<MAX_KEYS];
    memset(visited, 0, sizeof(visited));
    Node *front = NULL, *rear = NULL;
    State start = {start_x, start_y, 0, 0};
    enqueue(&front, &rear, start);
    visited[start_x][start_y][0] = 1;

    while (dequeue(&front, &start)) {
        for (int d = 0; d < 4; d++) {
            int nx = start.x + dx[d], ny = start.y + dy[d];
            int keys = start.keys;
            if (nx < 0 || nx >= rows || ny < 0 || ny >= cols) continue;
            char cell = grid[nx][ny];
            if (cell == '#') continue;
            // Door check
            if (cell >= 'A' && cell <= 'Z') {
                int key_bit = key_idx[(int)(cell-'A'+'a')] - 1;
                if (key_bit < 0 || !(keys & (1<<key_bit))) continue; // Key not collected
            }
            // Artifact collect
            if (cell >= 'a' && cell <= 'z') {
                int key_bit = key_idx[(int)cell] - 1;
                keys |= (1<<key_bit);
                if (keys == (1<<total_keys)-1) return start.steps+1;
            }
            if (!visited[nx][ny][keys]) {
                visited[nx][ny][keys] = 1;
                State next = {nx, ny, keys, start.steps+1};
                enqueue(&front, &rear, next);
            }
        }
    }
    return -1;
}

// Sample main usage
int main() {
    char *map1[] = {"@..a.", "###.#", "b.A.B"};
    int rows1 = 3, cols1 = 5;
    printf("%d\n", minMoves(map1, rows1, cols1)); // Output: 8

    char *map2[] = {"@Aa"};
    int rows2 = 1, cols2 = 3;
    printf("%d\n", minMoves(map2, rows2, cols2)); // Output: -1
    return 0;
}
