--INSERT (ROW 삽입)
--DELETE (ROW 삭제)
--UPDATE (ROW 에 있는 데이터 변경)

USE BaseballData

SELECT *
FROM salaries
ORDER BY salary DESC

--INSERT INTO salaries VALUES (2025,'123','NL','DEFGHIJK',50000000)
--DELETE FROM [테이블] WHERE [조건]
--DELETE FROM salaries 
--WHERE playerID = 'DEFGHIJK'

--UPDATE [테이블명] SET[열 = 값] WHERE [조건]
--UPDATE salaries 
--SET salary = salary * 1.5
--WHERE yearID = 2025 AND teamID ='123' AND lgID = 'NL' AND playerID = 'DEFGHIJK' 