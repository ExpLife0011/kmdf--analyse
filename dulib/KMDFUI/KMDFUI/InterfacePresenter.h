#pragma once
#include "InterfaceView.h"
#include "interfaceModel.h"
/*
��ģ��Ϊ�߼�����ģ�� ���ڴ����modelȡ������ �����ӹ������ ���������͸�view��չʾ
*/
interface IInterfacePresenter
{
public:
	IInterfacePresenter() 
	{
		m_pInterView = nullptr;
		m_pInterModel = nullptr;
	};
	virtual ~IInterfacePresenter()
	{
		ReleaseData( );
		m_pInterView = nullptr;
		m_pInterModel = nullptr;
	};

public://model 
	virtual void InitView( IInterfaceView *pView ) { m_pInterView = pView; };
	virtual void InitModel( IIinterfaceModel *pModel ) { m_pInterModel = pModel; };
	virtual void ReleaseData( ) {};
	
	//����
	virtual void LoadProcessData( UINT32 uProcessId ) {};//view
	virtual void ProcessCreateData( ProcessCreate *pData ) {};//model
	//ע���
	virtual void ProcessRegisterData( RegisterMonitor *pData ) {}
	//����
	virtual void ProcessNetData( NetMonitor *pData ) {};
	//�ļ�
	virtual void ProcessFileData( FileMonitor *pData ) { };
protected:
	IInterfaceView *m_pInterView = nullptr;
	IIinterfaceModel *m_pInterModel = nullptr;
};