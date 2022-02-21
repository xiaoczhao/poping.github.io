import csv
my_num = [3,4,5]
with open('temp2_2.csv', 'r', newline = '') as csv_in_file:
    with open('temp3_1.csv', 'w', newline = '') as csv_out_file:
        filereader = csv.reader(csv_in_file)
        filewriter = csv.writer(csv_out_file,delimiter = ' ')
#用列表筛选需要保存的列，用append函数将需要保存的列加入另一个空列表中。最后将列表l以文件形式写入
        for row_list in filereader:
            l = []
            for index_value in my_num:
                l.append(row_list[index_value])
            filewriter.writerow(l)
