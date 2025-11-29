#include <iostream>
#include <string>
#include <cctype>
/*
Një program që analizon një fjalëkalim dhe përcakton fortësinë e tij duke kontrolluar:

gjatësinë

karakteret speciale

numrat

shkronjat e mëdha/vogla
*/

int LengthStrength(const std::string&password){
    int strength = 0;
    size_t length = password.length();

    if(length >= 8) strength += 1;
    if(length >= 12) strength += 1;
    if(length >= 16) strength += 1;

    return strength;
}

int hasSpecialChar(const std::string &password){
    int strength = 0;
    const std::string specialCharacters = "!#$%^&*()-+?_=,<>/";
    for(char ch : password){
        if(specialCharacters.find(ch) != std::string ::npos){
            strength += 1;
        }
    }
    return strength;
}

int hasDigit(const std::string &password){
    int strength = 0;
    for(char ch : password){
        if(ch >= '0' && ch <= '9'){
            strength += 1;
        }
    }
    return strength;
}

int hasUpper(const std::string &password){
    int strength = 0;
    for(char ch : password){
        if(std::isupper(ch)){
            strength += 2;
        }
    }
    return strength;
}

int hasLower(const std::string &password){
    int strength = 0;
    for(char ch : password){
        if(std::islower(ch)){
            strength += 1;
        }
    }
    return strength;
}

int CalculateStrength(const std::string &password){
    int totalStrength = 0;
    totalStrength += LengthStrength(password);
    totalStrength += hasSpecialChar(password);
    totalStrength += hasDigit(password);
    totalStrength += hasUpper(password);
    totalStrength += hasLower(password);
    return totalStrength;
}

int main(){

    std::string password;
    std::cout <<"Shkruaj fjalekalimin per te pare fortesine e tij: ";
    std::cin >> password;

    int strength = CalculateStrength(password);

    if(strength == 0){
        std::cout << "Shkruaj fjalekalim." << std::endl;
    }
    else if(strength <= 8){
        std::cout << "Fjalekalimi juaj eshte shume i dobet." << std::endl;
    }
    else if(strength <= 20){
        std::cout << "Fjalekalimi juaj eshte i dobet." << std::endl;
    }
    else if(strength <= 30){
        std::cout << "Fjalekalimi juaj eshte i forte." << std::endl;
    }
    else{
        std::cout << "Fjalekalimi juaj eshte shume i forte." << std::endl;
    }

}
