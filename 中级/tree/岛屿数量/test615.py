import string
'''
class Solution:
    def __init__(self):
        self.island_lst = []
    def locate_pos(self, pos, grid):
        i = pos[0]
        j = pos[1]
        wall_dict = {(i - 1, j): grid[i - 1][j], (i, j - 1): grid[i][j - 1], (i, j + 1): grid[i][j + 1],
                     (i + 1, j): grid[i + 1][j]}
        wall_lst = []
        for k, v in wall_dict.items():
            if (v == '1'):
                wall_lst.append(k)
                pass
            pass
        combind_lst = []
        neighbor_lst = []
        for lst in self.island_lst:
            if len(list(set(wall_lst).intersection(set(lst)))) == 0:
                continue
            else:
                neighbor_lst.append(lst)
            pass
        #去重和合并

        for obj in neighbor_lst:
            self.island_lst.remove(obj)
            combind_lst = combind_lst + obj
            pass
        return combind_lst

    def numIslands(self, grid):
        if len(grid) == 0:
            return 0
        self.island_lst = []
        i = 0
        j = 0

        row_len = 0

        # 额外在数组外添加0， 方便处理
        for row in grid:
            row.append("0")
            row.insert(0, "0")
            row_len = len(row)
            pass
        new_row = ['0' for x in range(0, row_len)]
        grid.insert(0, new_row)
        grid.append(new_row)

        for row in grid:
            j = 0
            for col in row:
                if int(grid[i][j]) == 1:
                    # 如果当前点的上下左右都是0， 则是一个新的孤立岛屿, 在island_lst中新添加岛屿
                    tmp_lst = []
                    tmp_lst = self.locate_pos((i, j), grid)
                    if len(tmp_lst) != 0:  # 如果不全为0，则在island_lst中搜索，看处于哪个岛屿，找到后，放入这个岛屿对应的list中
                        tmp_lst.append((i, j))
                        self.island_lst.append(tmp_lst)
                        pass
                    else:  # 如果找不到对应岛屿，则在island_lst中新创建岛屿
                        self.island_lst.append([(i, j)])
                        pass
                    pass
                j += 1
                pass
            i += 1
            pass
        return len(self.island_lst)
        pass
'''

class Solution:
    def __init__(self):
        self.visited = []
        pass
    def island_dfs(self, pos, grid):
        i = pos[0]
        j = pos[1]
        grid[i][j] = True
        if (grid[i][j-1]=='1' and self.visited[i][j-1] == False):
            self.island_dfs((i,j-1), grid)
            pass
        if (grid[i][j+1]=='1' and self.visited[i][j+1] == False):
            self.island_dfs((i,j+1), grid)
            pass
        if (grid[i-1][j]=='1' and self.visited[i-1][j] == False):
            self.island_dfs((i-1,j), grid)
            pass
        if (grid[i+1][j]=='1' and self.visited[i+1][j] == False):
            self.island_dfs((i+1,j), grid)
            pass
        pass
    def numIslands(self, grid):
        if len(grid) == 0:
            return 0
        i = 0
        j = 0
        count = 0
        row_len = 0
        # 额外在数组外添加0， 方便处理
        for row in grid:
            row.append("0")
            row.insert(0, "0")
            row_len = len(row)
            pass
        new_row = ['0' for x in range(0, row_len)]
        grid.insert(0, new_row)
        grid.append(new_row)
        self.visited = [[False for x in range(0, row_len)] for y in range(0, len(grid))]

        for row in grid:
            j = 0
            for col in row:
                if (grid[i][j] == '1' and self.visited[i][j] == False):
                    #开始进行遍历
                    self.island_dfs((i,j), grid)
                    count += 1
                    pass
                j += 1
                pass
            i += 1
            pass

        return count
        pass

if __name__ == "__main__":
    #grid = [[1]]
    #grid = [['1','1','1','1','0'],['1','1','0','1','0'],['1','1','0','0','0'],['0','0','0','0','0']]
    grid = [['1','1','0','0','0'], ['1','1','0','0','0'], ['0','0','1','0','0'], ['0', '0', '0', '1', '1']]
    #grid = [["1","1","1"],["0","1","0"],["1","1","1"]]

    solution = Solution()
    print(solution.numIslands(grid))