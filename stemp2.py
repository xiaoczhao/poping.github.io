import csv

move_Dict = {}
list = []
with open('temp1_1.csv','r',newline='')as csv_in_file:
        filereader = csv.reader(csv_in_file)
        for row in filereader:
            move_Dict[row[1]] = move_Dict.get(row[1],0)+1
            #这一步是为每种动作数量进行统计,row[1]代表每一行第二个元素即动作名称
        for move, move_Dict[move] in move_Dict.items():
            print('Movement: %5s\t' % move, end='')
            print('Amount: %d' % move_Dict[move])
            move_Dict[move] = move_Dict[move] // 100 * 100
            list.append(move_Dict[move])
#运用seek函数，用来移动文件读取指针到指定位置。                        
        csv_in_file.seek(0, 0)
#在输出文件的时候，使动作分别计数，每写入一次让计数器+1
        with open('temp2_2.csv', 'w', newline='') as csv_out_file:
            filewriter = csv.writer(csv_out_file)
            Walking = 0
            Jogging = 0
            Downstairs = 0
            Upstairs = 0
            Sitting = 0
            Standing = 0
            for row_list in filereader:
                if row_list[1] == 'Jogging' and Jogging < list[1]:
                    Jogging += 1
                    filewriter.writerow(row_list)
                if row_list[1] == 'Upstairs' and Upstairs < list[2]:
                    Upstairs += 1
                    filewriter.writerow(row_list)
                if row_list[1] == 'Downstairs' and Downstairs < list[3]:
                    Downstairs += 1
                    filewriter.writerow(row_list)
                if row_list[1] == 'Standing' and Standing < list[4]:
                    Standing += 1
                    filewriter.writerow(row_list)
                if row_list[1] == 'Sitting' and Sitting < list[4]:
                    Sitting += 1
                    filewriter.writerow(row_list)
                if row_list[1] == 'Walking' and Walking < list[0]:
                    Walking += 1
                    filewriter.writerow(row_list)


