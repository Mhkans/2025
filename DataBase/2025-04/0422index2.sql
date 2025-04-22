USE GameDB

DECLARE @i INT
SET @i = 10

WHILE(@i<=500)
BEGIN
	INSERT INTO PlayerAccount2
	VALUES(@i , 'Hanil' + CONVERT(VARCHAR,@i),@i * 1000,GETUTCDATE());
	SET @i = @i +1
END

SELECT *
FROM PlayerAccount2

--index (B-tree : �ڰ���������Ž��Ʈ��)

--Clustered Index
--���ѻ��� : ���� �����Ͱ� index������ ����
--->������ ������ �� ����
--
--Non-Clustered Index
--����: ���� � ���̺�(b-tree)�����
--������ �������� �����͸� ���� ��ƸԴ´� , ���� ĳ�� �س��´� ->�޸𸮸� ���� ��Ƹ��� �� �ִ�
--Non-Clustered Index�� �ɾ����ÿ� heap���̺��� �����
--Non-Clustered Index �� Clustered Index�� ������ �޴´�

--�������� : ������� ��Ƴ��� �����
--ĳ�� : �޸� ���� ���� ��� ����ϴ� �� , ����ϰ� ���� �޸� ������ ����

CREATE CLUSTERED INDEX index_ID ON PlayerAccount2(accountID)
DROP INDEX index_ID ON PlayerAccount2


CREATE INDEX index_name ON PlayerAccount2(accountName)
DROP INDEX index_name ON PlayerAccount2

Select*
From PlayerAccount2 WITH(INDEX(index_name))
WHERE accountName = 'Hanil13'

--index scan vs index seek
--��Ȳ�� ���� ��ĵ�� �� ���� ���� �ִ�

SET STATISTICS TIME ON
SET STATISTICS IO ON
SET STATISTICS 