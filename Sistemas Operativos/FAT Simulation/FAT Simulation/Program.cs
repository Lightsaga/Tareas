using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace FAT_Simulation
{
    class Program
    {
        static void Main(string[] args)
        {
            Bloque[] MemoriaFAT = new Bloque[10];
            MemoriaFAT[2] = new Bloque('H', 5);
            MemoriaFAT[5] = new Bloque('O', 1);
            MemoriaFAT[1] = new Bloque('L', 8);
            MemoriaFAT[8] = new Bloque('A', -1);
            Leer(ref MemoriaFAT, 2);
            Console.ReadLine();
        }

        public static void Leer(ref Bloque[] memoria,int inidiceInicial)
        {
            int i = inidiceInicial;
            string resultado = "";
            while (true)
            {
                if(memoria[i] !=null)
                {
                    Console.WriteLine("Indice del bloque: {0}\nValor del bloque: {1}\nIndice de Siguiente Bloque: {2}",i,memoria[i].Caracter,memoria[i].IndiceSiguiente);
                    Console.WriteLine(" ");
                    resultado += memoria[i].Caracter;
                    if (memoria[i].IndiceSiguiente != -1)
                    {
                        i = memoria[i].IndiceSiguiente;
                    }
                    else
                    {
                        Console.WriteLine("Resultado de lectura completo: " + resultado);
                        break;
                    }
                }
                else
                {
                    break;
                }
            }
        }
    }

    public class Bloque
    {
        public char Caracter { get; set; }
        public int IndiceSiguiente { get; set; }

        public Bloque(char caracter, int inidiceSiguiente)
        {
            Caracter = caracter;
            IndiceSiguiente = inidiceSiguiente;
        }
    }

}
