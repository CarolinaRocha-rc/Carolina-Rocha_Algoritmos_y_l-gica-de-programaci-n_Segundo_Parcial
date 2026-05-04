import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class Productosarchivo {
    public static void main(String[] args) {
        File archivo = new File("productos.txt");
        if (!archivo.exists()) {
            System.out.println("Error: el archivo no existe.");
            return;
        }
        double total = 0;
        String productoMasCaro = "";
        double precioMayor = 0;
        try {
            Scanner lector = new Scanner(archivo);
            while (lector.hasNext()) {
                String nombre = lector.next();
                double precio = lector.nextDouble();
                int cantidad = lector.nextInt();
                double subtotal = precio * cantidad;
                System.out.println("Producto: " + nombre);
                System.out.println("Precio: " + precio);
                System.out.println("Cantidad: " + cantidad);
                System.out.println("Subtotal: " + subtotal);
                System.out.println("----------------------");
                total += subtotal;
                if (precio > precioMayor) {
                    precioMayor = precio;
                    productoMasCaro = nombre;
                }
            }
            lector.close();
            System.out.println("Total general: " + total);
            System.out.println("Producto mas caro: " + productoMasCaro);
        } catch (FileNotFoundException e) {
            System.out.println("Error al leer el archivo.");
        }
    }
}