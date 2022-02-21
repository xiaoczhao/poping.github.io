import numpy as np
import matplotlib.pyplot as plt
plt.style.use('ggplot')
x = np.random.randn(100).cumsum()#cumsum是对其进行求和
y = np.linspace(0,20,100)#在0到20之间找100个数
fig,ax = plt.subplots()
ax.fill_between(x,y,color = 'lightblue')#将画出的图像进行填充
plt.show()
