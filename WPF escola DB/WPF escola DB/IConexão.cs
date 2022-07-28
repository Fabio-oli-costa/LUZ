using MySql.Data.MySqlClient;
using Npgsql;
using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Data.Common;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace WPF_escola_DB
{
    /// <summary>
    /// Essa interface define como devem ser as classes de conexão com os bancos
    /// </summary>
    public interface IConexão
    {
        DbConnection Conectar();
        List<Aluno> Mostrar();
        void Enviar(Aluno aluno);
        void Atualizar(Aluno aluno);
        void Deletar(Aluno aluno);
    }
}
