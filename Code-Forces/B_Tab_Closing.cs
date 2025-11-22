using System;

class Program
{
    static void Main()
    {
        int t = int.Parse(Console.ReadLine());
        while (t-- > 0)
        {
            var parts = Console.ReadLine().Split();
            long a = long.Parse(parts[0]);
            long b = long.Parse(parts[1]);
            long n = long.Parse(parts[2]);

            long moves = 0;
            long prevX = -1;

            long m = n;
            while (m > 0)
            {
                long len = Math.Min(b, a / m);
                long x = m * len;

                if (x != prevX)
                {
                    moves++;
                    prevX = x;
                }

                // Find next m where x changes:
                if (len == b)
                {
                    // x = m*b, decreases linearly
                    // x changes every time m decreases by 1
                    m--;
                }
                else
                {
                    // len = a/m  => x = a  (constant)
                    // Find the largest m where a/m is still >= b
                    long next_m = a / b;      // threshold where len stops being a/m
                    if (next_m < m) m = next_m;
                    else m--; // fallback
                }
            }

            Console.WriteLine(moves);
        }
    }
}
