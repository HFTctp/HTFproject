// ���� ifdef ���Ǵ���ʹ�� DLL �������򵥵�
// ��ı�׼�������� DLL �е������ļ��������������϶���� CTPPROXY_EXPORTS
// ���ű���ġ���ʹ�ô� DLL ��
// �κ�������Ŀ�ϲ�Ӧ����˷��š�������Դ�ļ��а������ļ����κ�������Ŀ���Ὣ
// CTPPROXY_API ������Ϊ�Ǵ� DLL ����ģ����� DLL ���ô˺궨���
// ������Ϊ�Ǳ������ġ�
#ifdef CTPPROXY_EXPORTS
#define CTPPROXY_API __declspec(dllexport)
#else
#define CTPPROXY_API __declspec(dllimport)
#endif

// �����Ǵ� CTPProxy.dll ������
class CTPPROXY_API CCTPProxy {
public:
	CCTPProxy(void);
	// TODO: �ڴ�������ķ�����
};

extern CTPPROXY_API int nCTPProxy;

CTPPROXY_API int fnCTPProxy(void);
