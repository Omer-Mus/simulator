import numpy as np
import matplotlib.pyplot as plt
# from mpl_toolkits.mplot3d import Axes3D
# import pandas as pd
# import sys

mass1 = '/Users/omeromer/CLionProjects/simulation/cmake-build-debug/mass1.csv'
mass2 = '/Users/omeromer/CLionProjects/simulation/cmake-build-debug/mass2.csv'

my_data = np.genfromtxt(mass1, delimiter=",", dtype=float)
my_data2 = np.genfromtxt(mass2, delimiter=",", dtype=float)

# fig = plt.figure()
# ax = fig.add_subplot(111, projection='3d')
# ax.plot(x,y,z)

plt.plot(my_data, color = 'r')
plt.plot(my_data2, color = 'g')
plt.show()
