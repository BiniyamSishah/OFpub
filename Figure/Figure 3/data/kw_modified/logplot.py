import numpy as np
import matplotlib.pyplot as plt
from scipy import interpolate

#Load openfoam data
ke1 = np.loadtxt("postProcessing/sampleDict/19.44/sampleU_U_wallShearStress.xy",skiprows=0)
ke2 = np.loadtxt("postProcessing/sampleDict/19.44/sampleWSS_U_wallShearStress.xy",skiprows=0)


#Compute therorical profiles
x=np.linspace(0.1,100000,1000000)
yp=x

#Laminar
up=yp
#Low-law
up1=(1.0/0.41)*np.log(yp)+5.0

#Where to sample
xloc=0.005   

#Input values
U = 2
nu = 1.14e-06
rho = 1

#interpolate data
fint5=interpolate.interp1d(ke2[:,0],ke2[:,4],kind='linear')

#find value at a given point
#fint(xloc)

#Compute wall shear stress magnitude and velocity magnitude
#Shear stress units is in pascal must multiply by density in incompressible flows

#kepsilon
ws5 = np.sqrt(ke2[:,4]**2)
um5 = np.sqrt(ke1[:,1]**2)

#wsm
wsm5=np.abs(fint5(xloc))

utau5=np.sqrt(wsm5/rho)
ypn5=utau5*ke1[:,0]/nu
upn5=um5/utau5

#Plot profiles

plt.figure(figsize=(14, 8))

#Correlations
plt.plot(yp,up,label='Viscous sublayer')
plt.plot(yp,up1,label='log-law')

#OpenFOAM
plt.plot(ypn5[1:],upn5[1:],'-o',ms=3,c='brown',label='$ Model$')

plt.xscale('log')
plt.xlim(0.1,100000)
plt.ylim(0,100)
plt.xlabel ('$y^+$')
plt.ylabel ('$U^+$')
plt.grid()
plt.legend(loc=2)

plt.savefig("fig.png")
