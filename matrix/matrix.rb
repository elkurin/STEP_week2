include(Math)

def make_matrix(a, b)
	x = Array.new(a){ Array.new(b, 1) }
end


def matrix(n)
	for j in 0..9 do
		size = 2 ** j
		a = make_matrix(size, size)
		b = make_matrix(size, size)
		c = make_matrix(size, size)

		for p in 0..size-1 do
			for q in 0..size-1 do
				a[p][q] = 1;
				b[p][q] = 1;
				c[p][q] = 0;
			end
		end
		
		t0 = Time.now

		for p in 0..size-1 do
			for q in 0..size-1 do
				for i in 0..size-1 do
					c[p][q] += a[p][i] * b[i][q]
				end
			end
		end

		t1 = Time.now

		puts "#{(t1 - t0)}"
	end
end

	
