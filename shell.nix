{ mkShell
, cudaPackages_12_3
, gcc12Stdenv
}:
mkShell.override { stdenv = gcc12Stdenv; } {
  buildInputs = [
    cudaPackages_12_3.cudatoolkit
  ];
}
