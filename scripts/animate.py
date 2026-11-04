import numpy as np
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation

data = np.genfromtxt("out.csv", delimiter=",", names=True)
n = (len(data.dtype.names) - 1) // 2

# Concatenate all x and y values to set the animation frame size
all_x = np.concatenate([data[f"x{i}"] for i in range(n)])
all_y = np.concatenate([data[f"y{i}"] for i in range(n)])

fig, ax = plt.subplots()
ax.set_aspect("equal")
ax.set_xlim(all_x.min(), all_x.max())
ax.set_ylim(all_y.min(), all_y.max())

trails, dots = [], []
for i in range(n):
    trail = ax.plot([], [], lw=1)[0]
    dot = ax.plot([], [], "o", color=trail.get_color())[0] #try "s"
    trails.append(trail)
    dots.append(dot)

TRAIL_LENGTH = 500
def update(k):
    start = max(0, k - TRAIL_LENGTH)
    for i in range(n):
        x, y = data[f"x{i}"], data[f"y{i}"]
        trails[i].set_data(x[start:k + 1], y[start:k + 1])
        dots[i].set_data([x[k]], [y[k]])

anim = FuncAnimation(fig, update, frames=range(0, len(data), 20), interval=20)
plt.show()

# Save as a gif:
''' anim.save("orbit.gif", writer="pillow", fps=30) '''