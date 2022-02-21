import csv
list1=[]
list2=[]
Temp = 0
with open('temp3_1.csv', 'r', newline = '') as csv_in_file:
    with open('temp4_1.csv', 'w', newline = '') as csv_out_file:
        filereader = csv.reader(csv_in_file)
        filewriter = csv.writer(csv_out_file)
        for row in filereader:
            list1.append(' '.join(row))
        for line in list1:
            if Temp < 20:
                list2.append(line)
                Temp += 1
 #每循环20次后，将list2列表置空，直到遍历所有的行
            if Temp == 20:
                filewriter.writerow(list2)
                list2 = []
                Temp= 0
