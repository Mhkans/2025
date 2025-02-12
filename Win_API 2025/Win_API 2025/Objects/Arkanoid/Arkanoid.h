#pragma once
#define X_COUNT 11
#define Y_COUNT 5
class Arkanoid
{
public:
	Arkanoid();
	~Arkanoid();

	void Update();
	void Render(HDC hdc);

	void CreateArkanoid();
	void SetItemBricks(const int num);

	void SetInit();
private:
	
private:
	vector<vector<shared_ptr<class Brick>>> _bricks;
	float _xDistance = 160.0f;
	float _yDistance = 25.0f;
	
	shared_ptr<class Paddle> _paddle;
	unordered_map<int, bool> um; //������ ���� , �����ۺ�� ���� ����
	shared_ptr<class A_ball> _ball;

	bool _isFired = false;

	vector<shared_ptr<CircleCollider>> _life;
	int _lifeCount = 3;
	HBRUSH _brush;
};
//��ī���̵带 ��ġ�ϴ� Ŭ����
//�긯���� �������̸� ���⼭ ������ ������ ȹ��
//������ġ �ݻ�ó�� -> ball �������� ���������� �ݹ� �е鿡 �� ���ġ 

//�е鿡 ��� ��ġ�� ������ ���� ���� ���� 
