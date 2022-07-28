using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static Wpf1.Aluno;

namespace Wpf1
{
    public class Escola
    {

        private List<Aluno> listaAluno; //Lista que recebe o tipo Alunoe chama listaAluno

        public Escola()
        {
            this.listaAluno = ListaStaticAluno.listaStaticAluno;
        }

        public void AddAluno(string nomeCompleto, string codAluno, Ano serie)
        {
            this.listaAluno.Add(new Aluno(nomeCompleto, codAluno, serie));
        }

        //RemoverAluno
        public void RemoveAluno(Aluno aluno)
        {
            this.listaAluno.Remove(aluno);
        }

    }

}

