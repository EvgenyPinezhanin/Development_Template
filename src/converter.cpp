#include <converter.h>

char arrNum[] = { 'I', 'V', 'X', 'L', 'C', 'D', 'M' }; 

void converter::toArabic() {
    if (!checkRoman()) throw logic_error("Invalid roman number");
    int tmpArabic = 0;
    string tmp = romanNumber.value;
    int count = 0;
    string twoC;
    while (count < (int)tmp.length() - 1)
    {
        twoC = tmp.substr(count, 2);
        if (twoC == "IV") {
            tmp.replace(count, 2, "");
            tmpArabic += 4;
            count--;
        }
        if (twoC == "IX") {
            tmp.replace(count, 2, "");
            tmpArabic += 9;
            count--;
        }
        if (twoC == "XL") {
            tmp.replace(count, 2, "");
            tmpArabic += 40;
            count--;
        }
        if (twoC == "XC") {
            tmp.replace(count, 2, "");
            tmpArabic += 90;
            count--;
        }
        if (twoC == "CD") {
            tmp.replace(count, 2, "");
            tmpArabic += 400;
            count--;
        }
        if (twoC == "CM") {
            tmp.replace(count, 2, "");
            tmpArabic += 900;
            count--;
        }
        count++;
    }
    
    for (int i = 0; i < tmp.length(); i++) {
        if (romanNumber.value[i] == 'I') {
            tmpArabic += 1;
        }
        if (romanNumber.value[i] == 'V') {
            tmpArabic += 5;
        }
        if (romanNumber.value[i] == 'X') {
            tmpArabic += 10;
        }
        if (romanNumber.value[i] == 'L') {
            tmpArabic += 50;
        }
        if (romanNumber.value[i] == 'C') {
            tmpArabic += 100;
        }
        if (romanNumber.value[i] == 'D') {
            tmpArabic += 500;
        }
        if (romanNumber.value[i] == 'M') {
            tmpArabic += 1000;
        }
    }
    arabicNumber.value = tmpArabic;
    isReadyArabic = true;
}
    
void converter::toRoman() {
    arabic tmp = arabicNumber;
    string tmpRoman = "";

    if (tmp.value / M > 0) {
        for (int i = 0; i < tmp.value / M; i++) {
            tmpRoman += "M";
        }
        tmp.value = tmp.value % M;
    }
    if (tmp.value >= 900) {
        tmpRoman += "CM";
        tmp.value -= 900;
    }

    if (tmp.value / D > 0) {
        for (int i = 0; i < tmp.value / D; i++) {
            tmpRoman += "D";
        }
        tmp.value = tmp.value % D;
    }
    if (tmp.value >= 400) {
        tmpRoman += "CD";
        tmp.value -= 400;
    }

    if (tmp.value / C > 0) {
        for (int i = 0; i < tmp.value / C; i++) {
            tmpRoman += "C";
        }
        tmp.value = tmp.value % C;
    }
    if (tmp.value >= 90) {
        tmpRoman += "XC";
        tmp.value -= 90;
    }

    if (tmp.value / L > 0) {
        for (int i = 0; i < tmp.value / L; i++) {
            tmpRoman += "L";
        }
        tmp.value = tmp.value % L;
    }
    if (tmp.value >= 40) {
        tmpRoman += "XL";
        tmp.value -= 40;
    }

    if (tmp.value / X > 0) {
        for (int i = 0; i < tmp.value / X; i++) {
            tmpRoman += "X";
        }
        tmp.value = tmp.value % X;
    }
    if (tmp.value >= 9) {
        tmpRoman += "IX";
        tmp.value -= 9;
    }

    if (tmp.value / V > 0) {
        for (int i = 0; i < tmp.value / V; i++) {
            tmpRoman += "V";
        }
        tmp.value = tmp.value % V;
    }
    if (tmp.value >= 4) {
        tmpRoman += "IV";
        tmp.value -= 4;
    }

    if (tmp.value / I > 0) {
        for (int i = 0; i < tmp.value / I; i++) {
            tmpRoman += "I";
        }
    }
    
    romanNumber.value = tmpRoman;
    isReadyRoman = true;
}
    
bool converter::checkRoman() {
    for (int i = 0; i < romanNumber.value.length(); i++) {
        romanNumber.value[i] = toupper(romanNumber.value[i]);
        bool b = false;
        for(int j = 0; j < sizeArr; j++) {
            if (romanNumber.value[i] == arrNum[j]) {
                b = true;
                break;
            }
        }
        if (!b) return false;
    }

    enum State {q0, q1, q2, q3};

    for (int i = 0; i < romanNumber.value.length(); i++) {
        
    }
    return true;
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
