using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OS___NRU_Algorithm
{
    class Program
    {
        
        static void Main(string[] args)
        {
            List<int> Numeros = new List<int>();
            int x = 4;
            int y = 4;
            int[,] Matriz = new int[x, y];
            InicializarMatriz(ref Matriz, x, y);
            while (true)
            {
                Console.WriteLine("Ingresar una cifra numerica con numeros desde 1 a 4");
                string CifraInput = Console.ReadLine();
                if (LlenarArreglo(CifraInput,ref Numeros))
                {
                    foreach (int i in Numeros)
                    {
                        Console.WriteLine("Despues del numero " + (i+1));
                        LlenarMatriz(ref Matriz, x, y, i);
                        ImprimirMatriz(ref Matriz,x,y);
                    }
                }
                else
                {
                    Console.WriteLine("Error: has ingresado caracteres invalidos en la cifra numerica");
                    Console.ReadLine();
                    Console.Clear();
                }
                Console.ReadLine();
                InicializarMatriz(ref Matriz, x, y);
                Console.Clear();
            }
        }

        //Metodos A:
        public static bool LlenarArreglo(string s,ref List<int> Numeros)
        {
            bool v = true;
            Numeros.Clear();
            foreach (char c in s)
            {
                if (VerificarChar(c))
                {
                    Numeros.Add(int.Parse(c.ToString())-1);
                }
                else
                {
                    v = false;
                }
            }
            return v;
        }
        public static bool VerificarChar(char c)
        {
            bool v = true;
            if((int)c<49 || (int)c >52)
            {
                v = false;
            }
            return v;
        }
        public static void InicializarMatriz(ref int[,] m,int x, int y)
        {
            for (int i = 0; i < x; i++)
            {
                for (int j = 0; j < y; j++)
                {
                    m[i, j] = 0;
                }
            }
        }
        public static void LlenarMatriz(ref int[,] m, int x, int y,int index)
        {
            for (int i = 0; i < x; i++)
            {
                m[index,i] = 1;
            }
            for (int j = 0; j < y; j++)
            {
                m[j, index] = 0;
            }
        }
        public static void ImprimirMatriz(ref int[,] m, int x, int y)
        {
            for (int i = 0; i < x; i++)
            {
                for (int j = 0; j < y; j++)
                {
                    Console.Write(m[i, j] + " ");
                }
                Console.WriteLine();
            }
        }
    }
}
