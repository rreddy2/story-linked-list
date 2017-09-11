all : run

run : driver2.o Word.o Sentence.o Paragraph.o Story.o
	g++ driver2.o Word.o Sentence.o Paragraph.o Story.o -o run

Word.o : Word.cpp
	g++ -c -g Word.cpp

Sentence.o : Sentence.cpp
	g++ -c -g Sentence.cpp

Paragraph.o : Paragraph.cpp
	g++ -c -g Paragraph.cpp
	
Story.o : Story.cpp
	g++ -c -g Story.cpp

driver2.o : driver2.cpp
	g++ -c -g  driver2.cpp

clean:
	rm -f *.o run
