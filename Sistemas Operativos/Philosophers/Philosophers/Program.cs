using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Threading;

namespace Philosophers
{
    class Program
    {
        public static Semaphore S1 = new Semaphore(1, 2);
        public static Filosofo[] Filosofos = new Filosofo[5];
        public static Tenedor[] Tenedores = new Tenedor[5];
        static void Main(string[] args)
        {
            Filosofos[0] = new Filosofo(100, 4, 0);
            Filosofos[0].Proceso = new Thread(FilosofoM);
            Filosofos[1] = new Filosofo(100, 0, 1);
            Filosofos[1].Proceso = new Thread(FilosofoM);
            Filosofos[2] = new Filosofo(100, 1, 2);
            Filosofos[2].Proceso = new Thread(FilosofoM);
            Filosofos[3] = new Filosofo(100, 2, 3);
            Filosofos[3].Proceso = new Thread(FilosofoM);
            Filosofos[4] = new Filosofo(100, 3, 4);
            Filosofos[4].Proceso = new Thread(FilosofoM);
            for (int i = 0; i < Tenedores.Length; i++)
            {
                Tenedores[i] = new Tenedor();
            }
            for (int i = 0; i < Filosofos.Length; i++)
            {
                Filosofos[i].Nombre = "Filosofo" + (i + 1);
                Filosofos[i].Proceso.Start(Filosofos[i]);
            }
            //Filosofos[0].Proceso.Start();
            //Filosofos[1].Proceso.Start();
            //Filosofos[2].Proceso.Start();
            //Filosofos[3].Proceso.Start();
            //Filosofos[4].Proceso.Start();
        }

        public static bool TomarTenedor(int index)
        {
            bool v = false;
            int i = 0;
            for (; i < index; )
            {
                i++;
            }
            if (Tenedores[i].Disponible)
            {
                Tenedores[i].Disponible = false;
                v = true;
            }
            return v;
        }

        public static void DejarTenedores(int index)
        {
            int i = 0;
            for (; i < index; )
            {
                i++;
            }
           Tenedores[i].Disponible = true;
        }

        public static void FilosofoM(object f)
        {
            Filosofo F = (Filosofo)f;
            while (true)
            {
                if (F.Estado == Filosofo.estado.Pensando)
                {
                    Console.WriteLine("El " + F.Nombre + " esta Pensando...");
                    S1.WaitOne();
                    if (TomarTenedor(F.PrimerTenerdorIndex))
                    {
                        F.PrimerTenedor = true;
                        Console.WriteLine("El " + F.Nombre + " tomo un tenedor");
                        //Thread.Sleep(1000);
                        foreach (Tenedor t in Tenedores)
                        {
                            Console.WriteLine(t.Disponible);
                        }
                    }
                    if (TomarTenedor(F.SegundoTenedorIndex))
                    {
                        F.SegundoTenedor = true;
                        Console.WriteLine("El " + F.Nombre + " tomo un tenedor");
                        //Thread.Sleep(1000);
                        foreach (Tenedor t in Tenedores)
                        {
                            Console.WriteLine(t.Disponible);
                        }
                    }
                    if (F.PrimerTenedor != true || F.SegundoTenedor != true)
                    {
                        Console.WriteLine("El " + F.Nombre + " fallo en tomar un tenedor y dejo ambos");
                        F.PrimerTenedor = false;
                        F.SegundoTenedor = false;
                        DejarTenedores(F.PrimerTenerdorIndex);
                        DejarTenedores(F.SegundoTenedorIndex);
                        //Thread.Sleep(1000);
                    }
                    if (F.PrimerTenedor == true && F.SegundoTenedor == true)
                    {
                        F.Estado = Filosofo.estado.Comiendo;
                        Console.WriteLine("El " + F.Nombre + " esta comiendo");
                        while (F.comida != 0)
                        {
                            F.comida--;
                            Thread.Sleep(100);
                        }
                        DejarTenedores(F.PrimerTenerdorIndex);
                        DejarTenedores(F.SegundoTenedorIndex);
                        F.comida = 100;
                        F.Estado = Filosofo.estado.Pensando;
                    }
                    S1.Release();
                }
                Thread.Sleep(5000);
            }
        }
    }
}
