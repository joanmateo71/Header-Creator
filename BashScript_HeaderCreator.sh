#!/bin/bash

#====================================================================================================
# Name:					Header Creator
# Author:				Joan Mateo
# Date:					11/10/2021
# Version:				2.0	
# Execution command:			bash Bash_HeaderCreator.sh
# Description:				Make header for bash scripts
# Licenses:				This is free software, licensed under the MIT Massachusetts Institute of Technology. See https://mit-license.org/ for more information.
#====================================================================================================

echo "Idioma/Language [ es / en ]"
read Idioma
if [ $Idioma == es ];
then

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

echo "Coloca el comando de ejecución del script:"
read usage

echo "Coloca la descripción del script:"
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

else
if [ $Idioma == en ];
then

echo "Welcome to Header Creator. The script that make your header for your scripts or files."
sleep 1

echo "Put the script/file name:"
read nameFile

echo "Put the author of the script:"
read author

echo "The current date will be added automatically."
ActualDate=$(date +"%d"/"%m"/"%Y") 

echo "Put the version of the script:"
read version

echo "Put the execution command:"
read usage

echo "Put the description of the script:"
read description

echo "What license would you add to your script? [g] = GPL v3.0 / [m] = MIT."
read licenseSelect

if [ $licenseSelect == g ];
then
	license=$(echo "This is free software, licensed under the GNU General Public License v3. See http://www.gnu.org/licenses/gpl.html for more information.")
else
if [ $licenseSelect == m ];
then
	license=$(echo "This is free software, licensed under the MIT Massachusetts Institute of Technology. See https://mit-license.org/ for more information.")
else
	echo "Put a correct answer."
    exit 1
fi
fi

echo "Creating the new header..."
sleep 1

echo "
#!/bin/bash
#====================================================================================================
# Name:					$nameFile
# Author:				$author
# Date:					$ActualDate
# Version:				$version	
# Execution command:			$usage
# Description:				$description
# Licenses:				$license
#===================================================================================================="

sleep 1
echo "Thanks for use Header Creator, see you soon. :)"

exit 0

else 
	sleep 1
	echo Escoge bien la opción / Choose the correct option.
	exit 1
fi
fi
