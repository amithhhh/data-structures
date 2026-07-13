import matplotlib
matplotlib.use('TkAgg')

import matplotlib.pyplot as plt

# Experimental data
sizes = [10000, 20000, 30000, 40000, 50000,
         60000, 70000, 80000, 90000, 100000]

times = [0.041740, 0.163034, 0.366586, 0.653979, 1.019470,
         1.472834, 2.016499, 2.648555, 3.369485, 4.143554]

theoretical = [(n ** 2) / 2500000000 for n in sizes]

plt.figure(figsize=(10, 6))

# Experimental graph
plt.plot(sizes, times, marker='o', label='Experimental Time')

# Theoretical graph
plt.plot(sizes, theoretical, linestyle='--', label='n^2 Curve')

plt.xlabel("Input Size (n)")
plt.ylabel("Time")
plt.title("Experimental vs Theoretical Time Complexity")

plt.legend()
plt.grid(True)

plt.show()