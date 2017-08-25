'''
    思路：分两个列表装男生和女生，然后分别排序
'''

male_student = []
female_student = []
N = int(input())

for x in range(N):
    name,gender,ID,grade = input().split()
    student = {'name':name,'gender':gender,'ID':ID,'grade':int(grade)}
    if gender == 'M':
        male_student.append(student)
    else:
        female_student.append(student)

isabsent = False
if len(female_student) == 0:
    print('Absent')
    isabsent = True
else:
    highest_female = sorted(female_student,key=lambda x:x['grade'],reverse=True)[0]   #   获取成绩最高的女生
    print(highest_female['name'] + ' ' + highest_female['ID'])

if len(male_student) == 0:
    print('Absent')
    isabsent = True
else:
    lowest_male = sorted(male_student,key=lambda x:x['grade'])[0]   #   获取成绩最低的男生
    print(lowest_male['name'] + ' ' + lowest_male['ID'])

if isabsent == True:
    print('NA')
else:
    print(highest_female['grade'] - lowest_male['grade'])