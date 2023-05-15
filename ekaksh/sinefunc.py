import matplotlib.pyplot as plt
import pandas as pd
import numpy as np

df = np.loadtxt("randfile.txt")
print(df)
#df = pd.read_csv('randfile.txt', sep="     ")
#print(df)

plt.plot(df[:,0],df[:,1])
plt.show()