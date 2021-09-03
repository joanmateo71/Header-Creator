#!/bin/bash

#===============================================================================================================================================================
# Nombre:			HeaderCreator_ES
# Autor:			Joan Mateo Salazar
# Fecha:			03/09/2021
# Versión:              	1.0
# Comando de ejecución:		bash HeaderCreator_EN.sh
# Descripción:          	Crea automaticamente cabeceras para scripts
# Licencia:             	This is free software, licensed under the GNU General Public License v3. See http://www.gnu.org/licenses/gpl.html for more information."
#================================================================================================================================================================


echo "Bienvenido al Header Creator. El script que crea cabeceras para tus scripts"
sleep 1

echo "Coloca el nombre del script/archivo:"
read nameFile

echo "Coloca el autor del script:"
read autor

echo "Se añadirá la fecha actual del script."
ActualDate=$(date +"%d"/"%m"/"%Y") 

echo "Coloca la versión del script:"
read version

echo "Coloca el comando de ejecución del script"
read usage

echo "Coloca la descripción del script"
read description

echo "¿Qué licencia te gustaría añadir a tu script? [g] = GPL v3.0 / [m] = MIT."
read licenseSelect

if [ $licenseSelect == g ];
then
	license=$(echo "This is free software, licensed under the GNU General Public License v3. See http://www.gnu.org/licenses/gpl.html for more information.")
else
if [ $licenseSelect == m ];
then
	license=$(echo "This is free software, licensed under the MIT Massachusetts Institute of Technology. See https://mit-license.org/ for more information.")
else
	echo "Coloca una respuesta correcta."
    exit 1
fi
fi

echo "Creando una nueva cabecera..."
sleep 1

echo "
#!/bin/bash

#====================================================================================================
# Nombre:			$nameFile
# Autor:			$autor
# Fecha:			$ActualDate
# Versión:			$version	
# Comando de ejecución:		$usage
# Descripción:			$description
# Licencia:			$license
#===================================================================================================="

sleep 1
echo "Gracias por usar Header Creator. Hasta pronto. :)"
exit 0
