use escola;

INSERT INTO professores
(idProfessores, nomeProfessor)
values
('1', 'Godofredo');

INSERT INTO professores (idProfessores, nomeProfessor)
values
('234', 'Maria');

INSERT INTO professores (idProfessores, nomeProfessor)
values
('432', 'João Miguel');

INSERT INTO professores (idProfessores, nomeProfessor)
values
('465', 'Zé Rodrigues');

INSERT INTO professores
(idProfessores, nomeProfessor)
values
('867', 'Roberto');

INSERT INTO professores
(idProfessores, nomeProfessor)
values
('756', 'Antônio Roberto');

INSERT INTO professores
(idProfessores, nomeProfessor)
values
('132', 'Tony Stark');

INSERT INTO professores
(idProfessores, nomeProfessor)
values
('243', 'Pops do Santos Silva');

INSERT INTO professores
(idProfessores, nomeProfessor)
values
('354', 'Chaves Silveira del Ocho');

INSERT INTO professores
(idProfessores, nomeProfessor)
values
('456', 'Madruga dos Santos');

/* ---------- INSERINDO REGISTROS NA TABELA "DISCIPLIANAS" ---------- */

INSERT INTO disciplinas
(idDisciplinas, nomeDisciplina)
values
('1', 'Matemática'),
('2', 'Português'),
('3', 'Biologia'),
('4', 'Química'),
('5', 'Física'),
('6', 'Artes'),
('7', 'Educação Religigiosa'),
('8', 'Sociologia'),
('9', 'Filosofia'),
('10', 'Geografia'),
('11', 'História'),
('12', 'Redação'),
('13', 'Inglês'),
('14', 'Espanhol'),
('15', 'Educação Física'),
('16', 'Libras'),
('17', 'Literatura'),
('18', 'Psicologia');


/* ---------- INSERINDO REGISTROS NA TABELA "CURSOS" ---------- */

INSERT INTO cursos
(idCursos, nomeCurso)
values
('098', 'Ciências Humanas'),
('987', 'Ciências exatas'),
('986', 'Ciências da Natureza'),
('985', 'Ciências Sociais'),
('981', 'Ciências Artíticas');



/* ---------- INSERINDO REGISTROS NA TABELA "ALUNOS" ---------- */

INSERT INTO alunos
(idAlunos, idCursos, nomeAluno)
values
('1', '098', 'José Pereira Silva'),
('2', '987', 'Elisa Mariz Quinta'),
('3', '986', 'Roberta Frajuca Borba'),
('4', '985', 'Enoque Cabeça de Vaca Rodovalho'),
('5', '981', 'Lara Freiria Matos'),
('6', '098', 'Maximiano Vilalobos Aveiro'),
('7', '987', 'Ariel Mamouros Bivar'),
('8', '986', 'Carol Serro Gois'),
('9', '985', 'Iúri Sardinha Rosa'),
('10', '981', 'Áurea Damasceno Arouca'),
('11', '098', 'Davide Cantanhede Malho'),
('12', '987', 'Susana Matoso Viegas'),
('13', '986', 'Kaya Bragança Fragoso'),
('14', '985', 'Lourenço Cancela Faia'),
('15', '981', 'Simona Gomide Fagundes'),
('16', '098', 'Ângela Sítima Cavaco'),
('17', '987', 'Elena Aquino Fortes'),
('18', '986', 'Sílvia Bingre Roçadas'),
('19', '985', 'Isaac Pinheiro Vilhena'),
('20', '981', 'Miguela Lameiras Abranches'),
('21', '098', 'Lilian Redondo Leal'),
('22', '987', 'Daiana Natal Guedes'),
('23', '986', 'Anita Muniz Canedo'),
('24', '985', 'Matviy Cidreira Carmona'),
('25', '981', 'Cristovão Peseiro Cadavez'),
('26', '098', 'Isabella Inês Ruela'),
('27', '987', 'Destiny Moita Macieira'),
('28', '986', 'Aicha Moutinho Rabelo'),
('29', '985', 'Matthias Neto Berenguer'),
('30', '981', 'Adelina Mata Pureza'),
('31', '098', 'Orlando Girão Carvalhosa'),
('32', '987', 'Ayla Neto Norões');

