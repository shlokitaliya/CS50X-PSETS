import cs50

while(True):
    input = cs50.get_float("enter your money value here: ")
    if(input >= 0):
        break


answer = 0
input *=100

if(input >= 25):
    answer += input / 25
    input %= 25

print(input)
if(input >= 10):
    answer += input / 10
    input = input % 10

print(int(answer))
print(input)
if(input >= 5):
    answer += input / 5
    input %= 5
print(input)
print(int(answer))
if(input >= 1):
    answer += input / 1
    input %= 1

print(int(answer))
