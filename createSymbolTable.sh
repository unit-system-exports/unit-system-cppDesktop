#!/bin/bash

soFiles=("base" "common")
exportFolder="windows-extras"

echo -e "cleaning up old dir"
rm -rf $exportFolder
mkdir $exportFolder
    
for file in ${soFiles[@]}
do
    echo -e "create new export folder for $file"
    mkdir $exportFolder/$file
    
    echo -e "getting symbol table for build/$file/libunit-system-$file.so"
    
    echo -e "; Auto-generated by symbol Table Script\nEXPORTS unit-system-$file" > "windows-extras/$file/unit-system-$file.def"
    symbols=($(nm -gD build/$file/libunit-system-$file.so | awk '{print $3}' | grep _))
    echo -e "found ${#symbols[*]} symbols"
    for (( i=0 ; i < ${#symbols[*]} ; i++ ));
    do
        sym=${symbols[i]}
        echo "$sym @$i" >> "windows-extras/$file/unit-system-$file.def"
    done
done
