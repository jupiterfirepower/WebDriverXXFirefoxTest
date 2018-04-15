#include <fstream>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <functional>
#include <cctype>
#include <locale>
#include <vector>
#include <list>
#include <stdio.h>
#include <sstream>
#include <codecvt>
#include <clocale>
#include <chrono>

#include <webdriverxx/webdriver.h>
#include <webdriverxx/browsers/firefox.h>

using namespace std;
using namespace chrono;
using namespace webdriverxx;
using WebDriver = webdriverxx::WebDriver;

class Base {
    virtual void method()
    {
	std::cout << "from Base - virtual void method()" << std::endl;
    }
public:
    virtual ~Base()
    {
        std::cout << "from Base - ~Base()" << std::endl;
        method();
    }
    void baseMethod()
    {
        std::cout << "from Base - void baseMethod()" << std::endl;
        method();
    }
};

class A : public Base {
    void method()
    {
	std::cout << "from class A -  void method()" << std::endl;
    }
public:
    ~A(){ std::cout << "from class A -  ~A()" << std::endl;
        method(); }
};

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "Russian");

    Base* base = new A;
    base->baseMethod();
    delete base;

    WebDriver firefox = Start(Firefox());
    firefox
    .Navigate("https://rabota.ua/company1175016/vacancy7057514?mode=apply#apply")
    .FindElement(ById("content_vcVwPopup_vacancyApplyForm_txFromEMail"))
    .SendKeys("test@email.net");

    firefox
    .FindElement(ById("content_vcVwPopup_vacancyApplyForm_txtSurName"))
    .SendKeys("Test");

    firefox
    .FindElement(ById("content_vcVwPopup_vacancyApplyForm_txtName"))
    .SendKeys("Test");

    // Simple script, no parameters
    firefox.Execute("document.getElementById('content_vcVwPopup_vacancyApplyForm_flUplResume').style.visibility='visible'");

    //firefox
    //.FindElement(ById("content_vcVwPopup_vacancyApplyForm_flUplResume"))
    //.SendKeys("/home/pwd/Documents/test.txt");*/
    //.SetAttribute("value", "/home/pwd/Documents/empty.txt");
    //.SendKeys("/home/pwd/Documents/test.txt");
    //.FindElement(ById("content_vacSearch_lnkSearch"))
    //.Click();
    //.Submit()//;

    std::cout << "Finish press Enter for Exit." << std::endl;
    std::cin.get();

    return 0;
}