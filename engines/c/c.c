int Fibon1(int n) {
  if (n == 1 || n == 2) {
    return 1;
  } else {
    return Fibon1(n - 1) + Fibon1(n - 2);
  }
}