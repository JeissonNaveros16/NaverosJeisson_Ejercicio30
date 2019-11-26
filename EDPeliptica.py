import numpy as np
import matplotlib.pylab as plt
from mpl_toolkits.mplot3d import Axes3D
import matplotlib.pyplot as plt

data = np.loadtxt("EDPelip.dat");
n = data[:,0]
iter = data[:,1]
eps = data[:,2]
p_0 = data[:,3]

plt.figure(figsize=(15,8))
plt.subplot(1,3,1)
plt.plot(n, ite)
plt.scatter(n, ite)
plt.xlabel("Nx")
plt.ylabel("Iteraciones")

plt.subplot(1,3,2)
plt.plot(n, abs(p_0+0.5)/0.5)
plt.scatter(n, abs(p_0+0.5)/0.5)
plt.xlabel("Nx")
plt.ylabel("Error relativo")

plt.subplot(1,3,3)
plt.plot(n, eps)
plt.scatter(n, eps)
plt.xlabel("Nx")
plt.ylabel("Epsilon")
plt.savefig("Resultado.png")