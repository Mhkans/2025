--기본키와 외래키
--
--기본키
--1. NULL 값을 가질 수 없다
--2. 테이블에서 단 하나의 기본키만 존재한다
--3. 중복을 허용하지않는다
--->Clusted Index
--
--외래키
--1. 하나의 테이블에서 다른 테이블의 키를 참조하는 키
--2. 데이터 무결성을 지키는 중요한 역할
--3. NULL값 허용
--4. 테이블에서 여러개의 외래키가 등장 할 수 있다
--5. 중복된 키도 외래키로 만들 수 있다.

--테이블을 합친다
--1.UNION
--2.JOIN

USE BaseballData
--UNION -> 디자인이 같아야함
-- players 테이블에서 생일이 1950년도 이상 , 1900년도 이하의 plater들의 모든 정보

--(SELECT *
--FROM players
----WHERE birthYear >= 1950 OR birthYear <= 1900
--WHERE birthYear >= 1950)
--UNION
--(SELECT *
--FROM players
--WHERE birthYear <= 1900)

-- players와 salaries테이블을 보면서 평균 연봉이 300만달러 이상이거나 12월에 태어난 선수들의 playerID를 추출해주세요
-- 중복된다면 중복 허용 (UNION ALL)
--(SELECT playerID
--FROM players
--WHERE birthMonth = 12 AND playerID IS NOT NULL)
--UNION ALL
--(SELECT playerID
--FROM salaries
--GROUP BY playerID
--HAVING AVG(salary) >= 3000000
--)

--JOIN

--CROSS JOIN 
--SELECT *
--FROM
--((SELECT * 
--FROM players
--WHERE lahmanID <=10)T0
--CROSS JOIN
--(SELECT *
--FROM batting
--WHERE HR > 55)T1)

--INNER JOIN

--SELECT *
--FROM players AS pTable
--INNER JOIN
--(SELECT *
--FROM batting
--WHERE HR > 20)AS bTable
--ON pTable.playerID = bTable.playerID
----batting AS bTable
----ON pTable.playerID = bTable.playerID AND bTable.HR > 20

--OUTER JOIN

--LEFT JOIN , RIGHT JOIN
SELECT *
FROM
(SELECT playerID , AVG(HR) AS HOMERUN
FROM batting
GROUP BY playerID) AS bTable
LEFT JOIN
(SELECT lahmanID,playerID , nameFirst , nameLast
FROM players) AS pTable
ON bTable.playerID = pTable.playerID
--LEFT JOIN 왼쪽에 정보가 있고 오른쪽에 없다 -> NULL 표시
--LEFT JOIN 왼쪽에 정보가 없고 오른쪽에 있다 -> 표시X

--프로그래머스
--있었는데요 없었습니다
--없어진 기록 찾기
--오랜 기간 보호한 동물(1)
--보호소에서 중성화한 동물
--5월 식품들의 총매출 조회하기
--그룹별 조건에 맞는 식당 목록 출력하기