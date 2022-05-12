//
// Created by Lix Xeil on 09.05.2022.
//

#ifndef RECORDSTORE_RECORD_H
#define RECORDSTORE_RECORD_H

#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <string>
#include <vector>
#include <iostream>
using std::string;
using std::vector;

enum class Support{
    PICKUP,                     //for vinyls
    AUDIO_PLAYER,               //cassettes/cds
    COMPUTER,                   //downloadable/convertable
    PHONE,                       //downloadable
    PHYSICAL_MEMORY,              //convertable
    ARTISTIC_PURPOSES             //for limited edition classes
};

class Record{

public:
    //constructor
    Record(string i, unsigned int dur, string artName, string recName, unsigned int yr, float p);

    //getters for the class object  (self-explanatory)
    string getId() const;
    unsigned int getDuration() const;
    string getArtistName() const;
    string getRecordName() const;
    unsigned int getYear() const;
    float getPrice() const;

    //setters for the class object  (self-explanatory)
    void setId(string st);
    void setDuration(int dur);
    void setArtistName(string st);
    void setRecordName(string st);
    void setYear(int yr);
    void setPrice(float p);

    // pure virtual functions
    virtual vector<Support> getSupportType();
    virtual string toString();

protected:
    string id;
    unsigned int duration;
    string artistName;
    string recordName;
    unsigned int year;
    float price;
};

class Cassette : public Record {

public:
    Cassette(string i, unsigned int dur, string artName, string recName, unsigned int yr, float p, bool isConvertable);
    vector<Support> getSupportType();
    string toString() override;

private:
    //bool isDoubleSided;
    bool isConvertable;
};

class CD : public Record {

public:
    CD(string i, unsigned int dur, string artName, string recName, unsigned int yr, float p, bool isDownloadable, bool isConvertable);
    vector <Support> getSupportType();
    string toString() override;

private:
    //bool isDoubleSided;
    bool isDownloadable;
    bool isConvertable;
};

class Vinyl : public Record {

public:
    Vinyl(string i, unsigned int dur, string artName, string recName, unsigned int yr, float p, bool isDownloadable, bool isConvertable, bool isLimitedEdition);
    vector <Support> getSupportType();
    string toString() override;

private:
    bool isDownloadable;
    bool isConvertable;
    bool isLimitedEdition;
};

#endif //RECORDSTORE_RECORD_H
