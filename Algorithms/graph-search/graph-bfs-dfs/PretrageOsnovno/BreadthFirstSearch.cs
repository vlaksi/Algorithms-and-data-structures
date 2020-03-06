using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PretrageOsnovno
{
    class BreadthFirstSearch
    {
        public State Search(string startNodeName, string endNodeName)
        {
            // TODO 4: implementirati algoritam prvi u dubinu širinu
            #region BFS
            /*
             * Ideja je na implementaciji pomocu simuliranja REDA i FIFO principa.
             */

            Node startNode = Program.instance.graph[startNodeName];
            Node endNode = Program.instance.graph[endNodeName];

            List<State> red = new List<State>();            // RED - FIFO princip cemo simulirati preko liste i dodavanja na kraj
                                                            // za razliku od DFS gde UBACUJEMO na pocetak i tako simuliramo STEK
            red.Add(new State(startNode));

            while (red.Count > 0)
            {
                State naObradi = red[0];
                red.Remove(naObradi);

                // proverimo da li je na obradi ciljni cvor ako jeste, vratimo ga, u suprotnom dodamo njegovu decu u RED, na kraj
                // kako bi ocuvali FIFO princip
                if(naObradi.Node.Name == endNode.Name)
                {
                    return naObradi;
                }
                else
                {
                    List<State> mogucaSledecaStanja = naObradi.children();
                    foreach (State stanje in mogucaSledecaStanja)
                    {
                        red.Add(stanje);
                    }
                }
            }
            #endregion
            return null;
        }
    }
}
