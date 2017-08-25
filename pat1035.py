'''
    思路：可以直接调用string的translate解题
    注意：密码没改变时N=1和N>1输出语句不同
'''

N = int(input())
accounts = []
for x in range(N):
    ID,password = input().split()
    account = {}
    account['ID'] = ID
    account['password'] = password
    accounts.append(account)
origin_string = '10lO'
new_string = '@%Lo'
modified_cnt = 0
modified_account = []
for account in accounts:
    str_trans = str.maketrans(origin_string,new_string)
    new_password = account['password'].translate(str_trans)
    if new_password != account['password']:
        modified_cnt += 1
        account['password'] = new_password
        modified_account.append(account['ID'])

if modified_cnt == 0:
    if(N == 1):
        print('There is ' + str(N) + ' account and no account is modified')
    else:
        print('There are ' + str(N) + ' accounts and no account is modified')
else:
    print(modified_cnt)
    for account in accounts:
        if account['ID'] in modified_account:
            print(account['ID'] + ' ' + account['password'])
