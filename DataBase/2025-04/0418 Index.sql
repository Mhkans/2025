USE BaseballData

SELECT*
FROM players

CREATE TABLE IndexTest
(
	lahmanID INT NOT NULL,
	fullName NVARCHAR(50) NOT NULL,
	weight INT,
	height INT
)


INSERT INTO IndexTest
SELECT lahmanID , nameFirst + nameLast , weight , height
FROM players
WHERE nameFirst IS NOT NULL AND nameLast IS NOT NULL

--Table Scan - bad
SELECT *
FROM IndexTest
WHERE lahmanID = 1500

--Clustered Index
--Index Seek - LogN 데이터가 많을 수록 효율적이다 
--정렬되어있다 테이블에서 단 하나만 존재할 수 있다
CREATE CLUSTERED INDEX Clustered_Test ON IndexTest(lahmanID)
DROP INDEX Clustered_Test ON IndexTest

--Non Clustered Index
--Index Scan - N (해시테이블 최악의경우) 데이터가 많을수록 비효율적
--정렬 X 테이블에서 여러개 존재할 수 있다 
CREATE INDEX Non_Test ON IndexTest(fullName)
DROP INDEX Non_Test ON IndexTest

SELECT *
FROM IndexTest
WHERE fullName LIKE 'J%'



--복합인덱스
--순서차이에 의해서 찾는 시간의 차이가 발생한다
CREATE INDEX NON_Composite ON IndexTest(lahmanID , fullName)

--Seek
SELECT*
FROM IndexTest
WHERE lahmanID = 80 AND fullName = 'DeweyAdkins'

--Seek
SELECT*
FROM IndexTest
WHERE lahmanID = 80

--Scan
SELECT*
FROM IndexTest
WHERE fullName = 'DeweyAdkins'

DROP TABLE IndexTest