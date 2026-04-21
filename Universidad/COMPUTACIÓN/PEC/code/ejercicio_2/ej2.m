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
   % buscar min/max entre el actual y los nuevos valores
   umin = min(umin, vdata);
end

% Valor máximo y mínimo de color se halla automáticamente en el colormap <?>, lo podemos observar con colorbar
exit = 1;
while exit==1
    for n=1:10
    for i=1:10
        surf(1:100,1:100,redu{i});
        view(2); % vista desde arriba en 2D
        drawnow;
    end
    end
    % exit = input("¿Deseas salir? (0/1)");
end