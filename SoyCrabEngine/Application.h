#include "SoyCrabEngine.h"
#include <cstdlib>

class Application
{
protected:
    //���� â ����
    int height;
    //���� â ����
    int width;

public:
    //â Ÿ��Ʋ �̸�
    virtual const char* getTitle();

    //�׷��� ���̺귯�� �ʱ�ȭ
    virtual void initGraphics();

    //FOV ������Ʈ
    virtual void setView();

    //�ν��Ͻ� �ı�
    virtual void deinit();

    //������
    virtual void display();

    //������Ʈ
    virtual void update();

    //Ű�Է�
    virtual void key(unsigned char key);

    //������ ������ ����
    virtual void resize(int width, int height);

    //���콺 �Է�
    virtual void mouse(int button, int state, int x, int y);

    //���콺 �巹�� �Է�
    virtual void mouseDrag(int x, int y);

    //�ؽ�Ʈ ����
    void renderText(float x, float y, const char *text, void* font=NULL);
};