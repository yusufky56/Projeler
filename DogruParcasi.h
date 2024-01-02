#pragma once
#include "Nokta.h"

class DogruParcasi {
private:
    Nokta nokta1, nokta2;

public:
    // İki uç noktayı Nokta nesnesi olarak alan yapıcı.
    DogruParcasi(const Nokta& n1, const Nokta& n2) : nokta1(n1), nokta2(n2) {}

    // Başka bir DogruParcasi nesnesi alıp onun bir kopyasını yeni bir DogruParcasi nesnesi olarak oluşturan yapıcı.
    DogruParcasi(const DogruParcasi& other) : nokta1(other.nokta1), nokta2(other.nokta2) {}

    // Bir Nokta nesnesi (doğru parçasının orta noktası olarak), parçanın uzunluğu (double) ve eğimi (double) değerlerini alarak, doğru parçasının 2 uç noktasının x ve y koordinatlarını hesaplayan yapıcı.
    DogruParcasi(const Nokta& orta, double uzunluk, double egim) {
        // Verilen orta noktayı ve doğrunun uzunluğu ile eğimi kullanarak doğru parçasının uç noktalarını hesapla
        double deltaX = uzunluk / sqrt(1 + egim * egim); // x eksenine olan uzaklık
        double deltaY = egim * deltaX; // y eksenine olan uzaklık

        // Birinci uç noktanın koordinatlarını hesapla
        double x1 = orta.getX() - deltaX / 2;
        double y1 = orta.getY() - deltaY / 2;

        // İkinci uç noktanın koordinatlarını hesapla
        double x2 = orta.getX() + deltaX / 2;
        double y2 = orta.getY() + deltaY / 2;

        nokta1.setXY(x1, y1);
        nokta2.setXY(x2, y2);
    }

    // İlgili get ve set metotları
    Nokta getP1() const {
        return nokta1;
    }

    void setP1(const Nokta& n1) {
        nokta1 = n1;
    }

    Nokta getP2() const {
        return nokta2;
    }

    void setP2(const Nokta& n2) {
        nokta2 = n2;
    }

    Nokta ortaNokta() {
        return Nokta((nokta1.getX() + nokta2.getX()) / 2, (nokta1.getY() + nokta2.getY()) / 2);
    }

    string toString() {
        // Geçerli DogruParcasi nesnesini String olarak döndürür
        return "Nokta1 : (" + to_string(nokta1.getX()) + ", " + to_string(nokta1.getY()) + "), Nokta 2: (" + to_string(nokta2.getX()) + ", " + to_string(nokta2.getY()) + ")";
    }

    void yazdir() {
        cout << toString() << endl;
    }

    // uzunluk metodu: DogruParcasi nesnesinin uzunluğunu hesaplar ve döndürür
    double uzunluk() const {
        double uzunlukX = nokta2.getX() - nokta1.getX();
        double uzunlukY = nokta2.getY() - nokta1.getY();
        return sqrt(uzunlukX * uzunlukX + uzunlukY * uzunlukY);
    }

    // kesişimNoktası metodu: Bir Nokta nesnesini parametre olarak alır, bu noktadan doğru parçasına dik olarak çizilecek doğru parçasının kesişme noktasını hesaplar ve bir Nokta nesnesi olarak döndürür.
    Nokta kesisimNoktasi(const Nokta& nokta) const {
        double x1 = nokta1.getX();
        double y1 = nokta1.getY();
        double x2 = nokta2.getX();
        double y2 = nokta2.getY();
        double x3 = nokta.getX();
        double y3 = nokta.getY();

        // Doğru parçasının eğimi
        double m = (y2 - y1) / (x2 - x1);

        // Doğrunun denklemi: y = mx + n
        // Doğrunun n değeri
        double n = y1 - m * x1;

        // Verilen noktadan dikey geçen doğrunun denklemi: y = -1/m * x + k
        // Verilen noktanın doğruya dik olan eğimi
        double dik_egim = -1 / m;

        // Verilen noktanın doğruya dik olan denklemdeki n değeri
        double k = y3 - dik_egim * x3;

        // Kesişim noktasının x koordinatı
        double kesisim_x = (k - n) / (m - dik_egim);
        // Kesişim noktasının y koordinatı
        double kesisim_y = m * kesisim_x + n;

        Nokta kesisim_nokta(kesisim_x, kesisim_y);
        return kesisim_nokta;
    }
};