
with open("input.txt") as inputfile:
    list1, list2 =[],[]
    for line in inputfile:
        list1.append(int(line.split()[0]))
        list2.append(int(line.split()[1]))

list1.sort()
list2.sort()

result = 0
for i in range(len(list1)):
    result += abs(list1[i]-list2[i])
print(result)


#pt 2

similarity_score =0

for i in list1:
    similarity_score += list2.count(i) * i

print(similarity_score)
