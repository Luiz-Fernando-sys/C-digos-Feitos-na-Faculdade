use escola;

create table professores_disciplinas(
id int(11) primary key,
idProfessores int(11),
idDisciplinas int(11),
constraint fk_idProfessores foreign key (idProfessores) references insercao_tb_professores (idProfessores),
constraint fk_idDisciplinas foreign key (idDisciplinas) references insercao_tb_cursos_disciplinas (idDisciplinas)
) default charset = utf8;
