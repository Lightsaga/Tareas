using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Threading;

namespace Barbershop
{
    //Pequeña referencia a esto: http://www.youtube.com/watch?v=cH14UJkfhwY
    class Program
    {
        static Queue<Thread> Espera = new Queue<Thread>();
        static Semaphore Barbero = new Semaphore(1, 1);
        public static int cupo = 5;
        public static int clientes = 0;
        static void Main(string[] args)
        {
            int i = 0;
            while(true)
            {
                if (clientes == 0)
                {
                    Atender(0);
                }
                if (clientes < cupo)
                {
                        Espera.Enqueue(new Thread(Program.Atender));
                        Console.WriteLine("El ciente numero: " + (i + 1) + " ha llegado...");
                        Espera.Peek().Start(i + 1);
                        Espera.Dequeue();
                        i++;
                        clientes++;
                }
                else
                {
                    Console.WriteLine("El ciente numero: " + (i+1) + " se ha ido...");
                    i++;
                }
                Thread.Sleep(2000);
            }
        }

       static void Atender(object numero)
        {
            if (clientes > 0)
            {
                Barbero.WaitOne();
                Console.WriteLine("El ciente numero: " + numero + " esta siendo atendido por el barbero");
                Thread.Sleep(1000);
                Console.WriteLine("El ciente numero: " + numero + " ya fue atendido");
                clientes--;
                Barbero.Release();
            }
            else
            {
                Console.WriteLine("Barbero dormido...");
                Thread.Sleep(500);
            }
        }

    }


}
