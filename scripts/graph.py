import numpy as np
import matplotlib.pyplot as plt

data = np.genfromtxt("out.csv", delimiter=",", names=True) ## reads in output csv file
names = data.dtype.names
n = (len(names)-1) // 2

for i in range(n):
    plt.plot(data[f"x{i}"], data[f"y{i}"], label=f"body #{i+1}")
plt.gca().set_aspect("equal") ## ensures our aspect ratio is 1:1
plt.xlabel("x")
plt.ylabel("y")
plt.title("Euler: two-body orbit")
plt.legend()
plt.savefig("trajectory.png", dpi=150)