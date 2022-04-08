#include <SFML/Graphics.hpp>
#include <iostream>
#include "Juego.h"
#include "mascota.h"


using namespace std;
int sprite = 0;
int posicionx = 600;
int posiciony = 400;

Juego::Juego(int x, int y, const char *nombre)
{
    sf::RenderWindow window(sf::VideoMode(x,y), nombre);
    {

    }
    while (window.isOpen()) {
        Event evento;
        while (window.pollEvent(evento)) {

            if (evento.type == Event::Closed) {
                window.close();
            }
        }
        window.clear();
        window.display();
    }
}

Juego::Juego() {};

void Juego::Ventana1()
{
    
     _ventana1= new RenderWindow (sf::VideoMode(800, 600), "MASCOTA VIRTUAL");
     _ventana1->setFramerateLimit(60);
    Clock reloj;
    Clock relojAcciones;
    Pusheen_Sprites[0].setPosition(350, 300);

    RectangleShape HambreBar;
    HambreBar.setFillColor(Color::White);
    HambreBar.setSize(Vector2f((float)Back.gethambre()-reloj.getElapsedTime().asMilliseconds(), 20.f));
    HambreBar.setPosition(400, 300);
    HambreBar.setSize(Vector2f((float)Back.gethambre() - 1, 30.f));
    _ventana1->draw(HambreBar);



    Event evento;
    while (_ventana1->isOpen()) {
       
        while (_ventana1->pollEvent(evento)) {

            if (evento.type == Event::Closed) {
               
                _ventana1->close();
                
            }
        }

        Reloj(reloj, relojAcciones);
       
        int hambre = Back.gethambre();
        int suenio = Back.getsuenio();
        int carinio = Back.getCarinio();

        _ventana1->clear();
        Fondo();
        cargarSprites();
       // MostrarEstadistica(hambre, 10);
        //MostrarEstadistica(suenio, 70);
       // MostrarEstadistica(carinio, 140);
        Acciones(relojAcciones);
       
        _ventana1->draw(Pusheen_Sprites[sprite]);
        Barra();
        _ventana1->display();
    }
}

