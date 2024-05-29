import sys, random
from PyQt5.QtCore import Qt, QEvent
from PyQt5.QtWidgets import QApplication, QWidget, QPushButton, QLineEdit, QGridLayout, QVBoxLayout, QHBoxLayout, QMessageBox


class GuessingGame(QWidget):
	def __init__(self):
		super().__init__()
		
		#lista de palavras possiveis
		possible_words = ["FREVO", "ASTRO", "CHUVA", "GOSTO", "LOUSA", "NAVIO", "TESTE", "ENTRA", "ROUPA", "PESCA", "ARROZ", "FESTA", "CHAVE", "NUNCA", "BLUSA"]
		self.trying = 0

		self.secret_word = random.choice(possible_words) #escolha da palavra
		self.secret_word = list(self.secret_word) #separando em lista por letra
		self.secret2 = self.secret_word.copy() #cria uma copia
		
		self.setWindowTitle("TERMO") #nome do jogo
		self.setStyleSheet("""
			QWidget{
				background-color: #6F5C62;
				color: white;
			}
			QLabel.warning{
				color: white;
			}
			QLineEdit{
				font-size: 50px;
				font-weight: bold;
				color: white;
				background-color: #6F5C62;
				border: 5px solid #4C4346;
				border-radius: 10px;
				width: 80px;
				height: 80px;
				text-align: center
				
			}
		""")
		
		self.layout = QVBoxLayout() #PRINCIPAL na vertical
		self.Guesslayout = QVBoxLayout() #para cada tentativa
		
		self.letters_boxes = [] #recebe todas as letras
		self.Inputlayout = QHBoxLayout() #na horizontal para as 5 letras

		
		for i in range(5): #pede 5 letras
			self.line_edit = QLineEdit() #uma letras por vez
			self.line_edit.setMaxLength(1) #apenas uma letra
			self.line_edit.setAlignment(Qt.AlignCenter)
			self.Inputlayout.addWidget(self.line_edit) 
			self.letters_boxes.append(self.line_edit) #vai juntando as letras
			self.line_edit.textChanged.connect(self.onTextChanged) #verifica se colocou a letra
			self.line_edit.textChanged.connect(self.updateGuess) #vai formando as palavras
			self.line_edit.installEventFilter(self) #eventos
			
			
		self.setLayout(self.layout) #colocando como principal    
		self.layout.addLayout(self.Inputlayout) #cloca o layout das 5 letras no layout principal
		
		
		self.submit_button = QPushButton("Enviar") #texto do botão
		self.submit_button.setStyleSheet("""
			QPushButton {
				background-color: #4CAF50;
				border: none;
				color: white;
				padding: 10px 10px;
				text-align: center;
				text-decoration: none;
				font-size: 14px;
				margin: 4px 2px;
				border-radius: 10px;
			}

			QPushButton:hover {
				background-color: #45a049;
			}

			QPushButton:pressed {
				background-color: #3e8e41;
			}
		""") #estilo do botão
		self.submit_button.clicked.connect(self.check_guess) #conecta o botao a acao de verificar se ganhou
		self.layout.addWidget(self.submit_button) #add o botao ao layout principal

		self.layout.addLayout(self.Guesslayout) #add o guess(tentativas) ao layout principal
		
	def onTextChanged(self, text): #se coloca uma letra move automaticamente para o lado
		current_index = self.letters_boxes.index(self.sender())
		if len(text) == 1 and current_index < len(self.letters_boxes) - 1:
			self.letters_boxes[current_index + 1].setFocus()
		
	def updateGuess(self, text): #forma a palavra que é a tentativa de advinhar
		self.guess = "".join(line_edit.text() for line_edit in self.letters_boxes)
		
	def eventFilter(self, obj, event):
		if event.type() == QEvent.KeyPress:
			current_index = self.letters_boxes.index(obj)
			if event.key() == Qt.Key_Backspace:
				if current_index > 0 and obj.text() == "":
					self.letters_boxes[current_index - 1].setFocus()
					self.letters_boxes[current_index - 1].clear()
					return True  # Event handled
			elif event.key() == Qt.Key_Left:
				if current_index > 0:
					self.letters_boxes[current_index - 1].setFocus()
					return True  # Event handled
			elif event.key() == Qt.Key_Right:
				if current_index < len(self.letters_boxes) - 1:
					self.letters_boxes[current_index + 1].setFocus()
					return True  # Event handled
			elif event.key() == Qt.Key_Return and obj.hasFocus():
				self.check_guess()
				return True  # Event handled
		return super().eventFilter(obj, event)
			
			
	def check_guess(self): #verifica se a palavra ta certa
		guess = list(self.guess.upper())

		guesscheck = guess.copy() #faz uma copia
		self.Letterlayout = QHBoxLayout() #horizontal para as letras
		self.Guesslayout.addLayout(self.Letterlayout) #add as letras ao layout do guess(tentativas)

		correct = 0 #conta os acertos

		for i in range(len(self.secret_word)):
			if self.secret_word[i] == guess[i]: #compara as palavras
				self.secret2[i] = '+' #se for igual apaga da SECRETA

		for i in range(len(self.secret_word)):
			if self.secret_word[i] == guess[i]:
				guess[i] = "*" #(vai ser verde)
				correct += 1 #se for igual retira da ADVINHA
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
			button.setStyleSheet('font-size: 50px; font-weight: bold; color: white; background-color: '
								 + ('rgb(58, 163, 148)' if guess[i] == "*" 
									else '#D4AD6A' if guess[i] == "-" 
									else '#302A2C')
								 + '; border: ' 
								 + ('5px solid rgb(58, 163, 148)' if guess[i] == "*" 
									else '5px solid #D4AD6A' if guess[i] == "-" 
									else '5px solid #302A2C') 
								 + '; border-radius: 10px; width: 80px; height: 80px; ')

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
			
		for self.line_edit in self.letters_boxes:
			self.line_edit.clear()
		self.letters_boxes[0].setFocus()



if __name__ == "__main__":
	app = QApplication(sys.argv)
	game = GuessingGame()
	game.show()
	sys.exit(app.exec())
