clear all;
close all; 

AoE=[1 1.5 2 2.5 3 3.5 4 5];
dt(1:length(AoE))=0.01;
dtt(1:length(AoE))=0.01;
dt(3)=0.001; %4.5
dt(4)=0.001; %4.5
dt(7)=0.0005; %9.5
dt(8)=0.001; %9.5
dttt= 0.01;
load Area
AA=AoE;
Uo= [0.09 0.135 0.18 0.224 0.269 0.314 0.359 0.140];  
ks= [0.26 0.45 0.5 0.375 1.25 3 1.5 0.81];
rho=1000;
T= ones(1,8).*7;
T(8)=5.37;

TT=ones(1,2).*7;
TT(2)=5.37;

omega=(ones(1,8)).*(2*pi./T);

nu=0.000001;
delta=(ones(1,8)).*sqrt(2*nu./omega);
No= T./dt; 
Noo= T./dtt;

Nooo= TT./dttt;

Uoo= [0.18 0.140];

omegaa=(ones(1,2)).*(2*pi./TT);

file_in={"forces/featureResolved/Ap1dp2T7",...
         "forces/featureResolved/Ap15dp2T7",...
         "forces/featureResolved/Ap2dp2T7",... 
         "forces/featureResolved/Ap25dp2T7.csv",... 
         "forces/featureResolved/Ap3dp2T7",...
         "forces/featureResolved/Ap35dp2T7",...
         "forces/featureResolved/Ap4dp2T7",...
         "forces/featureResolved/DUTOTI"};
file_in_1={"forces/param/1DV/Ap1dp2T7.csv",...
         "forces/param/1DV/Ap15dp2T7.csv",...
         "forces/param/1DV/Ap2dp2T7.csv",... 
         "forces/param/1DV/Ap25dp2T7.csv",... 
         "forces/param/1DV/Ap3dp2T7.csv",...
         "forces/param/1DV/Ap35dp2T7.csv",...
         "forces/param/1DV/Ap4dp2T7.csv",...
         "forces/param/1DV/DUTOTI.csv"};    
 
file_in_2={"forces/param/2DV/Ap2dp2T7.csv",... 
          "forces/param/2DV/DUTOTI.csv"};     
      
tit={"(a)","(b)","(c)","(d)","(e)","(f)","(g)","(h)"};

%%
for i=1:length(file_in_2)

Data4= importdata(file_in_2{i});

Nppp(i)=round(length(Data4)./Nooo(i));         %number of periods

timeee{i}=Data4((Nooo(i)+1):end,1);


stress_fw_2dv{i}=2*((Data4((Nooo(i)+1):end,2))./((Uoo(i))^2));

UU_inf{i}=Uoo(i)*cos(omegaa(i)*timeee{1,i});  
 
  
% figure
% yyaxis left
% plot(timeee{1,i},stress_fw_2dv{1,i},'m','LineWidth',2);
% set(gca,'XColor','k', 'YColor','k')
% 
% ylabel('${2{\tau}}/ ( {\rho} {{U_o}}^2)$','Interpreter','latex');
% xlabel('$ time [s] $','Interpreter','latex');
% %xlim([63 70])
% 
% 
% yyaxis right
% plot(timeee{1,i},UU_inf{1,i}/Uoo(i),'k','LineWidth',1);
% %ylim ([-1.5 1.5])
% ylabel('$ u/U_o$','Interpreter','latex');
% set(gca, 'XColor','k', 'YColor','k');
% 
% legend("pressure ","viscous", "total","Velocity");
% title(tit{i});
% set(gca,'XColor','k', 'YColor','k')
% 
% %xlim([63 70])
% set(gca,"DefaultAxesFontName",'Arial');
% set(gca,"DefaultTextFontName",'Arial');
% ax=gca;
% ax.FontSize = 20;

end

%%
for i=1:length(file_in)

Data= importdata(file_in{i});
Data1= importdata(file_in_1{i});

Np(i)=round(length(Data)./No(i));    %number of periods
Npp(i)=round(length(Data1)./Noo(i)); %number of periods

time{i}=Data((No(i)+1):end,1);
timee{i}=Data1((Noo(i)+1):end,1);

stress_t{i}=(Data((No(i)+1):end,2))./Area(i);   % Stress is in pascal 
stress_fw{i}=2*((Data((No(i)+1):end,2))./((Area(i)*rho).* (Uo(i))^2));
stress_fw_1dv{i}=2*((Data1((Noo(i)+1):end,2))./((Uo(i))^2));

