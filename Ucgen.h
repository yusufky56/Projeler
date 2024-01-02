#pragma once

#include "Nokta.h"
#include "DogruParcasi.h"
#include <array>

using namespace std;

// Ucgen sınıfı, üç Nokta nesnesi ile tanımlanan bir üçgeni temsil eder.
class Ucgen {
private:
    Nokta nokta1, nokta2, nokta3;

public:
    // Üç Nokta nesnesi alarak bir üçgen oluşturan yapıcı.
    Ucgen(const Nokta& _nokta1, const Nokta& _nokta2, const Nokta& _nokta3)
        : nokta1(_nokta1), nokta2(_nokta2), nokta3(_nokta3) {}

    // Getter ve setter metotları
    Nokta getNokta1() const { return nokta1; }
    void setNokta1(const Nokta& _nokta1) { nokta1 = _nokta1; }

    Nokta getNokta2() const { return nokta2; }
    void setNokta2(const Nokta& _nokta2) { nokta2 = _nokta2; }

    Nokta getNokta3() const { return nokta3; }
    void setNokta3(const Nokta& _nokta3) { nokta3 = _nokta3; }

    // Üçgenin bilgilerini string olarak döndüren metot
    std::string toString() const {
        return "Üçgen; " + nokta1.toString() + ", " + nokta2.toString() + ", " + nokta3.toString();
    }

    // Üçgenin alanını hesaplayan metot
    double alan() const {
        double a = DogruParcasi(nokta1, nokta2).uzunluk();
        double b = DogruParcasi(nokta2, nokta3).uzunluk();
        double c = DogruParcasi(nokta3, nokta1).uzunluk();

        double s = (a + b + c) / 2;
        return sqrt(s * (s - a) * (s - b) * (s - c));
    }

    // Üçgenin çevresini hesaplayan metot
    double cevre() const {
        double a = DogruParcasi(nokta1, nokta2).uzunluk();
        double b = DogruParcasi(nokta2, nokta3).uzunluk();
        double c = DogruParcasi(nokta3, nokta1).uzunluk();
        return a + b + c;
    }

    // Üçgenin iç açılarını hesaplayıp dizi olarak döndüren metot
    std::array<double, 3> acilar() const {
        double a = DogruParcasi(nokta1, nokta2).uzunluk();
        double b = DogruParcasi(nokta2, nokta3).uzunluk();
        double c = DogruParcasi(nokta3, nokta1).uzunluk();

        double aciA = acos((b * b + c * c - a * a) / (2 * b * c));
        double aciB = acos((c * c + a * a - b * b) / (2 * c * a));
        double aciC = acos((a * a + b * b - c * c) / (2 * a * b));

        return { aciA, aciB, aciC };
    }
};
