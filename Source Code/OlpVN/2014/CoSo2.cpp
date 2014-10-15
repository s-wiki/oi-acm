#include <cstdio>
#include <cmath>
typedef unsigned long long ull;

// Tinh b^0 + b^1 + b^2 + .. + b^deg
ull f(ull base, ull deg)
{
	unsigned long long rs=1;
	unsigned long long k=base;
	
	while(deg--)
	{
		rs += k;
		k *= base;
	}
	
	return rs;
}

ull get_min_base(ull n)
{
	ull m = (ull)sqrt(n);
	ull min_base = n-1;
	ull a, x, y, d, b, r;
	bool check;
	// N = a*x, 2 <= a <= sqrt(n) va x = b^0 + b^1 + b^2 + .. + b^d
	for(a = m; a > 1; a--)
	{
		if(n % a == 0)
		{
			x = n/a;
			// d lon nhat khi 2^d = x => d = log2(x) va d > 0
			for(d = (ull)log2(x); d > 0; d--)
			{
				// b^d = x => b = x^(1/d)
				b = (ull)(pow(x, 1.0/d));
				// Kiem tra xem co tim thay co so b thoa man f(b, d) = x khong
				check = false;
				r=1;
				
				while(b>r)
				{
					y = f(b, d);
					//printf("x=%llu b=%llu d=%llu y=%llu\n", x, b, d, y);
					
					if(y == x) 
					{
						check = true;
						break;
					}
					else if(y < x)
					{
						// r luu lai co so b lam f(b, d) < x, ro rang khi d giam o buoc tiep theo
						// neu b <= r thi f(b, d) luon luon < x => khong can xet voi b <= r
						r = b;
						break;
					}
					
					b--;
				}
				
				// Da tim thay co so b thoa man X = f(b, d), cap nhat co so nho nhat
				if(check) 
				{
					if(b < min_base)
						min_base = b;
					break;
				}
			}
		}
	}
	
	return min_base;	
}

int main()
{
	int T;
	unsigned long long n;
	scanf("%d", &T);
	
	for(int i=0; i<T; i++)
	{
		scanf("%llu", &n);
		printf("%llu\n", get_min_base(n));
	}
	return 0;
}
