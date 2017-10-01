#pragma once

class objeto
{
  public:
    virtual void pintar(char**)=0;
    virtual void generar_objeto(int,int,int,int,char**)=0;
    char ocupado(int,int,char**);
    virtual void set_pos(int,int)=0;
};

class amuleto:public objeto
{
  private:
    int pos[2];
    int beneficio;
  public:
    amuleto();
    void pintar(char**);
    void generar_objeto(int,int,int,int,char**);
    void set_pos(int,int);
};

class pocima:public objeto
{
  private:
    int pos[2];
    int beneficio;
    int fuerza;
  public:
    pocima();
    void pintar(char**);
    void generar_objeto(int,int,int,int,char**);
    void set_pos(int,int){};
};

class espada:public objeto
{
  private:
    int pos[2];
    int fuerza;
  public:
    espada();
    void pintar(char**);
    void generar_objeto(int,int,int,int,char**);
    void set_pos(int,int){};
};