# # import numpy as np
# # import matplotlib.pyplot as plt
# # import matplotlib.animation as animation
# # from matplotlib import style
# # # from mpl_toolkits.mplot3d import Axes3D
# # # import pandas as pd
# # # import sys
# #
mass1 = '/Users/omeromer/CLionProjects/simulation/cmake-build-debug/mass1.csv'
mass2 = '/Users/omeromer/CLionProjects/simulation/cmake-build-debug/mass2.csv'
mass3 = '/Users/omeromer/CLionProjects/simulation/cmake-build-debug/mass3.csv'
mass4 = '/Users/omeromer/CLionProjects/simulation/cmake-build-debug/mass4.csv'
mass5 = '/Users/omeromer/CLionProjects/simulation/cmake-build-debug/mass5.csv'
mass6 = '/Users/omeromer/CLionProjects/simulation/cmake-build-debug/mass6.csv'
mass7 = '/Users/omeromer/CLionProjects/simulation/cmake-build-debug/mass7.csv'
mass8 = '/Users/omeromer/CLionProjects/simulation/cmake-build-debug/mass8.csv'
# #
# # # style.use('fivethirtyeight')
# # #
# # # fig = plt.figure()
# # # ax1 = fig.add_subplot(1,1,1)
# # #
# # # def animate(i):
# # #     graph_data = open('/Users/omeromer/CLionProjects/simulation/cmake-build-debug/mass1.csv','r').read()
# # #     lines = graph_data.split('\n')
# # #     xs = []
# # #     ys = []
# # #     zs = []
# # #     for line in lines:
# # #         if len(line) > 1:
# # #             x, y, z = line.split(',')
# # #             xs.append(float(x))
# # #             ys.append(float(y))
# # #             zs.append(float(z))
# # #     ax1.clear()
# # #     ax1.plot(xs, ys, zs)
# # #
# # # ani = animation.FuncAnimation(fig, animate, interval=1000)
# # # plt.show()
# #
# # my_data = np.genfromtxt(mass1, delimiter=",", dtype=float)
# # my_data2 = np.genfromtxt(mass2, delimiter=",", dtype=float)
# # # fig = plt.figure()
# # # ax = fig.add_subplot(111, projection='3d')
# # # ax.plot(x,y,z)
# # #
# #
# # # for i in range(len(my_data)):
# # #     my_data[i][0], my_data[i][1] = 0,0
# #
# # plt.plot(my_data[:140], color = 'r')
# # plt.show()
# # plt.plot(my_data2, color = 'g')
# # plt.show()
# # d = range(0,len(my_data))
# # my_data = my_data.T
# # my_data2 = my_data2.T
# # ax = plt.axes(projection ='3d')
# # ax.plot3D(my_data[2], d, d, 'red')
# # # plt.show()
# # # ax = plt.axes(projection ='3d')
# # ax.plot3D(my_data2[2], d, d, 'green')
# # plt.show()
#
#
#
#
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
import matplotlib.animation
from IPython import display

x = np.genfromtxt(mass1, delimiter=",", dtype=float)
df = pd.DataFrame(x, columns=["x","y","z"])

y = np.genfromtxt(mass2, delimiter=",", dtype=float)
df2 = pd.DataFrame(y, columns=["x","y","z"])

z = np.genfromtxt(mass3, delimiter=",", dtype=float)
df3 = pd.DataFrame(z, columns=["x","y","z"])

w = np.genfromtxt(mass4, delimiter=",", dtype=float)
df4 = pd.DataFrame(w, columns=["x","y","z"])

x2 = np.genfromtxt(mass5, delimiter=",", dtype=float)
df5 = pd.DataFrame(x2, columns=["x","y","z"])

y2 = np.genfromtxt(mass6, delimiter=",", dtype=float)
df6 = pd.DataFrame(y2, columns=["x","y","z"])

z2 = np.genfromtxt(mass7, delimiter=",", dtype=float)
df7 = pd.DataFrame(z2, columns=["x","y","z"])

w2 = np.genfromtxt(mass8, delimiter=",", dtype=float)
df8 = pd.DataFrame(w2, columns=["x","y","z"])

fig = plt.figure()
ax = fig.add_subplot(111,projection='3d')
sc = ax.scatter([],[],[], c='darkblue', alpha=0.5)

sc2 = ax.scatter([],[],[], c='green', alpha=0.5)
sc2 = ax.scatter([],[],[], c='green', alpha=0.5)
sc3 = ax.scatter([],[],[], c='green', alpha=0.5)
sc4 = ax.scatter([],[],[], c='green', alpha=0.5)
sc5 = ax.scatter([],[],[], c='green', alpha=0.5)
sc6 = ax.scatter([],[],[], c='green', alpha=0.5)
sc7 = ax.scatter([],[],[], c='green', alpha=0.5)
sc8 = ax.scatter([],[],[], c='green', alpha=0.5)

