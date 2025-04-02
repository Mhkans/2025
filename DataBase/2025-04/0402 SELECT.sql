USE BaseballData;
-- * : ALL

--SELECT players.birthYear
--FROM부터 읽는다 -> birthYear만 써도 동일하게 동작

--해석
--FROM : 어떤 테이블에서 가져올건지
--WHERE
--SELECT : 추출
--ORDER BY 

--ASC : 오름차순
--EESC : 내림차순

--SELECT TOP(100) playerID AS ID , birthYear
--
--FROM dbo.players
--
--WHERE birthYear > 1950 AND birthMonth = 7 AND birthCountry = 'USA'
--
--ORDER BY ID ASC
--
SELECT *

FROM dbo.players

WHERE birthYear > 1950 AND birthMonth = 7 AND birthCountry = 'USA' AND (deathYear IS NOT NULL)

ORDER BY playerID ASC

--DATABASE 가 무엇인지
--DATABASE를 왜 쓰는지
--DATABASE 종류 2가지 이상 쓰고 , 관계형 DB에 대해서 조사하기

--기본키가 무엇인지
--Clustered Index 와 Non Clustered Index 가 무엇인지
--Clustered Index 자료구조 , Non Clustered Index 자료구조

--프로그래머스
--모든 레코드 조회하기
--동물의 아이디와 이름
--조건에 맞는 회원수 구하기
--어린동물 찾기
--아픈동물 찾기
--역순 정렬하기
--상위 n개 레코드 (LIMIT사용)

