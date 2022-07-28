using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Npgsql;
using System.Data;
using System.Windows;
using System.Collections.ObjectModel;
using System.Data.Common;

namespace WPF_escola_DB
{
    public class ConexãoPostgres : IConexão
    {
        private string serverName;
        private string port;
        private string userName;
        private string password;
        private string databaseName;
        private NpgsqlConnection pgsqlConnection;
        private NpgsqlConnection objconexao;
        private NpgsqlCommand comandosql;
        private string connString;
        public ConexãoPostgres()
        {
            this.serverName = "127.0.0.1";
            this.port = "5432";
            this.userName = "postgres";
            this.password = "1234";
            this.databaseName = "postgres";

            this.connString = string.Format("Server={0};Port={1};User Id={2};Password={3};Database={4};",
                                                serverName, port, userName, password, databaseName);
        }
        public DbConnection Conectar()
        {
            this.pgsqlConnection = new NpgsqlConnection(this.connString);
            return this.pgsqlConnection;
        }

        public void Enviar(Aluno aluno)
        {
            using (this.objconexao = (NpgsqlConnection)Conectar())
            {
                try
                {
                    objconexao.Open();

                    string sqlInsert = $"INSERT INTO alunos (nomecompleto, codaluno, serie) VALUES ('{aluno.NomeCompleto}', '{aluno.CodAluno}', '{(int)aluno.Serie}');";

                    using (this.comandosql = new NpgsqlCommand(sqlInsert, this.objconexao))
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
            using (this.objconexao = (NpgsqlConnection)Conectar())
            {
                try
                {
                    this.objconexao.Open();

                    string sqlSelect = "SELECT * FROM  alunos";

                    using (this.comandosql = new NpgsqlCommand(sqlSelect, this.objconexao))
                    {
                        NpgsqlDataReader adoDR = this.comandosql.ExecuteReader();
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
            using (this.objconexao = (NpgsqlConnection)Conectar())
            {
                try
                {
                    this.objconexao.Open();

                    string sqlUpdate = $"UPDATE alunos SET (nomecompleto, serie) = ('{aluno.NomeCompleto}', '{(int)aluno.Serie}') WHERE codaluno = '{aluno.CodAluno}'";


                    using (this.comandosql = new NpgsqlCommand(sqlUpdate, this.objconexao))
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
            using (this.objconexao = (NpgsqlConnection)Conectar())
            {
                try
                {
                    this.objconexao.Open();

                    string sqlDelete = $"DELETE FROM alunos WHERE codaluno = '{aluno.CodAluno}';";

                    using (this.comandosql = new NpgsqlCommand(sqlDelete, this.objconexao))
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

