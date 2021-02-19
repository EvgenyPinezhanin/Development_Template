#include <converter.h>

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
        for (int j = 0; j < sizeArr; j++) {
            if (tmp[i] == arrNum[j].c) {
                tmpArabic += arrNum[j].n;
            }
        }
    }
    arabicNumber.value = tmpArabic;
    isReadyArabic = true;
}
    
void converter::toRoman() {
    arabic tmp = arabicNumber;
    string tmpRoman = "";

    if (arabicNumber.value > 3999) throw logic_error("Number greater than 3999");

    int k = 100;
    for (int i = 6; i >= 0; i--) {
        if (tmp.value / arrNum[i].n > 0) {
            for (int j = 0; j < tmp.value / arrNum[i].n; j++) {
                tmpRoman.append(1, arrNum[i].c);
            }
            tmp.value = tmp.value % arrNum[i].n;
        }
        if (tmp.value >= arrNum[i].n - k) {
            tmpRoman.append(1, arrNum[i - 1 - !(i % 2)].c);
            tmpRoman.append(1, arrNum[i].c);
            tmp.value -= (arrNum[i].n - k);
        }
        if (i % 2 == 1) k /= 10;
    }
    
    romanNumber.value = tmpRoman;
    isReadyRoman = true;
}
    
bool converter::checkRoman() {
    for (int i = 0; i < romanNumber.value.length(); i++) {
        romanNumber.value[i] = toupper(romanNumber.value[i]);
        bool b = false;
        for(int j = 0; j < sizeArr; j++) {
            if (romanNumber.value[i] == arrNum[j].c) {
                b = true;
                break;
            }
        }
        if (!b) return false;
    }

    int count = 0;
    char c, c1;
    while (count < (int)romanNumber.value.length() - 1)
    {
        c = romanNumber.value[count];
        c1 = romanNumber.value[count + 1];
        for (int j = 0; j < sizeArr; j++) {
            if (c == arrNum[j].c) {
                bool b = false;
                for (int k = 0; k < sizeArr; k++) {
                    if (c1 == arrNum[k].c) {
                        if ((j == 0) && (k - j > 2)) {
                            b = true;
                        } else if ((j == 1) && (k - j > 0)) {
                            b = true;
                        } else if ((j == 2) && (k - j > 2)) {
                            b = true;
                        } else if ((j == 3) && (k - j > 0)) {
                            b = true;
                        } else if ((j == 5) && (k - j > 0)) {
                            b = true;
                        }
                        if (b) {
                            arabic ar(arrNum[k].n - arrNum[j].n);
                            converter conv(ar);
                            romanNumber.value.replace(count, 2, conv.getRoman().value);
                            count += conv.getRoman().value.length() - 1;
                            break;
                        }
                    }
                }
                break;
            }
        }
        count++;
    }

    char currN = romanNumber.value[0];
    count = 1;
    State state = q0;
    int countNum[] = {0, 0, 0, 0, 0, 0, 0};
    int i = 1;
    while (i < (int)romanNumber.value.length()) {
        c = romanNumber.value[i];
        if (c != currN) {
            for (int j = 0; j < sizeArr; j++) {
                if (c == arrNum[j].c) {
                    if (j % 2) {
                        if (count > 1) {
                            arabic ar(count * arrNum[j].n);
                            converter conv(ar);
                            romanNumber.value.replace(i - count, count, conv.getRoman().value);
                            i += (conv.getRoman().value.length() - 1 - count);
                        }
                    } else {
                        if (count > 3) {
                            arabic ar(count * arrNum[j].n);
                            converter conv(ar);
                            romanNumber.value.replace(i - count, count, conv.getRoman().value);
                            i += (conv.getRoman().value.length() - 1 - count);
                        }
                    }
                }
            }
            count = 0;
            currN = c;
        } else {
            count++;
        }
        i++;
    }
    for (int j = 0; j < sizeArr; j++) {
        if (c == arrNum[j].c) {
            if (j % 2) {
                if (count > 1) {
                    arabic ar(count * arrNum[j].n);
                    converter conv(ar);
                    romanNumber.value.replace(romanNumber.value.length() - count, count, conv.getRoman().value);
                }
            } else {
                if (count > 3) {
                    arabic ar(count * arrNum[j].n);
                    converter conv(ar);
                    romanNumber.value.replace(romanNumber.value.length() - count, count, conv.getRoman().value);
                }
            }
        }
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
