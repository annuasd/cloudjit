#-DFUNC_TYPE=int\(int\,int\) -DFUNC_PARAM=12\,5
cmake -B build -DEXE_NAME=$1 -DFUNC_TYPE=$2 -DFUNC_PARAM=$3
cmake --build build
rm -rf build
