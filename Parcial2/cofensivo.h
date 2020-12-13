#ifndef COFENSIVO_H
#define COFENSIVO_H


class cOfensivo
{
private:
    float d=0;
    float Xo=0; //pos inicial en x
    float Yo=0; //pos inicial en y
    float d0=0.05*d; //rango de destruccion

    float pi=3.1416;
    float G=9.81;
public:
    cOfensivo();
    void disparosOfensivos(float Xd,float Yd,int Vini);


    float getD() const;
    void setD(float value);

    float getXo() const;
    void setXo(float value);

    float getYo() const;
    void setYo(float value);

    float getD0() const;
    void setD0(float value);

};

#endif // COFENSIVO_H
