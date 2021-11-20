use escola;

create table cursos_disciplinas(
id int(11) primary key,
idCursos int(11),
idDisciplinas int(11),
constraint fk_idCursos foreign key (idCursos) references insercao_tb_cursos (idCursos),
constraint fk_idDisciplinas foreign key (idDisciplinas) references insercao_tb_disciplinas (idDisciplinas)
) default charset = utf8;
