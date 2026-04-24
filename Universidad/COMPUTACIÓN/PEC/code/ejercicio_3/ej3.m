clear
a=0.1;
b=0.9; 
Du=1;
Dv=10;
u0 = a+b;
v0 = b/(a+b)^2;

% Jacobiano
J = [-1+2*u0*v0, u0^2; -2*u0*v0, -u0^2];
fprintf('Los autovalores son:');
display(eig(J)); % Autovalores
if all(real(eig(J))) < 0
    fprintf('Los valores reales son negativos.'); %foco
else
    fprintf('Los valores reales son positivos.');
end

% Evolución de las perturbaciones M(k)
kval = linspace(0,2,600);
eigM = 0:length(kval);
hold on;
for i=1:length(kval)
    k=kval{i};
    M = J-[Du*k^2, 0; 0, Dv*k^2];
    eigM{i} = eig(M);
end