U_inf{i}=Uo(i)*cos(omega(i)*time{1,i});  
 

end
%%

for i=2
    
 xl=[1:No(i)]*dt(i);  
 xllv=[1:Noo(i)]*dtt(i);  
 xjbc=[1:No(i)]*dt(i);  
 xx=reshape(stress_t{1,i},No(i),[]);
 xy=reshape(stress_fw{1,i},No(i),[]);
 xz=reshape(stress_fw_1dv{1,i},Noo(i),[]);
  
 data(i).xy = xy;
 data1(i).xx = xx;
 per_t_av{i}= mean(reshape(stress_t{1,i},No(i),[])')';                    % total stress phase average
 per_t_av_fw{i}= mean(reshape(stress_fw{1,i},No(i),[])')';                % fw phase average
 
 
figure  

hold on

yyaxis left

hold on 


plot(xl*(360/T(i)),per_t_av_fw{i},'-b','Linewidth',3);
plot(xllv*(360/T(i)),-xz(:,length(xz(1,:))),'-m','Linewidth',3);
plot((timeee{1,1}-14)*(360/TT(1)),-stress_fw_2dv{1,1},'r','LineWidth',3);


xlim([0 (Noo(i)/100)*(360/T(i))])

set(gca, 'XColor','k', 'YColor','k');
xlabel('$\phi^o $','Interpreter','latex');
ylabel('${2{\tau}}/ ( {\rho} {{U_o}}^2)$','Interpreter','latex');

yyaxis right
plot(xl*(360/T(i)),(Uo(i)*cos(omega(i)*xl))./Uo(i),'k--','LineWidth',1); 
ylim([-1.1 1.1])
ylabel('$ u/U_o$','Interpreter','latex');
set(gca, 'XColor','k', 'YColor','g');


set(gca, 'XColor','k', 'YColor','k');
set(gca,"DefaultAxesFontName",'Arial');
set(gca,"DefaultTextFontName",'Arial');
ax=gca;
ax.FontSize = 20;
title(strcat(tit{1}));
hold on 
legend('ensemble average','param-all','param-reduced','Interpreter','latex');
end

print('fig4_a','-dpng','-r600')

%%

for i=8
    
 xl=[1:No(i)]*dt(i);  
 xllv=[1:Noo(i)]*dtt(i);  
 xjbc=[1:No(i)]*dt(i);  
 xx=reshape(stress_t{1,i},No(i),[]);
 xy=reshape(stress_fw{1,i},No(i),[]);
 xz=reshape(stress_fw_1dv{1,i},Noo(i),[]);
  
 data(i).xy = xy;
 data1(i).xx = xx;
 per_t_av{i}= mean(reshape(stress_t{1,i},No(i),[])')';                    % total stress phase average
 per_t_av_fw{i}= mean(reshape(stress_fw{1,i},No(i),[])')';                % fw phase average
 
 
figure  

hold on

yyaxis left

hold on 


plot(xl*(360/T(i)),per_t_av_fw{i},'-b','Linewidth',3);
plot(xllv*(360/T(i)),-xz(:,length(xz(1,:))),'-m','Linewidth',3);
plot((timeee{1,2}-5.37)*(360/TT(2)),-stress_fw_2dv{1,2},'r','LineWidth',3);

xlim([0 (Noo(i)/100)*(360/T(i))])

set(gca, 'XColor','k', 'YColor','k');
xlabel('$\phi^o $','Interpreter','latex');
ylabel('${2{\tau}}/ ( {\rho} {{U_o}}^2)$','Interpreter','latex');

yyaxis right
plot(xl*(360/T(i)),(Uo(i)*cos(omega(i)*xl))./Uo(i),'k--','LineWidth',1); 
ylim([-1.1 1.1])
ylabel('$ u/U_o$','Interpreter','latex');
set(gca, 'XColor','k', 'YColor','g');


set(gca, 'XColor','k', 'YColor','k');
set(gca,"DefaultAxesFontName",'Arial');
set(gca,"DefaultTextFontName",'Arial');
ax=gca;
ax.FontSize = 20;
title(strcat(tit{2}));
hold on 
%legend('ensemble average','param-all','param-reduced','Interpreter','latex');
end

print('fig4_b','-dpng','-r600')
%%