--Transaction : Ʈ�����

USE GameDB


--Commit : ������������ ��� �ݿ�
BEGIN TRAN
INSERT INTO PlayerAccount2 Values (4,'p4',1234,GETUTCDATE())
COMMIT --tran �ȿ� �ִ� �ڵ���� �� ok �� �ݿ�

--RollBack : �����ϸ� �ǵ���
BEGIN TRAN
INSERT INTO PlayerAccount2 values(5,'p5',123123,GETUTCDATE())
ROLLBACK --tran �ȿ� �ִ� �ڵ�� �ѹ�


--TRY A CATCH B : A�� �õ��ϰ� ����������� B
BEGIN TRY
	BEGIN TRAN
		INSERT INTO PlayerAccount2 values(6,'p6',123123,GETUTCDATE())
		INSERT INTO PlayerAccount2 values(7,'p7',123123,GETUTCDATE())

	COMMIT
END TRY

BEGIN CATCH
	IF @@TRANCOUNT > 0 --���� Ȱ��ȭ�� Ʈ������� ���� ��ȯ
		ROLLBACK
END CATCH

SELECT *
FROM PlayerAccount2

DROP TABLE PlayerAccount2