void Juego::Acciones(Clock &reloj) {
   
    if (Mouse::getPosition(*_ventana1).x < 700 && Mouse::getPosition(*_ventana1).x > 590 && Mouse::getPosition(*_ventana1).y < 290 && Mouse::getPosition(*_ventana1).y > 220)
    {
        if (Mouse::isButtonPressed(Mouse::Left)) {
            reloj.restart();
            Pusheen_Sprites[8].setPosition(600, 195);
            sprite = 8;

        }
    }

    MovimientoPersonaje();
    if (Mouse::getPosition(*_ventana1).x < 60 && Mouse::getPosition(*_ventana1).x > 0 && Mouse::getPosition(*_ventana1).y < 310 && Mouse::getPosition(*_ventana1).y > 200) {
        Carteles_Sprites[2].setPosition(0, 155);
        _ventana1->draw(Carteles_Sprites[2]);

        if (Mouse::isButtonPressed(Mouse::Left)) {
            reloj.restart();
            Pusheen_Sprites[7].setPosition(70, 315);
            sprite = 7;

        }
    }



    if (Mouse::getPosition(*_ventana1).x < 590 && Mouse::getPosition(*_ventana1).x > 540 && Mouse::getPosition(*_ventana1).y < 550 && Mouse::getPosition(*_ventana1).y > 510) {
        Carteles_Sprites[0].setPosition(480, 440);
        _ventana1->draw(Carteles_Sprites[0]);

        if (Mouse::isButtonPressed(Mouse::Left))
        {
            reloj.restart();
            Pusheen_Sprites[6].setPosition(670, 430);
            Back.Alimentar();
            sprite = 6;
            cout << "HAMBRE" << Back.gethambre() << endl;
            //_ventana1->draw(Pusheen_Sprites[3]);
        }

    }




    if (Mouse::getPosition(*_ventana1).x <330 && Mouse::getPosition(*_ventana1).x > 265 && Mouse::getPosition(*_ventana1).y < 285 && Mouse::getPosition(*_ventana1).y > 240) {
        Carteles_Sprites[0].setPosition(210, 170);
        _ventana1->draw(Carteles_Sprites[0]);


        if (Mouse::isButtonPressed(Mouse::Left))
        {
            reloj.restart();
            Pusheen_Sprites[3].setPosition(20, 280);
            Back.Alimentar();
            sprite = 3;
            cout << "HAMBRE" << Back.gethambre() << endl;
            //_ventana1->draw(Pusheen_Sprites[3]);
        }




    }
    

    if (Mouse::getPosition(*_ventana1).x < 690 && Mouse::getPosition(*_ventana1).x> 610 && Mouse::getPosition(*_ventana1).y < 480 && Mouse::getPosition(*_ventana1).y > 350) {
        Carteles_Sprites[1].setPosition(575, 250);
        _ventana1->draw(Carteles_Sprites[1]);

        Event::KeyPressed;
        if (Mouse::isButtonPressed(Mouse::Left))
        {

            reloj.restart();
            Pusheen_Sprites[1].setPosition(590, 340);
            sprite = 1;
            Back.Dormir();
            cout << "Sueño: " << Back.getsuenio() << endl;
           // _ventana1->draw(Pusheen_Sprites[1]);
        }
    }

    //_SCarinio->setPosition(600, 400);

    Event::KeyPressed;

    if (Mouse::getPosition(*_ventana1).x  > Pusheen_Sprites[0].getPosition().x && Mouse::getPosition(*_ventana1).x < Pusheen_Sprites[0].getPosition().x+80 && Mouse::getPosition(*_ventana1).y  > Pusheen_Sprites[0].getPosition().y && Mouse::getPosition(*_ventana1).y < Pusheen_Sprites[0].getPosition().y + 80 && sprite == 0) {

        if (Mouse::isButtonPressed(Mouse::Left)) {
     
        reloj.restart();
        Pusheen_Sprites[2].setPosition(190, 450);
        sprite = 2;
        Back.acariciar();
        cout << "Amor " << Back.getCarinio() << endl;
       // _ventana1->draw(Pusheen_Sprites[2]);
    }

    }
    
    //_Seat->setPosition(590, 325);

    if (Back.gethambre() < 10) {
        Pusheen_Sprites[4].setPosition(100, 300);
        sprite = 4;
        //_ventana1->draw(Pusheen_Sprites[4]);

        if (Back.gethambre() > 10) {
            sprite = 0;
        }


    }



   /** if (Back.getCarinio() < 10 || Back.getsuenio() < 10) {

       
        Pusheen_Sprites[5].setPosition(100, 300);
        sprite = 5;
       // _ventana1->draw(Pusheen_Sprites[5]);
        if (Back.getCarinio() > 10) {
            sprite = 0;
        }


    }
    */

}

void Juego::cargarSprites() {

    std::string path;
  
  
    for (int i = 0; i < 3; i++) {
        path = "Imagenes/barra" + to_string(i + 1) + ".png";
        Barras[i].loadFromFile(path);
        Barras_Sprites[i].setTexture(Barras[i]);
    }

    for (int i = 0; i < 9; i++) {
        path = "Imagenes/pusheen" + to_string(i + 1) + ".png";
        Pusheen[i].loadFromFile(path);
        Pusheen_Sprites[i].setTexture(Pusheen[i]);
    }

    for (int i = 0; i < 3; i++) {
        path = "Imagenes/cartel" + to_string(i + 1) + ".png";
        Carteles[i].loadFromFile(path);
        Carteles_Sprites[i].setTexture(Carteles[i]);
    }




}

void Juego::MostrarEstadistica(int estadistica, float Y ) {

    string estadisticaString = to_string(estadistica);
    Font FuenteEstadisticas;
    FuenteEstadisticas.loadFromFile("Estadisticas.otf");
    Text estadisticaTexto;
    estadisticaTexto.setFont(FuenteEstadisticas);
    estadisticaTexto.setString(estadisticaString);
    estadisticaTexto.setCharacterSize(50);
    estadisticaTexto.setFillColor(Color::Black);
    estadisticaTexto.setStyle(Text::Bold);
    estadisticaTexto.setPosition(700, Y);

    _ventana1->draw(estadisticaTexto);
}

