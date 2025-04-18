USE BaseballData

--변수선언
DECLARE @i AS INT = 1000000
DECLARE @s AS NVARCHAR(15) = 'hanil'

--SET @s = 'sotoma01'
--
--SELECT *
--FROM salaries
--WHERE salary > @i AND playerID = @s

--SET @s =
--(
--SELECT TOP(1) (nameFirst + nameLast) as FullName
--FROM players
--ORDER BY weight DESC
--)
--
--SELECT @s

--임시테이블
--DECLARE @testTable TABLE
--(
--fullName VARCHAR(50) NOT NULL,
--playerWeight INT NOT NULL
--)
--
--SELECT *
--FROM @testTable

--분기문
DECLARE @i2 AS INT = 5

--IF @i2 = 5
--BEGIN 
--PRINT('TRUE')
--END
--
--ELSE
--
--BEGIN
--PRINT('FALSE')
--END

--반복문

SET @i2 = 0
WHILE @i2 < 5
BEGIN 
	SET @i2 = @i2 +1
	PRINT @i2
END

--testTable에 이름과 몸무게를 넣어주세요

DECLARE @testTable TABLE
(
fullName VARCHAR(50) NOT NULL,
playerWeight INT NOT NULL
)

INSERT INTO @testTable (fullName, playerWeight)
SELECT (nameFirst + nameLast) AS FullName, weight
FROM players
WHERE weight IS NOT NULL 
 AND nameFirst IS NOT NULL 
 AND nameLast IS NOT NULL
ORDER BY weight DESC;

SELECT *
FROM @testTable