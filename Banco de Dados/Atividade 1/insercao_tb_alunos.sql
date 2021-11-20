use escola;

create table alunos(
idAlunos int(11) auto_increment primary key,
idCursos int(11),
nomeAluno varchar(45) not null,
constraint fk_idCursos foreign key (idCursos) references insercao_tb_cursos (idCursos)
) default charset = utf8;
