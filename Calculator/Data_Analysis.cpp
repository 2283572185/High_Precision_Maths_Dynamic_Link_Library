#include "pch.h"
#include "Data_Analysis.h"

bool check_bracket(CString& value)
{
	int left = 0;
	int max = value.GetLength();
	//��¼(�ĸ���
	for (int i = 0; i < max; i++) {
		if (value[i] == '(') {
			left++;
		}
	}
	int right = 0;
	//��¼)�ĸ���
	for (int i = 0; i < max; i++) {
		if (value[i] == ')') {
			right++;
		}
	}
	if (left == right) {
		return true;
	}
	else
	{
		return false;
	}
}

bool check_operator(CString& value)
{
	/*�ж��Ƿ�Ϸ��ı�׼��
		+-/*^�����໥�Ӵ�
		/*^����������ٿ�ͷ
		��)�ⲻ���ڽ�β����
		.ǰ�����������
		��ǰ�����ֲ�����С��
	*/
	// �Բ��Ϸ����������ͷ������false
	if (value[0] == '*' || value[0] == '/' || value[0] == '^' || value[0] == '.') {
		return false;
	}
	int max = value.GetLength();
	// ��β�ַ�����)�����֣�����false
	if (value[max - 1] != ')' && value[max - 1] != '1' && value[max - 1] != '2' && value[max - 1] != '3'
		&& value[max - 1] != '4' && value[max - 1] != '5' && value[max - 1] != '6' && value[max - 1] != '7'
		&& value[max - 1] != '8' && value[max - 1] != '9' && value[max - 1] != '0') {
		return false;
	}
	// �ж�������Ƿ��в��Ϸ��ĽӴ�
	for (int i = 0; i < max - 1; i++) {
		// ���������������������������ж�
		if (value[i] == '+' || value[i] == '-' || value[i] == '*' || value[i] == '/' || value[i] == '^') {
			// ��������������Ӵ�������false
			if (value[i + 1] == '+' || value[i + 1] == '-' || value[i + 1] == '*' || value[i + 1] == '/' || value[i + 1] == '^') {
				return false;
			}
		}
	}
	// Ѱ��.���ж�.�����Ƿ�������
	for (int i = 1; i < max - 1; i++) {

	}
}
