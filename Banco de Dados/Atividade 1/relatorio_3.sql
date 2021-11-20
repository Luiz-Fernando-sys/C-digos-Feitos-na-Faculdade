# RELATÓRIO 3

# Premiar professores pelo tempo de serviço e auxílio como professore na escola.

# A proposta criada por mim no relatório abaixo é a seguinte:
# Será feita uma premiação nesta escola visando premiar os 30 primeiro professores da escola, ou seja, no caso os 30 primeiros professores desta escola desde sua inauguração, como forma de agradecimento por todo conhecimento compoartilhado.
# A premiação deverá acontecer de acordo com a ordem que cada um chegou até a escola, ou seja, de acordo com a ordem de contratação de cada um dos professores na escola, pois assim ficará mais fácil para premiar corretamente os professores.
# O 10 primeiro professores serão premiado com premiação de alta classe, recebendo vale-compras, vale refeição em um jantar à luz de velas, e medalha como reconhecimento.
# Os demais professores serão premiados com um certificado de mensão honrosa e um vale compras de natal.

# Com isso, a proposta da pesquisa abaixo é consultar todos os professores que possuem número de identificação entre 1 a 30, para que a atual diretora da escola possa verificar quais foram os primeiros 30 professores da escola e já preparar os presentes personalizados de cada um de acordo com sua posição entre os primeiros docentes da escola.


# O código busca apenas o idProfessor e o nomeProfessor dentro da tabela professor e apresenta apenas o nome dos professores que estão entre as posições 1 e 30. O script apresentará os id's de maneira ordenada, que já é o de se esperar.

select idProfessores, nomeProfessor from professores
where idProfessores between 1 and 30
order by idProfessores;