USE BaseballData;
-- * : ALL

--SELECT players.birthYear
--FROM���� �д´� -> birthYear�� �ᵵ �����ϰ� ����

--�ؼ�
--FROM : � ���̺��� �����ð���
--WHERE
--SELECT : ����
--ORDER BY 

--ASC : ��������
--EESC : ��������

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

--DATABASE �� ��������
--DATABASE�� �� ������
--DATABASE ���� 2���� �̻� ���� , ������ DB�� ���ؼ� �����ϱ�

--�⺻Ű�� ��������
--Clustered Index �� Non Clustered Index �� ��������
--Clustered Index �ڷᱸ�� , Non Clustered Index �ڷᱸ��

--���α׷��ӽ�
--��� ���ڵ� ��ȸ�ϱ�
--������ ���̵�� �̸�
--���ǿ� �´� ȸ���� ���ϱ�
--����� ã��
--���µ��� ã��
--���� �����ϱ�
--���� n�� ���ڵ� (LIMIT���)

