import numpy as np
import matplotlib.pyplot as plt
plt.style.use('ggplot')
np.random.seed(0)
x = np.arange(5)
y = np.random.randint(-5,5,5)
fig,ax = plt.subplots()
v_bars = ax.bar(x,y,color='lightblue')#默认线条都为浅蓝色
for bar,height in zip(v_bars,y):#将条形图和y值进行遍历，将小于0图形改为黄色
    if height<0:
        bar.set(edgecolor = 'b',color ='y',linewidth=3)
plt.show()
