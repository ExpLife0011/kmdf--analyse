#pragma once

#include "DriverDataDefine.h"

enum class PAGE_TYPE :UINT32
{
	PAGE_TYPE_Min = 0,
	PAGE_TYPE_ProcessEnum,
	PAGE_TYPE_ProcessBehaviour,
	PAGE_TYPE_Max
};

struct ProcessCreate
{
	DataType eType;
	UINT32 uParentId;
	UINT32 uProceId;
	UINT32 uTimes;
	CString strCmd;
	CString strProcessFile;
	CString strParentFile;
};
struct RegisterMonitor
{
	DataType eType;
	UINT32 uProceId;
	UINT32 uTimes;
	RegDataType eRegType;
	CString strPath;
	CString strName;
	UINT32 uDataLength;
	BYTE* pbuffdata;
};
struct NetMonitor
{
	DataType eType;
	UINT32 uProceId;
	UINT32 uTimes;
	UINT16 uDirection;//���ݴ���ķ��� 0 out 1 in 2 none
	IPPROTO uProto;//����Э�� tcp udp IPPROTO
	UINT16 uSrcPort;
	CString SrcIP;
	UINT16 uDesPort;
	CString DesIP;
	UINT32 uDataLength;
	BYTE*  pDataBuff;
};

struct FileMonitor
{
	DataType eType;
	UINT32 uProceId;
	UINT32 uTimes;
	UINT32 uFileAttribute;
	FileDataType eAttType;
	CString strFileName;
	UINT32 uDatalength;
	BYTE *pDataBuff;
};