% Importar datos del ejercicio 1
time = readmatrix("../ejercicio_1/time.dat");
amp = readmatrix("../ejercicio_1/amplitud.dat");
% Bucle para leer los archivos de la red u
redu = cell(0,9);
%{
for i=0:9
    filename = sprintf("../ejercicio_1/u_%d.dat",i);
    redu{i} = readmatrix(filename);
end
%}

redu{0} = readmatrix("../ejercicio_1/u_0.dat");