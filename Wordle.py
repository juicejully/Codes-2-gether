```
import os

def main():
    name_aux = input("Escolha uma palavra:\n")
    name = list(name_aux)
    n = len(name)
    win = 0
    correct = 0
    tent = 0
    secret = ['-'] * n
    secret2 = ['+'] * n

    os.system('clear' if os.name == 'posix' else 'cls')
    print("A palavra secreta é:\n" + ''.join(secret))

    tentativas = [[''] * n for _ in range(n + 1)]

    while win == 0 and tent < (n + 1):
        correct = 0
        guess = input(f"{tent+1}ª tentativa]: ")

        if len(guess) != n:
            print(f"A palavra inserida não é compatível. Deve ter {n} letras!")
            continue

        os.system('clear' if os.name == 'posix' else 'cls')
        tent += 1

        secret2 = name.copy()

        for i in range(n):
            if name[i] == guess[i]:
                secret2[i] = '+'

        for i in range(n):
            if name[i] == guess[i]:
                print('\033[32m' + guess[i] + '\033[0m', end='')
                correct += 1
            else:
                has = 0
                for a in range(n):
                    if guess[i] == secret2[a] and guess[i] != name[i]:
                        print('\033[33m' + guess[i] + '\033[0m', end='')
                        has = 1
                        secret2[a] = '+'
                        break
                if has == 0:
                    print(guess[i], end='')

        print()

        if correct == n:
            print(f"Parabéns!! Você acertou a palavra na {tent}ª tentativa.")
            win = 1
        else:
            correct = 0

if __name__ == "__main__":
    main()
```
