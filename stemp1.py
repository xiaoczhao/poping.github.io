import csv
#创建输入输出文件对象
with open('OriginalData.csv','r',newline='')as csv_in_file:
    with open('temp1_1.csv','w',newline='')as csv_out_file:
        filereader = csv.reader(csv_in_file)
        filewriter = csv.writer(csv_out_file)
#运用for循环遍历满足条件的数据，并将它们写入输出文件      
        for row in filereader:
            if len(row) == 6 and int(row[2]) !=0 :
                filewriter.writerow(row)
