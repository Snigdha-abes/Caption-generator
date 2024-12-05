str1=input()
str2=input()
index=0
c1=0
c2=0
c3=0
c4=0
for c in str1:
    if c.isdigit():
        if index%2==0:
            c1+=int(c)
        else:
            c2+=int(c)
            
    index+=1
for c in str2:
    if c.isdigit():
        if index%2==0:
            c3+=int(c)
        else:
            c4+=int(c)
            
    index+=1
print(c1*c2+c3+c4)





x=int(input())
N=int(input())
l=[]
l2=[]
l3=[]
arr=list(map(int,input().split()))
for i in range(x):
    l.append(arr[i])
l.sort(reverse=True)
for i in range(x,N):
    l2.append(arr[i])
l2.sort(reverse=True)
l3=l+l2
print(l3)