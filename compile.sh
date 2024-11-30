#!/bin/bash

# Überprüfen, ob die Anzahl der übergebenen Argumente korrekt ist
if [ "$#" -ne 2 ]; then
    echo "Usage: $0 <input_c_file> <output_executable>"
    exit 1
fi

# Extrahieren der Eingabeparameter
input_file="$1"
output_file="$2"

# Verzeichnis für die Ausgabe erstellen, falls es nicht vorhanden ist
output_dir="bin"
mkdir -p "$output_dir"

# Kompilieren des C-Programms
gcc -o "$output_dir/$output_file" "$input_file"

# Überprüfen, ob das Kompilieren erfolgreich war
if [ $? -eq 0 ]; then
    echo "Compilation successful. Executable created: $output_dir/$output_file"
else
    echo "Compilation failed. Please check your C code."
fi
