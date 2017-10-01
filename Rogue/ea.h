#pragma once

class ea
{
   public:
      virtual void pintar(char**)=0;
      virtual void generar(int,int,int,ea*)=0;
      virtual int get_esquina_x()=0;
      virtual int get_esquina_y()=0;
      virtual int get_tamano_ancho()=0;
      virtual int get_tamano_alto()=0;
      virtual void asignar_datos(int,int,int,char**)=0;
};


class habitacion: public ea
{
   private:
      int v_esquina[2];
      int v_tamano[2];
   public:
      habitacion();
      int get_esquina_x();
      int get_esquina_y();
      int get_tamano_ancho();
      int get_tamano_alto();
      void set_tamano(int,int);
      void set_esquina(int,int);
      void generar(int,int,int,ea *);
      void pintar(char**);
      void asignar_datos(int,int,int,char**);
};

class puerta: public ea
{
   private:
      int v_coordenada[2];
   public:
      puerta();
      int get_esquina_x();
      int get_esquina_y();
      void set_coordenada(int,int);
      void generar(int,int,int, ea*);
      void pintar(char**);
      
      //////////////////////////////////////////
      int get_tamano_ancho(){};
      int get_tamano_alto(){};
      void asignar_datos(int,int,int,char**){};
      //////////////////////////////////////////
};
   
    