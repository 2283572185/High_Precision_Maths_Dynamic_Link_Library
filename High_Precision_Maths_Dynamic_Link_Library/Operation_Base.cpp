#include "Operation_Base.h"
#define _10 ':'

void position_point(Operand_Base& value)
{
	char _point = '.';
	char _0 = '0';
	unsigned long long max = value.data.size();
	while (true)
	{
		//����С���㿪ͷ����ǰ�油��һ��0
		if (value.point == 0 && value.data[value.point] == '.') {
			value.data.insert(value.data.begin(), _0);
			break;
		}
		//����С�����β������󲹳�һ��0
		else if (value.point == max - 1 && value.data[value.point] == '.') {
			value.data.push(_0);
			break;
		}
		//��û��С���㣬�򲹳�С�����0
		else if (value.point == max - 1 && value.data[value.point] != '.') {
			value.data.push(_point);
			value.data.push(_0);
			break;
		}
		//������С���㣬����
		else if (value.data[value.point] == '.') {
			break;
		}
		else
		{
			value.point++;
		}
	}
	return;
}

void high_precision_add(char& left, char& right, Result& _result)
{
	//���֮ǰ���ڽ�λ������������ϼ�һ
	if (_result.change == '1') {
		left++;
	}
	//���������������Ӵ���9����λ��ֵ1�����Ϊ�ͼ�10
	if (left + right > '9') {
		_result.result = left + right - _10;
		_result.change = '1';
	}
	//��������λ��ֵ0�����Ϊ��
	else
	{
		_result.result = left + right;
		_result.change = '0';
	}
	return;
}

void decimal_point(Operand_Base& left, Operand_Base& right)
{
	//����ǰ����
	char _0 = '0';
	unsigned long long i, need;
	if (left.point > right.point) {
		need = left.point - right.point;
		Value<char>* begin = right.data.begin();
		for (i = 0; i < need; i++) {
			right.data.insert(begin, _0);
		}
	}
	else
	{
		need = right.point - left.point;
		Value<char>* begin = left.data.begin();
		for (i = 0; i < need; i++) {
			left.data.insert(begin, _0);
		}
	}
	//�������
	if (left.data.size() > right.data.size()) {
		need = left.data.size() - right.data.size();
		for (i = 0; i < need; i++) {
			right.data.push(_0);
		}
	}
	else
	{
		need = right.data.size() - left.data.size();
		for (i = 0; i < need; i++) {
			left.data.push(_0);
		}
	}
}
