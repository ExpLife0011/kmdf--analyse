#pragma once
#include "ObjectInterface.h"
class CFileMonitor :public CObjectInterface
{
public:
	CFileMonitor( CListContainer *pList );
	virtual ~CFileMonitor( );

public:
	virtual bool init( );
	virtual void Release( );
	virtual void FileMonitorData( PFLT_CALLBACK_DATA  pData, PCFLT_RELATED_OBJECTS FltObjects, PVOID *CompletionContext, bool bPre );
protected:

	void PreFileMonitorData( PFLT_CALLBACK_DATA  pData );
	void PostFileMonitorData( PFLT_CALLBACK_DATA  pData ); //��ѯ�ļ���ϢʱҪ�õ�post���� ��Ϊ��postʱ�Ѿ�����ļ�����Ϣ��ѯ ��ʱ��paramter���в�ѯ������

	bool GetDataTypeByIoParameter(const PFLT_IO_PARAMETER_BLOCK  pData, DataType &eType, FileDataType &eFileType, UINT32 &uFileAttribute,BYTE *&pRetrnData,UINT32 &uReturnLegth );
	void AnalyseFileData( PFLT_CALLBACK_DATA  pData );
	void FormatFileMonitorData( UNICODE_STRING &pFileName,DataType eType, FileDataType eFileType, UINT32 uFileAttribute,BYTE *pData = nullptr, UINT32 uDataLength  = 0);
private:
	PFLT_FILTER m_pFileRegFilter;
};