using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PretrageOsnovno
{
    class State
    {
        public State Parent { get; set; }
        public Node Node { get; set; }
        public double Cost { get; set; }
        public int Level { get; set; }

        public State(Node node)
        {
            this.Node = node;
            this.Level = 1;
            this.Cost = 0;
        }

        public State(Node node, int level, double cost)
        {
            this.Node = node;
            this.Level = level;
            this.Cost = cost;
        }

        // konstruise moguce sledece stanje na osnovu cvora u grafu
        public State NextState(Node node, double cost)
        {
            State nextState = new State(node, this.Level + 1, cost);
            nextState.Node = node;
            nextState.Parent = this;
            return nextState;
        }

        // metoda odredjuje sledeca stanja u koja je moguce preci iz trenutnog stanja
        public List<State> children()
        {
            List<State> children = new List<State>();

            // TODO 2: pronaci moguca sledeca stanja na osnovu veza koje vode iz cvora u kom je trenutno stanje
            #region PronalazenjeMogucihStanja
            /*
             * Ideja je proci kroz sve linkove trenutnog cvora
             * i videti gde sve mogu da zavrse, to staviti u strukturu NextState()
             * i ta sledeca stanja dodati u listu children.
             */

            foreach (Link link in this.Node.Links)
            {
                Node endNode = link.EndNode;
                double cenaLinka = link.Cost;   // na to dodati jos cenu trenutnog cvora jer generalno tako funkcionise
                // cena odredjenog cvora, tj. cena roditelja i "puta" do njega
                cenaLinka += this.Cost;
                children.Add(NextState(endNode, cenaLinka));
                
            }

            #endregion

            return children;
        }

        public override int GetHashCode()
        {
            return Node.GetHashCode() * 100;
        }

        public List<State> path()
        {
            List<State> path = new List<State>();
            State tt = this;
            while (tt != null)
            {
                path.Insert(0, tt);
                tt = tt.Parent;
            }
            return path;
        }
    }
}
