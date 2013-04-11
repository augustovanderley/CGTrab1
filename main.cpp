#include <URGE/URGE.h>

USING_URGE;

URGE_BEGIN
{
    //new window: RX, RY, RENDER QUALITY LEVEL, PARAMS, WINDOW TITTLE,
    gimme_window(800,600, RENDER_QUALITY_PERFECT, WINDOWED, "URGE Application");
    Scenario cenario;
    FirstPersonCamera camera;
    Terrain terreno;
    Light luz;
    Sky ceu;

    luz.point();
    luz.position(0,25,0);
    luz.intensity(5);
    camera.position(0,20,0);
    camera.activeBody();
    terreno.load ("media/terrain/heightmap.jpg", 0, 25, 100, 100, "media/tex/terrain.jpg");
    ceu.loadTexture("media/sky/cloudy");

    cenario.insert(camera);
    cenario.insert(terreno);
    cenario.insert(luz);
    cenario.insert(ceu);

    cenario.prepare();
    do
    {
        if(Keyboard::hit(Keyboard::ESC))  break;
        cenario.update();

        next_frame();
    } while(true);

    thanks_byebye();
}
URGE_END
