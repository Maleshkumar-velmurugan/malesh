test.o: imp.o app.o
        g++ imp.o app.o -o test
imp.o: imp.cpp
        g++ -c imp.cpp
app.o: app.cpp
        g++ -c app.cpp
