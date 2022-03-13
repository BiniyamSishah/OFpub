% log-law

clear all;
close all;

C=5;
K =0.41;
nu=0.000001; 


kw_u_tau = importdata('data/kw/postProcessing/sampleDict/19.44/sampleU_U_wallShearStress.xy');
kwSST_u_tau = importdata('data/kwSST/postProcessing/sampleDict/19.44/sampleU_U_wallShearStress.xy');
kwMod_u_tau = importdata('data/kw_modified/postProcessing/sampleDict/19.44/sampleU_U_wallShearStress.xy');
% plot

% Shear velocity 
uShear_kw=sqrt(abs(kw_u_tau(1,5)));
uShear_kwSST=sqrt(abs(kwSST_u_tau(1,5)));
uShear_kwMod=sqrt(abs(kwMod_u_tau(1,5)));

% viscos layer 
yplus =0:0.1:10000;
uplus =yplus; 
uplus_lg= (1/K)*log(yplus)+ C;

yplus_kw = kw_u_tau(:,1).*uShear_kw/nu;
yplus_kwSST = kwSST_u_tau(:,1).*uShear_kwSST/nu;
yplus_kwMod = kwMod_u_tau(:,1).*uShear_kwMod/nu;


uplus_kw = kw_u_tau(:,2)./uShear_kw;
uplus_kwSST = kwSST_u_tau(:,2)./uShear_kwSST;
uplus_kwMod = kwMod_u_tau(:,2)./uShear_kwMod;



semilogx(yplus,uplus,'-k','Linewidth',2);
hold on
semilogx(yplus,uplus_lg,'-k','Linewidth',2);

ylim ([0 30])
xlim ([0.1 10000])


ha= semilogx(yplus_kw,uplus_kw,'-bo','Linewidth',2);
hb=semilogx(yplus_kwSST,uplus_kwSST,'-ro','Linewidth',2);
hc=semilogx(yplus_kwMod,uplus_kwMod,'-mo','Linewidth',2);


xlabel('$ y^+ $','Interpreter','latex');
ylabel('$ u^+ $','Interpreter','latex');

set(gca, 'XColor','k', 'YColor','k');


hold on 
lgnd= legend ([ha hb hc],'$\kappa - \omega $','$\kappa - \omega - $ SST','$\kappa - \omega - $ Mod ' ,'Interpreter','latex','box','off');
set(lgnd,'color','none');

set(gca,"DefaultAxesFontName",'Arial');
set(gca,"DefaultTextFontName",'Arial');
ax=gca;
ax.FontSize = 20;


% print('fig3a','-dpng','-r600')

%%
% comparison of bottom shear stress

Uo=2;
T =9.42;
omega = 2*pi/T;
time = 0.01:0.01:T;

kw_wallShearStress = importdata('data/kw/postProcessing/wallShearStress/0/wallShearStress.csv');
kwSST_wallShearStress = importdata('data/kwSST/postProcessing/wallShearStress/0/wallShearStress.csv');
kwMod_wallShearStress = importdata('data/kw_modified/postProcessing/wallShearStress/0/wallShearStress.csv');
tauExp= importdata('data/Data/tauEXP1');


figure  

hold on

yyaxis left

hold on 

p= plot(tauExp(:,1)+15, (2*0.001*tauExp(:,2))./(Uo)^2,'ko','Linewidth',2);
plot(kw_wallShearStress(972:end,1).*(360/T) - 630,-(2*kw_wallShearStress(972:end,2))./(Uo)^2,'-b','Linewidth',3);
plot(kwSST_wallShearStress(972:end,1).*(360/T) -630,-(2*kwSST_wallShearStress(972:end,2))./(Uo)^2,'-r','Linewidth',3);
plot(kwMod_wallShearStress(972:end,1).*(360/T) - 630,-(2*kwMod_wallShearStress(972:end,2))./(Uo)^2,'-m','Linewidth',3);

p.MarkerFaceColor = [0 0 0];
p.MarkerSize = 8;

xlim([0 180])

set(gca, 'XColor','k', 'YColor','k');
xlabel('$\Omega$t','Interpreter','latex');
ylabel('${2{\tau}}/ ( {\rho} {{U_o}}^2)$','Interpreter','latex');

yyaxis right
plot(time.*(360/T),(Uo*sin(omega*time))./Uo,'k--','LineWidth',1); 
ylim([-1.1 1.1])
ylabel('$ u/U_o$','Interpreter','latex');
set(gca, 'XColor','k', 'YColor','g');


set(gca, 'XColor','k', 'YColor','k');
set(gca,"DefaultAxesFontName",'Arial');
set(gca,"DefaultTextFontName",'Arial');
ax=gca;
ax.FontSize = 20;
hold on 
lgnd=legend('Jensen et al. (1989)','$\kappa - \omega $','$\kappa - \omega - $ SST','$\kappa - \omega - $ Mod ' ,'Interpreter','latex','box','off');
set(lgnd,'color','none');

print('fig3b','-dpng','-r600')

%%