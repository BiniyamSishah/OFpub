# import python pakages 
import pandas as pd 
from matplotlib import pyplot as plt
import numpy as np

# file locations
filename = ('postProcessing/wallShearStress/0/wallShearStress.dat')
tt = 'Ap2dp2T7'

# import data
data =np.loadtxt(tt)
my_cols = [str(i) for i in range(13)] 
df = pd.read_csv(filename,sep='[\s()]',skiprows= 2,names=my_cols,header=None,engine="python")


# Variables for computation
Area = 0.00134295
Uo = 0.180
rho = 1000
T = 7
# choose values of t plots and f_w are computed with 
t1=T      
t2=3*T
searchval = t1
searchval2 = t2
time = df ['0']
ii=int(np.where(time   == searchval)[0])
iii=int(np.where(time  == searchval2)[0])

pi = np.pi
a = 2*pi/T
nu =  0.0000014
de = np.sqrt (nu*T/pi)
df ['13'] = df ['0'] * a
df ['14'] = 2* df ['3'] /(Uo*Uo)
bcd = (2*(-data[:,1])/(Uo*Uo*rho*Area))

# plot results

# plot results

plt.rcParams['figure.figsize'] = (8,7)
plt.rcParams.update({'font.size':12})
plt.plot(df ['13'] - 2*pi, df ['14'],label='Form drag parametrization')
plt.plot ((data[:,0])*a - 4*pi,bcd, 'o',ms=4,c='black',label='Sishah and Vittori,$(2021)$',markevery=5)
plt.xticks([0, pi/2, pi, 3*pi/2, 2*pi],
          ['$0$','$\dfrac{\pi}{2}$', '$\pi$','$\dfrac{3 \pi}{2}$', '$2\pi$'])
#plt.title("time development of X - Shear stress")
plt.xlabel("$\Phi$")         
plt.ylabel('$f_f $')
plt.axhline(0, color= 'black', lw=1)
plt.ylim(-0.25, 0.25)
plt.xlim(0,2*pi)
plt.legend (loc='best',fontsize=10)
plt.grid()
plt.savefig("output.png")

# compute and print the wave friction factor for calibration

fw = max (abs(df['14'][ii:iii]))
print (fw)

