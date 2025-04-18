--Transaction : 트랜잭션

USE GameDB


--Commit : 실패하지않을 경우 반영
BEGIN TRAN
INSERT INTO PlayerAccount2 Values (4,'p4',1234,GETUTCDATE())
COMMIT --tran 안에 있는 코드들이 다 ok 면 반영

--RollBack : 실패하면 되돌림
BEGIN TRAN
INSERT INTO PlayerAccount2 values(5,'p5',123123,GETUTCDATE())
ROLLBACK --tran 안에 있는 코드들 롤백


--TRY A CATCH B : A를 시도하고 실패했을경우 B
BEGIN TRY
	BEGIN TRAN
		INSERT INTO PlayerAccount2 values(6,'p6',123123,GETUTCDATE())
		INSERT INTO PlayerAccount2 values(7,'p7',123123,GETUTCDATE())

	COMMIT
END TRY

BEGIN CATCH
	IF @@TRANCOUNT > 0 --현재 활성화된 트랜잭션의 수를 반환
		ROLLBACK
END CATCH

SELECT *
FROM PlayerAccount2

DROP TABLE PlayerAccount2