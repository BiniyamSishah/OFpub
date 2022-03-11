# import python pakages 
import pandas as pd 
from matplotlib import pyplot as plt
import numpy as np

# file locations
filename = ('postProcessing/wallShearStress/0/wallShearStress.dat')
tt = 'Ap2dp2T7.txt'

# import data
data =np.loadtxt(tt)
my_cols = [str(i) for i in range(13)] 
df = pd.read_csv(filename,sep='[\s()]',skiprows= 2,names=my_cols,header=None,engine="python")


# Variables for computation

Uo = 0.180
T = 7 
pi = np.pi
a = 2*pi/T
nu =  0.0000014
de = np.sqrt (nu*T/pi)
df ['13'] = df ['0'] * a
df ['14'] = df ['3'] /(Uo*de*a)
Area = 0.00134295
bcd = ((-data[:,1])/(Uo*de*a))/Area

# plot results

plt.rcParams['figure.figsize'] = (8,7)
plt.rcParams.update({'font.size':12})

df.plot(kind='line', x = '13' ,y='14',label= '$1D$')
plt.plot ((data[:,0])*a - 4*pi,bcd, label= '$2D$')

#plt.xticks([0, pi/2, pi, 3*pi/2, 2*pi],
#          ['$0$','$\dfrac{\pi}{2}$', '$\pi$','$\dfrac{3 \pi}{2}$', '$2\pi$'])
plt.title("time development of X - Shear stress")
#plt.xlabel("$\Phi$")         
# plt.ylabel('$\dfrac{\sigma_x}{U_0 \delta \omega}$')
plt.axhline(0, color= 'black', lw=1)
plt.ylim(-1.5*max(bcd), 1.5*max(bcd))
plt.xlim(0,2*pi)
plt.legend (loc='best',fontsize=10)
plt.grid()
plt.savefig("output.png")

# compute and print the wave friction factor for calibration
max_tau = max (df ['3'][200:700])
fw = (2 * max_tau)/ Uo**2
print (fw)

