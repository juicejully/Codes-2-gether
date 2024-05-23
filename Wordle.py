import sys, random
from PyQt5.QtWidgets import QApplication, QWidget, QPushButton, QLineEdit, QGridLayout, QVBoxLayout, QHBoxLayout, QMessageBox


class GuessingGame(QWidget):
    def __init__(self):
        super().__init__()
        
        #lista de palavras possiveis
        possible_words = ["FREVO", "ASTRO", "CHUVA", "GOSTO", "LOUSA", "NAVIO", "TESTE", "ENTRA", "ROUPA", "PESCA"]
        self.trying = 0

        self.secret_word = random.choice(possible_words) #escolha da palavra
        self.secret_word = list(self.secret_word) #separando em lista por letra
        self.secret2 = self.secret_word.copy() #cria uma copia

        self.setWindowTitle("TERMO") #nome do jogo
        
        self.layout = QVBoxLayout() #PRINCIPAL na vertical
        self.Buttonslayout = QVBoxLayout() #para cada tentativa

        self.input_box = QLineEdit() #input texto

        self.input_box.setStyleSheet("""
            QLineEdit {
                background-color: #f0f0f0;
                border: 2px solid #c0c0c0;
                border-radius: 5px;
                padding: 5px;
                font-size: 20px;
                height: 40px;
                text-align: center;
            }

            QLineEdit:focus {
                border: 2px solid #4CAF50;
            }
        """) #style TextBox
        self.layout.addWidget(self.input_box) #add TextBox para o Layout principal

        self.submit_button = QPushButton("Enviar") #texto do botão
        self.submit_button.setStyleSheet("""
            QPushButton {
                background-color: #4CAF50;
                border: none;
                color: white;
                padding: 10px 10px;
                text-align: center;
                text-decoration: none;
                display: inline-block;
                font-size: 14px;
                margin: 4px 2px;
                cursor: pointer;
                border-radius: 10px;
            }

            QPushButton:hover {
                background-color: #45a049;
            }

            QPushButton:pressed {
                background-color: #3e8e41;
            }
        """) #estilo do botão
        self.submit_button.clicked.connect(self.check_input) #conecta o botao a acao de verificar se ganhou
        self.layout.addWidget(self.submit_button) #add o botao ao layout principal

        self.buttons = [] #cria uma lista vazia para as letras
        self.setLayout(self.layout) #colocando como principal
        self.layout.addLayout(self.Buttonslayout) #add o butao ao layout principal
        
    def check_input(self):  # verifica se tem 5 letras
        word = self.input_box.text()
    
        if len(word) != 5:
            QMessageBox.warning(self, "Erro!", "A Palavra deve conter exatamente 5 letras.")
            self.input_box.clear()
        else:
            self.check_guess()

    def check_guess(self): #verifica se a palavra ta certa
        guess = list(self.input_box.text().upper())

        guesscheck = guess.copy() #faz uma copia
        self.Letterlayout = QHBoxLayout() #horizontal para as letras
        self.Buttonslayout.addLayout(self.Letterlayout) #add o butao ao layout principal

        correct = 0 #conta os acertos

        for i in range(len(self.secret_word)):
            if self.secret_word[i] == guess[i]: #compara as palavras
                self.secret2[i] = '+' #se for igual apaga da SECRETA

        for i in range(len(self.secret_word)):
            if self.secret_word[i] == guess[i]:
                guess[i] = "*" #(vai ser verde)
                correct += 1 #se for igaul retira da ADVINHA
            else:
                has = 0
                for t in range(len(self.secret_word)):
                    if guess[i] == self.secret2[t] and guess[i] != self.secret_word[i]: #tem mas não na posicao correta
                        guess[i] = "-" #(vai ser amarelo)
                        has = 1
                        self.secret2[t] = '+' #retira de SECRETA
                        break
                if has == 0:
                    guess[i] = "#" #(vai ser preta)

        for i in range(len(self.secret_word)):
            button = QPushButton(guesscheck[i] if i < len(guess) else '')
            button.setStyleSheet('font-size: 60px; color: white; background-color: '
                                 + ('rgb(58, 163, 148)' if guess[i] == "*" else
                                    'yellow' if guess[i] == "-" else 'black')
                                 + '; border: None; width: 80px; height: 80px; ')

            self.Letterlayout.addWidget(button)
            
        
        self.secret2 = self.secret_word.copy() #cria uma copia novamente
            
        if correct == len(self.secret_word):
            QMessageBox.warning(self,"Parabens!","Você acertou a palavra.")
            raise SystemExit("Fim de Jogo")
        else:
            self.trying += 1
            
        if self.trying == 5:
            QMessageBox.warning(self,"Poxa!","Suas tentativas acabaram.\nExperimente jogar novamente")
            raise SystemExit("Fim de Jogo")



if __name__ == "__main__":
    app = QApplication(sys.argv)
    game = GuessingGame()
    game.show()
    sys.exit(app.exec())
