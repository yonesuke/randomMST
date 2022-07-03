import numpy as np
import matplotlib.pyplot as plt
import mpmath

z3 = mpmath.zeta(3, 1)

ns = [100, 200, 400, 800, 1600, 3200]
fnames = [f"data/mst{n}.txt" for n in ns]

means = []
variances = []

for i in range(len(ns)):
    n = ns[i]
    mst = np.loadtxt(fnames[i])
    means.append(mst.mean())
    variances.append(mst.var())

means = np.array(means)
variances = np.array(variances)

# plot
plt.figure(figsize=[6, 8])

plt.subplot(2,1,1)
plt.xscale("log")
plt.scatter(ns, means)
plt.plot([100, 3200], [z3, z3], ls="dashed", color="gray", label="$\zeta(3)$")
plt.xlabel("n")
plt.ylabel("mean")
plt.legend()

plt.subplot(2,1,2)
plt.xscale("log")
plt.scatter(ns, ns*variances)
plt.xlabel("n")
plt.ylabel("n * variance")

plt.savefig("result.png")