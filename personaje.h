#pragma once

class personaje
{
  public:
    virtual void mover(char,char**)=0;
    virtual void mover_pasillo(char,char**)=0;
    virtual void pintar(char**)=0;
    virtual void set_posicion(int,int)=0;
    virtual void generar_personaje(int,int,int,int,char**)=0;
    char ocupado(int,int,char**);
    virtual int get_pos_x()=0;
    virtual int get_pos_y()=0;
    virtual int get_anterior()=0;
    virtual int get_vida()=0;
    virtual int get_fuerza()=0;
    virtual bool get_amuleto()=0;
    virtual int get_beneficio()=0;
    virtual void quitar_vida(int&,int&,char**)=0;
    virtual void quitar()=0;
};

class heroe:public personaje
{
  private:
    int posicion[2];
    char anterior;
    int vida;
    int fuerza;
    int beneficio;
    bool amuleto;
  public:
    heroe();
    void set_posicion(int, int);
    void mover(char,char**);
    void mover_pasillo(char,char**);
    void pintar(char**);
    void generar_personaje(int,int,int,int,char**){};
    int get_pos_x();
    int get_pos_y();
    int get_anterior();
    int get_vida();
    int get_fuerza();
    bool get_amuleto();
    int get_beneficio();
    void quitar_vida(int&,int&,char**);
    void quitar();
};

class trol:public personaje
{
  private:
    int pos[2];
    char mov;
    int vida;
    int fuerza;
  public:
    trol();
    void mover(char,char**);
    void pintar(char**);
    void generar_personaje(int,int,int,int,char**);
    int get_pos_x();
    int get_pos_y();
    void quitar_vida(int&,int&,char**);
    int get_vida();

    //////////////////////////////////////////
    void mover_pasillo(char,char**){};
    void set_posicion(int,int){};
    int get_anterior(){};
    int get_fuerza(){};
    bool get_amuleto(){};
    int get_beneficio(){};
    void quitar(){};
};

class dragon:public personaje
{
private:
  int pos[2];
  int vida;
  int fuerza;
public:
  dragon();
  int get_vida();
  void mover(char,char**);
  void quitar_vida(int&,int&,char**);
  void pintar(char**);
  void generar_personaje(int,int,int,int,char**);
  int get_pos_x();
  int get_pos_y();
  
  //////////////////////////////////////////
  int get_anterior(){};
  int get_fuerza(){};
  bool get_amuleto() {};
  int get_beneficio(){};
  void mover_pasillo(char,char**){};
  void set_posicion(int,int){};
  void quitar(){};
};


    
  
    
  
  