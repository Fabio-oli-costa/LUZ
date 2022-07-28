using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Data.Common;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Npgsql;
using MySql.Data.MySqlClient;

namespace WPF_escola_DB
{
    /// <summary>
    /// Essa classe vai linkar as multipals conexões com bancos diversos a MainWindowsVM
    /// Fazendo a ligação, sem que a MainWindowsVM precise saber do
    /// </summary>
    public class GerenciaConexão
    {
        private IConexão con;

        public GerenciaConexão()
        {
            this.con = new ConexãoPostgres();
        }
        public DbConnection Conectar()
        {

            return this.con.Conectar();
        }

        public void Atualizar(Aluno aluno)
        {
            this.con.Atualizar(aluno);
        }

        public void Deletar(Aluno aluno)
        {
            this.con.Deletar(aluno);
        }

        public void Enviar(Aluno aluno)
        {
            this.con.Enviar(aluno);
        }

        public List<Aluno> Mostrar()
        {
            return this.con.Mostrar();
        }
    }
}
