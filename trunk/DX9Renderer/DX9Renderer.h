// ���� ifdef ���Ǵ���ʹ�� DLL �������򵥵�
// ��ı�׼�������� DLL �е������ļ��������������϶���� DX9RENDERER_EXPORTS
// ���ű���ġ���ʹ�ô� DLL ��
// �κ�������Ŀ�ϲ�Ӧ����˷��š�������Դ�ļ��а������ļ����κ�������Ŀ���Ὣ
// DX9RENDERER_API ������Ϊ�Ǵ� DLL ����ģ����� DLL ���ô˺궨���
// ������Ϊ�Ǳ������ġ�
#ifdef DX9RENDERER_EXPORTS
#define DX9RENDERER_API __declspec(dllexport)
#else
#define DX9RENDERER_API __declspec(dllimport)
#endif

// �����Ǵ� DX9Renderer.dll ������
class DX9RENDERER_API CDX9Renderer {
public:
	CDX9Renderer(void);
	// TODO: �ڴ�������ķ�����
};

extern DX9RENDERER_API int nDX9Renderer;

DX9RENDERER_API int fnDX9Renderer(void);
