// CTPProxy.cpp : 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"
#include "CTPProxy.h"
//1.引入.h
#include "ThostFtdcMdApi.h"

//此类是从CTPProxy.dll导出的
//2.继承Spi
class CTPPROXY_API CCTPProxy : CThostFtdcMdSpi {
public:
	CCTPProxy(void);
	//TODO:在此添加您的方法

	//3.实现Spi函数（拷贝过来之后，替换"{};"为";"
	///当客户端与交易后台建立起通信连接时（还未登陆前），该方法被调用
	virtual void OnFrontConnected();
};

// 这是导出变量的一个示例
CTPPROXY_API int nCTPProxy=0;

// 这是导出函数的一个示例。
CTPPROXY_API int fnCTPProxy(void)
{
	return 42;
}

//4.定义响应类型
typedef int (WINAPI *CBOnFrontConnected)(void);

//5.定义响应变量
CBOnFrontConnected cbOnFrontConnected = 0;

// 这是已导出类的构造函数。
// 有关类定义的信息，请参阅 CTPProxy.h
CCTPProxy::CCTPProxy()
{
	return;
}

//6.注册客户端响应
CTPPROXY_API void WINAPI RegOnFrontConnected(CBOnFrontConnected cb)
{
	cbOnFrontConnected = cb;
}

void CCTPProxy :: OnFrontConnected()
{
	//7.调用客户端响应
	if (cbOnFrontConnected != NULL)
	{
		cbOnFrontConnected();
	}
}

//指令封装
CTPPROXY_API void RegConnect()
{

}
