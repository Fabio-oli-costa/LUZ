using Npgsql;
using System;
using System.Collections.ObjectModel;
using System.ComponentModel;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;

namespace WPF_escola_DB
{
    public class Aluno : INotifyPropertyChanged, ICloneable
    {
        private string nomeCompleto;
        private string codAluno;
        private Ano serie;

        public event PropertyChangedEventHandler PropertyChanged;

        public Aluno()
        {
        }
        public Aluno(string nomeCompleto, string codAluno, Ano serie)
        {
            this.nomeCompleto = nomeCompleto;
            this.codAluno = codAluno;
            this.serie = serie;
        }

        public string NomeCompleto
        {
            get { return this.nomeCompleto; }
            set { this.nomeCompleto = value; this.Notifica("nomeCompleto"); }
        }
        public string CodAluno
        {
            get { return this.codAluno; }
            set { this.codAluno = value; this.Notifica("CodAluno"); }
        }
        public Ano Serie
        {
            get { return this.serie; }
            set { this.serie = value; this.Notifica("Serie"); }
        }


        public void Notifica(string propertyName)
        {
            PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(propertyName));
        }


        public object Clone()
        {
            Aluno clone = (Aluno)MemberwiseClone();
            return clone;
        }
    }
}
