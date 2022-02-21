import numpy as np
import matplotlib.pyplot as plt
plt.style.use('ggplot')
np.random.seed(0)#取相同的seed，使得生成的随机数相同
x = np.arange(5)
y = np.random.randint(-5,5,5)#在-5到5之间选取5个数
print(y)
fig,axes = plt.subplots(ncols = 2)
v_bars = axes[0].bar(x,y,color='r')#纵轴
h_bars = axes[1].barh(x,y,color='g')#横轴
#给图表加上横线
axes[0].axhline(0,color='grey',linewidth=2)
axes[1].axvline(0,color='grey',linewidth=2)
plt.show()
