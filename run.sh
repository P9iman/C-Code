#!/bin/bash

# Funktion zur Zuordnung von Exit-Codes zu Signalnamen
get_signal_name() {
    case $1 in
        1) echo "SIGHUP";;
        2) echo "SIGINT";;
        3) echo "SIGQUIT";;
        4) echo "SIGILL";;
        6) echo "SIGABRT";;
        8) echo "SIGFPE";;
        9) echo "SIGKILL";;
        11) echo "SIGSEGV";;
        13) echo "SIGPIPE";;
        14) echo "SIGALRM";;
        15) echo "SIGTERM";;
        139) echo "SIGSEGV";;
        *) echo "Unknown signal";;
    esac
}

# Überprüfen, ob die Anzahl der übergebenen Argumente korrekt ist
if [ "$#" -ne 1 ]; then
    echo "Usage: $0 <executable_name>"
    exit 1
fi

# Extrahieren des Eingabeparameters
executable_name="$1"

# Überprüfen, ob das Ausführbare im bin-Verzeichnis vorhanden ist
if [ -x "bin/$executable_name" ]; then
    # Ausführen des Ausführbaren und Fehlerausgabe umleiten
    echo "Executing $executable_name..."
    ./bin/"$executable_name" 2> /dev/null
    exit_code=$?

    if [ $exit_code -ne 0 ]; then
        signal_name=$(get_signal_name $exit_code)
        echo "The executable '$executable_name' terminated with an error code: $exit_code ($signal_name)"
    else
        echo "The executable '$executable_name' finished successfully."
    fi
else
    echo "Executable '$executable_name' not found in bin directory."
    echo "Available executables in bin directory:"
    ls -1 bin/ | grep -vE '/$'
fi
