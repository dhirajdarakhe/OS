import socket 

def server_socket():
    
    host  = socket.gethostname()
    port  = 3000
    
    ss = socket.socket()
    
    ss.bind((host, port))
    ss.listen(3)
    
    conn, add = ss.accept()
    
    print("Connection is formed from : ", (add))
    
    while (1):
        
        data = conn.recv(2014).decode()
        print("DATA  : ", data)
        data = input("Enter the data : ")
        if data == 'exit':
            break
        conn.send(data.encode())
        
    ss.close()
    
    
server_socket()