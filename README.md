# WebDriverXXFirefox Test tested on Ubuntu 17.10.1
# Download Oracle JRE
tar zxvf jre-9.0.4_linux-x64_bin.tar.gz
export JAVA_HOME=~/Downloads/jre-9.0.4
export PATH=$JAVA_HOME/bin:$PATH

# Download geckodriver search by Google
tar zxvf geckodriver-v0.19.1-linux64.tar.gz
whereis geckodriver
export PATH=$PATH:/home/pwd/bin

# install Google tests
sudo apt-get install libgtest-dev

# Clone WebDriverxx c++
git clone https://github.com/durdyev/webdriverxx
mkdir build
cd build/
cmake ..
make
sudo make install
# Download Selenium Server and Run in console
java -jar selenium-server-standalone-3.9.1.jar
# make test application an run
make webdrivetest