using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Shapes;

namespace WPF_escola_DB
{
    /// <summary>
    /// Lógica interna para CadastroAluno.xaml
    /// </summary>
    public partial class CadastroAluno : Window
    {
        public CadastroAluno()
        {
            InitializeComponent();
            comboAno.ItemsSource = Enum.GetValues(typeof(Ano)).Cast<Ano>();
        }
        public void bnt_envia(object sender, RoutedEventArgs e)
        {
            if (Nome.Text == "" || Codigo.Text == "")
            {
                MessageBox.Show("Preencha todos os campos");
                return;
            }
            DialogResult = true;
        }
    }
}
