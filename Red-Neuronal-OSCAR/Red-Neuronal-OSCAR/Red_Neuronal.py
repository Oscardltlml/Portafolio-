import matplotlib.pyplot as plt
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg
from tkinter import *
import numpy as np
import threading

def change_color():
    global good_or_bad
    good_or_bad = not(good_or_bad)
    if good_or_bad:
        red_green_button.config(text="Good", background="#2CA711")
    else:
        red_green_button.config(text="Bad", background="#FF0000")

def plot_point(event):
    ix, iy = event.xdata, event.ydata
    X.append((1, ix, iy))
    if good_or_bad:
        d.append(1)
        ax.plot(ix,iy, '.g')
    else:
        d.append(0)
        ax.plot(ix,iy, '.r')
    canvas.draw()

# Inicializar los pesos del perceptrón
def initializeWeights():
    global W
    W = np.random.rand(3)

# Reimprimir la gráfica principal con su plano y tamaño correspondiente
def print_axis():
    global ax
    ejeX = [-5,5]
    ejeY = [-5,5]
    zeros = [0,0]
    ax.plot(ejeX, zeros, 'k')
    ax.plot(zeros, ejeY, 'k')
    plt.xlim(-1.5,1.5)
    plt.ylim(-1.5,1.5)

# Limpiar pantalla y valores
def clean_screen():
    global X, W, d
    X = []
    d = []
    W = []

    ax.cla()
    print_axis()
    canvas.draw()

# Función de activación escalón
def ActivationFunc(x):
    return 1 if np.dot(W, x) >= 0 else 0

# Entrenar el perceptrón
def trainPerceptron():
    global eta_gui, epoch_gui, X, W, d
    eta = float(eta_gui.get())
    epoch = int(epoch_gui.get())
    epoch_count = 0

    X = np.array(X)
    d = np.array(d)
    
    while epoch:
        for i in range(len(X)):
            y = ActivationFunc(X[i])
            error = d[i] - y
            W += eta * error * X[i]  # Actualización de pesos
            epoch_count += 1

            # Imprimir los puntos en la gráfica
            ax.cla()

            for i in range(len(X)):
                if ActivationFunc(X[i]) == 1:
                    ax.plot(X[i,1], X[i,2], 'o', color='green')
                else:
                    ax.plot(X[i,1], X[i,2], 'o', color='red')

            # Dibujar la frontera de decisión
            x_vals = np.linspace(-1.5, 1.5, 100)
            y_vals = -(W[0] + W[1] * x_vals) / W[2]
            ax.plot(x_vals, y_vals, 'b-')

            print_axis()
            canvas.draw()

        epoch -= 1
        epoch_label.config(text="Epoca: " + str(epoch_count))

# Inicio de programa + interfaz
X = []
W = []
d = []
good_or_bad = True

# Inicializar la gráfica de matplotlib
fig, ax = plt.subplots(facecolor='#8D96DA')
print_axis()

mainwindow = Tk()
mainwindow.geometry('900x600')
mainwindow.wm_title('Perceptrón Simple')

eta_gui = StringVar(mainwindow, 0)
epoch_gui = StringVar(mainwindow, 0)

# Colocar la gráfica en la interfaz
canvas = FigureCanvasTkAgg(fig, master = mainwindow)
canvas.get_tk_widget().place(x=10, y=10, width=580, height=580)
fig.canvas.mpl_connect('button_press_event', plot_point)

# Etiquetas, cuadros de entrada y botón
eta_label = Label(mainwindow, text = "Eta: ")
eta_label.place(x=600, y=60)
eta_entry = Entry(mainwindow, textvariable=eta_gui)
eta_entry.place(x=600, y=80)

epoch_label = Label(mainwindow, text = "Epochs: ")
epoch_label.place(x=600, y=110)
epoch_entry = Entry(mainwindow, textvariable=epoch_gui)
epoch_entry.place(x=600, y=130)

start_button = Button(mainwindow, text="Go!", command=lambda:threading.Thread(target=trainPerceptron).start())
start_button.place(x=600, y=160)

red_green_button = Button(mainwindow, text="Good", background="#2CA711", width=10, command=change_color)
red_green_button.place(x=600, y=200)

clean_button = Button(mainwindow, text="Clean", command=clean_screen)
clean_button.place(x=600, y=240)

epoch_label = Label(mainwindow, text="Epoca: 0")
epoch_label.place(x=600, y=300)

# Mostrar la interfaz
mainwindow.mainloop()
