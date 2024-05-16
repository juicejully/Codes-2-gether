import sys
from PySide6.QtWidgets import QApplication, QWidget, QPushButton, QLineEdit, QGridLayout, QVBoxLayout, QHBoxLayout

a = 10


class GuessingGame(QWidget):
    def __init__(self):
        super().__init__()

        self.secret_word = 'AUREO'
        self.secret_word = list(self.secret_word)
        self.secret2 = self.secret_word.copy()

        self.setWindowTitle("TERMO")

        self.layout = QVBoxLayout()
        self.Buttonslayout = QHBoxLayout()

        self.input_box = QLineEdit()

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
        """)
        self.layout.addWidget(self.input_box)

        self.submit_button = QPushButton("Submit")
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
        """)
        self.submit_button.clicked.connect(self.check_guess)
        self.layout.addWidget(self.submit_button)

        self.buttons = []
        self.setLayout(self.layout)
        self.layout.addLayout(self.Buttonslayout)

    def check_guess(self):
        guess = list(self.input_box.text().upper())
        if len(guess) < len(self.secret_word) or len(self.secret_word) > len(guess):
            pass

        guesscheck = guess.copy()

        b = 10
        correct = 0

        # Clear the layout and buttons from the previous guess
        for button in self.buttons:
            button.setParent(None)
        self.buttons = []

        for i in range(len(self.secret_word)):
            if self.secret_word[i] == guess[i]:
                self.secret2[i] = '+'

        for i in range(len(self.secret_word)):
            if self.secret_word[i] == guess[i]:
                guess[i] = "*"
                correct += 1
            else:
                has = 0
                for t in range(len(self.secret_word)):
                    if guess[i] == self.secret2[t] and guess[i] != self.secret_word[i]:
                        guess[i] = "-"
                        has = 1
                        self.secret2[t] = '+'
                        break
                if has == 0:
                    guess[i] = "#"

        for i in range(len(self.secret_word)):
            button = QPushButton(guesscheck[i] if i < len(guess) else '')
            button.setStyleSheet('font-size: 60px; color: white; background-color: '
                                 + ('rgb(58, 163, 148)' if guess[i] == "*" else
                                    'yellow' if guess[i] == "-" else 'black')
                                 + '; border: None; width: 80px; height: 80px; ')

            self.Buttonslayout.addWidget(button)
            self.buttons.append(button)
            b += 10

        # if correct == len(self.secret_word):
        #     self.setLayout(self.winlayout)
        #     win = QPushButton('VOCÃŠ GANHOU')
        #     self.winlayout.addWidget(win)


if __name__ == "__main__":
    app = QApplication(sys.argv)
    game = GuessingGame()
    game.show()
    sys.exit(app.exec())
