# RELATÓRIO 1

# Consulta para achar os alunos de um curso específico.
# O presente relatório visa apresentar somente pessoas alunos que estaão cadastrado no curso com identificação 987.

# O objetivo disso é uma consulta rápida no banco de dados quando quisermos localizar alunos de um curso específico.
# Com esta consulta será possível gerar o relatório de consulta de alunos cadastrados em um determinado curso, ou seja, não será preciso procurar pelo aluno dentre todas as pessoas de outros cursos, pois podemos filtrar para que apareça somente alunos do curso que desejo.

select idCursos, nomeAluno from alunos
where idCursos = 987;