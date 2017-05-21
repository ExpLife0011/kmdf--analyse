#pragma once
//#pragma pack(push,1)
//#pragma pack(pop)
#ifdef DRIVER_DATA
#include <ntdef.h>
#else
#include <winioctl.h>
#endif

#pragma pack(1) //�����Զ������ݽṹ�Ķ��뷽ʽ

// {204977AC-1434-4AC4-B27F-8DB906FE3D9B} //
DEFINE_GUID( CallOutTCPUDPConnect_V4, 0x204977ac, 0x1434, 0x4ac4, 0xb2, 0x7f, 0x8d, 0xb9, 0x6, 0xfe, 0x3d, 0x9b );
// {4FA12EDB-2AFC-4C8D-824A-28564361FFB6}
DEFINE_GUID( CallOutTCPUDPBind_V4, 0x4fa12edb, 0x2afc, 0x4c8d, 0x82, 0x4a, 0x28, 0x56, 0x43, 0x61, 0xff, 0xb6 );

#define NetMonitorCallbackIDNum 2 

#define IOCTL_READ_DATA	 CTL_CODE( FILE_DEVICE_UNKNOWN, 0x1100, METHOD_OUT_DIRECT,FILE_READ_ACCESS )
#define IOCTL_WRITE_DATA  CTL_CODE( FILE_DEVICE_UNKNOWN, 0x1101, METHOD_IN_DIRECT,FILE_WRITE_ACCESS )


enum DataType:UINT32
{
	DATA_TYPE_MIN = 0,
	DATA_TYPE_PROCESS_START,
	DATA_TYPE_PROCESS_Create,//���̴���
	DATA_TYPE_PROCESS_Exit,//�����˳�
	DATA_TYPE_PROCESS_END,
	
	DATA_TYPE_REGISTER_START,//ע���
	DATA_TYPE_REGISTER_CreateKey,
	DATA_TYPE_REGISTER_CreateKeyEX,
	DATA_TYPE_REGISTER_DeleteKey,
	DATA_TYPE_REGISTER_SetValueKey,
	DATA_TYPE_REGISTER_DeleteValueKey,
	DATA_TYPE_REGISTER_QueryKey,
	DATA_TYPE_REGISTER_QueryValueKey,
	DATA_TYPE_REGISTER_OpenKey,
	DATA_TYPE_REGISTER_OpenKeyEx,
	DATA_TYPE_REGISTER_END,
	
	DATA_TYPE_FILE_START,
	DATA_TYPE_FILE_Create,//�ļ�����
	DATA_TYPE_FILE_Create_Dir,
	DATA_TYPE_FILE_Write,
	DATA_TYPE_FILE_Read,
	DATA_TYPE_FILE_Set_Information,
	DATA_TYPE_FILE_Delete,
	DATA_TYPE_FILE_Rename,
	DATA_TYPE_FILE_Open,
	DATA_TYPE_FILE_Open_Dir,
	DATA_TYPE_FILE_Close,
	DATA_TYPE_FILE_END,

	DATA_TYPE_NET_START,//����
	DATA_TYPE_NET_Connect,
	DATA_TYPE_NET_Bind,
	DATA_TYPE_NET_DNS,
	DATA_TYPE_NET_END,
	DATA_TYPE_MAX
};

enum RegDataType :UINT32
{
	REGDATATYPE_Min = 0,//REG_NONE( 0ul ) // No value type (0-11) Ϊϵͳ�����ע����ֵ���� 20�Ժ��ֵ�Զ�������

    //DATA_TYPE_REGISTER_QueryKeyʱʹ��
	REGDATATYPE_BasicClassInfo = 20, //��ʱRegisterData��uRegDataOffset��������Ϣ���ݸ�ʽΪ KEY_BASIC_INFORMATION 
	REGDATATYPE_NodeClassInfo,//PKEY_NODE_INFORMATION 
	REGDATATYPE_FullClassInfo,//KEY_FULL_INFORMATION
	REGDATATYPE_NameClassInfo,// KEY_NAME_INFORMATION
	REGDATATYPE_CachedClassInfo,// KEY_CACHED_INFORMATION
	REGDATATYPE_FlagsClassInfo,//Reserved for system use.
	REGDATATYPE_VirtualizationClassInfo,// KEY_VIRTUALIZATION_INFORMATION
	REGDATATYPE_HandleTagsClassInfo,//Reserved for system use.

	//DATA_TYPE_REGISTER_QueryValueKeyʹ��
	REGDATATYPE_KeyValueBasic,
	REGDATATYPE_KeyValueFull,
	REGDATATYPE_KeyValuePartial,
	REGDATATYPE_KeyValueFullAlign64,
	REGDATATYPE_KeyValuePartialAlign64,

	REGDATATYPE_Max
};

typedef struct UNIT_Flag
{
#ifdef DRIVER_DATA
	LIST_ENTRY ListEntry;
#endif

	DataType eType;//��������
	UINT32 nLength;//���ݳ���
}UNIT_FLAG;
typedef UNIT_FLAG* PUNIT_FLAG;

typedef struct ProcessData
{
	UNIT_FLAG unit;
	UINT32 uProceId;
	UINT32 uTimes;
	UINT32 uParentId;
	UINT32 uCMDLineOffset;
	UINT32 uProcessFileOffset;
	UINT32 uParentFileOffset;

}PROCESS_DATA;
typedef PROCESS_DATA* PPROCESS_DATA;

typedef struct RegisterData 
{
	UNIT_FLAG unit;
	UINT32 uProceId;
	UINT32 uTimes;
	RegDataType eRegType;
	UINT32 uDataLength;
	UINT32 uRegPathOffset;
	UINT32 uRegNameOffset;
	UINT32 uRegDataOffset;
}REGISTER_DATA;
typedef REGISTER_DATA* PREGISTER_DATA;

typedef struct NetWorkMonitor
{
	UNIT_FLAG unit;
	UINT32 uProceId;
	UINT32 uTimes;
	UINT16 uDirection;//���ݴ���ķ���
	UINT16 uProto;//����Э�� tcp udp IPPROTO
	UINT16 uSrcPort;
	UINT32 uSrcIP;
	UINT16 uDesPort;
	UINT32 uDesIP;
	UINT32 uDataLength;
	UINT32 uNetDataOffset;
}NETWORKMONITOR_DATA;
typedef NETWORKMONITOR_DATA* PNETWORKMONITOR_DATA;

enum FileDataType :UINT32
{
	FILE_DATATYPE_min = 0,
	
	FILE_DATATYPE_FileAllocationInformation,//DATA_TYPE_FILE_Set_Information
	FILE_DATATYPE_FileBasicInformation,
	FILE_DATATYPE_FileDispositionInformation,
	FILE_DATATYPE_FileEndOfFileInformation,
	FILE_DATATYPE_FileLinkInformation,
	FILE_DATATYPE_FilePositionInformation,
	FILE_DATATYPE_FileRenameInformation,
	FILE_DATATYPE_FileValidDataLengthInformation,

	FILE_ATTRIBUTE_Max
};
typedef struct FileOperationMonitor
{
	UNIT_FLAG unit;
	UINT32 uProceId;
	UINT32 uTimes;
	UINT32 uFileAttribute;
	FileDataType eAttType;
	UINT32 uFileNameOffset;
	UINT32 uDatalength;
	UINT32 uDataOffset;
}FILEOPERATIONMONITOR_DATA;
typedef FILEOPERATIONMONITOR_DATA* PFILEOPERATIONMONITOR_DATA;

#pragma pack()

