clear
% Importar datos del ejercicio 1
time = readmatrix("../ejercicio_1/time.dat");
amp = readmatrix("../ejercicio_1/amplitud.dat");
% Bucle para leer los archivos de la red u
redu = cell(0,9);
for i=0:9
    filename = sprintf("../ejercicio_1/u_%d.dat",i);
    data = readmatrix(filename);
    redu{i+1} = data;

   % Buscar valores máx y mín globales
   vdata = reshape(data, 1, []); %convertir en vector con 1 fila y [] columnas
   % buscar min/max entre el actual y los nuevos valores meidante concatenación
   umin = 999 ; umax = 0;
   umin = min([umin, vdata]);
   umax = max([umax, vdata]);
end

% ----------------------------

% Amplitud
%se han elegido los límites de la gráfica para la sección exponencial
X = time(1400:12000);
Y = log(amp(1400:12000));

% (figura separada)
f1 =figure('WindowStyle','normal'); ax1 = axes(f1);
f2 = figure('WindowStyle','normal'); ax2 = axes(f2);

% ajuste lineal
figure(f1);
xlim([1400 12000]);
syms x;
fit = polyfit(X,Y,1);
y = fit(1)*x+fit(2) ;
hold (ax1, 'on'); % combinar gráficas
scatter(ax1, X,Y,'Marker', '.', 'MarkerEdgeColor',"#b7d4f7"); %transparente
fplot(ax1, y, 'r');
text(6900,1.5,sprintf('A(t) = %f t + %f', fit(1),fit(2)));
text(7700,1, sprintf('\\lambda = %f', fit(1)));
hold (ax1, 'off');

% ----------------------------

% Loop de la animación
figure(f2);
while true
    for i=1:10
        surf(ax2 ,1:100,1:100,redu{i});
        clim(ax2, [umin umax]);
        colorbar(ax2);
        view(ax2,2); % vista desde arriba en 2D
        drawnow;
        pause(0.01);
    end
end