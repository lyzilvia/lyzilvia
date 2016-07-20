create database test_;

create table S
	(NO_ char(2) Unique Not Null,
	NAME char(10) Unique,
	SEX char(2),
	AGE int,
	CLASS char(5),
	primary key (NO_));
	
insert into S
	values(25, '李明', '男', 21, '95031');

insert into S
	values(10, '王丽', '女', 20, '95101');
	
insert into S(CLASS, NO_, NAME)
	values('95031', 30, '郑和');
	
create unique index sno on S(NO_ ASC);

create index sage on S(AGE DESC);
	
alter table S add comedate datetime;

drop index sage on S;

alter table S alter column AGE smallint;

alter table S drop Constraint No_;

drop table S;