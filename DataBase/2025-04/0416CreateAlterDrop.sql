--DDL(Data Definition Language)
--Create
CREATE DATABASE GameDB
USE GameDB
CREATE TABLE PlayerAccount2
(	
	accountID INTEGER NOT NULL,
	accountName VARCHAR(10) NOT NULL,
	accountMoney INTEGER DEFAULT 0,
	accountCreateTime DATETIME,

)
USE GameDB


INSERT INTO PlayerAccount2(accountID,accountName,accountMoney,accountCreateTime)
VALUES (1,'p1',1000,GETDATE())
INSERT INTO PlayerAccount2(accountID,accountName,accountMoney,accountCreateTime)
VALUES (2,'p2',1000,GETDATE())
INSERT INTO PlayerAccount2(accountID,accountName,accountMoney,accountCreateTime)
VALUES (3,'p3',1000,GETDATE())

SELECT * 
FROM PlayerAccount2

--ALTER : 테이블 디자인 변경
ALTER TABLE PlayerAccount2
ADD CONSTRAINT PK_accountID PRIMARY KEY(accountID)

ALTER TABLE PlayerAccount2
DROP CONSTRAINT PK_AccountID

ALTER TABLE PlayerAccount2
ADD CONSTRAINT accountName PRIMARY KEY(accountName)

--DROP
DROP TABLE PlayerAccount2