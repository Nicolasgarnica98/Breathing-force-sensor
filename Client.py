import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation
import time
import socket
import pickle

TCP_IP = '192.168.1.104'

TCP_PORT = 5005
BUFFER_SIZE = 1024
#MESSAGE = "data2"
s = socket.socket()
s.connect((TCP_IP, TCP_PORT))
#data_String = pickle.dumps([MESSAGE])
#s.send(data_String)
x_time = []
y_voltage = []
plt.axis([0, 10, 0, 3.3])
t = 0
while 1:
    data_Rec = s.recv(BUFFER_SIZE)
    content = data_Rec.decode("utf-8")
    #print(content)
    content = content.split(",")
    Fuerza_medicion = content[0]
    voltage_medicion = float(int(Fuerza_medicion)*(3.3/4096))
    # if voltage_medicion > 3.3:
    #     voltage_medicion = 3.3
    print('Fuerza: ',str(voltage_medicion) + ' V')
    x_time.append(t)
    y_voltage.append(voltage_medicion)
    plt.plot(x_time, y_voltage,color='red')
    plt.pause(0.1)
    t = t+0.1
plt.grid()
plt.show()
s.close()

