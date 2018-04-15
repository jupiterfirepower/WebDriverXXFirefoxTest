all: webdrivetest clean

webdrivetest: main.cpp
	g++ main.cpp -pipe -O2 -Wall -I /usr/local/include/webdriverxx -L /usr/local/lib -std=c++1z -march=native -lboost_system -lboost_thread -lcrypto -lssl -lcurl -pthread -o webdrivetest
clean:
	rm -f  *o webdrivetest