txt = fig.suptitle('')

def update(i):
    txt.set_text('num={:d}'.format(i))
    sc._offsets3d = (df.x.values[i:i+1], df.y.values[i:i+1], df.z.values[i:i+1])


def update2(i):
    sc2._offsets3d = (df2.x.values[i:i+1], df2.y.values[i:i+1], df2.z.values[i:i+1])

def update3(i):
    sc3._offsets3d = (df3.x.values[i:i+1], df3.y.values[i:i+1], df3.z.values[i:i+1])

def update4(i):
    sc4._offsets3d = (df4.x.values[i:i+1], df4.y.values[i:i+1], df4.z.values[i:i+1])

def update5(i):
    sc5._offsets3d = (df5.x.values[i:i+1], df5.y.values[i:i+1], df5.z.values[i:i+1])

def update6(i):
    sc6._offsets3d = (df6.x.values[i:i+1], df6.y.values[i:i+1], df6.z.values[i:i+1])

def update7(i):
    sc7._offsets3d = (df7.x.values[i:i+1], df7.y.values[i:i+1], df7.z.values[i:i+1])

def update8(i):
    sc8._offsets3d = (df8.x.values[i:i+1], df8.y.values[i:i+1], df8.z.values[i:i+1])

ax.set_xlabel('X')
ax.set_ylabel('Y')
ax.set_zlabel('Z')
ax.set_xlim(0,4)
ax.set_ylim(0,4)
ax.set_zlim(0,4)

ani = matplotlib.animation.FuncAnimation(fig, update, frames=len(df), interval=1)
ani2 = matplotlib.animation.FuncAnimation(fig, update2, frames=len(df), interval=1)
ani3 = matplotlib.animation.FuncAnimation(fig, update3, frames=len(df), interval=1)
ani4 = matplotlib.animation.FuncAnimation(fig, update4, frames=len(df), interval=1)
ani5 = matplotlib.animation.FuncAnimation(fig, update5, frames=len(df), interval=1)
ani6 = matplotlib.animation.FuncAnimation(fig, update6, frames=len(df), interval=1)
ani7 = matplotlib.animation.FuncAnimation(fig, update7, frames=len(df), interval=1)
ani8 = matplotlib.animation.FuncAnimation(fig, update8, frames=len(df), interval=1)

plt.tight_layout()


plt.show()




# from matplotlib import pyplot as plt
# import numpy as np
# import mpl_toolkits.mplot3d.axes3d as p3
# from matplotlib import animation
#
#
# fig = plt.figure()
# ax = p3.Axes3D(fig)
#
# m1 = np.genfromtxt(mass1, delimiter=",", dtype=float)
# m2 = np.genfromtxt(mass2, delimiter=",", dtype=float)
# m3 = np.genfromtxt(mass3, delimiter=",", dtype=float)
# m4 = np.genfromtxt(mass4, delimiter=",", dtype=float)
# m5 = np.genfromtxt(mass5, delimiter=",", dtype=float)
# m6 = np.genfromtxt(mass6, delimiter=",", dtype=float)
# m7 = np.genfromtxt(mass7, delimiter=",", dtype=float)
# m8 = np.genfromtxt(mass8, delimiter=",", dtype=float)
#
#
# x=np.array(m1[0])
# y=np.array(m2[1])
# z=np.array(m3[2])
# w=np.array(m4[2])
# u=np.array(m5[2])
# h=np.array(m6[2])
# i=np.array(m7[2])
# k=np.array(m8[2])
#
#
# ax.set_xlabel('X')
# ax.set_ylabel('Y')
# ax.set_zlabel('Z')
# ax.set_xlim(0,4)
# ax.set_ylim(0,4)
# ax.set_zlim(0,4)
#
# points, = ax.plot(x, y ,z, '*')
# txt = fig.suptitle('')
#
# def update_points(num, x, y, z, points):
#     txt.set_text('num={:d}'.format(num)) # for debug purposes
#
#     # calculate the new sets of coordinates here. The resulting arrays should have the same shape
#     # as the original x,y,z
#
#     new_x = m1[num]
#     new_y = m2[num]
#     new_z = m3[num]
#
#     # update properties
#     points.set_data(new_x, new_y, new_z)
#     points.set_3d_properties(new_z, 'z')
#
#     # return modified artists
#     return points,txt
#
# ani=animation.FuncAnimation(fig, update_points, frames=10, fargs=(x, y, z, points))
#
# plt.show()
