import os
import serial
import time

puerto = 'COM2'  # Cambia esto al puerto correcto
baudrate = 9600

puertoSerial = serial.Serial(puerto, baudrate)
time.sleep(2)  # Espera a que el puerto se inicialice

def menu():
    while True:
        os.system('cls' if os.name == 'nt' else 'clear')

        # Menú de selección
        for i in range(1, 10):
            print(f"{i} - Led {i}")
        print("x - Salir")

        opcion = input("Seleccione el led a encender \n")

        if opcion == 'x':
            print("Saliendo...")
            break
        elif opcion not in [str(i) for i in range(1, 10)]:
            print("Opción no válida. Intente de nuevo.")
            time.sleep(1)
            continue
        else:
            print(f"Encendiendo led {opcion}")
            puertoSerial.write(opcion[0].encode())
            time.sleep(1)


if __name__ == '__main__':
    try:
        menu()
    except KeyboardInterrupt:
        print("Saliendo...")
    finally:
        puertoSerial.close()


