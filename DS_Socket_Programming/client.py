
import socket

def client_program():
    
    host = socket.gethostname()
    port = 3000
    
    c_socket = socket.socket()
    c_socket.connect((host, port))
    
    m = input("Enter the mess : ")
    
    while m.lower().strip() != 'exit':
        
        c_socket.send(m.encode())
        
        data = c_socket.recv(2014).decode()
        print("data : ", data)
        m = input("Enter the mess : ")
    
    c_socket.close()
client_program()