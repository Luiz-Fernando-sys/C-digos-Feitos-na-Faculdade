# RELATÓRIO 4

# Esta escola está atualizando todos os seus materiais das disciplinas existentes.
# Com isso, foi escolhido uma query para ir selecionando de 4 em 4 disciplinas por vês.
# Com isso, o código abaixo tem o intuito de separar as disciplinas por grupos de a cada 4 disciplinas, ou seja, primeiro será selecionado as 4 primeiras disciplinas, depois as próximas 4 disciplinas, e assim por diante.

# Assim, o intuito desta verificação abaixo é verificar quais são as 4 primeiras disciplinas a avaliar.
# Após a verificação das 4 primeiras disciplinas acontecerem, a equipe encarregada por atualizar começará a atualizar os materiais das respectivas disciplinas.
# Assim, as disciplinas a serem atualizadas serão atualizadas de acordo com a ordem alfabética.



select * from disciplinas
where idDisciplinas >= 1 and idDisciplinas <= 4
order by nomeDisciplina;

# OBSERVAÇÃO: A cada vez, o idDisciplina será mudado para 4 em 4, ou seja, na próxima passada ele teria que ser >= 5 e <= 8.
# Com isso, poderemos ter um código em PHP por exemplo que conversará com este nosso banco de dados, em específico esta query, para que os valores de idDisciplina sejam mudados.
# Perceba que os nomes das disciplinas aparecerão em órdem alfabética. No caso os idDisciplinas existentes irão mudar de ordem, mas irá obedecer a regra de estarem dentro do id definido no momento.
