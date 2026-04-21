% Importar datos del ejercicio 1
time = readmatrix("../ejercicio_1/time.dat");
amp = readmatrix("../ejercicio_1/amplitud.dat");
% Bucle para leer los archivos de la red u
red = cell(0,9);
for i=0:9
    filename = sprintf("../ejercicio_1/u_%d.dat",i);
    red{i} = readmatrix(filename);
end