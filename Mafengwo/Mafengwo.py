s = input()
v = s.split('，')
n = len(v)
res = []
for i in range(1,n-1):
    cur = int(v[i][1:])
    pre = int(v[i-1][1:])
    if i == n-2:
    	lenl = len(v[i+1])
    	nxt = int(v[i+1][1:lenl-1])
    else:
    	nxt = int(v[i+1][1:])
    if (pre < cur and cur > nxt) or (pre > cur and cur < nxt):
    	res.append(i)
for i in res:
	print(i)
