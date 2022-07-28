using NUnit.Framework;
using System;
using System.Collections.Generic;
using System.Text;
using WPF_escola_DB;

namespace Tests
{
    public class TestesIntegração
    {
        [SetUp]
        public void Setup()
        {
        }

        [Test]
        public void ValidaInserir()
        {
            Aluno aluno = new Aluno("Aluno1", "1234", (Ano)2);
            GerenciaConexão gerenciador = new GerenciaConexão();
                    
            gerenciador.Enviar(aluno);

            Assert.Pass();
        }
    }
}
