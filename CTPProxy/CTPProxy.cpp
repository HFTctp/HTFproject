// CTPProxy.cpp : ���� DLL Ӧ�ó���ĵ���������
//

#include "stdafx.h"
#include "CTPProxy.h"
//1.����.h
#include "ThostFtdcMdApi.h"

//�����Ǵ�CTPProxy.dll������
//2.�̳�Spi
class CTPPROXY_API CCTPProxy : CThostFtdcMdSpi {
public:
	CCTPProxy(void);
	//TODO:�ڴ�������ķ���

	//3.ʵ��Spi��������������֮���滻"{};"Ϊ";"
	///���ͻ����뽻�׺�̨������ͨ������ʱ����δ��½ǰ�����÷���������
	virtual void OnFrontConnected();
};

// ���ǵ���������һ��ʾ��
CTPPROXY_API int nCTPProxy=0;

// ���ǵ���������һ��ʾ����
CTPPROXY_API int fnCTPProxy(void)
{
	return 42;
}

//4.������Ӧ����
typedef int (WINAPI *CBOnFrontConnected)(void);

//5.������Ӧ����
CBOnFrontConnected cbOnFrontConnected = 0;

// �����ѵ�����Ĺ��캯����
// �й��ඨ�����Ϣ������� CTPProxy.h
CCTPProxy::CCTPProxy()
{
	return;
}

//6.ע��ͻ�����Ӧ
CTPPROXY_API void WINAPI RegOnFrontConnected(CBOnFrontConnected cb)
{
	cbOnFrontConnected = cb;
}

void CCTPProxy :: OnFrontConnected()
{
	//7.���ÿͻ�����Ӧ
	if (cbOnFrontConnected != NULL)
	{
		cbOnFrontConnected();
	}
}

//ָ���װ
CTPPROXY_API void RegConnect()
{

}
