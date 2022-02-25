import matplotlib.pyplot as plt
from matplotlib.lines import Line2D
import numpy as np
import os
from pylab import *
from matplotlib import ticker
from matplotlib.ticker import ScalarFormatter
sformatter=ScalarFormatter(useOffset=True,useMathText=True)
sformatter.set_scientific(True)
sformatter.set_powerlimits((-2,3))

Npanels=2


plt.figure(figsize=(5,9))
fig = plt.figure(1)

xx0=0.18
yy0=0.07
ww0=1.0-xx0-0.02
hh0=1.0-yy0-0.02

modeldir='../../output_posterior_corrected/default/'
decaydata=np.loadtxt('decay.dat',unpack=True)
nbodies=decaydata[0]
eff=decaydata[1]
time=decaydata[2]

for ipanel in range (0,2):
  ax = fig.add_axes([xx0,yy0+ipanel*hh0/Npanels,ww0,hh0/Npanels])
  if ipanel == 0:
      plt.loglog(nbodies,eff,marker='o',color='r')
      plt.ylabel("Monte Carlo Efficiency, $\langle w\\rangle/w_{\\rm max}$")
      plt.xlabel("$N_{\\rm bodies}$")
  elif ipanel == 1:
     plt.loglog(nbodies,time,marker='o',color='g')
     plt.ylabel("Computational time per million configurations (s)")
    

plt.savefig('efficiency.pdf',format='pdf')
os.system('open -a Preview efficiency.pdf')
#plt.show()

quit()
