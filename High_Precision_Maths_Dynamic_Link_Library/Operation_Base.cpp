#include "Operation_Base.h"
constexpr auto _10 = ':';
using namespace High_Precision_Maths_Library;
void High_Precision_Maths_Library::position_point(Operand_Base& value)
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
			value.data.push_back(_0);
			break;
		}
		//��û��С���㣬�򲹳�С�����0
		else if (value.point == max - 1 && value.data[value.point] != '.') {
			value.data.push_back(_point);
			value.data.push_back(_0);
			value.point++;
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

void High_Precision_Maths_Library::high_precision_add(char& left, char& right, Result& _result)
{
	//�����С���㣬ֱ�ӷ���
	if (left == '.' || right == '.') {
		_result.result = '.';
		return;
	}
	//���֮ǰ���ڽ�λ������������ϼ�һ
	if (_result.change == '1') {
		left++;
	}
	//���������������Ӵ���9����λ��ֵ1�����Ϊ�ͼ�10
	if (left + right - '0' > '9') {
		_result.result = left + right - _10;
		_result.change = '1';
	}
	//��������λ��ֵ0�����Ϊ��
	else
	{
		_result.result = left + right - '0';
		_result.change = '0';
	}
	return;
}

void High_Precision_Maths_Library::decimal_point(Operand_Base& left, Operand_Base& right)
{
	//����ǰ����
	char _0 = '0';
	unsigned long long i, need;
	if (left.point > right.point) {
		need = left.point - right.point;
		for (i = 0; i < need; i++) {
			right.data.insert(right.data.begin(), _0);
		}
		right.point += need;
	}
	else
	{
		need = right.point - left.point;
		for (i = 0; i < need; i++) {
			left.data.insert(left.data.begin(), _0);
		}
		left.point += need;
	}
	//�������
	if (left.data.size() > right.data.size()) {
		need = left.data.size() - right.data.size();
		for (i = 0; i < need; i++) {
			right.data.push_back(_0);
		}
	}
	else
	{
		need = right.data.size() - left.data.size();
		for (i = 0; i < need; i++) {
			left.data.push_back(_0);
		}
	}
}

Operand_Base High_Precision_Maths_Library::Addition(Operand_Base& left, Operand_Base& right)
{
	position_point(left);
	position_point(right);
	decimal_point(left, right);
	unsigned long long max = left.data.size();
	Result _result;
	Operand_Base result;
	result.data.push_back((char&)_10);
	while (true)
	{
		if (max == 0) {
			break;
		}
		high_precision_add(left.data[max - 1], right.data[max - 1], _result);
		result.data.insert(result.data.begin(), _result.result);
		max--;
	}
	result.data.pop();
	if (_result.change == '1') {
		result.data.insert(result.data.begin(), _result.change);
	}
	position_point(result);
	return result;
}
