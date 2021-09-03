#!/bin/bash

#===============================================================================================================================================================
# File name:          HeaderCreator_EN
# Author:             Joan Mateo Salazar
# Date:               03/09/2021
# Version:            1.0
# Execution command:  bash HeaderCreator_EN.sh
# Description:        Creates automatically a header for scripts
# License:            This is free software, licensed under the GNU General Public License v3. See http://www.gnu.org/licenses/gpl.html for more information."
#================================================================================================================================================================


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

echo "Put the description of the script"
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
# File Name: 	        $nameFile
# Author:	            $autor
# Date:		            $ActualDate
# Version:		        $version	
# Execution command:	$usage
# Description:		    $description
# License:	          $license
#===================================================================================================="

sleep 1
echo "Thanks for use Header Creator, see you soon. :)"
