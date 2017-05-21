#pragma once
#include "DriverOperator.h"
#include "DriverDataDefine.h"
#include "ListContainer.h"


class CObjectInterface:public CDriverMem
{
public:
	CObjectInterface(CListContainer *pList);
	virtual ~CObjectInterface( );

public:
	virtual bool init( );
	virtual void Release( );
	virtual bool InsertDataList( const BYTE *pData );
	virtual BYTE *GetDataBuffer( UINT32 nLength );
	virtual void FreeDataBuffer( BYTE *pData );
	virtual void ProcessMonitorData(const PVOID handle, const PVOID pCreateinfo);//���̴����˳���Ϊ

	virtual void RegisterMonitorData( REG_NOTIFY_CLASS regType, const PVOID pData );//ע���
	
	virtual void NetMonitorData( const FWPS_INCOMING_VALUES  *inFixedValues, const FWPS_INCOMING_METADATA_VALUES  *inMetaValues, PVOID pNetrData, OUT FWPS_CLASSIFY_OUT  *classifyOut, DataType eType );//����
	virtual void FileMonitorData( PFLT_CALLBACK_DATA  pData, PCFLT_RELATED_OBJECTS FltObjects, PVOID *CompletionContext, bool bPre );//�ļ�

protected:
	CListContainer *m_pListContainer;
};
