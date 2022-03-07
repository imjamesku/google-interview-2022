function shortestPath(grid: number[][], k: number): number {
  const q = [[0, 0, k, 0]];
  const visited = new Set([makeState(0, 0, k)]);
  while (q.length > 0) {
    const [i, j, rk, steps] = q.shift();
    if (i == grid.length - 1 && j == grid[0].length - 1) {
      return steps;
    }
    for (const [nextI, nextJ] of [
      [i + 1, j],
      [i - 1, j],
      [i, j + 1],
      [i, j - 1]
    ]) {
      if (
        nextI >= 0 &&
        nextI < grid.length &&
        nextJ >= 0 &&
        nextJ < grid[0].length
      ) {
        const nextK = grid[nextI][nextJ] == 0 ? rk : rk - 1;
        const nextState = makeState(nextI, nextJ, nextK);
        if (nextK >= 0 && !visited.has(nextState)) {
          visited.add(nextState);
          q.push([nextI, nextJ, nextK, steps + 1]);
        }
      }
    }
  }
  return -1;
}

function makeState(i: number, j: number, k: number): string {
  return `${i}, ${j}, ${k}`;
}
