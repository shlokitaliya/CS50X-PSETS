from cs50 import get_int
height = 0
while height > 8 or height < 1:
    height = get_int("Height: ")

# Loop through rows and then columns
for i in range(1, height + 1):
    for j in range(1, height + 1):
        # Start printing # after correct number of spaces
        if j > (height - i):
            print("#", end="")
        else:
            print(" ", end="")
        # Print middle space and remaining #
        if j == height:
            print(" ", "#" * i, end="")
    print()



# while(True):
#     try:
#         height = int(input("enter the height: "))
#         if height > 0 and height < 9:
#             break
#     except:
#         print("invalid input")



# for i in range(height):
#     for j in range((height*2)+2):
#         if j == height or j == height+1:
#             print(" ",end="")
#         elif j < height:
#             if j<height and j>=height-1-i:
#                 print("#", end="")
#             else:
#                 print(" ",end="")
#         elif j >= height+1:
#             if j<=i+height+2:
#                 print("#", end="")
#             else:
#                 print(" ", end="")
#     print()
