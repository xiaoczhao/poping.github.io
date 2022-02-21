import matplotlib.pyplot as plt
plt.style.use('ggplot')#这里我使用的是ggplot风格
customers = ['ABC','DEF','GHI','JKL','MNO']#横轴
customers_index = range(len(customers))
sale_amounts = [127,90,201,111,232]
fig = plt.figure()
#添加一个子图1，1，1表示创建一个一行一列的子图
ax1 = fig.add_subplot(1,1,1)
#customers_index设置条形左侧在x轴上的坐标，sale_amounts设置条形的高度，align='center'设置条形与标签中间对齐，color即为设置颜色。
ax1.bar(customers_index,sale_amounts,align='center',color='darkblue')
#设置刻度线位置在x轴底部和y轴左侧，使图形的上部和右侧不显示刻度线
ax1.xaxis.set_ticks_position('bottom')
ax1.yaxis.set_ticks_position('left')
#rotation=0表示刻度标签是水平的，fontsize = 'small'将刻度标签的字体设为小字体
plt.xticks(customers_index,customers,rotation=0,fontsize = 'small')
plt.xlabel('Custmoer Name')
plt.ylabel('Sale Amount')
plt.title('Sale Amount per Customer')
#dpi=400设置图形分辨率，bbox_inches = 'tight'表示保存图片时，将四周的空白去掉
plt.savefig('bar_plot.png',dpi=400,bbox_inches = 'tight')
plt.show()
