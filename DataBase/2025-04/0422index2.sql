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

--index (B-tree : 자가균형이진탐색트리)

--Clustered Index
--영한사전 : 실제 데이터가 index순으로 정렬
--->여러개 존재할 수 없다
--
--Non-Clustered Index
--색인: 따로 어떤 테이블(b-tree)생긴다
--많으면 많을수록 데이터를 많이 잡아먹는다 , 보통 캐싱 해놓는다 ->메모리를 많이 잡아먹을 수 있다
--Non-Clustered Index만 걸었을시에 heap테이블이 생긴다
--Non-Clustered Index 는 Clustered Index의 영향을 받는다

--레지스터 : 계산결과를 담아놓는 저장소
--캐시 : 메모리 번지 수를 잠깐 기억하는 곳 , 빈번하게 쓰는 메모리 번지수 저장

CREATE CLUSTERED INDEX index_ID ON PlayerAccount2(accountID)
DROP INDEX index_ID ON PlayerAccount2


CREATE INDEX index_name ON PlayerAccount2(accountName)
DROP INDEX index_name ON PlayerAccount2

Select*
From PlayerAccount2 WITH(INDEX(index_name))
WHERE accountName = 'Hanil13'

--index scan vs index seek
--상황에 따라 스캔이 더 좋을 수도 있다

SET STATISTICS TIME ON
SET STATISTICS IO ON
SET STATISTICS 