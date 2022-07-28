using System;
using System.ComponentModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Wpf1
{
    public class Aluno: INotifyPropertyChanged, ICloneable
    {
        private string nomeCompleto;
        private string codAluno;
        private Ano serie;
        private Ano serieAno;
        public event PropertyChangedEventHandler PropertyChanged;

        public Aluno(string nomeCompleto, string codAluno, Ano serie)
        {
            this.nomeCompleto = nomeCompleto;
            this.codAluno = codAluno;
            this.serie = serie;
        }

        public Aluno()
        {

        }

        //O que falta aqui? - Geters e Setters
        public string NomeCompleto
        {
            get { return nomeCompleto; }
            set { nomeCompleto = value; Notifica("nomeCompleto"); }
        }
        public string CodAluno
        {
            get { return codAluno; }
            set { codAluno = value; Notifica("CodAluno"); }
        }
        public Ano Serie
        {
            get { return serie; }
            set { serie = value; Notifica("Serie"); }
        }

        public Ano SerieAno
        {
            get { return Serie; }
            set
            {
                Serie = value;
                Console.WriteLine(serieAno);
            }
        }

        public void Notifica(string propertyName)
        {
            PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(propertyName));
        }


        public object Clone()
        {
            Aluno clone = (Aluno) MemberwiseClone();
            return clone;                     
        }
    }
}
