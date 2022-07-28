using MySql.Data.MySqlClient;
using Npgsql;
using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Data.Common;
using System.Data.SqlClient;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace WPF_escola_DB
{
    public class ConexãoMysql : IConexão
    {
        private string serverName;
        private string port;
        private string userName;
        private string password;
        private string databaseName;
        private string connString;
        private MySqlConnection MysqlConnection;
        private MySqlConnection objconexao;
        private MySqlCommand comandosql;
        public ConexãoMysql()
        {
            this.serverName = "127.0.0.1";
            this.port = "3306";
            this.userName = "root";
            this.password = "1234";
            this.databaseName = "fabio";

            this.connString = string.Format("Server={0};Port={1};User Id={2};Password={3};Database={4};",
                                                serverName, port, userName, password, databaseName);
        }
        public DbConnection Conectar()
        {
            this.MysqlConnection = new MySqlConnection(this.connString);
            return this.MysqlConnection;
        }
        public void Enviar(Aluno aluno)
        {
            using (this.objconexao = (MySqlConnection)Conectar())
            {
                try
                {
                    this.objconexao.Open();

                    string sqlInsert = $"INSERT INTO alunos (nomecompleto, codaluno, serie) VALUES ('{aluno.NomeCompleto}', '{aluno.CodAluno}', '{(int)aluno.Serie}')";

                    using (this.comandosql = new MySqlCommand(sqlInsert, this.objconexao))
                    {
                        this.comandosql.ExecuteNonQuery();

                        Console.WriteLine("*********** ENVIOU ***********");
                    }
                }
                catch (Exception ex)
                {
                    Console.WriteLine("*********** FALHOU ***********");
                    Console.WriteLine(ex.Message);
                }
                finally
                {
                    this.objconexao.Close();
                }
            }
        }
        public List<Aluno> Mostrar()
        {

            using (this.objconexao = (MySqlConnection)Conectar())
            {
                try
                {
                    this.objconexao.Open();

                    string sqlSelect = "SELECT * FROM  alunos";

                    using (this.comandosql = new MySqlCommand(sqlSelect, this.objconexao))
                    {
                        MySqlDataReader adoDR = this.comandosql.ExecuteReader();
                        List<Aluno> listaDeAlunos = new List<Aluno>();

                        if (adoDR.HasRows)
                        {
                            while (adoDR.Read())
                            {
                                Aluno aluno = new Aluno();
                                aluno.NomeCompleto = adoDR.GetString(0);
                                aluno.CodAluno = adoDR.GetString(1);
                                aluno.Serie = (Ano)adoDR.GetInt16(2);
                                listaDeAlunos.Add(aluno);
                            }
                        }
                        return listaDeAlunos;
                    }
                }
                catch (Exception ex)
                {
                    Console.WriteLine("*********** FALHOU ***********");
                    Console.WriteLine(ex.Message);
                    throw ex;
                }
                finally
                {
                    this.objconexao.Close();
                }
            }
        }
        public void Atualizar(Aluno aluno)
        {
            using (this.objconexao = (MySqlConnection)Conectar())
            {
                try
                {
                    this.objconexao.Open();

                    string sqlUpdate = $"UPDATE alunos SET (nomecompleto, serie) = ('{aluno.NomeCompleto}', '{(int)aluno.Serie}') WHERE codaluno = '{aluno.CodAluno}'";


                    using (this.comandosql = new MySqlCommand(sqlUpdate, this.objconexao))
                    {
                        this.comandosql.ExecuteNonQuery();

                        Console.WriteLine("*********** ALTEROU ***********");
                    }
                }
                catch (Exception ex)
                {
                    Console.WriteLine("*********** FALHOU ***********");
                    Console.WriteLine(ex.Message);
                }
                finally
                {
                    this.objconexao.Close();
                }
            }
        }

        public void Deletar(Aluno aluno)
        {
            using (this.objconexao = (MySqlConnection)Conectar())
            {
                try
                {
                    this.objconexao.Open();

                    string sqlDelete = $"DELETE FROM alunos WHERE codaluno = '{aluno.CodAluno}';"; ;

                    using (this.comandosql = new MySqlCommand(sqlDelete, this.objconexao))
                    {
                        this.comandosql.ExecuteNonQuery();

                        Console.WriteLine("*********** DELETOU ***********");
                    }
                }
                catch (Exception ex)
                {
                    Console.WriteLine("*********** FALHOU ***********");
                    Console.WriteLine(ex.Message);
                }
                finally
                {
                    this.objconexao.Close();
                }
            }
        }      
    }
}
