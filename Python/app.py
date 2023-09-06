from rich.console import Console
from rich.markdown import Markdown
import Assets.katahm 
import random

class game:
    def __init__(self,soal,desk,type):
        self.soal=soal
        self.desk=desk
        self.type=type
        self.himpunan_jawaban=[]
        self.coba=1
        self.sisa=6
        self.console = Console()
        self.buatSoal()

    def buatSoal(self):
        for i in range(0,len(self.soal)):
            self.himpunan_jawaban.append("-")

    def displaySoal(self):
        self.gambar_orang()
        for i in self.himpunan_jawaban:
            print(i,end="")
        print("")
        print("")

    def check_jawaban(self,jawaban):
        for i in range(0,len(self.soal)):
            if jawaban==self.soal[i]:
                self.himpunan_jawaban[i]=jawaban
        else:
            if jawaban not in self.soal:
                self.coba+=1
                self.sisa-=1
                
    
    def check_status_permainan(self):
        if self.coba>6:
            self.check_kalah()
        else:
            self.check_menang()

    def check_kalah(self):
        print("")
        print("MEH! FUCKING LOSER! IT'S FUCKING {} FOR FUCK SAKE!".format(self.soal))
        exit()
    
    def check_menang(self):
        for i in self.himpunan_jawaban:
            if "-" not in self.himpunan_jawaban:
                print("")
                print("ANSWER : ", self.soal)
                print("")
                print("YOU FUCKING WON! CONGRATS!")
                exit()
    
    def gambar_orang(self):
        gambar_hangman=['''
  +---+
      |
      |
      |
    ===
                        ''', 
                        '''
  +---+
  O   |
      |
      |
    ===
                        ''', 
                        '''
  +---+
  O   |
  |   |
      |
    ===
                        ''', 
                        '''
  +---+
  O   |
 /|   |
      |
    ===
                        ''', 
                        '''
  +---+
  O   |
 /|\  |
      |
    ===
                            ''', 
                            '''
  +---+
  O   |
 /|\  |
 /    |
    ===
                              ''', 
                              '''
  +---+
  O   |
 /|\  |
 / \  |
    ===
                              ''']
        print(gambar_hangman[self.coba])

    def welcome(self):
        with open("./Assets/welcome.md") as readme:
            markdown = Markdown(readme.read())
        self.console.print(markdown)
        user=int(input("Please input your answer : "))
        if(user==0):
            exit()
        elif(user==1):
            self.gameplay()
    
    def gameplay(self):
        while(self.coba<=6):
            print("-"*100)
            print("Attempts left : {}".format(self.sisa))
            self.displaySoal()
            print("Type : {}".format(self.type))
            print("Description : {}".format(self.desk))
            user=str(input("Input a letter, plz : ")).lower()
            self.check_jawaban(user)
            self.check_status_permainan()

if __name__ == "__main__":
    kamus = Assets.katahm
    number=random.randint(0,8)
    kata=kamus.katakatahm[number]
    desk=kamus.describe[number]
    type=kamus.type[number]
    thegame = game(kata,desk,type)
    thegame.welcome()
            
            

    
