//
// Created by Alex Doudkin on 9/10/24.
//

#ifndef HEARTATTACK_H
#define HEARTATTACK_H

#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

class HeartAttack {

private:
    std::string gender, treatment, chestPainType, smoking, diabetes;
    int id, age, bloodPressure, cholesterol;


public:
    HeartAttack() { //constructor
    }

    HeartAttack(int id,
                std::string gender,
                int age,
                int bloodPressure,
                int cholesterol,
                std::string diabetes,
                std::string smoking,
                std::string chestPainType
    ) {
        this->id = id;
        this->gender = gender;
        this->age = age;
        this->bloodPressure = bloodPressure;
        this->cholesterol = cholesterol;
        this->diabetes = diabetes;
        this->smoking = smoking;
        this->chestPainType = chestPainType;


    }
    //getters
    std::string getGender() const {
        return gender;
    }
    std::string getTreatment() const {
        return treatment;
    }
    std::string getChestPainType() const {
        return chestPainType;
    }
    std::string getSmoking() const {
        return smoking;
    }
    std::string getDiabetes() const {
        return diabetes;
    }
    int getID() const {
        return id;
    }
    int getAge() const {
        return age;
    }
    int getBloodPressure() const {
        return this->bloodPressure;
    }
    int getCholesterol() const {
        return this->cholesterol;
    }
    //setters
    void setID(int id) {
        this->id = id;
    }
    void setGender(std::string gender) {
        this->gender = gender;
    }
    void setTreatment(std::string treatment) {
        this->treatment = treatment;
    }
    void setChestPainType(std::string chestPainType) {
        this->chestPainType = chestPainType;
    }
    void setSmoking(std::string smoking) {
        this->smoking = smoking;
    }
    void setDiabetes(std::string diabetes) {
        this->diabetes = diabetes;
    }
    void setAge(int age) {
        this->age = age;
    }
    void setBloodPressure(int bloodPressure) {
        this->bloodPressure = bloodPressure;
    }
    void setCholesterol(int cholesterol) {
        this->cholesterol = cholesterol;
    }

    friend std::ostream& operator << (std::ostream& outs, const HeartAttack& obj) {
        outs << std::fixed
             << std::right
             << std::setprecision(10)
             << " "
             << std::setw(1) << obj.getID()
             << std::left
             << "  "
             << std::setw(8) << obj.getGender()
             << std::setw(10) << obj.getAge()
             << std::left
             << "  "
             << std::setw(16) << obj.getBloodPressure()
             << std::setw(14) << obj.getCholesterol()
             << std::setw(16) << obj.getDiabetes()
             << std::setw(16)
             << std::left
             << std::setw(20) << obj.getSmoking()
             << std::setw(20) << obj.getChestPainType()
             << std::right
             //<< std::setw(20) << obj.getTreatment()
             << std::left;
        return outs;
    }

    friend bool operator < (const HeartAttack& l, const HeartAttack r) {
        return l.getID() < r.getID();
    }
    friend bool operator > (const HeartAttack& l, const HeartAttack r) {
        return l.getID() < r.getID();
    }
    friend bool operator <= (const HeartAttack& l, const HeartAttack r) {
        return l.getID() < r.getID();
    }
    friend bool operator >= (const HeartAttack& l, const HeartAttack r) {
        return l.getID() < r.getID();
    }
    friend bool operator == (const HeartAttack& l, const HeartAttack r) {
        return l.getID() < r.getID();
    }






};


//reads the data from the csv file into the vector
//sets the constructors variables

bool loadFromFile(std::string fn, std::vector<HeartAttack>& objs) {
    std::ifstream fin;
    fin.open(fn);

    if (!fin) {
        return false;
    }

    std::string header = "";
    getline(fin, header);

    int counter = 1;
    while (fin && fin.peek() != EOF) {

        int id = -1;
        std::string gender = "INVALID";
        int age = -1;
        int bloodPressure = -1;
        int cholesterol = -1;
        std::string diabetes = "INVALID";
        std::string smoking = "INVALID";
        std::string chestPainType = "INVALID";
        std::string treatment = "INVALID";
        char comma = ',';

        fin >> id;
        fin >> comma;
        getline(fin, gender, comma);
        fin >> age;
        fin >> comma;
        fin >> bloodPressure;
        fin >> comma;
        fin >> cholesterol;
        fin >> comma;
        getline(fin, diabetes, comma);
        getline(fin, smoking, comma);
        getline(fin, chestPainType, comma);
        getline(fin, treatment);

        HeartAttack heart_attack(id, gender, age, bloodPressure,cholesterol, diabetes,
                                 smoking,chestPainType);

        objs.push_back(heart_attack);
        counter += 1;
    }
    fin.close();
    return true;
}

#endif //HEARTATTACK_H
