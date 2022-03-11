
clear all;
close all;

% Figure 1a

ksPlus=0:0.01:1000;
cs=0.5;

delB_1=zeros(1,226);
delB_2=(1/0.41)*log(((ksPlus(226:9001)-2.25)/(87.75)) + cs*(ksPlus(226:9001)));
delB_3=(1/0.41)*log(1 + cs*(ksPlus(9001:end)));
figure 

hold on 

plot (ksPlus(1:226),delB_1,'k','Linewidth',3);
plot (ksPlus(226:9001),delB_2,'k','Linewidth',3);
plot (ksPlus(9001:end),delB_3,'k','Linewidth',3);

xlim([0 500])
ylim([0 15])
xlabel('$ {k_s}^+ $','Interpreter','latex');
ylabel('$ \Delta B $','Interpreter','latex');

set(gca,"DefaultAxesFontName",'Arial');
set(gca,"DefaultTextFontName",'Arial');
ax=gca;
ax.FontSize = 20;
print('fig1_a','-dpng','-r600')

%%

% Figure 1b

Sks_1= ((ones(1,2501).*50)./ksPlus(1:2501)).^2;

Sks_1R= Sks_1.^(-1/2);

Sks_2= ((ones(1,length(ksPlus) - 2500)).*100)./(ksPlus(2501:end));

Sks_2R= Sks_2.^(-1/2);

figure 

hold on 

plot (ksPlus(1:2501),Sks_1R,'k','Linewidth',3);
plot (ksPlus(2501:end),Sks_2R,'k','Linewidth',3);

xlim([0 500])
ylim([0 3])


xlabel('$ {k_s}^+ $','Interpreter','latex');
ylabel('$ {S_R}^{-1/2}$','Interpreter','latex');

set(gca,"DefaultAxesFontName",'Arial');
set(gca,"DefaultTextFontName",'Arial');
ax=gca;
ax.FontSize = 20;

print('fig2_a','-dpng','-r600')






