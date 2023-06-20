cmake -B build -DEXE_DIR=$1 -DEXE_NAME=$2 -DFUNC_TYPE=$3 -DNULL_ARG=$4 -DARG_TYPE=$5 -DARG_INDEX=$6 
cmake --build build
