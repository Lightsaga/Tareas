using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace SemaphoreP
{
    class Program
    {
        public static Semaphore S1 = new Semaphore(1, 1);
        //Semaphore S2 = new Semaphore(0, 0);
        public static int size = 3;
        public static int item = 0;
        public static int semaphore = 1;
        static void Main(string[] args)
        {
            Console.WriteLine("Presione 1 y de enter si quiere hacerlo por el metodo logico\nsin la clase Semaphore,de lo contrario solo de enter...");
            if (Console.ReadLine() == "1")
            {
                Thread Producer_T = new Thread(new ThreadStart(Producer_M));
                Thread Consumer_T = new Thread(new ThreadStart(Consumer_M));
                Producer_T.Start();
                Consumer_T.Start();
            }
            else
            {
                Thread Producer_S = new Thread(new ThreadStart(Producer_SM));
                Thread Consumer_S = new Thread(new ThreadStart(Consumer_SM));
                Producer_S.Start();
                Consumer_S.Start();
            }
        }

        static void Producer_M()
        {
            bool c = true;
            while (c == true)
            {
                if (semaphore > 0)
                {
                   
                    if (item < size)
                    {
                        semaphore--;
                        item++;
                        Console.WriteLine("Elemento ha sido producido/item: " + item);
                        semaphore++;
                        //Thread.Sleep(100);
                    }
                }
                if (item > size)
                    c = false;
            }
            Console.WriteLine(item);
            Console.ReadLine();
        }

        static void Consumer_M()
        {
            bool c = true;
            while (c == true)
            {
                if (semaphore > 0)
                {
                    
                    if (item > 0)
                    {
                        semaphore--;
                        item--;
                        Console.WriteLine("Elemento ha sido consumido/item: " + item);
                        semaphore++;
                        Thread.Sleep(100);
                    }
                }
                if (item < 0)
                    c = false;
            }
            Console.WriteLine(item);
            Console.ReadLine();
        }

        static void Producer_SM()
        {
            while (true)
            {
                S1.WaitOne();
                if (item < size)
                {
                    item++;
                    Console.WriteLine("Elemento ha sido producido/item: " + item);
                    Thread.Sleep(100);
                }
                S1.Release();
            }
        }
        static void Consumer_SM()
        {
            while (true)
            {
                S1.WaitOne();
                if (item > 0)
                {
                    item--;
                    Console.WriteLine("Elemento ha sido consumido/item: " + item);
                    Thread.Sleep(100);
                }
                S1.Release();
            }
        }

    }
}
