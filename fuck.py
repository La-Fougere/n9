import serial
import time
from http.server import BaseHTTPRequestHandler, HTTPServer
import threading

# Configurez le port série (ajustez le port COM si nécessaire)
ser = serial.Serial('COM9', 9600, timeout=1)
time.sleep(2)

class RequestHandler(BaseHTTPRequestHandler):
    def do_GET(self):
        ser.write(b"HTTP ON\n")
        print("Requête 'on' envoyée")

        time.sleep(5)

        ser.write(b"HTTP OFF\n")
        print("Requête 'off' envoyée")

        self.send_response(200)
        self.send_header('Content-type', 'text/html')
        self.end_headers()
        self.wfile.write(b"Commande envoyee a l'Arduino")

def run_server():
    server_address = ('', 8000)
    httpd = HTTPServer(server_address, RequestHandler)
    print("Serveur en ecoute sur le port 8000...")
    httpd.serve_forever()

server_thread = threading.Thread(target=run_server, daemon=True)
server_thread.start()

while True:
    if ser.in_waiting:
        print(ser.readline().decode().strip())
