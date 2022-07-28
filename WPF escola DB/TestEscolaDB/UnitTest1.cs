using NUnit.Framework;
using System.Collections.ObjectModel;
using System.Windows.Input;
using WPF_escola_DB;

namespace Tests
{
    public class TestesUnitarios
    {
        [SetUp]
        public void Setup()
        {
        }

        [Test]
        public void ValidaCamposPreenchidos()
        {
            Aluno aluno = new Aluno("Jonas", "1234", (Ano)2);

            Assert.IsNotNull(aluno.NomeCompleto);
            Assert.IsNotNull(aluno.CodAluno);
        }

        [Test]
        public void ValidaCamposVazios()
        {
            Aluno aluno = new Aluno();

            Assert.IsNull(aluno.NomeCompleto);
            Assert.IsNull(aluno.CodAluno);
        }
    }
}