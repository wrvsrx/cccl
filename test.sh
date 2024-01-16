nvcc -Ithrust -Ilibcudacxx/include -Icub -Xcompiler "-fPIC" -shared lib.cu -o libtest.so
nvcc -Ithrust -Ilibcudacxx/include -Icub -Xcompiler \"-Wl,-rpath=.\" -ltest -L. main.cu -o main
./main
