using MySql.Data.MySqlClient;
using Npgsql;
using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.ComponentModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Input;

namespace WPF_escola_DB
{
    public class MainWindowsVM
    {
        private GerenciaConexão gerenciador;
        public MainWindowsVM()
        {
            gerenciador = new GerenciaConexão();
            listaAlunos = new ObservableCollection<Aluno>(gerenciador.Mostrar()); // vai vir de GerenciaConexão
            IniciaComandos();
        }

        public ObservableCollection<Aluno> listaAlunos { get; set; }
        public ICommand add { get; private set; }
        public ICommand remove { get; private set; }
        public ICommand atualiza { get; private set; }
        public Aluno alunoSelecionado { get; set; }

        public void IniciaComandos()
        {

            this.add = new RelayCommand((object _) =>
            {
                Aluno AlunoNovo = new Aluno();

                CadastroAluno janelaCadastro = new CadastroAluno();
                janelaCadastro.DataContext = AlunoNovo;
                bool? verifica = janelaCadastro.ShowDialog();
                if (verifica.HasValue && verifica.Value)
                {
                    try
                    {
                        gerenciador.Enviar(AlunoNovo);
                        this.listaAlunos.Add(AlunoNovo);
                    }
                    catch (Exception ex)
                    {
                        Console.WriteLine("*********** FALHOU ***********");
                        Console.WriteLine(ex.Message);                   
                    }
                }
            });


            this.remove = new RelayCommand((object _) =>
            {
                try
                {
                    gerenciador.Deletar(this.alunoSelecionado);
                    this.listaAlunos.Remove(alunoSelecionado);
                }
                catch (Exception ex)
                {
                    Console.WriteLine("*********** FALHOU ***********");
                    Console.WriteLine(ex.Message);
                }
            },
            (object _) =>
            {
                return this.alunoSelecionado != null;
            });

            this.atualiza = new RelayCommand((object _) =>
            {
                try
                {
                    Aluno AlunoClone = (Aluno)this.alunoSelecionado.Clone();

                    CadastroAluno janelaAtualizar = new CadastroAluno();
                    janelaAtualizar.DataContext = AlunoClone;

                    bool? verifica = janelaAtualizar.ShowDialog();
                    if (verifica.HasValue && verifica.Value)
                    {
                        gerenciador.Atualizar(AlunoClone);
                        this.alunoSelecionado.NomeCompleto = AlunoClone.NomeCompleto;

                        this.alunoSelecionado.Serie = AlunoClone.Serie;
                    }
                }
                catch (Exception ex)
                {
                    Console.WriteLine("*********** FALHOU ***********");
                    Console.WriteLine(ex.Message);
                }
            },
               (object _) =>
               {
                   return this.alunoSelecionado != null;
               });
        }
    }
}

