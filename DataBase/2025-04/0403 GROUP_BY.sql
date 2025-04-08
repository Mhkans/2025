USE BaseballData
--GROUP BY
--집계함수
--COUNT , AVG , SUM  ,MIN ,MAX
--HAVING


-- FROM WHERE GROUP BY HAVING SELECT ORDER BY

--players 테이블에서 국가별로 몇명의 선수들이 있었는지 -> GROUP BY 분류  , 집계함수
--SELECT COUNT(lahmanID) as Count , birthCountry as Country
--FROM dbo.players
--
--GROUP BY birthCountry
--
----players 테이블에서 국가별로 몇명의 현존하는 선수들이 있는지
--SELECT COUNT(lahmanID) as Count , birthCountry as Country
--FROM dbo.players
--WHERE deathYear IS NULL
--GROUP BY birthCountry

----players 테이블에서 국가별로 몇명의 현존하는 선수들이 있는지 출력할때 COUNT가 10명 이상인 것들만 출력
--SELECT COUNT(lahmanID) as Num , birthCountry as Country
--FROM dbo.players
--WHERE deathYear IS NULL
--GROUP BY birthCountry
--HAVING COUNT(lahmanID) > 10


--salaries 테이블에서 팀별로 salary의 총합을 출력해주세요
--SELECT SUM(CAST(salary AS BIGINT)) , teamID
--FROM dbo.salaries
--GROUP BY teamID

--salaries 테이블에서 팀별로 salary의 평균을 출력해주세요
--SELECT AVG(CAST(salary AS BIGINT)) , teamID
--FROM dbo.salaries
--GROUP BY teamID

--salaries 테이블에서 연도별로 최고의 salary와 최저의 salary를 출력해주세요
SELECT MIN(salary)AS minSalary ,MAX(salary) AS maxSalary, yearID
FROM dbo.salaries
GROUP BY yearID


--프로그래머스
--고양이와 개는 몇마리 있을까
--동명 동물 수 찾기
--입양 시각 구하기
--가격대 별 상품개수 구하기
--진료과별 총 예약 횟수 출력하기
--자동차 종류 별 특정 옵션이 포함된 자동차 수 구하기