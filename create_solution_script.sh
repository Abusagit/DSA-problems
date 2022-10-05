#! /bin/bash

usage="$(basename "$0") - Template for automatic creation of raw, blank scripts with given name and extension in provided directory - because who wants to type it by its own???!
        -d <dir> [current_dir] - directory for new file to be saved at
        -n <Any name> - name of a file in qoutes - any dots/lines will be removed and spaces replaces by underscores
        -e <extension> [cpp] - extension of a future file

    Enjoy!
"

EXTENSION="cpp"
OUTDIR="./"

if [ "$1" == "-h" ]; then
  echo "$usage"
  exit 0
fi

while getopts ":d:n:h:e:" opt; do
    case $opt in
        d)
            OUTDIR=$OPTARG;;
        n) 
            NAME="$OPTARG";;

        e) 
            EXTENSION="$OPTARG";;

        \?)
            echo "Invalid parameter!"
            exit;;
    esac
done


NAME="${NAME// /_}" # replace spaces by underscores
NAME="${NAME//-/}"  # delete lines from name
NAME="${NAME//./}.${EXTENSION}" # delete dots from name

mkdir -p $OUTDIR # create directory if it doesn`t exist


whole_name="${OUTDIR}/${NAME}"
touch $whole_name
echo "File with name ${NAME} was created at ${whole_name}"