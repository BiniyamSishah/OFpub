%%
close all;
clear all;


load Alldata;

figure 
for i=1:8
    
    Aks(i)=Alldata(i).A/Alldata(i).ks;
    fww(i)= Alldata(i).fw;
    fww1(i)= Alldata(i).fww;
    hold on 
end 
hold on
p = plot(Aks, fww,'ro','LineWidth',2);
p.MarkerFaceColor = [0 0 0];
p.MarkerSize = 8;


q = plot(Aks, fww1,'bo','LineWidth',2);
q.MarkerFaceColor = [0 1 0];
q.MarkerSize = 8;

xlabel('${a/k_s}$','Interpreter','latex','rot',0);
ylabel('$ f_w $','Interpreter','latex','rot',90);

set(gca,"DefaultAxesFontName",'Arial');
set(gca,"DefaultTextFontName",'Arial');
ax=gca;
ax.FontSize = 20;

legend(' feature resolved sim.','parametrization','Interpreter','latex');

print('fig6a','-dpng','-r600')

%% Van Rijn et al.(1993) ks=1-3*h

figure
for i=1:8
    
    Allh(i)=Alldata(i).h;
    Alks(i)= Alldata(i).ks;     
    
    hold on 
end 

p = plot(Allh, Alks,'bo','LineWidth',2);

p.MarkerFaceColor = [0 1 0];
p.MarkerSize = 8;

xlabel('$ h$ [m]','Interpreter','latex','rot',0);
ylabel('$ {k_s} $ [m]','Interpreter','latex','rot',90);

set(gca,"DefaultAxesFontName",'Arial');
set(gca,"DefaultTextFontName",'Arial');
ax=gca;
ax.FontSize = 20;

print('fig6b','-dpng','-r600')
