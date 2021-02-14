#include <converter.h>

void converter::toArabic() {

}
    
void converter::toRoman() {
    string tmp = "";
    
}
    
bool converter::checkRoman() {

}

converter::converter() {
    isReadyRoman = false;
    isReadyArabic = false;
}

converter::converter(const arabic& ar) {
    arabicNumber = ar;
    isReadyArabic = true;
    isReadyRoman = false;
    toRoman();
}

converter::converter(const roman& rom) {
    romanNumber = rom;
    isReadyRoman = true;
    isReadyArabic = false;
    checkRoman();
    toArabic();
}

void converter::setArabic(const arabic& num) {
    arabicNumber = num;
    isReadyArabic = true;
    isReadyRoman = false;
    toRoman();
}

void converter::setRoman(const roman& num) {
    romanNumber = num;
    isReadyRoman = true;
    isReadyArabic = false;
    checkRoman();
    toArabic();
}

arabic converter::getArabic() const {
    if (!isReadyArabic) throw logic_error("Arabic number not defined");
    return arabicNumber;
}

roman converter::getRoman() const {
    if (!isReadyArabic) throw logic_error("Roman number not defined");
    return romanNumber;
}
