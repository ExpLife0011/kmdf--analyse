#pragma once
/*****
��ģ�������ݻ�ȡģ�� ���ں��²���������� ��ȡ�����ɼ�������
******/
#include "UserDataDefine.h"
interface IIinterfaceModel
{
public:
	virtual BOOL DeviceControl( DWORD IoControlCode, PVOID pData, DataType eType = DataType::DATA_TYPE_MIN ) = 0;
	virtual BOOL ReadData( ) = 0;
	virtual BOOL WriteData( PVOID pData ) = 0;
	virtual void CloseDevice( ) = 0;
	virtual BOOL CreateDevice( ) = 0;
};