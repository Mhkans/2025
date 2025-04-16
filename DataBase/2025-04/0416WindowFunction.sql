USE BaseballData
--Window 함수
-- ~OVER([Partition]) [Order By] [Rows]
--        서브셋       정렬       범위

select * , 
ROW_NUMBER() OVER(ORDER BY salary DESC) AS rowNum,
RANK() OVER(ORDER BY salary DESC) AS ranking,
DENSE_RANK() OVER(ORDER BY salary DESC) AS denseRank,
NTILE(100) OVER(ORDER BY salary DESC) AS percentage

FROM salaries
-- 같은 플레이어 안에서 순위를 매기기
Select * ,
RANK() Over(partition By playerID ORDER By salary DESC)
FROM salaries

--LAG(바로 이전) LEAD(바로 다음)
Select * ,
RANK() Over(partition By playerID ORDER By salary DESC) AS Ranking,
LAG(salary) OVER(partition By playerID ORDER by salary DESC) AS PREV,
LEAD(salary) OVER(partition By playerID ORDER by salary DESC) AS NEXT

FROM salaries
--FIRST_VALUE , LAST_VALUE (범위설정)
SELECT *, 
RANK() OVER(PARTITION By playerID ORDER BY salary DESC) AS RANKIng,
FIRST_VALUE(salary) OVER(PARTITION By PlayerID ORDER BY salary DESC ROWS BETWEEN UNBOUNDED PRECEDING AND CURRENT ROW) AS MAX_SALARY,
LAST_VALUE(salary) OVER(PARTITION By PlayerID ORDER BY salary DESC ROWS BETWEEN CURRENT ROW AND UNBOUNDED FOLLOWING) AS MIN_SALARY
FROM salaries
