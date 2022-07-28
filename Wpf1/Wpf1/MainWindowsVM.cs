using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.ComponentModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Input;

namespace Wpf1
{
    public class MainWindowsVM
    {
        
        public ObservableCollection<Aluno> listaAlunos { get; set;}

        public ICommand Add { get; private set; }
        public ICommand Remove { get; private set; }
        public ICommand Atualiza { get; private set; }
        public Aluno AlunoSelecionado { get; set; }
        public MainWindowsVM()
        {
            listaAlunos = new ObservableCollection<Aluno>();
            IniciaComandos();
        }

        public void IniciaComandos()
        {
            Add = new RelayCommand((object _) =>
            {

                Aluno AlunoNovo = new Aluno();

                CadastroAluno janelaCadastro = new CadastroAluno();
                janelaCadastro.DataContext = AlunoNovo;
                bool? verifica = janelaCadastro.ShowDialog();
                if(verifica.HasValue && verifica.Value) 
                { 
                    listaAlunos.Add(AlunoNovo); 
                }
                
            });

            Remove = new RelayCommand((object _) =>
            {
                listaAlunos.Remove(AlunoSelecionado);
            }, 
            (object _) =>
            {

                return AlunoSelecionado != null;
            });

             Atualiza = new RelayCommand((object _) =>
             {  
                    Aluno AlunoClone = (Aluno)AlunoSelecionado.Clone();

                    CadastroAluno janelaAtualizar = new CadastroAluno();
                    janelaAtualizar.DataContext = AlunoClone;

                    bool? verifica = janelaAtualizar.ShowDialog();
                    if (verifica.HasValue && verifica.Value)
                    {
                        AlunoSelecionado.NomeCompleto = AlunoClone.NomeCompleto;

                        AlunoSelecionado.CodAluno = AlunoClone.CodAluno;

                        AlunoSelecionado.Serie = AlunoClone.Serie;
                    }
             }, 
                (object _) =>
                {
                    return AlunoSelecionado != null;
            });
        }
           
    }
}

