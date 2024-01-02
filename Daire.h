#pragma once
#include "Nokta.h"

// Daire sınıfı, Nokta nesnesi olan merkez ve bir double olan yarıçap değerlerini içerir.
class Daire {
private:
    Nokta merkez;
    double yaricap;

public:
    // Parametre olarak verilen merkez noktası ve yarıçap değeriyle bir Daire nesnesi oluşturur.
    Daire(const Nokta& _merkez, double _yaricap) : merkez(_merkez), yaricap(_yaricap) {}

    // Başka bir Daire nesnesini alan ve onun bir kopyasını oluşturan yapıcı.
    Daire(const Daire& other) : merkez(other.merkez), yaricap(other.yaricap) {}

    // Başka bir Daire nesnesini ve bir katsayıyı alan ve yeni bir Daire oluşturan yapıcı.
    Daire(const Daire& other, double x) : merkez(other.merkez), yaricap(other.yaricap* x) {}

    // Dairenin alanını hesaplar.
    double alan() const {
        return 3.0 * yaricap * yaricap;
    }

    // Dairenin çevresini hesaplar.
    double cevre() const {
        return 2.0 * 3.0 * yaricap;
    }

    // Diğer bir Daire ile kesişimin durumunu belirler.
    
    int kesisim(const Daire& digerDaire) const {
        double uzaklik = sqrt(pow(merkez.getX() - digerDaire.merkez.getX(), 2) + pow(merkez.getY() - digerDaire.merkez.getY(), 2));
        double toplamYaricap = yaricap + digerDaire.yaricap;

        if (uzaklik < toplamYaricap) {
            if (uzaklik + digerDaire.yaricap == yaricap || uzaklik + yaricap == digerDaire.yaricap)
                return 1; // Daireler birebir örtüşüyor
            else
                return 0; // Bir daire diğerinin içinde
        }
        else {
            return 2; // Kesişim yok
        }
    }

    // Dairenin merkez noktasını ve yarıçapını string olarak döndürür.
    std::string toString() const {
        return "Merkez: " + merkez.toString() + ", Yaricap: " + std::to_string(yaricap);
    }

    // Dairenin bilgilerini ekrana yazdırır.
    void yazdir() const {
        std::cout << toString() << std::endl;
    }
};