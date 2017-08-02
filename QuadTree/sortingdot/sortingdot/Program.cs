using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace sortingdot
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("The Fat Cat");

            Random rnd = new Random(101);

            int[] numbersarray = new int[10];

            for (int i = 0; i < 10; i++)
            {
                numbersarray[i] = rnd.Next(1, 51);
                Console.Write(numbersarray[i] + " ");
            }

            bool swapped = true;

            while (swapped == true)
            {
                swapped = false;
                for (int i = 1; i < 10; i++)
                {
                    if (numbersarray[i - 1] > numbersarray[i])
                    {
                        int temp = numbersarray[i];
                        numbersarray[i] = numbersarray[i - 1];
                        numbersarray[i - 1] = temp;
                        swapped = true;
                    }
                }
            }

            Console.WriteLine();

            for (int i = 0; i < 10; i++)
            {
                Console.Write(numbersarray[i] + " ");
            }

            Console.Read();
        }
    }
}
