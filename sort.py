with open('cougar_01.vts', 'r') as file:
    lines = file.readlines()

# 将字符串转换为整数并存储在列表中
numbers = [int(line.strip()) for line in lines]

# 对整数列表进行排序
numbers.sort()

# 打印排序后的结果
for num in numbers:
    print(num)