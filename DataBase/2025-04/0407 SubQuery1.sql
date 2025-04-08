--MSSQL
--DATETIME Type 의 비교
--VARCHAR(String) 비교
--집계함수
--Sub Query

--USE BaseBallData;
----players 테이블에서 모든 사람의 이름과 태어난 날짜 사망날짜 나이 를 출력 
--SELECT nameFirst , nameLast , 
--DATEFROMPARTS(birthYear , birthMonth,birthDay) As 생일 ,
--DATEFROMPARTS(deathYear , deathMonth,deathDay) AS 돌아가신날,
--(deathYear - birthYear) as 나이
--
--FROM players
--WHERE DATEFROMPARTS(deathYear , deathMonth,deathDay) IS NOT NULL AND DATEFROMPARTS(birthYear , birthMonth,birthDay) IS NOT NULL
--ORDER BY 나이

--players 테이블에서 birthCity 가 New로 시작하는 사람들의 모든 정보를 출력
--SELECT * 
--FROM players
----VARCHAR
----LIKE 'NEW%' -> New로 시작하는 모든 단어
----LIKE 'NEW___' -> new로 시작하고 뒤에 세글자
--WHERE birthCity LIKE 'NEW%'

--SubQuery -> Query in Query

SELECT TOP(1) playerID
FROM salaries
ORDER BY salary DESC

SELECT * 
FROM players
WHERE playerID = --자료형을 맞춰줘야함
(
	SELECT TOP(1) playerID
	FROM salaries
	ORDER BY salary DESC
)

--프로그래머스 문제 
--가장 비싼 상품 구하기
--가격이 제일 비싼 식품의 정보 
--최대값 구하기
--동물 수 구하기
--중복 제거하기

--GROUP BY 
--고양이와 개는 몇마리 
--자동차 종류 별 특정 옵션이 포함
--동명 동물 수 찾기