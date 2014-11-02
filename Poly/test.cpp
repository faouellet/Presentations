int countOdd(int A[], int N) {
  int cpt = 0;

  for (int i = 0; i < N; ++i)
    if (A[i] % 2 == 1)
      cpt++;

  return cpt;
}
