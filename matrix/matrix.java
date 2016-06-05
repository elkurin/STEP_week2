class matrix
{
	public static void main(String args[]) {
		int size = 1;
		for (int i = 1; i <= 20; i++) {
			int a[][];
			int b[][];
			a = new int[size][size];
			b = new int[size][size];
			int c[][];
			c = new int[size][size];

			for (int j = 0; j < size; j++) {
				for (int k = 0; k < size; k++) {
					a[j][k] = 1;
					b[j][k] = 1;
					c[j][k] = 0;
				}
			}
			long tstart = System.nanoTime();
			for (int p = 0; p < size; p++) {
				for (int q = 0; q < size; q++) {
					for (int r = 0; r < size; r++) {
						c[p][q] += a[p][r] * b[r][q];
					}
				}
			}
			long tend = System.nanoTime();

			System.out.println((tend - tstart) / 1000000000f);
			size *= 2;
		}
	}
}

