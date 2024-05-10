
import sqlite3
import time

class Book():
    def __init__(self,name,writer,publisher,kind,printing):

        self.name = name
        self.writer = writer
        self.publisher = publisher
        self.kind = kind
        self.printing = printing

    def __str__(self):
        return "Kitap İsmi: {}\n" \
               "Yazar: {}\n" \
               "Yayınevi: {}\n" \
               "Tür: {}\n" \
               "Baskı: {}\n".format(self.name,self.writer,self.publisher,self.kind,self.printing)

class Library():
    def __init__(self):
        self.create_connect()

    def create_connect(self):

        self.connect = sqlite3.connect("kütüphane.db")

        self.cursor = self.connect.cursor()  # bir tane tablo oluşturmamızı sağlıyor

        query = "Create table If not exists kitaplar1 (name TEXT,writer TEXT,publisher TEXT,kind TEXT,printing INT)"

        self.cursor.execute(query)

        self.connect.commit()   # yapılan işlemleri veri tabanına günceller.

    def interrupt_connection(self):
        self.connect.close()

    def exhibit_books(self):
        query = "SELECT * FROM kitaplar1"

        self.cursor.execute(query)

        books = self.cursor.fetchall()    # kitapların hepsini bir demete atmamızı sağlıyor

        if len(books) == 0:
            print("Kütüphanede kitap bulunmuyor.")
        else:
            for i in books:
                # print(i)
                book = Book(i[0],i[1],i[2],i[3],i[4])
                print(book)

#########################
    def query_book_name(self,name):
        query = "SELECT * FROM kitaplar1 WHERE LOWER(name)=? COLLATE NOCASE"

        self.cursor.execute(query,(name.lower(),))

        books = self.cursor.fetchall()

        if(len(books) == 0):
            print("Böyle bir kitap bulunmuyor")
        else:
            for book_data in books:
                book = Book(book_data[0], book_data[1], book_data[2], book_data[3], book_data[4])
                print(book)

    def query_book_writer(self,writer):
        query = "SELECT * FROM kitaplar1 WHERE LOWER(writer)=? COLLATE NOCASE"

        self.cursor.execute(query,(writer.lower(),))

        books = self.cursor.fetchall()

        if(len(books) == 0):
            print("Böyle bir kitap bulunmuyor")
        else:
            for book_data in books:
                book = Book(book_data[0], book_data[1], book_data[2], book_data[3], book_data[4])
                print(book)

    def query_book_publisher(self,publisher):
        query = "SELECT * FROM kitaplar1 WHERE LOWER(publisher)=? COLLATE NOCASE"

        self.cursor.execute(query,(publisher.lower(),))

        books = self.cursor.fetchall()

        if(len(books) == 0):
            print("Böyle bir kitap bulunmuyor")
        else:
            for book_data in books:
                book = Book(book_data[0], book_data[1], book_data[2], book_data[3], book_data[4])
                print(book)

    def query_book_kind(self,kind):
        query = "SELECT * FROM kitaplar1 WHERE LOWER(kind)=? COLLATE NOCASE"

        self.cursor.execute(query,(kind.lower(),))

        books = self.cursor.fetchall()

        if(len(books) == 0):
            print("Böyle bir kitap bulunmuyor")
        else:
            for book_data in books:
                book = Book(book_data[0], book_data[1], book_data[2], book_data[3], book_data[4])
                print(book)

    def query_book_printing(self,printing):
        query = "SELECT * FROM kitaplar1 WHERE LOWER(printing)=? COLLATE NOCASE"

        self.cursor.execute(query,(printing.lower(),))

        books = self.cursor.fetchall()

        if(len(books) == 0):
            print("Böyle bir kitap bulunmuyor")
        else:
            for book_data in books:
                book = Book(book_data[0], book_data[1], book_data[2], book_data[3], book_data[4])
                print(book)

########################################
    def add_book(self,book):

        query = "INSERT INTO kitaplar1 VALUES(?,?,?,?,?)"

        self.cursor.execute(query,(book.name,book.writer,book.publisher,book.kind,book.printing))
        self.connect.commit()

    def delete_book(self,name):
        query = "DELETE FROM kitaplar1 WHERE name=?"
        self.cursor.execute(query,(name,))
        self.connect.commit()

    def upgrade_printing(self,name):
        query = "SELECT * FROM kitaplar1 WHERE name=?"
        self.cursor.execute(query,(name,))

        books = self.cursor.fetchall()

        if(len(books) == 0):
            print("Böyle bir kitap bulunmuyor")
        else:
            printing = books[0][4]
            printing += 1

            query2 = "UPDATE kitaplar1 SET printing = ? WHERE name = ?"
            self.cursor.execute(query2,(printing,name))
            self.connect.commit()

    def count_data(self):
        query = "SELECT * FROM kitaplar1"

        self.cursor.execute(query)

        books = self.cursor.fetchall()    # kitapların hepsini bir demete atmamızı sağlıyor

        print("Kütüphanemizdeki kayıtlı kitap sayısı: ",len(books))

    def count_printing(self):
        query = "SELECT * FROM kitaplar1"

        self.cursor.execute(query)

        books = self.cursor.fetchall()    # kitapların hepsini bir demete atmamızı sağlıyo
        count = 0
        for i in books:
            # print(i,i[4],type(i[4]))
            count += int(i[4])
        print("Kütüphanemizdeki kayıtlı olan kitapların basım sayılarının toplamı: ",count)









