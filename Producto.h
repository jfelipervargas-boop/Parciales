#include <iostream>
#include <string>

class Producto{
private:
  string nombre;
  float precio;
  int stock;
  int descuento;
public:
  Producto(string n, float p, int s, int d){}: nombre(n), precio(p), stock(p), descuento(d){}
  void actualizarPrecio(){
    precio = nuevoPrecio;
  }

    void resumenProducto() {
        cout << "Producto: " << nombre
             << "\nPrecio: $" << precio
             << "\nStock: " << stock
             << "\nDescuento: " << descuento << "%\n";
    }

    float vender(int cantidad) {
        if (cantidad > stock) {
            cout << "Stock insuficiente\n";
            return 0;
        }
        float precioFinal = precio * (1 - descuento / 100.0);
        float total = precioFinal * cantidad;
        stock -= cantidad;
        return total;
    }

    void reabastecer(int cantidad) {
        stock += cantidad;
    }

    float consultarValorInventario() {
        return precio * stock;
    }
};

}
