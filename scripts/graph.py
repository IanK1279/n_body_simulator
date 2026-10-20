import numpy as np
import matplotlib.pyplot as plt

data = np.genfromtxt("out.csv", delimiter=",", names=True) ## reads in output csv file

plt.plot(data["x1"], data["y1"], label="small body")
plt.plot(data["x0"], data["y0"], label="large body")
plt.gca().set_aspect("equal") ## ensures our aspect ratio is 1:1
plt.xlabel("x")
plt.ylabel("y")
plt.title("Euler: two-body orbit")
plt.legend()
plt.savefig("trajectory.png", dpi=150)