using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Threading;

namespace Philosophers
{
    class Filosofo
    {
        public string Nombre { get; set; }
        public estado Estado { get; set; }
        public enum estado {Pensando,Comiendo };
        public Thread Proceso { get; set; }
        public int comida { get; set; }
        public int PrimerTenerdorIndex { get; set; }
        public int SegundoTenedorIndex { get; set; }
        public bool PrimerTenedor { get; set; }
        public bool SegundoTenedor { get; set; }

        public Filosofo()
        {
            Estado = estado.Pensando;
            comida = 10;
        }

        public Filosofo(int _comida, int primerIndex, int segundoIndex)
        {
            Estado = estado.Pensando;
            comida = _comida;
            PrimerTenerdorIndex = primerIndex;
            SegundoTenedorIndex = segundoIndex;
            PrimerTenedor = false;
            SegundoTenedor = false;
        }

    }
}
