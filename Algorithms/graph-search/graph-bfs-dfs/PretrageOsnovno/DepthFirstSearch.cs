using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Collections;

namespace PretrageOsnovno
{
    class DepthFirstSearch
    {
        public State Search(string startNodeName, string endNodeName)
        {
            // TODO 3: implementirati algoritam prvi u dubinu     

            #region DFS
            /*
             * Kao sto stek funkcionise - LIFO princip.
             */
            Node startNode = Program.instance.graph[startNodeName];
            Node endNode = Program.instance.graph[endNodeName];

            List<State> stek = new List<State>();       // preko liste cemo simulirati stek
            stek.Add(new State(startNode));             // dodajemo pocetak u stek

            while (stek.Count > 0)                       // obradjujemo dokle god ima elemenata na steku
            {
                State naObradi = stek[0];
                stek.Remove(naObradi);                  // uklanjamo ga sa steka jer je na obradi

                // proveravamo da li je na obradi trazeni Node
                if (naObradi.Node.Name == endNode.Name)
                {
                    return naObradi;                    // ako jeste, vratimo taj node
                }
                else                                    // u suprotnom, svu njegovu decu na stek dodamo
                {// moramo voditi racuna da dodamo na pocetak da bi ispostovali STEK
                    List<State> mogucaSledecaStanja = naObradi.children();
                    foreach (State stanje in mogucaSledecaStanja)
                    {
                        stek.Insert(0, stanje);         // mora na pocetak da bi ispostovali STEK i LIFO
                    }

                }

            }
            #endregion

            return null;
        }
    }
}
