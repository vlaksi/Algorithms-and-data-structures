using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PretrageOsnovno
{
    class Graph
    {
        public Dictionary<string, Node> graph = null;

        public Graph(string[] linesNodes, string[] linesLinks)
        {
            graph = new Dictionary<string, Node>();
            formGraph(linesNodes, linesLinks);
        }

        // TODO 1 : implementirati metodu formiranja grafa
        #region KreiranjeGrafa
        private void formGraph(string[] linesNodes, string[] linesLinks)
        {
            // Formiranje svih cvorova
            foreach (string red in linesNodes)
            {
                /*
                 * Ideja je je splitovati ulazni tekst kako bi dobili ime i heuristiku
                 * i tako kreirati Node i onda ga dodati u graf.
                 */
                string[] splitovano = red.Split(':');
                string imeGrada = splitovano[0];
                string heuristikaString = splitovano[1];
                double heuristika = double.Parse(heuristikaString);     // prebacivanje iz stringa u double
                Node node = new Node(imeGrada, heuristika);

                graph.Add(node.Name, node);

            }

            // Formiranje svih linkova
            foreach (string red in linesLinks)
            {
                /*
                 * Ideja je uraditi neophodno splitovanje radi dekomponovanje sadrzaja reda
                 * i potom dodati linkove
                 */
                string[] splitovanRed = red.Split(':');
                string[] splitovanLink = splitovanRed[1].Split(',');
                //string name = 

                string ime = splitovanRed[0];
                string pocetni = splitovanLink[0];
                string kraj = splitovanLink[1];
                string cenaString = splitovanLink[2];
                double cena = double.Parse(cenaString);

                Node pocetniCvor = graph[pocetni];
                Node zavrsniCvor = graph[kraj];

                Link link = new Link(pocetniCvor, zavrsniCvor, ime, cena); // taj cvor potom dodajemo pocetnom cvoru
                pocetniCvor.Links.Add(link);
                
            }
        }
        #endregion

        #region ispis
        public void printGraph()
        {
            StringBuilder sb = new StringBuilder();
            foreach (KeyValuePair<string, Node> kvp in graph)
            {
                foreach (Link link in kvp.Value.Links)
                {
                    Console.WriteLine(link.Name + ":" + link.StartNode + "," + link.EndNode + "," + link.Cost);
                }
            }
        }
        #endregion
    }
}