void Juego::Reloj(Clock &reloj, Clock &relojacciones) {
    

    Time tiempo = reloj.getElapsedTime();
    Time contador = relojacciones.getElapsedTime();
    if (contador.asSeconds() > 3.f) {
        
        sprite = 0;
        relojacciones.restart();

    }
    if (tiempo.asSeconds() > 1.f)
    {

        Back.sethambre(Back.gethambre() - 1.f);
        if (Back.gethambre()<0)
        {
            Back.sethambre(0);
        }

        Back.setsuenio(Back.getsuenio() - 1);
        if (Back.getsuenio() < 0) {
            Back.setsuenio(0);
        }



        Back.setcarinio(Back.getCarinio() - 1);
        if (Back.getCarinio() < 0) {
            Back.setcarinio(0);
        }


        reloj.restart();
    }


}

void Juego::MovimientoPersonaje() {
    float velocidad = 6;

    if (Keyboard::isKeyPressed(Keyboard::Up)) {
        Pusheen_Sprites[0].move(0, -velocidad);
    }

    if (Keyboard::isKeyPressed(Keyboard::Left)) {
        Pusheen_Sprites[0].move(-velocidad, 0);
    }

    if (Keyboard::isKeyPressed(Keyboard::Down)) {
        Pusheen_Sprites[0].move(0, velocidad);
    }

    if (Keyboard::isKeyPressed(Keyboard::Right)) {
        Pusheen_Sprites[0].move(velocidad, 0);
    }

    if (Pusheen_Sprites[0].getPosition().x < 0) {
        Pusheen_Sprites[0].setPosition(0, Pusheen_Sprites->getPosition().y);
    }
    if (Pusheen_Sprites[0].getPosition().y < 0) {
        Pusheen_Sprites[0].setPosition(Pusheen_Sprites->getPosition().x, 0);
    }

    if (Pusheen_Sprites[0].getPosition().x+Pusheen_Sprites[0].getGlobalBounds().width > 800) {
        Pusheen_Sprites[0].setPosition(800- Pusheen_Sprites[0].getGlobalBounds().width, Pusheen_Sprites->getPosition().y);
    }
 
    if (Pusheen_Sprites[0].getPosition().y + Pusheen_Sprites[0].getGlobalBounds().height > 600) {
        Pusheen_Sprites[0].setPosition(Pusheen_Sprites[0].getPosition().x , 600 - Pusheen_Sprites[0].getGlobalBounds().height);
    }



}

void Juego::Fondo() {
    Texture menu;
    Sprite FondoMenu;


    menu.loadFromFile("Neko.jpg");
    FondoMenu.setTexture(menu);
    _ventana1->draw(FondoMenu);

}

void Juego::Barra() {


    Barras_Sprites[0].setPosition(640,13);
    RectangleShape HambreBar;
    HambreBar.setOutlineColor(Color::Red);
    HambreBar.setFillColor(Color::Black);
    HambreBar.setPosition(700, 20);
    HambreBar.setSize(Vector2f((float)Back.gethambre() - 1, 30.f));

    Barras_Sprites[1].setPosition(635, 60);
    RectangleShape SuenioBar;
    SuenioBar.setOutlineColor(Color::Red);
    SuenioBar.setFillColor(Color::Black);
    SuenioBar.setPosition(700, 80);
    SuenioBar.setSize(Vector2f((float)Back.getsuenio() - 1, 30.f));


    Barras_Sprites[2].setPosition(638, 117);
    RectangleShape CarinioBar;
    CarinioBar.setOutlineColor(Color::Red);
    CarinioBar.setFillColor(Color::Black);
    CarinioBar.setPosition(700, 140);
    CarinioBar.setSize(Vector2f((float)Back.getCarinio() - 1, 30.f));


    _ventana1->draw(HambreBar);
    _ventana1->draw(Barras_Sprites[0]);
    _ventana1->draw(SuenioBar);
    _ventana1->draw(Barras_Sprites[1]);
    _ventana1->draw(CarinioBar);
    _ventana1->draw(Barras_Sprites[2]);



}