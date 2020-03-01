#include <iostream>

using namespace std;

#include <gui.h>

float esferaX = -1;

Model3DS modelo3ds = Model3DS("/home/oem/Desktop/CG/00 BASE - PROJETO GRAFICO E INSTALACOES/00_projeto inicial com camera/GLUTdoZero20201/3ds/cartest.3DS");

void desenha() {
    GUI::displayInit();

    GUI::setLight(0, 0,2,0, true, false);

    //referencia (sistema de coordenadas global)
    GUI::drawOrigin(0.5);

    GUI::setColor(1,0,0);
    GUI::drawFloor();

    GUI::setColor(0,1,0, 0.5);
    GUI::drawSphere(glutGUI::tx,1,0, 0.3);

    //GUI::setColor(0,0,1);
    //GUI::drawBox(-5,-5,-2, 5,5,2, true);

    GUI::setColor(0,0,1);
    GUI::draw3ds(modelo3ds,-1,0,1);


    GUI::setColor(0,0,1);
    GUI::drawBox(1,1,-2, 2,2,-1);

    glBegin(GL_POLYGON);
        glNormal3f(0,0,1);
        glVertex3f(1,0,0);
        glVertex3f(1,1,0);
        glVertex3f(0,1,0);
        glVertex3f(0,0,0);
    glEnd();

    GUI::displayEnd();
}


void teclado(unsigned char tecla, int x, int y) {
    GUI::keyInit(tecla,x,y);

    switch (tecla) {
    case 'l':
        glutGUI::trans_luz = !glutGUI::trans_luz;
        break;
    case 't':
        glutGUI::trans_obj = !glutGUI::trans_obj;
        break;

    case 'a':
        esferaX -= 0.1;
        break;
    case 'd':
        esferaX += 0.1;
        break;

    default:
        break;
    }
}

int main()
{
    cout << "Hello World!" << endl;

    GUI gui = GUI(800,600,desenha,teclado);
}

//inicializando OpenGL
//while(true) {
//    desenha();
//    interacaoUsuario();
//}
