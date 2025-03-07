import pyautogui
import pytesseract
import time
import requests
from PIL import Image
import numpy as np

# Configurez le chemin vers l'exécutable Tesseract si nécessaire
pytesseract.pytesseract.tesseract_cmd = r'C:\Program Files\Tesseract-OCR\tesseract.exe'

def detect_text():
    screenshot = pyautogui.screenshot()
    
    screenshot_np = np.array(screenshot)
    
    gray_image = Image.fromarray(screenshot_np).convert('L')
    
    # OCR sur la partie inférieure de l'écran (y > 700)
    height = screenshot.height
    text = pytesseract.image_to_string(gray_image.crop((0, 700, screenshot.width, height)))
    
    return "a few seconds" in text.lower()

def main():
    while True:
        if detect_text():
            # Envoyer une requête GET à localhost:8000
            try:
                response = requests.get("http://localhost:8000")
                print("Requête envoyée, statut:", response.status_code)
            except requests.RequestException as e:
                print("Erreur lors de l'envoi de la requête:", e)
            
            while detect_text():
                time.sleep(0.2)
        
        time.sleep(0.1)

if __name__ == "__main__":
    main()