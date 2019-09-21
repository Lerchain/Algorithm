res = 0
def dfs(pos, thre, v, sum, vis):
    global res
    if sum > thre or pos == len(v) - 1 or vis[pos] == 1:
        return
    res += 1
    dfs(pos+1, thre, v, sum+int(v[pos+1]),vis)
    vis[pos] = 1
    dfs(pos+1, thre, v, int(v[pos+1]),vis)
s = input()
v = s.split(',')
t = input()
thre = int(t)
vis = []
for i in range(len(v)):
    vis.append(0)
dfs(0,thre, v, int(v[0]),vis)
print(res)
