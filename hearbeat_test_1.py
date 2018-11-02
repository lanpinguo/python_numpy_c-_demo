#/usr/bin/env python


import matplotlib.pyplot as plt
import numpy as np
import max30102 as my
'''
x = np.arange(0, 100, 0.2)
y = np.sin(x)
fig, ax = plt.subplots()
ax.plot(x, y,marker='x')
plt.show()
'''
x = np.arange(-10, 10, 0.1)
ret = my.test(x)
print(ret)
fig, ax = plt.subplots()
ax.plot(x, ret,marker='x')
plt.show()
#plt.ion()
#plt.plot([1.6, 2.7])